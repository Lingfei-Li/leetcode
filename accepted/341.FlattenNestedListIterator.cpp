// no data yet
// using stack to perform stoppable recursion

#include"mytest.h"

class NestedIterator {
public:
    stack<pair<NestedInteger,int> > stk;
    int pos = 0;
    int nextval = 0;
    vector<NestedInteger> v;
    NestedIterator(vector<NestedInteger> &nestedList) {
        v = nestedList;
    }

    int next() {
        return nextval;
    }

    bool hasNext() {
        while(pos < v.size() || !stk.empty()){
            if(stk.empty()) {
                if(v[pos].isInteger()) {
                    nextval = v[pos++].getInteger();
                    return true;
                }
                else {
                    stk.push(pair<NestedInteger,int>(v[pos++],0));
                }
            }
            pair<NestedInteger, int> p = stk.top();
            stk.pop();
            if(p.first.isInteger()) {
                nextval = p.first.getInteger();
                return true;
            }

            vector<NestedInteger>& tmp = p.first.getList();
            int idx = p.second++;
            if(p.second < tmp.size()) {
                stk.push(p);
            }
            if(idx < tmp.size()) {
                NestedInteger u = tmp[idx];
                stk.push(pair<NestedInteger,int>(u,0));
            }
        }
        return false;
    }
};



int main() {
	srand(time(NULL));




    return 0;
}
