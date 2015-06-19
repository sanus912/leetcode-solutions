#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;


class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        
        const int n = num.size();
        if(n < 2) return n;

        unordered_map<int, bool> used;
        for(int i = 0; i < n; i++) used[num[i]] = false;
        
        int result = 0;

        for(auto i : num) {
            if(used[i]) 
                continue;
            used[i]= true;
            int length = 1;

            for (int j=i+1;used.find(j)!=used.end();j++)
            {
                used[j]=true;
                length++;
            }
            for (int j=i-1;used.find(j)!=used.end();j--)
            {
                used[j]=true;
                length++;
            }

            result = max(length,result);
        }
        
        return result;
    }

};

int main() {

    Solution mySol;
    const int s = 6;
    int myarr[s] = {100, 4, 200, 1, 3, 2};
    vector<int> num(myarr, myarr + s);

    
    int has;
    has = mySol.longestConsecutive(num);
    cout << "Longest Consecutive Sequence is " << has << endl;





    return 0;
}
