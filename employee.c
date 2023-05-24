#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct employe_details {
    int roll_no;
    char name[30];
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
    printf ("Enter the choices from below: \n1)Enter User\n2)Search User");
    int choi;
    scanf("%d", &choi);
    if (choi==1){
        printf ("Enter the user name, rollno:  ");
        char name[30];
        int rollno;
        gets(name);
        scanf("%d", &rollno);
        add_user(name, rollno);
    }
    if (choi==2){
        
    }
}
