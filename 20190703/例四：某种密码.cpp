/*����ĳ������������������
ĳ�������ԭ��A����N��������ɣ�������B��һ������ΪN��01������ԭ�ĺ����ĵĹ�������һ��Կ����KEY��
��KEY=�ơ�Ai*Bi���������ľ���ԭ�ĵ�һ��Ϸ����롣
������ԭ�ĺ�Կ���룬���һ��������������ͳ�Ƶ����ж��ٸ��������������ġ�
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

