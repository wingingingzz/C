#include <stdio.h>

int* merge(int* p1,int* p2, int numsSize);
int* merge_sort();

int* merge(int* p1, int* p2, int numsSize){
    int* ans_arr = (int*)malloc(sizeof(int)*numsSize);
    int i = 0;
    while(!p1 && !p2 && i <= numsSize){
        if(*p1 > *p2){
            ans_arr[i] = *p1;
            p1++;            i++;
        }
        else
        {
            ans_arr[i] = *p2;
            p2++;            i++;
        }
    }
    return ans_arr;

}

int* merge_sort(int* arr, int numsSize){
    int mid_of_array = numsSize / 2;
    int size = numsSize / 2;
    int *arr2 = arr[mid_of_array];

    temp1 = merge_sort(arr,size);
    temp2 = merge_sort(arr2,size);
    temp = merge(arr, arr2);

    return ans_arr;
    
}

