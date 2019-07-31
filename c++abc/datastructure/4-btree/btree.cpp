#include<iostream>
using namespace std;

struct Node {
	int data;
	struct Node * lchild, *rchild;
};

struct Queue {
	int front, rear, size;
	Node ** que;
	bool init(int size);
	
	bool enque(Node *);
	Node * deque();
	void emptyQueue();
};

typedef Node* PNode;
//按照层序的顺序将1-100的数据建立二叉树 
Node * createBTree(Queue *q);
void preOrderTraverse(Node* root);
void preOrderTraverseWithStack(Node* root);
void inOrderTraverse(Node* root);
void postOrderTraverse(Node* root);
void levelOrderTraverse(Node* root, Queue * q);
void deleteTree(Node * root);


bool Queue::init(int n) {
	if (size <= 0)
	    return false;
	que = new Node*[n];
	size = n;
	front=rear=0;
	return true;
}
bool Queue::enque(Node * p) {
	if ((rear + 1) % size == front) {
		cout<<"队列满"<<endl;
		return false;
	}
	que[rear] = p;
	rear = (rear + 1) % size;
	return true;
}
Node * Queue::deque() {
	Node *p = NULL;
	if (front == rear) {
		//cout<<"队列空"<<endl;
        return p; 
	}
	p = que[front];
	front = (front+1) % size;
	return p;
}

void Queue::emptyQueue() {
	front = rear = 0;
}

int main(int argc, char** argv) {
	Queue * q = new Queue;
	q->init(100);
	Node * root = createBTree(q);
	if (root == NULL) {
		cout<<"树空"; 
	}
	cout<<endl<<"先序遍历二叉树"<<endl;
	preOrderTraverse(root);
	cout<<endl<<"使用stack先序遍历二叉树"<<endl;
	preOrderTraverseWithStack(root);
    cout<<endl<<"中序遍历二叉树"<<endl;
	inOrderTraverse(root);
	cout<<endl<<"后序遍历二叉树"<<endl;
	postOrderTraverse(root);
	cout<<endl<<"层序遍历二叉树"<<endl;
    q->emptyQueue();
	levelOrderTraverse(root,q);
	deleteTree(root);
}

Node * createBTree(Queue * q) {
	Node * root = new Node;
	root->data = 1;
	root->lchild = root->rchild = NULL;
	q->enque(root);
	int k = 1;
	while (k < 100) {
		Node * tmp = q->deque();
		Node * lchild = new Node;
		lchild->data = ++k;
		lchild->lchild = NULL;
		lchild->rchild = NULL;
		tmp->lchild = lchild;
		q->enque(lchild);
		if (k < 100) {
			Node * rchild = new Node;
		    rchild->data = ++k;
		    rchild->lchild = NULL;
		    rchild->rchild = NULL;
		    tmp->rchild = rchild;
		    q->enque(rchild);
		}
	}
	return root;
}

void preOrderTraverse(Node * root) {
	if (root == NULL)
	    return;
	cout<<root->data<<" ";
    preOrderTraverse(root->lchild);
    preOrderTraverse(root->rchild);
}

void preOrderTraverseWithStack(Node * root) {
	Node * stack[100];
	int top = -1;
	Node * tmp = root;
	while (tmp != NULL || top > -1) {
		while (tmp != NULL) {
			cout<<tmp->data<<" ";
			stack[++top] = tmp->rchild;
			tmp = tmp->lchild;
		}
		if (top > -1) {
		    tmp = stack[top--];
	    }	
	}
}

void postOrderTraverse(Node * root) {
	if (root != NULL) {
		postOrderTraverse(root->lchild);
		postOrderTraverse(root->rchild);
		cout<<root->data<<" "; 
	}
}

void inOrderTraverse(Node * root) {
	if (root != NULL) {
		inOrderTraverse(root->lchild);
		cout<<root->data<<" ";
		inOrderTraverse(root->rchild);
	}
}

void levelOrderTraverse(Node * root, Queue *q) {
	if (root == NULL || q == NULL)
	    return;
	Node * tmp = root;
	while (tmp != NULL) {
		cout<<tmp->data<<" ";
		if (tmp->lchild != NULL) {
			q->enque(tmp->lchild);
		} 
		if (tmp->rchild != NULL) {
			q->enque(tmp->rchild);
		}
		tmp = q->deque();
	}
}

void deleteTree(Node * root) {
	if (root != NULL) {
		deleteTree(root->lchild);
		deleteTree(root->rchild);
		delete root;
	}
}

