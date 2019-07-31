/* 
1，有编号为1-100共100个房间，第一个服务员把所有房间门打开
第二个服务员把所有编号是2的倍数的房间门做相反处理，（相反处理
就是如果门开着就关上，如果关着就打开）。第三个服务员把所有编号
是3的倍数的房间门做相反处理。。。以后每个服务员都是如此。
编程计算第100个服务员离开之后哪些房间门是开着的
2, 修改程序，当第N个服务员离开之后，哪些门是开着的，N由用户输入 
*/

#include <iostream> 

using namespace std;

int main(int argc, char** argv) {
	bool door[100];
	// true -- opened, false -- closed
	for (int i=0; i<100; i++) {
		door[i] = true;
	}

	for (int j=2; j<=100; j++) {
		for (int i=1; i<=100; i++) {
			if (i % j == 0)
			    door[i-1] = !door[i-1];
		}
	}
	for (int i=0; i<100; i++) {
		if (door[i])
		    cout<<i+1<<" "; 
	}
	
}
