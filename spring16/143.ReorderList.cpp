// 43.63%
// linked list manipulation
// hashmap

#include"mytest.h"


using namespace std;


void reorderList(ListNode* head) {
    if(!head) return;
    vector<ListNode*> v;
    ListNode* u  = head;
    while(u) {
        v.push_back(u);
        u = u->next;
    }

    int n = v.size();
    ListNode* p = 0;
    int range = n/2;
    if(n%2) range ++;
    for(int i = 0; i < range; i ++) {
        ListNode* u1, *u2;
        u1 = v[i];
        u2 = v[n-1-i];
        u1->next = u2;
        if(i == range-1) u2->next = 0;
        if(p)
            p->next = u1;
        p = u2;
    }
    u = head;
                
}


int main() {
	srand(time(NULL));

    ListNode* u;
    u = genLinkedList(19);
    printListkedList(u);
    reorderList(u);
    printListkedList(u);



    return 0;
}
