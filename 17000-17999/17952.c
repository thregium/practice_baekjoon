#include <stdio.h>

/*
���� : N(N <= 10^6)�е��� ������ �־����ų� �־����� ���� ��, �־��� �������� ������ �־��� ��Ĵ��
����� ���� �� �ִ� ������ ���Ѵ�.

�ذ� ��� : �� �и��� ������ ���ÿ� �߰��ϰ�, ���ÿ� ������ �ִٸ� �� ���� ������ 1�� �����Ų��.
�� �� ������ �����ٸ� �� ������ ������ �ᱣ���� �߰��ϰ� �� ���Ҹ� ���ÿ��� ����.
�̷��� ��� �����Ͽ� ���� ������ ����ϸ� �ȴ�.

�ֿ� �˰��� : �ڷ� ����, ����, �ùķ��̼�

��ó : �Ѿ�� 6ȸ AA/BA��
*/

int homework[1048576][2];
int hcnt = 0;

int main(void) {
    int n, o, a, t, score = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &o);
        if (o) {
            scanf("%d %d", &a, &t);
            homework[hcnt][0] = a;
            homework[hcnt][1] = t;
            hcnt++;
        }
        if (hcnt == 0) continue;
        homework[hcnt - 1][1]--;
        if (homework[hcnt - 1][1] == 0) {
            score += homework[hcnt - 1][0];
            hcnt--;
        }
    }
    printf("%d", score);
    return 0;
}