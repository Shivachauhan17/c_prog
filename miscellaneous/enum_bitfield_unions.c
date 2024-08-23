#include <stdio.h>
#include<stdarg.h>
/*defining macros for bit fields value*/
#define MALE 0;
#define FEMALE 1;
#define SINGLE 0;
#define MARRIED 1;
#define DIVORCED 2;
#define WIDOWED 3;
/*enum*/
enum mar_status {
    single='S', 
    married='M', 
    divorced='D', 
    widowed='W'
};
/*function for pointer to functions*/
void display();

void display(){
    printf("display anythong dummy\n");
}

/*functioin returning pointer*/
int *func();
int *func(){
    static int i=20;
    return (&i);
}

/*function with variable parameter*/
int findMax(int,...);
int find_max(int tot_num,...){
    int max,count,num;
    va_list ptr;
    va_start(ptr,tot_num);
    max=va_arg(ptr,int);

    for(count=1;count<tot_num;count++){
        num=va_arg(ptr,int);
        if(num>max)
            max=num;
    }
    va_end(ptr);
    return max;
}
 
int main() {
    enum mar_status person1, person2;

    person1 = married;
    person2 = divorced;

    printf("person 1 has value %c\n", person1);
    printf("person 2 has value %c\n", person2);

    /*typecasting*/
    float a,b;
    int x=6,y=4;
    a=x/y;
    printf("value of a=%f\n",a);//integer then convereted to float 
    b=(float)x/y;
    printf("value of b=%0.1f\n\n",b);//result directly being stored as integer not being converted to integer

    /*Bit Field*/
    struct employee{
        unsigned gender:1; 
        unsigned mar_stat:2;
    };

    struct employee e;
    e.gender=MALE;
    e.mar_stat=SINGLE;

    printf("gender value is %d\n",e.gender);
    printf("merriege stat value is %d\n",e.mar_stat);

    /*pointer to functions */
    void (*ptr)();
    ptr=display;
    (*ptr)();

    /*function returning pointer*/
    int *p;
    p=func();
    printf("this the value returned by the function %d\n\n",*p);

    /*function with variable parameter*/
    int max;
    max=find_max(10,20,30);
    printf(max);
    return 0;
}
