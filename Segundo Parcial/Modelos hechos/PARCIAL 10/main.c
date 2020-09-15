#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int cod;
    char des [35];
    char cara;
    int est;
    int cant;
}merca;
typedef struct
{
    int cod;
    int cant;
    int zona;
    int dia;
}pedi;

int buscar(int,merca[],int);
int carga_archivo(merca[],int);
void graba_archivo(pedi[],int);

int main()
{
    int cant,pos,x,ant,acum,acuma,acumb,acumc,acumd,acume,acumf,v1[10]={0},v2[10]={0},no;
    acum=acuma=acumb=acumc=acumd=acume=acumf=no=x=0;
    merca mer[500];
    pedi ped, ped_no[10000];
    cant=carga_archivo(mer,500);

    FILE * PE;
    if((PE=fopen("pedidos.dat","rb"))==NULL)
    {
        puts("Error");
        exit(0);
    }
    fread(&ped,sizeof(pedi),1,PE);
    while (!feof(PE))
    {
        ant=ped.cod;
        pos=buscar(ant,mer,cant);
        acum=0;
        while(ant==ped.cod)
        {
            if(mer[pos].cant>=ped.cant&&mer[pos].est==3)
            {
                mer[pos].cant-=ped.cant;
                acum+=ped.cant;
                switch(mer[pos].cara)
                {
                    case 'A':acuma+=ped.cant;
                    break;
                    case 'B':acumb+=ped.cant;
                    break;
                    case 'C':acumc+=ped.cant;
                    break;
                    case 'D':acumd+=ped.cant;
                    break;
                    case 'E':acume+=ped.cant;
                    break;
                    case 'F':acumf+=ped.cant;
                    break;
                }
                v1[ped.zona-1]++;
            }
            else
            {
                printf("\n No hay stock o articulo no terminado");
                ped_no[no]=ped;
                v2[ped.zona-1]++;
                no++;
            }
        fread(&ped,sizeof(pedi),1,PE);
        }
        printf("\n El codigo %d tiene una cantidad pedida que se cumplio de %d",ant,acum);
    }
    fclose(PE);
    printf("\n La caracteristica 'A' tiene %d pedidos",acuma);
    printf("\n La caracteristica 'B' tiene %d pedidos",acumb);
    printf("\n La caracteristica 'C' tiene %d pedidos",acumc);
    printf("\n La caracteristica 'D' tiene %d pedidos",acumd);
    printf("\n La caracteristica 'E' tiene %d pedidos",acume);
    printf("\n La caracteristica 'F' tiene %d pedidos",acumf);
    graba_archivo(ped_no,no);
    printf("\n ZONA / Cantidad Pedidos Cumplidos / Cantidad No Cumplidos");
    for(x=0;x<10;x++)
    {
        printf("\n %d \t %d \t %d",x+1,v1[x],v2[x]);
    }
    return 0;
}
int carga_archivo(merca a[],int b)
{
    int x; x=0;
    FILE *ME;
    if((ME=fopen("comercial.dat","rb"))==NULL)
    {
        puts("Error");
        exit(0);
    }
    fread(&a[x],sizeof(merca),1,ME);
    while(!feof(ME)&&x<b)
    {
        x++;
        fread(&a[x],sizeof(merca),1,ME);
    }
    fclose(ME);
    return x;
}
int buscar(int a,merca b[],int c)
{
    int p,x;
    p=-1;x=0;
    while(p==-1&&x<c)
    {
        if(a==b[x].cod)
            p=x;
        else
            x++;
    }
    return p;
}
graba_archivo(pedi a[],int b)
{
    int x=0;
    FILE * PP;
    if((PP=fopen("Pedidos_no.dat","wb"))==NULL)
    {
        puts("Error");
        exit(0);
    }
    for(x=0;x<b;x++)
    {
        fwrite(&a[x],sizeof(pedi),1,PP);
    }
    fclose(PP);
}
