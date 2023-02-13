#include <iostream>
using namespace std;

int c2n(int n) {
	return n*(n-1)/2;
}

int main() {
	int n; cin >> n;
	int a[n + 1];
	for(int i = 0; i < n; ++i) cin >> a[i];

	for(int i = 0; i < n - 1; ++i) {
		for(int j = i + 1; j < n; ++j) 
			if(a[i] > a[j]) swap(a[i],a[j]);
	}

	a[n] = a[n-1] + 1;
	int cnt = 0;
	int t = 1;
	for(int i = 0; i < n; ++i) 
		if(a[i] == a[i+1]) t++;
		else {
			cnt += c2n(t);
			t = 1;
		} 	
	cout << cnt;
}