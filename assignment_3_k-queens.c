//main.c

#include <stdio.h>
#include <stdlib.h>

int k, num = 0;

int score(int** queen, int* eight);
void arrange(int* column, int row);

void arrange(int* column, int row){
    int no = 0;
    for (int i = 0; i < k; ++i) {
        no = 0;
        if (row == 0) {
            column[row] = i;
            arrange(column, row + 1);
        } else {
        
            for (int j = 0; j < row; ++j) {
                
                if ((i == column[j]) || ((i + row) == column[j] + j) || (i - row) == (column[j] - j)) {
                    no = 1;
                    break;
                }
            }
            if (no == 0) {
                column[row] = i;
                if (row != k - 1) {
                    arrange(column, row + 1);
                } else {
                    break;
                }
            }
        }
    }

    if (row == k - 1 && no == 0) {
        
        for (int i = 0; i < k; ++i) {
            printf("%d ", column[i] + 1);
        }
        printf("\n");
        ++num;
    }
}

int main(){
    
    int* column = (int*) malloc(8 * sizeof(int));
    
    scanf("%d",&k);
    arrange(column, 0);
    printf("%d solution(s) for the %d-Queen problem.", num, k);
    return 0;
}
