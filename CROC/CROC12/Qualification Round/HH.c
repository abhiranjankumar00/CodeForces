//Name         : Shinchan Nohara
//Age          : 5 years
//Organisation : Kasukabe Defense Force

#include <stdio.h>
#include <string.h>

int cnt[5005][5005];
int len;
char st[5005];
int palin[5005][5005];

void updateFreq(int r, int c) {
	int cc;
	while(r <= len) {
		cc = c;
		while(cc <= len) {
			cnt[r][cc]++;
			cc += (cc & (-cc));
		}
		r += (r & (-r));
	}
}

int readFreq(int r, int c) {
	int ret = 0;
	int cc;
	while(r > 0) {
		cc = c;
		while(cc > 0) {
			ret += cnt[r][cc];
			cc -= (cc & (-cc));
		}
		r -= (r & (-r));
	}
	return ret;
}

int main()
{
	int d, q, i, j;
	int l, r;
	scanf("%s", st+1);
	len = strlen(st+1);

	scanf("%d", &q);

	for(d = 0; d <= len; d++) {
		for(i = 1; i <= len; i++) {
			j = i+d;
			if(j > len)
				break;

			if(i == j)
				palin[i][j] = 1;
			else if(j-i == 1) 
				palin[i][j] = st[i]==st[j] ? 1 : 0;
			else if(palin[i+1][j-1])
				palin[i][j] = st[i] == st[j] ? 1 : 0;
			else
				palin[i][j] = 0;

			if(palin[i][j])
				updateFreq(i, j);
		}
	}

	while(q--) {
		scanf("%d %d", &l, &r);
		int ans = readFreq(r, r) - readFreq(r, l-1) - readFreq(l-1, r) + readFreq(l-1, l-1);
		printf("%d\n", ans);
	}

	return 0;
}

