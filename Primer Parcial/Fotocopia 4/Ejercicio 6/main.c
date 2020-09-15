#include <stdio.h>
#include <stdlib.h>

int main()
{int x,cont,acum,ord1,ord2;
float prom,val,min,max;
for (x=1;x<=18;x++)
{
    printf("Ingrese valor de la temperatura %d:",x);
    scanf("%f",&val);
if (x==1)
{min=1;ord1=x;max=1;ord2=x;}
if (val<0)
{cont++; acum+=val;}
if (val<min)
{min=val;ord1=x;}
if (val>max)
{max=val;ord2=x;}
}
prom=acum/cont;
printf("\n El mayor valor ingresado es:%f, y su numero de orden es:%d",max,ord2);
printf("\n El menor valor ingresado es:%f, y su numero de orden es:%d",min,ord1);
printf("\n El promedio de los valores negativos es de:%f",prom);
    return 0;
}
