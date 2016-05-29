// 4.54% slow
// intersection of linked lists

#include"mytest.h"


using namespace std;


ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode* u = headA, *v = headB;
    int cnt1 = 0, cnt2 = 0;
    while(u) {
        cnt1 ++;
        u = u->next;
    }
    while(v) {
        cnt2 ++;
        v = v->next;
    }
    int diff = cnt1-cnt2;
    u = headA, v = headB;
    if(diff>0) {
        while(diff--) 
            u = u->next;
    }
    else {
        diff = -diff;
        while(diff--)
            v = v->next;
    }

    while(u && v) {
        if(u != v) {
            u = u->next;
            v = v->next;
        }
        else return u;
    }
    return 0;


}



int main() {
	srand(time(NULL));


    ListNode* n = new ListNode(0);
    printf("%p\n", n);
    ListNode* u = new ListNode(1);
    ListNode* v = new ListNode(2);
    printf("%p %p\n", u, v);
    v->next = n;
    u->next = n;
    ListNode* ans = getIntersectionNode(n,n);
    printf("%p\n", ans);
//    ListNode* n = new ListNode(1);





    return 0;
}
