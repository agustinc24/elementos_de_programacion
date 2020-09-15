#include <stdio.h>
#include <stdlib.h>
void CARGAR (int [4][12], int, int);
int SUCMENOR (int [], int);
int main()
{
    int Mkb [4][12]={{0}},x,i,v[4]={0};
    CARGAR(Mkb,4,12);

    for (x=0;x<4;x++)
    {
        for (i=0;i<12;i++)
        {
            v[x]+=Mkb[x][i];
        }
    printf ("\n La cantidad de pedidos de la sucursal %d es:%d",x+1,v[x]);
    }

    SUCMENOR (v,4);
    return 0;
}
void CARGAR(int a [4][12],int f, int c)
{
    int s,r,u;

    do
    {
        printf("\n Ingrese numero de sucursal:");
        scanf("%d",&s);
    }while ((s<1||s>f)&&s=!0);

    while (s=!0)
    {
        do
        {
            printf("\n Ingrese codigo de rubro:");
            scanf("%d",&r);
        }while (r<1||r>c);

        printf ("\n Ingrese cantidad de unidades pedidas:");
        scanf ("%d",&u);

        a[s-1][r-1]=a[s-1][r-1]+u;
        do
        {
            printf("\n Ingrese numero de sucursal:");
            scanf("%d",&s);
        }while ((s<1||s>4)&&s=!0);
    }
}

int SUCMENOR(int a[4],int b)
{
    int min,smen,x;
    min=a[0];
    smen=1;
    for (x=0;x<b;x++)
    {
        if (min>a[x])
        {
            min=a[x];
            smen=x+1;
        }
    }
    printf("\n La sucursal %d fue la que pidio la menor cantidad de %d",smen,min);
    return x;
}
