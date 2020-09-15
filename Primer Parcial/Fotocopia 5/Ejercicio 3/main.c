#include <stdio.h>
#include <stdlib.h>

int main()
{int senial,na,st,pr,maya,cont,mayna;
    cont=0;senial=0;
    do {
            printf("\n Ingrese numero de articulo:");
            scanf("%d",&na);
       }while ((na<1000||na>5000)&&na!=9999);
    while (na!=9999)
    {
            do
            {
                printf("\n Ingrese stock de articulos:");
                scanf ("%d",&st);
            }while (st<1||st>1000);
            do
            {
                printf("\n Ingrese punto de reposicion:");
                scanf ("%d",&pr);
            }while (pr<1||pr>500);

        if (st<pr) cont++;
        if (senial==0||maya<st)
        {
            senial=1;
            maya=st;
            mayna=na;
        }
        do {
            printf("\n Ingrese numero de articulo:");
            scanf("%d",&na);
       }while ((na<1000||na>5000)&&na!=9999);
    }
    printf("\n La cantidad de articulos por debajo del punto de reposicion es:%d",cont);
    printf("\n El numero de articulo que tiene mayor stock es:%d",mayna);
    return 0;
}
