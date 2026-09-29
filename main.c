#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    int data;
    struct Node *next;
};
int main(int argc, char **argv)
{
    struct Node *head;
    head = (struct Node *)malloc(sizeof(struct Node));

    struct Node *p;
    struct Node *q;
    struct Node *r;

    p = (struct Node *)malloc(sizeof(struct Node));
    q = (struct Node *)malloc(sizeof(struct Node));
    r = (struct Node *)malloc(sizeof(struct Node));

    p->data = 10;
    q->data = 20;
    r->data = 30;

    p->next = q;
    q->next = r;
    r->next = nullptr;

    head = p;

    struct Node *temp = head;

    while (temp != nullptr)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("nullptr");
    return EXIT_SUCCESS;
}
