#include <stdio.h>
#define INF 1012345678

/*
���� : ���� V(V <= 10^6)�̸� �� ���� ���̰� �ڿ����� ������ü ��� ���� �ѳ��̰� ���� ���� �ѳ��̸� ���Ѵ�.

�ذ� ��� : ������ ��� ��쿡 ���� �ѳ��̸� ���غ��� �� ��� ���� ���� ���� ���ϸ� �ȴ�.

�ֿ� �˰��� : ���Ʈ ����, ����, ������

��ó : BAPC 2018 C��
*/

int main(void) {
    int n, k, r = INF;
    scanf("%d", &n);
    for (int i = 1; i * i * i <= n; i++) {
        for (int j = i; i * j * j <= n; j++) {
            if (n % (i * j)) continue;
            k = n / i / j;
            if (2 * (i * j + i * k + j * k) < r) r = 2 * (i * j + i * k + j * k);
        }
    }
    printf("%d", r);
    return 0;
}