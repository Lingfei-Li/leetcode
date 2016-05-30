// 5.77% 1.1st group
// linked list manipulation

#include"mytest.h"

void deleteNode(ListNode* u) {
    ListNode* v = u->next;
    u->val = v->val;
    u->next = v->next;
    free(v);
}



int main() {
	srand(time(NULL));

    ListNode* u;
    u = genLinkedList(10);
    printListkedList(u);
    deleteNode(u);
    printListkedList(u);



    return 0;
}
