#include<iostream>
#include<stdlib>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
};

void push(Node** head_ref,int new_data){
    Node* new_node=new Node();
    new_node->data=new_data;
    new_node->next=(*head_ref);
    (*head_ref)=new_node;
}

void deleteNode(Node** head_ref,int position){
    if(*head_ref==NULL)
    return;

    Node* temp=*head_ref;
    //if head need to be removed

    if(position==0){
        *head_ref=temp->next;
        free(temp);
        return;
    }

    //find previous node of the node to be deleted
    for(int i=0;temp!=NULL && i<position-1;i++){
        temp=temp->next;
        //if the position is more than number of nodes
        if(temp==NULL || temp->next==NULL)
        return;
    }
    //Node temp->next is the node to be deleted
    //Store pointer to the next of node to be deleted
    Node* next=temp->next->next;
    free(temp->next);
    temp->next=next;
}

void printList(Node* node){
    while(node!=NULL){
        cout<<node->data<<" ";
        node=node->next;
    }
}

int main(){
    //start with the empty list
    Node* head =NULL;
    push(&head,7);
    push(&head,4);
    push(&head,1);
    push(&head,5);
    push(&head,8);

    cout<<"Created the Linked List: ";
    printList(head);

    deleteNode(&head,4);
    cout<<"\nLinked List after deletion at position 4 : ";
    printList(head);
    return 0;
}

