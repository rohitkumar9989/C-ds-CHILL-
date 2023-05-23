#include<stdio.h>
#include<stdlib.h>
struct linked _list{
    int el;
    struct linked_list *next;
};

typedef struct linked_list node;
node *head=NULL;
node *current=NULL;
int main (){
    printf ("Enter the length of the linked list: ");
    int len;
    scanf ("%d",&len);
    for(int i=0; i<len; i++){
        printf ("Enter the element: ");
        node *newnode;
        newnode=(node *)malloc(sizeof(node));
        int ele;
        scanf ("%d", &ele);
        newnode->el=ele;
        if (head == NULL){
            head=newnode;;
            newnode->next=NULL;
            current=head;
            
        }
        else{
            current->next=newnode;
            newnode->next=NULL;
            current=newnode;
            
        }
    }
    printf ("Saving the data..\n");
    FILE *ptr;
    ptr=fopen("new.txt", "wb");
    fwrite(&head, sizeof(node *),1, ptr);
    printf ("Data written...\n");
    fclose (ptr);
    
    // #################################### //
    // Now a new pointer will be created in order to read the header data from the file and
    // print the data 
    FILE *pt;
    node *tempo;
    tempo=(node *)malloc(sizeof(node));
    tempo=NULL;
    pt=fopen ("new.txt", "rb");
    fread(&tempo, sizeof(node *),1, pt);
    printf ("The 1 element is: %d\n", tempo->el);
    current=tempo->next;;
    int i=1;
    while (current!=NULL){
        i++;
        printf ("The %d element is: %d\n", i,current->el);
        current=current->next;
    }
    fclose(pt);
}
