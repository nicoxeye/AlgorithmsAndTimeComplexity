#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> computeLPSArray(string &pattern){
    int n = pattern.size();
    vector<int> lps(n, 0);

    int len = 0;
    int i = 1;

    while (i<n) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

void search(string &pattern, string &text) {
    int n = text.length();
    int m = pattern.length();

    vector<int> lps = computeLPSArray(pattern);

    int i = 0;
    int j = 0;

    while (i < n) {

        if (text[i] == pattern[j]){
            i++;
            j++;
        } else {
            if (j != 0){
                j = lps[j - 1];
            } else {
                i++;
            }
        }

        if (j == m) {
            cout << "pattern found at inx: " << i - j << endl;
            j = lps[j - 1];
        }

    }
}

int main() {
    string txt = "aabaacaadaabaaba";
    string pat = "aaba";

    search(pat, txt);

    return 0;
}