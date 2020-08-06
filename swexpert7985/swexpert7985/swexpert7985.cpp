
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> v(1024, 0);
vector<vector<int>> layer;

void init() {
	layer.clear();
	for (int i = 0; i < 11; i++) {
		layer.push_back(vector<int>());
	}
	for (int i = 0; i < 1024; i++) {
		v[i] = 0;
	}
}

void divide(int start, int end, int cnt) {
	int mid = (end + start) / 2;
	cnt++;
	layer.at(cnt).push_back(v[mid]);
	if (start == end) {
		return;
	}
	divide(start, mid-1, cnt);
	divide(mid+1, end, cnt);
	return;
}

int main(int argc, char** argv)
{
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		int K;
		cin >> K;
		int size = pow(2, K) - 1;
		init();
		for (int i = 0; i < size; i++) {
			int a;
			cin >> a;
			v[i] = a;
		}
		int cnt = -1;
		divide(0, size-1, cnt);

		cout << "#" << tc << " ";
		for (int i = 0; i < K; i++) {
			for (int j = 0; j < layer.at(i).size(); j++) {
				cout << layer[i][j] << " ";
			}
			cout << endl;
		}
	}

}
