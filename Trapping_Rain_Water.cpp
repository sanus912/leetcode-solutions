#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

class Solution {
public:

    int trap(int A[], int n) {
        
        vector<int> l(n, 0);
        vector<int> r(n, 0);
        int res = 0;
        
        l[0] = A[0];
        for(int i = 1; i < n-1; i++) {
            l[i] = max(l[i-1],A[i-1]);
        }
        
        r[n-1] = A[n-1];
        for(int i = n-2; i > 0; i--) {
            r[i] = max(r[i+1],A[i+1]);
        }
        
        for(int i = 1; i < n-1;i++) {
            res += max(min(l[i], r[i]) - A[i],0);   
        }
        
        return res;
    }

    int trap(vector<int>& A) {
        int n = A.size();
        stack<int> s;
        int water = 0;
        for (int i=0;i<n;i++)
        {
            if (s.empty() || A[i]<A[s.top()])
            {
                s.push(i);
                continue;
            }

            int bottom = A[s.top()];
            s.pop();
            while(!s.empty())
            {
                int t = s.top();
                water += (min(A[t],A[i])-bottom)*(i-t-1);
                if (A[i] < A[t])
                    break;
                bottom = A[t];
                s.pop();
            }
            s.push(i);
        }
        return water;
    }

};



int main() {

    Solution mySol;
    const int s = 12;
    int A[s] = {0,1,0,2,1,0,1,3,2,1,2,1};
    vector<int> myVec(A, A+s);

    int ans = mySol.trap_stk(A, s);

    cout << "Trapping Rain Water Answer : "<< ans << endl;


    return 0;
}
