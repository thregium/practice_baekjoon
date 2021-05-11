#include <stdio.h>

/*
���� : S�� T(S < T <= 100)�� �־��� ��, S�� T�� ����µ� ���� ������� �ּ� �� �� ��� �ϴ��� ���Ѵ�.
1. S�� 2�� ���ϰ� T�� 3�� ���Ѵ�. / 2. S�� 1�� ���Ѵ�.

�ذ� ��� : S�� T���� Ŀ���� ��� ���� ������ (2, 1)�� ��츦 �����ϸ� S�� T�� ���� �� ������ �� �� �ִ�.
�׷���, �׷��� ��찡 ���� ���� ����, S�� T�� ������ �۾� ��Ʈ��ŷ�� �ϴ��� �ð� ���� ����� Ǯ �� �ִ�.

�ֿ� �˰��� : ��Ʈ��ŷ

��ó : �߾Ӵ� 2017R B��
*/

int best;

void track(int x, int y, int c) {
    if (x == y) {
        if (c < best) best = c;
        return;
    }
    else if (x > y) return;
    track(x * 2, y + 3, c + 1);
    track(x + 1, y, c + 1);
}

int main(void) {
    int n, s, t;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &s, &t);
        best = 999;
        track(s, t, 0);
        printf("%d\n", best);
    }
    return 0;
}