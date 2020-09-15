#include <stdio.h>
#include <stdlib.h>

int main()
{int x,ord1,ord2;
float min,max,val;
for(x=1;x<=10;x++)
{
    printf("Ingrese el valor entero Nro.%d:",x);
    scanf("%f",&val);
    if(x==1)
    {
        min=val;ord1=x;max=val;ord2=x;
    }
    if(val>max)
    {
        max=val;
        ord2=x;
    }
    if(val<min)
    {
        min=val;
        ord1=x;
    }
}
printf("\n El minimo es:%f, El orden del minimo es:%d, El maximo es:%f, El orden del maximo es:%d",min,ord1,max,ord2);
    return 0;
}
