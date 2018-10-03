#include <bits/stdc++.h>

using namespace std;

char hexa[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
int expPerm[49] = {0,
                    32, 1, 2, 3, 4, 5,
                    4, 5, 6, 7, 8, 9,
                    8, 9, 10, 11, 12, 13,
                    12, 13, 14, 15, 16, 17,
                    16, 17, 18, 19, 20, 21,
                    20, 21, 22, 23, 24, 25,
                    24, 25, 26, 27, 28, 29,
                    28, 29, 30, 31, 32, 1
                };

int compPerm[33] = {0,
                    16, 7, 20, 21, 29, 12, 28, 17,
                    1, 15, 23, 26, 5, 18, 31, 10,
                    2, 8, 24, 14, 32, 27, 3, 9,
                    19, 13, 30, 6, 22, 11, 4, 25
                };

string generateKey(int n) {
    string res = "";
    for (int i = 0; i < n; i++) {
        res += hexa[rand() % 16];
    }
    return res;
}

pair<string, string> split(string s) {
    int n = (int)s.length();
    pair<string, string> res;
    res.first = res.second = "";
    for (int i = 0; i < n / 2; i++) {
        res.first += s[i];
    }
    for (int i = n / 2; i < n; i++) {
        res.second += s[i];
    }
    return res;
}

void shiftLeft(string s) {
    int n = (int)s.length();
    char ch = s[0];
    for (int i = 0; i < n - 1; i++) {
        s[i] = s[i + 1];
    }
    s[n - 1] = ch;
}

string compressionPBOX(string s) {
    int n = (int)s.length();
    string res = "";
    for (int i = 0; i < n; i++) {
        res += s[compPerm[i] - 1];
    }
}

string expansionPBOX(string s) {
    int n = (int)s.length();
    string res = "";
    for (int i = 0; i < n; i++) {
        res += s[expPerm[i] - 1];
    }
    return res;
}

string SBOX(string s) {
    
}

vector<string> generateRoundKey(string key) {
    int n = (int)key.length();
    vector<string> res;
    pair<string, string> splt = split(key);
    string left = splt.first, right = splt.second;
    for (int rnd = 0; rnd < 16; rnd++) {
        shiftLeft(left);
        shiftLeft(right);
        res.push_back(compressionPBOX(left + right));
    }
    return res;
}

string XOR(string a, string b) {
    int n = a.length();
    string res = "";
    for (int i = 0; i < n; i++) {
        int x = lower_bound(hexa, hexa + 16, a[i]) - hexa;
        int y = lower_bound(hexa, hexa + 16, b[i]) - hexa;
        res += hexa[x ^ y];
    }
    return res;
}

string f(string val, string key) {
    string res = val;
    res = expansionPBOX(res);
    res = XOR(res, key);
    res = SBOX(res);
    // res = straightPBOX(res);
    return res;
}

string encode(string plain, vector<string> roundKey) {
    string cipher = plain;
    for (int rnd = 0; rnd < 16; rnd++) {
        pair<string, string> splt = split(cipher);
        string left = splt.first, right = splt.second;
        string nxtLeft = XOR(left, f(right, roundKey[rnd]));
        string nxtRight = right;
        cipher = nxtLeft + nxtRight;
    }
    return cipher;
}

int main() {
    string plain;
    cout << "Enter plain text:\t";
    cin >> plain;

    string key = generateKey(14);
    cout << "Generated key is:\t" << key << "\n";

    vector<string> roundKey = generateRoundKey(key);

    string cipher = encode(plain, roundKey);
    cout << "Cipher text is:\t\t" << cipher << "\n";

    return 0;
}