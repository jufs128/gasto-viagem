#include "func.h"

void Merge (TipoIlha *a, TipoIlha *aux, int e, int m, int d) {
    int i, j, k;
    //Considerar dois subvetores A (de e a m) e B (de m a d)
    for (i = 0; i <= m; i++){ //Copia o subvetor A para aux
        aux[i].Custo = a[i].Custo;
        aux[i].Pont = a[i].Pont;
        aux[i].Prop = a[i].Prop;
    }
    for (j = m+1; j <= d; j++){ //Copia o subvetor B reversamente para aux; evita repetição na junção
        aux[d-j+m+1].Custo = a[j].Custo;
        aux[d-j+m+1].Pont = a[j].Pont;
        aux[d-j+m+1].Prop = a[j].Prop;
    }

    i = e; //i primeiro elemento de A
    j = d; //j primeiro elemento de B
    for (k = e; k <= d; k++) //Percorre aux para fazer junção
        if (aux[i].Prop <= aux[j].Prop){ //Se o elemento A[i] é menor ou igual ao elemento B[m+1-j]
            a[k].Custo = aux[i].Custo; //Coloca A[i] no vetor
            a[k].Pont = aux[i].Pont;
            a[k].Prop = aux[i].Prop;
            i++; //Próximo elemento de A
        } else { //Se é maior
            a[k].Custo = aux[j].Custo; //Coloca B[m+1-j]
            a[k].Pont = aux[j].Pont;
            a[k].Prop = aux[j].Prop;
            j--; //Próximo elemento de B
        }
}

void Mergesort (TipoIlha *a, TipoIlha *aux, int e, int d) { //Ordena crescentemente pela pela proporção
    int m = (d+e)/2; //Meio do vetor

    if (e < d) { //Se o tamanho do vetor é maior que 0
        Mergesort(a, aux, e, m); //Faz para subvetor esquerdo
        Mergesort(a, aux, m+1, d); //Faz para subvetor direiro
        Merge(a, aux, e, m, d); //Junção dos subvetores já ordenados
    }
}

void Guloso (TipoIlha *Ilhas, int N, int M) { //Resolução por algoritmo guloso
    int i, dias = 0, pont = 0, custo = N;

    for (i = M-1; i >= 0; i--) { //Do final do vetor (maior proporção pontuação/custo) para o começo
        while (Ilhas[i].Custo <= custo) { //Enquanto o custo da ilha i for maior que o dinheiro restante
            custo = custo - Ilhas[i].Custo; //Subtrai o custo do dinheiro restante
            pont = pont + Ilhas[i].Pont; //Soma a pontuação pela estadia
            dias++; //Aumenta um dia à viagem
        }
    }

    printf("%d %d\n",pont,dias); //Imprime a pontuação atingida e o numero de dias de viagem
}

int max (int a, int b) { //Acha o maior entre dois numeros
    if (a >= b)
        return a; //Se a maior ou igual a b, retorna a
    else
        return b; //Senão retorna b
}

void ProgDinam(TipoIlha *Ilhas, int W, int N) { //Resolução por programação dinâmica
    int i, j, dias = 0;
    int **M = malloc((N+1)*sizeof(int *)); //Matriz de pontuação máximo por número de ilhas e custo máximo
    for (i = 0; i <= N; i++){ //Inicializa a matriz M[N+1][M+1]
        M[i] = malloc((W+1)*sizeof(int));
        for (j = 0; j <= W; j++){
            M[i][j] = 0; //Inicialmente tudo 0
        }
    }

    for (i = 1; i <= N; i++){
        for (j = 0; j <= W; j++){
            if(Ilhas[i-1].Custo > j) //Se o custo de uma estadia na ilha é maior que o peso restante
                M[i][j] = M[i - 1][j]; //Não inclui a ilha i
            else //Se pode incluir a ilha i
                M[i][j] = max((Ilhas[i-1].Pont + M[i-1][j - Ilhas[i-1].Custo]), M[i-1][j]); //Acha o maior entre incluir ou não a ilha i
        }
    }

    //Achar a quantidade de dias de viagem
    j = W; //Dinheiro disponível
    i = N; //Número de ilhas
    while((i > 0) && (j > 0)){ //Enquanto não verificou todas as ilhas ou esgotou o orçamento
        if (M[i][j] > M[i-1][j]){ //Se M[i][j] é maior que M[i-1][j], ilha i foi visitada
            dias = dias + 1; //Aumenta em 1 o número de dias
            j = j - Ilhas[i-1].Custo; //Tira o custo da estadia do dinheiro restante
        }
        i--; //Checa ilha de cima
    }

    printf("%d %d",M[N][W],dias); //Imprime a pontuação máxima e o número de dias de viagem
}
