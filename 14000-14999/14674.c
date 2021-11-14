#include <stdio.h>
#include <stdlib.h>

/*
���� : ���� N(N <= 1000)���� ���ݰ� ������(, <= 10^8)�� �־��� ��,
���ӵ��� ������(��������) -> ����(��������) -> ��ȣ(��������) �������� �����Ͽ� ���� K(K <= N)���� ����Ѵ�.

�ذ� ��� : ������ �־��� ��� �����Ѵ�. �̶�, ������� ���������� ����ؾ� �Ǽ� ������ ���� �� �ִ�.

�ֿ� �˰��� : ����, ����

��ó : ���Ǵ� 2017 E��
*/

int game[1024][3];

int cmp1(const void* a, const void* b) {
    int a1 = *(int*)a;
    int b1 = *(int*)b;
    int a2 = *((int*)a + 1);
    int b2 = *((int*)b + 1);
    int a3 = *((int*)a + 2);
    int b3 = *((int*)b + 2);
    if ((long long)a3 * b2 != (long long)b3 * a2) return (long long)a3 * b2 < (long long)b3* a2 ? 1 : -1;
    if (a2 != b2) return a2 > b2 ? 1 : -1;
    return a1 > b1 ? 1 : a1 == b1 ? 0 : -1;
}

int main(void) {
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &game[i][0], &game[i][1], &game[i][2]);
    }
    qsort(game, n, sizeof(int) * 3, cmp1);
    for (int i = 0; i < k; i++) {
        printf("%d\n", game[i][0]);
    }
    return 0;
}