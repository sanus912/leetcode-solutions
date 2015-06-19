#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


class HtWt {
public:
	HtWt(int ht, int wt) :
		ht_(ht), wt_(wt) {
	}
	int getHt() {
		return ht_;
	}
	int getWt() {
		return wt_;
	}
	bool isAfter(HtWt previous) {
		if (ht_ > previous.ht_ && wt_ > previous.wt_) {
			return true;
		} else {
			return false;
		}
	}
private:
	int ht_;
	int wt_;
};

bool compare(HtWt a, HtWt b) {
	if (a.getHt() != b.getHt())
		return a.getHt() < b.getHt();
	else
		return a.getWt() < b.getWt();
}

void Helper(vector<HtWt> &items, vector<vector<HtWt>> &solution, int id)
{
    if (id<0 || id>=items.size()) return;

    vector<HtWt> best;
    for (int i=0;i<id;i++)
        if (items[id].isAfter(items[i]))
            if (solution[i].size() > best.size())
                best = solution[i];

    best.push_back(items[id]);

    solution.push_back(best);

    Helper(items, solution, id+1);

}

// Find the maximum length sequence
vector<HtWt> findMaxSeq(vector<HtWt> items) {
    vector<vector<HtWt>> solution;
    Helper(items, solution, 0);

	vector<HtWt> maxSeq;
    for (int i=0;i<items.size();i++)
    {   
        if (solution[i].size()>maxSeq.size())
            maxSeq = solution[i];
    }
    
	return maxSeq;
}

int LIS(vector<HtWt> items)
{
    if (items.size()==0)
        return 0;
    int maxLIS=1;
    vector<int> f(items.size(),1);
    for (int i = 1; i<items.size(); i++){
        for (int j =0;j<i;j++)
            if (items[i].isAfter(items[j])){
                f[i] = max(f[j]+1,f[i]);
            }
        maxLIS = max(maxLIS, f[i]);
    }
    return maxLIS;
}

int main() {
    vector<HtWt> items;
    items.push_back(HtWt(65, 100));
    items.push_back(HtWt(70, 150));
    items.push_back(HtWt(56, 90));
    items.push_back(HtWt(75, 190));
    items.push_back(HtWt(60, 89));
    items.push_back(HtWt(68, 99));
    sort(items.begin(), items.end(), compare);

    cout << "Input (ht,wt): ";
    vector<HtWt>::iterator it = items.begin();
    while (it != items.end()) {
        cout << "(" << it->getHt() << ", " << it->getWt() << ") ";
        it++;
    }

    cout << endl << LIS(items) << " : ";

    vector<HtWt> maxSeq = findMaxSeq(items);
    it = maxSeq.begin();
    while (it != maxSeq.end()) {
        cout << "(" << it->getHt() << ", " << it->getWt() << ") ";
        it++;
    }
    cout << endl;

    return 0;
}
