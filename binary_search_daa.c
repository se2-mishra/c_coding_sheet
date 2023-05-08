#include <stdio.h>

int binaryScr(int a[], int low, int high, int key)
{
    if (high >= low) 
    {
        int mid = (low+high)/ 2;
        if (a[mid] == key)
            return mid;
        if(a[mid] > key)
            return binaryScr(a, low, mid - 1, key);
        return binaryScr(a, mid + 1, high, key);
    }
    return -1;
}

int main()
{
    int n;
    int i,key;
    printf("Enter size of the array: ");
    scanf("%d",&n);
    int a[n];
    printf("\n\n\nElements in sorted form only\n\n\n");
    for(i=0;i<n;i++)
    {
        printf("Enter element at index %d: ",i);
        scanf(" %d",&a[i]);
    }
    printf("\n");
    
    printf("Enter the number to be searched\n");
    scanf("%d", &key);
    int result = binaryScr(a, 0, n - 1, key);
    if (result == -1) 
        printf("The element is not present in array");
    else
        printf("The element is present at index %d",result);
    return 0;
}