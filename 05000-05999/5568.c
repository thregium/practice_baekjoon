#include <stdio.h>
#include <stdlib.h>

/*
���� : N(N <= 10)���� ī�忡 �� �ڸ� �Ǵ� �� �ڸ� ���� ���� �ִ�. �̶�, K(2 <= K <= 4)���� ī�带 �̾�ٿ��� ���� �� �ִ�
���� �ٸ� ���� ������ ���Ѵ�. ���� ����� �ٸ����� ���� ���ٸ� ���� ���̴�.

�ذ� ��� : ī���� ��� ������ ���� ���� �� �ִ� ���� ���� ����, �����Ͽ� �ߺ��� ������ ���� ������ ���� �ȴ�.
���Ʈ ������ �ϸ� �� �ڸ��� ���� �� �ڸ��� ��츦 ���� ������ Ȯ���ؾ� �Ѵ�.

�ֿ� �˰��� : ���Ʈ ����

��ó : JOI 2010�� 4��
*/

int card[16], chk[16], res[5120];
int rp = 0;

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

void track(int n, int k, int l, int r) {
    if (k == l) {
        res[rp++] = r;
        return;
    }
    for (int i = 0; i < n; i++) {
        if (chk[i]) continue;
        chk[i] = 1;
        if (card[i] < 10) track(n, k, l + 1, r * 10 + card[i]);
        else track(n, k, l + 1, r * 100 + card[i]);
        chk[i] = 0;
    }
}

int main(void) {
    int n, k, r = 0;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &card[i]);
    }
    track(n, k, 0, 0);
    if (rp > 5120) return 1;
    qsort(res, rp, sizeof(int), cmp1);
    for (int i = 0; i < rp; i++) {
        if (i == 0 || res[i] != res[i - 1]) r++;
    }
    printf("%d", r);
    return 0;
}