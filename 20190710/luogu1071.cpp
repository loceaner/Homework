#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#define N 1010
using namespace std;

char d[N], s[N], e[N];
string a, b, c;

int main() {
	cin >> a >> b >> c;
	for(int i = 0; i < a.size(); i++) {
		if(s[a[i]] == 0) s[a[i]] = b[i];
		else if(s[a[i]] != b[i]) {
			cout << "Failed";
			return 0;
		}
		e[b[i]]++;
	}
	for(int i = 'A'; i <= 'Z'; i++) {
		if(s[i] == 0 || e[i] == 0) {
			cout << "Failed";
			return 0;
		}
	}
	for(int i = 0; i < c.size(); i++) {
		d[i] = s[c[i]];
		cout << d[i];
	}
	return 0;
}
