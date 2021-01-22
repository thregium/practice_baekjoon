#include <stdio.h>

double nums[10240], max[10240];

int main(void) {
	int n, t = 0, maxi = 0;
	double h, res;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lf", &nums[i]);
		//nums[i] = 0.5;
		if (i == 0) max[i] = nums[i];
		else {
			res = 1.0;
			h = -1.0;
			for (int j = i; j >= maxi; j--) {
				res = res * nums[j];
				if (res > h) {
					h = res;
					t = j;
				}
			}
			if (h > max[i - 1]) {
				max[i] = h;
				maxi = t;
			}
			else {
				max[i] = max[i - 1];
			}
		}
	}

	printf("%.3f", max[n - 1]);
	return 0;
}
