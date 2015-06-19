#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>
#include <unordered_map>
using namespace std;

class Solution {
public:
    //hash map
    bool ifallunique(string s) {
        if (s.size()<=1) return true;
        unordered_map<char,bool> hs; 
        for (auto c : s)
            if(hs.find(c)!=hs.end())
                return false;
            else
                hs[c] = true;

        return true;
    }

    //bit shift --- only for ASCII chars [256]
    bool ifallunique_bit(string s) {
        if (s.size()<=1) return true;
        int hs[8];
        for (auto c : s)
        {
            int v = int(c);
            int idx = v/32;
            int shift = v%32;
            if(hs[idx] & 1<<shift)
                return false;
            else
                hs[idx] |= (1<<shift);
        }
        return true;
    }

    //sort
    bool ifallunique_3(string s) {
        if (s.size()<=1) return true;
        sort(s.begin(),s.end()); 
        for (auto it = s.begin()+1; it!=s.end(); it++)
            if(*it == *(it-1))
                return false;
        return true;
    }

    //no additional data structure
    bool ifallunique_4(string s) {
        if (s.size()<=1) return true;
        for (int i = 1; i < s.size();i++)
            for (int j = 0; j < i; j++)
                if(s[i]==s[j])
                    return false;
        return true;
    }
};

int main() {

    string s = "aab";

    Solution mySol;

    cout << mySol.ifallunique(s) << endl;
    cout << mySol.ifallunique_bit(s) << endl;
    cout << mySol.ifallunique_3(s) << endl;
    cout << mySol.ifallunique_4(s) << endl;


    return 0;
}
