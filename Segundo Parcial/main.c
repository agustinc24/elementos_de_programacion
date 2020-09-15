#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int cod;
    char desc[30];
    int ru;
    float precio;
    int pp;
    int stock;
}merca;
typedef struct
{
    int cod;
    int cant;
    int nrocli;
    int nroped;
    int dia;
}pedidos;
int cargar_archivo(merca[],int);
int buscar(int,merca[],int);
void ordenar(float[],int[],int);
void imprimir_d(float[],int[],int);
void grabar_archivo(merca[],int);
int main()
{
    int x,cant,ant,acumc,pos,sen,max,maxp,vdia[31]={0},codi;
    float acumm,vec[31]={0};
    merca mer[4000];
    pedidos pe;
    cant=cargar_archivo(mer,4000);
    FILE * PP;
    if((PP=fopen("PEDIDOS.dat","rb"))==NULL)
    {
        puts("Error");
        exit(0);
    }
    fread(&pe,sizeof(pedidos),1,PP);
    while(!feof(PP))
    {
        ant=pe.cod;
        codi=pe.cod;
        pos=buscar(codi,mer,cant);
        acumm=0;
        acumc=0;
        while(ant==pe.cod)
        {
            if(mer[pos].stock>=pe.cant)
            {
                mer[pos].stock-=pe.cant;
                acumm+=pe.cant*mer[pos].precio;
                acumc+=pe.cant;
                vec[pe.dia-1]+=mer[pos].precio*pe.cant;
                vdia[pe.dia-1]=pe.dia;
            }
            else
                printf("\n No hay stock");
        }
        if(mer[pos].ru<=20&&acumm!=0)
        {
            printf("\n prodcuto:%d monto:%f cantidad:%d",ant,acumm,acumc);
        }
        if(sen==0||max<acumc)
        {
            sen=1;
            max=acumc;
            maxp=ant;
        }
    }
    printf("\n Producto mas solicitado:%d",maxp);
    grabar_archivo(mer,cant);
    ordenar(vec,vdia,31);
    imprimir_d(vec,vdia,31);
    return 0;
}
int cargar_archivo(merca a[],int n)
{
    int x;
    FILE * NN;
    if((NN=fopen("STOCK.dat","rb"))==NULL)
    {
        puts("Error");
        exit(0);
    }
    fread(&a[x],sizeof(merca),1,NN);
    while(feof(NN)&&x<n)
    {
        x++;
        fread(&a[x],sizeof(merca),1,NN);
    }
    fclose(NN);
    return x;
}
int buscar(int a,merca b[],int n)
{
    int x,p;
    x=0;
    p=-1;
    while(p==-1&&x<n)
    {
        if(a==b[x].cod)
            p=x;
        else
            x++;
    }
    return p;
}
void grabar_archivo(merca a[],int n)
{
    int x;
    FILE * NN;
    if((NN=fopen("stock_act.dat","wb"))==NULL)
    {
        puts("ERROR");
        exit(0);
    }
    for(x=0;x<n;x++)
    {
        fwrite(&a[x],sizeof(merca),1,NN);
    }
    fclose(NN);
}
void ordenar(float a[],int b[],int n)
{
    int x,aux1,aux2,sen;
    sen=0;
    while(sen==0)
    {
        sen=1;
        for(x=0;x<n-1;x++)
        {
            if(a[x]<a[x+1])
            {
                aux1=a[x];
                a[x]=a[x+1];
                a[x+1]=aux1;
                aux2=b[x];
                b[x]=b[x+1];
                b[x+1]=aux2;
                sen=0;
            }
        }
        n--;
    }
}
imprimir_d(float a[],int b[],int n)
{
    int x;
    printf("\n FECHA/monto recaudado x producto");
    for(x=0;x<n;x++)
    {
        printf("\n %d   %f",b[x],a[x]);
    }
}
