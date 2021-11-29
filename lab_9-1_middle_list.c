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

void initialize(linked_list_t *list_ptr) {
    list_ptr->head = NULL;
    list_ptr->tail = NULL;
}

void output_list(linked_list_t *ptr_list) {
    while(ptr_list -> head != NULL){
        printf("%d ", ptr_list -> head -> data);
        ptr_list -> head = ptr_list -> head -> next;
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

node_t* find_middle(linked_list_t *list_ptr) {
    node_t *ptr = (node_t*) malloc(sizeof(node_t));
    ptr = list_ptr -> head;
    int n = 0;
    while(ptr -> next != NULL){
        ptr = ptr -> next;
        ++n;
    }
    ptr -> next = list_ptr -> head;
    for(int i = 0; i < (n+1)/2; ++i){
        ptr = ptr -> next;
    }
    return ptr -> next;
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
    node_t *middle_ptr;
    
    int data, input_size;
    /* when you add a node, you add it at the tail */
    
    scanf("%d\n", &input_size);
    for(int i=0; i < input_size; ++i) {
        scanf("%d", &data);
        add_node(&my_list, data);
    }
    
    middle_ptr = find_middle(&my_list);
    printf("%d\n", middle_ptr->data);

    free_list(&my_list);
    return 0;
}

