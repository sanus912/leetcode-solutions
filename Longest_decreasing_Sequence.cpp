#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


class SatGpa {
public:
	SatGpa(int sat, double gpa) :
		Sat_(sat), Gpa_(gpa) {
	}
    int getSat() {
		return Sat_;
	}
	double getGpa() {
		return Gpa_;
	}
    bool isAfter(SatGpa previous) {
		if (Sat_ > previous.Sat_ && Gpa_ < previous.Gpa_) {
			return true;
		} else {
			return false;
		}
	}
private:
	int Sat_;
	double Gpa_;
};

bool compare(SatGpa a, SatGpa b) {
	if (a.getSat() != b.getSat())
		return a.getSat() < b.getSat();
	else
		return a.getGpa() > b.getGpa();
}

void Helper(vector<SatGpa> &items, vector<vector<SatGpa>> &solution, int id)
{
    if (id<0 || id>=items.size()) return;

    vector<SatGpa> best;
    int best_size = 0;
    int best_index = -1;
    for (int i=0;i<id;i++)
        if (items[id].isAfter(items[i]))
            if (solution[i].size() > best_size)
            {    
                best_index = i;
                best_size = solution[i].size();
            }

    if(best_index != -1) best = solution[best_index];

    best.push_back(items[id]);

    solution.push_back(best);

    Helper(items, solution, id+1);

}

// Find the maximum length sequence
vector<SatGpa> findMaxSeq(vector<SatGpa> items) {
    vector<vector<SatGpa>> solution;
    Helper(items, solution, 0);

	vector<SatGpa> maxSeq;
    int max_size = 0;
    int max_index = -1;
    for (int i=0;i<items.size();i++)
    {   
        if (solution[i].size()>max_size)
        {
            max_index = i;
            max_size = solution[i].size();
        }
    }
    if(max_index != -1) maxSeq = solution[max_index];
    
	return maxSeq;
}


int main() {
    vector<SatGpa> items;
    items.push_back(SatGpa(650, 3.2));
    items.push_back(SatGpa(700, 3.4));
    items.push_back(SatGpa(560, 4.0));
    items.push_back(SatGpa(750, 3.5));
    items.push_back(SatGpa(600, 3.9));
    items.push_back(SatGpa(680, 2.7));
    sort(items.begin(), items.end(), compare);

    cout << "Input (Sat, Gpa): ";
    vector<SatGpa>::iterator it = items.begin();
    while (it != items.end()) {
        cout << "(" << it->getSat() << ", " << it->getGpa() << ") ";
        it++;
    }
    cout << endl;
    cout << endl;

    vector<SatGpa> maxSeq = findMaxSeq(items);
    it = maxSeq.begin();
    while (it != maxSeq.end()) {
        cout << "(" << it->getSat() << ", " << it->getGpa() << ") ";
        it++;
    }
    cout << endl;

    return 0;
}
