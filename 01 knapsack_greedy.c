/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
void knap( int n, float w[], float p[], float capacity)
{
    float tp=0;
    int i, j, u, x[30];
    u=capacity;
    
    for (i=0; i<n; i++)
        x[i]=0;
    
    for (i=0; i<n; i++)
    {
        if (w[i]>u)
            break;
        
        else 
        {
            x[i]=1;
            tp=tp+p[i];
            u=u-w[i];
        }
    }
    if (i<n)
        x[i]=u/w[i];
    
    tp=tp+(x[i]*p[i]);
    printf("\n The result vector is: \n");
    for (i=0; i<n; i++)
        printf("%d \t", x[i]);
    printf("\n\nMaximum profit is : %f", tp);
}

int main()
{
    float w[30], p[30], capacity, ratio[30], temp;
    int num, i, j;
    printf("\n Enter the number of objects: ");
    scanf("%d", &num);
    printf("Enter the weights and profits of each object (W P): \n");
    for (i=0; i<num; i++)
    {
        scanf("%f %f",  &w[i], &p[i]);
    }
    
    printf("Enter the total capacity of knapsack: ");
    scanf("%f", &capacity);
    
    for (i=0; i<num; i++)
    {
        for (j=i+1; j<num; j++)
        {
            if (ratio[i] <ratio[j])
            {
                temp=ratio[j];
                ratio[j]=ratio[i];
                ratio[i]=temp;
                
                temp=w[j];
                w[j]=w[i];
                w[i]=temp;
                
                temp=p[j];
                p[j]=p[i];
                p[i]=temp;
            }
        }
    }
    
    knap(num, w, p, capacity);
    
    return 0;
}
