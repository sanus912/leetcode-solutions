#include <iostream> 
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:

    string minWindow(string S, string T) {
        unordered_map<char,int> expected;
        for (auto r : T)
            expected[r]++;
        unordered_map<char,int> appeared(expected);
        
        for (auto &p : appeared)
            p.second = 0;

        int t = 0;
        
        int minwin = INT_MAX;
        int minb = 0;
        int b = 0;
        for (int e = 0; e < S.size(); e++)
        {
            if (expected.find(S[e])!=expected.end())
            {
                appeared[S[e]]++;
                if (appeared[S[e]] <= expected[S[e]])
                    t++;

                if (t == T.size())
                {
                    while (expected.find(S[b])==expected.end() || appeared[S[b]] > expected[S[b]])
                    {
                        if (expected.find(S[b])!=expected.end())
                            appeared[S[b]]--;
                        b++;
                    }
                    if (minwin > e-b+1)
                    {
                        minwin = e-b+1;
                        minb = b;
                    }
                }
            }
        }
        if (minwin == INT_MAX)
            return "";
        else
            return S.substr(minb,minwin);
    }

};

int main(int argc, char ** argv) { 

    Solution mySol;

    char cs1[] = "aasfalasdjfals";
    char cs2[] = "adf"; 

    string s1(cs1);
    string s2(cs2);

    string mw = mySol.minWindow(s1, s2);

    cout << cs1 << "'s minWindow enclosing " << cs2 << " is "<<  mw <<endl;


    return 0; 
}
