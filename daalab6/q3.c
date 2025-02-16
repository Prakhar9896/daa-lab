#include<stdio.h>
#include<stdlib.h>

void merge(int a[],int low,int mid, int high){
    int left=low;
    int right =mid+1;
    int temp[100];
    int k=0;
    while (left<=mid && right<=high)
    {
        if (a[left]<a[right])
        {
            temp[k++]=a[left];
            left++;
        }

        else {
            temp[k++]=a[right];
            right++;
        }
        
    }

    while(left<=mid){
        temp[k++]=a[left];
        left++;
    }
    while (right<=high)
    {
        temp[k++]=a[right];
        right++;
    }

    for (int i = low; i <= high; i++)
    {
        a[i]=temp[i-low];
    }
 
}
void mergesort(int arr[],int low,int high){
    if (low>=high) return;
    int mid=(low+high)/2;
    mergesort(arr,low,mid);
    mergesort(arr,mid+1,high);
    merge(arr,low,mid,high);
}
int main(){
    int a[]={4,6,2,5,7,9,1,3};
    int n=sizeof(a)/sizeof(a[0]);
    int low=0;
    int high=n-1;
    mergesort(a,low,high);
    for (int i = 0; i < n; i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}