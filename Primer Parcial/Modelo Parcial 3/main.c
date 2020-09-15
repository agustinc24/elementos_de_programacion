#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void carga_genero (char [][11]);
int validar (int, int, char [10]);
int buscar (char [11], char [7][11], int);
void ordenar (int [], int [], int);

int main ()
{
    char mg[7][11]={{0}},gen[10];
    int mes,pos,cant,mcan[7][12]={{0}},acum,acumgen,acum2,contm,vp[12]={0},vpp[12]={0},z,x;
    float prom;
    acum=acumgen=acum2=contm=0;

    carga_genero(mg);
    mes=validar(0,12,"mes");
    while (mes!=0)
    {
        printf("\Ingrese genero:");
        scanf("%s",&gen);
        pos=buscar(gen,mg,7);
        printf("Ingrese cantidad alquilada:");
        scanf("%d",&cant);
        mcan[pos][mes-1]+=cant;
        mes=validar(0,12,"mes");
    }

    for (x=0;x<7;x++)
    {
        acum=0;
        for (z=0;z<12;z++)
        {
            acumgen+=mcan[x][z];
            if (mcan[x][z]!=0)
                acum+=mcan[x][z];
        }
        prom=acum/7;
        printf("\n El promedio de peliculas alquiladas del genero %s es:%f",mg[x],prom);
    }
    printf ("\n El total de peliculas alquiladas en 2018 es:%d",acumgen);

    for (z=0;z<12;z++)
    {
        acum2=0;
        for (x=0;x<7;x++)
        {
            acum2+=mcan[x][z];
        }
        vp[z]=acum2;
        vpp[z]=z;
    }
    ordenar(vp,vpp,12);
    for (z=0;z<12;z++)
    {
        printf("\n Mes:%d \t Total alquileres:%d",vpp[z]+1,vp[z]);
    }
    for (z=0;z<12;z++)
    {
        for (x=0;x<7;x++)
        {
            if (mcan [x][z]==0)
                contm++;
        }
    }
printf("\n No registraron alquiler %d",contm);

}

void carga_genero (char a [][11])
{
    int x;
    for (x=0;x<7;x++)
    {
        printf("Ingrese genero:");
        gets(a[x]);
    }
}
int validar (int a, int b, char c [10])
{
    int x;
    do
    {
        printf ("\Ingrese %s:",c);
        scanf ("%d",&x);
    }while (x<a||x>b);
    return x;
}
int buscar (char a [11],char b [][11], int n)
{
    int x=0,p=-1;
    while (p==-1&&x<n)
    {
        if(strcmpi(a,b[x])==0)
            p=x;
        else
            x++;
    }
    return p;
}
void ordenar (int a [], int b[], int n)
{
    int x,aux,aux2,sen=0;
    while (sen==0)
    {
        sen=1;
        for (x=0;x<n-1;x++);
        {
            if (a[x]>a[x+1])
            {
                aux=a[x];
                a[x]=a[x+1];
                a[x+1]=aux;
                aux2=b[x];
                b[x]=b[x+1];
                b[x+1]=aux2;
                sen=0;
            }
        }
        n--;
    }
}
