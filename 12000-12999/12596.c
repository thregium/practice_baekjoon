#include <stdio.h>

/*
���� : G(G < 1000, G�� Ȧ��)���� �������� �־�����. �̶�, �� ������ �����ϰ�� ��� ���� ������ ���� ���� ��,
���� ���� ������ ���Ѵ�.

�ذ� ��� : �迭�� �Է¹��� ����, �迭�� �տ������� �ڿ� �ִ� �� ��� ���� ���� �� �ִ� ���� �ֳ� Ȯ���Ѵ�.
�ִٸ� �� ���� ���� �����ٴ� ǥ�ø� �ϰ� ���� ���� ���캻��. ���� �̹� ���� ���� ���� ������ �Ѿ��.
�̸� �ݺ��� �� ���� ���� ���� ���� ���� �ȴ�.

�ֿ� �˰��� : ����

��ó : GCJ 2010A OA2��
*/

int a[1024], chk[1024];

int main(void) {
    int t, g;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        scanf("%d", &g);
        if (~g & 1) return 1;
        for (int i = 0; i < g; i++) {
            scanf("%d", &a[i]);
        }
        for (int i = 0; i < g; i++) {
            if (chk[i]) continue;
            for (int j = i + 1; j < g; j++) {
                if (chk[j]) continue;
                if (a[i] == a[j]) {
                    chk[i] = 1;
                    chk[j] = 1;
                    break;
                }
            }
        }
        for (int i = 0; i < g; i++) {
            if (!chk[i]) {
                printf("Case #%d: %d\n", tt, a[i]);
            }
            else chk[i] = 0;
        }
    }
    return 0;
}