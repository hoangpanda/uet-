#include <iostream>
#include <vector>
using namespace std;

const int N = 1e3;
vector<int> st(N,0);
int ss;

bool not_empty() {
	return ss;
} 

void push(int num) {
	ss++;
	st[ss] = num;
}

void pop() {
	if(not_empty()) {
		ss--;
	}
}

void print() {
	for(int i = 1; i <= ss; ++i) cout << st[i] << ' ';
}

int main() {
	int n; cin >> n;
	ss = 0;
	while(n--) {
		string s; cin >> s;
		if(s == "push") {
			int num; cin >> num;	
			push(num);
		}
		else {
			pop();
		}
	}
	print();
}