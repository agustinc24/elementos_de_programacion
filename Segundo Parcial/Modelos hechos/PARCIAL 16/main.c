#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int cod;
    int gal;
    int bar;
    int anio;
    float cant;
}produ;
typedef struct
{
    int nped;
    int cod;
    float cant;
    int des;
}pedido;
int buscar (int,produ [],int);
int carga_archivo (produ[],int);
void graba_archivo(produ [],int);
void imprime_a(float,int);

int main()
{
    produ prod[1650];
    pedido ped;
    int x,pos,cant,ant,sen;
    float acum1,acum2,acum;
    acum1=acum2=acum=x=0;
    cant=carga_archivo(prod,1650);
    FILE * PE;
    if((PE=fopen("PEDIDOS.dat","rb"))==NULL)
    {
        puts("Error");
        exit(0);
    }
    fread(&ped,sizeof(pedido),1,PE);
    while(!feof(PE))
    {
        ant=ped.cod;
        pos=buscar(ant,prod,cant);
        acum=0;
        while(ant==ped.cod)
        {
            if(ped.cant<=prod[pos].cant)
            {
                prod[pos].cant-=ped.cant;
                acum+=ped.cant;
                if (ped.des==1)
                    acum1+=ped.cant;
                else
                    acum2+=ped.cant;
            }
            else
            {
                printf("\n No hay stock de los siguientes vinos:");
                printf("\n Nro.pedido: %d /t Código vino: %d /t Nro.barril: %d \t Cantidad: %f",ped.nped,ant,prod[pos].bar,ped.cant);
            }
        fread(&ped,sizeof(pedido),1,PE);
        }
        imprime_a(acum,ant);
    }
    fclose(PE);
    graba_archivo(prod,cant);
    printf("\n La cantidad de litros pedidos para el interior es %f y para el exterior %f",acum1,acum2);
    for(x=0;x<cant;x++)
    {
        if (prod[x].cant<100&&sen==0)
        {
            sen=1;
            printf("\n Galpon: \t Nro.barril: \t Codigo vino: \t Anio: \t Cantidad:");
        }

    }
    for(x=0;x<cant;x++)
    {
        if(prod[x].cant<100)
        {
            printf("%d \t %d \t %d \t %d \t %f",prod[x].gal,prod[x].bar,prod[x].cod,prod[x].anio,prod[x].cant);
        }
    }
    return 0;
}
int carga_archivo(produ a [],int b)
{
    int x=0;
    FILE * PR;
    if((PR=fopen("PRODUCTO.dat","rb"))==NULL)
    {
        puts("Error");
        exit(0);
    }
    fread(&a[x],sizeof(produ),1,PR);
    while(!feof(PR)&&x<b)
    {
        x++;
        fread(&a[x],sizeof(produ),1,PR);
    }
    fclose(PR);
    return x;
}
int buscar(int a,produ b[],int c)
{
    int x,p;
    x=0;p=-1;
    while(p==-1&&x<c)
    {
        if(a==b[x].cod)
          p=x;
        else
            x++;
    }
    return p;
}
void imprime_a(float a,int b)
{
    printf("\n La cantidad de litros pedidos del vino %d es de %f",b,a);
}
void graba_archivo(produ a [],int b)
{
    int x=0;
    FILE * PP;
    if((PP=fopen("PROCUACT.dat","wb"))==NULL)
    {
        puts("Error");
        exit(0);
    }
    for (x=0;x<b;x++)
    {
        fwrite(&a[x],sizeof(produ),1,PP);
    }
    fclose(PP);
}
