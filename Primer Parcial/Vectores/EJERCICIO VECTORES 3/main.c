#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x,acu,vec[100]={0};
    float prom;
    x=0;
    acu=0;
    printf("\n Ingrese edad del alumno:");
    scanf("%d",&vec[x]);
    while(vec[x]!=0&&x<100)
    {
        acu+=vec[x];
        x++;
        printf("\n Ingrese edad del alumno:");
        scanf("%d",&vec[x]);
    }
    prom=acu/x;
    printf("\n El promedio de edad de los %d alumnos es:%f",x,prom);
    return 0;
}
