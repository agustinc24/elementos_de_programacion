#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void MOSTRAR (float [],int);
void SUMA (float [],float[], float [], int);
void MOSTRARINV (float [],float [], int);
int BUSCAR (int, float [], int);
int main()
{
    int x,dato,pos;
    float VA[10]={0},VB[10]={0}, VC[10]={0}, VD[10]={0};
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
    MOSTRARINV (VC,VD,x);

    int max=VA[0];
    int pos_mayor=0;
    for(x=1;x<2;x++)
    {
        if(max<VA[x])
        {
            max=VA[x];
            pos_mayor=x;
        }
    }
    printf("\n Mayor VA= %d \tPosicion mayor =%d",max,pos_mayor);
    int min;
    for (x=0;x<2;x++)
    {
        if (x==0||min>VB[x])
        {
            min=VB[x];
        }
    }
    for (x=0;x<2;x++)
    {
        if (VB[x]==min)
        {
            printf("\n Menores VB= %d \t Posiciones menores=%d",min,x);
        }
    }


    printf("\n Ingrese dato a encontrar en VC:");
    scanf("%d",&dato);
    pos=BUSCAR (dato,VC,2);
    printf("\n La posicion del dato en VC es:%d",pos);

    return 0;
}
int BUSCAR (int a, float b [], int c)
{
    int pos=-1,x=0;

    while (pos==-1&&x<c)
    {
        if (a==b[x])
            pos=x;
        else
            x++;
    }
    return pos;
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
void MOSTRARINV (float a [], float b[], int c)
{
    int m,z;
    z=1;
    for (m=0;m<c;m++)
    {b[m]=a[z-m];
    printf("\t \n %6.2f",b[m]);

    }
    return m;
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
