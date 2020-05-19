#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//TODO: Create Node
typedef struct _Node{
	int key;
	struct _Node *left, *right, *parent;
}Node;

Node* initNode(int keyInt);
bool equalsNode(Node* no, Node newNode);

//TODO: Create Splay Tree and functions
typedef struct _SplayTree{
	struct _Node *root, *header;
}SplayTree;

void initTree(SplayTree *tree);
void insert(SplayTree *tree, int keyInt);
void removeDelete(SplayTree *tree, int keyInt);
int findMin(SplayTree *tree);
int findMax(SplayTree *tree);
int find(SplayTree *tree, int keyInt);
bool isEmpty(SplayTree *tree);
void splay(SplayTree *tree, int keyInt);

static Node* l;
static Node* r;
static Node* t;
static Node* y;
static Node* n;
static Node* x;
static Node* new;
static SplayTree* splayTree;

//TODO: Test
void test();

int main(){

	l = (Node*)malloc(sizeof(Node));
	r = (Node*)malloc(sizeof(Node));
	t = (Node*)malloc(sizeof(Node));
	y = (Node*)malloc(sizeof(Node));
	n = (Node*)malloc(sizeof(Node));
	x = (Node*)malloc(sizeof(Node));
	new = (Node*)malloc(sizeof(Node));

	test();

//	free(new);
//	free(l);
//	free(r);
//	free(t);
//	free(n);
//	free(x);
//	free(y);
	free(splayTree);
}

Node* initNode(int keyInt){
	Node* no = (Node*)malloc(sizeof(Node));
	no->key = keyInt;
	no->left = no->right = NULL;
	return no;
}
/*not using code
bool equalsNode(Node* no, Node newNode){

	return no->key == newNode.key;
}
*/

void test(){
	splayTree = (SplayTree*)malloc(sizeof(SplayTree));
	isEmpty(splayTree);
	initTree(splayTree);
	removeDelete(splayTree, 5);
	findMax(splayTree);
    findMin(splayTree);
	find(splayTree, 3);
	insert(splayTree, 5);
	find(splayTree, 1);
	insert(splayTree, 10);
	insert(splayTree, 2);
	insert(splayTree, 1);
	removeDelete(splayTree, 5);
	insert(splayTree, 1);
	find(splayTree, 1);
	removeDelete(splayTree, 1);
	findMax(splayTree);
	findMin(splayTree);
	find(splayTree, 3);
	find(splayTree, 5);
	insert(splayTree, 55);
	removeDelete(splayTree, 5);
}

void initTree(SplayTree *tree){
	tree->root = NULL;
	new = initNode(-1);//For splay()
	tree->header = new;
}

void insert(SplayTree *tree, int keyInt){
	if(tree->root == NULL){
		new = initNode(keyInt);
		//printf("%d", new->key);
		tree->root = new;
		return;
	}
	splay(tree, keyInt);

	//If the key is already there in the tree, don't do anything.
	if (tree->root->key == keyInt)
		return;

	new = initNode(keyInt);
	n = new;

	if (keyInt < tree->root->key){
		n->left = tree->root->left;
		n->right = tree->root;
		tree->root->left = NULL;
	}else{
		n->right = tree->root->right;
		n->left = tree->root;
		tree->root->right = NULL;
	}
	tree->root = n;
	
}

void removeDelete(SplayTree *tree, int keyInt){
	splay(tree, keyInt);
	if((tree->root == NULL)||(keyInt != tree->root->key))
		return;

	//Now delete the root
	if(tree->root->left == NULL)
		tree->root = tree->root->right;
	else{
		x = tree->root->right;
		tree->root = tree->root->left;
		splay(tree, keyInt);
		tree->root->right = x;
	}
}

int findMin(SplayTree *tree){
	if(tree->root == NULL)
		return -1;

	x = tree->root;

	while (x->left != NULL)
		x = x->left;

	splay(tree, x->key);
	return x->key;

}

int findMax(SplayTree *tree){
	if(tree->root == NULL)
		return -1;

	x = tree->root;

	while(x->right != NULL)
		x = x->right;

	splay(tree, x->key);

	return x->key;

}

int find(SplayTree *tree, int keyInt){
	if(tree->root == NULL)
		return -1;
	splay(tree, keyInt);
	if(tree->root->key != keyInt)
		return -1;
	return tree->root->key;

}

bool isEmpty(SplayTree *tree){
	return tree->root == NULL;

}

void splay(SplayTree *tree, int keyInt){

	l = tree->header;
	r = tree->header;
	t = tree->root;

	if(t == NULL)
		return;

	tree->header->left = tree->header->right = NULL;

	while(true){
		if(keyInt < t->key){
			if(t->left == NULL)
				break;
			if(keyInt < t->left->key){
				y = t->left;
				t->left = y->right;
				y->right = t;
				t = y;
				if (t->left == NULL)
					break;
			}
			r->left = t;
			r = t;
			t = t->left;
		}
		else if(keyInt > t->key){
			if(t->right == NULL)
				break;
			if(keyInt > t->right->key){
				y = t->right;
				t->right = y->left;
				y->left = t;
				t = y;
				if(t->right == NULL)
					break;
			}
			l->right = t;
			l = t;
			t = t->right;
		}
		else
			break;
	}
	l->right = t->left;
	r->left = t->right;
	t->left = tree->header->right;
	t->right = tree->header->left;
	tree->root = t;

}
