#include <map>
#include <queue>
#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
using namespace std;

string st, pur=" 123804765", s, si;
char x;
map<string, int>p;
queue<string>q;
queue<int>t;

int main() {
	cin >> st;
	st = ' ' + st;
	q.push(st);
	p[st] = 1;
	t.push(0);
	while(!q.empty()) {
		s = q.front();
		int step = t.front();
		t.pop();
		q.pop();
		if(s == pur) {
			cout << step << '\n';
			return 0;
		}
		si = s;
		int pi = si.find("0");
		if(pi + 3 <= 9) {
			x = si[pi + 3], si[pi + 3] = si[pi], si[pi] = x;
			if(p[si] == 0) {
				q.push(si);
				t.push(step+1);
				p[si]=1;
			}
		}
		si = s;
		if(pi - 3 >= 1) {
			x = si[pi - 3 ], si[pi - 3] = si[pi], si[pi] = x;
			if(p[si] == 0) {
				q.push(si);
				t.push(step+1);
				p[si]=1;
			}
		}
		si = s;
		if(pi + 1 <= 9 && pi != 3 && pi != 6) {
			x = si[pi + 1 ], si[pi + 1] = si[pi], si[pi] = x;
			if(p[si] == 0) {
				q.push(si);
				t.push(step+1);
				p[si]=1;
			}
		}
		si = s;
		if(pi - 1 >= 1 && pi != 4 && pi != 7) {
			x = si[pi - 1 ], si[pi - 1] = si[pi], si[pi] = x;
			if(p[si] == 0) {
				q.push(si);
				t.push(step+1);
				p[si]=1;
			}
		}
		si = s;
	}
	return 0;
}
