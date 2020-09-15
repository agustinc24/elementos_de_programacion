#include <stdio.h>
#include <stdlib.h>
int VALIDAR (int,int,char[10]);
typedef struct
{
    char ape[15];
    char nom[15];
}nomyape;
typedef struct
{
    int dn;
    int mn;
    int an;
}nacimiento;
typedef struct
{
    int leg;
    nomyape nya;
    float alt;
    char sex;
    nacimiento na;
}persona;
int main()
{
    int x;
    persona per[10];
    for(x=0;x<2;x++)
    {
        per[x].leg=VALIDAR(1,10000,"legajo");
        printf("\n Ingrese apellido:");
        fflush(stdin);
        gets(per[x].nya.ape);
        printf("\n Ingrese nombre:");
        fflush(stdin);
        gets(per[x].nya.nom);
        do
        {
            printf("\n Ingrese altura:");
            scanf("%f",&per[x].alt);
        }while (per[x].alt<0);
        do
        {
            printf("\n Ingrese sexo:");
            fflush(stdin);
            scanf("%c",&per[x].sex);
        }while (per[x].sex!='F'&&per[x].sex!='M');
        per[x].na.dn=VALIDAR(1,31,"Dia.nac");
        per[x].na.mn=VALIDAR (1,12,"Mes.nac");
        per[x].na.an=VALIDAR (1950,2010,"Anio.nac");
        printf("\n legajo:%d",per[x].leg);
        printf("\n Apellido:"); puts(per[x].nya.ape);
        printf("\n Nombre:"); puts(per[x].nya.nom);
        printf("\n altura:%4.2f",per[x].alt);
        printf("\n sexo:%c",per[x].sex);
        printf("\n dia nacimiento:%d",per[x].na.dn);
        printf("\n mes nacimiento:%d",per[x].na.mn);
        printf("\n anio nacimiento:%d",per[x].na.an);
    }
        return 0;
}
int VALIDAR(int a, int b,char c [10])
{
    int x;
    do
    {
        printf("\n Ingrese %s:",c);
        scanf("%d",&x);
    }while (x<a||x>b);
}
