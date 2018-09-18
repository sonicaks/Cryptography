#include <bits/stdc++.h>

using namespace std;

char hexa[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
char subs[16] = {'E', '4', 'D', '1', '2', 'F', 'B', '8', '3', 'A', '6', 'C', '5', '9', '0', '7'};
char invSubs[16] = {'E', '3', '4', '8', '1', 'C', 'A', 'F', '7', 'D', '9', '6', 'B', '2', '0', '5'};
int perm[8] = {0, 3, 4, 6, 2, 5, 1, 7};
int invPerm[8] = {0, 6, 4, 1, 2, 5, 3, 7};

string generate(int n) {
    string res = "";
    for (int i = 0; i < n; i++) {
        int p = rand() % 16;
        res += hexa[p];
    }
    return res;
}

string XOR(string x, string y) {
    int n = (int)x.length();
    string res = "";
    for (int i = 0; i < n; i++) {
        int a = lower_bound(hexa, hexa + 16, x[i]) - hexa;
        int b = lower_bound(hexa, hexa + 16, y[i]) - hexa;
        res += hexa[a ^ b];
    }
    return res;
}

string SBOX(string x) {
    int n = (int)x.length();
    string res = "";
    for (int i = 0; i < n; i++) {
        int c = lower_bound(hexa, hexa + 16, x[i]) - hexa;
        res += subs[c];
    }
    return res;
}

string PBOX(string x) {
    int n = (int)x.length();
    string res = "";
    for (int i = 0; i < n; i++) {
        res += x[perm[i]];
    }
    return res;
}

string invSBOX(string x) {
    int n = (int)x.length();
    string res = "";
    for (int i = 0; i < n; i++) {
        int c = lower_bound(hexa, hexa + 16, x[i]) - hexa;
        res += invSubs[c];
    }
    return res;
}

string invPBOX(string x) {
    int n = (int)x.length();
    string res = "";
    for (int i = 0; i < n; i++) {
        res += x[invPerm[i]];
    }
    return res;
}

string encode(string plain, string key) {
    string cipher = plain;
    for (int r = 1; r <= 4; r++) {
        string roundKey = "";
        for (int i = 4 * r - 3 - 1; i < 4 * r + 4; i++) {
            roundKey += key[i];
        }
        cipher = XOR(cipher, roundKey);
        cipher = SBOX(cipher);
        if (r != 4) cipher = PBOX(cipher);
    }
    return cipher;
}

string decode(string cipher, string key) {
    string plain = cipher;
    for (int r = 4; r >= 1; r--) {
        string roundKey = "";
        for (int i = 4 * r - 3 - 1; i < 4 * r + 4; i++) {
            roundKey += key[i];
        }
        if (r != 4) plain = invPBOX(plain);
        plain = invSBOX(plain);
        plain = XOR(plain, roundKey);
    }
    return plain;
}

int main() {
    string plain;
    // Plain text entered should be of 8 bits in hexadecimal
    // Eg: ABCD123E
    cout << "Enter plain text:\t";
    cin >> plain;

    string key = generate(24);

    string cipher = encode(plain, key);
    cout << "Encoded text is:\t" << cipher << "\n";

    string decipher = decode(cipher, key);
    cout << "Decoded text is:\t" << decipher << "\n";

    return 0;
}