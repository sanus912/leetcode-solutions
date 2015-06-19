#include <iostream>
#include <vector>
#include <cstdlib>
#include <map>
using namespace std;

/*
 *	Given a 2D binary matrix filled with 0's and 1's, 
 *	find the largest rectangle containing all ones and return its area.
 *
 */

class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {

        int res = 0;
        if(matrix.empty() || matrix[0].empty() ) return res;
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int > > width(m, vector<int>(n, 0));
        vector<vector<int > > height(m, vector<int>(n, 0));


        if( matrix[0][0] != '0') {
                width[0][0] = 1;
                height[0][0] = 1;
                res = 1;
        }

        for(int j = 1; j < n; j++) {
            if( matrix[0][j] != '0') {
                width[0][j] = width[0][j-1] + 1;
                height[0][j] = 1;
                res = max(res, width[0][j]);
            }
        }
        for(int i = 1; i < m; i++) {
            if( matrix[i][0] != '0') {
                width[i][0] = 1;
                height[i][0] = height[i-1][0] + 1;
                res = max(res, height[i][0]);
            }
        }

        if( m == 1 || n == 1) return res;



        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                int a, b;
                if( matrix[i][j] != '0') {
                    a = width[i][j] = width[i][j-1] + 1;
                    b = height[i][j] = height[i-1][j] + 1;
                    for( int k = i; k > i - b; k--) {
                        a = min(a, width[k][j]);
                        int tmp = a * (i-k+1);
                        if (tmp > res) res = tmp;
                        //cout <<  width[k][j] <<"*"<<i-k+1 << " (i,j)= "<<i<<j<< " ";
                    }
                    //cout << endl;
                }
            }
        }


        return res;
        
    }
};


int main() {

    Solution mySol;
    const int m = 6;
    const int n = 5;

	vector<vector<char> > board(m, vector<char>(n));
	char array0[]={"00010"};
	char array1[]={"01110"};
	char array2[]={"11111"};
	char array3[]={"11111"};
	char array4[]={"00001"};
	char array5[]={"01001"};
	board[0].assign(array0, array0 + n);
	board[1].assign(array1, array1 + n);
	board[2].assign(array2, array2 + n);
	board[3].assign(array3, array3 + n);
	board[4].assign(array4, array4 + n);
	board[5].assign(array5, array5 + n);

    //board.resize(1, vector<char>(2, '0'));
    //board[0].resize(2, '0');
    //board[0][0] = '1';

    vector<vector<char> >::iterator it;
    vector<char>::iterator is;
    for(it = board.begin(); it != board.end(); it++) {
        for(is = (*it).begin(); is != (*it).end(); is++) {
            cout << *is << "  " ;
        }
        cout << endl;
    }
    cout << endl;

    int area = mySol.maximalRectangle(board);
    cout << " The maxima rectangle area is : " << area << endl;
    
    return 0;
}
