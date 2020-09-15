#include <stdio.h>
#include <stdlib.h>
char CLASEVINO (char, char, char);
float PROMEDIO (int,int);
int main()
{
    int x,ce,mce,mcl,contc,acuc;
    float promc;
    char cv,mcv;
    acuc=0;
    contc=0;
        for (x=1;x<=200;x++)
        {
            cv=CLASEVINO ('A','B','C');
            printf("\n Ingrese cantidad de embases de esa clase de vino:");
            scanf("%d",&ce);
            if (cv=='C')
            {
                acuc+=ce;
                contc++;
            }
            if (mce<ce)
            {
                mce=ce;
                mcl=x;
                mcv=cv;
            }
        }
        promc=PROMEDIO (acuc,contc);
        printf("\n El promedio de la clase de vino C es:%f",promc);
        printf("\n El lote con la mayor cantidad de embases es:%d, con una cantidad de embases de:%d, y su clase de vino:%c",mcl,mce,mcv);
    return 0;
}
    char CLASEVINO (char a, char b, char c)
    {
        char v;
        do
        {
            printf("\n Ingrese la clase de vino:");
            fflush (stdin);
            scanf ("%c",&v);
        }while (v!='A'&&v!='B'&&v!='C');
        return v;
    }
    float PROMEDIO (int a,int b)
    {
        float p;
        p=a/b;
        return p;
    }
