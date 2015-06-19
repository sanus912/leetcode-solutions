#include <iostream>
#include <vector>
#include <cstdlib>
#include <map>
#include <queue>
using namespace std;



class Solution {
public:
    void solve(vector<vector<char> > &board) {
       
        if(board.empty() || board[0].empty()) return;
        const int m = board.size();
        const int n = board[0].size();

        for(int i = 0; i < m; i++) {
            bfs(board, i, 0, m, n);
            bfs(board, i, n-1, m, n);
        }

        for(int j = 0; j < n; j++) {
            bfs(board, 0, j, m, n);
            bfs(board, m-1, j, m, n);
        }

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == 'O') board[i][j] = 'X';
                if(board[i][j] == '+') board[i][j] = 'O';
            }
        }

        
    }

    void bfs(vector<vector<char> > &board, int si, int sj, int m, int n) {
        typedef pair<int,int> point;
        queue<point> q;

        point start = {si,sj};
        if (board[si][sj]=='O')
        {
            q.push(start);
            board[si][sj]='+';
        }

        while(!q.empty())
        {
            int nq = q.size();
            while(nq>0)
            {
                point cur = q.front();
                q.pop();
                int i = cur.first;
                int j = cur.second;

                if (i+1<m && board[i+1][j]=='O'){
                    board[i+1][j]='+';
                    q.push({i+1,j});
                }
                if (i-1>=0 && board[i-1][j]=='O'){
                    board[i-1][j]='+';
                    q.push({i-1,j});
                }
                if (j+1<n && board[i][j+1]=='O'){
                    board[i][j+1]='+';
                    q.push({i,j+1});
                }
                if (j-1>=0 && board[i][j-1]=='O'){
                    board[i][j-1]='+';
                    q.push({i,j-1});
                }
                nq--;

            }
        }
    }
};



int main() {

    Solution mySol;
    const int d= 4;
	vector<vector<char> > matrix(d, vector<char>(d));
	vector<vector<char> > board(d, vector<char>(d));
	char array0[]={"XXXX"};
	char array1[]={"XXOX"};
	char array2[]={"XOXX"};
	char array3[]={"XOXX"};
	board[0].assign(array0, array0+d);
	board[1].assign(array1, array1+d);
	board[2].assign(array2, array2+d);
	board[3].assign(array3, array3+d);
    matrix = board;
        
    vector<vector<char> >::iterator it;
    vector<char>::iterator is;
    for(it = matrix.begin(); it != matrix.end(); it++) {
        for(is = (*it).begin(); is != (*it).end(); is++) {
            cout << *is << " " ;
        }
        cout << endl;
    }
    cout << endl;

    mySol.solve(matrix);
    cout << "After Solve :" << endl << endl;

    for(it = matrix.begin(); it != matrix.end(); it++) {
        for(is = (*it).begin(); is != (*it).end(); is++) {
            cout << *is << " " ;
        }
        cout << endl;
    }
    cout << endl;



    return 0;
}
