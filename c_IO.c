#include<stdio.h>
#include<stdlib.h>

//sprintf() and sscanf() function
void sprintf_sscanf(){
    int i=10,j;
    char ch='A',ch2;
    float a=3.14;
    char str[20];
    printf("%d %c %f\n",i,ch,a);
    sprintf(str,"%d %c %f",i,ch,a);
    printf("array of characters: %c",str[0]);

    sscanf(str,"%d %c",&j,&ch2);
    printf("given using sscanf: %d %c",j,ch2);
    return;
}

//getchar() and putchar() function
void getchar_putchar(){
    char ch;
    printf("enter a character:");
    ch=getchar();
    printf("you entered:");
    putchar(ch);
}

//gets() and puts() function
void gets_puts(){
    char *ch;
    ch = (char *)malloc(100 * sizeof(char));
    printf("enter a string:");
    gets(ch);
    printf("you entered:");
    puts(ch);
}

/*display the content of a file on the screen*/
void display_content(){
    FILE *fp;
    char ch;
    fp=fopen("filerw_test.c","r");
    while(1){
        ch=fgetc(fp);
        if(ch==EOF){
            break;
        }
        printf("%c",ch);
    }
    printf("\n");
    fclose(fp);
    return;
}
/*count the characters, tabs, spaces and newlines in a file*/
void count_chars(){
    FILE *fp;
    char ch;
    int nol=0,not=0,nob=0,noc=0;
    fp=fopen("filerw_test.c","r");
    while(1){
        ch=fgetc(fp);
        if(ch== EOF) break;
        noc++;
        if(ch==' ') nob++;
        if(ch=='\n') nol++;
        if(ch=='\t') not++;
        }
    fclose(fp);
    printf("Number of characters=%d\n",noc);
    printf("Number of lines=%d\n",nol);
    printf("NUmber of blanks=%d\n",nob);
    printf("Number of tabs=%d\n",not);
    return;
    
}
/*program to copy a file*/
void copy_file(){
    FILE *fs,*ft;
    char ch;
    fs=fopen("filerw_test.c","r");
    ft=fopen("filecopy_test.c","w");
    if(fs==NULL){
        printf("source file is not  opened");
        exit(1);
    }
    if(ft==NULL){
        printf("target file is not opened");
        fclose(fs);
        exit(2);
    }
    while(1){
        ch=fgetc(fs);
        if(ch==EOF){
            break;
        }
        else{
            fputc(ch,ft);
        }
    }
    fclose(fs);
    fclose(ft);
    return;
}

/*receiving string from keyboard and writing them to a file*/


int main(){
    copy_file();
    return 0;
}