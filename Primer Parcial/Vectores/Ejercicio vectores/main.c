#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x;
    float vec[10]={0,0,0,0,0,0,0,0,0,0};
    for(x=0;x<10;x++)
    {
        printf("\n Ingrese %d:",x+1);
        scanf("%f",&vec[x]);
    }
    for(x=0;x<10;x++)
    {
        printf("\t %6.2f",vec[x]);
    }
    return 0;
}
