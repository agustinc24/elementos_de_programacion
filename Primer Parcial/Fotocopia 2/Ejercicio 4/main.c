#include <stdio.h>
#include <stdlib.h>

int main()
{float po,pna,desa,pnb,desb,pnc,desc,pnd,desd;
printf("Ingrese el precio original del producto:");
scanf("%f",&po);
if (po<50)
{
    desa=po*0.035;
    pna=po-desa;
    printf("\n El precio original es=%f",po);
    printf("\n El descuento que se debe efectuar es de=%f",desa);
    printf("\n El precio neto es=%f",pna);
}
else
    if (po>=50&&po<=150)
{
    desb=po*0.1;
    pnb=po-desb;
    printf("\n El precio original es=%f",po);
    printf("\n El descuento que se debe efectuar es de=%f",desb);
    printf("\n El precio neto es=%f",pnb);
}
else
    if (po>=151&&po<=300)
{
    desc=po*0.2;
    pnc=po-desc;
    printf("\n El precio original es=%f",po);
    printf("\n El descuento que se debe efectuar es de=%f",desc);
    printf("\n El precio neto es=%f",pnc);
}
else
    if (po>300)
{
    desd=po*0.25;
    pnd=po-desd;
    printf("\n El precio original es=%f",po);
    printf("\n El descuento que se debe efectuar es de=%f",desd);
    printf("\n El precio neto es=%f",pnd);

}
    return 0;
}
