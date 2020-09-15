#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int cprod;
    char des [30];
    int ru;
    float pre;
    int pp;
    int sto;
}merca;
typedef struct
{
    int cprod;
    int cantu;
    int ncli;
    int nped;
    int dia;
}pedi;
int buscar(int,merca [],int);
int carga_archivo(merca[],int);
void ordenar (float [],int [],int);
void graba_archivo (merca [],int);
int main()
{
    merca mer[4000];
    pedi ped;
    int cant,v[31]={0},
    float ve[31]={0};
    cant=carga_archivo(mer,4000);
    FILE * PE;
    if((PE=fopen("STOCK.DAT","rb"))==NULL)
    {
        puts("Error");
        exit(0);
    }
    fread (&ped,sizeof(pedi),1,PE);
    while(!feof(PE))
    {
        cod=ped.cprod;
        ant=cod;
        pos=buscar(cod,mer,cant)

        while(ant==cod)
        {
            if(ped.cantu<=mer[pos])
            {
                mer[pos].sto-=ped.cantu;
                acumgen+=ped.cantu;
                v[dia-1]=ped.dia;
                ve[pos]+=ped.cantu*mer[pos].pre;
                if(mer[pos].ru<21)
                {
                    acumc+=ped.cantu;
                    monto=ped.cantu*mer[pos].pre;
                    acumm+=monto;
                }
            }
            else
                printf("\n No hay stock");
        }
        if (acumm!=0&&acumc!=0)
        {
            printf("\n Producto:%d \t Cantidad Pedida:%d \t Monto:%f",ant,acumc,acumm);
        }
        if(sen==0||max<acumgen)
        {
            max=acumgen;
            maxp=ant;
        }
    }
    ordenar(ve,v,31);
    printf("\n El producto %d fue el mas solicitado",maxp);
    graba_archivo(mer,cant);
    return 0;
}
graba_archivo(merca a [],int b)
{
    int x;
    FILE * NN;
    if((NN=fopen("stock_act","wb"))==NULL)
    {
        puts("Error");
        exit(0);
    }
    for(x=0;x<)
}
