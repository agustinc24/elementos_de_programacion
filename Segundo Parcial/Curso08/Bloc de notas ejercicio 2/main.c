#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int leg;
    char edad;
    char loc;
    int cod;
}universidad;

int validar (int, int, char[10]);
char validar2 (char,char,char[10]);
void guardar_archivo (universidad [],int);


int main()
{
    int x,cant; x=0;
    universidad uni [10000];
    uni[x].leg=validar(10000,99000,"legajo");

    while (uni[x].leg!=10000)
    {
        uni[x].edad=validar2('A','M',"edad");
        uni[x].loc=validar2('C','P',"localidad");
        uni[x].cod=validar(101,350,"codigo");
        x++;
        uni[x].leg=validar(10000,99000,"legajo");
    }
    guardar_archivo(uni,1000);

    return 0;
}
int validar (int a, int b, char c [10])
{
    int x;
    do
    {
        printf ("Ingrese %s:",c);
        scanf ("%d",&x);
    }while (x<a||x>b);
    return x;
}
char validar2 (char a, char b, char c [10])
{
    char x;
    do
    {
        printf ("Ingrese %s:",c);
        scanf ("%c",&x);
    }while (x!=a&&x!=b);
    return x;
}
void guardar_archivo(universidad a[1000],int n)
{
    int x=0;
     FILE * NN;
     if((NN=fopen("C:\\Progra\\TANDIL.dat","wb"))==NULL)
    {
        puts ("Error");
        exit(0);
    }
    for (x=0;x<n;x++)
    {
        fwrite(&a[x],sizeof(universidad),1,NN);
    }
    fclose(NN);
}
