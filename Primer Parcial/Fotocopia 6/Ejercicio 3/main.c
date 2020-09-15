#include <stdio.h>
#include <stdlib.h>
int VALIDAR (int,int);
float PORCENTAJE (int,int);
int main()
{
    int med,cont,contp,sen,mayv,mayo;
    float por;
    cont=0;contp=0;sen=0;
    med=VALIDAR (15,45);
    while (med!=-1)
    {

        if (med>=15&&med<=45) cont++;
        if (med>30) contp++;
        if (sen==0||mayv<med) {sen=1;mayv=med;mayo=cont;}
    med=VALIDAR (15,45);
    }

    por=PORCENTAJE(contp,cont);
    printf("\n El porcentaje de muestra que supera el valor 30 es:%f",por);
    printf("\n El mayor valor de la madera es:%d y su posicion es:%d",mayv,mayo);
    return 0;
}
int VALIDAR (int a,int b)
{
    int m;
    do
    {
        printf("\n Ingrese la medida de la madera:");
        scanf("%d",&m);
    }while ((m>b||m<a)&&m!=-1);
    return m;
}
float PORCENTAJE (int a, int b)
{
    int p;
    p=a*100/b;
    return p;
}
