#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:

    vector<vector<int> > generateMatrix(int n) {
        
        vector<vector<int> > res;
        if(n < 1) return res;
        res.resize(n, vector<int>(n,0));

        int n1 = 0, n2 = n-1;
        int i, j, d = 1;
                
        while(n1 < n2) {
            for(i = n1, j = n1; j < n2; j++) res[i][j] = d++;
            for(j = n2, i = n1; i < n2; i++) res[i][j] = d++;
            for(i = n2, j = n2; j > n1; j--) res[i][j] = d++;
            for(j = n1, i = n2; i > n1; i--) res[i][j] = d++;
            n1 ++; n2--;
        }
        if(n1 == n2) res[n1][n1] = d;
        
        return res;
    }
    

    vector<vector<int> > generateMatrix_2(int n) {
        vector<vector<int> > matrix(n,vector<int>(n,0));
        if (n==0) return matrix;
        
        int minid_x = 0;
        int minid_y = 0;
        int maxid_x = n-1;
        int maxid_y = n-1;

        int cur = 1;
        while (true){
            for (int j = minid_y; j<=maxid_y; j++)
            {
                matrix[minid_x][j] = cur++;
            }
            if (++minid_x > maxid_x)
                break;
            for (int i = minid_x; i<=maxid_x; i++)
            {
                matrix[i][maxid_y] = cur++;
            }
            if (--maxid_y < minid_y)
                break;
            for (int j = maxid_y; j>=minid_y; j--)
            {
                matrix[maxid_x][j] = cur++;
            }
            if (--maxid_x < minid_x)
                break;
            for (int i = maxid_x; i>=minid_x; i--)
            {
                matrix[i][minid_y] = cur++;
            }
            if (++minid_y > maxid_y)
                break;
        }
        return matrix;
    }
};


int main() {

    Solution mySol;
    const int n = 4;


    vector<vector<int> > ss = mySol.generateMatrix_2(n);
    vector<vector<int> >::iterator it;
    vector<int>::iterator is;
    for(it = ss.begin(); it != ss.end(); it++) {
        for(is = (*it).begin(); is != (*it).end(); is++) {
            cout << *is << "\t" ;
        }
        cout << endl;
    }

    return 0;
}
