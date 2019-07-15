#include <bits/stdc++.h>
#define N 1000011
using namespace std;

inline int read() {
	int s=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9') {
		if(ch=='-')w=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
	return s*w;
}

int Next[N], sum[N][20], leng[N];
char txt[N], line[N];
int n, m;

void getNext(char *line) {
	Next[0] = -1;
	for(int i = 0, j = -1, len = strlen(line); i < len;) {
		if(j == -1 || line[i] == line[j]) {
			i++, j++;
			Next[i] = j;
		} else j = Next[j];
	}
}

void kmp(char *line, char *txt, int number) {
	for(int lent = strlen(txt), len = strlen(line), i = 0, j = 0; i <= lent;) {
		if(j == -1 || txt[i] == line[j]) {
			i++;
			j++;
		} else j = Next[j];
		if(j == len) {
			sum[i][number]++;
			j = Next[j];
		}
	}
}

int main() {
	n = read(), m = read();
	cin >> txt;
	int lent = strlen(txt);
	for(int i = 1; i <= n; i++) {
		cin >> line;
		getNext(line);
		kmp(line, txt, i);
		leng[i] = strlen(line);
	}
	for(int i = 1; i <= lent; i++) {
		for(int j = 1; j <= n; j++) {
			sum[i][j] += sum[i - 1][j];
		}
	}
	int x, y, ans;
	for(int i = 1; i <= m; i++) {
		x = read();
		y = read();
		ans = 0;
		for(int j = 1; j <= n; j++) {
			if(x - 1 <= y - leng[j]) {
				ans += sum[y][j] - sum[x + leng[j] - 2][j];
			}
		}
		cout << ans << '\n';
	}
	return 0;
}