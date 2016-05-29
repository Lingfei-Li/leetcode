#include"mytest.cpp"


using namespace std;



class LinkedListNode{
public:
    int val;
    LinkedListNode *next;

    LinkedListNode(int node_value) {
        val = node_value;
        next = NULL;
    }
};

LinkedListNode* _insert_node_into_singlylinkedlist(LinkedListNode *head, int val){
    if(head == NULL) {
        head = new LinkedListNode(val);
    }
    else {
        LinkedListNode *end = head;
        while (end->next != NULL) {
            end = end->next;
        }
        LinkedListNode *node = new LinkedListNode(val);
        end->next = node;
    }
    return head;
}


LinkedListNode* manipulateList(LinkedListNode* root) {
    if(root == NULL) return NULL;
    if(root->next == NULL) return root;
    int len = 0;
    LinkedListNode* u = root;
    while(u) {
        len++;
        u = u->next;
    }
//    printf("\nlen: %d\n", len);
    LinkedListNode* rhs = root;
    LinkedListNode* lhs_end = root;
    for(int i = 0; i < len/2; i ++) {
        lhs_end = rhs;
        rhs = rhs->next;
    }
//    printf("val: %d, end: %d\n", rhs->val, lhs_end->val);
    lhs_end->next = NULL;

    LinkedListNode*u1, *u2, *v1, *v2;

    u1 = root, u2 = u1->next, v1 = rhs, v2 = v1->next;

    while(u1&&v1) {
        if(u1&&v1) {
            u1->next = v1;

            u1 = u2;
            if(u1) u2 = u1->next;
            else u2 = NULL;
        }
        if(u1&&v1) {
            v1->next = u1;
            v1 = v2;
            if(v1) v2 = v1->next;
            else v2 = NULL;
        }
    }

//    u1 = root;
//    while(u1) {
//        printf("%d ", u1->val);
//        u1 = u1->next;
//    }
//    printf("\n");

    return root;

}



int main() {
	srand(time(NULL));

    while(1) {
        LinkedListNode* res;

        int _root_size;
        int _root_item;
        LinkedListNode* _root = NULL;
        cin >> _root_size;
        int _root_i;
        for(_root_i = 0; _root_i < _root_size; _root_i++) {
            cin >> _root_item;
            _root = _insert_node_into_singlylinkedlist(_root, _root_item);
        }


        res = manipulateList(_root);
        LinkedListNode* u = res;
        while(u) {
            printf("%d ", u->val);
            u = u->next;
        }



    }




    return 0;
}



LinkedListNode* manipulateList_naive(LinkedListNode* root) {
    if(root == NULL) return NULL;
    if(root->next == NULL) return root;
    int len = 0;
    LinkedListNode* u = root;
    while(u) {
        len++;
        u = u->next;
    }
//    printf("\nlen: %d\n", len);
    LinkedListNode* rhs = root;
    LinkedListNode* lhs_end = root;
    for(int i = 0; i < len/2; i ++) {
        lhs_end = rhs;
        rhs = rhs->next;
    }
//    printf("val: %d, end: %d\n", rhs->val, lhs_end->val);
    lhs_end->next = NULL;

    LinkedListNode* lhs = root;

    LinkedListNode* newHead = (LinkedListNode*)malloc(sizeof(LinkedListNode));
    newHead->val = lhs->val;
    LinkedListNode* tmp = (LinkedListNode*)malloc(sizeof(LinkedListNode));
    tmp->val = rhs->val;
    newHead->next = tmp;
    u = tmp;
    lhs = lhs->next;
    rhs = rhs->next;
    while(lhs&&rhs) {
//        printf("lhs: %d, rhs: %d\n", lhs->val, rhs->val);
        tmp = (LinkedListNode*)malloc(sizeof(LinkedListNode));
        tmp->val = lhs->val;
        u->next = tmp;
        u = u->next;

        tmp = (LinkedListNode*)malloc(sizeof(LinkedListNode));
        tmp->val = rhs->val;
        u->next = tmp;
        u = u->next;

        lhs = lhs->next;
        rhs = rhs->next;
    }
    if(rhs) {
        tmp = (LinkedListNode*)malloc(sizeof(LinkedListNode));
        tmp->val = rhs->val;
        u->next = tmp;
        u = u->next;
    }
    u->next = 0;


//    u = newHead;
//    while(u) {
//        printf("%d ",u->val);
//        u = u->next;
//    }

    return newHead;

}




bool isBalanced(string input) {
    if(input.length() == 0) return true;
    cout<<input<<endl;
    int l = 0, r = input.length()-1;
    for(; l <= r; l ++) {
        if(input[l] == '[' ) {
            if(l==r) return false;
            for(; r > l; r --) {
                if(input[r] == ']') {
                    return isBalanced(input.substr(l+1, r-l-1));
                }
                else if(input[r] == '[' || input[r] == '(' || input[r] == ')') return false;
            }
            return false;
        }
        else if(input[l] == '(' ) {
            if(l==r) return false;
            for(; r > l; r --) {
                if(input[r] == ')') {
                    return isBalanced(input.substr(l+1, r-l-1));
                }
                else if(input[r] == '[' || input[r] == '(' || input[r] == ']') return false;
            }
            return false;
        }
        else if(input[l] == ')' || input[l] == ']') return false;
    }
    return true;
}
