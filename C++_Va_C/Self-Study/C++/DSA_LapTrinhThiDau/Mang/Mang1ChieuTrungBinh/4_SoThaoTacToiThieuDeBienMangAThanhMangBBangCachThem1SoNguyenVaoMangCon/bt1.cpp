#include <bits/stdc++.h>
using namespace std;

//Số thao tác tối thiểu để chuyển đổi mảng A thành
//mảng B bằng cách thêm một số nguyên vào mảng con

void checkArray(int a[], int b[], int n)
{
	int operations = 0;
	int i = 0;
	while (i < n) {
		if (a[i] - b[i] == 0) {
			i++;
			continue;
		}
		int diff = a[i] - b[i];
		i++;
		//lặp khi các cặp phần tử tương ứng có sự khác biệt
		//giống nhau
		while (i < n && a[i] - b[i] == diff) {
			i++;
		}
		operations++;
	}
	cout << operations << "\n";
}

int main()
{
	int n; cin>> n;
	int a[n], b[n];
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];
	int size = n;
	checkArray(a, b, size);
	return 0;
}
