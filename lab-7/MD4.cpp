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

string toBinary(string s) {
	string ans = "";
	for (int i = 0; i < (int)s.length(); i++) {
		int val = lower_bound(hexa, hexa + 16, s[i]) - hexa;
		string res = "";
		for (int j = 0; j < 4; j++) {
			if (val % 2) res += '1';
			else res += '0';
			val /= 2;
		}
		reverse(res.begin(), res.end());
		ans += res;
	}
	return ans;
}

string toHexa(string s) {
	string res = "";
	for (int i = 0; i < (int)s.length(); i += 4) {
		int val = 0;
		for (int j = i; j < i + 4; j++) {
			val = val * 2 + (s[j] - '0');
		}
		res += hexa[val];
	}
	return res;
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

string OR(string x, string y) {
	string res = "";
	for (int i = 0; i < (int)x.length(); i++) {
		int a = lower_bound(hexa, hexa + 16, x[i]) - hexa;
		int b = lower_bound(hexa, hexa + 16, y[i]) - hexa;
		res += hexa[a | b];
	}
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

string NOT(string s) {
	s = toBinary(s);
	string res = "";
	for (int i = 0; i < (int)s.length(); i++) {
		if (s[i] == '1') res += '0';
		else res += '1';
	}
	res = toHexa(res);
	return res;
}

string XOR(string x, string y, string z) {
	return XOR(x, XOR(y, z));
}

string MAJ(string x, string y, string z) {
	return XOR(AND(x, y), XOR(AND(x, z), AND(y, z)));
}

string IF(string x, string y, string z) {
	return OR(AND(x, y), AND(NOT(x), z));
}

string F(int rnd, string x, string y, string z) {
	if (rnd == 1) return XOR(x, y, z);
	if (rnd == 2) return MAJ(x, y, z);
	if (rnd == 3) return IF(x, y, z);
}

string SHIFT(string x, int cnt) {
	string res = "";
	x = toBinary(x);
	for (int i = 0; i < cnt; i++) {
		char t = x[0];
		for (int i = 1; i < (int)x.length(); i++) {
			res += x[i];
		}
		res += t;
		x = res;
		res = "";
	}
	x = toHexa(x);
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
	// msg = "76931FAC9DAB2B36C248B87D6AE33F9A62D71B3A5D5789E4B2D6B441E2411DC709E111C7E1E7ACB6FBCAC0BB2FC4C8BC2AE3BAAAB9165CC458E199CB89F51B13";
	cout << "Enter hexadecimal message: ";
	cin >> msg;
	
	msg = toBinary(msg);
	int len = msg.length();
	msg += '1';
	
	while ((int)msg.length() < 448) {
		msg += '0';
	}

	string lenBinary = "";
	for (int i = 0; i < 64; i++) {
		if (len % 2) lenBinary += '1';
		else lenBinary += '0';
		len /= 2;
	}	

	reverse(lenBinary.begin(), lenBinary.end());
	msg += lenBinary;
	msg = toHexa(msg);

	cout << "Message is: " << msg << "\n";
	
	string hash = computeHash(msg);
	cout << "The computed hash is: " << hash << "\n";
	
	return 0;
}

// acd18b60168c4a3478fe56517eb8070b
