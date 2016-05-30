// 8.99% med
// linked list manipulation

#include"mytest.h"


ListNode* oddEvenList(ListNode* head) {
    if(!head) return 0;
    ListNode* tail, *pu;
    tail = head;
    pu = head->next;
    while(pu && pu->next) {
        ListNode* u = pu->next;
        pu->next = u->next;
        u->next = tail->next;
        tail->next = u;

        pu = pu->next;
        tail = u;
    }
    return head;
}



int main() {
	srand(time(NULL));

    ListNode* u = genLinkedList(0);
    print(u);
    print(oddEvenList(u));




    return 0;
}
