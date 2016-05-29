#include"mytest.h"


using namespace std;


ListNode* deleteDuplicates(ListNode* head) {

    if(head == 0) return 0;
    ListNode *u = head->next, *p = head;

    while(u) {
        if(u->val == p->val) {
            u = u->next;
            free(p->next);
            p->next = u;
        }
        else {
            p = u;
            u = u->next;
        }
    }

    return head;

}



int main() {
	srand(time(NULL));

     int a;
     ListNode* head = 0;
     ListNode* tail = 0;
     while(cin>>a) {
         ListNode* u = new ListNode(a);
         if(head == 0) {
             tail = head = u;
         }
         else {
             tail->next = u;
         }
         tail = u;
     }
     ListNode* u = head;
     while(u) {
        printf("%d->", u->val);
        u = u->next;
     }

     u = deleteDuplicates(head);
     cout<<endl;
     while(u) {
        printf("%d->", u->val);
        u = u->next;
     }



    return 0;
}
