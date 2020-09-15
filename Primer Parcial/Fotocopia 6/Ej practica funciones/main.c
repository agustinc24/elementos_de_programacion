#include <stdio.h>
#include <stdlib.h>
float PROMEDIO (float,float,float);
int main()
{
    float N1,N2,N3,PROM;
    int x;
        for (x=1;x<=4;x++)
        {
            printf("\n Ingrese valor 1:");
            scanf("%f",&N1);
            printf("\n Ingrese valor 2:");
            scanf("%f",&N2);
            printf("\n Ingrese valor 3:");
            scanf("%f",&N3);
            PROM=PROMEDIO(N1,N2,N3);
            printf("\n PROMEDIO %f de %d",PROM,x);
        }
    return 0;
}
float PROMEDIO (float a,float b,float c)
{
    float P;
    P=(a+b+c)/3;
    return P;
}
