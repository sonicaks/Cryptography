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

string encrypt(string plain, int k1, int k2) {
	string cipher = "";
	for (int i = 0; i < (int)plain.length(); i++) {
		int p = plain[i] - 'a';
		cipher += (char)('a' + (p * k1 + k2) % 26);
	}
	return cipher;
}

string decrypt(string cipher, int k1, int k2) {
	string plain = "";
	for (int i = 0; i < (int)cipher.length(); i++) {
		int c = cipher[i] - 'a';
		plain += (char)('a' + ((c - k2) % 26 + 26) % 26 * mmi(k1, 26) % 26);
	}
	return plain;
}

int main() {
	string txt;
	cout << "Enter plain text: ";
	cin >> txt;
	
	int k1, k2;
	cout << "Enter 2 keys k1 and k2 (k1 should be coprime with 26): ";
	cin >> k1 >> k2;

	if (__gcd(k1, 26) != 1) {
		cout << "k1 not coprime with 26\n";
		return 0;
	}
	
	string encode = encrypt(txt, k1, k2);
	cout << "Cipher is: " << encode << "\n";
	
	string decode = decrypt(encode, k1, k2);
	cout << "Plain is: " << decode << "\n";
	
	return 0;
}
