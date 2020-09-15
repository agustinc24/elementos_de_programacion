#include <stdio.h>
#include <stdlib.h>

int main()
{int num,cont1,cont2,min,minpos;
cont1=0;cont2=1;
printf("Ingrese un numero entero:");
scanf("%d",&num);
while (num!=0)
    {
        if (num>=105&&num<=310)
        cont1++;
        if (cont2==1||num<min)
        {min=num;minpos=cont2;}
        printf("Ingrese un numero entero:");
        scanf("%d",&num);
        cont2++;
    }
printf("\n La cantidad de valores ingresados entre 105 y 310 es:%d",cont1);
printf("\n El menor valor ingresado es:%d",min);
printf("\n Su numero de orden de ingreso es:%d",minpos);
    return 0;
}
