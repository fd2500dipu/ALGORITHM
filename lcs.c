#include<stdio.h>

int max(int a, int b){
    if(a>b){
        return a;
    }
    else{
        return b;
    }
}

int lcs( char X[], char Y[], int x, int y){
    if (x == 0 || y == 0){
        return 0;
    }
    if (X[x-1] == Y[y-1]){
        return 1 + lcs(X, Y, x-1, y-1);
    }
    else{
        return max(lcs(X, Y, x-1, y), lcs(X, Y, x, y-1));
    }
}

int main(){
    int x = 6;
    int y = 7;

    char X[] = "BDCABA";
    char Y[] = "ABCBDAB";

    printf("Length of LCS is %d", lcs( X, Y, x, y));
}
