#include <bits/stdc++.h>

using namespace std;

char hexa[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

int expPerm_32_48[48] = {
                            32, 1, 2, 3, 4, 5,
                            4, 5, 6, 7, 8, 9,
                            8, 9, 10, 11, 12, 13,
                            12, 13, 14, 15, 16, 17,
                            16, 17, 18, 19, 20, 21,
                            20, 21, 22, 23, 24, 25,
                            24, 25, 26, 27, 28, 29,
                            28, 29, 30, 31, 32, 1
                        };

int strPerm[32] = {
                        16, 7, 20, 21, 29, 12, 28, 17,
                        1, 15, 23, 26, 5, 18, 31, 10,
                        2, 8, 24, 14, 32, 27, 3, 9,
                        19, 13, 30, 6, 22, 11, 4, 25
                };

int parDrop_64_56[56] = {
                            57, 49, 41, 33, 25, 17, 9, 1,
                            58, 50, 42, 34, 26, 18, 10, 2,
                            59, 51, 43, 35, 27, 19, 11, 3,
                            60, 52, 44, 36, 63, 55, 47, 39,
                            31, 23, 15, 7, 62, 54, 46, 38,
                            30, 22, 14, 6, 61, 53, 45, 37,
                            29, 21, 13, 5, 28, 20, 12, 4
                        };

int compPerm_56_48[48] = {
                            14, 17, 11, 24, 1, 5, 3, 28,
                            15, 6, 21, 10, 23, 19, 12, 4,
                            26, 8, 16, 7, 27, 20, 13, 2,
                            41, 52, 31, 37, 47, 55, 30, 40,
                            51, 45, 33, 48, 44, 49, 39, 56,
                            34, 53, 46, 42, 50, 36, 29, 32
                        };

int sPerm_6_4[8][4][16] = {
                            {
                                {14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7},
                                {0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8},
                                {4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0},
                                {15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13}
                            },
                            {
                                {15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0, 5, 10},
                                {3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5},
                                {0, 14, 7, 11, 10, 4, 13, 1, 5, 8, 12, 6, 9, 3, 2, 15},
                                {13, 8, 10, 1, 3, 15, 4, 2, 11, 6, 7, 12, 0, 5, 14, 9}
                            },
                            {
                                {10, 0, 9, 14, 6, 3, 15, 5, 1, 13, 12, 7, 11, 4, 2, 8},
                                {13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1},
                                {13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12, 5, 10, 14, 7},
                                {1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12}
                            },
                            {
                                {7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15},
                                {13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9},
                                {10, 6, 9, 0, 12, 11, 7, 13, 15, 1, 3, 14, 5, 2, 8, 4},
                                {3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14}
                            },
                            {
                                {2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9},
                                {14, 11, 2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6},
                                {4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14},
                                {11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3}
                            },
                            {
                                {12, 1, 10, 15, 9, 2, 6, 8, 0, 13, 3, 4, 14, 7, 5, 11},
                                {10, 15, 4, 2, 7, 12, 9, 5, 6, 1, 13, 14, 0, 11, 3, 8},
                                {9, 14, 15, 5, 2, 8, 12, 3, 7, 0, 4, 10, 1, 13, 11, 6},
                                {4, 3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 7, 6, 0, 8, 13}
                            },
                            {
                                {4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1},
                                {13, 0, 11, 7, 4, 9, 1, 10, 14, 3, 5, 12, 2, 15, 8, 6},
                                {1, 4, 11, 13, 12, 3, 7, 14, 10, 15, 6, 8, 0, 5, 9, 2},
                                {6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15, 14, 2, 3, 12}
                            },
                            {
                                {13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3, 14, 5, 0, 12, 7},
                                {1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11, 0, 14, 9, 2},
                                {7, 11, 4, 1, 9, 12, 14, 2, 0, 6, 10, 13, 15, 3, 5, 8},
                                {2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 0, 3, 5, 6, 11}
                            }
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

string binary(int n) {
    string res = "";
    for (int i = 0; i < 4; i++) {
        res += to_string(n % 2);
        n /= 2;
    }
    reverse(res.begin(), res.end());
    return res;
}

string toBinary(string s) {
    int n = (int)s.length();
    string res = "";
    for (int i = 0; i < n; i++) {
        int idx = lower_bound(hexa, hexa + 16, s[i]) - hexa;
        res += binary(idx);
    }
    return res;
}

char hexad(string s) {
    int n = (int)s.length();
    int res = 0;
    for (int i = 0; i < n; i++) {
        res = res * 2 + (s[i] - '0');
    }
    return hexa[res];
}

string toHexa(string s) {
    int n = (int)s.length();
    string res = "";
    for (int i = 0; i < n; i += 4) {
        string val = "";
        for (int j = i; j < i + 4; j++) {
            val += s[j];
        }
        res += hexad(val);
    }
    return res;
}

int toDecimal(string s) {
    int n = (int)s.length();
    int res = 0;
    for (int i = 0; i < n; i++) {
        res = res * 2 + (s[i] - '0');
    }
    return res;
}

string parityDrop(string key) {
    key = toBinary(key);
    string res = "";
    for (int i = 0; i < 56; i++) {
        res += key[parDrop_64_56[i] - 1];
    }
    res = toHexa(res);
    return res;
}

void shiftLeft(string &s) {
    s = toBinary(s);
    int n = (int)s.length();
    char ch = s[0];
    for (int i = 0; i < n - 1; i++) {
        s[i] = s[i + 1];
    }
    s[n - 1] = ch;
    s = toHexa(s);
}

string straightPBOX(string s) {
    s = toBinary(s);
    string res = "";
    for (int i = 0; i < 32; i++) {
        res += s[strPerm[i] - 1];
    }
    res = toHexa(res);
    return res;
}

string compressionPBOX_56_48(string s) {
    s = toBinary(s);
    string res = "";
    for (int i = 0; i < 48; i++) {
        res += s[compPerm_56_48[i] - 1];
    }
    res = toHexa(res);
    return res;
}

string expansionPBOX_32_48(string s) {
    s = toBinary(s);
    string res = "";
    for (int i = 0; i < 48; i++) {
        res += s[expPerm_32_48[i] - 1];
    }
    res = toHexa(res);
    return res;
}

vector<string> generateRoundKey(string key) {
    key = parityDrop(key);
    int n = (int)key.length();
    vector<string> res;
        pair<string, string> splt = split(key);
    string left = splt.first, right = splt.second;
    for (int rnd = 0; rnd < 16; rnd++) {
        if (rnd == 0 or rnd == 1 or rnd == 8 or rnd == 15) {
            shiftLeft(left);
            shiftLeft(right);
        } else {
            shiftLeft(left);
            shiftLeft(left);
            shiftLeft(right);
            shiftLeft(right);
        }
        res.push_back(compressionPBOX_56_48(left + right));
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

string SBOX(string s) {
    s = toBinary(s);
    int n = (int)s.length();
    string res = "";
    for (int i = 0, j = 0; i < n; i += 6, j++) {
        string p = "", q = "";
        p += s[i];
        p += s[i + 5];
        for (int k = 1; k <= 4; k++) {
            q += s[i + k];
        }
        int x = toDecimal(p);
        int y = toDecimal(q);
        int val = sPerm_6_4[j][x][y];
        res += hexa[val];
    }
    return res;
}

string f(string val, string key) {
    string res = val;
    res = expansionPBOX_32_48(res);
    res = XOR(res, key);
    res = SBOX(res);
    res = straightPBOX(res);
    return res;
}

string encode(string plain, vector<string> roundKey) {
    string cipher = plain;
    for (int rnd = 0; rnd < 16; rnd++) {
        pair<string, string> splt = split(cipher);
        string left = splt.first, right = splt.second;
        string nxtLeft = XOR(left, f(right, roundKey[rnd]));
        string nxtRight = right;
        if (rnd != 15) swap(nxtLeft, nxtRight);
        cout << nxtLeft << "\t" << nxtRight << "\t" << roundKey[rnd] << "\n";
        cipher = nxtLeft + nxtRight;
    }
    return cipher;
}

string decode(string cipher, vector<string> roundKey) {
    string plain = cipher;
    for (int rnd = 15; rnd >= 0; rnd--) {
        pair<string, string> splt = split(plain);
        string left = splt.first, right = splt.second;
        string nxtLeft = XOR(left, f(right, roundKey[rnd]));
        string nxtRight = right;
        if (rnd != 0) swap(nxtLeft, nxtRight);
        cout << nxtLeft << "\t" << nxtRight << "\t" << roundKey[rnd] << "\n";
        plain = nxtLeft + nxtRight;
    }
    return plain;
}

int main() {
    string plain;
    cout << "Enter plain text:\t";
    cin >> plain;

    string key = generateKey(14);
    key = "AABB09182736CCDD";
    cout << "Generated key is:\t" << key << "\n";

    vector<string> roundKey = generateRoundKey(key);

    cout << "\n**********ENCODING**********\n\n";
    string cipher = encode(plain, roundKey);
    cout << "Cipher text is:\t\t" << cipher << "\n";

    cout << "\n**********DECODING**********\n\n";
    string decipher = decode(cipher, roundKey);
    cout << "Decipher text is:\t" << decipher << "\n";

    return 0;
}