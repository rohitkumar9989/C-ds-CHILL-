#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct employe_details {
    int roll_no;
    char name[15];
    struct token {
        char token[10];
    }token_;
};
struct linked_list {
    struct employe_details emp;
    struct linked_list *next;
};
typedef struct linked_list node;
node *head=NULL;
node *current=NULL;

void add_user(char nam[], int roll_no){
    node *newnode;
    newnode=(node *)malloc(sizeof(node));
    newnode->emp.roll_no=roll_no;
    strcpy(newnode->emp.name,nam);
    printf ("Enter the token: ");
    char t[10];
    scanf ("%s", t);
    strcpy(newnode->emp.token_.token, t);
    newnode->next=NULL;
    if (head==NULL){
        head=newnode;
        current=newnode;
        
        FILE *pt;
        pt=fopen("data.txt", "wb");
        fwrite (&head, sizeof(node *),1, pt);
        fclose(pt);
    }
    else{
        current->next=newnode;
        current=newnode;
    }
}
void search_user(){
    
}
int main(){
    while (1){
        printf ("Enter the choices from below: \n1)Enter User\n2)Search User\nChoice:");
        int choi;
        scanf("%d", &choi);
        if (choi==1){
            printf ("Enter the user name, rollno:\n");
            char name[30];
            printf ("Enter the name: ");
            scanf ("%s", name);
            printf ("Enter the roll no: ");
            int rollno;
            scanf("%d", &rollno);
            add_user(name, rollno);
        }
        if (choi==2){
            break;
        }
    }
}
