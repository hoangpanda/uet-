#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n = 5;
	vector<double> a(n);
	for(int i = 0; i < n; ++i) cin >> a[i];

	double min_value = 1e9;
	double max_value = -1e9;
	for(int i = 0; i < n; ++i) {
		min_value = min(min_value,a[i]);
		max_value = max(max_value,a[i]);
	}
	cout << max_value + min_value;
}