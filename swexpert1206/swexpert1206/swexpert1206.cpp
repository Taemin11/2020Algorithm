
#include "pch.h"
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int city[1001];

int main()
{
	
	int T = 10;
	for (int tc = 1; tc <= T; tc++) {
		int N;
		cin >> N;

		long ans = 0;

		memset(city, 0, sizeof(city));
		for (int i = 0; i < N; i++) {
			cin >> city[i];
		}

		for (int i = 2; i < N - 2; i++) {
			int m = max(max(city[i - 2], city[i - 1]), max(city[i + 1], city[i + 2]));
			if (city[i] > m) {
				ans += city[i] - m;
			}
		}
		cout << "#" << tc << " " << ans << "\n";
	}
}
