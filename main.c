#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node * createSinglyLinkedList(){
    Node * head = (Node *)malloc(sizeof(Node));
    return head;
}

void addAtLast(Node* head, int val){
    if(head == NULL){
        head->data = val;
        return;
    }
    Node *temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    Node * n = (Node*)malloc(sizeof(Node));
    n->data = val;
    n->next = NULL;
}

void print(Node * head){
    Node * temp = head;
    while(temp->next){
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

void f(){
    static int x = 0;
    x++;
    printf("%d",x);
}
int main(void)
{
    // Node * head = createSinglyLinkedList();
    // addAtLast(head, 4);
    // addAtLast(head, 49);
    // addAtLast(head, 8);

    // print(head);

   f();
   f();
   f();

    return 0;
}
