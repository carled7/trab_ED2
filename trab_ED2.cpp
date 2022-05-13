#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <vector>
#include <ctype.h>
#include <string.h>

using namespace std;

void troca(int v[], int a,int b){

    int aux = v[a];
    v[a] = v[b];
    v[b] = aux;
}

int particiona(int v[],int s, int e){
    int pivot = v[s];
    int i=s;
    for(int j=s+1; j<=e; j++)
    {
        if(v[j]<=pivot)
        {
            i++;
            troca(v,i,j);
        }
    }
    troca(v,s,i);
    return i;

}

void quickSort(int v[], int s, int e){
    if (s<e)
    {
        int p = particiona(v,s,e);
        quickSort(v,s,p-1);
        quickSort(v,p+1,e);
    }
}

int vtrLen(int v[]){
 
    int len;
    for (len = 0; v[len] != 0 || v[len] > 1000; len++);
    return len - 1;
        
}

void printVtr(int* v){

    char ignore;

    for (int i = 0; i < vtrLen(v); i++){
        printf("\n%d: \t | %d |",i+1, v[i]);
    }

    printf("\n\nDigite qualquer tecla para sair: ");   
    scanf(" %c", &ignore);
}

int* cpyVtr(int* scr, int* dest){

    for (int i = 0; i < vtrLen(scr); i++){
        dest[i] = scr[i];
    }

    return dest;    
}

void escolherMetOrdena(int* v){

    char metodo;
    int* aux = (int*) malloc(vtrLen(v) * sizeof(int));

    system("clear");
    printf("-----------------------------------------\n");
    printf(" [B] - Ordenar Vetor");
    printf("\n-----------------------------------------\n");
    printf(" [Q] - Ordenar com QUICK SORT\n");
    printf(" [M] - Ordenar com MERGE SORT\n");
    scanf(" %c", &metodo);

    switch (metodo)
    {
    case 'Q':
        cpyVtr(v, aux);
        quickSort(aux, 0, vtrLen(aux)-1);
        system("clear");
        printf("-----------------------------------------\n");
        printf(" [Q] - Vetor Ordenado");
        printf("\n-----------------------------------------\n");
        printVtr(aux);
        break;
    
    default:
        break;
    }
}

int* gerarVetor(int* v){

    system("clear");
    int len;
    printf("-----------------------------------------\n");
    printf(" [A] - Gerar Valores");
    printf("\n-----------------------------------------\n");
    printf(" Digite o tamanho do vetor a ser gerado: ");
    scanf(" %d", &len);

    v = (int*) malloc(len * sizeof(int));

    for (int i = 0; i < len; i++){
        v[i] = rand() % 1000;
    }
    
    return v;
}

void menu(int* vetor){

    char op;
    while (op != 'Q'){
        system("clear");
        printf("[A] - Gerar vetor\n");
        printf("[B] - Ordenar vetor\n");
        printf("[C] - Busca sequencial\n");
        printf("[D] - Busca binária\n");
        printf("[E] - Imprimir vetor\n");
        printf("\n[Q] - Para encerrar programa\n\n");

        scanf(" %c", &op);

        switch (op)
        {
        case 'A':
            vetor = gerarVetor(vetor);
            break;
        case 'B':
            escolherMetOrdena(vetor);
            break;
        case 'E':
            printVtr(vetor);
        }
    }

}

int main(){

    int* vetor;

    menu(vetor);
    //hub(option, vetor);
    
    printf("\n\nPrograma encerrado com sucesso\n\n\n");
}