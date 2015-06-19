#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
   vector<int> grayCode(int n) {
        if (n==0)
        return {0};
 
        vector<int> res = grayCode(n-1);
        int m = res.size();
        for (int i=m-1; i>=0;i--)
            res.push_back(res[i]+pow(2,n-1));
        
        return res;
    } 
};


int main() {

    Solution mySol;
    vector<int> myvec = mySol.grayCode(3);

    for (auto a: myvec)
        cout <<a << " ";
    cout << endl;
    return 0;
}
