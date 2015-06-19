#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;



class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        if(board.empty() || board[0].empty()) return false;
        if(word.empty()) return false;
        const int m = board.size();
        const int n = board[0].size();
        vector<vector<bool> > visited(m, vector<bool>(n,false));
        
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++) {
                if(search(board, word,i, j, 0, visited)) 
                    return true;
            }
        return false;
    }
    
    bool search(vector<vector<char> > &board, string word, int i, int j, int p, vector<vector<bool> > &visited) {
        if(p ==  word.size()) 
            return true;

        if (i<0 || j<0 || i>=board.size() || j >=board[0].size())
            return false;

        if (visited[i][j]) 
            return false;

        if (board[i][j] != word[p]) 
            return false;
        
        visited[i][j] = true;
        bool res = search(board, word, i-1, j, p+1, visited) ||
            search(board, word, i+1, j, p+1, visited) ||
            search(board, word, i, j-1, p+1, visited) ||
            search(board, word, i, j+1, p+1, visited);
        visited[i][j] = false;

        return res;
    }
};



int main() {

    Solution mySol;
    const int m = 3;
    const int n = 4;

    vector<vector<char> > board(m, vector<char>(n));
    char array0[]={"ABCE"};
    char array1[]={"SFES"};
    char array2[]={"ADEE"};
    board[0].assign(array0, array0 + n);
    board[1].assign(array1, array1 + n);
    board[2].assign(array2, array2 + n);

    vector<vector<char> >::iterator it;
    vector<char>::iterator is;
    for(it = board.begin(); it != board.end(); it++) {
        for(is = (*it).begin(); is != (*it).end(); is++) {
            cout << *is << "  " ;
        }
        cout << endl;
    }
    cout << endl;

    string w("");
    w = "BCESEEEFS";
    //w = "ABCEEE";
    bool iv = mySol.exist(board, w);
    if( iv)
        cout << endl << "This Board Contains '" << w <<"' ? Yes!" <<endl;
    else
        cout << endl << "This Board Contains " << w <<" ? No!" <<endl;

    return 0;
}
