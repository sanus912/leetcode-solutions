#include <iostream> 
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        unordered_map<string,int> expected;
        for (auto r : L)
            expected[r]++;
        
        int wordlength = L.front().size();
        int canlength = wordlength * L.size();
        vector<int> res;
        if (canlength > S.size()) return res;
        
        for (int i = 0;i<S.length() - canlength +1 ; i++)
        {
            unordered_map<string,int> appeared = expected;
            for (int j = i;j<i+canlength;j+=wordlength)
            {
                string cur = S.substr(j,wordlength);
                if (appeared.find(cur)==appeared.end() || appeared[cur] == 0)
                    break;
                else
                    {
                        appeared[cur]--;
                        if (appeared[cur] == 0)
                            appeared.erase(cur);
                    }
            }
            if (appeared.size()==0)
                res.push_back(i);
        
        }
        return res;
    }
};

int main(int argc, char ** argv) { 

    Solution mySol;
    string s("aaaa");
    vector<string> dict;
    
    dict.push_back("a");
    dict.push_back("a");



    vector<int> res = mySol.findSubstring(s, dict);

    for(vector<int>::iterator it = res.begin(); it!= res.end(); it++)
        cout <<  " "<< *it <<",";
    cout << endl;


    return 0; 
}
