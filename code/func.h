#ifndef FUNC_H
#define FUNC_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct { //Estrutura para ilhas
    int Custo; //Custo por dia
    int Pont; //Pontuação por dia
    float Prop; //Proporção de pontuação por custo
} TipoIlha;

void Merge (TipoIlha *a, TipoIlha *aux, int e, int m, int d); //Junção dos dois subvetores

void Mergesort (TipoIlha *a, TipoIlha *aux, int e, int d); //Ordenação crescente das ilhas por proporção

void Guloso (TipoIlha *Ilhas, int N, int M); //Resolve por algoritmo guloso

int max (int a, int b); //Acha o maior entre dois números

void ProgDinam(TipoIlha *Ilhas, int W, int N); //Resolve por programação dinâmica

#endif
