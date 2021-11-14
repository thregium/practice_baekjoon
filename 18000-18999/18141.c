#include <stdio.h>

/*
���� : N(N <= 50)���� �ڿ���(<= 100)�� �־��� ��, ���� �ٸ� i, j, k�� ���� (a[i] - a[j]) / a[k]�� �׻� �������� Ȯ���Ѵ�.

�ذ� ��� : 3�� for ���� ���� ���� �ٸ� i, j, k�� ���� ���� (a[i] - a[j]) % a[k]�� 0�� �ƴ� ��찡 �ִ��� Ȯ���غ���.
�׷��� ��찡 �ִٸ� ������ �ƴ� ��찡 �ִ� ���̰� �� �ܿ��� �׻� ������ ���̴�.

�ֿ� �˰��� : ���Ʈ ����

��ó : Taipei 2019 C��
*/

int a[64];

int main(void) {
    int n, r = 1;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            for (int k = 0; k < n; k++) {
                if (i == k || j == k) continue;
                if ((a[i] - a[j]) % a[k]) r = 0;
            }
        }
    }
    printf("%s", r ? "yes" : "no");
    return 0;
}
