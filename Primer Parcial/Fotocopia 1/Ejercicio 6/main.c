#include <stdio.h>
#include <stdlib.h>

int main()
{int num,dia,r,mes,anio,anio2,mes2,suma;
printf("Ingrese la fecha en formato DDMMAA:");
scanf("%d",&num);
dia=num/10000;
r=num%10000;
mes=r/100;
anio=r%100;
anio2=anio*10000;
mes2=mes*100;
suma=anio2+mes2+dia;
printf("\n La fecha en formato AAMMDD es=%d",suma);
    return 0;
}
