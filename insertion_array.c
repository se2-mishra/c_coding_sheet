#include <stdio.h>

void display(int arr[], int n)
{
    //traversal
    for(int i=0; i<n; i++)
    {
        printf("%d \t",arr[i]);
    }
    printf("\n");
}

int insertion(int arr[], int size, int element, int index, int capacity)
{
    if (size>=capacity)
        return -1;

    for (int i=size-1; i>=index; i--)
    {
        arr[i+1]=arr[i];
    }
    arr[index]=element;
    return 1;

}

int deletion(int arr[], int size, int index, int capacity)
{
    if (size==0)
        return -1;

    for (int i=index; i<size-1; i++)
    {
        arr[i]=arr[i+1];
    }


}

int main()
{
    int arr[100]={1,2,3,5,10};
    int size=5, element= 32, index= 3, capacity=100;
    display(arr, size);
    insertion(arr, size, element, index, capacity);
    size+=1;
    display(arr, size);
    int a=size, ind=1;
    deletion(arr, a, ind, capacity);
    size-=1;
    display(arr, size);


    return 0;
}
