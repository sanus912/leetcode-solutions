#include <iostream>
using namespace std;

/*	
 *	Given a linked list and a value x, partition it such that all 
 *	nodes less than x come before nodes greater than or equal to x.
 *
 *	You should preserve the original relative order of the nodes in each of the two partitions.
 *	
 *	For example,
 *	Given 1->4->3->2->5->2 and x = 3,
 *	return 1->2->2->4->3->5.
 *
 */



struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x=0) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode *partition(ListNode *head, int x) {

        if( !head) return NULL;
        ListNode * before = new ListNode(-1);
        ListNode * after = new ListNode(-1);
        ListNode *p = before, *q = after;

        while (head) {
            if(head -> val < x) {
                p -> next = head;
                p = p -> next;
            }
            else {
                q -> next = head;
                q = q -> next;
            }
            head = head -> next;
        }
        q -> next = NULL;
        p -> next = after->next;

        return before->next;
    }

    
};

ListNode * arraytolist(int A[], int n)
{
    if (n<=0) return NULL;

    ListNode * head = new ListNode(A[0]);
    ListNode * p = head;

    for (int i =1;i<n;i++)
    {
        ListNode * node = new ListNode(A[i]);
        p->next = node;
        p = p->next;
    }
    return head;
}

void printlist(ListNode *head)
{
    while(head)
    {
        cout << head->val << " ";	
        head = head->next;
    }
    cout << endl;
}


int main() {

    int myArr[] = {1, 4, 3, 2, 5, 2};
    Solution mySol;

    // make & construct our linked list
    ListNode * mylist = arraytolist(myArr,6);

    printlist(mylist);

    ListNode * rlist = mySol.partition(mylist, 3);

    printlist(rlist);

    return 0;
}
