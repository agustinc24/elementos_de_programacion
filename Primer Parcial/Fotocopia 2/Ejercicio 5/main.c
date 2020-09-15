#include <stdio.h>
#include <stdlib.h>

int main()
{int codigo;
printf("Ingrese el codigo del articulo:");
scanf("%d",&codigo);
switch (codigo)
{
    case 1,10,100:printf("10 pesos");
    break;
    case 2,22,222: printf("7 pesos");
    break;
    case 3,33: printf("3 pesos");
    break;
    case 4,44: printf("1 peso");
    break;
}

    return 0;
}
