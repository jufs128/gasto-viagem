#include <time.h>
#include "func.h"

int main (int argc, char *argv[]){
    //Medir tempo
    //clock_t tempoInicial;
    //clock_t tempoFinal;
    //tempoInicial = clock();

    char NomeArq[100];
    if(argc > 1){ //Verifica se o nome do arquivo foi colocado como parâmetro
        strcpy(NomeArq,argv[1]); //Copia o nome para string NomeArq
    } else { //Se não foi colocado, pede para inserir
        printf("Digite o nome do arquivo de entrada: ");
        scanf("%s",NomeArq); //Lê da stdin
    }
    FILE *arq;
    arq = fopen(NomeArq,"r"); //Abre o arquivo para leitura
    if(arq==NULL){ //Se arquivo inserido não está na pasta
        printf("Erro ao abrir arquivo de entrada.\n"); //Dá erro
        return 1;
    }

    int i, N, M;
    fscanf(arq,"%d %d",&N,&M); //Lê o custo máximo e número de ilhas

    TipoIlha *Ilhas = malloc(M*sizeof(TipoIlha)); //Vetor de Ilhas
    for(i = 0; i < M; i++) {
        fscanf(arq,"%d %d",&Ilhas[i].Custo,&Ilhas[i].Pont); //Lê o custo e pontuação de cada
        Ilhas[i].Prop = (float)Ilhas[i].Pont / Ilhas[i].Custo; //Calcula o custo
    }

    TipoIlha *aux = malloc(M*sizeof(TipoIlha)); //Vetor auxiliar utilizado no Mergesort
    Mergesort(Ilhas,aux,0,M-1); //Ordena Ilhas por proporção pontuação/custo
    Guloso(Ilhas,N,M); //Acha o resultado por algoritmo guloso
    ProgDinam(Ilhas,N,M); //Acha o resultado por programação dinâmica

    //tempoFinal = clock();
    //printf("%f,",(tempoFinal- tempoInicial) * 1000.0 / CLOCKS_PER_SEC);

    return 0;
}
