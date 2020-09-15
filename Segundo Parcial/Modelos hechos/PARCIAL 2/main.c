#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int cod;
    char des[35];
    char carac;
    int prod;
    int cants;
}merca;
typedef struct
{
    int cod;
    int cup;
    int zona;
    int dia;
}pedidos;
int buscar(int,merca [],int);
int carga_archivo (merca [], int);
void graba_archivo (merca [],int);

int main()
{
    merca mer[500];
    pedidos ped;
    int x,cant,ant,pos,codp,acuma,acumb,acumc,acumd,acume,acumf,cont,contgen,v[31]={0};
    float por;
    acuma=acumb=acumc=acumd=acume=acumf=cont=contgen=0;
    cant=carga_archivo(mer,500);
    FILE * PE;
    if((PE=fopen("pedidos.dat","rb"))==NULL)
    {
        puts("Error");
        exit(0);
    }
    fread(&ped,sizeof(pedidos),1,PE);

    while (!feof(PE))
    {
        ant=ped.cod;
        acuma=acumb=acumc=acumd=acume=acumf=cont=contgen=0;
        pos=buscar(codp,mer,cant);
        while(ant==ped.cod)
        {
            codp=ped.cod;

            if (ped.cup<=mer[pos].cants&&mer[pos].prod==3)
            {
                mer[pos].cants-=ped.cup;
                switch (mer[pos].carac)
                {
                    case 'A':acuma+=ped.cup;
                    break;
                    case 'B':acumb+=ped.cup;
                    break;
                    case 'C':acumc+=ped.cup;
                    break;
                    case 'D':acumd+=ped.cup;
                    break;
                    case 'E':acume+=ped.cup;
                    break;
                    case 'F':acumf+=ped.cup;
                    break;
                }
                contgen++;
                v[ped.dia-1]+=ped.cup;
            }
            else
                cont++;
                contgen++;
            fread(&ped,sizeof(pedidos),1,PE);
        }

        printf("\n La cantidad de unidades pedidas de A es:%d",acuma);
        printf("\n La cantidad de unidades pedidas de B es:%d",acumb);
        printf("\n La cantidad de unidades pedidas de C es:%d",acumc);
        printf("\n La cantidad de unidades pedidas de D es:%d",acumd);
        printf("\n La cantidad de unidades pedidas de E es:%d",acume);
        printf("\n La cantidad de unidades pedidas de F es:%d",acumf);
        por=cont*100/contgen;
        printf("\n El porcentaje de pedidos rechazados el del %f %",por);
    }
        fclose(PE);
        for (x=0;x<31;x++)
        {
            printf("\n Fecha:%d \t Cantidad Pedidos:%d",x+1,v[x]);
        }
        graba_archivo(mer,cant);
        return 0;
}
int carga_archivo(merca a [], int n)
{
    int x=0;
    FILE * NN;
    if((NN=fopen("comercial.dat","rb"))==NULL)
    {
        puts("Error");
        exit(0);
    }
    fread(&a[x],sizeof(merca),1,NN);
    while (!feof(NN)&&x<n)
    {
        x++;
        fread(&a[x],sizeof(merca),1,NN);
    }
    fclose(NN);
    return x;
}
int buscar (int a, merca b [], int c)
{
    int p,x;
    p=-1;x=0;
    while (p==-1&&x<c)
    {
        if (a==b[x].cod)
            p=x;
        else
            x++;
    }
    return p;
}
void graba_archivo(merca a[],int n)
{
    int x;
    FILE * MM;
    if((MM=fopen("articulosAct.dat","wb"))==NULL)
    {
        puts("Error");
        exit(0);
    }
    for(x=0;x<n;x++)
    {
        fwrite(&a[x],sizeof(merca),1,MM);
    }
    fclose(MM);
}
