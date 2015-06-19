#include <iostream>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(NULL) {}
     ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    //reverse order
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {

        if (!l1)
            return l2;
        if (!l2)
            return l1;

        int sum = 0;
        int carry = 0;

        ListNode * dummy = new ListNode(-1);
        ListNode * p = dummy;

        while(l1 || l2) {
            sum = carry;

            if (l1)
            {
                sum += l1->val;
                l1 = l1->next;
            }

            if (l2)
            {
                sum += l2->val;
                l2 = l2->next;
            }

            carry = sum/10;
            sum = sum%10;

            p->next = new ListNode(sum);
            p = p->next;
        }


        if(carry) {
            p->next = new ListNode(carry);
        }

        return dummy->next;
    }

    //FOLLOW UP: forward order
    ListNode * addTwoNumbers_for(ListNode *l1, ListNode *l2) 
    {
        if (!l1)
            return l2;
        if (!l2)
            return l1;

        int len1 = len(l1);
        int len2 = len(l2);
        if (len1<len2)
            l1 = padlist(l1,len2-len1);
        else
            l2 = padlist(l2,len1-len2);

        printlist(l1);
        printlist(l2);

        int carry = 0;

        ListNode * result = helper(l1,l2,carry);

        if (carry)
        {
            ListNode * node = new ListNode(carry);
            node->next = result;
            result = node;
        }

        return result;

    }

    ListNode * helper(ListNode *  pa, ListNode *  pb, int &carry) 
    {
        if (!pa&&!pb)
        {
            return NULL;
        }

        ListNode * nd = helper(pa->next,pb->next,carry);

        int val = pa->val + pb->val + carry;
        ListNode * node = new ListNode(val%10);
        node->next = nd;
        carry = val/10;
        return node;
    }

    int len(ListNode *l)
    {
        int i = 0;
        while(l)
        {
            i++;
            l = l->next;
        }
        return i;
    }

    ListNode * padlist(ListNode * head, int n)
    {
        for (int i=0;i<n;i++){
            ListNode * node = new ListNode(0);
            node->next = head;
            head = node;
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






int main() {

    int myArr1[] = {9, 9};
    int myArr2[] = {1};
    Solution mySol;

    // make & construct our linked list

    ListNode * mylist1 = arraytolist(myArr1,2);
    ListNode * mylist2 = arraytolist(myArr2,1);

    ListNode * rlist = mySol.addTwoNumbers(mylist1, mylist2);
    mySol.printlist(rlist);

    rlist = mySol.addTwoNumbers_for(mylist1, mylist2);
    mySol.printlist(rlist);


    return 0;
}
