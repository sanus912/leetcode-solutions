#include <iostream>
#include <unordered_map>
using namespace std;


 
struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x=0) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:

    //next pointer
    RandomListNode *copyRandomList(RandomListNode *head) {

        if(!head) return NULL;
        for (RandomListNode * cur = head; cur;)
        {
        RandomListNode *node = new RandomListNode(cur->label);
        node->next = cur->next;
        cur->next = node;
        cur = node->next;
        }

        for (RandomListNode * cur = head; cur;){
            if (cur->random)
                cur->next->random = cur->random->next;
            cur = cur->next->next;
        }

        RandomListNode * dummy = new RandomListNode(-1);
        RandomListNode * p = dummy;
        for (RandomListNode * cur = head; cur;)
        {
            p->next = cur->next;
            p = p->next;
            cur->next = cur->next-next;
            cur = cur->next;
        }
                
        return dummy->next;
    }

    //hash
    RandomListNode *copyRandomList_2(RandomListNode *head) {

        if(!head) return NULL;
        unordered_map<RandomListNode *,RandomListNode *> hs;
        RandomListNode * p =head;
        RandomListNode * pre = new RandomListNode(-1);
        while(p)
        {
            hs[p] = new RandomListNode(p->label);
            pre->next = hs[p];
            pre = pre->next;
            p = p->next;
        }

        p=head;
        while(p)
        {
            if (p->random)
                hs[p]->random = hs[p->random];

            p = p->next;
        }

        return hs[head];
    }
};

RandomListNode * arraytolist(int A[], int n)
{
    if (n<=0) return NULL;

    RandomListNode * head = new RandomListNode(A[0]);
    RandomListNode * p = head;

    for (int i =1;i<n;i++)
    {
        RandomListNode * node = new RandomListNode(A[i]);
        p->next = node;
        p = p->next;
    }
    return head;
}

void printlist(RandomListNode *head)
{
    while(head)
    {
        cout << head->label << " ";	
        head = head->next;
    }
    cout << endl;
}

int main() {

    int arr[] = {4, 2, 3, 1, 6, 7, 5, 0};
    Solution mySol;

    RandomListNode * mylist = arraytolist(arr,8);

    RandomListNode * rlist = mySol.copyRandomList(mylist);
    printlist(rlist);


    return 0;
}
