#include <iostream>
#include <vector>
#include <cstdlib>
#include <unordered_map>
using namespace std;



class Solution {
public:
    bool solveSudoku(vector<vector<char> > &board) {

        for(int i = 0; i < 9; i++)
            for(int j = 0; j < 9; j++) {
                if(board[i][j] == '.'){
                    for(char k = '1'; k  <= '9'; k++) {
                        board[i][j] = k;
                        if(validConf(board, i, j) && solveSudoku(board))
                            return true;
                        board[i][j] = '.';       
                    }
                    return false;        
                }
            }

        return true;           
    }

    bool validConf(vector<vector<char> > &board, int p, int q) {

        char cc = board[p][q];
        //cout << cc << "at" << p << q << endl;
        for(int i = 0; i < 9; i++)
            if( i != p && cc == board[i][q]) return false;
        for(int j = 0; j < 9; j++)
            if( j != q && cc == board[p][j]) return false;
        int s = p / 3;
        int t = q / 3;
        for(int i = 3*s; i < 3*s+3; i++)
            for(int j = 3*t; j < 3*t+3; j++)
                if( i != p && j != q && cc == board[i][j]) return false;
        // we could use the above faster conditon rather than the one below
        // because we have exclude the cases the same in one row or one col
        //if( (i != p || j != q) && cc == board[i][j]) return false;

        return true;
    }

    bool isValidSudoku(vector<vector<char> > &board) {
        unordered_map<char, int> hs_row;
        unordered_map<char, int> hs_col;
        unordered_map<char, int> hs_box;

        for(int i = 0; i < 9; i++) {
            char c;
            hs_row.clear();
            hs_col.clear();
            hs_box.clear();
            for(int j = 0; j < 9; j++) {
                c = board[i][j];
                if(c != '.' && ++hs_row[c] > 1) return false;

                c = board[j][i];
                if(c != '.' && ++hs_col[c] > 1) return false;

                c = board[3*(i/3)+j/3][3*(i%3)+j%3];
                if(c != '.' &&  ++hs_box[c] > 1) return false;
            }
        }

        return true;
    }
};



int main() {

    Solution mySol;
    const int d= 9;

    srand(time(NULL));

    vector<vector<char> > matrix(d, vector<char>(d));

    for(int i = 0; i < d; i++)
        for(int j = 0; j < d; j++)
            matrix[i][j] = 9.0 * rand() / RAND_MAX + '1';


    for(int i = 0; i < d; i++)
        for(int j = 0; j < d; j++)
            if( rand() - 0.8*RAND_MAX < 0) matrix[i][j] = '.';



    vector<vector<char> > board(9, vector<char>(9));
    /*
       char array0[]={"....5..1."};
       char array1[]={".4.3....."};
       char array2[]={".....3..1"};
       char array3[]={"8......2."};
       char array4[]={"..2.7...."};
       char array5[]={".15......"};
       char array6[]={".....2..."};
       char array7[]={".2.9....."};
       char array8[]={"..4......"};
     */
    char array0[]={"53..7...."};
	char array1[]={"6..195..."};
	char array2[]={".98....6."};
	char array3[]={"8...6...3"};
	char array4[]={"4..8.3..1"};
	char array5[]={"7...2...6"};
	char array6[]={".6....28."};
	char array7[]={"...419..5"};
	char array8[]={"....8..79"};
	
	board[0].assign(array0, array0+9);
	board[1].assign(array1, array1+9);
	board[2].assign(array2, array2+9);
	board[3].assign(array3, array3+9);
	board[4].assign(array4, array4+9);
	board[5].assign(array5, array5+9);
	board[6].assign(array6, array6+9);
	board[7].assign(array7, array7+9);
	board[8].assign(array8, array8+9);

        
    matrix = board;
    vector<vector<char> >::iterator it;
    vector<char>::iterator is;
    for(it = matrix.begin(); it != matrix.end(); it++) {
        for(is = (*it).begin(); is != (*it).end(); is++) {
            cout << *is << "  " ;
        }
        cout << endl;
    }
    cout << endl;

    bool iv = mySol.isValidSudoku(matrix);
    if( iv)
        cout << "This Matrix as Sudoku is valid ? Yes!" <<endl;
    else
        cout << "This Matrix as Sudoku is valid ? No!" <<endl;

    mySol.solveSudoku(matrix);
    cout << "After solvation we have :" << endl << endl;
    for(it = matrix.begin(); it != matrix.end(); it++) {
        for(is = (*it).begin(); is != (*it).end(); is++) {
            cout << *is << "  " ;
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}
