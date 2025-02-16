#include<stdio.h>
#include<stdlib.h>

void swap(int* a,int* b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

int f(int* arr,int low,int high){
    int pivot=arr[low];
    int i=low;
    int j=high;

    while (i<j)
    {
        while (arr[i]<=pivot && i<=high-1)
        {
            i++;
        }

        while (arr[j]>pivot && j>=low+1)
        {
            j--;
        }

        if (i<j)
        {
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[low],&arr[j]);
    return j;
}

void qs(int* arr,int low,int high){
    if (low<high)
    {
        int pindex=f(arr,low,high);
        qs(arr,low,pindex-1);
        qs(arr,pindex+1,high);
    }
    
}

int main(){
    int arr[]={4,6,2,5,7,9,1,3};
    int low=0;
    int n=sizeof(arr)/sizeof(arr[0]);
    int high=n-1;

    qs(arr,low,high);
    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }

    return 0;
    
}