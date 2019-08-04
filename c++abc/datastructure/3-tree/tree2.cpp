#include <iostream>
using namespace std;

struct node {
	char data;
	node * firstchild, * nextsibling;
	//node * parent;
	node (char c) {
		data = c;
		firstchild = NULL;
		nextsibling = NULL;
	}
};

node * createTree();
void preOrderTraverse(node *);
void postOrderTraverse(node *);
void levelOrderTraverse(node *);
void findKthChildP(node * root, char p, int k);
bool enque(node * [], node *);
node * deque(node *[]);

int front, rear;
const int quesesize=100;
node * queue[quesesize];

//TODO：
void destroyTree(node *& root) {
	if (root != NULL) {
		destroyTree(root->firstchild);
		destroyTree(root->nextsibling);
		delete root;
		root = NULL;
	}
}
//void insertNode(node* root, char p, int k, char k);
//void deleteNode(Node * root, char p, int k); 
// TODO: 使用非递归算法来实现先序和后序遍历 

int main(int argc, char ** argv) {
	node * root = createTree();
	cout<<"先序遍历:"<<endl; 
	preOrderTraverse(root);
	cout<<endl;
	cout<<"后序遍历:"<<endl; 
	postOrderTraverse(root);
	cout<<endl;
	cout<<"层序遍历:"<<endl; 
	levelOrderTraverse(root);
	cout<<endl;
	findKthChildP(root, 'G', 2);
	destroyTree(root);
	if (root != NULL)
	cout<<root->data;
}

node * createTree() {
	node * tmp = new node('B');
	tmp->firstchild = new node('E');
	tmp->firstchild->nextsibling = new node('F');
	tmp->firstchild->nextsibling->nextsibling = new node('G');
	tmp->firstchild->firstchild = new node('A');
	tmp->firstchild->nextsibling->firstchild = new node('C');
	tmp->firstchild->nextsibling->nextsibling->firstchild = new node('H');
	tmp->firstchild->nextsibling->nextsibling->firstchild->nextsibling = new node('J');
	tmp->firstchild->nextsibling->nextsibling->firstchild->nextsibling->nextsibling = new node('K');
	return tmp;
}

void preOrderTraverse(node * root) {
	if (root == NULL) {
		return;
	}
	cout<<root->data<<" ";
	preOrderTraverse(root->firstchild);
	/*
	if (root->firstchild != NULL) {
	    node * p= root->firstchild->nextsibling;
	    while (p) {
			preOrderTraverse(p);
			p=p->nextsibling;
    	}
	}
	*/
	preOrderTraverse(root->nextsibling);
}

void postOrderTraverse(node * t) {
	if (t != NULL) {
		if (t->firstchild != NULL) {
			postOrderTraverse(t->firstchild);
			node *p = t->firstchild->nextsibling;
			while (p) {
				postOrderTraverse(p);
				p = p->nextsibling;
			}
		}
		cout<<t->data<<" ";
	}
}

void levelOrderTraverse(node * root) {
	node * tmp = root;
	if  (tmp != NULL) {
		cout<<tmp->data<<" ";
		enque(queue, tmp);
		tmp = deque(queue);
		while (tmp !=NULL) {
		    if (tmp->firstchild != NULL) {
		    	tmp = tmp->firstchild;
		    	cout<<tmp->data<<" ";
		    	enque(queue, tmp);
				while (tmp->nextsibling != NULL) {
		    		tmp = tmp->nextsibling;
		    		cout<<tmp->data<<" ";
		    		enque(queue, tmp);
			    }
			}
			tmp=deque(queue);	
		}
	} 
}

void findKthChildP(node * root, char p, int k) {
	if (root == NULL) {
		return;
	}
	if (root->data == p) {
		node * tmp = root->firstchild;
	    int i = 1;
		while (tmp != NULL && i < k) {
			tmp = tmp->nextsibling;
			i++;
		}
		if (tmp == NULL) {
			cout<<"没有找到G的第二个孩子节点"<<endl;
			return;
		}
	    cout<<tmp->data<<endl;
	}
	else {
	    findKthChildP(root->firstchild, p, k);
		findKthChildP(root->nextsibling, p, k);	
	}
	
}

bool enque(node* q[], node* val) {
	if ((rear + 1) % quesesize == front) {
		cout<<"队列满"<<endl;
		return false;
	}
	q[rear] = val;
	rear = (rear+1)%quesesize;
	return true;
}

node* deque(node* q[]) {
	if (rear == front) {
		//cout<<"队列空"<<endl;
		return NULL;
	}
	node* val = q[front];
	front = (front+1) % quesesize;
	return val;
}
