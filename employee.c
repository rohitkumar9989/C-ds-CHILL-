#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct employe_details {
    int roll_no;
    char name[15];
    char password[10];
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
    printf("Enter the passoword: ");
    char pass[10];
    scanf("%s", pass);
    strcpy(newnode->emp.password, pass);
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
    printf ("Enter the user id: ");
    int roll;
    scanf ("%d",&roll);
    FILE *pt;
    pt=fopen("data.txt", "rb");
    node *read;
    read=(node *)malloc(sizeof(node));
    fread(&read, sizeof(node *), 1, pt);
    while (read!=NULL){
        if (read->emp.roll_no==roll){
            printf ("Name is %s\n", read->emp.name);
            printf ("Enter the password: ");
            char pass[10];
            scanf ("%s", pass);
            if (strcmp(pass, read->emp.password)==0){
                printf ("The token is: %s\n", read->emp.token_.token);
                break;
            }
        }
        read=read->next;
    }
    if (read==NULL){
        printf ("An employee with roll %d was not found\n", roll);
    }
    fclose(pt);
}
int main(){
    while (1){
        printf ("Enter the choices from below: \n1)Enter User\n2)Search User\n3)Exit\nChoice:");
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
            search_user();
        }
        if (choi==3){
            break;
        }
    }
}
