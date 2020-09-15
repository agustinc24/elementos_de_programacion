#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int validar (int,int,char [10]);
void ordenar (int [],int [], int);
void punto_d (int [][50], int ,int);
int buscar (char [10],char [][20],int);
int main ()
{
    char ms[6][20]={{0}},ts[10];
    int nc,mr,mp[6][50]={{0}},acum,x,z,vr[6]={0},vs[6]={0},pos, acum2;
    acum=acum2=0;
    for (x=0;x<6;x++)
    {
        printf("\n Ingrese tipo de stand %d:",x+1);
        gets(ms[x]);
    }
    nc=validar(0,50,"caja");
    while (nc!=0)
    {
        printf ("\Ingrese tipo de stand:");
        scanf("%s",&ts);
        pos=buscar(ts,ms,6);
        printf ("\Ingrese monto recaudado:");
        scanf("%d",&mr);
        mp[pos][nc-1]+=mr;
        nc=validar(0,50,"caja");
    }
    for (z=0;z<50;z++)
    {
        acum=0;
        for(x=0;x<6;x++)
        {
            acum+=mp[x][z];
        }
        printf("\n El total recaudado de la caja %d es:%d",z+1,acum);
    }

    for (x=0;x<6;x++)
    {
        acum2=0;
        for (z=0;z<50;z++)
        {
            acum2+=mp[x][z];
            if (mp [x][z]==0)
                puts ("\n El numero de caja %d del stand %s no realizo ventas",z+1,ms[x]);
        }
        vr[x]=acum2;
        vs[x]=x;
    }
ordenar (vr,vs,6);
    for (x=0;x<6;x++)
    {
        printf("\n Recaudacion del stand:%s \t %d",ms [vs[x]],vr[x]);
    }
punto_d(mp,6,50);

}
int buscar (char a[10],char b[][20], int n)
{
    int p=-1,x=0;
    while (p==-1&&x<n)
    {
        if(strcmpi(a,b[x])==0)
            p=x;
        else
            x++;
    }
    return p;
}
int validar(int a,int b,char c [10])
{
    int x;
    do
    {
        printf("\n Ingrese %s",c);
        scanf("%d",&x);
    }while (x<a||x>b);
    return x;
}
void ordenar (int a [],int b [], int n)
{
    int sen=0,x,aux,aux2;
    while (sen==0)
    {
        sen=1;
        for (x=0;x<n-1;x++)
        {
            if (a[x]<a[x+1])
            {
                aux=a[x];a[x]=a[x+1];a[x+1]=aux;
                aux2=b[x];b[x]=b[x+1];b[x+1]=aux2;sen=0;
            }
        }
        n--;
    }
}
void punto_d (int a [][50], int b, int c)
{
    int maxc,max,z,x,acum=0,cont=0,prom;
    for (z=0;z<c;z++)
    {
        acum=0;cont=0;
        for (x=0;x<b;x++)
        {
            if (a[x][z]!=0)
            {
                cont++; acum+=a[x][z];
            }
        }
        prom=acum/cont;
        if (z==0||max<prom)
        {
            max=prom;maxc=z+1;
        }
    }
    printf("\n La caja %d tiene el mayor promedio de ventas de %d",maxc,max);
}

