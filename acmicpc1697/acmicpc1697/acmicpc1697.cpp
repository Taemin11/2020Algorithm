
#include "pch.h"
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{

	vector<int > v(100000, 0);
	queue<int> q;

	int N;
	int K;
	cin >> N;
	cin >> K;
	q.push(N);
	v[N] = 1;
	if (N == K) {
		cout << 0;
		return 0;
	}

 	while (!q.empty()) {
		int fr = q.front();
		q.pop();
		int r = fr + 1;
		int l = fr - 1;
		int t = fr * 2;
		if (r >= 0 && r <= 100000 && v[r] == 0) {
			v[r] = v[fr] + 1;
			q.push(r);
			if (r == K) {
				cout << v[r] - 1;
				break;
			}
		}
		if (l >= 0 && l <= 100000 && v[l] == 0) {
			v[l] = v[fr] + 1;
			q.push(l);
			if (l == K) {
				cout << v[l] - 1;
				break;
			}
		}
		if (t >= 0 && t <= 100000 && v[t] == 0) {
			v[t] = v[fr] + 1;
			q.push(t);
			if (t == K) {
				cout << v[t] - 1;
				break;
			}
		}
	}
	return 0;
}
