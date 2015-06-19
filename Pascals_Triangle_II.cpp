#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if (rowIndex < 0 ) return vector<int>();
        vector<int> array;
        for (int i = 0; i <= rowIndex; i++) {
            for (int j = i - 1; j > 0; j--) {
                array[j] = array[j - 1] + array[j];
            }
            array.push_back(1);
        }
        return array;
    }
};


int main() {

    Solution mySol;
    int nrow = 2;
    vector<int> ss = mySol.getRow(nrow);
    vector<int>::iterator is;
    int ctrl=0;
    while ( ++ctrl < nrow )cout << "  ";
    for(is = ss.begin(); is != ss.end(); is++) {
        cout << *is << "   " ;
    }
    cout << endl;


    return 0;
}
