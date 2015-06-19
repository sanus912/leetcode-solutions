#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    //simplify
    vector<int> twoSum(vector<int> &numbers, int target) {
        unordered_map<int, int> mapping;
        for(int i = 0; i<numbers.size(); i++){
            const int gap = target - numbers[i];
            if (mapping.find(gap)!=mapping.end())
                return {mapping[gap]+1,i+1};
            mapping[numbers[i]] = i;
        }
        return vector<int>();
    }

    vector<int> twoSum_2(vector<int> &numbers, int target) {
        unordered_map<int, int> mapping;
        for(int i = 0; i<numbers.size(); i++)
            mapping[numbers[i]]=i;
        for(int i = 0; i<numbers.size(); i++){
            const int gap = target - numbers[i];
            if (mapping.find(gap)!=mapping.end() && mapping[gap] > i)
                return {i+1, mapping[gap]+1};
        }
        return vector<int>();
    }

};

int main() {

    const int s = 6;
    int myArr[s] = {2, 1, 4, 5, 7, 15};
    int target = 6;
    vector<int> myv;

    myv.assign(myArr, myArr+s);
    cout << "Size of myv: " << int (myv.size()) << endl;

    Solution mySol;
    vector<int> ss = mySol.twoSum(myv, target);

    for(auto is = myv.begin(); is != myv.end(); is++) {
        cout << *is << "  ";
    }
    cout << endl;
    for(auto is = ss.begin(); is != ss.end(); is++) {
        cout << *is << "  ";
    }
    cout << endl;


    int i = 1;
    if(i)
        cout << i << endl;
    i = 0;
    if(i)
        cout << i << endl;
    i = -1;
    if(i)
        cout << i << endl;
    return 0;
}
