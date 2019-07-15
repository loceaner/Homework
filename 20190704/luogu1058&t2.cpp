#include <iostream>
#include <cstdio>
using namespace std;

const int N = 100;
const char first[6][8] = {
	"..+---+",
	"./   /|",
	"+---+ |",
	"|   | +",
	"|   |/.",
	"+---+.."
};

int a[N][N];
char drow[N * 10][N * 10];

inline int read() {
	char c = getchar();
	int x = 0, f = 1;
	for( ; !isdigit(c); c = getchar()) if(c == '-') f = -1;
	for( ; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + (c ^ 48);
	return x * f;
}

inline void draw(int x, int y) {
	for(int i = 0; i < 6; i++) {
		for(int j = 0; j < 7; j++) {
			if(first[6 - i - 1][j] != '.') {
				drow[x - i][y + j] = first[6 - i - 1][j];
			}
		}
	}
}

int main() {
	int n, m, k, l, x, y;
	n = read(), m = read();
	l = 4 * m + 2 * n + 1;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			a[i][j] = read();
			k = max(k, a[i][j] * 3 + 2 * (n - i + 1) + 1);
		}
	}
	for(int i = 1; i <= k; i++) {
		for(int j = 1; j <= l; j++) {
			drow[i][j] = '.';		}
	} 
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++) {
			x = k - 2 * (n - i);
			y = 2 * (n - i) + 4 * (j - 1) + 1;
			while(a[i][j]--) {
				draw(x, y);
				x -= 3;
			}
		}
	}
	for(int i = 1; i <= k; i++) {
		for(int j = 1; j <= l; j++) {
			cout << drow[i][j];
		}
		cout << '\n';
	}
	return 0;
}
