#include <stdio.h>

/*
���� : N(N <= 100)���� �ڿ��� A_i(< 1000)�� �־��� ��, ���ʷ� ���� �ٸ� i, j, k�� ������ ��
A_i * A_j = A_k�� �Ǵ� ����� ���� ���Ѵ�.

�ذ� ��� : ��� i, j, k�� ���� �׷��� ������ ���� �õ��غ� �� Ƚ���� ���ϸ� �ȴ�.

�ֿ� �˰��� : ����, ���Ʈ ����

��ó : JOIG 2022 2��
*/

int a[128];

int main(void) {
    int n, r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (a[i] * a[j] == a[k]) r++;
            }
        }
    }
    printf("%d", r);
    return 0;
}