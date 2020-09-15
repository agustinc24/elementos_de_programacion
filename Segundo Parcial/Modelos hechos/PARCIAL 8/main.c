#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int nart;
    float pu;
}arti;
typedef struct
{
    int nven;
    int nprov;
}vende;
typedef struct
{
    int nven;
    int mes;
    int nart;
    int cantve;
}ventas;
int carga_archivo1 (arti[],int);
int carga_archivo2 (vende[],int);
int validar (int,int,char [10]);
int buscar (int,vende[],int);
int buscar2(int,arti[],int);
void informa_b(int [],int);
void ordenar(float [], int [],int);

int main()
{
    arti art[5000];
    vende vend[30];
    ventas ve;
    int pos,pos2,cant,cant2,x,z,cont,v[30]={0},vec[12]={0},maxv,mayven,mv[][12]={{0}},ven,arts;
    float ma[][12]={{0}},vi[12]={0},acum,acumgen;
    x=z=cont=acum=acumgen=0;
    cant=carga_archivo2(vend,30);
    cant2=carga_archivo1(art,5000);


    ve.nven=validar(0,30,"vendedor");

    while (ve.nven!=0)
    {
        ve.mes=validar(1,12,"validar");
        ve.nart=validar(1000,8000,"articulo");
        ve.cantve=validar(1,100,"unidades");
        ven=ve.nven;
        pos=buscar(ven,vend,cant);
        arts=ve.nart;
        pos2=buscar2(art,art,cant2);
        ma[vend[pos].nprov-1][ve.mes-1]+=ve.cantve*art[pos2].pu;
        mv[ve.nven-1][ve.mes-1]+=ve.cantve;
    }
    printf("\n Provincia-MES 1-MES 2-MES 3-MES 4-MES 5-MES 6-MES 7-MES 8-MES 9- MES- 10-MES 11-MES 12");
    for(x=0;x<24;x++)
    {
        printf("\n %d",x+1);
        for(z=0;z<12;z++)
        {
            printf("\t %d",ma[x][z]);
        }
    }
    for (x=0;x<30;x++)
    {
        acum=0;
        for(z=0;z<12;z++)
        {
            if(mv[x][z]==0)
                cont++;
            else
                cont=0;
            if(cont==4)
                v[x]=x+1;
            acum+=mv[x][z];
        }
        if(x==0||maxv<acum)
        {
            maxv=acum;
            mayven=x+1;
        }
    }
    printf("\n El vendedor que vendio mas unidades %d vendio %d unidades",mayven,maxv);
    for (x=0;x<30;x++)
    {
        acumgen=0;
        for(z=0;z<12;z++)
        {
            acumgen+=mv[x][z];
        }
        if(acumgen==maxv)
            printf("\n El vendedor que vendio mas unidades %d vendio %d unidades",x+1,maxv);
    }

    informa_b(v,30);
    for(z=0;z<12;z++)
    {
        for (x=0;x<24;x++)
        {
            vec[z]=z+1;
            vi[z]=ma[x][z];
        }
    }
    ordenar(vi,vec,12);
    printf("\n Mes: \t Importe vendido:");
    for(x=0;x<12;x++)
    {
        printf("\n %d \t %f",vec[x],vi[x]);
    }
    return 0;
}
int carga_archivo1(arti a [], int b)
{
    int x;
    FILE * AR;
    if((AR=fopen("ARTICULOS.dat","rb"))==NULL)
    {
        puts ("Error");
        exit(0);
    }
    fread(&a[x],sizeof(arti),1,AR);
    while (!feof(AR)&&x<b)
    {
        x++;
        fread(&a[x],sizeof(arti),1,AR);
    }
    fclose(AR);
}
int carga_archivo2(vende a [], int b)
{
    int x;
    FILE * VE;
    if((VE=fopen("ARTICULOS.dat","rb"))==NULL)
    {
        puts ("Error");
        exit(0);
    }
    fread(&a[x],sizeof(arti),1,VE);
    while (!feof(VE)&&x<b)
    {
        x++;
        fread(&a[x],sizeof(arti),1,VE);
    }
    fclose(VE);
}
int validar(int a,int b, char c [10])
{
    int x;
    do
    {
        printf("\n Ingres %s:",c);
        scanf("%d",&x);
    }while(x<a||x>b);
    return x;
}
int buscar(int a,vende b [],int c)
{
    int p,x;
    p=-1;x=0;
    while(p==-1&&x<c)
    {
        if (a==b[x].nven)
            p=x;
        else
            x++;
    }
    return p;
}
int buscar2(int a,arti b[],int c)
{
    int p,x;
    p=-1;x=0;
    while(p==-1&&x<c)
    {
        if (a==b[x].nart)
            p=x;
        else
            x++;
    }
    return p;
}
void informa_b(int a[],int b)
{
    int x;
    for(x=0;x<b;x++)
    {
        if(a[x]!=0)
            printf("\n El vendedor %d no tuvo ventas en 3 meses consecutivos",a[x]);
    }
}
void ordenar(float a[],int b[],int n)
{
    int x,aux,aux2,sen=0;
    while (sen==0)
    {
        sen=1;
        for(x=0;x<n-1;x++)
        {
            if(a[x]<a[x+1])
            {
                aux=a[x+1];a[x+1]=a[x];a[x]=aux;aux2=b[x+1];b[x+1]=b[x];b[x]=aux2;sen=0;
            }
            n--;
        }
    }
}
