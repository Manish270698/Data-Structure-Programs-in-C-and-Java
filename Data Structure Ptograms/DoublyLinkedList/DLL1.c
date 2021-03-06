#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node *prev,*next;
};
//Add node at front
void addFront(struct node* *head_ref, int info){
struct node *new_node=(struct node *)malloc(sizeof(struct node));
new_node->data=info;
new_node->next=(*head_ref);
new_node->prev=NULL;

if((*head_ref)!=NULL){
(*head_ref)->prev=new_node;
}
(*head_ref)=new_node;
}
//Add node after a given node
void addAfter(struct node* prev_node,int info){
    if(prev_node==NULL){return;}
struct node* new_node=(struct node*)malloc(sizeof(struct node));
new_node->data=info;
new_node->next=prev_node->next;
new_node->prev=prev_node;
prev_node->next=new_node;
if(new_node->next!=NULL)
    new_node->next->prev=new_node;
}
//Add node at the end
void addAtEnd(struct node* *head_ref,int info){
    struct node* current=(*head_ref);

struct node *new_node=(struct node*)malloc(sizeof(struct node));
new_node->data=info;
new_node->next=NULL;
new_node->prev=current;
if((*head_ref)==NULL){
        new_node->prev=NULL;
    (*head_ref)=new_node;
    return;
}
while(current->next!=NULL){
    current=current->next;
}
current->next=new_node;
new_node->prev=current;
}
//Add node before a given node
void addBefore(struct node* *head_ref,struct node *next_node,int info){
if(next_node==NULL)
    return;


    struct node* new_node=(struct node*)malloc(sizeof(struct node));
    new_node->data=info;
    new_node->next=next_node;
    new_node->prev=next_node->prev;
    next_node->prev=new_node;
    if(new_node->prev!=NULL)
        new_node->prev->next=new_node;
    else
        (*head_ref)=new_node;
}

//Delete a node in Doubly linked list

void deleteNode(struct node* *head_ref,struct node* del){
if(*head_ref==NULL || del==NULL)
    return;

    //if head node is to be deleted
    if(del==*head_ref)
        (*head_ref)=(*head_ref)->next;

    if(del->next!=NULL)
        del->next->prev=del->prev ;

    if(del->prev!=NULL)
        del->prev->next=del->next;

    free(del);
}

void print_list(struct node *head){
    struct node* last;
    printf("\nTraversal in forward direction: ");
while(head!=NULL){
    printf("%d ",head->data);
    last=head;
    head=head->next;
}

printf("\nTraversal in reverse direction: ");
while(last!=NULL){
    printf("%d ",last->data);
    last=last->prev;
}
}
void main(){
struct node* head=NULL;
addFront(&head,5);
addAtEnd(&head,7);
addAfter(head->next,2);
addBefore(&head,head->next->next,6);
print_list(head);

 deleteNode(&head, head); /*delete first node*/
    deleteNode(&head, head->next); /*delete middle node*/
    deleteNode(&head, head->next); /*delete last node*/

    /* Modified linked list will be NULL<-8->NULL */
    printf("\n Modified Linked list ");
    print_list(head);
}
