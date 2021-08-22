#include <stdio.h>

/*
문제 : N(N <= 14)개의 숫자들을 배치하여 자연수 두개를 만들 때, 두 수의 합을 가장 적게 한다면 그때의 합을 구한다.
단, 두 수는 0으로 시작할 수 없고, 0이 아닌 숫자는 최소 2개 이상 주어진다.

해결 방법 : 먼저 두 수의 길이가 균등해야 합이 가장 적어짐을 쉽게 알 수 있다. 또한, 앞쪽 자리가 작을수록 좋다는 것도 알 수 있다.
이를 이용해 두 수를 번갈아가며 작은 숫자부터 배정하면 된다. 단, 이때 0으로 시작하면 안된다는 점에 유의한다.

주요 알고리즘 : 그리디 알고리즘

출처 : MidC 2013 F번
*/

int nums[16];

int main(void) {
    int n, a, b, t;
    nums[0] = 99;
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &nums[i]);
        }
        t = 0;
        for (int i = 1; i <= n; i++) {
            if (nums[i] > 0 && nums[i] < nums[t]) t = i;
        }
        a = nums[t];
        nums[t] = -1;
        t = 0;
        for (int i = 1; i <= n; i++) {
            if (nums[i] > 0 && nums[i] < nums[t]) t = i;
        }
        b = nums[t];
        nums[t] = -1;

        for (int i = 2; i < n; i++) {
            t = 0;
            for (int j = 1; j <= n; j++) {
                if (nums[j] >= 0 && nums[j] < nums[t]) t = j;
            }
            if (i & 1) {
                b *= 10;
                b += nums[t];
            }
            else {
                a *= 10;
                a += nums[t];
            }
            nums[t] = -1;
        }
        printf("%d\n", a + b);
    }
    return 0;
}