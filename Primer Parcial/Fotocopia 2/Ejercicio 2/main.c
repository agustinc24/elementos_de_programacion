#include <stdio.h>
#include <stdlib.h>

int main()
{int num;
printf("Ingrese el numero del articulo:");
scanf("%d",&num);
if ((num>=12121&&num<=18081)||(num>=30012&&num<=45565)||(num>=67000&&num<=68000))
        printf("\n El articulo es defectuoso");
else
    printf("\n El articulo no es defectuoso");
    return 0;
}
