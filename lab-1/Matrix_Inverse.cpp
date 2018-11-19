#include <bits/stdc++.h>

using namespace std;

#define N 3

void getCofactor(int A[N][N], int temp[N][N], int p, int q, int n) {
	int i = 0, j = 0;
	for (int r = 0; r < n; r++) {
		for (int c = 0; c < n; c++) {
			if (r != p and c != q) {
				temp[i][j++] = A[r][c];
				if (j == n - 1) {
					j = 0;
					i++;
				}
			}
		}
	}
}

int determinant(int A[N][N], int n) {
	int D = 0;
	if (n == 1) return A[0][0];
	int temp[N][N];
	int sign = 1;
	for (int f = 0; f < n; f++) {
		getCofactor(A, temp, 0, f, n);
		D += sign * A[0][f] * determinant(temp, n - 1);
		sign -= sign;
	}
	return D;
}

void adjoint(int A[N][N], int adj[N][N]) {
	if(N == 1) {
		adj[0][0] = 1;
		return;
	}
	int sign = 1, temp[N][N];
	for (int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			getCofactor(A, temp, i, j, N);
			sign = ((i + j) % 2 == 0) ? 1 : -1;
			adj[j][i] = (sign) * (determinant(temp, N - 1));
		}
	}
}

bool inverse(int A[N][N], double inverse[N][N]) {
	int det = determinant(A, N);
	if(det == 0) {
		cout << "Singular matrix, Inverse not exists\n";
		return false;
	}
	int adj[N][N];
	adjoint(A, adj);
	for (int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			inverse[i][j] = adj[i][j] / (double)det;
		}
	}
	return true;
}

template<class T>
void display(T A[N][N])
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << A[i][j] << " ";
		}
		cout << "\n";
	}
}

int main() {
	int A[N][N] =
				{
					{4, 5, 6},
					{6, 5, 4},
					{4, 6, 5}
				};
	//To store adjoint of A[][]
	int adj[N][N];
	//To store inverse of A[][]
	double inv[N][N];
	cout << "Input Matrix is :\n";
	display(A);

	cout << "\nThe Adjoint is :\n";
	adjoint(A,adj);
	display(adj);

	cout << "\nThe Inverse is :\n";
	if(inverse(A, inv)) display(inv);

	return 0;
}
