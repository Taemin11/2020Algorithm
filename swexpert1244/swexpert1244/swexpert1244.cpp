
#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<int> v;
vector<int> ans;
vector<vector<int>> dp;
string N;
int C;

bool compare(vector<int> a, vector<int> b) {
	for (int i = 0; i < a.size(); i++) {
		if (a[i] > b[i]) {
			return true;
		}
		else if (a[i] == b[i]) {
			continue;
		}
		else {
			return false;
		}
	}
	return false;
}


vector<int> swap(vector<int> change, int a, int b) {
	int temp = change[a];
	change[a] = change[b];
	change[b] = temp;
	return change;
}

void fun(vector<int> change, int cnt) {
	if (compare(dp[cnt], change)) {
		return;
	}

	if (cnt == C) {
		if (compare(change, ans)) {
			ans = change;
		}
		return;
	}

	dp[cnt] = change;
	for (int i = 0; i < v.size(); i++) {
		for (int j = i + 1; j < v.size(); j++) {
			if (i != j) {
				vector<int> temp;
				temp = swap(change, i, j);
				fun(temp, cnt + 1);
			}
		}
	}

	return;
}



int main()
{
	cin.tie(NULL);
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> N;
		cin >> C;
		v.clear();
		ans.clear();
		dp.clear();


		for (int i = 0; i < N.length(); i++) {
			v.push_back(N[i] - 48);
		}
		vector<int> t(v.size(), 0);
		ans = t;

		int cnt = 0;
		vector<int> zeros;
		for (int j = 0; j < v.size(); j++) {
			zeros.push_back(0);
		}

		for (int i = 0; i <= C; i++) {

			dp.push_back(zeros);
		}

		fun(v, cnt);

		cout << "#" << tc << " ";

		for (int i = 0; i < ans.size(); i++) {
			cout << ans[i];
		}

		cout << "\n";
	}
}

