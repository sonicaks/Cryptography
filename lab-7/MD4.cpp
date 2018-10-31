#include <bits/stdc++.h>

using namespace std;

char hexa[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

string C[3] = {"00000000", "5A827999", "6ED9EBA1"};

int S[3][16] = {
	{3, 7, 11, 19, 3, 7, 11, 19, 3, 7, 11, 19, 3, 7, 11, 19},
	{3, 5, 9, 13, 3, 5, 9, 13, 3, 5, 9, 13, 3, 5, 9, 13},
	{3, 9, 11, 15, 3, 9, 11, 15, 3, 9, 11, 15, 3, 9, 11, 15}
};

string generate(int cnt) {
	string msg = "";
	for (int i = 0; i < cnt; i++) {
		msg += hexa[rand() % 16];
	}
	return msg;
}

string ADD(string x, string y) {
	int carry = 0;
	reverse(x.begin(), x.end());
	reverse(y.begin(), y.end());
	string res = "";
	for (int i = 0; i < (int)x.length(); i++) {
		int a = lower_bound(hexa, hexa + 16, x[i]) - hexa;
		int b = lower_bound(hexa, hexa + 16, y[i]) - hexa;
		int sum = a + b + carry;
		int carry = sum / 16;
		res += hexa[sum % 16];
	}
	reverse(res.begin(), res.end());
	return res;
}

string AND(string x, string y) {
	string res = "";
	for (int i = 0; i < (int)x.length(); i++) {
		int a = lower_bound(hexa, hexa + 16, x[i]) - hexa;
		int b = lower_bound(hexa, hexa + 16, y[i]) - hexa;
		res += hexa[a & b];
	}
	return res;
}

string XOR(string x, string y) {
	string res = "";
	for (int i = 0; i < (int)x.length(); i++) {
		int a = lower_bound(hexa, hexa + 16, x[i]) - hexa;
		int b = lower_bound(hexa, hexa + 16, y[i]) - hexa;
		res += hexa[a ^ b];
	}
	return res;
}

string XOR(string x, string y, string z) {
	return XOR(x, XOR(y, z));
}

string MAJ(string x, string y, string z) {
	return XOR(AND(x, y), XOR(AND(x, z), AND(y, z)));
}

string IF(string x, string y, string z) {
	return XOR(AND(x, y), XOR(AND(x, z), z));
}

string F(int rnd, string x, string y, string z) {
	if (rnd == 1) return XOR(x, y, z);
	if (rnd == 2) return MAJ(x, y, z);
	if (rnd == 3) return IF(x, y, z);
}

string SHIFT(string x, int cnt) {
	string res = "";
	for (int i = 0; i < cnt; i++) {
		char t = x[0];
		for (int i = 1; i < (int)x.length(); i++) {
			res += x[i];
		}
		res += t;
		x = res;
		res = "";
	}
	return x;
}

string computeHash(string msg) {
	string hash = "";
	string reg[4]; // 0 = a(i - 4), 1 = a(i - 1), 2 = a(i - 2), 3 = a(i - 3)
	reg[0] = "67452301";
	reg[1] = "EFCDAB89";
	reg[2] = "98BADCFE";
	reg[3] = "10325476";
	for (int rnd = 1; rnd <= 3; rnd++) {
		for (int m = 0, cnt = 0; m < 128; m += 8, cnt++) {
			string word = "";
			for (int i = m; i < m + 8; i++) {
				word += msg[i];
			}
			string nxtReg[4];
			nxtReg[0] = reg[3];
			nxtReg[1] = ADD(reg[0], F(rnd, reg[1], reg[2], reg[3]));
			nxtReg[1] = ADD(nxtReg[1], word);
			nxtReg[1] = ADD(nxtReg[1], C[rnd - 1]);
			nxtReg[1] = SHIFT(nxtReg[1], S[rnd - 1][cnt]);
			nxtReg[2] = reg[1];
			nxtReg[3] = reg[2];
			for (int i = 0; i < 4; i++) {
				reg[i] = nxtReg[i];
			}
		}
	}
	for (int i = 0; i < 4; i++) {
		hash += reg[i];
	}
	return hash;
}

int main() {
	string msg;
	msg = generate(128);
	cout << "Generated message (512 / 4 bits): " << msg << "\n";
	
	string hash = computeHash(msg);
	cout << "The computed hash is: " << hash << "\n";
	
	return 0;
}
