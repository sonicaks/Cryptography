#include <bits/stdc++.h>

using namespace std;

string decrypt(string text, int key) {
	string plain = "";
	for (int i = 0; i < text.length(); i++) {
		plain += (char)((text[i] - 'A' - key + 26) % 26 + 'A');
	}
	return plain;
}

int main() {
	string cipher = "BEEAKFYDJXUQYHYJIQRYHTYJIQFBQDUYJIIKFUHCQD";
	
	for (int key = 0; key < 26; key++) {
		string decipher = decrypt(cipher, key);
		cout << decipher << " " << key << "\n";
	}
	
	return 0;
}
