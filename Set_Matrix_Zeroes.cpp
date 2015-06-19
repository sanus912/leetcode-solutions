#include <iostream>
#include <vector>
#include <cstdlib>
#include <map>
using namespace std;



class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {

        if( matrix.empty() || matrix[0].empty() ) return;
        int m = matrix.size();
        int n = matrix[0].size();
        bool row0, col0;

        row0 = col0 = false;

        // Setting up Status
        for( int i = 0; i < m; i++)
             if(matrix[i][0] == 0) 
             {
                 col0 = true;
                 break;
             }
        for( int j = 0; j < n; j++)
             if(matrix[0][j] == 0)
             {
                 row0 = true;
                 break;
             }
        for( int i = 1; i < m; i++)
            for( int j = 1; j < n; j++)
                if(matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }


        // Setting Zerro 
        for( int i = 1; i < m; i++)
            for( int j = 1; j < n; j++)
                if( matrix[i][0] == 0 || matrix[0][j] == 0)  {
                    matrix[i][j] = 0;
                }

        if( col0 ) {
            for( int i = 0; i < m; i++) matrix[i][0] = 0;
        }

        if( row0 ) {
            for( int j = 0; j < n; j++) matrix[0][j] = 0;
        }

        return;
    };


    void setZeroes_vec(vector<vector<int> > &matrix) {

        if( matrix.empty() || matrix[0].empty() ) return;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> row_id(m, 0);
        vector<int> col_id(n, 0);


        for( int i = 0; i < m; i++)
            for( int j = 0; j < n; j++)
                if(matrix[i][j] == 0) {
                    row_id[i] = 1;
                    col_id[j] = 1;
                }

        for( int i = 0; i < m; i++)
            for ( int j = 0; j < n; j++)
                if( row_id[i] || col_id[j]){
                    matrix[i][j] = 0;
                }

        return;
    }
};



int main() {

    Solution mySol;
    const int d = 5;

    srand(time(NULL));

    vector<vector<int> > matrix(d, vector<int>(d));

    for(int i = 0; i < d; i++)
        for(int j = 0; j < d; j++)
            matrix[i][j] = 9.0 * rand() / RAND_MAX;


    for(int i = 0; i < d; i++)
        for(int j = 0; j < d; j++)
            if( rand() - 0.0*RAND_MAX < 0) matrix[i][j] = 0;



    vector<vector<int> >::iterator it;
    vector<int>::iterator is;
    for(it = matrix.begin(); it != matrix.end(); it++) {
        for(is = (*it).begin(); is != (*it).end(); is++) {
            cout << *is << "  " ;
        }
        cout << endl;
    }
    cout << endl;

    mySol.setZeroes(matrix);
    for(it = matrix.begin(); it != matrix.end(); it++) {
        for(is = (*it).begin(); is != (*it).end(); is++) {
            cout << *is << "  " ;
        }
        cout << endl;
    }
    cout << endl;


    return 0;
}
