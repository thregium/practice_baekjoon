#include <stdio.h>
#define INF 1012345678

/*
���� : N(N <= 11)���� �� ���̿� �����ڸ� ������ �����־� ���� �� �ִ� ���� ū ���� ���� ���� ���� ���Ѵ�.
��, ���� �� �ִ� �������� ������ ������ �ְ�, ������ �켱������ �����Ѵ�.

�ذ� ��� : �� �պ��� ���ʷ� �����ִ� �����ڵ��� �ϳ��� �������� Ȯ���Ѵ�. ������� �����ڰ� ���ٸ� ������ �ʰ�
�ٸ� �����ڸ� Ȯ���غ���.

�ֿ� �˰��� : ���Ʈ ����, ��Ʈ��ŷ
*/

int a[16], op[4];
int highest = -INF, lowest = INF; //�ִ�, �ּڰ��� �Ұ����� ������ ����

track(int n, int c, int m) {
    if (c == n - 1) {
        if (m > highest) highest = m;
        if (m < lowest) lowest = m;
        return;
    }
    for (int i = 0; i < 4; i++) {
        if (!op[i]) continue;
        op[i]--;
        if (i == 0) track(n, c + 1, m + a[c + 1]);
        else if (i == 1) track(n, c + 1, m - a[c + 1]);
        else if (i == 2) track(n, c + 1, m * a[c + 1]);
        else if (i == 3) track(n, c + 1, m / a[c + 1]);
        op[i]++;
    }
}

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < 4; i++) {
        scanf("%d", &op[i]);
    }
    track(n, 0, a[0]);
    printf("%d\n%d", highest, lowest);
    return 0;
}