// 50.46%
// linked list merge sort

#include"mytest.h"


using namespace std;



ListNode* sortList(ListNode* head) {
    if(!head || !head->next) return head;

    //find pivot (mid) point 
    ListNode *m, *u, *v;
    u = v = head;
    v = v->next;
    while(u && v) {
        m = u;
        u = u->next;
        v = (v->next)?v->next->next:v->next;
    }
    v = m->next;
    m->next = 0;
    
    u = head;
    u = sortList(u);
    v = sortList(v);

    ListNode* n = 0;


    //use a sentinel n (tail) to represent end of list
    while(u || v) {
        if(!v || (u && u->val < v->val)) {
            if(n) {
                n->next = u;
                u = u->next;
                n = n->next;
            }
            else {
                n = head = u;
                u = u->next;
            }
        }
        else {
            if(n) {
                n->next = v;
                v = v->next;
                n = n->next;
            }
            else {
                n = head = v;
                v = v->next;
            }
        }
    }

    return head;
                    
}



int main() {
	srand(time(NULL));


    ListNode* u = genLinkedList(10);
    printListkedList(u);
    u = sortList(u);
    printListkedList(u);




    return 0;
}
