#include <bits/stdc++.h>

using namespace std;

string encode(string plain, string key) {
    string cipher = "";
    int m = key.length();
    for (int i = 0, j = 0; i < plain.length(); i++, j++, j %= m) {
        int p = plain[i] - 'a';
        int k = key[j] - 'a';
        cipher += (char)((p + k) % 26 + 'a');
    }
    return cipher;
}

string decode(string cipher, string key) {
    string plain = "";
    int m = key.length();
    for (int i = 0, j = 0; i < cipher.length(); i++, j++, j %= m) {
        int c = cipher[i] - 'a';
        int k = key[j] - 'a';
        plain += (char)(((c - k) % 26 + 26) % 26 + 'a');
    }
    return plain;
}

int main() {
    string plain;
    cout << "Enter plain text: ";
    cin >> plain;

    string key;
    cout << "Enter key text: ";
    cin >> key;

    string cipher = encode(plain, key);
    cout << "Cipher text is: " << cipher << "\n";

    string decipher = decode(cipher, key);
    cout << "Decipher text is: " << decipher << "\n";

    return 0;
}