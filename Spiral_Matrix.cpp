#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:

    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> res;
        if (matrix.empty()) return res;
        int m = matrix.size();
        int n = matrix[0].size();
        int s = 0;
        int x = m-1;
        int y = n-1;
        while(s<x && s<y)
        {
            for (int i=s;i<y;i++) res.push_back(matrix[s][i]);
            for (int i=s;i<x;i++) res.push_back(matrix[i][y]);
            for (int i=y;i>s;i--) res.push_back(matrix[x][i]);
            for (int i=x;i>s;i--) res.push_back(matrix[i][s]);
            s++;
            x--;
            y--;
        }
        if (s==x && s==y)
            res.push_back(matrix[s][s]);
        else if (s==x)
            for (int i=s;i<=y;i++) res.push_back(matrix[s][i]);
        else if (s==y)
            for (int i=s;i<=x;i++) res.push_back(matrix[i][s]);
            
        return res;
    }

    vector<int> spiralOrder_2(vector<vector<int> > &matrix) {
        vector<int> res;
        if (matrix.empty()) return res;
        int m = matrix.size();
        int n = matrix[0].size();
        int minid_x = 0;
        int minid_y = 0;
        int maxid_x = m-1;
        int maxid_y = n-1;

        while (true){
            for (int j = minid_y; j<=maxid_y; j++)
            {
                res.push_back(matrix[minid_x][j]);
            }
            if (++minid_x > maxid_x)
                break;
            for (int i = minid_x; i<=maxid_x; i++)
            {
                res.push_back(matrix[i][maxid_y]);
            }
            if (--maxid_y < minid_y)
                break;
            for (int j = maxid_y; j>=minid_y; j--)
            {
                res.push_back(matrix[maxid_x][j]);
            }
            if (--maxid_x < minid_x)
                break;
            for (int i = maxid_x; i>=minid_x; i--)
            {
                res.push_back(matrix[i][minid_y]);
            }
            if (++minid_y > maxid_y)
                break;
        }
        return res;
    }

};


int main() {

    Solution mySol;
    const int m= 3;
    const int n= 1;
    vector<vector<int> > matrix(m, vector<int>(n));

    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
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

    vector<int> ss = mySol.spiralOrder_2(matrix);
    for(is = ss.begin(); is != ss.end(); is++) {
        cout << *is << " " ;
    }
    cout << endl;

    return 0;
}
