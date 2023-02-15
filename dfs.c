#include<stdio.h>

char c[8] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
int e[8] = {1, 1, 3, 1, 1, 2, 2, 1};
int list[8][3] = {{2}, {0}, {1,3,5}, {0}, {1}, {6,7}, {1,7}, {4}};
int checked[20];
int stack[20];
int top = 0;
int discovery [8];
int finish[8];
count = 1;

void push(int n){
    checked[n]=1;
    discovery[n]=count;
    count++;
    printf("%c", c[n]);
    stack[top++]=n;
}

void pop(){
    top = top-1;
    finish[stack[top]] = count;
    count++;
}

int notChecked(int n){
    if(checked[n]==1){
        return 0;
    }
    else return 1;
}

int main(){
    int n,f;
    push(0);
    while(top!=0){
        n=stack[top-1];
        for(int i=0; i<e[n]; i++){
            f=0;
            if(notChecked(list[n][i])==1){
                push(list[n][i]);
                f=1;
                break;
            }
        }
        if(f==0){
            pop();
        }
    }

     for(int j=0; j<8; j++){
        printf("\n");
        printf("%c", c[j]);
        printf(" %d", discovery[j]);
        printf(" %d", finish[j]);
    }
}
