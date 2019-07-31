#include <iostream>
using namespace std;

struct Node {
	int data;
	Node *next;
};

Node * findNode(int x, Node *head) {
	Node *tmp = head;
	int i = 0;
	while (tmp != NULL) {
		i++;
		if (tmp->data == x) {
			cout<<x<<"是第"<<i<<"个结点"<<endl;
			return tmp;
		}
		tmp=tmp->next;
	}
	cout<<"没有找到值为"<<x<<"的结点"<<endl;
}
//在第i个结点之后插入结点， 
void insertNode(int x, int i, Node * head) {
	Node * tmp = head;
	int j = i;
	while (tmp != NULL && --j > 0) {
		if (tmp->next != NULL) {
			tmp=tmp->next;
			j--;
		} else {
			j = 0; 
		} 
	}
	
	if (tmp != NULL) {
		Node * n = new Node;
		n->data = x;
		n->next = tmp->next;
		tmp->next = n;
	} 
}

void traverse(Node * p) {
	
	while (p != NULL) {
		cout<<p->data<<" "; 
		p=p->next;
	}
	cout<<endl;
}

Node* deleteNode(int x, Node* head) {
	Node * cur = head, *pri = head;
	Node * tmp;
	
	while (cur != NULL) {
		if (cur->data == x) {
			tmp = cur;
			if (cur == head) {
				// it's first node in linkedlist
				head = head->next;
				cur = pri = head; 
			} else {
				pri -> next = cur->next;
				cur = cur->next;
			}
			delete tmp;
		} else  {
			if (cur != head)
			    pri = pri->next;
		    cur = cur->next;
		}
	}
	return head;
} 

int main(int argc, char** argv) {
	Node *head, *cur;
	int val;
	cin>>val;
	if (val != 0) {
		cur = head = new Node;
	    head->next = NULL;
	    head->data = val;
	}
	cin>>val;
	while (val != 0) {
		Node *tmp = new Node;
		tmp->data = val;
		tmp->next = NULL;
		cur->next= tmp;
		cur= cur->next;
		cin>>val;
	}
	traverse(head);
	insertNode(11, 3, head);
	traverse(head);
	findNode(21, head);
	head = deleteNode(19, head);
	traverse(head);
}

