// Feature:
// Linked list manipulation.
// Comprehensive analysis of all possible cases

#include"mytest.h"


using namespace std;

ListNode* reverseBetween(ListNode* head, int m, int n) {
    if(head == 0 || head->next == 0 || n == m) return head;
    ListNode* u = head; 
    ListNode* p = 0;
    ListNode* l = 0;

    int cnt = 1;
    while(cnt <= n) {
        if(cnt == m-1) {
            l = u;
        }
        else if(cnt == n){
            if(m == 1) {
                head->next = u->next;
                u->next = p;
                head = u;
            }
            else {
                l->next->next = u->next;
                u->next = p;
                l->next = u;
            }
            break;
        }
        if(cnt >= m) {
            ListNode* tmp = u->next;
            u->next = p;
            p = u;
            u = tmp;
        }
        else {
            p = u;
            u = u->next;
        }
        cnt ++;
    }

    return head;

}


int main() {
	srand(time(NULL));



    ListNode* head = NULL;
    head = readIntLinkedList();
    printListkedList(head);
    head = reverseBetween(head, 5, 5);
    printListkedList(head);


    return 0;
}
