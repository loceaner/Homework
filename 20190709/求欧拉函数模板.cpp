int oula() {
	visit[1] = 1;
	enlur[1] = 0;
	for(int i = 2; i <= 1000005; i++) {
		if(!enlur[i]) {
			visit[i] = 1;
			enlur[i] = i - 1;
			for(int j = 2 * i; j <= 100005; j += i) {
				if(!visit[j]) {
					enlur[j] = j;
					visit[j] = 1;
				}
				enlur[j] = enlur[j] / i * (i - 1);
			}
		}
	}
}