#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 ;
vector<int> adj[N + 1];
vector<bool> visited(N + 1 , false);
vector<int> rootDistance (N + 1);

void bfs(int s) {
	queue<int> q ;
	q.push(s);
	while (!q.empty()) {
		int vertex = q.front();
		q.pop();
		for (auto &u : adj[vertex]) {
			if (!visited[u]) {
				q.push(u);
				rootDistance[u] = rootDistance[vertex] + 1 ;
			}
		}
		visited[vertex] = true ;
	}
}


int main()
{
	//ios::sync_with_stdio(0);cin.tie(0);
	int nodes , edges ;
	cin >> nodes >> edges ;
	for (int i = 0 ; i < edges ; i++) {
		int a , b ;
		cin >> a >> b ;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	int cnt = 0 ;
	for (int i = 1 ; i <= nodes ; i++) {
		if (visited[i])continue ;
		cnt++;
		bfs(i);
	}
	cout << "connected components : " <<  cnt << "\n";
	cout << "distance from root :\n";
	for (int i = 1; i <= nodes ; i++) {
		cout << rootDistance[i] << " ";
	}
	cout << "\n";
}