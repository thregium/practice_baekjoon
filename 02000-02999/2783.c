#include <stdio.h>

/*
���� : �� ���Կ� N(N <= 100)���� ���԰� ���� ��, �� ���Ե鿡�� � ������ Yg�� X���� �Ǵٸ�
1000g�� �������� ���Ѵ�.

�ذ� ��� : ��� ���Կ� ���� 1000g�� ������ ���� �� �� �� ���� ���� ���� ���ϸ� �ȴ�.

�ֿ� �˰��� : ����, ��Ģ����

��ó : COCI 12/13#2 1��
*/

int main(void) {
    int x, y, n;
    double best;
    scanf("%d %d", &x, &y);
    best = x * (1000.0 / y);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &x, &y);
        if (x * (1000.0 / y) < best) best = x * (1000.0 / y);
    }
    printf("%f", best);
    return 0;
}