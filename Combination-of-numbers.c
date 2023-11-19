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


int main() {
    // Write C code here
    //int a[] = {4,5,6,7,8,9};
    int a[] = {1,2,3,4,5};
    printCombination(a,5,2); //Combination of 2
    printCombination(a,5,3); //Combination of 2
    return 0;
}
