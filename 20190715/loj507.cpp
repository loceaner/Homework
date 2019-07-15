#include <iostream>
#include <cstdio>

const int BUF = 100000010;
char Buf[BUF], *buf = Buf;

inline long long max(long long a, long long b) { return a > b ? a : b; }

void read(int &now) {
    for (now = 0; !isdigit(*buf); ++buf)
        ;
    for (; isdigit(*buf); now = now * 10 + *buf - '0', ++buf)
        ;
}

#define Max 1000020
int N, K;
long long sum[Max];

int to[Max];
int last_kind[Max * 100];

long long dp[Max];

int main(int argc, char *argv[]) {
    fread(buf, 1, BUF, stdin);
    read(N);
    read(K);

    register int i;
    int x;
    for (i = 1; i <= N; ++i) {
        read(x);
        to[i] = last_kind[x];
        last_kind[x] = i;
    }

    for (i = 1; i <= N; ++i) {
        read(x);
        sum[i] = sum[i - 1] + x;
    }

    register int res;
    for (i = 1; i <= N; ++i) {
        dp[i] = dp[i - 1];
        if (to[i])
            dp[i] = max(dp[i], max(dp[to[i]] + sum[i] - sum[to[i]], dp[to[i] - 1] + sum[i] - sum[to[i] - 1]));
    }

    printf("%lld", dp[N]);
    return 0;
}
