#include"mytest.cpp"


using namespace std;
/*
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };
    void printVector(vector<int>& v);
    void printArray(int* A, int n);
    void printListkedList(ListNode *u);
    void genVector(vector<int>& v, int n);
    void genArray(int* A, int n);
    ListNode* genLinkedList(int n);
*/

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

static int cmp(const Interval& a1, const Interval& a2) {
    if(a1.start == a2.start) return a1.end < a2.end;
    return a1.start < a2.start;
}

vector<Interval> merge(vector<Interval>& intervals) {
    if(intervals.size() <= 1) return intervals;
    vector<Interval> ans;

//    cout<<endl<<endl;
    sort(intervals.begin(), intervals.end(), cmp);


    int s = intervals[0].start, e = intervals[0].end;
//    cout<<intervals[0].start<<" "<<intervals[0].end<<endl;
    for(int i = 1; i < intervals.size(); i ++) {
//        cout<<intervals[i].start<<" "<<intervals[i].end<<endl;
        if(intervals[i].start >= s && intervals[i].start <= e) {
            e = max(e, intervals[i].end);
        }
        else {
            ans.push_back(Interval(s,e));
            s = intervals[i].start;
            e = intervals[i].end;
        }

    }
    ans.push_back(Interval(s,e));
    return ans;
}

int main() {
	srand(time(NULL));

    vector<Interval> intervals;
    for(int i = 0; i < 2; i ++) {
        int a = rand()%20;
        int b = a+rand()%3;
        if(a>b) swap(a,b);
        intervals.push_back(Interval(a, b));
        cout<<a<<" "<<b<<endl;
    }

    vector<Interval> ans = merge(intervals);
    cout<<endl<<endl;
    for(int i = 0; i < ans.size(); i ++) {
        cout<<ans[i].start<<" "<<ans[i].end<<endl;
    }


    return 0;
}
