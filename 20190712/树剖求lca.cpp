void Dfs_1 (int n, int F) {
	s[n] = 1, d[n] = d[F] + 1, f[n] = F;
	int V;
	for (E *e = list[n]; e; e = e->n)
		if ((V = e->v) != F) {
			Dfs_1 (V, n);
			s[n] += s[V];
			if (s[son[n]] < s[V]) son[n] = V;
		}
}
void Dfs_2 (int n, int C) {
	c[n] = C;
	if (son[n]) Dfs_2 (son[n], C);
	else return ;
	int V;
	for (E *e = list[n]; e; e = e->n)
		if ((V = e->v) != f[n] && V != son[n]) Dfs_2 (V, V);
}
int lca (int x, int y) {
	for (; c[x] != c[y]; x = f[c[x]])
		if (d[c[x]] < d[c[y]]) swap (x, y);
	return d[x] < d[y] ? x : y;
}



