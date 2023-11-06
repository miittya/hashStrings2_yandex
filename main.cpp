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
    //объявления переменных и чтение из консоли
    string str;
    getline(cin, str);
    long Q, L, A, B;
    long n = str.size();
    long* h = new long[n + 1];
    long* x = new long[n + 1];
    h[0] = 0;
    x[0] = 1;
    cin >> Q;
    str = ' ' + str;

    //заполнение массивов
    for (int i = 1; i < n + 1; ++i) {
        h[i] = (h[i - 1] * x_ + int(str[i]) - 96) % p;
        x[i] = (x[i - 1] * x_) % p;
    }

    for (int i = 0; i < Q; ++i) {
        cin >> L >> A >> B;
        if (isEqual(A + 1, B + 1, L, h, x)) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }

    }
}