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

int mmi(int n, int m) {
	int x, y;
	int g = gcdExtended(n, m, &x, &y);
	x = (m + x % m) % m;
	return x;
}

string encrypt(string text, int key) {
	string cipher = "";
	for (int i = 0; i < text.length(); i++) {
		cipher += (char)(((text[i] - 'a') * key) % 26 + 'a');
	}
	return cipher;
}

string decrypt(string text, int key) {
	string plain = "";
	for (int i = 0; i < text.length(); i++) {
		plain += (char)(((text[i] - 'a') * mmi(key, 26)) % 26 + 'a');
	}
	return plain;
}

int main() {
	string plain;
	cout << "Enter plain text: ";
	cin >> plain;

	int key;
	cout << "Enter key (should be coprime with 26): ";
	cin >> key;

	if (__gcd(key, 26) != 1) {
		cout << "Key not coprime with 26\n";
		return 0;
	}

	string cipher = encrypt(plain, key);
	cout << "Deciphered text is: ";
	cout << cipher << "\n";

	string decode = decrypt(cipher, key);
	cout << "Original plain text is: ";
	cout << decode << "\n";

	return 0;
}
