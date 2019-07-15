#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, m;

struct Mat {
    int a[5][5];
    Mat() {
        memset(a, 0, sizeof(a));
    }
    int*operator[](int x) {
        return a[x];
    }
    void init() {for(int i = 0; i < 3; i++) a[i][i] = 1;}
    Mat operator*(Mat b) {
        Mat c;
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                for(int k = 0; k < 3; k++) {
                    c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % m;
                }
            }
        }
        return c;
    }
    Mat operator^(int cnt) {
        Mat ret, mul = *this;
        ret.init();
        for(; cnt; cnt >>= 1, mul = mul * mul) if(cnt & 1) ret = ret * mul;
        return ret;
    }
};

signed main() {
    scanf("%lld%lld", &n, &m);
    int now = 1;
    Mat ans, mul;
    ans[0][0] = 0, ans[0][1] = 1, ans[0][2] = 1;
    while(1) {
        mul[0][0] = now * 10 % m;
        mul[0][1] = 0;
        mul[0][2] = 0;
        mul[1][0] = 1;
        mul[1][1] = 1;
        mul[1][2] = 0;
        mul[2][0] = 0;
        mul[2][1] = 1;
        mul[2][2] = 1;
        if(now * 10 <= n) {
            mul = mul ^ (now * 9);
            ans = ans * mul;
        } else {
            mul = mul ^ (n - now + 1);
            ans = ans * mul;
            break;
        }
        now *= 10;
    }
    cout << ans[0][0] % m << '\n';
    return 0;
}