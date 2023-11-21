// Online C compiler to run C program online
// Write a Program to print combination of numbers of r given a array elements n 
#include <stdio.h>

void printCombination(int *a, int n, int r)
{
    
    int temp[r];
    printf("\nCombination of %d :",r);
    combination(a,temp,0,n-1,0,r);
    
}
//Print nC2 combination
void combination(int a[], int temp[], int start , int end ,int index ,int r)
{
    int i;
    
    if(index == r)
    {
     for(i=0;i<r;i++)
        printf("%d",temp[i]);
     printf(" ");
     return;
    }
    
    for(i=start; i<=end && end-i+1 >= r-index;i++)
    {
        temp[index] = a[i];    
        combination(a,temp, i+1, end, index+1, r);
    }
    
}

void printNCombSum(int *a, int n, int sum)
{
    int temp[n];
    printf("\n Combination of Sum %d :", sum);
    NCombSum(a,temp,0,n-1,0,0,sum);   
}

void NCombSum(int *a, int *temp, int start, int end, int index, int curSum, int sum)
{
    int i=0;
    if(curSum == sum)
    {
        for(i=0;i<index;i++)
            printf("%d",temp[i]);
     printf(" ");
     return;
    }
    else if(curSum > sum)
        return;
    else if(start > end)
        return;
       
    for(i=start; i<=end ;i++)
    {
        temp[index] = a[i];
        curSum+=temp[index];
        NCombSum(a,temp, i, end, index+1, curSum, sum);
        //NCombSum(a,temp, i+1, end, index+1, curSum, sum);
        curSum-=temp[index];
    }

}

int main() {
    // Write C code here
    //int a[] = {4,5,6,7,8,9};
    int a[] = {1,2,3,4,5};
    printCombination(a,5,2); //Combination of 2
    printCombination(a,5,3); //Combination of 2
    return 0;
}
