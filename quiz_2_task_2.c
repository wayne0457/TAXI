//有夠多誰寫得完，好吧...有人提早走
#include <stdio.h>
#include <stdlib.h>

void sort(int* a,int n){
  
    int* b = (int*) malloc(n*sizeof(int));
    int* c = (int*) malloc(n*sizeof(int));
    int count_1 = 0,count_2 = 0;

    if(n != 1){
        for(int i = 1; i < n; ++i) {
            if(a[i] < a[0]) {
                b[count_1++] = a[i];
            } else {
                c[count_2++] = a[i]; 
            }
        }
        if(count_1)
            sort(b,count_1);
        if(count_2)
            sort(c,count_2);

        a[count_1] = a[0];

        for(int i = 0; i <= count_1 + count_2; ++i) {
            if(i < count_1) {
                a[i] = b[i];
            }
            else if (i > count_1) {
                a[i] = c[i-1-count_1];
            }
        }
    }
}

int main(){
    int n;
    scanf("%d", &n);
    int* a = (int*) malloc(n*sizeof(int));

    for(int i = 0; i < n; ++i) {
        scanf("%d",&a[i]);
    }

    sort(a,n);

    for(int i = 0; i < n; ++i) {
        printf("%d",a[i]);
        if(i!= n-1) {
            printf(" ");
        }
    }
}
