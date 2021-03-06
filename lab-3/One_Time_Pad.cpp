#include <bits/stdc++.h>

using namespace std;

string generate() {
	string s = "";
	for (int i = 0; i < 5; i++) {
		s += (char)(rand() % 2 + '0');
	}
	return s;
}

string toBinary(int n) {
	string s = "";
	for (int i = 0; i < 5; i++) {
		if ((1 << i) & n) s += '1';
		else s += '0';
	}
	reverse(s.begin(), s.end());
	return s;
}

string computeXor(string text, string key) {
	string res = "";
	for (int i = 0; i < 5; i++) {
		int t = text[i] - '0';
		int k = key[i] - '0';
		int r = t ^ k;
		res += (char)(r + '0');
	}
	return res;
}

string encode(string plain, vector<string> &genKeys) {
	string cipher = "";
	cout << "Decimal plain text:\t";
	for (int i = 0; i < plain.length(); i++) {
		int p = plain[i] - 'a';
		string s = toBinary(p);
		cout << s << " ";
		genKeys.push_back(generate());
		cipher += computeXor(s, genKeys.back());
	}
	cout << "\n";
	return cipher;
}

char toDecimal(string s) {
	int val = 0;
	for (int i = 0; i < s.length(); i++) {
		val = val * 2 + (s[i] - '0');
	}
	return (char)(val + 'a');
}

string decode(string cipher, vector<string> &genKeys) {
	string plain = "";
	for (int i = 0, j = 0; i < cipher.length(); i += 5, j++) {
		string s = computeXor(cipher.substr(i, 5), genKeys[j]);
		plain += toDecimal(s);
	}
	return plain;
}

int main() {
	string plain;
	cout << "Enter plain text:\t";
	cin >> plain;
	
	vector<string> genKeys;
	string cipher = encode(plain, genKeys);
	
	cout << "Keys are:\t\t";
	for (int i = 0; i < genKeys.size(); i++) {
		cout << genKeys[i] << " ";
	}
	cout << "\n";

	cout << "Cipher text is:\t\t" << cipher << "\n";

	string decipher = decode(cipher, genKeys);
	cout << "Decipher text is:\t" << decipher << "\n";
	
	return 0;
}
