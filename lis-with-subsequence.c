#include <stdio.h>
int searchReplace(int *lis, int left, int right, int key){
    int mid;
    for (mid = (left+right)/2; left <= right; mid = (left+right)/2){
        if (lis[mid] > key){
            right = mid - 1;
        }
        else if (lis[mid] == key){
            return mid;
        }
        else if (mid+1 <= right && lis[mid+1] >= key){
            lis[mid+1] = key;
            return mid+1;
        }
        else{
            left = mid + 1;
        }
    }
    if (mid == left){
        lis[mid] = key;
        return mid;
    }
    lis[mid+1] = key;
    return mid+1;
}
int main(){
    int i, tmp, size = 10, lis_length = -1;
    int *answer;
    int A[10] = {9, 2, 5, 3, 7, 11, 8, 10, 13, 6}, LIS[10], index[10] = {0};
    printf("\n\tInput: ");
    for(int i=0; i<10; i++){
        printf("%d  ",A[i]);
    }
    LIS[0] = A[0];
    for (i = 1; i < size; ++i){
        LIS[i] = 9999;
    }
    for (i = 1; i < size; ++i) {
        index[i] = searchReplace(LIS, 0, i, A[i]);
        if (lis_length < index[i]){
            lis_length = index[i];
        }
    }
    answer = (int*) malloc((lis_length+1) * sizeof(int));
    for (i = size-1, tmp = lis_length; i >= 0; --i){
        if (index[i] == tmp){
            answer[tmp] = A[i];
            --tmp;
        }
    }
    printf("\n\n\tLIS: ");
    for (i = 0; i < lis_length+1; ++i){
        printf("%d ", answer[i]);
    }
    printf("\n");
}
