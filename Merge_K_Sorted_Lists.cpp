#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(NULL) {}
     ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    //priority_queue, minHeap O(nklogk) time, O(k) space
    struct comparator
    {
        bool operator() ( ListNode* i, ListNode* j)
         {
            return i->val > j->val;
         }
    };

    ListNode *mergeKLists(vector<ListNode *> &lists) 
    {

       // shortcut for edge cases. 
       if (lists.size() == 0) return NULL;
       if (lists.size() == 1) return lists[0]; 

       // initialize the maxHeap. 
       priority_queue<ListNode*, std::vector<ListNode*>, comparator> minHeap;

       // push the head of each of the items in list. 
       for (int i = 0; i< lists.size(); i++)
       {
           if (lists[i]!= NULL) minHeap.push(lists[i]);
       }

       // shortcut if we failed to find even one valid list. 
       if (minHeap.size() == 0) return NULL;

       // build the empty node as the return pointer.
       ListNode returnVal = ListNode(-1), *tmp = &returnVal; 

       // loop until the heap is empty. 
       while (minHeap.size() >0)
       {
           tmp->next = minHeap.top();
           minHeap.pop();
           tmp = tmp->next;
           if (tmp->next != NULL && minHeap.size()!=0)
           {
               minHeap.push(tmp->next);
           }
       }

       return returnVal.next;
    }

    /*  idea of merge-sort! O(nklogk) time, O(1) space
     */
    ListNode *mergeKLists_2(vector<ListNode *> &lists) {
        return merge(begin(lists), end(lists));
    }
    
    ListNode *merge(vector<ListNode*>::iterator b, vector<ListNode*>::iterator e){
        if(b==e)    return nullptr;
        if(b+1==e)  return *b;
        auto m=b+(e-b)/2;
        return mergeList(merge(b, m), merge(m,e));
    }

    ListNode *mergeList(ListNode *l1, ListNode *l2) {
        if (l1 == nullptr) return l2;
        if (l2 == nullptr) return l1;
        ListNode dummy(-1);
        ListNode *p = &dummy;
        for (; l1 != nullptr && l2 != nullptr; p = p->next) {
            if (l1->val > l2->val) { p->next = l2; l2 = l2->next; }
            else { p->next = l1; l1 = l1->next; }
        }
        p->next = l1 != nullptr ? l1 : l2;
        return dummy.next;

    }


    ListNode *mergeKLists_3(vector<ListNode *> &lists) 
    {
        int size = lists.size();
        if (0 == size)  return NULL;

        for (int i = 1; i < size; i = i + i)
            for (int j = i; j < size; j += 2*i)
                //merge two lists to one
                lists[j - i] = mergeList(lists[j - i], lists[j]);

        return lists[0];
    }

};


int main() {

    const int s1 = 8;
    const int s2 = 8;
    int arr1[s1] = {1, 2, 5, 6, 7, 9, 9, 9};
    int arr2[s2] = {3, 4, 5, 6, 7, 8, 8, 8};
    ListNode * mylist1;
    ListNode * mylist2;

    Solution mySol;

    // make & construct our linked list
    mylist1 = new ListNode(arr1[0]);
    mylist2 = new ListNode(arr2[0]);


    ListNode * p1 = mylist1;
    cout  << p1->val << "  ";
    for(int i = 1; i < s1; i++) {
        ListNode * node = new ListNode(arr1[i]);
        p1->next = node;
        p1 = p1->next;
        cout  << p1->val << "  ";
    }
    cout << endl;

    ListNode * p2 = mylist2;
    cout  << p2->val << "  ";
    for(int i = 1; i < s2; i++) {
        ListNode * node = new ListNode(arr2[i]);
        p2->next = node;
        p2 = p2->next;
        cout  << p2->val << "  ";
    }
    cout << endl;

    vector<ListNode*> lv;
    lv.push_back(mylist1);
    lv.push_back(mylist2);
    ListNode * rlist = mySol.mergeKLists(lv);

    while(rlist) {
        cout  << rlist->val << "  ";
        rlist = rlist->next;
    }
    cout << endl;


    return 0;
}
