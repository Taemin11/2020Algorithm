#include <iostream>

using namespace std;

int dir[4][2] = { {0, 1} ,{0, -1}, {1, 0}, {-1, 0} };
double prop[4];
int visit[31][31];
int N;
double ans;

void dfs(int r, int c, double per, int cnt) {

	if (cnt == N) {
		ans += per;
		return;
	}

	visit[r][c] = 1;

	for (int i = 0; i < 4; i++) {
		int dr = r + dir[i][0];
		int dc = c + dir[i][1];
		if (visit[dr][dc] == 0) {
			dfs(dr, dc, prop[i] * per, cnt+1);
			visit[dr][dc] = 0;
		}
	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < 4; i++) {
		double p;
		cin >> p;
		prop[i] = p / 100;
	}

	for (int i = 0; i < 31; i++) {
		for (int j = 0; j < 31; j++) {
			visit[i][j] = 0;
		}
	}

	dfs(15, 15, 1, 0);
	cout.precision(11);
	cout << ans << "\n";
}
