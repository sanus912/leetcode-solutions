#include <iostream>
#include <cstring>
#include <vector>
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
    TrieNode* root;
public:
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

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return dfs(word,0,root);
    }
    
    bool dfs(string word, int pos, TrieNode * p)
    {
        if (pos==word.size())
        {
            if(p->wordend)
                return true;
            else
                return false;
        }
        
        if (word[pos]!='.')
        {
            int i = word[pos]-'a';
            if(!p->neighbors[i])
                return false;    
            else
                return dfs(word,pos+1,p->neighbors[i]);
        }
        else
        {
            bool flag = false;
            for(int i=0; i<26;i++) 
            {
                if(p->neighbors[i])
                   flag = flag ||  dfs(word,pos+1,p->neighbors[i]);
            }
            return flag;
        }
    }
};

int main(){
    WordDictionary wordDictionary;
    wordDictionary.addWord("at");
    wordDictionary.addWord("and");
    wordDictionary.addWord("an");
    wordDictionary.addWord("add");
    cout << wordDictionary.search("a") << endl;;
    cout << wordDictionary.search(".at") << endl;;
    wordDictionary.addWord("bat");
    cout << wordDictionary.search(".at") << endl;;
    return 0;
}
