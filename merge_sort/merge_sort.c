#include<stdio.h>

void merge(int *arr,int p,int m, int q){
    int leftArrLength=m-p+1;
    int rightArrLength=q-m;

    int leftArr[leftArrLength];
    int rightArr[rightArrLength];

    for(int i=p;i<p+leftArrLength;i++){
        leftArr[i-p]=arr[i];
    }
    for(int i=m+1;i<m+1+rightArrLength;i++){
        rightArr[i-(m+1)]=arr[i];
    }

    int leftArrIndex=0;
    int rightArrIndex=0;
    int arrStartingIndex=p;

    while(leftArrIndex<leftArrLength && rightArrIndex<rightArrLength){
        if(leftArr[leftArrIndex]<rightArr[rightArrIndex]){
            arr[arrStartingIndex++]=leftArr[leftArrIndex++];
        }
        else{
            arr[arrStartingIndex++]=rightArr[rightArrIndex++];
        }
    }

    while(leftArrIndex<leftArrLength){
        arr[arrStartingIndex++]=leftArr[leftArrIndex++];
    }

    while(rightArrIndex<rightArrLength){
        arr[arrStartingIndex++]=rightArr[rightArrIndex++];  
    }

}

void merge_sort(int *arr,int p,int q){
    if(p>=q){
        return;
    }

    int m=(p+q)/2;
    merge_sort(arr,p,m);
    merge_sort(arr,m+1,q);
    merge(arr,p,m,q);
    printf("\n");
    printf("\n");
}

int main(){
    int n;
    printf("enter the length of array:");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements of the array\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("\n");
    for(int i=0;i<n;i++){
        printf("%d",arr[i]);
        printf(" ");
    }
    printf("\n");
    merge_sort(arr,0,n-1);
    printf("array after the sort\n");
    for(int i=0;i<n;i++){
        printf("%d",arr[i]);
        printf(" ");
    }
    return 0;
}