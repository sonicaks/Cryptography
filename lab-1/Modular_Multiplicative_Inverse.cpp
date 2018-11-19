#include <bits/stdc++.h>

using namespace std;

int gcdExtended(int a, int b, int *x, int *y) {
	if (a == 0) {
		*x = 0;
		*y = 1;
		return b;
	}
	int x1, y1;
	int g = gcdExtended(b % a, a, &x1, &y1);
	*x = y1 - (b / a) * x1;
	*y = x1;
	return g;
}

int main() {
	int a;
	cout << "Enter number whose modular multiplicative inverse is to be found: ";
	cin >> a;
	
	int m;
	cout << "Enter modulo: ";
	cin >> m;
	
	int x, y;
	int g = gcdExtended(a, m, &x, &y);
	
	x = (m + x % m) % m;
	
	if (g == 1) cout << "Modular multiplicative inverse is: " << x << "\n";
	else cout << "Not exists\n";

	return 0;
}
