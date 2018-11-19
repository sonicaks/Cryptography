#include <bits/stdc++.h>

using namespace std;

string encrypt(string text, int key) {
	string cipher = "";
	for (int i = 0; i < text.length(); i++) {
		cipher += (char)((text[i] - 'a' + key) % 26 + 'a');
	}
	return cipher;
}

string decrypt(string text, int key) {
	string plain = "";
	for (int i = 0; i < text.length(); i++) {
		plain += (char)(((text[i] - 'a' - key) % 26 + 26) % 26 + 'a');
	}
	return plain;
}

int main() {
	string plain;
	cout << "Enter plain text: ";
	cin >> plain;
	
	int key;
	cout << "Enter key: ";
	cin >> key;
	
	string cipher = encrypt(plain, key);
	cout << "Deciphered text is: ";
	cout << cipher << "\n";

	string decode = decrypt(cipher, key);
	cout << "Original plain text is: ";
	cout << decode << "\n";
	
	return 0;
}
