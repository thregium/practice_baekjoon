#include <stdio.h>

int nums[1024], max[1024];

int main(void) {
	int t, n, maxi, maxt, ts, h;
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++) {
		scanf("%d", &n);
		maxi = 1;
		for (int i = 1; i <= n; i++) {
			scanf("%d", &nums[i]);
			if (i == 1) {
				max[i] = nums[i];
				continue;
			}
			ts = 0;
			h = -2147483648;
			for (int j = i; j >= maxi; j--) {
				ts += nums[j];
				if (ts > h) {
					h = ts;
					maxt = j;
				}
			}
			if (h > max[i - 1]) {
				maxi = maxt;
				max[i] = h;
			}
			else {
				max[i] = max[i - 1];
			}
		}

		printf("%d\n", max[n]);
	}
	return 0;
}
