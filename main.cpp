#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void read (int& N, int& a, vector<int>& vec, vector<int>& temp){
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> a;
        vec.push_back(a);
        temp.push_back(a);
    }
}

void merge(vector<int>& vec, vector<int>& temp, int l, int m, int r) {
    int i = l;
    int k = l;
    int j = m + 1;

    while (i < m + 1 && j < r + 1) {
        if (vec[i] < vec[j]) {
            temp[k] = vec[i];
            i++;
            k++;
        } else {
            temp[k] = vec[j];
            j++;
            k++;
        }
    }

    while (i < m + 1) {
        temp[k] = vec[i];
        i++;
        k++;
    }

    for (int n = l; n <= r; ++n) {
        vec[n] = temp[n];
    }
}

void mergeSort(vector<int>& vec, vector<int>& temp, int l, int r) {
    if (l < r) {
        int m = floor((r + l)/2);
        mergeSort(vec, temp, l, m);
        mergeSort(vec, temp, m + 1, r);
        merge(vec, temp, l, m, r);
    }
}

int main () {
    int N;
    int a;
    vector<int> vec;
    vector<int> temp;
    read(N, a, vec, temp);
    mergeSort(vec, temp, 0, vec.size()-1);

    for (int i = 0; i < N; ++i) {
        cout << vec[i] << " ";
    }

    return 0;
}
