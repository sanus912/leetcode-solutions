#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;


class TrieNode {
public:
    vector<TrieNode *> neighbors;
    bool wordend;
    // Initialize your data structure here.
    TrieNode() {
        neighbors.resize(26,NULL);
        wordend =false;
    }
};

class WordDictionary {
public:
    TrieNode* root;
    
    WordDictionary() {
        root = new TrieNode();
    }
    // Adds a word into the data structure.
    void addWord(string word) {
        TrieNode * p = root;
        for(auto c : word)
        {
            int i = c-'a';
            if(!p->neighbors[i])
            {
                p->neighbors[i] = new TrieNode();    
            }
            p = p->neighbors[i];
        }
        p->wordend = true;
    }
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;
        if(board.empty() || board[0].empty())
            return res;
        if(words.empty()) return res;
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        
        WordDictionary trie;
        for (auto w : words)
            trie.addWord(w);
            
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                search(i,j,board,trie,trie.root,visited,res,"");
        
        return res;
    }
    
    void search(int i, int j, vector<vector<char>>& board, WordDictionary &trie, TrieNode * p, vector<vector<bool>> &visited, vector<string> &res, string word)
    {
        if(p->wordend)
        {
            res.push_back(word);
            p->wordend = false;
        }
        
        if(i<0 || i>=board.size()||j<0||j>=board[0].size())
            return;
        
        if(visited[i][j]) 
            return;
        
        int k = board[i][j]-'a';
        if(!p->neighbors[k])
            return;    
       
        visited[i][j]=true;
        search(i,j+1,board,trie,p->neighbors[k],visited,res,word+board[i][j]);
        search(i,j-1,board,trie,p->neighbors[k],visited,res,word+board[i][j]);
        search(i+1,j,board,trie,p->neighbors[k],visited,res,word+board[i][j]);
        search(i-1,j,board,trie,p->neighbors[k],visited,res,word+board[i][j]);
        visited[i][j]=false;
    }
};


int main() {

    Solution mySol;
    const int m = 3;
    const int n = 4;

    vector<vector<char> > board(m, vector<char>(n));
    char array0[]={"abce"};
    char array1[]={"sfes"};
    char array2[]={"adee"};
    board[0].assign(array0, array0 + n);
    board[1].assign(array1, array1 + n);
    board[2].assign(array2, array2 + n);

    vector<vector<char> >::iterator it;
    vector<char>::iterator is;
    for(it = board.begin(); it != board.end(); it++) {
        for(is = (*it).begin(); is != (*it).end(); is++) {
            cout << *is << "  " ;
        }
        cout << endl;
    }
    cout << endl;

    vector<string> words = {"abc","sfda"};
    vector<string> res = mySol.findWords(board, words);
    for (auto s : res)
        cout << s << " ";
    cout << endl;

    return 0;
}
