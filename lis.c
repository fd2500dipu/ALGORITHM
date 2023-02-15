#include<stdio.h>

int n = 10;

int lis(int input[]){
    int length[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    length[0] = 1;

    for(int i=1; i<n; i++){
        for(int j=0; j<i; j++){
            if(input[j]<input[i] && length[j]>length[i]){
                length[i] = length[j];
            }
        }
        length[i]++;
    }

    int lis = 0;

    for(int i=0; i<n; i++){
        if(length[i]>lis){
            lis = length[i];
        }
    }
    printf("\nLength of LIS = %d",lis);
}
int main(){
    int input[] = {9, 2, 5, 3, 7, 11, 8, 10, 13, 6};
    for(int i=0; i<10; i++){
        printf("%d  ",input[i]);
    }
    lis(input);
}
