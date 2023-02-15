#include<stdio.h>

int partition(int A[], int lb, int ub){
    int pivot = A[lb];
    int part = ub;

    for(int i=0; i<7; i++){
        printf("%d ", A[i]);
    }
    printf("\nPivot = %d\n\n", pivot);

    for (int i=ub; i>lb; i--) {
        if (A[i] >= pivot){
            int dummy = A[i];
            A[i] = A[part];
            A[part] = dummy;
            part--;
        }
    }

    int dummy = A[lb];
    A[lb] = A[part];
    A[part] = dummy;

    return part;
}

void quickSort(int A[], int lb, int ub){
    if(lb < ub){
        int pivot = partition(A, lb, ub);
        quickSort(A, lb, pivot-1);
        quickSort(A, pivot+1, ub);
    }
}

int main()
{
    int A[] = {3, 2, 1, 5,  4, 3, 7};

    quickSort(A, 0, 7);

    printf("\nSolution:\n");
    for(int i=0; i<7; i++){
        printf("%d ", A[i]);
    }
}


