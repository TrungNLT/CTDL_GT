#include<iostream>
using namespace std;
int main() {
	const int k = 1000;
	int cnt[k + 1] = { 0 };
	int nx;
	cin >> nx;
	for (int i = 0; i < nx; i++) {
		int val;
		cin >> val;
		if (cnt[val] == 0)  
			cnt[val] = 1; 
	}

	int ny;
	cin >> ny;
	for (int i = 0; i < ny; i++) {
		 int val;
		cin >> val;
		if (cnt[val] == 1)  
			cnt[val] = 2;  

	}

	int nz;
	cin >> nz;
	for (int i = 0; i < nz; i++) {
		int val;
		cin >> val;
		if (cnt[val] == 2) 
			cnt[val] = 3; 
	}

	int ans = 0; 
	for (int i = 0; i <= k; i++) {
		if (cnt[i] == 3) {
			ans++;
		}
	}
	cout << ans << endl;
	for (int i = 0; i <= k; i++) {
		if (cnt[i] == 3)
			cout << i << " ";
	}
	return 0;
}
