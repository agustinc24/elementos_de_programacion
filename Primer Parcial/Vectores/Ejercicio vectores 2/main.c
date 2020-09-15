#include <stdio.h>
#include <stdlib.h>
void carga_vector (float [], int);
void mostrar_vector (float [], int);
int main()
{
    float vec [10]={10};
    carga_vector (vec,10);
    mostrar_vector (vec,10);
    return 0;
}
void carga_vector (float a [], int n)
{
    int x;
    for (x=0;x<n;x++)
    {
        printf("Ingrese valor %d:",x+1);
        scanf ("%f",&a[x]);
    }
}
void mostrar_vector (float a[], int n)
{
    int x;
    for (x=0;x<n;x++)
    {
        printf("\t %6.2f",a [x]);
    }
}
