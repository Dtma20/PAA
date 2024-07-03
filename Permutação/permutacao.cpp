#include<bits/stdc++.h>
using namespace std;

void permutacao(vector<int> &v, int i) {
    if (i == v.size()) {
        for (int j = 0; j < v.size(); j++) {
            cout << v[j] << " ";
        }
        cout << endl;
        return;
    }
    for (int j = i; j < v.size(); j++) {
        swap(v[i], v[j]);
        permutacao(v, i + 1);
        swap(v[i], v[j]);
    }
}

int main() {
    vector<int> a(4);
    a = {1, 2, 3};
    permutacao(a, 0);
}

