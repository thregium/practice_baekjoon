#include <stdio.h>

/*
���� : N(N <= 10000)���� �ܵ��� ���� ��, ����ȣȯ(�ٴٱ����� �Ÿ��� �� �����ų� ����, ���� �� �ΰų� ���� ��)��
���� �ܵ��� ������ ���Ѵ�.

�ذ� ��� : N�� �ణ ũ��� ������ ��� ���� ���ϸ鼭 ����ȣȯ ���θ� üũ�ϴ��� �ð� ���� Ǯ �� �ִ�.

�ֿ� �˰��� : ���Ʈ ����

��ó : Beijing 2005 E��
*/

int condo[10240][2];

int main(void) {
    int n, ok, r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &condo[i][0], &condo[i][1]);
    }
    for (int i = 0; i < n; i++) {
        ok = 1;
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            if ((condo[j][0] <= condo[i][0] && condo[j][1] <= condo[i][1])) {
                ok = 0;
                break;
            }
        }
        r += ok;
    }
    printf("%d", r);
    return 0;
}