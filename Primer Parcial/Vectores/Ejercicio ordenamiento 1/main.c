#include <stdio.h>
#include <stdlib.h>
void ordenar(int[],int);
int main()
{
    int ve[12]={0},x;
    for(x=0;x<12;x++)
    {
        printf("\n Ingrese la recaduacion de la sucursal %d:",x+1);
        scanf("%d",&ve[x]);
    }
    ordenar(ve,12);
    for(x=0;x<12;x++)
    {
        printf("\n El ordenamiento de mayor a menor es:%d",ve[x]);
    }
    return 0;
}
void ordenar (int a[],int n)
{
    int aux,x,sen;
    sen=0;
    while(sen==0)
    {
        sen=1;
        for(x=0;x<n-1;x++)
        {
            if(a[x]<a[x+1])
            {
                aux=a[x+1];
                a[x+1]=a[x];
                a[x]=aux;
                sen=0;
            }
        }
        n--;
    }
}
