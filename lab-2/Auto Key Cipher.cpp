#include <bits/stdc++.h>

using namespace std;

string encode(string plain, int key) {
    string cipher = "";
    for (int i = 0; i < plain.length(); i++) {
        int p = plain[i] - 'a';
        int k = key;
        if (i >= 1) k = plain[i - 1] - 'a';
        cipher += (char)((p + k) % 26 + 'a');
    }
    return cipher;
}

string decode(string cipher, int key) {
    string plain = "";
    for (int i = 0; i < cipher.length(); i++) {
        int c = cipher[i] - 'a';
        int k = key;
        if (i >= 1) k = plain[i - 1] - 'a';
        plain += (char)(((c - k) % 26 + 26) % 26 + 'a');
    }
    return plain;
}

int main() {
    string plain;
    cout << "Enter plain text: ";
    cin >> plain;

    int key;
    cout << "Enter key integer: ";
    cin >> key;

    string cipher = encode(plain, key);
    cout << "Cipher text is: " << cipher << "\n";

    string decipher = decode(cipher, key);
    cout << "Decipher text is: " << decipher << "\n";

    return 0;
}