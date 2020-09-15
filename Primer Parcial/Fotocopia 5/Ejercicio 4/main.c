#include <stdio.h>
#include <stdlib.h>

int main()
{
 int nl,ai,cont1,cont2,senial,mayl,mayai;
 char s,mays;
 float por;
 cont1=0;cont2=0;senial=0;
    do {
            printf("Ingrese sexo del alumno:");
            fflush(stdin);
            scanf("%c",&s);
       }while (s!='M'&&s!='H'&&s!='F');

    while (s!='F')
    {
        do {
            printf("\n Ingrese numero de legajo del alumno:");
            scanf("%d",&nl);
           }while (nl>15000||nl<5000);
        do {
            printf("\n Ingrese anio de ingreso del alumno:");
            scanf("%d",&ai);
           }while (ai>2013||ai<1990);
    if (nl>5000&&nl<15000) cont1++;
    if (ai==2010&&s=='H') cont2++;
    if (senial==0||mayl<nl)
    {
        senial=1;mayl=nl;mays=s;mayai=ai;
    }
         do {
            printf("Ingrese sexo del alumno:");
            fflush(stdin);
            scanf("%c",&s);
       }while (s!='M'&&s!='H'&&s!='F');
    }
por=cont2*100/cont1;
printf("\n El porcentaje de los alumnos que ingresaron en 2010 y son hombres es:%f",por);
printf("\n El numero de legajo mas alto es:%d El sexo es:%c Su anio de ingreso es:%d",mayl,mays,mayai);
    return 0;
}
