#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
using namespace std;

class Solution {
public:
    void rerange(vector<int> &A)
    {
        int posNum = 0, negNum = 0;  
        for (int i = 0; i < A.size(); i++) {  
            if (A[i] > 0) {  
                posNum++;  
            } else {  
                negNum++;  
            }  
        }  
        int posInd = 1, negInd = 0;  
        if (posNum > negNum) {  
            posInd = 0;  
            negInd = 1;  
        }  

        while (negInd < A.size() && posInd < A.size()) {  
            while (negInd < A.size() && A[negInd] < 0) {  
                negInd += 2;  
            }  
            while (posInd < A.size() && A[posInd] > 0) {  
                posInd += 2;  
            }  
            if (posInd < A.size() && negInd < A.size()) {  
                swap(A[posInd], A[negInd]);  
                posInd += 2;  
                negInd += 2;  
            }  
        }    

    }
    void rerange_2(vector<int> &A) {
        int neg = -2;
        int pos = -1;
        int cur = 0;
        while(cur<A.size())
        {
            if (A[cur]<0 && cur%2==0){
                cur++;
            }
            else if (A[cur]>0 && cur%2==1){
                cur++;
            }
            else if (A[cur]<0 && cur<A.size()-1){
                neg += 2;
                if (neg >= A.size())
                    neg = A.size()-1;
                swap(A[cur],A[neg]);
            }
            else if (A[cur]>0 && cur<A.size()-1)
            {
                pos += 2;
                if (pos >= A.size())
                    pos = A.size()-1;
                swap(A[cur],A[pos]);
            }
            else
            {
                int b = A.back();
                A.erase(A.end()-1);
                A.insert(A.begin(),b);
                return;
            }
            cout << neg << " " << pos << " " << cur << endl;
            for( int i = 0; i < A.size(); i++) 
                cout << A[i] << "  ";
            cout << endl; 
            getchar();

        }
    }

};

int main() {

    Solution mySol;
    vector<int> v = {28,2,-22,-27,2,9,-33,-4,-18,26,25,34,-35,-17,2,-2,32,35,-8};
    mySol.rerange(v);

    for( int i = 0; i < v.size(); i++) 
        cout << v[i] << "  ";
    cout << endl;


    return 0;
}
