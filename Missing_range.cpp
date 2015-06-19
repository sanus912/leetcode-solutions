#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Solution {
public:

    vector<string> findMissingRanges(int A[], int n, int lower, int upper) {
        vector<string> res;
        if (n==0)
        {
            if (lower == upper)
                res.push_back(to_string(lower));
            else if (lower < upper)
                res.push_back(to_string(lower) + "->" + to_string(upper));
            return res;
        }

        if(lower==A[0]-1)
            res.push_back(to_string(lower));
        else if (lower<A[0]-1)
            res.push_back(to_string(lower) + "->" + to_string(A[0]-1));
        for (int i=1;i<n;i++)
        {
            if (A[i-1]+1 == A[i]-1)
            res.push_back(to_string(A[i-1]+1));
            else if (A[i-1]+1 < A[i]-1)
            res.push_back(to_string(A[i-1]+1) + "->" + to_string(A[i]-1) );
        }
        if (A[n-1]+1 == upper)
            res.push_back(to_string(upper));
        else if (A[n-1]+1 < upper)
            res.push_back(to_string(A[n-1]+1) + "->" + to_string(upper) );
        
        return res;
    }
        
};


int main() {

    const int s = 5;
    int Arr[s] = {0, 1, 3, 50, 75};

    Solution mySol;

    vector<string> res = mySol.findMissingRanges(Arr, s,0,100);
    for (auto s: res)
        cout << s << endl;

    return 0;
}
