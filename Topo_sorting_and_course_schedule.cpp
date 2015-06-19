// A C++ program to print topological sorting of a DAG
#include<iostream>
#include <list>
#include <stack>
#include <queue>
using namespace std;

/**
 * Definition for Directed graph.
 * struct DirectedGraphNode {
 *     int label;
 *     vector<DirectedGraphNode *> neighbors;
 *     DirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    //BFS
    vector<DirectedGraphNode*> topSort(vector<DirectedGraphNode*> graph) {
        int n = graph.size();
        vector<int> indeg(n,0);
        for (auto p : graph)
        {
            for(auto i : p->neighbors)
            {
                indeg[i->label]++;
            }
        }
        
        vector<DirectedGraphNode*> res;
        
        queue<DirectedGraphNode*> q;
        for (auto p : graph)
            if (indeg[p->label]==0){
                q.push(p);
                res.push_back(p);
            }
        
        while(!q.empty())
        {
            int n = q.size();
            while(n--)
            {
                DirectedGraphNode* node = q.front();
                q.pop();
                for(auto p : node->neighbors)
                {
                    indeg[p->label]--;
                    if(indeg[p->label] == 0)
                    {
                        q.push(p);
                        res.push_back(p);
                    }
                }
            }
        }
        return res;
    }

    //DFS
    vector<DirectedGraphNode*> topSort(vector<DirectedGraphNode*> graph) {
        vector<DirectedGraphNode*> res;
        int n = graph.size();
        if (n==0) return res;
        unordered_map<DirectedGraphNode*,bool> visited;
        stack<DirectedGraphNode*> stk;
        
        for(auto p : graph)
        {
            if(!visited[p])
                dfs(visited,stk,p);
        }
        
        while(!stk.empty())
        {
            res.push_back(stk.top());
            stk.pop();
        }
        return res;
    }
    
    void dfs(unordered_map<DirectedGraphNode*,bool> &visited, stack<DirectedGraphNode*> &stk, DirectedGraphNode* p)
    {
        visited[p] = true;
        for(auto i : p->neighbors)
        {
            if(!visited[i])
                dfs(visited,stk,i);
        }
        stk.push(p);
    }
};

//course_schedule
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>> neighbor(n,vector<int>());
        vector<int> indeg(n,0);
        for (int i = 0;i<prerequisites.size();i++)
        {
            indeg[prerequisites[i][0]] += prerequisites[i].size() - 1;
            for (int j = 1;j<prerequisites[i].size();j++)
            {
                neighbor[prerequisites[i][j]].push_back(prerequisites[i][0]);
            }
        }
        
        vector<int> res;
        
        queue<int> q;
        for (int i = 0;i<n;i++)
            if (indeg[i]==0){
                q.push(i);
                res.push_back(i);
            }
        
        while(!q.empty())
        {
            int n = q.size();
            while(n--)
            {
                int i = q.front();
                q.pop();
                for(auto j : neighbor[i])
                {
                    indeg[j]--;

                    if(indeg[j] == 0)
                    {
                        q.push(j);
                        res.push_back(j);
                    }
                }
            }
        }
        return res.size()==n;
    }
};

//another version
 
// Class to represent a graph
class Graph
{
    int V;    // No. of vertices'
 
    // Pointer to an array containing adjacency listsList
    list<int> *adj;
 
    // A function used by topologicalSort
    void topologicalSortUtil(int v, bool visited[], stack<int> &Stack);
public:
    Graph(int V);   // Constructor
 
     // function to add an edge to graph
    void addEdge(int v, int w);
 
    // prints a Topological Sort of the complete graph
    void topologicalSort_DFS();
    void topologicalSort_BFS();
};
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
 
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
}
 
// A recursive function used by topologicalSort
void Graph::topologicalSortUtil(int v, bool visited[], stack<int> &Stack)
{
    // Mark the current node as visited.
    visited[v] = true;
 
    // Recur for all the vertices adjacent to this vertex
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            topologicalSortUtil(*i, visited, Stack);
 
    // Push current vertex to stack which stores result
    Stack.push(v);
}
 
// The function to do Topological Sort. It uses recursive topologicalSortUtil()
void Graph::topologicalSort_DFS()
{
    stack<int> Stack;
 
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
 
    // Call the recursive helper function to store Topological Sort
    // starting from all vertices one by one
    for (int i = 0; i < V; i++)
      if (visited[i] == false)
        topologicalSortUtil(i, visited, Stack);
 
    // Print contents of stack
    while (Stack.empty() == false)
    {
        cout << Stack.top() << " ";
        Stack.pop();
    }
}

void Graph::topologicalSort_BFS()
{
    vector<int> indeg(V,0);
    for (int i=0;i<V;i++)
    {
        for (int r : adj[i])
            indeg[r]++;
    }
 
     
    queue<int> q;
    for (int i = 0; i < V; i++)
      if (indeg[i]==0)
          q.push(i);

    while(!q.empty())
    {
        int n = q.size();
        while(n>0)
        {
            int t = q.front();
            cout << t << " ";
            q.pop();
            for (int r : adj[t])
            {
                indeg[r]--;
                if (indeg[r] == 0)
                    q.push(r);
            }
            n--;
        }
    }

}

// Driver program to test above functions
int main()
{
    // Create a graph given in the above diagram
    Graph g(6);
    g.addEdge(1, 0);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(0, 4);
    g.addEdge(2, 4);
    g.addEdge(3, 5);

    cout << "Following is a Topological Sort of the given graph \n";
    g.topologicalSort_BFS();

    return 0;
}
