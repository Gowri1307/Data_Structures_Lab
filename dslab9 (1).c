#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <process.h>
struct node {
    int data;
    struct node *next;
    struct node *prev;
};

typedef struct node *NODE;

NODE getnode() {
    NODE p;
    p = (NODE) malloc(sizeof(struct node));
    if (p != NULL) return p;
    else {
	printf("No Memory \n");
	return NULL;}
}

NODE push(NODE head,int new_data)
{
    NODE new_node = getnode();

    new_node->data = new_data;

    new_node->next = head;
    new_node->prev = NULL;

    if (head!= NULL)
        head->prev = new_node;

    head= new_node;

    return head;
}

NODE insert_left(int item, NODE first)
{
    NODE t,p,c;
    if(first==NULL)
    {
        printf("List is empty");
        return first;
    }
    c=first;
    while(c!=NULL)
    {
        if(item==c->data)
            break;
        c=c->next;
    }
    if(c==NULL)
    {
        printf("Key not found");
        return first;
    }
    if(c==first)
    {
        printf("Enter the item to insert towards left %d= ",item);
        t=getnode();
        scanf("%d",&t->data);
        t->next=first;
        first->prev=t;
        t->prev=NULL;
        first=t;
        return first;
    }
    p=c->prev;
    printf("Enter the item to insert towards left %d= ",item);
    t=getnode();
    scanf("%d",&t->data);
    p->next=t;
    t->prev=p;
    c->prev=t;
    t->next=c;
    return first;
}

NODE delete_item(int item, NODE first)
{
    NODE p,c,nextn;
    if(first==NULL)
    {
        printf("List is empty");
        return first;
    }
    c=first;
    while(c!=NULL)
    {
        if(item==c->data)
            break;
        c=c->next;
    }
    if(c==NULL)
    {
        printf("Item not found");
        return first;
    }
    p=c->prev;
    if(p==NULL)
    {
        first=c->next;
        c->next->prev=NULL;
        return first;
    }
    nextn=c->next;
    p->next=nextn;
    nextn->prev=p;
    return first;
}

NODE disp(NODE first)
{ NODE t;
    if(first==NULL)
    {
        printf("List is empty");
        return;
    }
    t=first;
    printf("\nTraversal in forward direction \n");
    do{
        printf(" %d\t", t->data);
        t = t->next;
    }while(t!=NULL);
}



int main() {
    int choice,ele1,ele2,ele3,val,item;
    NODE head = NULL;
    NODE head1=NULL;

    do {
	printf("\n-*-*-*-*-*-*-*-*-*-*-Main Menu-*-*-*-*-*-*-*-*-*-*-\n");
	printf("1.Insert front\n");
	printf("2.Insert to the left of a certain node\n");
	printf("3.Delete a specific node\n");
    printf("4.Display\n");
    printf("5.Exit\n");
	printf("---------------------------------\n");
	printf("Enter Choice:  \n");
	printf("---------------------------------\n");
	scanf("%d", &choice);

	switch (choice) {
	    case 1: printf("Enter element to push\n");
                scanf("%d",&ele1);
                head=push(head,ele1);
                break;

	    case 2: printf("Enter element before which an element should be added\n");
                scanf("%d",&val);
                head=insert_left(val,head);
                break;

	    case 3: printf("Which item is to be deleted: ");
	            scanf("%d",&item);
	            head=delete_item(item,head);
		        break;

	    case 4: disp(head);
                break;

	    case 5: exit(0);
                break;

	    default: printf("Invalid Choice \n");
	}


    } while (choice != 7);

    return 0;
}
