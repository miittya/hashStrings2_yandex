#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

int Partition (vector<int>& vec, int l, int r) {
    int x = vec[r];
    int L = l - 1;
    int R = r + 1;
    while (1) {
        do {
            L++;
        } while (vec[L] < x);
        do {
            R--;
        } while (vec[R] > x);
        if (L >= R) {
            return R;
        }
        swap(vec[L], vec[R]);
    }
}

int randomizedPartition(vector<int>& vec, int l, int r)
{
    int pivotIndex = rand() % (r - l + 1) + l;

    swap(vec[pivotIndex], vec[r]);

    return Partition(vec, l, r);
}

void quickSort(vector<int>& vec, int l, int r) {
    if (l < r) {
        int p = randomizedPartition(vec, l, r);
        quickSort(vec, l, p);
        quickSort(vec, p + 1, r);
    }
}

int main() {
    int N, a;
    vector<int> vec;
    cin >> N;

    for (int i = 0; i < N; ++i) {
        cin >> a;
        vec.push_back(a);
    }

    quickSort(vec, 0, N - 1);
    for (int i = 0; i < N; ++i) {
        cout << vec[i] << " ";
    }

    return 0;
}
