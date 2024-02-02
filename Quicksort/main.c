#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *x,int *y);
void quicksort(int array[], int length);
void quicksort_recursion(int array[], int low, int high);
int partition(int array[], int low, int high);

int main()
{
    int array[] = {1,2,77,5,4,43,89,66};
    int length = 8;
    quicksort(array,length);

    for(int i=0; i<length; i++)
    {
        printf("Array element[%d]:%d",i,array[i]);
        printf("\n");
    }
}


void swap(int *x,int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void quicksort(int array[], int length)
{
    quicksort_recursion(array,0, length-1);
}

void quicksort_recursion(int array[], int low, int high)
{ if(low<high)
  {
    int pivot_index = partition(array, low, high);
    quicksort_recursion(array, low, pivot_index-1);
    quicksort_recursion(array, pivot_index+1, high);
  }
}

int partition(int array[], int low, int high)
{
    int pivot_value = array[high];

    int i = low;

    for(int j=low; j<high;j++)
    {
        if(array[j]<=pivot_value)
        {
            swap(&array[i],&array[j]);
            i++;
        }
    }

    swap(&array[i],&array[high]);
    return i;
}



