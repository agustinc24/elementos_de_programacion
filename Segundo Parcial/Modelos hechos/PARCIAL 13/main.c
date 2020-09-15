#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int codart;
    int nrolote;
    char desc[35];
    char cara;
    int est;
    int cant;
}arti;
typedef struct
{
    int ca;
    int nl;
    int es;
    int fe;
}produ;
typedef struct
{
    int dia;
    int est;
    int can;
}actual;
int carga_archivo(arti[],int);
int buscar(int,int,arti[],int);
void grabar_archivo(arti[],int);
void actualizacion(int[][3],int,int);
int main()
{
    int x,cant,cs,cc,cm,cr,pos,cod,lot,ma[31][3]={{0}};
    cs=cc=cm=cr=0;
    char ka;
    arti ar[6000];
    produ pr;
    cant=carga_archivo(ar,6000);
    FILE * NP;
    if((NP=fopen("produvvion.dat","rb"))==NULL);
    {
        puts("Error");
        exit(0);
    }
    fread(&pr,sizeof(produ),1,NP);
    while(!feof(NP))
    {
        cod=pr.ca;
        lot=pr.nl;
        pos=buscar(cod,lot,ar,cant);
        if(pos!=-1)
        {
            ka=ar[pos].cara;
            ar[pos].cant++;
        }
        else
        {
            cant++;
            printf("\n Ingrese descripcion del nuevo articulo nro.%d:",cant);
            fflush(stdin);
            scanf("%s",&ar[cant].desc);
            printf("\n Ingrese caracteristica del nuevo articulo nro.%d",cant);
            scanf("%c",&ar[cant].cara);
            ar[cant].codart=cod;
            ar[cant].nrolote=lot;
            ar[cant].est=pr.es;
            ka=ar[cant].cara;
            ar[cant].cant=1;
        }
        switch(ka)
        {
            case 'C':
                    cc++;
                    break;
            case 'S':
                    cs++;
                    break;
            case 'M':
                    cm++;
                    break;
            case 'r':
                    cr++;
                    break;
        }
        ma[pr.fe-1][pr.es-1]++;
        fread(&pr,sizeof(produ),1,NP);
    }
    printf("\n Cantidad de unidades producidas de la caracteristica C:%d",cc);
    printf("\n Cantidad de unidades producidas de la caracteristica S:%d",cs);
    printf("\n Cantidad de unidades producidas de la caracteristica M:%d",cm);
    printf("\n Cantidad de unidades producidas de la caracteristica R:%d",cr);
    grabar_archivo(ar,cant);
    actualizacion(ma,31,3);
    return 0;
}
int buscar(int a,int b,arti c[],int n)
{
    int x,p;
    x=0;
    p=-1;
    while(p==-1&&x<n)
    {
        if(a==c[x].codart&&b==c[x].nrolote)
            p=x;
        else
            x++;
    }
    return p;
}
int carga_archivo(arti a[],int n)
{
    int x;
    x=0;
    FILE * NN;
    if((NN=fopen("articulos.dat","rb"))==NULL)
    {
        puts("ERROR");
        exit(0);
    }
    fread(&a[x],sizeof(arti),1,NN);
    while(!feof(NN)&&x<n)
    {
        x++;
        fread(&a[x],sizeof(arti),1,NN);
    }
    fclose(NN);
    return x;
}
void grabar_archivo(arti a[],int n)
{
    int x;
    FILE * NN;
    if((NN=fopen("articulosnuevos.dat","wb"))==NULL)
    {
        puts("Error");
        exit(0);
    }
    for(x=0;x<n;x++)
    {
        fwrite(&a[x],sizeof(arti),1,NN);
    }
    fclose(NN);
}
void actualizacion(int a[][3],int f,int c)
{
    int x,y,z;
    z=0;
    actual ac[93];
    printf("\n DIA/ESTADO 1     2     3");
    for(x=0;x<f;x++)
    {
        printf("\n %d",x+1);
        for(x=0;x<c;x++)
        {
            printf("\t %d",a[x][y]);
            if(a[x][y]!=0)
            {
                ac[z].dia=x+1;
                ac[z].est=y+1;
                ac[z].can=a[x][y];
                z++;
            }
        }
    }
    FILE * NN;
    if((NN=fopen("actualizaciones.dat","wb"))==NULL)
    {
        puts("Error");
        exit(0);
    }
    for(x=0;x<z;x++)
    {
        fwrite(&ac[z],sizeof(actual),1,NN);
    }
    fclose(NN);
}
