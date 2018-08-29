#include <bits/stdc++.h>

using namespace std;

string decode(string cipher, int key) {
    string plain = "";
    for (int i = 0; i < cipher.length(); i++) {
        int c = cipher[i] - 'A';
        int k = key;
        if (i >= 1) k = plain[i - 1] - 'A';
        plain += (char)(((c - k) % 26 + 26) % 26 + 'A');
    }
    
    return plain;
}

int main() {
    string cipher = "UTMTCMSALHBVONA";

    for (int k = 0; k < 26; k++) {
        string decipher = decode(cipher, k);
        cout << decipher << " " << k << "\n";
    }

    return 0;
}