#include <iostream>
#include <vector>
#include <cstdlib>
#include <unordered_map>
using namespace std;



class Solution {
public:
    
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

    bool isValidSudoku_1(vector<vector<char> > &board) {

        unordered_map<char, int> hs;

        for(int i = 0; i < 9; i++) {
            hs.clear();
            for(int j = 0; j < 9; j++) {
                char c = board[i][j];
                if(c == '.') continue;
                if( ++hs[c] > 1) return false;
            }
        }

        for(int j = 0; j < 9; j++) {
            hs.clear();
            for(int i = 0; i < 9; i++) {
                char c = board[i][j];
                if(c == '.') continue;
                if( ++hs[c] > 1) return false;
            }
        }

        for(int i = 0; i < 9; i += 3) 
            for(int j = 0; j < 9; j += 3){
                hs.clear();
                for(int k = 0; k < 9; k++) {
                    char c = board[i+k/3][j+k%3];
                    if(c == '.') continue;
                    if( ++hs[c] > 1) return false;
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
	char array0[]={"....5..1."};
	char array1[]={".4.3....."};
	char array2[]={".....3..1"};
	char array3[]={"8......2."};
	char array4[]={"..2.7...."};
	char array5[]={".15......"};
	char array6[]={".....2..."};
	char array7[]={".2.9....."};
	char array8[]={"..4......"};
	
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



    return 0;
}
