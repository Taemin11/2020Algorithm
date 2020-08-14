// swexpert2005.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>

using namespace std;
int pascal[11][11];
int main()
{
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		
		int N;
		cin >> N;

		cout << "#" << tc << "\n";
		for (int i = 0; i < N; i++) {
			pascal[i][0] = 1;
			cout << pascal[i][0] << " ";
			for (int j = 1; j <= i ; j++) {
				if (j == i ) {
					pascal[i][j] = 1;
				}
				else {
					pascal[i][j] = pascal[i - 1][j - 1] + pascal[i - 1][j];
				}
				cout << pascal[i][j] << " ";
			}
			cout << "\n";
		}
	}
}
