
#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;
vector<int> v;

void makeSet(int n) {
	v.clear();
	for (int i = 0; i <= n; i++) {
		v.push_back(i);
	}
}

int find(int n) {
	if (n == v[n]) return n;
	return v[n] = find(v[n]);
}

void uni(int a, int b) {

	int rootA = find(a);
	int rootB = find(b);
	if (rootA == rootB) {
		return;
	}
	v[rootA] = rootB;
}

int main()
{ 
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	int M;
	cin >> N >> M;
	makeSet(N);
	for (int i = 0; i < M; i++) {
		int inst, a, b;
		cin >> inst >> a >> b;
		if (inst == 0) {

			uni(a, b);
		}
		else {
			int ra = find(a);
			int rb = find(b);
			if (ra == rb) {
				cout << "YES\n";
			}
			else {
				cout << "NO\n";
			}
		}
	}
}