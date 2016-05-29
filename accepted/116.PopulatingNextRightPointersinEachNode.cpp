// Feature:
// Tree manipulation
// properties of a tree

#include"mytest.h"


using namespace std;

struct TreeLinkNode{
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

void connect(TreeLinkNode *u) {
    if(!u) return;
    if(u->left) {
        u->left->next = u->right;
        u->right->next = (u->next)?u->next->left:NULL;
    }
    connect(u->left);
    connect(u->right);
}

int main() {
	srand(time(NULL));




    return 0;
}
