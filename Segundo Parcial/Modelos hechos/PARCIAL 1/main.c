#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int cod;
    char des [30];
    char sex;
    int can;
}merca;
typedef struct
{
    int zona;
    int sec;
    int casa;
    char nom [30];
    int cj;
}pedidos;

int carga_archivo (merca [],int);
int buscar(int,merca[],int);
void graba_archivo (pedidos[],int);
void impresion (pedidos[],int);

int main()
{
    int x,cant,ant,pos,codj,cjz,cjh,cjm,no,genm,genh,sen,mayor,mayorz;
    float porm,porh;
    cjz=cjh=cjm=no=genm=genh=sen=0;
    merca mer[19000];
    pedidos ped,pe_no[10000];

    cant=carga_archivo(mer,19000);
    FILE * MM;
    if((MM=fopen("PEDIDOS.dat","rb"))==NULL)
    {
        puts("\n Error");
        exit(0);
    }
    fread(&ped,sizeof(pedidos),1,MM);
while (!feof(MM))
{
        ant=ped.zona;
        cjz=cjh=cjm=0;
        while (ant==ped.zona)
        {
            cjz++;
            codj=ped.cj;
            pos=buscar(codj,mer,cant);
            if (mer[pos].sex=='M')
                cjm++;
            else
                cjh++;
           if(mer[pos].can>0)
               mer[pos].can--;
            else
            {
                pe_no[no]=ped;
                no++;
            }
        fread(&ped,sizeof(pedidos),1,MM);
        }
    printf("\n En la zona %d se hicieron %d pedidos",ant,cjz);
    porm=cjm*100/cjz;
    porh=cjh*100/cjz;
    printf("\n El porcentaje de M es:%f y el de H:%f",porm,porh);
    genm+=cjm;
    genh+=cjh;
    if(sen==0||mayor<cjz)
    {
        mayor=cjz;
        sen=1;
        mayorz=ant;
    }
}
    printf("\n La zona de mayor pedidos es la %d con %d",mayorz,mayor);
    if (no==0)
        printf("\n NO HUBO PEDIDOS");
    else
    {
       graba_archivo(pe_no,no);
       impresion(pe_no,cant);
    }
    if (genm>genh)
        printf("\n Pidieron mas juguetes las niñas");
    else
        printf("\n Pidieron mas juguetes los niños");
    return 0;
}
int carga_archivo(merca a [],int n)
{
    int x=0;
    FILE * NN;
    if((NN=fopen("ANIO2019.dat","rb"))==NULL)
    puts("\n Error");
        exit(0);
    fread(&a[x],sizeof(merca),1,NN);
    while (!feof(NN)&&x<n)
    {
        x++;
        fread(&a[x],sizeof(merca),1,NN);
    }
    fclose(NN);
    return x;
}
int buscar(int a,merca b [], int n)
{
    int p,x;
    p=-1;x=0;
    while (p==-1&&x<n)
    {
        if (a==b[x].cod)
            p=x;
        else
            x++;
    }
    return p;
}
void graba_archivo(pedidos a[], int b)
{
    int x=0;
    FILE * FF;
    if((FF=fopen("Pedi_no.DAT","wb"))==NULL)
    {
        puts("Error");
        exit(0);
    }
    for (x=0;x<b;x++)
    {
        fwrite(&a[x],sizeof(pedidos),1,FF);
    }
    fclose(FF);
}
void impresion(pedidos a [],int b)
{
    int x;
    for (x=0;x<b;x++)
    {
         printf("\n Pedidos no cumplidos:");
         printf("\n Zona:%d",a[x].zona);
         printf("\n Sector:%d",a[x].sec);
         printf("\n Numero de casa:%d",a[x].casa);
         printf("\n Nombre:%s",a[x].nom);
         printf("\n Codigo Juguete:%d",a[x].cj);
    }
}

