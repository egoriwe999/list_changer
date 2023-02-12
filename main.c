#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Item { 
    int data; 
    struct Item* next; 
} Item;

typedef struct Queue{ 
    Item* head; 
    Item* tail;
} Queue;


void deleteList(Item *head) {
    Item* prev = NULL;
    while ((head)->next) {
        prev = head;
        head = (head)->next;
        free(prev);
    }
    free(head);
}

Item *delsymv(Item *p) {
  Item* a = (Item*)calloc(1,sizeof(Item));
    for(a = p;a;){
        if(a->data == ' ' && a->next && a->next->data == ' ') {
                a = a->next;
        }

        else if(a->data == '!' || a->data == '.' || a->data=='?') {
                a->data = '\n';
                a->next->data -= 32;
                a = a->next;
        }
        if(a->data == '"' || a->data == '\n') {
                //a = a->next;
                if(a->next->data!=NULL){
                        a->next->data -= 32;
                }
                a = a->next;
        }
        else {
            a = a->next;
        }
    }
    return p;
}

int input(Queue* list,int* str) {
    Item* new=(Item*)malloc(sizeof(Item));
    if(!new){
        return 1;
    }
    new->data = *str;
    new->next=NULL;
    if(!list->head){
        list->head = new;
    }
    else{
        list->tail->next=new;
        //list-tali=new;
    }
    list->tail=new;
    return 0;
}

void print(const Queue* list) {
    Item* ptr = list->head;
    while(ptr) {
        printf("%c", ptr->data);
        ptr = ptr->next;
    }
}

int main() {
        int str;
        Queue* list = (Queue*)calloc(1,sizeof(Queue));
        str = '"';
        input(list, &str);
        //str = getchar();
        while(str != EOF) {
                str = getchar();
                if(str == EOF) {
                        str = '"';
                        input(list, &str);
                        break;
                }
                input(list, &str);
        }
        input(list, &str);
        printf("\n");
        delsymv(list->head);
        //str = '"';
        //input(list, &str);
        print(list);
        printf("\n");
        deleteList(list->head);
        free(list);
}


