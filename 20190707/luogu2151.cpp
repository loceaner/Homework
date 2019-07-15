#include <bits/stdc++.h>
using namespace std;
const int mod = 45989;
const int maxn = 21;
int cnt = 1;
int last[maxn], nex[1005], to[1005], from[1005];
int n, m, K, s, t;

void insert(int a, int b) {
    cnt++;
    nex[cnt] = last[a];
    last[a] = cnt;
    to[cnt] = b;
    from[cnt] = a;
}

struct Matrix {
    int v[125][125];
    Matrix(){
        memset(v, 0, sizeof(v));
    }
    friend void print(Matrix a) {
        for(int i = 1; i <= cnt; i++) {
            for(int j = 1; j <= cnt; j++) {
                cout << a.v[i][j] << ' ';
            }
            cout << endl;
        }
    }
    friend Matrix operator * (Matrix a, Matrix b) {
        Matrix ans;
        for(int i = 1; i <= cnt; i++) {
            for(int j = 1; j <= cnt; j++) {
                for(int k = 1; k <= cnt; k++) {
                    ans.v[i][j] = (ans.v[i][j] + a.v[i][k] * b.v[k][j]) % mod;
                }
            }
        }
        return ans;
    }
    friend Matrix operator ^ (Matrix a, int b) {
        Matrix ans;
        for(int i = 1; i <= cnt; i++) ans.v[i][i] = 1;
        for(int i = b; i;i >>= 1, a = a * a) {
           if(i & 1) ans = ans * a;
        }
        return ans;
    }
}a, b;

int main() {
    scanf("%d %d %d %d %d", &n, &m, &K, &s, &t);
    memset(last, 0, sizeof(last));
    for(int i = 1; i <= m; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        insert(x, y);
        insert(y, x);
    }
    for(int i = last[s]; i; i = nex[i]) {
        a.v[1][i] = 1;
    }
    for(int i = 2; i <= cnt; i++) {
        for(int j = 2; j <= cnt; j++) {
            if(to[i] == from[j]) {
                if(i != (j ^ 1)) {
                    b.v[i][j] = 1;
                }
            }
        }
    }
    a = a * (b ^ (K-1));
    int ans = 0;
    for(int i = last[t]; i; i = nex[i]) {
       ans = ans + a.v[1][i^1];
    }
    printf("%d\n", ans % mod);
    return 0;
} 