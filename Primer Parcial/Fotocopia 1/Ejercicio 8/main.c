#include <stdio.h>
#include <stdlib.h>

int main()
{float pi,desc,pf;
int cod;
printf("Ingrese el precio del producto:");
scanf("%f",&pi);
printf("\n Ingrese el codigo del producto:");
scanf("%d",&cod);
if (cod==0)
    printf("\n El precio final es:%f",pi);
else
{
desc=pi*20/100;
pf=pi-desc;
    printf("\n El precio final es=%f",pf);
    }
    return 0;
}
