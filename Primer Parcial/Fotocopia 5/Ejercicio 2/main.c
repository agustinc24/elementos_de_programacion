#include <stdio.h>
#include <stdlib.h>

int main()
{
    int mu,contp,contl,cont1;
    float p,l,acuml,prom,maxp,maxl;
    contp=0;
    contl=0;
    cont1=0;
    acuml=0;
    do
    {
        printf("\n Ingrese el numero de muestra:");
        scanf("%d",&mu);
    }while(mu<-1);
    while(mu!=-1)
    {
        printf("\n Ingrese el peso de la muestra:");
        scanf("%f",&p);
        if(p<=64.8&&p>=39.5)
            contp++;
        printf("\n Ingrese la longitud de la muestra:");
        scanf("%f",&l);
        if(l>15.30)
        {
            contl++;
            acuml+=l;
        }
        prom=acuml/contl;
        if(cont1==0||maxp<p)
        {
            cont1++;
            maxp=p;
            maxl=l;
        }
    do
    {
        printf("\n Ingrese el numero de muestra:");
        scanf("%d",&mu);
        }while(mu<-1);
    }
        printf("\n La cantidad de muestras con un peso entre 39.5 y 64.8 es:%d",contp);
        printf("\n El promedio de las longitudes mayores a 15.30 es:%f",prom);
        printf("\n La longitud y el peso de la muestra con mayor peso es:%f cm. y %f gramos",maxl,maxp);
    return 0;
}
