#include <stdio.h>
#include <stdlib.h>

int main()
{int val,x,cont1,cont2,cont3;
float acum1,acum2,prom1,prom2;
cont1=0;cont2=0;cont3=0;
printf("Ingrese un valor entero:");
scanf("%d",&val);
if (val>35)
    printf("\n VALOR EXCEDIDO");
else
{
for (x=1;x=val;x++)
  {
    if (val<0)
    {cont1++;acum1+=val;}
    if (val>0)
    {cont2++;acum2+=val;}
    if (val==0)
    {cont3++;}
   }
prom2=acum2/cont2;
printf("\n El promedio de los positivos es:%f",prom2);
prom1=acum1/cont1;
printf("\n El promedio de los negativos es:%f",prom1);
printf("\n La cantidad de ceros es:%d",cont3);
}
    return 0;
}
