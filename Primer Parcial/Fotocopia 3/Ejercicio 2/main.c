#include <stdio.h>
#include <stdlib.h>

int main()
{int fn,fh,dn,dh,mn,mh,an,ah,edad;
fh=14042019;
printf("Ingrese su fecha de nacimiento en formato ddmmaaaa:");
scanf("%d",&fn);
dn=(fn/10000)/100;
mn=(fn/10000)%100;
an=fn%10000;
dh=(fh/10000)/100;
mh=(fh/10000)%100;
ah=fh%10000;
edad=ah-an;
if (mn>mh||(mn==mh&&dn>dh))
    edad--;
    printf("\n Usted tiene:%d",edad);
    return 0;
}
