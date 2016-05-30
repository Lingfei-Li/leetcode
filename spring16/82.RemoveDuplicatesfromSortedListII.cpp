//Feature: the use of sentinel node
//  Note: I didn't free any memory in this code. Don't do this in real pojects

#include"mytest.h"


using namespace std;

/**
 *   Definition for singly-linked list.
 *   struct ListNode {
 *      int val;
 *      ListNode *next;
 *      ListNode(int x) : val(x), next(NULL) {}
 *   };
 *    */

ListNode* deleteDuplicates(ListNode* head) {
    if(head == NULL) return NULL;
    ListNode* u, *v, *p;
    ListNode* sentinel = (ListNode*)malloc(sizeof(ListNode));

    sentinel->next = head;
    p = sentinel;
    u = head;
    v = head->next;


    while(v != NULL) {
        if(u->val == v->val) {
            while(v != NULL && u->val == v->val) {
                v = v->next;
            }
            p->next = v;
            u = p;
        }
        else {
            p = u;
            u = v;
            v = v->next;
        }

    }
    return sentinel->next;
}





int main() {
	srand(time(NULL));




    return 0;
}
