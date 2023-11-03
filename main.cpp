#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int N;
    int M;
    int a;
    int L, R;
    int min;
    int ans;
    vector<int> vec;

    cin >> N;
    cin >> M;

    for (int i = 0; i < N; ++i) {
        cin >> a;
        vec.push_back(a);
    }

    for (int j = 0; j < M; ++j) {
        cin >> L;
        cin >> R;
        min = vec[L];
        ans = -1;
        int k = L + 1;
        while (k <= R) {
            if (vec[k] > min) {
                ans = vec[k];
            }
            else if (vec[k] < min) {
                ans = min;
                min = vec[k];
            }
            ++k;
        }

        if (ans == -1) {
            cout << "NOT FOUND" << endl;
        }
        else {
            cout << ans << endl;
        }
    }
}
