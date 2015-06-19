#include <iostream>
#include <cstring>
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

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string s) {
        TrieNode * p = root;
        for(auto c : s)
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

    // Returns if the word is in the trie.
    bool search(string key) {
        TrieNode * p = root;
        for(auto c : key)
        {
            int i = c-'a';
            if(!p->neighbors[i])
            {
                return false;    
            }
            p = p->neighbors[i];
        }
        if(p->wordend)
            return true;
        else
            return false;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode * p = root;
        for(auto c : prefix)
        {
            int i = c-'a';
            if(!p->neighbors[i])
            {
                return false;    
            }
            p = p->neighbors[i];
        }
        return true;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");

//another Trie implementation
class Trie{
public:
    static const int MAX_N = 100 * 100;// 100为主串长度
    static const int CLD_NUM = 26;
    int size;
    int trie[MAX_N][CLD_NUM];

    Trie(const char* s);
    void insert(const char* s);
    bool find(const char* s);
};

Trie::Trie(const char* s){
    memset(trie[0], -1, sizeof(trie[0]));
    size = 1;
    while(*s){
        insert(s);
        ++s;
    }
}

void Trie::insert(const char* s){
    int p = 0;
    while(*s){
        int i = *s - 'a';
        if(-1 == trie[p][i]){
            memset(trie[size], -1, sizeof(trie[size]));
            trie[p][i] = size++;
        }
        p = trie[p][i];
        ++s;
    }
}

bool Trie::find(const char* s){
    int p = 0;
    while(*s){
        int i = *s - 'a';
        if(-1 == trie[p][i])
            return false;
        p = trie[p][i];
        ++s;
    }
    return true;
}

int main(){
    Trie tree("mississippi");
    for (int i=0;i<26;i++)
        cout << char('a'+i) << "   ";
    cout << endl;
    for (int i = 0; i< 20; i++){
        for (int j=0; j<26; j++)
            cout << tree.trie[i][j] << "  ";
        cout << endl;
    }
    string patt[] = {
        "is", "sip", "hi", "sis", "mississippa"
    };
    int n = 5;
    for(int i=0; i<n; ++i)
        cout<<tree.find((char*)&patt[i][0])<<endl;
    return 0;
}
