#include "pch.h"
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

vector<char> bird;
vector<char> nbird;
int prFlag;

bool highPriority(int fr, int bc) {

	if (fr >= bc) {
		return true;
	}
	if (bird[fr] < bird[bc]) {
		return true;
	}
	else if (bird[fr] > bird[bc]) {
		return false;
	}
	else {
		return highPriority(fr + 1, bc - 1);
	}

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		int N;
		cin >> N;

		bird.clear();
		nbird.clear();
		for (int i = 0; i < N; i++) {
			char input;
			cin >> input;
			bird.push_back(input);
		}
		int frontCnt = 0;
		int backCnt = bird.size() - 1;
		prFlag = 0;
		cout << "#" << tc << " ";

		while (frontCnt <= backCnt) {
			if (bird[frontCnt] < bird[backCnt]) {
				nbird.push_back(bird[frontCnt]);
				frontCnt++;
			}
			else if (bird[frontCnt] > bird[backCnt]) {
				nbird.push_back(bird[backCnt]);
				backCnt--;
			}
			else {
				if (highPriority(frontCnt + 1, backCnt - 1)) {
					nbird.push_back(bird[frontCnt]);
					frontCnt++;
				}
				else {
					nbird.push_back(bird[backCnt]);
					backCnt--;
				}
			}
		}
		for (auto n : nbird) {
			cout << n;
		}
		cout << "\n";

	}
	return 0;
}

