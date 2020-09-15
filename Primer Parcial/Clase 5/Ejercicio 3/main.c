#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n1,n2,n3,n4,n5,sum,cont1,cont2;
    cont1=0;
    cont2=0;
    do{
      printf ("Ingrese valor 1:");
      scanf("%d",&n1);
      }while (n1<0||n1>9);
    do{
      printf ("Ingrese valor 2:");
      scanf("%d",&n2);
      }while (n2<0||n2>9);
    do{
      printf ("Ingrese valor 3:");
      scanf("%d",&n3);
     }while (n3<0||n3>9);
    do{
      printf ("Ingrese valor 4:");
      scanf("%d",&n4);
      }while (n4<0||n4>9);
    do{
       printf ("Ingrese valor 5:");
       scanf("%d",&n5);
      }while (n5<0||n5>9);
    sum=n1+n2+n3+n4+n5;

    while(sum!=0)
        {if(n1==n2&&n2==n3&&n3==n4&&n4==n5) cont1++;
        else
            if(n1==n5&&n2==n4) cont2++;
        do{
            printf ("Ingrese valor 1:");
            scanf("%d",&n1);
        }while (n1<0||n1>9);
     do{
      printf ("Ingrese valor 2:");
      scanf("%d",&n2);
    } while (n2<0||n2>9);
     do{
    printf ("Ingrese valor 3:");
    scanf("%d",&n3);
    } while (n3<0||n3>9);
     do{
    printf ("Ingrese valor 4:");
    scanf("%d",&n4);
    } while (n4<0||n4>9);
     do{
    printf ("Ingrese valor 5:");
    scanf("%d",&n5);
    } while (n5<0||n5>9);
    }
    printf("\n La cantidad de quintetos capicua triple es de:%d",cont1);
    printf("\n La cantidad de quintetos capicua quintuple es de:%d",cont2);
    return 0;
}
