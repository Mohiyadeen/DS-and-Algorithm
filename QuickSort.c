#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a =*b;
    *b =temp;
}

void quick_sort(int a[], int low, int high) {
int pivot = (low + high)/2;
int i=0,j=0, p= 0;
if(low>=high)
    return;
swap(&a[pivot],&a[low]);
pivot = low;
i = low+1;
j=i;
while(i<=high){
    if(a[pivot] >= a[i])
        swap(&a[i++],&a[j++]);
    else
        i++;
}
p = j-1;
swap(&a[p],&a[pivot]);

quick_sort(a, low, p-1);
quick_sort(a, p+1,high);

}

int main()
{
    int i =0;
    int a[] = {12, 23, 45, 55, 66, 22, 10};
    int no = (sizeof(a)/sizeof(a[0]));
    quick_sort(a, 0, no-1);
    for(i =0 ; i < no -1;i++)
    printf("\n%d",a[i]);
    return 0;
}
