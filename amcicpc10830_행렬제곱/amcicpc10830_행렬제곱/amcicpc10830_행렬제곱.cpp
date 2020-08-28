#include <iostream>
#include <vector>

using namespace std;
typedef vector<vector<int>> mat;
mat mul(mat arr, mat temp) {
	mat ans(arr.size(), vector<int>(arr.size(), 0));

	for (int i = 0; i < arr.size(); i++) {
		for (int j = 0; j < arr.size(); j++) {
			for (int k = 0; k < arr.size(); k++) {
				ans[i][j] += arr[i][k] * temp[k][j];
			}
			ans[i][j] %= 1000;
		}
	}

	return ans;
}

mat pow(mat arr, long long n) {
	mat ans(arr.size(), vector<int>(arr.size(), 0));
	for (int i = 0; i < arr.size(); i++) {
		ans[i][i] = 1;
	}
	while (n > 0) {
		if (n % 2 == 1) {
			ans = mul(ans, arr);
		}
		n = n / 2;
		arr = mul(arr, arr);
	}
	return ans;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	long long P;
	cin >> N >> P;
	mat arr(N, vector<int>(N, 0));
	mat ans;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int x;
			cin >> x;
			arr[i][j] = x;
		}
	}

	ans = pow(arr, P);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << ans[i][j] <<" ";
		}
		cout << "\n";
	}
}
