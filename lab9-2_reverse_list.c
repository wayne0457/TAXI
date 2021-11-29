#include <stdio.h>
#include <stdlib.h>


struct node{
    int data;
    struct node *next;
};
typedef struct node node_t;

typedef struct linked_list {
    node_t *head;
    node_t *tail;
} linked_list_t;

void output_list(linked_list_t *ptr_list) {
    while(ptr_list -> head != NULL){
        printf("%d", ptr_list -> head -> data);
        ptr_list -> head = ptr_list -> head -> next;
        if(ptr_list -> head != NULL){
            printf(" ");
        }
    }
}

void add_node(linked_list_t *list_ptr, int data) {
    node_t *ptr = (node_t*) malloc(sizeof(node_t));
    if(list_ptr -> head == NULL){
        ptr -> data = data;
        ptr -> next = NULL;
        list_ptr -> tail = ptr;
        list_ptr -> head = list_ptr -> tail;
    }
    else{
        ptr -> data = data;
        ptr -> next = NULL;
        list_ptr -> tail -> next = ptr;
        list_ptr -> tail = list_ptr -> tail -> next; 
    }
}

void initialize(linked_list_t *list_ptr) {
    list_ptr->head = NULL;
    list_ptr->tail = NULL;
}


void reverse_list(linked_list_t *list_ptr) {
    node_t *ptr, *temp;
    ptr = list_ptr -> head;
    int n = 0;
    while(ptr -> next != NULL){
        ptr = ptr -> next;
        ++n;
    }
    for(int i = n ; i > 0; --i){
        ptr = list_ptr -> head;
        for(int j = 0; j < i-1; j++){
            ptr = ptr -> next; /*把ptr往後到指定位置*/
        }
        ptr -> next -> next = ptr; /*把後面的next指向前面*/
    }
    ptr = list_ptr -> head;
    ptr -> next = NULL; /*把第一個的next指向NULL*/
    temp = (list_ptr -> head); 
    list_ptr -> head = list_ptr -> tail;
    list_ptr -> tail = temp;
}

void free_list(linked_list_t *ptr_list) {
    while(ptr_list -> head != NULL){
        node_t *ptr = (node_t*) malloc(sizeof(node_t));
        ptr = ptr_list -> head;
        ptr_list -> head = ptr_list -> head -> next;
        free(ptr);
    }
}
int main(){
    linked_list_t my_list;
    initialize(&my_list);
    
    int data, input_size;
    /* when you add a node, you add it at the tail */
    
    scanf("%d\n", &input_size);
    for(int i=0; i < input_size; ++i) {
        scanf("%d", &data);
        add_node(&my_list, data);
    }
    
    reverse_list(&my_list);
    output_list(&my_list);
    free_list(&my_list);

    return 0;
}

