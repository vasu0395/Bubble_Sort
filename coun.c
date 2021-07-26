#include <stdio.h>
#include <stdlib.h> // standard library
#include <sys/time.h> // library including time functions
// Function to generate random number and initalize array
void generate_random_number(int arr[],int n) // parameter array and size
{
    for(int i=0;i<n;i++)
    {
        arr[i]=rand()%n + 1; // using random function to initalize
    }
}
// Function to swap two number 
void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
// Function for bubble_sorting
void bubble_sort(int arr[],int size) // parameter array and size
{
    for(int i=0;i<size-1;i++)
    {
        for(int j=0;j<size-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(&arr[j],&arr[j+1]);
            }
        }
    }
}
// Function to print element of array
void print(int arr[],int size)
{
    for(int i=0;i<size;i++)
    printf("%d ",arr[i]);
    printf("\n");
}
void time_based_sorting(int intial_count,int increment_count)
{
    struct timeval te; 

    for(int i=0;i<8;i++)
    {
        int t=intial_count+increment_count*i;
        // creating array of size t
        int arr[t];
        // calling generate_random_number Function to initalize array
        generate_random_number(arr,t);
        
        gettimeofday(&te,NULL);
        //storing starting time
        long long start=te.tv_sec*1000LL + te.tv_usec / 1000;
        // calling bubble_sort for sorting element of array
        bubble_sort(arr,t);
        gettimeofday(&te,NULL);
        // sorting ending time
        long long end=te.tv_sec*1000LL + te.tv_usec / 1000;
        // print difference of end time  - start time
        printf("\t %lld",end - start);
    }
}
int main() {
        int intial_count=8000;
        int increment_count=4000;
        time_based_sorting(intial_count,increment_count);
        return 0;
}

