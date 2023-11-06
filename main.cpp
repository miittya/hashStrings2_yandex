#include <iostream>
#include <string>
#include <cmath>
using namespace std;

const int x_ = 257;
const int p = pow(10,9) + 7;

bool isEqual (long from1, long from2, long slen, long* h, long* x) {
    return ((h[from1 + slen - 1] + h[from2 - 1] * x[slen]) % p ==
            (h[from2 + slen - 1] + h[from1 - 1] * x[slen]) % p
    );
}

int main() {
    string str;
    getline(cin, str);

    long n = str.size();
    long* h = new long[n + 1];
    long* x = new long[n + 1];
    h[0] = 0;
    x[0] = 1;
    str = ' ' + str;
    for (int i = 1; i < n + 1; ++i) {
        h[i] = (h[i - 1] * x_ + int(str[i]) - 96) % p;
        x[i] = (x[i - 1] * x_) % p;
    }

    int i = 2;
    int L = str.size() - 2;

    while (i <= str.size()) {
        if (isEqual(1, i, L, h, x)) {
            cout << i - 1;
            return 0;
        }
        i++;
        L--;
    }

    return 0;
}