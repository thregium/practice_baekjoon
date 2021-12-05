#include <stdio.h>

/*
���� : N(N <= 100)�������� å�� �μ��ϱ� ���� �� ���̿� ���� �ϴ� �������� ���Ѵ�.

�ذ� ��� : ������ ���� 1�� ��� ���ʸ� ��� Ư���� ����, ���� ����Ѵ�. �� ���� ���� �� ��������
����ؾ� �ϴ� ������ ��ȣ�� Ȯ���� ����ϵ�, N���� ū ��쿡�� Blank�� ����ؾ� �Ѵ�.

�ֿ� �˰��� : ����

��ó : MidC 1998 A�� // CTUF 2003 B��
*/

int main(void) {
    int n;
    //freopen("E:\\PS\\ICPC\\North America\\Mid Central\\mcpc1998\\booklet\\booklet.in", "r", stdin);
    //freopen("E:\\PS\\ICPC\\North America\\Mid Central\\mcpc1998\\booklet\\booklet_t.out", "w", stdout);
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        printf("Printing order for %d pages:\n", n);
        if (n == 1) {
            printf("Sheet 1, front: Blank, 1\n\n");
            continue;
        }
        for (int i = 0; i < ((n + 3) >> 2) << 1; i++) {
            printf("Sheet %d, ", (i >> 1) + 1);
            if (i & 1) {
                printf("back : %d, ", i + 1);
                if ((((n + 3) >> 2) << 2) - i > n) printf("Blank\n");
                else printf("%d\n", (((n + 3) >> 2) << 2) - i);
            }
            else {
                printf("front: ", i + 1);
                if ((((n + 3) >> 2) << 2) - i > n) printf("Blank, ");
                else printf("%d, ", (((n + 3) >> 2) << 2) - i);
                printf("%d\n", i + 1);
            }
        }
        printf("\n");
    }
    return 0;
}