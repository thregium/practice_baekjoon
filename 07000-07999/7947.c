#include <stdio.h>

/*
���� : 10�� ���� R, G, B�� ���� �־�����. �� ���� ���(�ݿø�)�� �� ���� R, G, B ���� ����Ѵ�.
�̸� Z�� �ݺ��Ѵ�.

�ذ� ��� : R, G, B�� ���� ���� �� 5�� ���ؼ� 10���� ���� ���� ����ϸ� �ȴ�.

�ֿ� �˰��� : ����, ��Ģ����

��ó : AMPPZ 2005 A��
*/

int main(void) {
    int z, r, g, b, rs, gs, bs;
    scanf("%d", &z);
    for (int zz = 0; zz < z; zz++) {
        rs = 0, gs = 0, bs = 0;
        for (int i = 0; i < 10; i++) {
            scanf("%d %d %d", &r, &g, &b);
            rs += r, gs += g, bs += b;
        }
        printf("%d %d %d\n", (rs + 5) / 10, (gs + 5) / 10, (bs + 5) / 10);
    }
    return 0;
}