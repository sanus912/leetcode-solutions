#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

class TwoSum {
public:
	void add(int number) {
	    counts[number]++;
	}

	bool find(int value) {
	    for (auto p : counts)
	    {
	        int y = value - p.first;
	        if ((y==p.first && p.second >= 2) || (y!=p.first && counts.find(y)!=counts.end()))
	            return true;
	    }
	    return false;
	}
private:
    unordered_map<int,int> counts;
};

int main() {

    TwoSum a;
    a.add(1);
    a.add(1);
    a.add(2);
    a.add(3);

    cout << a.find(2) << endl;

    return 0;
}
