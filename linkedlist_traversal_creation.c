#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

traversal(struct Node *ptr)
{
    int i=0;
    while (ptr!=NULL)
    {
      printf("Element %d: %d\n",i,ptr->data);
      ptr=ptr->next;
      i++;
    }

}

int insert_at_beg(struct Node *head,int a)
{
    struct Node *ptr=(struct Node *)malloc(sizeof(struct Node));

    ptr->next=head;
    ptr->data=a;

    return ptr;

}

int insert_at_index(struct Node *head,int a , int index)
{
    struct Node *ptr=(struct Node *)malloc(sizeof(struct Node));
    struct Node *p=head;
    int i=0;
    while (i!=index-1)
    {
        p=p->next;
        i++;
    }
    ptr->data=a;
    ptr->next=p->next;
    p->next=ptr;
    return head;
};

int insert_at_end(struct Node *head,int a)
{
    struct Node *ptr=(struct Node *)malloc(sizeof(struct Node));
    struct Node *p=head;

    while (p->next!=NULL)
    {
        p=p->next;
    }
    ptr->data=a;
    p->next=ptr;
    ptr->next=NULL;
    return head;
};

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    head=(struct Node *)malloc(sizeof(struct Node));
    second=(struct Node *)malloc(sizeof(struct Node));
    third=(struct Node *)malloc(sizeof(struct Node));
    fourth=(struct Node *)malloc(sizeof(struct Node));
    int ch=0, a, index;
    //linking nodes

    head->data=2;
    head->next=second;

    second->data=13;
    second->next=third;

    third->data=11;
    third->next=fourth;

    fourth->data=15;
    fourth->next=NULL;
    printf("1. traversal.\n2. Insert at the beginning\n3. Insert at the index\n4.Insert at the End\n5. Exit\n\n");
    printf("Enter your choice: ");
    scanf("%d",&ch);

    switch (ch)
    {
    case 1:
        traversal(head);
        exit(1);
    case 2:
        printf("Enter data to be inserted at beginning: ");
        scanf("%d",&a);
        head=insert_at_beg(head, a);
        traversal(head);
        exit(1);
    case 3:
        printf("Enter data to be inserted: ");
        scanf("%d",&a);
        printf("Enter index of insertion: ");
        scanf("%d",&index);
        head=insert_at_index(head,a,index);
        traversal(head);
        exit(1);
    case 4:
        printf("Enter data to be inserted: ");
        scanf("%d",&a);
        head=insert_at_end(head,a);
        traversal(head);
        exit(1);
    case 5:
        exit(1);
    }

    return 0;
}
