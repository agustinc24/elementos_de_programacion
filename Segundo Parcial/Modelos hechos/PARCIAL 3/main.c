#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int codp;
    char des[30];
    int rub;
    float prec;
    int pp;
    int sto;
}merca;
typedef struct
{
    int codp;
    int cant;
    int cli;
    int ped;
    int dia;
}pedidos;
int buscar (int, merca [], int);
int carga_archivo (merca [],int);
void imprimir (int [],int);

int main()
{
    merca mer[6000];
    pedidos ped;
    int cant,ant,pos,codp,acum,cont,v[31]={0},sen;
    float monto;
    acum=cont=monto=0;
    cant=carga_archivo(mer,6000);
    FILE * PE;
    if ((PE=fopen("pedidos.dat","rb"))==NULL)
    {
        puts("Error");
        exit(0);
    }
    fread(&ped,sizeof(pedidos),1,PE);
    while (!feof(PE))
    {
        ant=ped.codp;
        acum=monto=sen=cont=0;
        pos=buscar(codp,mer,cant);

        while (ant==ped.codp)
        {
            codp=ped.codp;

            if(ped.cant<=mer[pos].sto)
            {
                mer[pos].sto-=ped.cant;
                acum+=ped.cant;
                monto+=ped.cant*mer[pos].prec;

                if((mer[pos].sto<=mer[pos].pp)&&sen==0)
                {
                    printf("\n Hay que reponer el producto numero %d",ant);
                    cont++;
                    sen=1;
                }
            }
            else
                printf("\n No hay stock bestiaaa");
            fread(&ped,sizeof(pedidos),1,PE);
        }
        v[ped.dia-1]+=mer[pos].sto;
        printf("\n La cantidad pedida del producto %d es:%d y su monto: %f",ant,acum,monto);
    }
        fclose(PE);
        printf("\n Se deben reponer %d productos",cont);
        imprimir(v,31);
    return 0;
}
int carga_archivo(merca a [], int n)
{
    int x=0;
    FILE * MM;
    if((MM=fopen("stock.dat","rb"))==NULL)
    {
        puts("Error");
        exit(0);
    }
    fread(&a[x],sizeof(merca),1,MM);
    while (!feof(MM)&&x<n)
    {
        x++;
        fread(&a[x],sizeof(merca),1,MM);
    }
    fclose(MM);
    return x;
}
int buscar(int a,merca b [], int c)
{
    int p,x;
    p=-1;x=0;
    while (p==-1&&x<c)
    {
        if (a==b[x].codp)
            p=x;
        else
            x++;
    }
    return p;
}
void imprimir(int a [],int n)
{
    int x;
    for (x=0;x<n;x++)
    {
        printf ("\n Fecha:%d \t Cantidad Productos:%d",x+1,a[x]);
    }
}

