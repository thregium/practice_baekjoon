#include <stdio.h>

/*
���� : N(N <= 14)���� ���ڵ��� ��ġ�Ͽ� �ڿ��� �ΰ��� ���� ��, �� ���� ���� ���� ���� �Ѵٸ� �׶��� ���� ���Ѵ�.
��, �� ���� 0���� ������ �� ����, 0�� �ƴ� ���ڴ� �ּ� 2�� �̻� �־�����.

�ذ� ��� : ���� �� ���� ���̰� �յ��ؾ� ���� ���� �������� ���� �� �� �ִ�. ����, ���� �ڸ��� �������� ���ٴ� �͵� �� �� �ִ�.
�̸� �̿��� �� ���� �����ư��� ���� ���ں��� �����ϸ� �ȴ�. ��, �̶� 0���� �����ϸ� �ȵȴٴ� ���� �����Ѵ�.

�ֿ� �˰��� : �׸��� �˰���

��ó : MidC 2013 F��
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