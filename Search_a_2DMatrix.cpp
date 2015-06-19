#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {

        if (matrix.empty()) return false;
        int n = matrix.size();
        int m = matrix[0].size();
        int p1, p2;


        p1 = 0;
        p2 = n*m-1;      

        while (p1 <= p2) {

            int pm = p1 + (p2 - p1)/2;
            int value = matrix[pm/m][pm%m];

            cout << value << endl;
            if( value < target) p1 = pm+1;
            else if( value > target ) p2 = pm-1;
            else if( value == target) return true;

        }

        return false;
    }

    bool searchMatrix_2(vector<vector<int> > &matrix, int target) {
        int start = 0;
        int end = matrix.size();
        while (start+1 < end)
        {
            int mid = start+(end-start)/2;
            if (target >= matrix[mid][0])
                start = mid;
            else 
                end = mid;
        }
        int pos = search(matrix[start],target);
        if (pos>=0)
        return true;
        else
        return false;
    }
    int search(vector<int> A, int target) {
        int start = 0;
        int end = A.size()-1;
        while (start<=end)
        {
            int mid = start+(end-start)/2;
            if (target == A[mid])
                return mid;
            else if (target > A[mid])
                start = mid+1;
            else if (target < A[mid])
                end = mid-1;
        }
                
        return -1;
    }
};

int main() {

    Solution mySol;
    const int dn= 3;
    const int dm= 5;

    vector<vector<int> > matrix(dn, vector<int>(dm));

    for(int i = 0; i < dn; i++)
        for(int j = 0; j < dm; j++)
            matrix[i][j] = 10 * (i+1) +(j+1);

    vector<vector<int> >::iterator it;
    vector<int>::iterator is;
    for(it = matrix.begin(); it != matrix.end(); it++) {
        for(is = (*it).begin(); is != (*it).end(); is++) {
            cout << *is << "  " ;
        }
        cout << endl;
    }


    int tar = 25;
    bool found = mySol.searchMatrix_2(matrix, tar);
    if (found)
        cout << "We found " <<  tar << " in above matrix" << endl;
    else
        cout << "We DON'T found " <<  tar << " in above matrix" << endl;




    return 0;
}
