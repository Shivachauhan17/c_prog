#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>


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

/*Writes/Read records to/from a file in text/bonary mode*/
void rw_records(){
    FILE *fp;
    struct emp{
        char name[40];
        int age;
        float bs;
    };

    struct emp e;
    // fp=fopen("EMPLOYEE.DAT","w");
    // if(fp==NULL){
    //     printf("fp is null");
    //     exit(1);
    // }
    // printf("Enter the values: ");
    // scanf("%s %d %f",e.name,&e.age,&e.bs);
    // fprintf(fp,"%s %d %f\n",e.name,e.age,e.bs);
    // fclose(fp);

    // fp=fopen("EMPLOYEE.DAT","r");
    // if(fp==NULL){
    //     printf("fp is null");
    //     exit(2);
    // }

    // while(fscanf(fp,"%s %d %f",e.name,&e.age,&e.bs)!=EOF){
    //     printf("record in file was: %s %d %f",e.name,e.age,e.bs);
    // }
    // fclose(fp);

    // fp=fopen("EMP.DAT","wb");
    // if(fp==NULL){
    //     printf("fp is null");
    //     exit(1);
    // }
    // printf("Enter the values: ");
    // scanf("%s %d %f",e.name,&e.age,&e.bs);
    // fwrite(&e,sizeof(e),1,fp);
    
    fp=fopen("EMP.DAT","rb");
    while(fread(&e,sizeof(e),1,fp)==1)
        printf("%s %d %f\n",e.name,e.age,e.bs);
    fclose(fp);
    return;
}


/*modify records*/
void modify_records(){
    FILE *fp;
    struct emp{
        char name[40];
        int age;
        float bs;
    };
    struct emp e;
    int recsize=sizeof(e);
    char  empname[50];
    fp=fopen("EMP.DAT","wb");
    printf("\nEnter name of employee to modify:");
    scanf("%s",empname);
    rewind(fp);
    while(fread(&e,recsize,1,fp)==1){
        if(strcmp(e.name,empname)==0){
            printf("enter new name,age & bs");
            scanf("%s%d%f",e.name,&e.age,&e.bs);
            fseek(fp,-recsize,SEEK_CUR);
            fwrite(&e,recsize,1,fp);
            printf("done");
            break;
        }
    }
    fclose(fp);
}

/*file copy program which copies text, .com and .exe file*/
void low_level_io(){
    char buffer[512],source[128],target[128];
    int in,out,bytes;
    printf("\nEnter source file name:");
    gets(source);
    in=open(source,O_RDONLY | O_BINARY);
    if(in==-1)
    {
        puts("cannot open file");exit(1);
    }
    printf("\nEnter target file name:");
    gets(target);
    out=open(target,O_CREAT | O_BINARY | O_WRONLY,S_IWRITE);
    if(out==-1){
        puts("cannot open file");
        close(in);exit(2);
    }
    while(1){
        bytes=read(in,buffer,512);
        if(bytes>0){
            write(out,buffer,bytes);
            printf("%d\n",out);
            printf("success.");
        }
        else
            break;
    }
    close(in);
    close(out);
    return;
}



int main(){
    low_level_io();
    return 0;
}