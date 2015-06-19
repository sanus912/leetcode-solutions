#include<iostream>  
#include<algorithm>  
#include<functional>  
#include<set>  
#include <queue>
using namespace std;  
  
typedef greater<int> Greater;//最大堆  
typedef less<int> Less;//最小堆  
typedef multiset<int,Greater> MaxHeap;  
typedef multiset<int,Less> MinHeap;  
  
  
int main()  
{  
    int arr[]={0,1,2,3,4,8,9,3,5};  
  
    MaxHeap heap;  
    for(int i=0;i<9;i++){  
        heap.insert(arr[i]);  
    }  
    for(auto it = heap.begin();it!=heap.end();++it){  
        cout<<*it<<" ";  
    }  
    cout<<endl;  
  
    heap.erase(heap.begin());  
    heap.insert(10);  
    for(auto it = heap.begin();it!=heap.end();++it){  
        cout<<*it<<" ";  
    }  

    cout << endl;

    //minheap
    priority_queue<int, vector<int>, greater<int> > ipq(arr,arr+9);
    cout<<"size="<<ipq.size()<<endl;  
    while(!ipq.empty()){  
    cout<<ipq.top()<<" ";  
    ipq.pop();  
    }   
    cout << endl;

    //maxheap
    priority_queue<int, vector<int>, less<int> > ipq2(arr,arr+9);
    cout<<"size="<<ipq2.size()<<endl;  
    while(!ipq2.empty()){  
    cout<<ipq2.top()<<" ";  
    ipq2.pop();  
    }

    return 0;  
} 


