#include <iostream>
#include <vector>
#include <stack>
#include <cstdlib>
#include <map>
using namespace std;

/*
 *	Given n non-negative integers representing the histogram's 
 *	bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.
 *
 *	For example,
 *	Given height = [2,1,5,6,2,3],
 *	return 10.
 *
 */

class Solution {
public:
    int largestRectangleArea(vector<int> &height) {

        if(height.size() == 0) return 0;

        stack<int> s;
        int res = 0;
        height.push_back(0);
        
        for (int i=0;i<height.size();i++) {
            if(s.empty() || height[s.top()] < height[i]) {
                s.push(i);
                continue;
            }
            
            while(!s.empty() && height[i] <= height[s.top()])
            {
                int t = s.top(); 
                s.pop();
                if(s.empty())
                    res = max(res, height[t]*i);
                else
                    res = max(res, height[t]*(i-1-s.top()));
            }
            s.push(i);
        }
        
        return res;
    }

    
};



int main() {

    Solution mySol;
    const int s = 6;
    int arr[] = {2,1,5,6,2,3};
	vector<int> hist(arr, arr + s);

    int area = mySol.largestRectangleArea(hist);
    cout << " The largest rectangle area is : " << area << endl;
    
    return 0;
}
