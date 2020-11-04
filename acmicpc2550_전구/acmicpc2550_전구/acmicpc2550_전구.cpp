
#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	int N = 0;

	cin >> N;

	vector<int> idx(N + 1); 
	vector<int> val(N + 1); 


	for (int i = 0; i < N; i++) {
		int input;
		cin >> input;
		idx[input] = i; //스위치 번호에 해당하는 순서
		val[i] = input; //스위치 순서에 해당하는 번호
	}
	
	vector<int> arr(N);

	for (int i = 0; i < N; i++) {
		int input;
		cin >> input;
		arr[i] = idx[input]; //전구에 연결된 스위치 순서
	}
	
	vector<int> lis(N, 987654321);
	vector<pair<int, int>> trace;

	int lis_size = 0;

	lis[0] = arr[0]; //처음 전구와 연결된 스위치 저장
	trace.push_back(make_pair(0, arr[0]));

	
	for (int i = 1; i < N; i++) {
		//
		auto it = lower_bound(lis.begin(), lis.end(), arr[i]) - lis.begin();
		
		lis[it] = arr[i];
		trace.push_back(make_pair(it, arr[i]));
	}

	int len = lis.size();
	for (int i = 0; i < len; i++) {
		if (lis[i] != 987654321) {
			lis_size++;
		}
	}

	lis_size--;

	len = trace.size();

	vector<int> ansIdx;
	for (int i = len - 1; i >= 0; i--) {
		if (trace[i].first != lis_size)
			continue;

		ansIdx.push_back(trace[i].second); // idx가 담긴다.    
		lis_size--;
	}
	vector<int> ans;

	// idx를 다시 실제 값으로 변환
	len = ansIdx.size();
	for (int i = 0; i < len; i++)
		ans.push_back(val[ansIdx[i]]);

	// 오름차순
	sort(ans.begin(), ans.end());

	printf("%d\n", ans.size());
	for (auto i : ans)
		printf("%d ", i);

	return 0;	

	
}
