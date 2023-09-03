#include<stdio.h>
void printsort(int *a,int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}
int partion(int * arr,int lb,int ub)
{
    int temp;
    int start=lb;
    int end=ub;
    int pivot=arr[lb];
    while(start < end)
    {
        while(arr[start]<=pivot)
        {
            start ++;
        }
         while(arr[end]>pivot)
        {
            end --;
        }
        if(start< end)
        {
            // swap(arr[start],arr[end]);
            temp=arr[start];
            arr[start]=arr[end];
            arr[end]=temp;
        }
    }
    // swap(arr[lb],arr[end]);
    temp=arr[lb];
    arr[lb]=arr[end];
    arr[end]=temp;
    return end;

}
void quicksort(int arr[],int lb,int ub)
{
    int loc;
    if(lb < ub)
    {
       loc= partion(arr,lb,ub);
       quicksort(arr,lb,loc-1);
       quicksort(arr,loc+1,ub);
    }
}
// void swap(int *a,int *b)
// {
//     int t;
//     t=*a;
//     *a=*b;
//     *b=t;
// }

int main(){
    int arr[]={4,3,6,1,8,7};
    int n=6;
    int lb=0;
    int ub=n-1;
    printsort(arr,n);
    quicksort(arr,lb,ub);
    printsort(arr,n);

    return 0;
}