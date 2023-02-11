#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

int n,m;
const int N = 1e5 + 10;
bool vis[N];
vector<int> adj[N],reverse_adj[N];
vector<int> ans;
vector<int> parent(N,-1);
stack<int> st;
vector<int> store;
int s, e;

bool cycle(int u) {
	vis[u] = true;
	for(int v:adj[u]) {
		if(!vis[v]) {
			parent[v] = u;
			if(cycle(v)) {
				return true;
			}
		}
		else if(v != parent[u]) {
			s = v;
			e = u;
			return true;
		}
	}
	return false;
}

void dfs1(int u) {
	vis[u] = true;
	for(int v:adj[u]) 
		if(!vis[v]) {
			dfs1(v);
		}
	st.push(u);
} 

void dfs2(int u) {
	vis[u] = true;
	store.push_back(u);
	for(int v:reverse_adj[u]) 
		if(!vis[v]) {
			dfs2(v);
		}
}

int main() {	
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	 // freopen("input.txt", "r",stdin);
	cin >> n >> m;
	for(int i = 0; i < m; ++i) {
		int u,v; cin >> u >> v;
		adj[u].push_back(v);
		reverse_adj[v].push_back(u);
	}

	memset(vis,false,sizeof(vis));
	for(int i = 1; i <= n; ++i) 
		if(!vis[i]) {
			dfs1(i);
		}

	memset(vis,false,sizeof(vis));
	int cnt = 0;
	ans.clear();
	while(!st.empty()) {
		int u = st.top(); st.pop();
		if(!vis[u]) {
			cnt++;
			dfs2(u);
			// for(int node:store) cout << node << ' ';
			// cout << endl;
			store.clear();
			ans.push_back(u);
		}
	}
	if(cnt == 1) {
		cout << "YES";
	}
	else {
		cout << "NO" << endl;
		cout << ans[1] << ' ' << ans[0];
	}

}