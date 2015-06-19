#include <iostream> 
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
// 2014 Feb, Rewrite
    string longestCommonPrefix(vector<string> &strs) {
        if (strs.empty())
            return "";
            
        for (int i=0;i<strs[0].size();i++)
            for (int j=0;j<strs.size();j++)
            {
                if(strs[0][i]!=strs[j][i])
                    return strs[0].substr(0,i);
            }
        
        return strs[0];
    }
};

int main(int argc, char ** argv) { 

    Solution mySol;

    vector<string> strs;
    strs.push_back("Hello World!");
    strs.push_back("Hello World!");
    strs.push_back("Hello World!"); 
    
    string comm = mySol.longestCommonPrefix(strs);

    cout << "Longest Common Prefix= " << comm << endl;



    return 0; 
}
