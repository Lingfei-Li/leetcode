// Feature:
// Tree manipulation
// properties of a tree
// order or traversal

#include"mytest.h"


using namespace std;

struct TreeLinkNode{
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

void connect(TreeLinkNode *u) {
    if(!u) return;
    //search for *next
    //assumption: current level has linked until right end
    TreeLinkNode* v = u->next;
    while(v) {
        if(v->left) {
            v = v->left;
            break;
        }
        else if(v->right) {
            v = v->right;
            break;
        }
        else {
            v = v->next;
        }
    }
    if(u->left) {
        if(u->right) u->left->next = u->right;
        else u->left->next = v;
    }
    if(u->right) u->right->next = v;

    //order is important
    connect(u->right);
    connect(u->left);
}

int main() {
	srand(time(NULL));

    TreeLinkNode *u[5];
    for(int i = 0; i < 5; i ++) {
        u[i] = new TreeLinkNode(i);
    }


    u[0]->left = u[1];
    u[0]->right = u[2];
    u[1]->left = u[3];
    u[2]->right = u[4];

    connect(u[0]);

    cout<<u[3]->next<<endl;


    return 0;
}
