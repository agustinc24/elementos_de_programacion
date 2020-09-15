#include <stdio.h>
#include <stdlib.h>

int main()
{int DNI,cod,cont1,cont2,x;
float por;
cont1=0;cont2=0;
for (x=1;x<=150;x++)
{
printf("Ingrese DNI del alumno:");
scanf("%d",&DNI);
printf("Ingrese codigo de carrera:");
scanf("%d",&cod);
if (cod==205)
 cont1++;
else
{
if (cod==606)
 cont2++;
 }
}
por=cont2*100/150;
printf("\n La cantidad de alumnos de Ingenieria Industrial es:%d",cont1);
printf("\n El porcentaje de alumnos de Ingenieria Informatica es:%f",por);
    return 0;
}
