#include <bits/stdc++.h>
using namespace std;

struct e {
	int u,v;
	int w;
};	

const int N = 1e5 + 1;
int parent[N],sz[N];
int n,m;
vector<e> edge;

// disjoin set union

void make_set() {
	for(int i = 1; i <= n; ++i) {
		parent[i] = i;
		sz[i] = 1;
	}
}

int find(int v) {
	if(v == parent[v]) return v;
	return parent[v] = find(parent[v]);
}

bool uni(int a, int b) {
	a = find(a);
	b = find(b);
	if(a == b) return false;
	if(sz[a] < sz[b]) swap(a,b);
	sz[a] += sz[b];
	parent[b] = a;
	return true;
}

//

bool cmp(e a, e b) {
	return a.w < b.w;
}

void kruskal() {
	vector<e> mst;
	int d = 0;
	sort(begin(edge),end(edge),cmp);
	make_set();

	for(int i = 0; i < m; ++i) {
		if(mst.size() == n - 1) break;
		bool ok = uni(edge[i].u,edge[i].v);
		if(ok) {
			mst.push_back(edge[i]);
			d += edge[i].w;
		}
	}


	if(mst.size() != n - 1) {
		cout << "not exist MST" << endl;
	}
	else {
		cout << d << endl;
	}
}

int main() {
	freopen("input.txt","r",stdin);

	cin >> n >> m;
	for(int i = 0; i < m; ++i) {
		int u,v,w; cin >> u >> v >> w;
		e t = {u,v,w};
		edge.push_back(t);
	}

	kruskal();

}