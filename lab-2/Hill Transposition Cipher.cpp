#include <bits/stdc++.h>

using namespace std;

void mul(int *a, int *b, int *c, int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            for (int k = 0; k < col; k++) {
                int x = *((a + i * col) + k);
                int y = *((b + k * col) + j);
                *((c + i * col) + j) += x * y;
            }
        }
    }
}

string encode(string plain, int block, int *perm) {
    int row = ceil(1.0 * plain.length() / block);
    int col = block;

    while ((int)plain.length() < row * col) {
        plain += 'X';
    }

    int permMat[col][col];
    for (int i = 0; i < col; i++) {
        for (int j = 0; j < col; j++) {
            permMat[i][j] = 0;
        }
        permMat[i][perm[i]] = 1;
    }

    int res[row][col];
    for (int i = 0, k = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            res[i][j] = plain[k++] - 'A';
        }
    }

    int prod[row][col];
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            prod[i][j] = 0;
        }
    }
    mul((int *)res, (int *)permMat, (int *)prod, row, col);

    string cipher = "";
    for (int j = 0; j < col; j++) {
        for (int i = 0; i < row; i++) {
            cipher += (char)(prod[i][j] + 'A');
        }
    }

    return cipher;
}

string decode(string cipher, int block, int *perm) {
    int row = ceil(1.0 * cipher.length() / block);
    int col = block;

    int invPermMat[col][col];
    for (int i = 0; i < col; i++) {
        for (int j = 0; j < col; j++) {
            invPermMat[i][j] = 0;
        }
    }
    for (int i = 0; i < col; i++) {
        invPermMat[perm[i]][i] = 1;
    }

    int res[row][col];
    for (int j = 0, k = 0; j < col; j++) {
        for (int i = 0; i < row; i++) {
            res[i][j] = cipher[k++] - 'A';
        }
    }

    int prod[row][col];
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            prod[i][j] = 0;
        }
    }
    mul((int *)res, (int *)invPermMat, (int *)prod, row, col);

    string plain = "";
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            plain += (char)(prod[i][j] + 'A');
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