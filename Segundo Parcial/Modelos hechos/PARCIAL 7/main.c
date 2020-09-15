#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int cuenta;
    char nom [24];
    float saldo;
}saldos;
typedef struct
{
    int cuentam;
    int mes;
    int dia;
    int cod;
    float imp;
}movimientos;
int carga_archivo(saldos [],int,int[]);
int buscar(int,saldos [],int);
void nuevoarch (saldos [],int);
void informar (int [],int);

int main()
{
    int x,can,pos,v[2000]={0},z,vc[2000]={0},VH[2000]={0};
    z=0;x=0;
    saldos sal [2000];
    movimientos movi;
    can=carga_archivo(sal,2000,VH);
     for (x=0;x<can;x++)
    {
        v[x]=sal[x].saldo;
    }
    FILE * MO;
    if((MO=fopen("MOVIMIENTOS.dat","rb"))==NULL)
    {
        printf("\n Error");
        exit(0);
    }
    fread(&movi,sizeof(movimientos),1,MO);
    while (!feof(MO))
    {
     pos=buscar(movi.cuentam,sal,can);
     if (pos!=-1)
     {
         if (movi.cod==1)
         {
             sal[pos].saldo+=movi.imp;
         }
         else
         {
             sal[pos].saldo-=movi.imp;
             VH[pos]++;
         }
     }
     else
        printf("\n ERROR");

     fread(&movi,sizeof(movimientos),1,MO);
    }
    fclose(MO);
    nuevoarch(sal,can);
    for (x=0;x<can;x++)
    {
        if (v[x]==sal[x].saldo)
        {
            vc[z]=sal[x].cuenta;
            z++;
        }
    }
    informar(vc,z);
    for (x=0;x<can;x++)
    {
        printf("\n El saldo de la cuenta %d es:%f",sal[x].cuenta,sal[x].saldo);
    }
    for (x=0;x<can;x++)
    {
        if(VH[x]>5)
        {
            printf("\n La cuenta %d ha realizado mas de 5 extracciones",sal[x].cuenta);
        }
    }
    return 0;
}

int carga_archivo(saldos a [],int n,int b[])
{
    int x=0;
    FILE * NN;
    if((NN=fopen("SALDANTE.dat","rb")==NULL))
    {
        printf("\n Error");
        exit(0);
    }
    fread(&a[x],sizeof(saldos),1,NN);
    while (!feof(NN)&&x>n)
    {
        x++;
        b[x]=a[x].cuenta;
        fread(&a[x],sizeof(saldos),1,NN);
    }
    fclose(NN);
    return x;
}
int buscar (int a,saldos b [], int c)
{
    int p,x;
    x=0;p=-1;
    while (p==-1&&x<c)
    {
        if (a==b[x].cuenta)
            p=x;
            else
                x++;
    }
    return x;
}
void nuevoarch(saldos a [], int n)
{
    int x;
    FILE * MM;
    if ((MM=fopen("SALDANTE_ACT.dat","wb"))==NULL)
    {
        printf("\n Error");
        exit(0);
    }
    for (x=0;x<n;x++)
    {
        fwrite(&a[x],sizeof(saldos),1,MM);
    }
    fclose(MM);
}
void informar(int a [], int b)
{
    int x;
    for (x=0;x<b;x++)
    {
        printf("\n Las cuentas sin movimientos son:%d",a[x]);
    }
}
