#include <stdio.h>

/*
���� : ũ�� N(N <= 200000)�� �ּ� ������ 1 ~ N������ �ڿ����� �� ���� �־� �ڿ��� K�� P�� ��忡 ������ �ϴ� ������ ���Ѵ�.
���� ���� ��� -1�� ����Ѵ�.

�ذ� ��� : ���� P�� 1�� ��츦 ���캻��. K�� 1�̶�� ��� ������ ����ϴ��� ��� ����, �ƴ϶�� �׻� �Ұ����ϴ�.
�� ���� ���� P�� ������ ���� ���� �Ʒ��� ��忡 ������ ä������. �������δ� �ڽ��� �� - 1�� ������� ä�������� �ǰ�,
�Ʒ������δ� ��͸� �̿��� ���� ä�������� �ȴ�. �߰��� ���� ������ ��쿡�� -1�� ����ϰ� ���α׷��� �����Ѵ�.
�������δ� 1�� ����� ���� 1�� ��ģ ���� �������� ������ ���� ������ ������ ��忡 ���ʷ� ����ִ´�.
�� ������ ������ ������ ����ϸ� �ȴ�.

�ֿ� �˰����� : �׸��� �˰�����, ������, ���

��ó : UCPC 2018 E��
*/

int res[204800], chk[204800];
int t, over = 0;

void track(int n, int p) {
    if (p > n) return;
    if (t > n) over = 1;
    res[p] = t;
    chk[t++] = 1;
    track(n, p * 2);
    track(n, p * 2 + 1);
}

int main(void) {
    int n, k, p;
    scanf("%d%d %d", &n, &k, &p);
    if (p == 1) {
        //��Ʈ ����� ���
        if (k == 1) {
            for (int i = 1; i <= n; i++) {
                printf("%d\n", i);
            }
        }
        else printf("-1");
        return 0;
    }
    //�������� �ڸ��� �ִ��� �˻�
    t = p;
    for (int i = 0; i < k; i++) t /= 2;
    if (t) {
        printf("-1");
        return 0;
    }
    res[p] = k;
    chk[k] = 1;
    for (int i = p; i > 1; i >>= 1) {
        //���� ��� ä���
        res[i >> 1] = res[i] - 1;
        chk[res[i >> 1]] = 1;
    }
    chk[res[1]] = 0;
    res[1] = 1;
    chk[1] = 1;
    t = k;
    track(n, p); //�Ʒ��� ��� ä���
    if (over) {
        //�Ѿ ���
        printf("-1");
        return 0;
    }
    t = 1;
    for (int i = 1; i <= n; i++) {
        //������ ��� ä���
        if (res[i]) continue;
        while (chk[t]) t++;
        res[i] = t;
        chk[t] = 1;
    }
    for (int i = 1; i <= n; i++) {
        printf("%d\n", res[i]);
    }
    return 0;
}