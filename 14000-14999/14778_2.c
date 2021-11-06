#include <stdio.h>
#include <stdlib.h>
//#include <time.h>

/*
���� : N(N <= 25000)���� ���� �ؾ� �Ѵ�. �� ���� �� �ܰ�� �������� �ְ�, ù ��° �ܰ踦 ������ ���� �ܰ踦 �� �� �ִ�.
ù ��° �ܰ�� �� ��° �ܰ��� ���� ���� ���������� �� �� �ִٸ� ��� ���� �ϴµ� �ɸ��� �ּ� �ð��� ���Ѵ�.

�ذ� ��� : ù ��° �ܰ�� �� ��° �ܰ��� ���� �ϴ� ������ ���� ���ƾ� �ּ��� ���� �� �� �ִ�.
���� ù ��° ���� ������ �����ϸ� �Ǵµ�, ��� ��ġ�� ���̵� ���� ����� ������ �ʱ� ������ ������ �����ϴ�.
�� ������ �� �ϸ� ���� �����ϸ� ã�� �� �ִ�. (���� ���� ù ��° �ܰ��� ��, ������ ���� �� ��° �ܰ��� ��)�� ���� �Ͱ�
(������ ���� ù ��° �ܰ��� ��, ���� ���� �� ��° �ܰ��� ��) �� ���� ���� ���ϴ� ����ε�, ... (�ۼ� ����)

�ֿ� �˰��� : �׸��� �˰���, ����

��ó : USACO 2006O G2��
*/

int milk[25600][2], seq[16], vis[16], bseq[16];
int best = 1012345678, bcnt = 1;

int big(int a, int b) {
    return a > b ? a : b;
}

int small(int a, int b) {
    return a < b ? a : b;
}

int cmp1(const void* a, const void* b) {
    int aa = *(int*)a;
    int ab = *((int*)a + 1);
    int ba = *(int*)b;
    int bb = *((int*)b + 1);
    return (aa < ab ? aa : 1012345678 - ab) - (ba < bb ? ba : 1012345678 - bb);
}

void track(int n, int x) {
    if (n == x) {
        int r1 = 0, r2 = 0;
        for (int i = 0; i < n; i++) {
            r1 += milk[seq[i]][0];
            r2 = big(r1, r2) + milk[seq[i]][1];
        }
        if (r2 < best) {
            best = r2;
            for (int i = 0; i < n; i++) bseq[i] = seq[i];
            bcnt = 1;
        }
        else if (r2 == best) bcnt++;
        return;
    }
    for (int i = 0; i < n; i++) {
        if (vis[i]) continue;
        vis[i] = 1;
        seq[x] = i;
        track(n, x + 1);
        vis[i] = 0;
    }
}

int main(void) {
    int n, t = 1;
    //freopen("E:\\PS\\Olympiad\\USA\\3_Gold\\2006_04\\usopen06\\testdata\\allopen06\\mqueue.10.in", "r", stdin);
    //srand(time(NULL));
    scanf("%d", &n);
    if (n > 25000) return 1;
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &milk[i][0], &milk[i][1]);
        //milk[i][0] = rand() + 1;
        //milk[i][1] = rand() + 1;
    }
    //if(t == 0 && n == 25000) return 1;
    /*
    track(n, 0);
    printf("%d %d\n", best, bcnt);
    for (int i = 0; i < n; i++) {
        printf("%d %d\n", milk[bseq[i]][0], milk[bseq[i]][1]);
    }
    */
    qsort(milk, n, sizeof(int) * 2, cmp1);
    int r1 = 0, r2 = 0;
    for (int i = 0; i < n; i++) {
        r1 += milk[i][0];
        r2 = big(r1, r2) + milk[i][1];
        if (r2 > 500000000) return 1;
    }
    printf("%d", r2);
    return 0;
}