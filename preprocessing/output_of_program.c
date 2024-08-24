#include<stdio.h>
#define PRODUCTION(x) (x*x)
#define PI 3.14
#define AREA(x,y,z) (PI*x*x+y*z)

int main(){ 
    int i=3,j,k,l;
    j=PRODUCTION(i+1);
    k=PRODUCTION(i++);
    l=PRODUCTION(++i);
    printf("first program: ");
    printf("%d %d %d %d\n",i,j,k,l);//7 7 12 49

    float a=AREA(1,5,8);
    float b=AREA(AREA(1,5,8),4,5);
    printf("Second Program: ");
    printf("a=%f b=%f\n",a,b);

    return 0;
}