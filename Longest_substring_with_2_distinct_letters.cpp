#include <iostream>
#include <cstring>
#include <unordered_map>
using namespace std;

int lengthOfLongestSubstringTwoDistinct(string s) {
        int n = s.size();
        if (n <= 2) return n;
        unordered_map<char, int> hs;
        int res = 2;
        int start = 0;
        for (int i = 0;i<n;i++)
        {
            if (hs.size()==2 && hs.find(s[i])==hs.end())
            {
                res = max(res,i-start);
                int min = i;
                char c;
                for (auto p : hs)
                {
                    if (p.second < min)
                    {
                        min = p.second;
                        c = p.first;
                    }
                }
                hs.erase(c);
                start = min+1;
            }
            hs[s[i]] = i;
        }
        res = max(res,n-start);
        return res;
    }

int main() 
{
	char s[] = { "ccccabdddd" };

	cout << s << " ---> " << lengthOfLongestSubstringTwoDistinct(s) << endl;

    return 0;

}

