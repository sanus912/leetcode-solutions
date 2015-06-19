#include <cmath>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

 
class Solution {
public:

    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        if (s.size()<4) return res;
        dfs(s,0,0,res,"");
        return res;
    }
    
    void dfs(string s, int pos, int np,vector<string> &res, string cur)
    {
        if (pos == s.size() && np == 4)
        {
            cur.erase(cur.end()-1);
            res.push_back(cur);
            return;
        }
        
        if (pos == s.size()||np == 4)
            return;
            
        int num=0;
        for(int i = pos ;i<pos+3;i++)
        {
            num = num*10 + int(s[i]-'0');
            if(num<256)
                dfs(s,i+1,np+1,res,cur+to_string(num)+".");
            
            if(num == 0)
                break;
        }
        
    }
        

};

int main() {
    Solution mySol;
    string st("25525010010");

    vector<string> ways = mySol.restoreIpAddresses(st);
    vector<string>::iterator it;
    cout << "We have " << ways.size() <<  " to restore IP " << st << endl;
    for( it = ways.begin(); it != ways.end(); it++) {
        cout << *it << endl;
    }

    return 0;
}
