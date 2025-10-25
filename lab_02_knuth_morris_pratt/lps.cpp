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


void printLPS(string &pattern) {
    vector<int> lps = computeLPSArray(pattern);
    cout << "pattern: " << pattern << "\nLPS: ";

    for (int val : lps) {
        cout << val << " ";
    }

    cout << "\n\n";
}


int main() {
    string a = "abbbbc";
    string b = "abbbba";
    string c = "niekoniecznie";
    string d = "kajak";
    string e = "abrakadabra";
    string f = "onions";
    string g = "ananas";
    string h = "banan";
    string i = "matematyka";
    string j = "abababababb";
    string k = "01010101011";
    string l = "CCCCTCCAG";
    string m = "wydrze wydrzx wydrze wydrze wydrze wydrzx";

    printLPS(a);
    printLPS(b);
    printLPS(c);
    printLPS(d);
    printLPS(e);
    printLPS(f);
    printLPS(g);
    printLPS(h);
    printLPS(i);
    printLPS(j);
    printLPS(k);
    printLPS(l);
    printLPS(m);

    return 0;
}