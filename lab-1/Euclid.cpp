#include <bits/stdc++.h>

using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	while (b != 0) {
		cout << a << " " << b << " " << a / b << " " << a - (a / b) * b << "\n";
		int x = a;
		a = b;
		b = x - (x / b) * b;
	}
	cout << a << "\n";
	
	return 0;
}
