#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int prod;
    int sto;
    float pu;
}produ;
typedef struct
{
    int ncli;
    int mes;
    int nprod;
    int cantv;
}ventas;
int carga_archivo(produ [],int);
int validar (int, int, char);
int buscar (int,produ [],int);
void ordenar (int [],int);
void genera_archivo(produ [],int);

int main()
{
    int cant,ncli,mes,nprod,cantv,pos,vart[800]={0},sen,maxa,maxu,x,z,vcli[999]={0},cont;
    float ma[][12]={{0}};
    sen=x=z=cont=0;
    produ prod[800];
    ventas ven;
    cant=carga_archivo(prod,800);
    ven.ncli=validar(0,999,"cliente");

    while (ven.ncli!=0)
    {
        ven.mes=validar (1,12,"mes");
        do
        {
            printf("\n Ingrese numero de producto:");
            scanf("%d",&ven.nprod);
        }while (ven.nprod<10000000||ven.nprod>99999999);
        printf("\n Ingrese cantidad de unidades vendidas:");
        scanf("%d",&ven.cantv);
        nprod=ven.nprod;
        pos=buscar(nprod,prod,cant);
        if (pos!=-1)
        {
            if (ven.cantv<=prod[pos].sto)
            {
                prod[pos].sto-=ven.cantv;
                ma[ven.ncli-1][ven.mes-1]+=ven.cantv*prod[pos].pu;
            }
            if (sen==0||maxu<ven.cantv)
            {
                maxu=cantv;
                maxa=nprod;
                sen=1;
            }
        }
        else
            printf("\n No hay stock");
        ven.ncli=validar(1,999,"cliente");
    }
    if (prod[pos].sto==0)
            {
                vart[pos]=nprod;
            }
    genera_archivo(prod,cant);
    for (x=0;x<999;x++)
    {
        cont=0;
        for (z=0;z<12;z++)
        {
            if (ma[x][z]>0)
                cont++;
        }
        if (cont>=3)
        {
            vcli[x]=x;
        }
    }
    printf("\n Cliente/Mes \t 1 2 3 4 5 6 7 8 9 10 11 12");
    for (x=0;x<999;x++)
    {

        if (x==vcli[x])
        {
            printf("\n %d/",x+1);
            for(z=0;z<12;z++)
            {
                printf("%d \t %f",z+1,ma[x][z]);
            }
        }
    }
    ordenar(vart,cant);
    printf("\n Los articulos que ya no tienen stock son:");
    for(x=0;x<cant;x++)
    {
        printf("\n %d",vart[x]);
    }
    printf("\n El articulo %d fue el que mas unidades vendio con un total de %d unidades",maxa,maxu);
    return 0;
}
int carga_archivo(produ a[],int b)
{
    int x;
    FILE * PR;
    if((PR=fopen("productos.dat","rb"))==NULL)
    {
        puts("Error");
        exit(0);
    }
    fread(&a[x],sizeof(produ),1,PR);
    while (!feof(PR)&&x<b)
    {
        x++;
        fread(&a[x],sizeof(produ),1,PR);
    }
    return x;
}
int validar(int a, int b, char c)
{
    int x;
    do
    {
        printf("\n Ingrese %s:",c);
        scanf("%d",&x);
    }while (x<a||x>b);
    return x;
}
int buscar (int a, produ b [], int c)
{
    int x,p;
    x=0; p=-1;
    while (p==-1&&x<c)
    {
        if (a==b[x].prod)
            p=x;
        else
            x++;
    }
    return x;
}
void ordenar(int a [],int b)
{
    int aux,x,sen=0;
    while (sen==0)
    {
        sen=1;
        for (x=0;x<b;x++)
        {
            if (a[x]>a[x+1])
            {
                aux=a[x+1];
                a[x+1]=a[x];
                a[x]=aux;
                sen=0;
            }
        }
        b--;
    }
}
void genera_archivo(produ a [], int b)
{
    int x;
    FILE * NN;
    if((NN=fopen("PROD_ACT.dat","wb"))==NULL)
    {
        puts("Error");
        exit(0);
    }
    for (x=0;x<b;x++)
    {
        fwrite(&a[x],sizeof(produ),1,NN);
    }
}
