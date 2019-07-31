#include <iostream>
using namespace std;

bool enque(int q[], int val);
int deque(int q[]);
void traverseQ(int q[]);

int front = 0, rear = 0;
int main(int argc, char** argv) {
	int queue[5];
	for (int i = 0; i < 7; i++) {
        bool ret = enque(que, 10);
        if (!ret) {
        	break;
		}
		if (!enque(queue, i+2)) {
			break;
		}
    }
	traverseQ(queue);
	cout<<endl;
	for (int i = 0; i < 2; i++) {
		cout<<deque(queue)<<" ";
	}
	cout<<endl;
	traverseQ(queue);
}

bool enque(int q[], int val) {
	if ((rear + 1) % 5 == front) {
		cout<<"队列满"<<endl;
		return 0;
	}
	q[rear] = val;
	rear = (rear+1)%5;
	return 1;
}

int deque(int q[]) {
	if (rear == front) {
		cout<<"队列空"<<endl;
		return -1;
	}
	int val = q[front];
	front = (front+1) % 5;
	
	return val;
}

void traverseQ(int q[]) {
	int tmp = front;
	while (tmp != rear) {
		cout<<q[tmp]<<" ";
		tmp = (tmp+1) % 5;
	}
}

