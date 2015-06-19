#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<int, int> map;
        hash<string> hash_fn;
        vector<string> v;

        for(int i = 0 ; i + 9 < s.size(); i++)
        {
            string t = s.substr(i, 10);
            int h = hash_fn(t);

            if(map.find(h) == map.end())
            {
                map[h] = 1;
            }
            else
            {
                if (map[h] == 1)
                {
                    v.insert (v.end(), t);
                }

                map[h]++;
            }
        }

        return v;
    }

};

int main() {

    string s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";

    Solution mySol;

    vector<string> res = mySol.findRepeatedDnaSequences(s);
    for (auto a : res)
        cout << a << " ";
    cout << endl;


    return 0;
}
