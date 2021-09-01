#include <stdio.h>

/*
���� : �־��� �� V(V <= 3^20)�� 3�������� ǥ���Ͽ� ����Ѵ�.

�ذ� ��� : V�� �� �ڸ����� ������ ���� ����ϸ� �ȴ�. ������ �ݴ밡 �ʰ� 0�� ��쿡 �����Ѵ�.

�ֿ� �˰��� : ����, ����

��ó : NWERC 2017 PC��
*/

int r[32];

int main(void) {
    int n, p = 0;
    long long v;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &v);
        if (v == 0) printf("0");
        for (; v; v /= 3) r[p++] = v % 3;
        while (p) printf("%d", r[--p]);
        printf("\n");
    }
    return 0;
}