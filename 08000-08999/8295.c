#include <stdio.h>

/*
���� : N * M(N, M <= 100) ũ���� ���簢�� ���ڿ��� �ѷ��� P �̻��� ���簢���� ������ ���Ѵ�.

�ذ� ��� : N�� M�� ũ�Ⱑ �۱� ������ ���� �� �ִ� ��� ������ ���簢���� ���캸�� �ѷ��� P �̻����� Ȯ���ϰ�,
�׷��ϴٸ� �� ũ���� ���簢���� ������ �ᱣ���� ���Ѵ�. �̸� ���� ���� ���� ����Ѵ�.

�ֿ� �˰����� : ����, ���Ʈ ����

��ó : PA 2010 0-1��
*/

int main(void) {
    int n, m, p, r = 0;
    scanf("%d %d %d", &n, &m, &p);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if ((i + j) * 2 >= p) r += (n - i + 1) * (m - j + 1);
        }
    }
    printf("%d", r);
    return 0;
}