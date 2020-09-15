#include <stdio.h>
#include <stdlib.h>

int main()
{int num,x,i,acpr,may,ord,r,contmul;
  for (x=1;x=10;x++)
  {contmul=0;
      for (i=1;i=3;i++)
      {
          printf("\n Ingrese el %d valor de la %d terna",i,x);
          scanf("%d",&num);
          if (i==1)
          {acpr+=num;may=num;ord=i;}
          if (may<num)
          {may=num;ord=i;}
          r=num%7;
          if(r==0) contmul++;
      }

}
    return 0;
}
