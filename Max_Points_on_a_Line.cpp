#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

class Solution {
public:
    int maxPoints(vector<Point> &points) {
        const int n = points.size();
        if(n <= 2) return n;
        unordered_map<double, int> hs;
        int res = 0;
        
        for(int i = 1; i < n; i++) {
            hs.clear();
            int ch = 0, gx = 1;
            for(int j = 0; j < i; j++) {
                double slope;
                int dx = points[j].x - points[i].x;
                int dy = points[j].y - points[i].y;
                if (dx==0){
                    slope = std::numeric_limits<double>::infinity();
                    if (dy==0){
                        ch++;
                        continue;
                    }
                }
                else
                    slope = 1.0*dy/dx;
              
                if (hs.find(slope)!=hs.end())
                    hs[slope]++;
                else{
                    hs[slope] = 2;
                }
            }
            for (auto r : hs)
                gx = max(gx,r.second);
            res = max(res, gx+ch);
        }
        return res;
    }
};


int main() {

    const int n = 8;
    Point pts[n];
    Solution mySol;

    for(int i = 0; i < n; i++) {
        pts[i].x = (random()%2);
        pts[i].y = (random()%2);
    }

    vector<Point> vpts(pts, pts + n);

    int ans = mySol.maxPoints(vpts);

    cout << "Max points on a line is : " << ans << endl;

    return 0;
}
