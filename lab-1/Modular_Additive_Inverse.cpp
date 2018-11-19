#include <bits/stdc++.h>

using namespace std;

int main() {
	int a;
	cout << "Enter number whose modular additive inverse is to be found: ";
	cin >> a;
	
	int m;
	cout << "Enter value of modulo: ";
	cin >> m;
	
	a %= m;
	if (a < 0) a += m;
	
	int b = (m - a) % m;
	cout << "Modular additive inverse is: " << b << "\n";
	
	return 0;
}
