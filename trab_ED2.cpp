#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <vector>
#include <ctype.h>
#include <string.h>

#define RANDOM 1000

using namespace std;

 int buscaBinaria(int v[], int n, int x){
    int s = 0, e = n -1;
    while(s <= e){

        int m = (s + e)/2;
        if(x == v[m]){
            return m;
        }else if (x > v[m]){
            s = m + 1;
        }else if (x < v[m]){
            e = m - 1;
        }

    }
    return -1;
 }

int buscaSequencial (int v[], int n, int x){

    for(int i = 0; i < n; i++){
        if(v[i] == x){
            return i;
        }
    }
    return -1;
 }

void merge(int v[], int s, int m, int e) {
    int tmp[(e - s) + 1];
    int i = s, j = m + 1, k = 0;
    while (i <= m && j <= e) {
        if (v[i] < v[j]) {
            tmp[k++] = v[i++];
        } else {
            tmp[k++] = v[j++];
        }
    }
    for (; i <= m; i++, k++) {
        tmp[k] = v[i];
    }
    for (; j <= e; j++, k++) {
        tmp[k] = v[j];
    }
    for (i = s, k = 0; i <= e; i++, k++) {
        v[i] = tmp[k];
    }
}

void mergeSort(int v[], int s, int e) {
    if (s < e) {
        int m = (s + e) / 2;
        mergeSort(v, s, m);
        mergeSort(v, m + 1, e);
        merge(v, s, m, e); // Aqui é a lógica da conquista
    }
}

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

int vtrLen(int* v){
 
    int len, i = 1;
    for (len = 0; v[len] != '\0' || v[len] != 0; ++len){
        i++;
    }
    return len;
        
}

void printVtr(int* v){

    char ignore;
    char len = vtrLen(v);

    for (int i = 0; i < len; i++){
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
    cpyVtr(v, aux);

    system("clear");
    printf("-----------------------------------------\n");
    printf(" [B] - Ordenar Vetor");
    printf("\n-----------------------------------------\n");
    printf(" [Q] - Ordenar com QUICK SORT\n");
    printf(" [M] - Ordenar com MERGE SORT\n");
    printf(" [A] - Ordenar com QUICK SORT (salva ordenado)\n");
    printf(" [B] - Ordenar com MERGE SORT (salva ordenado)\n");
    scanf(" %c", &metodo);

    switch (metodo)
    {
    case 'Q':
        quickSort(aux, 0, vtrLen(aux)-1);
        system("clear");
        printf("-----------------------------------------\n");
        printf(" [Q] - Vetor Ordenado");
        printf("\n-----------------------------------------\n");
        printVtr(aux);
        break;
    case 'M':
        mergeSort(aux, 0, vtrLen(aux)-1);
        system("clear");
        printf("-----------------------------------------\n");
        printf(" [M] - Vetor Ordenado");
        printf("\n-----------------------------------------\n");
        printVtr(aux);
        break;
    case 'A':
        quickSort(v, 0, vtrLen(v)-1);
        system("clear");
        printf("-----------------------------------------\n");
        printf(" [A] - O vetor foi ordenado");
        printf("\n-----------------------------------------\n");
        break;
    case 'B':
        mergeSort(v, 0, vtrLen(v)-1);
        system("clear");
        printf("-----------------------------------------\n");
        printf(" [B] - O vetor foi ordenado");
        printf("\n-----------------------------------------\n");
        break;
    default:
        printf("\nNão valido\n");
        break;
    }
}

int* gerarVetor(int* v){

    system("clear");
    int len;
    printf("-----------------------------------------\n");
    printf(" [A] - Gerar Valores");
    printf("\n-----------------------------------------\n");
    printf("\n Digite o tamanho do vetor a ser gerado: ");
    scanf(" %d", &len);

    v = (int*) malloc(len * sizeof(int));

    for (int i = 0; i < len; i++){
        v[i] = rand() % RANDOM;
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
        case 'C':
            int x, idx;
            system("clear");
            printf("-----------------------------------------\n");
            printf(" [C] - Busca sequencial");
            printf("\n-----------------------------------------\n");
            printf(" Digite o valor a ser buscado: ");
            scanf(" %d", &x);
            idx = buscaSequencial(vetor, vtrLen(vetor), x);
            if (idx != -1){
                printf("\n-----------------------------------------\n");
                printf("\n [%d] encontrado em %d\n", x, idx + 1);
            }else{
                printf("\n-----------------------------------------\n");
                printf("\n [%d] não encontrado\n", x);
            }
            printf("\n Digite qualquer coisa para sair: ");
            scanf(" %d", &x);
            break;
        case 'D':
            int y, yidx;
            system("clear");
            printf("-----------------------------------------\n");
            printf(" [D] - Busca binária");
            printf("\n-----------------------------------------\n");
            printf(" Digite o valor a ser buscado: ");
            scanf(" %d", &y);

            //int* aux = (int*) malloc(vtrLen(vetor) * sizeof(int));
            //cpyVtr(vetor, aux);

            yidx = buscaBinaria(vetor, vtrLen(vetor), y);

            if (yidx != -1){
                printf("\n-----------------------------------------\n");
                printf("\n [%d] encontrado em %d\n", y, yidx + 1);
            }else{
                printf("\n-----------------------------------------\n");
                printf("\n [%d] não encontrado\n", y);
            }
            printf("\n Digite qualquer coisa para sair: ");
            scanf(" %d", &y);

            break;
        case 'E':
            printVtr(vetor);
            break;
        }
    }

}

int main(){

    int* vetor;

    menu(vetor);
    //hub(option, vetor);
    
    printf("\n\nPrograma encerrado com sucesso\n\n\n");
}