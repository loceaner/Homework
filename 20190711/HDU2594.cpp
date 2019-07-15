#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#define N 50011
using namespace std;

int Next[N << 1];
char s1[N << 1], s2[N];

void getNext(char *s) {
	int len = strlen(s);
	int i = 0, j = -1;
	Next[0] = -1;
	while(i < len) {
		if(j == -1 || s[i] == s[j]) {
			i++;
			j++;
			Next[i] = j;
		} else j = Next[j];
	}
}

int main() {
	while(scanf("%s%s", s1, s2) != EOF) {
		int len1 = strlen(s1);
		int len2 = strlen(s2);
		strcat(s1, s2);
		getNext(s1);
		int k = len1 + len2;
		while(Next[k] > len1 || Next[k] > len2) k = Next[k];
		if(Next[k]==0)
			printf("0\n");
		else {
			for(int i=0; i<Next[k]; i++)
				printf("%c",s1[i]);
			printf(" %d\n",Next[k]);
		}
	}
	return 0;
}