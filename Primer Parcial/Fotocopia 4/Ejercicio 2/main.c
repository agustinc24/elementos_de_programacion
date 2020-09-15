#include <stdio.h>
#include <stdlib.h>

int main()
{
    float val,prom,sum,acum,x;
    int cont,z;
    x=3.14;
    cont=0;
    acum=0;
    for(z=1;z<=20;z++)
    {
        printf("\n Ingrese el valor Nro.%d:",z);
        scanf("%f",&val);
        sum+=val;
        if(val>x)
            {
            cont++;
            acum+=val;
            }
    }
    prom=acum/cont;
    printf("\n El promedio es de:%f y la suma es:%f",prom,sum);
    return 0;
}
