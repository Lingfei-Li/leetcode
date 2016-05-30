

#include"mytest.h"

bool isPalindrome(ListNode* head) {
    //Note: optimization: can reverse the right half and compare in O(n)tm  O(1)sp
 
    ListNode *u = head;
    vector<int> v;
    while(u) {
        v.push_back(u->val);
        u = u->next;
    }

    int n = v.size();
    for(int i = 0; i < n/2; i ++) {
        if(v[i] != v[n-1-i]) return false;
    }
    return n;

                
}



int main() {
	srand(time(NULL));

    ListNode* n;
    n = genLinkedList(3);
    printListkedList(n);
    cout<<isPalindrome(n)<<endl;




    return 0;
}
