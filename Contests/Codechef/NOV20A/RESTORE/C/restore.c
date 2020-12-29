#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main() {
	int maxN = 1400000;
	int seive[maxN + 1];
	for(int i=0;i<=maxN;i++) {
		seive[i] = 1;
	}
	printf("%d\n", maxN);
	for(int i=2;i*i<=maxN;i++) {
		if(seive[i] == 1) {
			for(int j=i*i;j<=maxN;j+=i) {
				seive[j] = 0;
			}
		}
	}
	int primes[100100];
	int ind = 0;
	for(int i=2;i<=maxN;i++) {
		if(seive[i] == 1) {
			primes[ind] = i;
			ind++;
			printf("%d ", i);
		}
	}
	int t;
	scanf("%d", &t);
	while(t--) {
		int n;
		scanf("%d", &n);
		int b[n + 1];
		int ans[n + 1];
		for(int i=1;i<=n;i++) {
			scanf("%d", &b[i]);
		}
		ind = 0;
		for(int i=1;i<=n;i++) {
			if(ans[b[i]] == -1) {
				ans[i] = primes[ind];
				ans[b[i]] = ans[i];
				ind++;
			}
			else {
				ans[i] = ans[b[i]];
			}
		}
		for(int i=1;i<=n;i++) {
			printf("%d ", ans[i]);
		}
		printf("\n");
	}
}