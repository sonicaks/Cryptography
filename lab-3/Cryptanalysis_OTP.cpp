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

int main() {
    string plain;
    cout << "Enter plain text: ";
    cin >> plain;

    int S[3];
    for (int i = 0, k = 0; i < 15; i += 5, k++) {
        string s = "";
        for (int j = i; j < i + 5; j++) {
            s += plain[j];
        }
        S[k] = toDecimal(s);
    }

    int A, B;
    pair<int, int> res = computeAB(S);
    A = res.first;
    B = res.second;

    cout << "Values of S0, A, B are: " << S[0] << " " << A << " " << B << "\n";

    // cout << S[0] << " " << (S[0] * A + B) % 26 << " " << (S[1] * A + B) % 26 << "\n";

    // cout << S[0] << " " << S[1] << " " << S[2] << "\n";

    return 0;
}