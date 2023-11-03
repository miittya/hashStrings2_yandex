#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int a, b, c, d, m, n;
    cin >> a >> b >> c >> d;
    m = a*d + b*c;
    n = b*d;
    int max = (m>n) ? m : n;
    for (int i = max; i > 0; --i) {
        if (m%i == 0 && n%i == 0) {
            m/=i;
            n/=i;
        }
    }
    cout << m << " " << n;
}
