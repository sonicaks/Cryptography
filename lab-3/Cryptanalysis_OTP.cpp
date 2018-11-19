#include <bits/stdc++.h>

using namespace std;

int toDecimal(string s) {
    int val = 0;
    for (int i = 0; i < (int)s.length(); i++) {
        val = 2 * val + (s[i] - '0');
    }
    return val;
}

int mmi(int n) {
    n %= 26;
    if (n < 0) n += 26;
    for (int i = 0; i < 26; i++) {
        if (n * i % 26 == 1) return i;
    }
    return 1;
}

string toBinary(int n) {
    string res = "";
    for (int i = 0; i < 5; i++) {
        if ((1 << i) & n) res += '1';
        else res += '0';
    }
    reverse(res.begin(), res.end());
    return res;
}

string computeXor(string a, string b) {
    string res = "";
    for (int i = 0; i < 5; i++) {
        int x = a[i] - '0';
        int y = b[i] - '0';
        res += (char)(x ^ y + '0');
    }
    return res;
}

pair<int, int> computeAB(int S[]) {
    // S0
    // S1 = A * S0 + B mod 26
    // S2 = A * S1 + B mod 26
    // A = (S1 - S2) * mmi(S0 - S1) mod 26
    // B = S1 - A * S0 mod 26
    int A = ((S[1] - S[2]) % 26 + 26) * mmi(S[0] - S[1]) % 26;
    int B = ((S[1] - A * S[0]) % 26 + 26) % 26;
    return make_pair(A, B);
}

string encode(string plain, int S[]) {
    string cipher = "";
    for (int i = 0, l = 0; i < 15; i += 5, l++) {
        string p = "";
        for (int j = i; j < i + 5; j++) {
            p += plain[j];
        }
        string k = toBinary(S[l]);
        cipher += computeXor(p, k);
    }
    return cipher;
}

int main() {
    string plain;
    cout << "Enter plain text (binary 16 bit):\t";
    cin >> plain;

    string cipher;
    cout << "Enter cipher text (binary 16 bit):\t";
    cin >> cipher;

    string key = "";
    for (int i = 0; i < 15; i++) {
        int p = plain[i] - '0';
        int c = cipher[i] - '0';
        key += (char)(p ^ c + '0');
    }
    cout << "Key is:\t\t\t" << key << "\n";

    int S[3];
    for (int i = 0, k = 0; i < 15; i += 5, k++) {
        string s = "";
        for (int j = i; j < i + 5; j++) {
            s += key[j];
        }
        S[k] = toDecimal(s);
    }

    cout << "Key in decimal is:\t";
    for (int i = 0; i < 3; i++) {
        cout << S[i] << " ";
    }
    cout << "\n";

    int A, B;
    pair<int, int> res = computeAB(S);
    A = res.first;
    B = res.second;

    cout << "Values of S0, A, B are: " << S[0] << " " << A << " " << B << "\n";

    string encoded = encode(plain, S);
    cout << "Cipher text is:\t\t" << encoded << "\n";

    return 0;
}