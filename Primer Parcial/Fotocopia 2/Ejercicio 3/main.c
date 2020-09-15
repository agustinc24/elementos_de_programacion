#include <stdio.h>
#include <stdlib.h>

int main()
{int legajo,pp,sp;
printf("Ingrese numero de legajo del alumno:");
scanf("%d",&legajo);
printf("\n Ingrese nota del primer parcial:");
scanf("%d",&pp);
printf("\n Ingrese nota del segundo parcial:");
scanf("%d",&sp);
if (pp>=7&&sp>=7)
    {
    printf("\n El numero de legajo es:%d",legajo);
    printf("\n La nota del primer parcial es:%d",pp);
    printf("\n La nota del segundo parcial es:%d",sp);
    printf("\n Condicion final: PROMOCIONA");
    }
else
    if (pp>=4&&sp>=4&&pp<7&&sp<7)
    {
    printf("\n El numero de legajo es:%d",legajo);
    printf("\n La nota del primer parcial es:%d",pp);
    printf("\n La nota del segundo parcial es:%d",sp);
    printf("\n Condicion final: RINDE EXAMEN FINAL");
    }
    else
    {
    printf("\n El numero de legajo es:%d",legajo);
    printf("\n La nota del primer parcial es:%d",pp);
    printf("\n La nota del segundo parcial es:%d",sp);
    printf("\n Condicion final: REPROBO LA MATERIA");
    }
return 0;
}
