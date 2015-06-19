#include <iostream> 
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int wordBreak(string s, unordered_set<string> &dict) 
    {
        vector<vector<bool>> prev(s.length()+1,vector<bool>(s.length()));
        for (int i=1;i<=s.size();i++)
            for (int j=i-1;j>=0;j--)
            {
                if (dict.find(s.substr(j,i-j))!=dict.end())
                {   
                    prev[i][j] = true;//[j,i) is found in dict.
                }
            } 

        int mininv = INT_MAX;
        dfs(s,prev,0,0,mininv);
        return mininv;

    }

    void dfs(string &s, vector<vector<bool>> & prev, int cur, int inv, int & mininv)
    {
        if (cur == s.size())
        {
            mininv = min(mininv,inv);
            return;
        }
        for (int i=cur+1;i<=s.size();i++)
        {
            int more_inv = 0;
            if (!prev[i][cur])
                more_inv = i-cur;

            //cout << cur << " " << i << " " << inv + more_inv << " " << mininv << endl; 
            //getchar();
            dfs(s,prev,i,inv + more_inv,mininv);
        }
    }
};

int main(int argc, char ** argv) { 

    Solution mySol;
    string s = "thit";
    unordered_set<string> dict;
    
    dict.insert("hit");
    dict.insert("i");

    int res = mySol.wordBreak(s, dict);
    cout << res << endl;

    return 0; 
}
