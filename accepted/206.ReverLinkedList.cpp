// 13.13% 1st group
// reverse a linked list
// stack

#include"mytest.h"


ListNode* solve(ListNode* head) {

    if(!head || !head->next) return head;
    solve(head->next)->next = head;
    return head;
}

//recursion version
ListNode* reverseList(ListNode* head) {
    if(!head || !head->next) return head;
    ListNode* u = head;
    while(u->next) {
        u = u->next;
    }
    solve(head);
    head->next = 0;
    return head = u;
}

ListNode* reverseList_ite(ListNode* head) {
    if(!head || !head->next) return head;

    stack<ListNode*> st;
    ListNode* u = head;

    while(u) {
        st.push(u);
        u = u->next;
    }
    head = st.top();
    while(!st.empty()) {
        ListNode* u = st.top();
        st.pop();
        if(!st.empty())
            u->next = st.top();
        else u->next = 0;
    }
    return head;
}

int main() {
	srand(time(NULL));


    ListNode* u;
    u = genLinkedList(1);
    printListkedList(u);
    printListkedList(reverseList(u));



    return 0;
}
