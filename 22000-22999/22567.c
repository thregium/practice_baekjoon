#include <stdio.h>

/*
���� : N * N(N <= 500) ũ���� ���� �ǿ� �� ���� 10^6 ������ ���� �ٸ� �ڿ������� ���.
�� ���� ���� U, V(U, V <= 13) ���� ���� �ϼ��Ǹ� �̱��. M(M <= 10^6)���� ���� �ٸ� �ڿ���(<= 10^6)����
�־��� ��, �ش� ������ ������ �Ҹ��� ���� �̱���� �Ǵ� ���� �� ���Ѵ�.

�ذ� ��� : �� ĭ�� ���� ������ �Է¹����鼭 �� ���� �ش��ϴ� �ٵ��� ���� ����صд�.
���� ������ �۱� ������ �̰��� �����ϴ�.
�� �������� ������ �־��� �� ���� �� ���� �� ���� �ش��ϴ� �ٵ鿡 �Ҹ� ������ ������ �����Ѵ�.
�� ������ N���� �Ǵ� �ٵ��� ������ ���ϰ� �� �� ���� U, V�� �Ǵ� �� ���ο� ���� ���� ���ϸ� �ȴ�.
��, N�� 1�� ������ �ߺ��Ǵ� ���� ������� �ʾƾ� �Կ� �����Ѵ�.

�ֿ� �˰��� : ����, �ùķ��̼�, �ֵ� Ȥ?

��ó : JAG 2010S3 J��
*/

int usm[512][512], nkm[512][512], usl[1024], nkl[1024];
short ust[1048576][5], nkt[1048576][5];

int main(void) {
    int n, u, v, m, x;
    scanf("%d %d %d %d", &n, &u, &v, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &usm[i][j]);
            ust[usm[i][j]][++ust[usm[i][j]][0]] = i;
            ust[usm[i][j]][++ust[usm[i][j]][0]] = 500 + j;
            if (i == j) ust[usm[i][j]][++ust[usm[i][j]][0]] = 1000;
            if (i == n - j - 1) ust[usm[i][j]][++ust[usm[i][j]][0]] = 1001;
            if (n == 1) ust[usm[i][j]][0] = 1;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &nkm[i][j]);
            nkt[nkm[i][j]][++nkt[nkm[i][j]][0]] = i;
            nkt[nkm[i][j]][++nkt[nkm[i][j]][0]] = 500 + j;
            if (i == j) nkt[nkm[i][j]][++nkt[nkm[i][j]][0]] = 1000;
            if (i == n - j - 1) nkt[nkm[i][j]][++nkt[nkm[i][j]][0]] = 1001;
            if (n == 1) nkt[nkm[i][j]][0] = 1;
        }
    }

    for (int i = 0; i < m; i++) {
        scanf("%d", &x);
        for (int j = 1; j <= ust[x][0]; j++) {
            usl[ust[x][j]]++;
            if (usl[ust[x][j]] == n) u--;
        }
        for (int j = 1; j <= nkt[x][0]; j++) {
            nkl[nkt[x][j]]++;
            if (nkl[nkt[x][j]] == n) v--;
        }

        if (u <= 0 && v <= 0) printf("DRAW\n");
        else if (u <= 0) printf("USAGI\n");
        else if (v <= 0) printf("NEKO\n");
        if (u <= 0 || v <= 0) {
            return 0;
        }
    }
    printf("DRAW\n");
    return 0;
}