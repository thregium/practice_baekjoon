#include <stdio.h>

/*
���� : N(N <= 1080)���� ��Ϲ����� �ִ�. (0, 0)�� ��ġ�� ��Ϲ����� ���� ��, ���������� ���ư��� ��Ϲ����� ��ġ�� ���Ѵ�.
��, �� ��Ϲ����� �ִ� 2���� ��Ϲ����͸� �پ��ְ�, (0, 0)�� ��ġ�� ��Ϲ����� ������ ��Ϲ����� �ִ� 1���� ��Ϲ����͸� �پ��ִ�.

�ذ� ��� : (0, 0)���� ���� �� �ִ� ��Ϲ����� ã�ư��� ���ʷ� ���� ��Ϲ����� ������. �� ��Ϲ����� ���ư� ��,
���� ���ư��� �Ǵ� ��Ϲ����� �� ��Ϲ������� �Ÿ��� �� ����� ���� �հ� ���� ����̰�, �̴� ��Ÿ����� ������ ���� �Ÿ��� ã�� ����
������ ���� ���� �� �ִ�. ���������� ���ư��� ��Ϲ����� ���� �ȴ�.
�̶�, ��Ϲ����� �����鼭 �̹� ���ȴ� ��Ϸ� ���ư��� �ʵ��� ���ȴ� ��Ϲ����� �湮 ó���� ����� �Ѵ�.

�ֿ� �˰��� : ����, ������, �ùķ��̼�

��ó : USACO 2008M B3��
*/

int rollers[1280][3], driving[1280];

int sqr(int a) {
    return a * a;
}

int main(void) {
    int n, checking = -1, nxt;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &rollers[i][0], &rollers[i][1], &rollers[i][2]);
        if (rollers[i][0] == 0 && rollers[i][1] == 0) {
            if (checking >= 0) return 1;
            checking = i;
            driving[i] = 1;
        }
    }
    if (checking < 0) return 2;
    for (int i = 1; i < n; i++) {
        nxt = -1;
        for (int j = 0; j < n; j++) {
            if (driving[j]) continue;
            if (sqr(rollers[j][0] - rollers[checking][0]) + sqr(rollers[j][1] - rollers[checking][1]) == sqr(rollers[j][2] + rollers[checking][2])) {
                if (nxt >= 0) return 3;
                nxt = j;
                driving[j] = 1;
            }
        }
        checking = nxt;
    }
    printf("%d %d", rollers[checking][0], rollers[checking][1]);
    return 0;
}