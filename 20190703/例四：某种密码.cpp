/*关于某种密码有如下描述：
某种密码的原文A是由N个数字组成，而密文B是一个长度为N的01数串，原文和密文的关联在于一个钥匙码KEY。
若KEY=∑〖Ai*Bi〗，则密文就是原文的一组合法密码。
现在有原文和钥匙码，请编一个程序来帮助他统计到底有多少个符合条件的密文。
*/
#include <map>
#include <cstdio>
#include <iostream>
#define M 45
#define ll long long
using namespace std;

ll a[M], s1[M], s2[M], n, key, ans;
map<ll, int> hash;

void dfs(int x, int sum, int flag) {
	if(!flag && x > n / 2) {
		hash[sum]++;
		return;
	}
	if(flag && x > n) {
		ans += hash[key - sum];
		return;
	}
	dfs(x + 1, sum + a[x], flag);
	dfs(x + 1, sum, flag);
}
int main() {
	cin >> n >> key;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	dfs(1, 0, 0);
	dfs(n / 2 + 1, 0, 1);
	cout << ans << '\n';
	return 0;
}

