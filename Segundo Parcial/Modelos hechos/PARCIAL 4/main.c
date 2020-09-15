#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    int nroven;
    int nroart;
    float imp;
}merca;
typedef struct
{
    int nroven;
    char nom[25];
}vendedores;
typedef struct
{
    int nrocli;
    char razon[30];
    int nroven;
    int nroart;
    int cantven;
    float preuni;
}hoy;
int carga_archivo(merca[],int);
int carga_archivo2(vendedores[],int);
int validar(int,int,char[15]);
int buscar(int,int,merca[],int);
int buscar2(int,vendedores[],int);
void grabar_archivo(merca[],int);
int main()
{
    int x,cant,pos,ant,vv[5]={0},pos2,cant2,max,maxv,pos3,y,vend,art;
    float imp,acum;
    x=0;
    merca mer[100];
    vendedores ven[5];
    hoy h;
    cant=carga_archivo(mer,100);
    cant2=carga_archivo2(ven,5);
    h.nrocli=validar(1,1000,"cliente");
    while(h.nrocli!=0)
    {
            printf("\n Ingrese Razon Social:");
            fflush(stdin);
            scanf("%s",&h.razon);
        ant=h.nrocli;
        printf("\n Razon social:%s",h.razon);
        acum=0;
        while(ant==h.nrocli)
        {
            h.nroven=validar(1,5,"vendedor");
            h.nroart=validar(1,20,"articulo");
            printf("\n Ingrese cantidad vendida:");
            scanf("%d",&h.cantven);
            printf("\n Ingrese precio unitario:");
            scanf("%f",&h.preuni);
            printf("\n Nro. articulo:%d",h.nroart);
            imp=h.preuni*h.cantven;
            printf("\t Importe de la venta:%f",imp);
            acum+=imp;
            vend=h.nroven;
            art=h.nroart;
            pos=buscar(vend,art,mer,cant);
            mer[pos].imp+=imp;
            vv[h.nroven-1]+=h.cantven;
            h.nrocli=validar(1,1000,"cliente");
        }
    }

    grabar_archivo(mer,cant);
    for(x=0;x<5;x++)
    {
        if(vv[x]==0)
        {
            pos2=buscar2(x,ven,cant2);
            printf("\n Vendedor que no tuvo ventas:%s",ven[pos2].nom);
        }
        if(x=0||max<vv[x])
        {
            max=vv[x];
            maxv=x;
        }
    }
    pos3=buscar2(maxv,ven,cant2);
    printf("\n Vendedor que realizo mas ventas:%s",ven[pos3].nom);
    return 0;
}
int carga_archivo(merca a[],int n)
{
    int x;
    x=0;
    FILE * NN;
    if((NN=fopen("ven_ven.dat","rb"))==NULL)
    {
        puts("Error");
        exit(0);
    }
    fread(&a[x],sizeof(merca),1,NN);
    while(!feof(NN)&&x<n)
    {
        x++;
        fread(&a[x],sizeof(merca),1,NN);
    }
    fclose(NN);
    return x;
}
int validar(int a,int b ,char c[15])
{
    int x;
    do
    {
        printf("\n Ingrese %s:",c);
        scanf("%d",&x);
    }while(x<a||x>b);
    return x;
}
int carga_archivo2(vendedores a[],int n)
{
    int x;
    x=0;
    FILE * NN;
    if((NN=fopen("VENDEDOR.dat","rb"))==NULL)
    {
        puts("Error");
        exit(0);
    }
    fread(&a[x],sizeof(vendedores),1,NN);
    while(!feof(NN)&&x<n)
    {
        x++;
        fread(&a[x],sizeof(vendedores),1,NN);
    }
    fclose(NN);
    return x;
}
void grabar_archivo(merca a[],int n)
{
    int x;
    FILE * NN;
    if((NN=fopen("ven_ven_act.dat","wb"))==NULL)
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
int buscar(int a,int d,merca b[],int n)
{
    int x,p;
    x=0;
    p=-1;
    while(p==-1&&x<n)
    {
        if(a==b[x].nroven&&d==b[x].nroart)
            p=x;
        else
            x++;
    }
    return p;
}
int buscar2(int a,vendedores b[],int n)
{
    int x,p;
    x=0;
    p=-1;
    while(p==-1&&x<n)
    {
        if(a==b[x].nroven)
            p=x;
        else
            x++;
    }
    return p;
}
