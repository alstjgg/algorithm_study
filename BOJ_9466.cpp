#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int i, j;
	int n, r;
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> r;
		vector<int> choose(r + 1);
		vector<char> group(r + 1); // 'T' �׷� ���� / 'F' �׷� �ȵ� / NULL �⺻��
		for (j = 1; j <= r; j++) {
			cin >> choose[j];
			if (j == choose[j])
				group[j] = 'T';
		}

		for (j = 1; j <= r; j++) {
			if (group[j] == NULL) {
				int next = j;
				vector<int> remember;
				group[j] = 'F';
				remember.push_back(j);
				while (true) {
					next = choose[next];
					remember.push_back(next);
					if (group[next] == 'F') {
						auto f = find(remember.begin(), remember.end(), next);
						auto end = remember.end() - 1;
						if (f != remember.end() && f != remember.end() - 1) { // ����Ŭ ã���� ��
							for (int k = f - remember.begin(); k < remember.size(); k++)
								group[remember[k]] = 'T';
						}
						break;
					}
					else if (group[next] == 'T') break;
					group[next] = 'F';
				}
			}
		}
		int count = 0;
		for (auto g : group) {
			if (g == 'F') count++;
		}
		cout << count << '\n';
	}

	return 0;
}