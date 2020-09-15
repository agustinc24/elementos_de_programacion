#include <stdio.h>
#include <stdlib.h>

int main()
{int num,N1,N2,N3,N4,r1,r2,suma,N5,N6,suma2,N7,N8,suma3;
printf("Ingrese un numero positivo de cuatro cifras:");
scanf("%d",&num);
N1=num/1000;
r1=num%1000;
N2=r1/100;
r2=r1%100;
N3=r2/10;
N4=r2%10;
suma=N1+N2+N3+N4;
if (suma<10)
    printf("\n La suma de sus digitos es=%d",suma);
    else
{
N5=suma/10;
N6=suma%10;
suma2=N5+N6;
}
if(suma>=10&&suma2<10)
printf("\n La suma de la suma de sus digitos es=%d",suma2);
        else
{
N7=suma2/10;
N8=suma2%10;
suma3=N7+N8;
}
if(suma2>=10)
printf("\n La suma de la suma de la suma de sus digitos es=%d",suma3);
    return 0;
}
