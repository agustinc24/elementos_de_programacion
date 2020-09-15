#include <stdio.h>
#include <stdlib.h>
float promedio(float,int);
void mostrar(float,float);
int main()
{
    int cont1,sen;
    float acum,prom,menorp,menorl,pes,lon;
    cont1=0;
    sen=0;
    printf("\n Ingrese peso:");
    scanf("%f",&pes);
    while(pes!=-1)
    {
        printf("\n Ingrese longitud:");
        scanf("%f",&lon);
        if(lon>35.50)
        {
            cont1++;
            acum+=lon;
        }
        if(sen==0||pes<menorp)
        {
            sen=1;
            menorp=pes;
            menorl=lon;
        }
        printf("\n Ingrese peso:");
        scanf("%f",&pes);
    }
    prom=promedio(acum,cont1);
    printf("\n El promedio de los valores mayores a 35.50 es:%f",prom);
    mostrar(menorp,menorl);
    return 0;
}
float promedio(float a,int b)
{
    float p;
    p=a/b;
    return p;
}
void mostrar(float a,float b)
{
    printf("\n El menor peso es:%f",a);
    printf("\n su longitud es:%f",b);
}
