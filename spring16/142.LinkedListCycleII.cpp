// slow: 9.02%
// linked list cycle

#include"mytest.h"


using namespace std;

ListNode *detectCycle(ListNode *head) {
    if(!head) return 0;
    ListNode *u = head;
    unordered_set<ListNode*> st;
    while(u) {
        if(st.count(u)) return u;
        st.insert(u);
        u = u->next;
    }
    return 0;
}



int main() {
	srand(time(NULL));


    ListNode* u= 0, *head;
    for(int i = 0; i < 5; i ++) {
        ListNode* v = new ListNode(i);
        if(!u) {
            head = u = v;
        }
        else {
            u->next = v;
            u = v;
        }
    }
    u = head;
    while(u->next) {
        cout<<u->val<<" ";
        u = u->next;
    }
//    u->next = head;
    u = detectCycle(head);
    if(u)
        cout<<u->val<<endl;
    else 
        cout<<"no cycle\n";





    return 0;
}
