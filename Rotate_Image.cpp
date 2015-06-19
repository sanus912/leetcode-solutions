#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        
        if(matrix.empty() || matrix[0].empty()) return;
        const int n = matrix.size();

        for(int i = 0; i <= n-2; i ++) 
            for(int j = 0; j <= n - 2 - i; j++) 
                swap(matrix[i][j], matrix[n-1-j][n-1-i]);
                
        for(int i = 0; i < n / 2; i ++) 
            for(int j = 0; j < n; j++) 
                swap(matrix[i][j], matrix[n-1-i][j]);
    }

};

int main() {

    Solution mySol;
    const int d= 9;

    vector<vector<int> > matrix(d, vector<int>(d));

    for(int i = 0; i < d; i++)
        for(int j = 0; j < d; j++)
            matrix[i][j] = 10 * (i+1) +(j+1);

    vector<vector<int> >::iterator it;
    vector<int>::iterator is;
    for(it = matrix.begin(); it != matrix.end(); it++) {
        for(is = (*it).begin(); is != (*it).end(); is++) {
            cout << *is << "  " ;
        }
        cout << endl;
    }
    cout << endl;

    mySol.rotate(matrix);

    for(it = matrix.begin(); it != matrix.end(); it++) {
        for(is = (*it).begin(); is != (*it).end(); is++) {
            cout << *is << "  " ;
        }
        cout << endl;
    }



    return 0;
}
