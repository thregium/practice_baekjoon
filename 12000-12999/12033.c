#include <stdio.h>
#include <stdlib.h>

/*
���� : ���� N * 2(N <= 4)�� ������ �־��� ��, �� �������� 4�� ����� N���� ���� �ش� ���� 3 / 4�� N���� ������
���� �ִٰ� �Ѵ�. �� �������� 3 / 4�� ������ ������������ ��� ���Ѵ�. ���� ���� ���� �� ���� �� �ִ�.
���� �����ϴٴ� ���� ����ȴ�.

�ذ� ��� : �� ������ Ȯ���ϸ� ���� ���� 3 / 4�� ���� ���� ã���� ��������� ���� ���� ã�� ������.
�̸� N���� ���� ã�� �� ���� �ݺ��� ������ �ȴ�.

�ֿ� �˰��� : ���Ʈ ����, ��Ʈ��ŷ

��ó : GCJ 2016W A1��
*/

int price[8], chk[8], collect[4];
int fin = 0;

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

void track(int n, int x, int tt) {
    if (n == x) {
        fin = 1;
        qsort(collect, n, sizeof(int), cmp1);
        printf("Case #%d: ", tt);
        for (int i = 0; i < n; i++) {
            printf("%d ", collect[i]);
        }
        printf("\n");
        return;
    }

    for (int i = 0; i < n * 2; i++) {
        if (chk[i]) continue;
        for (int j = 0; j < n * 2; j++) {
            if (i == j) continue;
            if (chk[j]) continue;
            if (price[i] * 4 == price[j] * 3) {
                chk[i] = 1;
                chk[j] = 1;
                collect[x] = price[i];
                track(n, x + 1, tt);
                chk[i] = 0;
                chk[j] = 0;
                if (fin) return;
                break;
            }
        }
    }
}

int main(void) {
    int t, n;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        scanf("%d", &n);
        for (int i = 0; i < n * 2; i++) {
            scanf("%d", &price[i]);
        }
        track(n, 0, tt);
    }
    return 0;
}