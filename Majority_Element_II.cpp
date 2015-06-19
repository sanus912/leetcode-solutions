#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    int majorityNumber(vector<int> nums) {
        int a,b;
        int ca=0,cb=0;
        for (int i : nums)
        {
            if (ca!=0 && a == i)
            {
                ca++;
            }
            else if (cb != 0 && b == i)
            {
                cb++;
            }
            else if (ca == 0)
            {
                a = i; ca++;
            }
            else if (cb == 0)
            {
                b = i; cb++;
            }
            else
            {
                ca--;
                cb--;
            }
        }
        
        ca = 0;
        cb = 0;
        for (int i : nums)
        {
            if (i == a)
            ca++;
            else if (i == b)
            cb++;
            
        }
        return ca > cb? a:b;
        
    }
};


int main() {

    Solution mySol;
    vector<int> v = {1, 2, 2, 2, 3, 5, 6, 6};


    for(int i = 0; i < v.size(); i++) {
        cout  << v[i] << "  ";
    }
    cout << endl;

    cout << mySol.majorityNumber(v) << endl;





    return 0;
}
