// Feature:
// Linked list cycle detection
// Fast & slow pointer

#include"mytest.h"


using namespace std;


bool hasCycle(ListNode *head) {
    if(!head) return false;
    ListNode* u1, *u2;
    u1 = u2 = head;
    u1 = head->next;
    cout<<u1<<endl;
    cout<<u2<<endl;
    while(u1 && u2) {
        cout<<"asd\n";
        if(u1 == u2) return true;
        if(!u1->next) return false;
        u1 = u1->next->next;
        u2 = u2->next;
    }
    cout<<u1->val<<endl;
    return false;
}



int main() {
	srand(time(NULL));

    ListNode* u = new ListNode(1);
    u->next = u;
    cout<<hasCycle(u)<<endl;




    return 0;
}
