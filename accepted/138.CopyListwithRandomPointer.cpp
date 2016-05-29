// Note: slow 25.89%
// Feature:
// hashmap

#include"mytest.h"


using namespace std;


struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};


RandomListNode *copyRandomList(RandomListNode *head) {
    if(!head) return 0;

    unordered_map<RandomListNode*, RandomListNode*> m;
    RandomListNode* u = head;
    while(u) {
        RandomListNode* v; 
        if(!m.count(u)) {
            v = new RandomListNode(u->label);
            m[u] = v;
        }
        else {
            v = m[u];
        }

        if(u->next) {
            RandomListNode* n;
            if(!m.count(u->next)) {
                n = new RandomListNode(u->next->label);
                m[u->next] = n;
            }
            else {
                n = m[u->next];
            }
            v->next = n;
        }
        if(u->random) {
            RandomListNode* n;
            if(!m.count(u->random)) {
                n = new RandomListNode(u->random->label);
                m[u->random] = n;
            }
            else {
                n = m[u->random];
            }
            v->random = n;
        }
        u = u->next;
    }
              

    return m[head];
}


int main() {
	srand(time(NULL));


    int a;
    vector<RandomListNode*> v;
    for(int i = 0; i < 5; i ++) {
        RandomListNode* u = new RandomListNode(i);
        v.push_back(u);
    }
    v.push_back(0);
    for(int i = 0; i < 5; i ++) {
        v[i]->next = v[i+1];
        v[i]->random = v[4-i];
    }

    RandomListNode* u;
    for(int i = 0; i < 5; i ++) {
        u = v[i];
        printf("%d %d %d\n", u->label, (u->next)?u->next->label:-1, u->random->label);
        printf("%p %p %p\n", u, u->next, u->random);
    }

    v[0]->next = 0;
    v[0]->random = v[0];
    u = copyRandomList(v[0]);
    cout<<"printing..\n";
    while(u){
        printf("%d %d %d\n", u->label, (u->next)?u->next->label:-1, u->random->label);
        printf("%p %p %p\n", u, u->next, u->random);
        u = u->next;
    }





    return 0;
}
