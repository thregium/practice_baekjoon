#include <stdio.h>

/*
���� : i dolphin(s), i jump(s), splash�� i��(i�� �ݺ��� ��)��ŭ �ݺ��� ��,
N(N <= 2 * 10^9)��°�� ���ľ� �� ���� ����Ѵ�.

�ذ� ��� : �� i���� �������� ��ĥ ��°�� ����� ������. �̸� �ݺ��ϸ� N��°�� �Ѿ ��,
�� ��°�� �������� ���ľ� �� ��Ȯ�� ������ ã���� �ȴ�.
���������� ���� N^2�� ����ϹǷ� O(sqrt(N))�� Ǯ �� �ִ�.

�ֿ� �˰��� : ����

��ó : Thai 2016A G��
*/

int main(void) {
    int t, n, s;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d", &n);
        s = 0;
        for (int i = 1;; i++) {
            s += i * 3;
            if (s >= n) {
                if (s - i * 2 >= n) {
                    printf("%d dolphin", i);
                    if (i > 1) printf("s\n");
                    else printf("\n");
                }
                else if (s - i >= n) {
                    printf("%d jump", i);
                    if (i > 1) printf("s\n");
                    else printf("\n");
                }
                else printf("splash\n");
                break;
            }
        }
    }
    return 0;
}