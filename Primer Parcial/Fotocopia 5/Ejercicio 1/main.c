#include <stdio.h>
#include <stdlib.h>

int main()
{int dh,mh,ah,dn,mn,an,anios;
    do
      {printf("\n Ingrese dia hoy:");
       scanf("%d",&dh);
      }while (dh<1||dh>31);
    do
      {printf("\n Ingrese mes hoy:");
       scanf("%d",&mh);
      }while (mh<1||mh>12);
    do
      {printf("\n Ingrese anio hoy:");
       scanf("%d",&ah);
      }while (ah<2018||ah>2019);
    do
      {printf("\n Ingrese dia de nacimiento:");
       scanf("%d",&dn);
      }while (dn<0||dn>31);

    while (dn!=0)
         {do
             {printf("\n Ingrese mes de nacimiento:");
             scanf("%d",&mn);
             }while (mn<1||mn>12);
          do
             {printf("\n Ingrese anio de nacimiento:");
             scanf("%d",&an);
             }while (an<1940||an>2019);
    anios=ah-an;
    if (mn>mh) anios--;
    else {if(mn==mh&&dn>dh) anios--;}
        printf("\n Ud. tiene %d anios",anios);
        do
      {printf("\n Ingrese dia de nacimiento:");
       scanf("%d",&dn);
      }while (dn<0||dn>31);
    }
    return 0;
}
