#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
using namespace std;

class Solution {
public:

    string largestNumber(vector<int> &num) {
        sort(num.begin(), num.end(), [](int a, int b){
            return to_string(a)+to_string(b) > to_string(b)+to_string(a);
        });
        string ans;
        for(int i=0; i<num.size(); i++){
            ans += to_string(num[i]);
        }
        return ans[0]=='0' ? "0" : ans;
        
    }
};


int main() {

    Solution mySol;
    vector<int> v = {1,2,3,4,5,6,7,8,9,0};


    cout << mySol.largestNumber(v) << endl;





    return 0;
}
