#include <stdio.h>

/*
���� : ī���̽����� �� �ڵ������� ���� ������ ���� ��ȭ�� �־��� ��, ���� ������ ����� ���� �������� ���ϰ�
�����ϴٸ� ���� ����ǥ�� ����Ѵ�.

�ذ� ��� : �� �ڵ����� ���� ������ ���� �������� ���� ��ȭ���� �� �Ͱ� ����. �� ���� ���� ������ ����ų�
�̹� �ش� ������ �ٸ� ���� �ִٸ� ����� ���� �Ұ����ϰ� ����� �ʴ´ٸ� �����ϴ�.

�ֿ� �˰��� : ����

��ó : Latin 2008 G��
*/

int rank[1024];

int main(void) {
    int n, c, p, r;
    //freopen("E:\\PS\\ICPC\\Latin America\\Latin\\2008\\testset_2008\\pole.in", "r", stdin);
    //freopen("E:\\PS\\ICPC\\Latin America\\Latin\\2008\\testset_2008\\pole.out", "w", stdout);
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        r = 1;
        for (int i = 0; i < n; i++) rank[i] = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d %d", &c, &p);
            if (i + p >= n || i + p < 0 || rank[i + p]) {
                r = 0;
                continue;
            }
            rank[i + p] = c;
        }
        if (!r) {
            printf("-1\n");
            continue;
        }
        for (int i = 0; i < n; i++) {
            printf("%d ", rank[i]);
        }
        printf("\n");
    }
    return 0;
}