#include<stdio.h>
int binearySearch(int arr[],int low,int high,int target)
{
    if(low>high)
    {
        return -1;
    }

    int  mid = low+(high-low)/2;
    if(arr[mid]==target)
    {
        return mid;
    }
    if(arr[mid]>target)
    {
        return binearySearch(arr,low,mid-1,target);
    }
    else{
        return binearySearch(arr,mid+1,high,target);
    }
}
int main()
{
    int n,target;
    printf("Enter the no of elements:");
    scanf("%d",&n);

    int arr[n];
    printf("Enter the elements:");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    printf("Enter the element to be search:");
    scanf("%d",&target);
    int result = binearySearch(arr,0,n-1,target);

    if(result!=-1)
    {
        printf("Elements found at the index:%d",result);
    }
    else {
        printf("Elements not found");
    }
}