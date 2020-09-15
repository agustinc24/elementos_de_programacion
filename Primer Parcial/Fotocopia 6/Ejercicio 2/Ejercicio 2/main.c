#include <stdio.h>
#include <stdlib.h>
char VALIDAR (char,char);
float PORCENTAJE (int,int);
int main()
{
    int dni,acu,cont,x;
    float al,prom,por;
    char s;
    cont=0;
    acu=0;
    for (x=1;x<=90;x++)
    {

        do
        {
            printf("\n Ingrese DNI:");
            scanf("%d",&dni);
        }while (dni<20000000||dni>35000000);
        do
        {
            printf("\n Ingrese altura:");
            scanf("%f",&al);
        }while (al<1.65||al>1.95);

        s=VALIDAR('H','M');
        if (al>1.65&&al<1.95) acu+=al;
        if (s=='M') cont++;
    }
prom=acu/x-1;
printf("\n El promedio de las alturas es:%f",prom);
por=PORCENTAJE(cont,x);
printf("\n El porcentaje de mujeres en la comision es:%f",por);
    return 0;
}
char VALIDAR (char a, char b)
{
    char z;
    do
    {
        printf("\n Ingrese el sexo:");
        fflush(stdin);
        scanf("%c",&z);
        }while (z!=a&&z!=b);
    return z;
}
float PORCENTAJE (int a, int b)
{
    float p;
    p=a*100/b-1;
    return p;
}

