#include <stdio.h>








int main()
{
    int i =0, mid=0;
    int a[] = {12, 23, 45, 55, 66, 22, 10};
    int no = (sizeof(a)/sizeof(a[0]));
    mid = (0+no)/2;
    merge_sort(a, 0, mid+1, no-1);
    for(i =0 ; i < no -1;i++)
    printf("\n%d",a[i]);
    return 0;
}
