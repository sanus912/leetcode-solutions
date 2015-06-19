#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <stack>
using namespace std;

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x=0) : label(x) {};
};

class Solution {
public:
    //DFS
    UndirectedGraphNode *cloneGraph(const UndirectedGraphNode *node) {
        if(!node) return NULL;
        unordered_map<const UndirectedGraphNode*, UndirectedGraphNode*> m;
        clone(node,m);
        return m[node];
    }
    
    static UndirectedGraphNode *clone(const UndirectedGraphNode *node, unordered_map<const UndirectedGraphNode*, UndirectedGraphNode*> &m)
    {
        if (m.find(node)!=m.end())
            return m[node];
        
        m[node] = new UndirectedGraphNode(node->label);
        for (auto a: node->neighbors)
            m[node]->neighbors.push_back(clone(a,m));
            
        return m[node];
    }

    //BFS
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {

        if (!node) return NULL;
        //同时表示visited
        unordered_map<UndirectedGraphNode *,UndirectedGraphNode *> hs;
        hs[node] = new UndirectedGraphNode(node->label);
        queue<UndirectedGraphNode *> q;
        q.push(node);
        while(!q.empty())
        {
            int n = q.size();
            while(n--)
            {
                UndirectedGraphNode * p = q.front();
                q.pop();
                for (auto nb : p->neighbors)
                {
                    if (hs.find(nb)==hs.end()){
                        hs[nb] = new UndirectedGraphNode(nb->label);
                        q.push(nb);
                    }
                    hs[p]->neighbors.push_back(hs[nb]);
                }
            }
        }
        return hs[node];
        
    }
};

int main() {

    Solution mySol;
    
    UndirectedGraphNode *root = new UndirectedGraphNode(0);

    for(int i = 1; i <= 3; i++) {
        UndirectedGraphNode *tmp = new UndirectedGraphNode(i);
        root->neighbors.push_back(tmp);
    }

    UndirectedGraphNode *cp = mySol.cloneGraph(root);
    for(int i = 0;i<cp->neighbors.size(); i++) {
        cout << cp->neighbors[i]->label << " ";
    }
    cout << endl;



    return 0;
}
