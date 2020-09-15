#include <stdio.h>
#include <stdlib.h>

int main()
{int N1,N2,N3,sum,R,P,PP;
printf("Ingrese primer numero entero:");
scanf("%d",&N1);
printf("Ingrese segundo numero entero:");
scanf("%d",&N2);
printf("Ingrese tercer numero entero:");
scanf("%d",&N3);
sum=N1+N2+N3;
R=sum%2;
if (sum>100&&R==0)
    {
    P=N1*N2*N3;
    printf("\n El producto es:%d, La suma es:%d",P,sum);
    }
else
    {if (sum>100)
    {PP=(N1*N3)+N2;
    printf("\n El producto del primero y el tercero mas el segundo es:%d",PP);
    }
else
    printf("\n La suma es:%d",sum);
    }
    return 0;
}
