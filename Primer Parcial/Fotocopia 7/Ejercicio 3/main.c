#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void MOSTRAR (float [],int);
void SUMA (float [],float[], float [], int);
int main()
{
    int x;
    float VA [10]={0},VB [10]={0}, VC [10]={0};
    for (x=0;x<2;x++)
    {
        printf ("Ingrese valor real %d:",x+1);
        scanf ("%f",&VA[x]);
        VB[x]=sqrt(VA[x]);
    }
    MOSTRAR (VA,x);
    MOSTRAR (VB,x);
    SUMA (VA,VB,VC,x);
    MOSTRAR (VC,x);
    return 0;
}
void MOSTRAR (float a [],int b)
{
    int z;
    for (z=0;z<b;z++)
    {
        printf("\t \n %6.2f",a[z]);

    }
    return z;
}
void SUMA (float a [], float b [], float c [], int d)
{
    int s;
    for (s=0;s<d;s++)
    {
        c[s]=a[s]+b[s];
    }
    return s;
}

