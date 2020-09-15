#include <stdio.h>
#include <stdlib.h>

int main()
{float V1,V2,V3;
printf("Ingrese primer valor real:");
scanf("%f",&V1);
printf("Ingrese segundo valor real:");
scanf("%f",&V2);
printf("Ingrese tercer valor real:");
scanf("%f",&V3);
if (V1>V3&&V2>V3)
    printf("\n MAYORES AL TERCERO");
else
    if (V1==V2&&V2==V3)
    printf("\n TRES IGUALES");
else
    if (V1<V3||V2<V3)
    printf("\n ALGUNO ES MENOR");
    return 0;
}
