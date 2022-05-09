#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <ctype.h>

using namespace std;

int quickSort(vector <int> v, int s, int e)
{
    if (s<e)
    {
        int p = particiona(v,s,e);
        quickSort(v,s,p-1);
        quickSort(v,p+1,e);
    }
}

void printVector(vector <int> v){
    int ignore;
    printf("\n\n");
    for (int i = 0; i < v.size(); i++)
    {
        printf("| %d ",v.at(i));
    }
    printf("|\n\nDigite qualquer tecla para sair: ");   
    scanf("%d", &ignore);
}

void escolherMetOrdena(vector <int> *v){
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
        quickSort()
        break;
    
    default:
        break;
    }
}

void gerarVetor(vector <int> *v){
    system("clear");
    int len;
    printf("\n-----------------------------------------\n");
    printf(" [A] - Gerar Valores");
    printf("\n-----------------------------------------\n");
    printf("Digite o tamanho do vetor a ser gerado: ");
    scanf(" %d", &len);

    for (int i = 0; i < len; i++)
    {
        v->push_back(rand() % 1000);
    }
}

void hub(char op){
    
    vector <int> vetor;
    switch (op)
    {
    case 'A':
        gerarVetor(&vetor);
        printVector(vetor);
        break;
    case 'B':
        escolherMetOrdena(%vetor);
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

    char option = 1;

    while(option != 'Q'){
        menu(&option);
        hub(option);
    }
    printf("\n\nPrograma encerrado com sucesso\n\n\n");
}