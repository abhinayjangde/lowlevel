#include <stdio.h>
void printArray(int *arr, int n){
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void bubbleSort(int *arr, int n){
    bool isSorted = false;
    for(int i=0; i<n-1; i++){
        printf("Working on pass number %d\n", i+1);
        isSorted = true;
        for(int j=0; j<n-1-i; j++){
            if(arr[j] > arr[j+1]){
                // swap
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                isSorted = false;
            }
        }
        if(isSorted){
            break;
        }
    }
}
int main(){
    int nums[5] = {5, 6, 7, 20, 10};
    int n = sizeof(nums)/sizeof(nums[0]);

    printArray(nums,n);
    bubbleSort(nums,n);
    printArray(nums,n);

    return 0;
}

