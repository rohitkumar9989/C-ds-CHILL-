#include<stdio.h>
#include<stdlib.h>
#include "arrayadt.h"
struct linked_list{
    int el;
    struct linked_list *next;
};
typedef struct linked_list node;
node *head=NULL;
node *current=NULL;
void create (){
    printf("Creating a linked node\n");
    int num;
    printf ("Enter the element to be entered\n");
    scanf ("%d", &num);
    node *newnode;
    newnode=(node*)malloc(sizeof(node));
    newnode->el=num;
    newnode->next=NULL;
    if (head==NULL){
        head=newnode;
        current=newnode;
    }
    else{
        current->next=newnode;
        current=newnode;
    }
    printf ("The address of the var is %d", newnode);
}
void display (){
    node *temp;
    temp=head;
    printf ("The array is: ");
    while(temp!=NULL){
        printf ("%3d", temp->el);
        temp=temp->next;
    }
}
int search (){
    printf ("Enter the element to be searched: ");
    scanf ("%d", &search_el);
    node *_temp;
    _temp=head;
    while (_temp!=NULL){
        if (_temp->el==search_el){
            return 1;
        }
        _temp=_temp->next;
    }
}
// Use the previos node's address variable pointing towards the number and the newnodes->"next" pointing to the next node
void insert (){
    printf ("Enter the element to be inserted: ");
    scanf ("%d", &insert_el);
    node *newnode, *temp, *main_po=NULL;
    newnode=(node*)malloc(sizeof(node));
    printf ("Enter the position: ");
    int pos;
    scanf ("%d", &pos);
    temp=head;
    for (int i=0; i<pos-1;i++){
        if (i==pos-1){
            break;
        }
        temp=temp->next;
        main_po=temp;
    }
    newnode->el=insert_el;
    if (main_po == NULL) {  
        newnode->next = head;
        head = newnode;
    } else {
        newnode->next = main_po->next;
        main_po->next = newnode;
    }

}
void delete_last(){
    printf ("Performing delete ops\n");
    node *temp;
    temp=head;
    while (temp!=NULL){
        temp=temp->next;
        if (temp->next->next==NULL){
            free(temp->next->next);
            temp->next=NULL;
            break;
        }
    }
}
void delete_mem(){
    node *temp, *val;
    temp=head;
    while (temp!=NULL){
        val=temp->next;
        free(temp);
        temp=val;
    }
    head=NULL;
    printf ("The memoory has been deleted\n");
}
void iasp(){
    node *temp;
    temp=head;
    int pos;
    printf ("Enter the position: ");
    scanf ("%d", &pos);
    for (int i=0; i<pos-1; i++){
        temp=temp->next;
    }
    temp->next=temp->next->next;

}

int main (){
    while (1){
    printf("Enter your choice\n1)Create rec:\n2)Search:\n3)Display: \n4)Delete_last: \n5)Delete mem: \n6)Insert: \n7)Iasp: \n8)Exit: \n");
    int choi;
    scanf ("%d", &choi);
        if (choi==1){
            create();
        }
        if (choi==2){
            result_search=search();
            printf ("%d\n", result_search);
        }
        if (choi==3){
            display();
        }
        if (choi==4){
            delete_last();
        }
        if (choi==5){
            delete_mem();
        }
        if (choi==6){
            insert();
        }
        if (choi==7){
            iasp();
        }
        
    }
}
