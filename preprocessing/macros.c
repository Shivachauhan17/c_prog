#include<stdio.h>
#define ISLOWER(x) (x>='a' && x<='z')
#define ISUPPER(x) (x>='A' && x<='Z')
#define ISALPHA(x) (ISLOWER(x) || ISUPPER(x))
#define BIGGER(a,b) (a>b?a:b)

int main(){
    int result=ISLOWER('b');
    printf("%d\n",result);
    result=ISUPPER('a');
    printf("%d\n",result);
    result=ISALPHA(1);
    printf("%d\n",result);
    result=BIGGER(4,5);
    printf("%d\n",result);


    return 0;
}