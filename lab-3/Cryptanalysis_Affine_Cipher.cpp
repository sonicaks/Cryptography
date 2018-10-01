#include <bits/stdc++.h>

using namespace std;

int mmi(int n) {
    n %= 26;
    if (n < 0) n += 26;
    for (int i = 0; i < 26; i++) {
        if (n * i % 26 == 1) {
            return i;
        }
    }
    return 0;
}

string decode(string cipher, int k1, int k2) {
    string plain = "";
    int inv = mmi(k1);
    for (int i = 0; i < cipher.length(); i++) {
        int c = cipher[i] - 'A';
        int p = (c - k2) * inv % 26;
        if (p < 0) p += 26;
        plain += (char)(p + 'A');
    }
    return plain;
}

int main() {
    // string cipher = "XXXXGGXXXXGGXXXXGGXXXXGGXXXXGGXXXXGGXXXXGGXXXXGGXXXXGGXXXXGGXXXXGGXXXXGGXXXXGGXXXXGGXXXXGGXXXXGGXXXXGGXXXXGGXXXXGGXXXXGG";

    string cipher = "KQEREJEBCPPCJCRKIEACUZBKRVPKRBCIBQCARBJCVFCUPKRIOFKPACUZQEPBKRXPEIIEABDKPBCPFCDCCAFIEABDKPBCPPFEQPKAZBKRHAIBKAPCCIBURCCDKDCCJCIDFUIXPAFFERBICZDFKABICBBENEFCUPJCVKABPCYDCCDPKBCOCPERKIVKSCPICBRKIJPKABI";

    int freq[26] = {0};
    for (int i = 0; i < cipher.length(); i++) {
        freq[cipher[i] - 'A']++;
    }

    vector<pair<int, int> > v;
    for (int i = 0; i < 26; i++) {
        v.push_back(make_pair(freq[i], i));
    }
    sort(v.rbegin(), v.rend());
    
    for (int i = 1; i <= 2; i++) {
        int r = v[0].second;
        int s = v[i].second;
        int p = 4; // E
        int q = 19; // T
        int k1 = mmi(p - q) * (r - s) % 26;
        if (k1 < 0) k1 += 26;
        int k2 = mmi(p - q) * (p * s - q * r) % 26;
        if (k2 < 0) k2 += 26;
        if (mmi(k1)) {
            cout << k1 << "\t" << k2 << "\t" << decode(cipher, k1, k2) << "\n";
        }
    }

    return 0;
}