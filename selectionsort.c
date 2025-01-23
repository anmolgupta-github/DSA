#include<stdio.h>
void selection_sort(int arr[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        int min=i;
        for(int j=i+1;j<=n;j++)
        {
            if(arr[j]<arr[min])
            {
                min=j;
            }
                int temp = arr[min];
                arr[min]=arr[i];
                arr[i]=temp;
            
        }
    }
}
int main()
{
    int n;
    printf("Enter the number of elements:");
    scanf("%d",&n);

    int arr[n];
    printf("Enter the array elemnts:");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    selection_sort(arr,n);
    printf("Sorted array:\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\n",arr[i]);
    }
    return 0;
}