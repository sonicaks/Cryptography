#include <bits/stdc++.h>

using namespace std;

void createList(string cipher, map<string, vector<int> > &repLetters) {
    for (int i = 0; i + 3 <= cipher.length(); i++) {
        string s = cipher.substr(i, 3);
        repLetters[s].push_back(i);
    }

    for (int i = 0; i + 4 <= cipher.length(); i++) {
         string s = cipher.substr(i, 4);
         repLetters[s].push_back(i);
    }
}

void printRepLetters(map<string, vector<int> > &repLetters) {
    int g = 0;
    for (auto it : repLetters) {
        if ((int)it.second.size() == 1) continue;
        cout << it.first << "\t->";
        int diff = -1;
        for (auto i : it.second) {
            cout << "\t" << i;
            if (diff == -1) diff = i;
            else diff = i - diff;
        }
        cout << "\t->\t" << diff << "\n";
        g = __gcd(diff, g);
    }
    cout << "Guessed block size is: " << g << "\n";
}

int main() {
    string cipher = "VHVSSPQUCEMRVBVBBBVHVSURQGIBDUGRNICJQUCERVUAXSSR";

    map<string, vector<int> > repLetters;
    createList(cipher, repLetters);

    printRepLetters(repLetters);

    return 0;
}