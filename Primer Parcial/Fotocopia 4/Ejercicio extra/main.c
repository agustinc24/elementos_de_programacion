#include <stdio.h>
#include <stdlib.h>

int main()
{int num,x,R,cont=0;
printf("Ingrese un numero entero:");
scanf("%d",&num);
for(x=1;x<=num;x++)
    {
        R=num%x;
        if(R==0)
            cont++;
    }
if (cont>2)
    printf("\n No es primo");
else
    printf("\n Es primo");
    return 0;
}
