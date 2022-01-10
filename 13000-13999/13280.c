#include <stdio.h>
#include <stdlib.h>

/*
���� : N(N <= 1000)���� ���� �ƴ� ����(<= 10^6)�� �̷���� �迭�� �־��� ��, �迭�� �� �� ���
���� ���� ���̰� ���� ���� ���̸� ���Ѵ�.

�ذ� ��� : 2�� for������ ��� �� �� ��� ���� ���̰� ���� ���� ���ϸ� �ȴ�.

�ֿ� �˰��� : ���Ʈ ����

��ó : JDC 2016 A��
*/

int a[1024];

int main(void) {
    int n, best;
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        best = 1048576;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (abs(a[i] - a[j]) < best) best = abs(a[i] - a[j]);
            }
        }
        printf("%d\n", best);
    }
    return 0;
}