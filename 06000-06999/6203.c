#include <stdio.h>
#include <stdlib.h>

/*
���� : ��ǥ���� N(N <= 1000)���� ���� �ִ�. �� ���鿡 ��ȣ�� �ű�� 1������ ���ʷ� ���� ������ �ִ� ���� �����Ѵ�.
������ ���� �Ѿ�� �������� ���� ���� ������ ���� ������ �ִ� ���� �����ϴ� ���� �ݺ��Ѵ�. ������ �� ��������
�ٽ� 1�� ������ ���ƿͼ� �̸� �ݺ��Ѵ�. �̶�, ���������� ���� ���� ���Ѵ�.

�ذ� ��� : �� ���� ������ �Ÿ��� �̸� ���ص� ����, �� ���鿡�� ����� ������ ������ ��ȣ�� �����صд�.
�� �ڷδ� ������ ���캸�鼭 ���� ����� ���� ���ϰ� ����� ���� �ݺ��ϸ� �ȴ�.

�ֿ� �˰��� : ����, �ùķ��̼�, ������, ����

��ó : USACO 2006N B3�� // CERC 2002 E��
*/

int pos[1024][2], dists[1024][1024], order[1024][1024], checked[1024], elim[1024];
int search = 0; //������ ���� ���� ����

int sqr(int x) {
    return x * x;
}

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return dists[search][ai] > dists[search][bi] ? 1 : dists[search][ai] == dists[search][bi] ? 0 : -1;
}

int main(void) {
    int n, turn = 1;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &pos[i][0], &pos[i][1]);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dists[i][j] = sqr(pos[i][0] - pos[j][0]) + sqr(pos[i][1] - pos[j][1]); //�Ÿ� ���ϱ�
            order[i][j - 1] = j; //��� ��ȣ�� �̸� ����д�.
        }
    }
    for (int i = 1; i <= n; i++) {
        search = i;
        qsort(order + i, n, sizeof(int), cmp1); //�����Ѵ�.
    }
    for (int i = 1; i < n; i++) {
        for (int j = checked[turn] + 1; j <= n; j++) {
            //���������� Ȯ���� ��ȣ �������� Ȯ���Ѵ�.
            checked[turn] = j;
            if (j >= n) return 1; //���� �����
            if (!elim[order[turn][j]]) {
                elim[order[turn][j]] = 1; //������ ���� ���� ���
                break;
            }
        }
        turn = turn % n + 1;
        while (elim[turn]) turn = turn % n + 1; //���� ���� ã�´�.
    }
    printf("%d", turn);
    return 0;
}