#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > result;
        vector<int> array;
        for (int i = 1; i <= numRows; i++) {
            for (int j = i - 2; j > 0; j--) {
                array[j] = array[j - 1] + array[j];
            }
            array.push_back(1);
            result.push_back(array);
        }
        return result;
    }


};


int main() {

    Solution mySol;
    int nrow = 6;
    vector<vector<int> > ss = mySol.generate(nrow);

    vector<vector<int> >::iterator it;
    vector<int>::iterator is;
    int ctrl;
    for(it = ss.begin(); it != ss.end(); it++) {
        ctrl = 0;
        while ( ++ctrl < nrow )cout << "  ";
        for(is = (*it).begin(); is != (*it).end(); is++) {
            cout << *is << "   " ;
        }
        nrow --;
        cout << endl;
    }


    return 0;
}
