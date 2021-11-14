#include <stdio.h>

/*
���� : N(N <= 1000)���� �������� �̷���� ���� Ʈ���� ����, ���� ��ȸ�� �־����� ���� ��ȸ�� ����Ѵ�.

�ذ� ��� : ���� �������� ������ ù �κ��� ��Ʈ�Ӱ� ���� ��ȸ���� ����Ʈ���� �������� ���������� �̿��Ѵ�.
ó������ ��ü �������� ���� Ʈ���� ������� ��ȸ�� �ϸ� �ȴ�. ���� ��ȸ�̹Ƿ� �������� ����� �ؾ� �Ѵ�.

�ֿ� �˰��� : ���� ����, Ʈ��

��ó : Daejeon 2013 L��
*/

int in[1024], pr[1024];

void find(int si, int ei, int sp, int ep) {
    int t = -1, r = pr[sp];
    for (int i = si; i <= ei; i++) {
        if (in[i] == r) {
            t = i;
            break;
        }
    }
    if (t > si) find(si, t - 1, sp + 1, sp + (t - si));
    if (t < ei) find(t + 1, ei, sp + (t - si + 1), ep);
    printf("%d ", r);
}

int main(void) {
    int t, n;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &pr[i]);
        }
        for (int i = 0; i < n; i++) {
            scanf("%d", &in[i]);
        }
        find(0, n - 1, 0, n - 1);
        printf("\n");
    }
    return 0;
}