#include <iostream>
#include <vector>
using namespace std;


struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {

        vector<Interval> res;

        for( int i = 0; i < intervals.size(); i++) 
            res = insert(res, intervals[i]);

        return res;
    }

    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        
        vector<Interval> res;
        
        for(int i = 0; i < intervals.size(); i++) {
            Interval oneInterval = intervals[i];
            if(newInterval.end < oneInterval.start) {
                res.push_back(newInterval);
                newInterval = oneInterval;
            } else if(oneInterval.end < newInterval.start) {
                res.push_back(oneInterval);
            } else {
                newInterval.start = min(newInterval.start, oneInterval.start);
                newInterval.end = max(newInterval.end, oneInterval.end);
            }
        }
        res.push_back(newInterval);
        return res;
    }

};


int main() {

    Solution mySol;
    vector<Interval> vi; 

    vi.push_back(Interval(1, 3));
    vi.push_back(Interval(2, 6));
    vi.push_back(Interval(8, 10));
    vi.push_back(Interval(15,18));


    vector<Interval> ans = mySol.merge(vi);
    vector<Interval>::iterator it;

    for(it = ans.begin(); it !=ans.end(); it++)
        cout << (*it).start << ", " << (*it).end << endl;


    return 0;
}
