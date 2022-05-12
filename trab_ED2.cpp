#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <vector>
#include <ctype.h>
#include <string.h>

using namespace std;

void printVector(int* v){

    char ignore;

    for (int i = 0; v[i] != 0; i++){
        printf("\n| %d |\n", v[i]);
    }

    printf("\n\nDigite qualquer tecla para sair: ");   
    scanf(" %c", &ignore);
}

void escolherMetOrdena(int* v){
    char metodo;
    system("clear");
    printf("\n-----------------------------------------\n");
    printf(" [B] - Ordenar Vetor");
    printf("\n-----------------------------------------\n");
    printf("[Q] - Ordenar com QUICK SORT\n");
    printf("[M] - Ordenar com MERGE SORT\n");
    scanf(" %c", &metodo);

    switch (metodo)
    {
    case 'Q':
       // quickSort(&v, 0, v.size());
        break;
    
    default:
        break;
    }
}

int* gerarVetor(int* v){

    system("clear");
    int len;
    printf("\n-----------------------------------------\n");
    printf(" [A] - Gerar Valores");
    printf("\n-----------------------------------------\n");
    printf("Digite o tamanho do vetor a ser gerado: ");
    scanf(" %d", &len);

    v = (int*) malloc(len * sizeof(int));

    for (int i = 0; i < len; i++){
        v[i] = rand() % 1000;
    }
    
    return v;
}

void hub(char op, int* vetor){
    
    switch (op)
    {
    case 'A':
        vetor = gerarVetor(vetor);
        printVector(vetor);
        break;
    case 'B':
        //escolherMetOrdena(*vetor);
        break;
    }
}

void menu(char * op){

    system("clear");
    printf("[A] - Gerar vetor\n");
    printf("[B] - Ordenar vetor\n");
    printf("[C] - Busca sequencial\n");
    printf("[D] - Busca binária\n");
    printf("\n[Q] - Para encerrar programa\n\n");

    scanf(" %c", op);
   // *op = toupper(*op);
}

int main(){

    int* vetor;
//    vetor = (int*) malloc(5 * sizeof(int));
    char option = 1;

    while(option != 'Q'){
        menu(&option);
        hub(option, vetor);

    }
    printf("\n\nPrograma encerrado com sucesso\n\n\n");
}