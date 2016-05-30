// slow 17.46%
// insertion sort
// linked list - insertion sort

#include"mytest.h"


using namespace std;


ListNode* insertionSortList(ListNode* head) {
    if(!head || !head->next) return head;

    ListNode* u = head->next, *up = head;
    while(u) {
        int val = u->val;

        ListNode *v, *vp;
        vp = 0;
        v = head;
        while(v && v->val < u->val) {
            vp = v;
            v = v->next;
        }
        if(v != u) {
            up->next = u->next;
            u->next = v;
            if(vp) vp->next = u;
            else head = u;
            u = up->next;
        }
        else {
            up = u;
            u = u->next;
        }
    }

    return head;
}



int main() {
	srand(time(NULL));


    ListNode* head;
    head = genLinkedList(10);
    printListkedList(head);
    head = insertionSortList(head);
    printListkedList(head);




    return 0;
}
