#include<stdio.h>

/*char c[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
int mat[20][20];*/

char c[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
int mat[9][9] = {
    {0, 1, 0, 0, 0, 1, 0, 0, 0},
    {0, 0, 1, 1, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 1, 0, 1},
    {0, 0, 0, 0, 0, 0, 0, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0}
};

int checked[20];
int que[20];
int level[20];
int first=0, last=0, flag=0;

void enq(int n, int l){
    checked[n] = 1;
    level[n] = l;
    que[last++] = n;
}

int dq(){
    printf("%c", c[que[first]]);
    first++;
    return que[first - 1];
}

int notChecked(int n){
    if(checked[n] == 1){
        flag=1;
        return 0;
    }
    else return 1;
}

int main(){

    int out;

    /*int e,n,out;
    printf("Enter edge number: ");
    scanf("%d",&e);
    printf("Enter node number: ");
    scanf("%d",&n);

    char j,k;
    printf("Enter edges: \n");
    for(int i=0;i<e;i++){
        scanf(" %c %c ",&j,&k);
        mat[j-97][k-97] = mat[k-97][j-97] = 1;
    }*/

    enq(0,0);

    printf("\n\nBFS: ");

    /*while(first<last){
        int n = dq();
        for(int i=0; i<e[n]; i++){
            level[list[n][i]]=distance;
            if(notChecked(list[n][i])==1){
                enq(list[n][i],level[n]+1);
            }
        }
    }*/

    while(first<last){
        out = dq();
        for(int j=0; j<9; j++){
            if(j == out){
                for(int k=0; k<9; k++){
                    if(mat[j][k] == 1){
                        if (notChecked(k) == 1){
                            enq(k, level[out]+1);
                        }
                    }
                }
            }
        }
    }

    printf("\n\nMatrix: \n");
    for(int i=0; i<9; i++){
        for(int x=0; x<9; x++){
            printf("%d ",mat[i][x]);
        }
        printf("\n");
    }

    printf("\nNode\tLevel");
    for(int j=0; j<9; j++){
        printf("\n %c\t", c[j]);
        printf(" %d ", level[j]);
    }

    /*if(flag==1){
        printf("\n\nCycle present");
    }
    else printf("\n\nCycle not present");*/

}
