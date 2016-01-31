/*
OVERVIEW: Merge two sorted linked lists.
E.g.: 1->3->5 and 2->4, output is 1->2->3->4->5.

INPUTS: Two sorted linked lists.

OUTPUT: Return merged sorted linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

struct node * merge2LinkedLists(struct node *p, struct node *q) {
	if(p==NULL && q==NULL)
	return NULL;
	else
    {
        struct node *start,*temp;
        if(p==NULL)
            return q;
        else if(q==NULL)
            return p;
        else
        {
            if(p->num<q->num)
            {
                start=p;
                p=p->next;
            }
            else
            {
                start=q;
                q=q->next;
            }

            temp=start;
            while(p!=NULL&&q!=NULL)
            {
                if((q->num)>(p->num))
                {
                    temp->next=p;
                    temp=temp->next;
                    p=p->next;
                }
                else
                {
                    temp->next=q;
                    temp=temp->next;
                    q=q->next;
                }

            }
            if(p==NULL && q!=NULL)
                temp->next=q;
            else if(p!=NULL && q==NULL)
                temp->next=p;
            temp=start;
            return start;
        }
    }
}
