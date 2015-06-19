#include <iostream> 
#include <unordered_set>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:

    bool wordBreak(string s, unordered_set<string> &dict, int maxl) {
        vector<bool> f(s.size()+1,false);
        f[0]=true;
        for (int i=1;i<=s.size();i++)
            for (int j=i-1;j>=max(i-maxl,0);j--)
            {
                if (f[j] && dict.find(s.substr(j,i-j))!=dict.end())
                {   
                    f[i]=true;
                    break;
                }
            }
        return f[s.size()];
    }
        
};

int main(int argc, char ** argv) { 

    Solution mySol;
    string s("aaaaaaa");
    unordered_set<string> dict;
    
    dict.insert("apple");
    dict.insert("leet");
    dict.insert("code");
    dict.insert("aaaa");
    dict.insert("aaa");

    int maxl = 0;
    for (auto s: dict)
        if (s.size()>maxl)
            maxl = s.size();

    cout <<  " it is "<< mySol.wordBreak(s, dict, maxl) << endl;


    return 0; 
}
