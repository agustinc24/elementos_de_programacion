#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int nroart;
    char cara;
    char des[25];
    float puni;
    int sto;
}merca;
typedef struct
{
    int nroven;
    int nart;
    char carac;
    int dia;
    int cantven;
}ventas;
int carga_archivo(merca[],int);
void nuevoarch(merca[],int);
void informa_menor(float,int);
int buscar(int,merca[],int);
void imprimo(float[],int);
int main()
{
    int x,can,ant,pos,acu1,vdia[31]={0},sen=0,vme,art;
    float acu2,menor;
    x=0;
    merca mer[2000];
    ventas ven;
    can=carga_archivo(mer,2000);
    FILE * FF;
    if((FF=fopen("VENTASMAYO.dat","rb"))==NULL)
    {
        puts("ERROR");
        exit(0);
    }
    fread(&ven,sizeof(ventas),1,FF);
    while(!feof(FF))
    {
        ant=ven.nroven;
        acu1=acu2=0;
        while(ant==ven.nroven)
        {
            art=ven.nart;
            pos=buscar(art,mer,can);
            if(pos!=-1)
            {
                if(ven.cantven<=mer[pos].sto)
                {
                    mer[pos].sto-=ven.cantven;
                    acu1+=ven.cantven;
                    acu2+=ven.cantven*mer[pos].puni;
                    vdia[ven.dia-1]+=ven.cantven*mer[pos].puni;
                }
                else
                {
                    printf("\n No hay stock bestia");
                }
            }
            else
                printf("\n Error crack");

             fread(&ven,sizeof(ventas),1,FF);
        }
        printf("\n Vendedor:%d \t Importe:%f",acu1,acu2);
        if(sen==0||acu2>menor)
        {
            sen=1;
            menor=acu2;
            vme=ant;
        }
    }
    nuevoarch(mer,can);
    informa_menor(vme,menor);
    imprimo(vdia,31);
    return 0;
}
int carga_archivo(merca a[],int n)
{
    int x;
    x=0;
    FILE * FR;
    if((FR=fopen("STOCK.dat","rb"))==NULL)
    {
        puts("ERROR");
        exit(0);
    }
    fread(&a[x],sizeof(merca),1,FR);
    while(!feof(FR)&&x>n)
    {
        x++;
        fread(&a[x],sizeof(merca),1,FR);
    }
    fclose(FR);
    return x;
}
int buscar(int a,merca b[],int c)
{
    int x=0,p=-1;
    while(p==-1&&x<c)
    {
        if(a==b[x].nroart)
            p=x;
        else
            x++;
    }
    return x;
}
void nuevoarch(merca a[],int n)
{
    int x;
    FILE * FF;
    if((FF=fopen("STOCK_ACT.dat","wb"))==NULL)
    {
        puts("ERROR");
        exit(0);
    }
    for(x=0;x<n;x++)
    {
        fwrite(&a[x],sizeof(merca),1,FF);
    }
    fclose(FF);
}
void informa_menor(float a,int b)
{
    printf("\n Menor vendedor:%d \t Importe:%f",b,a);
}
void imprimo(float a[],int n)
{
    int x;
    for(x=0;x<n;x++)
    {
        printf("\n Dia:%d \t Importe Vendido:%f",x+1,a[x]);
    }
}
