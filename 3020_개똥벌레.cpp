#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, H;
int min_h, ncount = 1;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int i, j;
	cin >> N >> H;
	vector<int> hurdle1(H + 1, 0);
	vector<int> hurdle2(H + 1, 0);
	vector<int> sum1(H + 1, 0);
	vector<int> sum2(H + 1, 0);

	// 장애물의 길이를 길이 별로 저장
	int h_len;
	for (i = 1; i <= N; i++) {
		cin >> h_len;
		if (i % 2 == 1) hurdle1[h_len]++;
		else hurdle2[h_len]++;
	}

	// sum 배열에 각 높이별 장애물 개수를 저장 
	sum1[1] = N / 2;
	sum2[1] = N / 2;
	for (i = 2; i <= H; i++) {
		sum1[i] = sum1[i - 1] - hurdle1[i - 1];
		sum2[i] = sum2[i - 1] - hurdle2[i - 1];
	}

	// 최종 높이 별 장애물 개수를 저장
	int temp = 0;
	min_h = N;
	for (i = 1; i <= H; i++) {
		temp = sum1[i] + sum2[H + 1 - i];
		if (temp < min_h) {
			min_h = temp;
			ncount = 1;
		}
		else if (temp == min_h) ncount++;
	}

	cout << min_h << ' ' << ncount << '\n';

	return 0;
}