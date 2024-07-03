#include<bits/stdc++.h>
using namespace std;

vector<pair<int, int>> mov;

void cavalo(vector<vector<int>> tab, int i, int j, int k) {
    if(k == 64) {
        for(int i = 0; i < 8; i++) {
            for(int j = 0; j < 8; j++) {
                cout << tab[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        exit(0);
    }
    int l = 0;
    while (l < 8) {
        int x = i + mov[l].first;
        int y = j + mov[l].second;
        if(x >= 0 && x < 8 && y >= 0 && y < 8 && tab[x][y] == -1) {
            tab[x][y] = k;
            cavalo(tab, x, y, k + 1);
            tab[x][y] = -1;
        }
        l++;
    }
}

int main() {

    mov = {{-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}};
    vector<vector<int>> tab(8, vector<int>(8, -1));
    tab[0][0] = 0;
    cavalo(tab, 0, 0, 1);

}