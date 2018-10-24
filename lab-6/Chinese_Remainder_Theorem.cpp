#include <bits/stdc++.h>

using namespace std;

const int MX = 10;

int a[MX], m[MX], M[MX], invM[MX];

int gcdExtended(int a, int b, int *x, int *y) {
    if (a == 0) {
        *x = 0;
        *y = 1;
        return b;
    }
    int x1, y1;
    int g = gcdExtended(b % a, a, &x1, &y1);
    *x = y1 - (b / a) * x1;
    *y = x1;
    return g;
}

int mmi(int a, int mod) {
    int x, y;
    int g = gcdExtended(a, mod, &x, &y);
    int inv = (x % mod + mod) % mod;
    return inv;
}

int main() {
    int n;
    cout << "Enter number of congruences: ";
    cin >> n;

    cout << "\nEnter the congruences as (a, m):\n";
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> m[i];
    }

    int prod = 1;
    for (int i = 1; i <= n; i++) {
        prod *= m[i];
    }

    cout << "\nValue of product of m is:\n";
    cout << prod << "\n";

    for (int i = 1; i <= n; i++) {
        M[i] = prod / m[i];
    }

    cout << "\nValues of M[i] (prod / m[i]):\n";
    for (int i = 1; i <= n; i++) {
        cout << M[i] << " ";
    }
    cout << "\n";

    for (int i = 1; i <= n; i++) {
        invM[i] = mmi(M[i], m[i]);
    }

    cout << "\nValues of inverse of M[i] wrt m[i]:\n";
    for (int i = 1; i <= n; i++) {
        cout << invM[i] << " ";
    }
    cout << "\n";

    int x = 0;
    for (int i = 1; i <= n; i++) {
        x += a[i] * M[i] % prod * invM[i] % prod;
        x %= prod;
    }

    cout << "\nThe solution of the congruence is: " << x << "\n";

    return 0;
}