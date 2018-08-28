#include <bits/stdc++.h>

using namespace std;

string encode(string plain, int block, int *perm) {
    int row = ceil(1.0 * plain.length() / block);
    int col = block;

    while ((int)plain.length() < row * col) {
        plain += 'X';
    }

    char res[row][col];
    for (int i = 0, k = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            res[i][j] = plain[k++];
        }
    }

    string cipher = "";
    for (int j = 0; j < col; j++) {
        for (int i = 0; i < row; i++) {
            cipher += res[i][perm[j]];
        }
    }
    
    return cipher;
}

string decode(string cipher, int block, int *perm) {
    int row = ceil(1.0 * cipher.length() / block);
    int col = block;

    int invPerm[block];
    for (int i = 0; i < block; i++) {
        invPerm[perm[i]] = i;
    }

    char res[row][col];
    for (int j = 0, k = 0; j < col; j++) {
        for (int i = 0; i < row; i++) {
            res[i][j] = cipher[k++];
        }
    }

    string plain;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            plain += res[i][invPerm[j]];
        }
    }

    return plain;
}

int main() {
    string plain;
    cout << "Enter plain text: ";
    cin >> plain;

    int block;
    cout << "Enter block size: ";
    cin >> block;
    int perm[block];

    cout << "Enter permutation key:\n";
    for (int i = 0; i < block; i++) {
        cout << i << " ";
    }
    cout << "\n";
    for (int i = 0; i < block; i++) {
        cin >> perm[i];
    }

    string cipher = encode(plain, block, perm);
    cout << "Cipher text is: " << cipher << "\n";

    string decipher = decode(cipher, block, perm);
    cout << "Decipher text is: " << decipher << "\n";

    return 0;
}