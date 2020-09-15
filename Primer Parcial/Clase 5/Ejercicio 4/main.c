#include <stdio.h>
#include <stdlib.h>

int main()
{int np,cr,cont1,cont2,cont3,cont4,cont5,acu1,acu2,acu3,acu4,acu5;
float prom;
cont1=0;cont2=0;cont3=0;cont4=0;cont5=0;
     do{
        printf ("Ingrese numero de planta:");
        scanf("%d",&np);
       }while (np<0||np>5);

while (np!=0)
{
      do{
         printf("\n Ingrese cantidad de rollos:");
         scanf("%d",&cr);
        }while (cr<1||cr>1000);

 switch (np)
      {case 1: acu1+=cr;
               cont1++;
       case 2: acu2+=cr;
               cont2++;
       case 3: acu3+=cr;
               cont3++;
       case 4: acu4+=cr;
               cont4++;
       case 5: acu5+=cr;
               cont5++;
      }

      do{
        printf ("\n Ingrese numero de planta:");
        scanf("%d",&np);
       }while (np<0||np>5);
}
prom=acu1/cont1;
printf("\n El promedio de rollos de la planta 1 es:%f",prom);
prom=acu2/cont2;
printf("\n El promedio de rollos de la planta 2 es:%f",prom);
prom=acu3/cont3;
printf("\n El promedio de rollos de la planta 3 es:%f",prom);
prom=acu4/cont4;
printf("\n El promedio de rollos de la planta 4 es:%f",prom);
prom=acu5/cont5;
printf("\n El promedio de rollos de la planta 5 es:%f",prom);

if (acu1>acu2&&acu1>acu3&&acu1>acu4&&acu1>acu5)
    printf("\n Planta 1 tiene mayor cantidad de rollos");
if (acu2>acu1&&acu2>acu3&&acu2>acu4&&acu2>acu5)
    printf("\n Planta 2 tiene mayor cantidad de rollos");
if (acu3>acu1&&acu3>acu2&&acu3>acu4&&acu3>acu5)
    printf("\n Planta 3 tiene mayor cantidad de rollos");
if (acu4>acu1&&acu4>acu2&&acu4>acu3&&acu4>acu5)
    printf("\n Planta 4 tiene mayor cantidad de rollos");
if (acu5>acu1&&acu5>acu2&&acu5>acu3&&acu5>acu4)
    printf("\n Planta 5 tiene mayor cantidad de rollos");
    return 0;
}
