#include <stdio.h>
#include <stdlib.h>

int main()
{int N1,N2,N3,N4,N5,num,R,R2,R3;
printf("Ingrese un numero de cinco cifras:");
scanf("%d",&num);
N1=num/10000;
R=num%10000;
N2=R/1000;
R2=R%1000;
N3=R2/100;
R3=R2%100;
N4=R3/10;
N5=R3%10;
if (N1==N5&&N2==N4)
    printf("\n Es capicua");
else
    printf("\n No es capicua");
    return 0;
}
