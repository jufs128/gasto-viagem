# gasto-viagem
  O programa recebe um valor total que pode ser gasto, um número de ilhas que podem ser visitadas, o custo por dia e pontuação por dia de visita em cada ilha, e retornar qual a pontuação máxima a ser atingida e os dias que durará a viagem quando: (1) puder repetir a estadia em certa ilha; e (2) não puder ficar em cada ilha mais de um dia.
  
## Implementação
  Foi feito um struct TipoIlha com custo, pontuação e proporção pontuação/custo. Para gravar os dados de todas as ilhas, foi criado um vetor TipoIlha com as N ilhas disponíveis. A fim de resolver o problema 1, usou-se algoritmo guloso, e para resolver o problema 2, programação dinâmica.
  
## Entrada
  Lê-se dois inteiros N e M, o custo máximo e o número de ilhas, respectivamente. Depois, lê-se o custo/dia e a pontuação/dia de cada uma das M ilhas. Na saída, imprime a resolução do algoritmo guloso seguido da programação dinâmica. Exemplo:
  
#### Entrada:
  6000 5            
  1000 30           
  2000 32           
  500 4           
  5000 90         
  2200 45         
  
#### Saída:
  180 6               
  120 2               
  
## Compilação
  Na pasta archives está incluso um Makefile, basta digitar make na linha de comando.  

## Execução
  A função funciona passando o nome do arquivo .txt como parâmetro, mas, caso isso não seja feito, pede para o usuário digitar o nome do arquivo no início da execução.

*Obs.: Inclua o .txt no nome do arquivo, isto é, nome.txt e não somente nome.*
