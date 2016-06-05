//
// use of comparison function in class
// use of vector iterator

#include"mytest.h"

//Definition for an interval.

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}

    bool operator < (const Interval& rhs) const {
        if(start == rhs.start) return end < rhs.end;
        return start < rhs.start;
    }
};


class SummaryRanges {

public:

    vector<Interval> v;

	struct Cmp{
        bool operator()(Interval a, Interval b){ return a.start < b.start; }
    };

    SummaryRanges() {
    }

    
    bool cmp(Interval& lhs, Interval& rhs){
        if(lhs.start == rhs.start) return lhs.end < rhs.end;
        return lhs.start < rhs.start;
    }

    void addNum(int val) {

        int low = val, high = val;
        vector<Interval>::iterator it = lower_bound(v.begin(), v.end(), Interval(val,val), Cmp);
        if(it != v.begin()){
            it = prev(it);
        }
        while(it != v.end() && (val >= it->start - 1 || val <= it->end + 1)) {
            if(val >= it->start - 1 && val <= it->end + 1) {
                low = min(low, it->start);
                high = max(high, it->end);
                v.erase(it);
            }
            else
                it ++;
        }
        it = lower_bound(v.begin(), v.end(), Interval(low, high), Cmp);
        v.insert(it, Interval(low, high));
    }

    vector<Interval> getIntervals() {
        return v;
    }

};



/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges obj = new SummaryRanges();
 * obj.addNum(val);
 * vector<Interval> param_2 = obj.getIntervals();
 */


int main() {
	srand(time(NULL));

    SummaryRanges sol;
    int a;
    while(cin>>a){
        cout<<a<<endl;
        sol.addNum(a);
        vector<Interval> v = sol.getIntervals();
        for(auto it:v){
            printf("[%d,%d] ", it.start, it.end);
        }
        cout<<endl;
    }




    return 0;
}
