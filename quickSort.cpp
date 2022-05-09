#include<stdio.h>
#include <conio.h>
#include <stdlib.h>


using namespace std;

void troca(int v[], int a,int b)
{

    int aux = v[a];
    v[a] = v[b];
    v[b] = aux;
}



int particiona(int v[],int s, int e)
{
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




int quickSort(int v[], int s, int e)
{
    if (s<e)
    {
        int p = particiona(v,s,e);
        quickSort(v,s,p-1);
        quickSort(v,p+1,e);
    }
}

void imprimeVetor(int v[], int n)
{
    for(int i=0; i<n; i++)
    {
        printf("%d ",v[i]);

    }
    printf("\n");
}




int main()
{
    int i=0;
        int n=8;

    int v[n] = {3, 5, 1, 4, 6, 8, 7, 3};

   printf("%dan", v[0]);


    imprimeVetor(v,n);
    quickSort(v,0,n-1);
    printf("\n");
    imprimeVetor(v,n);


    return 0;
}
