#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void MOSTRAR (float [],int);
int main()
{
    int x;
    float VA [10]={0},VB [10]={0};
    for (x=0;x<10;x++)
    {
        printf ("Ingrese valor real %d:",x+1);
        scanf ("%f",&VA[x]);
        VB[x]=sqrt(VA[x]);
    }
    MOSTRAR (VA,x);
    MOSTRAR (VB,x);
    return 0;
}
void MOSTRAR (float a [],int b)
{
    int z;
    for (z=0;z<b;z++)
    {
        printf("\t %4.2f",a[z]);

    }
    return z;
}
