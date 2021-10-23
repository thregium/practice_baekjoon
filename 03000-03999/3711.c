#include <stdio.h>

/*
���� : G(G <= 300)���� 10^6 ������ ���� �ƴ� ������ �־�����. �̶�, M���� ��� ���� ���� �������� ���� �ٸ� �ڿ���
M ��� ���� ���� ���� ���Ѵ�.

�ذ� ��� : G�� �۱� ������ 1���� �ö󰡸� �׷��� ���� ã���� ���� ������ ���� ������ �ȴ�.

�ֿ� �˰��� : ���Ʈ ����, ������

��ó : NWERC 2005 F��
*/

int nb[512], md[1048576];

int main(void) {
    int n, g, r;
    //freopen("E:\\PS\\ICPC\\Europe\\NWERC\\2005\\reducedidnumbers.in", "r", stdin);
    scanf("%d", &n);
    for (int nn = 0; nn < n; nn++) {
        scanf("%d", &g);
        for (int i = 0; i < g; i++) {
            scanf("%d", &nb[i]);
        }
        for (int i = 1;; i++) {
            r = 1;
            for (int j = 0; j < g; j++) {
                if (md[nb[j] % i]) {
                    r = 0;
                    break;
                }
                else md[nb[j] % i] = 1;
            }
            for (int j = 0; j < i; j++) md[j] = 0;
            if (r) {
                printf("%d\n", i);
                break;
            }
        }
    }
    return 0;
}