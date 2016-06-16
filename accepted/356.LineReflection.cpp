#include"mytest.h"


class Solution {
public:
    bool isReflected(vector<pair<int, int> >& points) {
        map<int, vector<int> > pts;
        for(auto p : points) {
            pts[p.second].push_back(p.first);
        }

        int flag = 0;
        double reflect;
        for(auto y : pts){
            vector<int>& x = y.second;

            sort(x.begin(), x.end());
            int l = 0, r = x.size()-1;
            if(flag == 0){
                reflect = ((double)x[l++]+(double)x[r--])/2;
                flag = 1;
            }
            while(l <= r){
                double tmp = ((double)x[l++]+(double)x[r--])/2;
                if(abs(tmp-reflect) > 0.000001) return false;
            }
        }
        return true;
    }
};



int main() {
	srand(time(NULL));

    Solution sol;
    vector<pair<int,int> > points;
    int a, b;
    while(cin>>a>>b){
        points.push_back(pair<int,int>(a, b));
        cout<<a<<" "<<b<<endl;
    }
    cout<<sol.isReflected(points);



    return 0;
}
