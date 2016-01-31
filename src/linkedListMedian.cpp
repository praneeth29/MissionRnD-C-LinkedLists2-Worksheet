/*
OVERVIEW: Given a single sorted linked list find the median element of the single linked list.
Median is the middle element.
E.g.: 1->2->3->4->5, output is 3.

INPUTS: A sorted linked list.

OUTPUT: Return median of the linked list elements.

ERROR CASES: Return -1 for error cases.

NOTES: If length is even, return average of middle pair of numbers.
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

int linkedListMedian(struct node *head) {
	if(head==NULL)
        return -1;
    else
    {
        struct node *temp;
        struct node *median;
        temp=head;
        median=head;
        if(head->next!=NULL)
        {
            while((temp->next)!=NULL && (temp->next->next)!=NULL)
            {
                temp=temp->next->next;
                median=median->next;
            }

            if (temp->next==NULL)
                return median->num;
            else
            {
                return (median->num+median->next->num)/2.0;
            }
        }
        else
            return head->num;

    }
}
