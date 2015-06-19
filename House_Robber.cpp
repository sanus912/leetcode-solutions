#include <iostream>
#include <vector>
using namespace std;

int rob(vector<int> &num) {
        int n = num.size();
        if (n == 0)
            return 0;
        vector<int> f(n+1,0);
        f[1] = num[0];
        for (int i = 2; i<=n;i++){
            f[i] = max(num[i-1] + f[i-2], f[i-1]);
        }
        return f[n];
    }

int main() {

    vector<int> v = {2,1,1,2};
    cout << rob(v) << endl;
    return 0;

}

