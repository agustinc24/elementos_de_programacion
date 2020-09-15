#include <stdio.h>
#include <stdlib.h>

int main()
{char letra;
int cont1, cont2,x;
float por;
cont1=0;cont2=0;
for (x=1;x<=5;x++)
{
     printf("\n Ingrese caracter nro.%d:",x);
     fflush(stdin);
     scanf("%c",&letra);
switch (letra)
 {
 case 'a':cont1++;

 case 'A':cont1++;

 case 'e':cont1++;

 case 'E':cont1++;

 case 'i':cont1++;

 case 'I':cont1++;

 case 'o':cont1++;

 case 'O':cont1++;

 case 'u':cont1++;

 case 'U':cont1++;
break;
 case 'C':cont2++;
  break;
 case 'B':cont2++;
  break;
 case 'D':cont2++;
  break;
 case 'G':cont2++;
 }
}
por=cont1/5*100;
printf("\n El porcentaje de vocales es:%f, La cantidad de letras C,B,D,G es:%d",por,cont2);
    return 0;
}
