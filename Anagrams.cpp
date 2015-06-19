#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
#include<Algorithm>
using namespace std;


class Solution {
public:

    vector<string> anagrams(vector<string> &strs) {
    
        vector<string> res;
        if( strs.empty()) return res;
        unordered_map<string, vector<string>> group;

        for(auto c : strs) {
            string key = c;
            sort( key.begin(), key.end());
            group[key].push_back(c);    
        }

        for (auto it = group.begin();it!=group.end();it++)
            if (it->second.size()>1)
                res.insert(res.end(),it->second.begin(),it->second.end());


        return res;
    }

};


int main(int argc, char ** argv) {


    vector<string> strs;

    strs.push_back("abc");
    strs.push_back("cba");
    strs.push_back("xyz");
    strs.push_back("yxz");
    strs.push_back("mpq");


    Solution mysol;

    vector<string> ans =  mysol.anagrams(strs);
    vector<string>::iterator it;

    for(it = ans.begin(); it != ans.end(); it++)
        cout << *it << "  ";
    cout << endl;



    return 0;
}
