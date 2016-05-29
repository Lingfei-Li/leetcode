// Feature:
// recursion (DFS)


#include"mytest.h"


using namespace std;

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};


void solve(UndirectedGraphNode* u, UndirectedGraphNode* v, unordered_map<int, UndirectedGraphNode*>& mp) {
    int label = u->label;
    if(mp.count(label)) {
        return;
    }
    mp[label] = v;
    v->neighbors.resize(u->neighbors.size());

    for(int i = 0; i < u->neighbors.size(); i ++) {
        if(mp.count(u->neighbors[i]->label)) {
            v->neighbors[i] = mp[u->neighbors[i]->label];
        }
        else {
            UndirectedGraphNode* n = new UndirectedGraphNode(u->neighbors[i]->label);
            v->neighbors[i] = n;
            solve(u->neighbors[i], n, mp);
        }
    }
}

UndirectedGraphNode *cloneGraph(UndirectedGraphNode *u) {
    if(!u) return 0;
    unordered_map<int, UndirectedGraphNode*> mp;
    UndirectedGraphNode* v = new UndirectedGraphNode(u->label);
    solve(u, v, mp);
    return v;
}


int main() {
	srand(time(NULL));




    return 0;
}
