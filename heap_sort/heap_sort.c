#include<stdio.h>


int largestOfThree(int *arr,int parentIndex,int leftChildIndex,int rightChildIndes,int n){
    int largest=parentIndex;
    
    if(leftChildIndex<n && arr[largest]<arr[leftChildIndex]){
        largest=leftChildIndex;
    }

    if(rightChildIndes<n && arr[largest]<arr[rightChildIndes]){
        largest=rightChildIndes;
    }

    return largest;
}

void heapify(int *arr,int i,int n){
    int largest=largestOfThree(arr,i,i*2+1,i*2+2,n);
    if(largest!=i){
        int temp=arr[largest];
        arr[largest]=arr[i];
        arr[i]=temp;

        heapify(arr,largest,n);
    }
}


// n/2 element in the max heap are not leaf element they are parents
void maxHeap(int *arr,int n){
    for(int i=n/2-1;i>=0;i--){
        heapify(arr,i,n);
    }
}


void heapSort(int *arr,int n){
    maxHeap(arr,n);
    printf("first maxheap made");
    int max=n;
    for(int i=n-1;i>=0;i--){
        int temp=arr[i];
        arr[i]=arr[0];
        arr[0]=temp;
        max=max-1;
        heapify(arr,0,max);
    }
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
    heapSort(arr,n);
    printf("array after the sort\n");
    for(int i=0;i<n;i++){
        printf("%d",arr[i]);
        printf(" ");
    }
    return 0;
}