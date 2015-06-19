#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:

    vector<vector<int> > permute(vector<int> &num) {

        vector<vector<int> > res;
        vector<int> one;
        vector<int> visited(num.size(), 0);
        if(num.empty()) return res; 
        findPermute(num,visited, one, res);
        
        return res;

    }

    void findPermute(vector<int> num, vector<int>& visited, vector<int>& one, vector<vector<int> >& res)  
    { 
        if(one.size()==num.size()) {
            res.push_back(one);
            return;
        }
        
        for(int i=0; i<num.size(); i++) {
            if(visited[i]==0) {
                visited[i]=1;
                one.push_back(num[i]);
                findPermute(num, visited, one, res);
                one.pop_back();
                visited[i]=0;
            }
        }
    }  
    
};


int main() {

    const int s = 3;
    int myArr[s] = {1, 2, 3};
    vector<int> myv;

    myv.assign(myArr, myArr+s);
    cout << "Size of myv: " << int (myv.size()) << endl;
    sort(myv.begin(), myv.end());

    Solution mySol;
    vector<vector<int> > ss = mySol.permute(myv);

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
