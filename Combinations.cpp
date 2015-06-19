#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:

    vector<vector<int> > combine(int n, int k) {

        vector<vector<int> > res;
        vector<int> one;

        if(n<k || n<1 || k<1)return res; 
        comb(n, k, 1,  one, res);
        return res;
    }

    void comb(int n, int k, int pos, vector<int> &one, vector<vector<int> > &res) {

        if(one.size()==k) {
            res.push_back(one);
            return;
        }

        for(int i = pos; i <=n; i++) {
            one.push_back(i);
            comb(n, k, i + 1, one, res);
            one.pop_back();
        }

    }
};


int main() {

    const int s = 4;
    int myArr[s] = {1, 2, 3, 4};
    vector<int> myv;

    myv.assign(myArr, myArr+s);
    cout << "Size of myv: " << int (myv.size()) << endl;
    sort(myv.begin(), myv.end());

    Solution mySol;
    vector<vector<int> > ss = mySol.combine(s, 2);

    vector<vector<int> >::iterator it;
    vector<int>::iterator is;
    for(it = ss.begin(); it != ss.end(); it++) {
        for(is = (*it).begin(); is != (*it).end(); is++) {
            cout << *is << "  " ;
        }
        cout << endl;
    }


    return 0;
}
