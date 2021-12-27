/*老師表示前面我們都亂做*/
#include <stdio.h>
#include <stdlib.h>

void merge(int [], int, int);
void input(int [], int*, int *);
void output(int [], int);


int main(){
  int a[40],  size1, size2;

   //  input
   input(a, &size1, &size2);

   //  merge
   merge(a,size1,size2);

   //  output
   output(a, size1+size2);

   return 0;
}

  
void merge(int a[], int size1, int size2){
/*  a and b's memory must be next to each other.  *  a is ahead of b. 
 *  b begins at a[size1]. 
 * The merged array should be saved at a's location of length size1+size2.  
 */
    int x = 0, y = size1, z = 0;
    int* b = (int*) malloc((size1+size2)*sizeof(int));
    for(int i = 0; i < size1 + size2; i++){
        if(a[x] < a[y]) {
            b[i] = a[x];
            ++x;
        } else {
            b[i] = a[y];
            ++y;
        }
        if(x > size1-1 || y > size1+size2){
            z = (x < size1 )? x : y;
            for(int j = i + 1; j < size1 +size2; ++j){
                b[j] = a[z];
                ++z;
            }
            break;
        }
    }
    for(int i = 0; i < size1 + size2; i++){
        a[i] = b[i];
    }
}
void input(int a[], int *p_sz1, int *p_sz2){
    scanf("%d",p_sz1);
    for(int i = 0; i < *p_sz1; ++i){
        scanf("%d", &a[i]);
    }
    scanf("%d",p_sz2);
    for(int i = *p_sz1; i < *p_sz1 + *p_sz2; ++i){
        scanf("%d", &a[i]);
    }
}

void output(int a[], int size){
    printf("%d\n",size);
    for(int i = 0; i < size; ++i){
        printf("%d", a[i]);
        if(i != size - 1){
            printf(" ");
        }
    }
}
