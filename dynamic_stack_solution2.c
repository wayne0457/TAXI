/*
也可以用這個方法
#include <stdlib.h>
#include <stdio.h>
int main(){
    int max = 4;
    int* a = (int*) malloc(max * sizeof(int));
    for(int i = 0; i< max; ++i){
        scanf("%d",a+i);
    }
    for(int i = 0; i < max; ++i){
        printf("%d",*(a+i));
    }
    for(int i = max; i < 2 * max; ++i)
      *(a+i) =  (int*) malloc(sizeof(int));
    for(int i = max; i< max*2; ++i){
        scanf("%d",a+i);
    }
    for(int i = 0; i< max*2; ++i){
        printf("%d",*(a+i));
    }
}
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct stack {
    int *head;
    int top;
    int max_size;
} stack_arr_t;


void stack_init(stack_arr_t *s, int size) {
/* your code here
 *
 */
  s -> max_size = size;
  s -> head = (int*) malloc (size*sizeof(int));
  s -> top = 0;
}

void stack_destroy(stack_arr_t *s) {
/* your code here
 *
 */
  free(s -> head);
}

void dynamic_push(int elem, stack_arr_t *s) {
/* your code here
 *
 */
  ++ (s -> top);
  if(s -> top > s -> max_size){
    for(int i = s -> max_size; i < 2 * s -> max_size; ++i){
      *(s -> head + i) = (int*) malloc(sizeof(int));
      *(s -> head + i) = elem;
    }
    s -> max_size = s -> max_size *2;
    *(s -> head + (s -> top)-1) = elem;

  }
  else{
    *(s -> head + (s -> top)-1) = elem;
  }
}

int dynamic_pop(stack_arr_t *s) {
/* your code here
 *
 */
  if(s -> top != 0){
    -- s -> top;
    if(s -> top < s -> max_size / 4){
      int *a = (int*) malloc (s -> max_size * sizeof(int));
      for(int i = 0; i < s -> max_size; ++i){
        a[i] = *(s -> head + i);
      }
      s -> max_size = s -> max_size / 2;
      free(s -> head);
      s -> head = (int*) malloc ( s -> max_size * sizeof(int));
      for(int i = 0; i < s -> max_size; ++i){
        *(s -> head + i) = a[i];
     }
  }
    return(*(s -> head + s -> top ));
  }
  else{
    printf("\nPopping empty stack!\n");
    exit(1);
  }
  return 0;
}



void show_stack(stack_arr_t *s) {
/* your code here
 *
 */
  printf("Stack contains %d element(s)\n", s -> top );
  for(int i = 0; i < s -> top-1; i++){
    printf("%d ", *(s -> head + i ));
  }
  printf("%d", *(s -> head + s -> top -1));
  printf("\n");
  printf("top = %d, ", s -> top);
  printf("max_size = %d", s -> max_size);
}




int main(){
    stack_arr_t my_stack;

    int input_size, temp, max_size, pop_size;

    /* input stack's max size */
    scanf("%d", &max_size);
    stack_init(&my_stack, max_size);

    /* input elements to be pushed */
    scanf("\n%d", &input_size);
    int i;
    for(i=0; i<input_size; ++i){
        scanf("\n%d", &temp);
        dynamic_push(temp, &my_stack);
    }

    /* input number of elements to be popped */
    scanf("\n%d", &pop_size);
    for(i=0; i < pop_size-1; ++i){
        printf("%d ", dynamic_pop(&my_stack));
    }
    if (0 != pop_size){
        printf("%d\n", dynamic_pop(&my_stack));
    }

    show_stack(&my_stack);

    stack_destroy(&my_stack);

    return 0;
}
