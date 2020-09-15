#include <stdio.h>
#include <stdlib.h>

int main()
{
    float temp,acum,prom;
    int x,cont;
    acum=0;cont=0;
    for(x=1;x<=15;x++)
    {
        printf("\n Ingrese temperatura Nro.%d:",x);
        scanf("%f",&temp);
        if(temp>0)
        {
            cont++;
            acum+=temp;
        }
    }
   prom=acum/cont;
   printf("\n El promedio es:%f grados centigrados",prom);
    return 0;
}
