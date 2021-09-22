#include <stdio.h>
#include <stdlib.h>
#define INF 1012345678

/*
���� : N(N <= 20)���� ���簢���� �ִ��� ��ġ�� ���� ��, ���� �� �ִ� �ִ� ������ ���Ѵ�. ���簢���� ȸ����Ű�� ���� �Ұ����ϴ�.
�׸���, ���� �ö���� ���簢���� �ݵ�� �Ʒ��� ���簢������ ���ο� ������ ���̰� ��� �۾ƾ� �Ѵ�.

�ذ� ��� : �� ���簢���� ���� -> ���� ������ ������ ����, ��� ���簢������ �״� ���� ���� �ʴ� ���� ������
��Ʈ����ŷ�� ���� ��� ��츦 �õ��� ����. �� ��쿡�� ���ηδ� �̹� ���ĵ� ������ ���̹Ƿ� ���η� ������� �׿����� Ȯ���Ͽ�
������� ������ ���� ���� �����ϰ�, ������� ���� ���� ��� �ִ��� ���ϸ� �ȴ�.

�ֿ� �˰��� : ���Ʈ ����, ��Ʈ����ŷ, ����

��ó : USACO 2007J B3��
*/

int bale[32][2];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    int aj = *((int*)a + 1);
    int bj = *((int*)b + 1);
    return ai > bi ? 1 : ai < bi ? -1 : aj > bj ? 1 : aj == bj ? 0 : -1;
}

int main(void) {
    int n, lb, best = 0, cnt;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &bale[i][0], &bale[i][1]);
    }
    qsort(bale, n, sizeof(int) * 2, cmp1);

    for (int i = 0; i < (1 << n); i++) {
        lb = 0;
        cnt = 0;
        for (int j = 0; j < n; j++) {
            if ((1 << j) & i) {
                cnt++;
                if (bale[j][1] <= lb) {
                    cnt = 0;
                    break;
                }
                else lb = bale[j][1];
            }
        }
        if (cnt > best) best = cnt;
    }
    printf("%d", best);
    return 0;
}