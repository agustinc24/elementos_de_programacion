#include <stdio.h>
#include <stdlib.h>

int main()
{int T1A,T1B,T1C,T2A,T2B,T2C,T3A,T3B,T3C,T4A,T4B,T4C,R,valor;
int ContM=0;
int ContP=0;
valor=3.14;
printf("\n Ingrese el primer nro de la primer terna:");
scanf("%d",&T1A);
printf("\n Ingrese el segundo nro de la primer terna:");
scanf("%d",&T1B);
printf("\n Ingrese el tercer nro de la primer terna:");
scanf("%d",&T1C);
if (T1A>valor)
    {ContM++;
    }
 if (T1B>valor)
    {ContM++;
    }
 if (T1C>valor)
    {ContM++;
    }
printf("\n Ingrese el primer nro de la segunda terna:");
scanf("%d",&T2A);
printf("\n Ingrese el segundo nro de la segunda terna:");
scanf("%d",&T2B);
printf("\n Ingrese el tercer nro de la segunda terna:");
scanf("%d",&T2C);
if (T2A>valor)
    {ContM++;
    }
    if (T2B>valor)
    {ContM++;
    }
    if (T2C>valor)
    {ContM++;
    }
printf("\n\n Ingrese el primer nro de la tercer terna:");
scanf("%d",&T3A);
printf("\n\n Ingrese el segundo nro de la tercer terna:");
scanf("%d",&T3B);
printf("\n\n Ingrese el tercer nro de la tercer terna:");
scanf("%d",&T3C);
R=T3A%2;
if (R==0)
{ContP++;
}
R=T3B%2;
if (R==0)
{ContP++;
}
R=T3C%2;
if (R==0)
{ContP++;
}
printf("\n Ingrese el primer nro de la cuarta terna:");
scanf("%d",&T4A);
printf("\n Ingrese el segundo nro de la cuarta terna:");
scanf("%d",&T4B);
printf("\n Ingrese el tercer nro de la cuarta terna:");
scanf("%d",&T4C);
R=T4A%2;
if (R==0)
{ContP++;
}
R=T4B%2;
if (R==0)
{ContP++;
}
R=T4C%2;
if (R==0)
{ContP++;
}
if  (ContM==6)
    printf("\n Todos los valores de las dos primeras ternas son mayores a 3.14");
if (ContP==0)
    printf("\n No Pares");
else
    printf("\n Si Par");
    return 0;
}

