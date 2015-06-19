#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:

    vector<vector<int> > permuteUnique(vector<int> &num) {

        vector<vector<int> > res;
        vector<int> one;
        vector<int> visited(num.size(), 0);
        if(num.empty()) 
            return res; 

        sort(num.begin(),num.end());
        findPermute(num,visited, one, res);
        
        return res;

    }

    void findPermute(vector<int> &num, vector<int>& visited, vector<int>& one, vector<vector<int> >& res)  
    { 
        if(one.size()==num.size()) {
            res.push_back(one);
            return;
        }
        
        for(int i=0; i<num.size(); i++) {
            
            if (i>0 && num[i]==num[i-1] && !visited[i-1])
                continue;
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

    const int s = 4;
    int myArr[s] = {1, 1, 2, 2};
    vector<int> myv;

    myv.assign(myArr, myArr+s);
    cout << "Size of myv: " << int (myv.size()) << endl;
    sort(myv.begin(), myv.end());

    Solution mySol;
    vector<vector<int> > ss = mySol.permuteUnique(myv);

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
