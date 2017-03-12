#include <stdio.h>
#include <string.h>
#include "source.h"

int main()
{
    /* Sort. Implement a function to print
     * the resulting array to see that it really works */ 
    int arr[] = {3, 4, 7, 2, 8};
    sort(arr, 5);
    for(int i=0;i<sizeof(arr)/sizeof(int);i++)
        printf("%d ", arr[i]);
    return 0;
}
