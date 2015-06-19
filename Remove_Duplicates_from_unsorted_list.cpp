#include <iostream>
#include <unordered_set>//hash table
#include <cstdlib>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:

    /*
     * method 1: with buffer
     * O(n) time, O(n) space
     */
    void rm_duplicates_buff_func(ListNode *head) {

        if (head==NULL)
            return;
        std::unordered_set<int> buffer;
        buffer.insert(head->val);
        ListNode *p=head, *q=head->next;
        while(q){
            if(buffer.find(q->val)!=buffer.end()){
                p->next = q->next;
                delete q;
                q = p->next;
            }
            else{
                buffer.insert(q->val);
                p = q; q = q->next;
            }
        }

    }

    /*
     * method 2: without buffer
     * O(n^2) time, O(1) space
     */
    void rm_duplicates_no_buffer_func(ListNode *head) {

        if(head==NULL) return;
        ListNode *p, *q, *c=head;
        while(c){
            p=c; q=c->next;
            int d = c->val;
            while(q){
                if(q->val==d){
                    p->next = q->next;
                    delete q;
                    q = p->next;
                }
                else{
                    p = q; q = q->next;
                }
            }
            c = c->next;
        }

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

    int n = 10;
    int myArr[] = {3, 2, 1, 3, 5, 6, 2, 6, 3, 1};

    Solution mySol;

    // make & construct our linked list
    ListNode * mylist = arraytolist(myArr,n);

    printlist(mylist);

    mySol.rm_duplicates_buff_func(mylist);

    printlist(mylist);

    return 0;
}
