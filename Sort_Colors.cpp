#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
using namespace std;

class Solution {
public:
    void sortColors(int A[], int n) {
        
        int red, cur, blue;
        red = cur = 0;
        blue = n - 1;
        
        while(cur <= blue) {
            if(A[cur] == 0) swap(A[cur++], A[red++]);
            else if(A[cur] == 1) cur++;
            else if(A[cur] == 2) swap(A[cur], A[blue--]);
        } 
        
        return;
    }

};

int main() {

    Solution mySol;
    const int s = 11;
    int A[s] = {1,2,0,1,2,0,1,2,0,1,2};
    mySol.sortColors(A, s);

    for( int i = 0; i < s; i++) 
        cout << A[i] << "  ";
    cout << endl;


    return 0;
}
