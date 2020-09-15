#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int nfila;
    int cantv;
    float pre;
}datos;
typedef struct
{
    int nfila;
    int cants;
}ventas;
int carga_archivo (datos[],int);
void informar_b(int [],int);
int buscar(int,datos[],int);
void graba_archivo(datos[],int);
int main()
{
    datos dat[600];
    ventas ven;
    int x,pos,cant,v[20]={0},fila,vr[20]={0};
    float vd[20]={0};
    cant=carga_archivo(dat,600);

    FILE * VE;
    if((VE=fopen("ventas.dat","rb"))==NULL)
    {
        puts("Error");
        exit(0);
    }
    fread(&ven,sizeof(ventas),1,VE);
    while(!feof(VE))
    {
        fila=ven.nfila;
        pos=buscar(fila,dat,cant);
        if(ven.cants<=dat[pos].cantv)
        {
            dat[pos].cantv-=ven.cants;
            vd[fila-1]+=ven.cants*dat[pos].pre;
            v[fila-1]=dat[pos].cantv;
        }
        else
        {
            printf("\n No hay disponibilidad");
            vr[fila-1]+=ven.cants;
        }
        fread(&ven,sizeof(ventas),1,VE);
    }
    fclose(VE);
    for(x=0;x<20;x++)
    {
        printf("\n La disponibilidad de la fila %d es de:%d y monto recaudado fue de:%f",x+1,v[x],vd[x]);
    }
    informar_b(vr,20);
    graba_archivo(dat,cant);
    return 0;
}
int carga_archivo(datos a[],int n)
{
    int x=0;
    FILE * DA;
    if((DA=fopen("Vent_21Junio.dat","rb"))==NULL)
    {
        puts("Error");
        exit(0);
    }
    fread(&a[x],sizeof(datos),1,DA);
    while (!feof(DA)&&x<n)
    {
        x++;
        read(&a[x],sizeof(datos),1,DA);
    }
    fclose(DA);
    return x;
}
int buscar(int a,datos b [],int c)
{
    int x,p;
    x=0;p=-1;
    while (p==-1&&x<c)
    {
        if (a==b[x].nfila)
            p=x;
        else
            x++;
    }
    return p;
}
void informar_b(int a [], int b)
{
    int x=0;
    for(x=0;x<b;x++)
    {
        printf("\n De la fila %d fueron solicitadas y rechazadas %d butacas",x+1,a[x]);
    }
}
void graba_archivo(datos a[],int b)
{
    int x=0;
    FILE * NN;
    if((NN=fopen("Vent_21Julio.dat","wb"))==NULL)
    {
        puts("Error");
        exit(0);
    }
    for(x=0;x<b;x++)
    {
        fwrite(&a[x],sizeof(datos),1,NN);
    }
    fclose(NN);
}
