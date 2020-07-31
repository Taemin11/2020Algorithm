#include "pch.h"
#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>

using namespace std;

int N, M, V;
vector<vector<int>> nodes(1001, vector<int>(1001, 0));
vector<bool> checked(1001, 0);

void dfs(int v) {
	cout << v << " ";
	checked[v] = true;
	for (int i = 1; i <= N; i++) {
		if (checked[i] == false && nodes[v][i] == 1) {
			dfs(i);
		}
	}
}

void bfs(int v) {
	queue<int> q;
	q.push(v);
	checked[v] = true;

	while (q.empty() == false) {
		int fronts = q.front();
		checked[fronts] = true;
		cout << fronts << " ";
		q.pop();
		for (int i = 1; i <= N; i++) {
			if (checked[i] == false && nodes[fronts][i] == 1) {
				checked[i] = true;
				q.push(i);
			}
		}
	}

}

int main()
{
	cin >> N;
	cin >> M;
	cin >> V;

	int node_s, node_e;
	for (int i = 0; i < M; i++) {
		cin >> node_s;
		cin >> node_e;
		nodes[node_e][node_s] = 1;
		nodes[node_s][node_e] = 1;
	}
	dfs(V);
	cout << "\n";

	checked.assign(1001, false);
	bfs(V);
	cout << "\n";
}
