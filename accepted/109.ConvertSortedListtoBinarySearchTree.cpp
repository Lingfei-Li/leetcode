// Feature:
// definition of BST
// linked list manipulation
// fast-slow pointers

#include"mytest.h"


using namespace std;


TreeNode* sortedListToBST(ListNode* head) {
    if(!head) return 0;
    TreeNode* res = new TreeNode(head->val);
    if(!(head->next)) return res;

    ListNode* u, *v, *p;
    u = v = head;
    while(u && v && v->next) {
        p = u;
        u = u->next;
        v = v->next->next;
    }
    res->val = u->val;
    p->next = 0;
    res->left = sortedListToBST(head);
    res->right = sortedListToBST(u->next);

    return res;
}


int main() {
	srand(time(NULL));




    return 0;
}
