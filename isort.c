#include <stdio.h>
// c = Close.

void insertion_sort(int* arr, int len){
     
     for(int *i = arr+1; i<arr+len; i++)
     {
        for(int *j=i-1; j>=arr; j--)
        {
            if(*(j+1) < *j)
            {
                int temp = *(j+1);
                shift_element(j,1);
                *j= temp;
            }// C if
        }// C second for
    }// C first for
}// C insertion_sort function.

void shift_element(int* arr, int i) {
   
    for(int* j = arr+i; j>arr ;j--)
    {
        *(j) = *(j-1);
    }
}// C shift_element function.

void printMe (int *arr, int len){
    
    for (int j = 0; j<len ; j++){
        printf("%d",arr[j]);
        // Check if j in the last cell of arr[],
        // and if so stop printing "," between the numbers.
        if (j < len-1) { 
	        printf(",");
        }// C if.
    }// C if  
} // C printMe function. 