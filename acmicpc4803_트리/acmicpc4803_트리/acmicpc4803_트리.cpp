#include "pch.h"
#include <iostream>

using namespace std;


int root[1001];
int check[1001];
int sizeT[1001];

int find(int x) {
	while (root[x] != x) {
		root[x] = root[root[x]];
		x = root[x];
	}

	return x;
}

void uni(int x, int y) {
	int rx = find(x);
	int ry = find(y);

	if (rx == ry) {
		check[rx] = 0;
	}
	else {
		if (sizeT[rx] < sizeT[ry]) {
			root[rx] = ry;
			sizeT[ry] += sizeT[rx];
		}
		else {
			root[ry] = rx;
			sizeT[rx] += sizeT[ry];
		}
	}
}


int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	int tc = 0;

	while (1) {
		tc++;
		
		int n;
		int m;
		int ans = 0;


		cin >> n >> m;
		for (int i = 1; i <= n; i++) {
			root[i] = i;
			sizeT[i] = 1;
			check[i] = 1;
		}

		if (n == 0 && m == 0) {
			break;
		}
		int x, y;

		for (int j = 1; j <= m; j++) {
			cin >> x >> y;
			uni(x, y);

		}
		for (int i = 1; i <= n; i++) {
			int ri = find(i);
			if (check[ri]) {
				check[ri] = 0;
				ans++;
			}
		}


		cout << "Case " << tc << ": ";
		if (ans == 0) {
			cout << "No trees.\n";
		}
		else if (ans == 1) {
			cout << "There is one tree.\n";
		}
		else {
			cout << "A forest of " << ans << " trees.\n";
		}
	}
}