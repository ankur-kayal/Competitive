#include <stdio.h>

int main() {

	int t;
	scanf("%d", &t);
	while(t--) {
		int n,m;
		scanf("%d%d",&n,&m);
		int a[n];
		int maxH = -1;
		for(int i=0;i<n;i++) {
			scanf("%d",&a[i]);
			maxH = (maxH < a[i] ? a[i] : maxH);
		}
		for(int i=0;i<n;i++) {
			m-=(maxH - a[i]);
		}
		if(m >= 0 and m % n == 0) {
			printf("Yes\n");
		}
		else {
			printf("No\n");
		}
	}
}