// 54.36% 1.1-th group
// linked list.
// (program is faster without free..)

#include"mytest.h"


ListNode* delNext(ListNode* p) {
    ListNode* v = p->next;
    p->next = v->next;
    free(v);
    return p->next;
}

ListNode* removeElements(ListNode* head, int val) {
    if(head == 0) return 0;
    while(head && head->val == val) {
        ListNode* tmp = head;
        head = head->next;
        free(tmp);
    }

    ListNode* u = head;
    while(u && u->next) {
        if(u->next->val == val) {
            delNext(u);
            continue;
        }
        u = u->next;
    }

    return head;
}


int main() {
	srand(time(NULL));

    ListNode* u = genLinkedList(10);
        printListkedList(u);
    int a;
    while(cin>>a) {
        u = removeElements(u, a);
        printListkedList(u);
    }





    return 0;
}
