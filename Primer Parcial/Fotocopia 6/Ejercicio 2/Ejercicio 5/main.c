#include <stdio.h>
#include <stdlib.h>
int validar(int,int,char[20]);
float promedio(int,int);
int main()
{
    int np,tr,acum1,acum2,acum3,acum4,acum5,cont3,cont5,menp,menr;
    float prom1,prom2;
    acum1=0;
    acum2=0;
    acum3=0;
    acum4=0;
    acum5=0;
    cont3=0;
    cont5=0;
    np=validar(0,5,"numero de planta:");
    while(np!=0)
    {
        tr=validar(1,1000,"cantidad de rollos:");
        if(np==3)
        {
            cont3++;
            acum3+=tr;
        }
        if(np==5)
        {
            cont5++;
            acum5+=tr;
        }
        if(np==1)
            acum1+=tr;
        if(np==2)
            acum2+=tr;
        if(np==4)
            acum4+=tr;
        np=validar(0,5,"numero de planta:");
    }
    prom1=promedio(acum3,cont3);
    prom2=promedio(acum5,cont5);
    printf("\n El promedio de la planta 3 es:%f",prom1);
    printf("\n El promedio de la planta 5 es:%f",prom2);
    menr=acum1;
    menp=1;
    if(acum2<menr)
    {
        menr=acum2;
        menp=2;
    }
    if(acum3<menr)
    {
        menr=acum3;
        menp=3;
    }
    if(acum4<menr)
    {
        menr=acum4;
        menp=4;
    }
    if(acum5<menr)
    {
        menr=acum5;
        menp=5;
    }
    printf("\n La planta con menor cantidad de rollos es: %d , con una cantidad de rollos de: %d",menp,menr);
    return 0;
}
int validar(int a,int b,char c[20])
{
    int v;
    do
    {
        printf("\n Ingrese %s",c);
        scanf("%d",&v);
        }while(v<a||v>b);
    return v;
}
float promedio(int a,int b)
{
    float p;
    p=a/b;
    return p;
}
