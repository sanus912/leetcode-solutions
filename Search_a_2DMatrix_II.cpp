#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int searchMatrix(vector<vector<int> > &matrix, int target) {

        if (matrix.empty()) 
            return false;

        unordered_map<int,bool> visited;
        
        int count=0;
        while(search(matrix,target,visited))
        {   
            count++;
        }

        return count;
    }

    bool search(vector<vector<int> > &matrix, int num, unordered_map<int,bool> & visited)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        int row = 0;
        int col = m-1;
        while (row < n && col >= 0) {
            if (matrix[row][col] == num) {
                if (visited.find(row*m+col)==visited.end()){
                    visited[row*m+col]=true; 
                    cout << row << " " << col << endl;
                    return true;
                }
                else
                {
                    col--;
                    row++;
                }
            } else if (matrix[row][col] > num) {
                col--;
            } else {
                row++;
            }
        }
        return false;
    }

};

int main() {

    Solution mySol;
    vector<vector<int> > matrix = { {1,3,5,7},
        {2,4,7,8},
        {3,5,9,10}};

    vector<vector<int> >::iterator it;
    vector<int>::iterator is;
    for(it = matrix.begin(); it != matrix.end(); it++) {
        for(is = (*it).begin(); is != (*it).end(); is++) {
            cout << *is << "  " ;
        }
        cout << endl;
    }


    int tar = 3;
    cout << mySol.searchMatrix(matrix, tar) << endl;

    return 0;
}
