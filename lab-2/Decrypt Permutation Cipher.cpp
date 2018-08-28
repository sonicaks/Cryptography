#include <bits/stdc++.h>

using namespace std;

string decode(string cipher, int block, int *perm) {
    int row = ceil(1.0 * cipher.length() / block);
    int col = block;

    int invPerm[block];
    for (int i = 0; i < block; i++) {
        invPerm[perm[i]] = i;
    }

    char res[row][col];
    for (int i = 0, k = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
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
    string cipher = "TGEEMNELNNTDROEOAAHDOETCSHAEIRLM";
    int block = 8;
    int perm[8] = {3, 0, 5, 1, 6, 2, 7, 4};

    string decipher = decode(cipher, block, perm);
    cout << "Decipher text is: " << decipher << "\n";

    return 0;
}