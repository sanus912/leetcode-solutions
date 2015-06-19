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


    //TLE
    vector<Interval> insert_0(vector<Interval> &intervals, Interval newInterval) {
        auto it = intervals.begin();
        while (it != intervals.end())
        {
            if (newInterval.end < it->start)
            {
                intervals.insert(it, newInterval);
                return intervals;
            }
            else if (newInterval.start > it->end)
            {
                it++;
                continue;
            }
            else
            {
                newInterval.start = min(newInterval.start, it->start);
                newInterval.end = max(newInterval.end, it->end);
                it = intervals.erase(it);
            }
        }
        intervals.push_back(newInterval);
        return intervals;
    }
};


int main() {

    Solution mySol;
    vector<Interval> vi; 

    vi.push_back(Interval(1, 2));
    vi.push_back(Interval(3, 6));
    vi.push_back(Interval(8, 10));
    vi.push_back(Interval(15,18));


    vector<Interval> ans = mySol.insert_0(vi,Interval(2,3));
    vector<Interval>::iterator it;

    for(it = ans.begin(); it !=ans.end(); it++)
        cout << (*it).start << ", " << (*it).end << endl;


    return 0;
}
