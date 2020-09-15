#include <stdio.h>
#include <stdlib.h>

int main()
{float pi,pf,des;
char cod, os [12];
printf("Ingrese codigo:");
fflush(stdin);
scanf("%c",&cod);
printf("\n Ingrese monto total:");
scanf("%f",pi);
switch (cod)
{
    case 'B':des=0.70;
    strcpy(os,"Bancarios");
    break;
    case 'M':des=0.65;
    strcpy(os,"Municipales");
    break;
    case 'P':des=0.50;
    strcpy(os,"PAMI");
    break;
    case 'C':des=0.55;
    strcpy(os,"Camioneros");
    break;
    case 'V':des=0.75;
    strcpy(os,"UTA");
    break;
    case 'R':des=0.90;
    strcpy(os,"Resto");
}
pf=pi*des;
printf("\n Monto total:%f",pi);
printf("\n El descuento es:%f",des);
printf("\n Monto final:%f",pf);
printf("\n Obra social:%s",os);
    return 0;
}
