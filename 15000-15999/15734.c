#include <stdio.h>

/*
���� : L, R, A�� �־��� ��, A�� L�� R �� �ƹ� �����γ� �� �� �ִٸ�, L�� R�� ���� ���� ���߷��� �� ��,
�ִ� ���� ���� �� �� �ִ��� ���Ѵ�.

�ذ� ��� : A�� �� �� ���� ������ ������ ����, ���´ٸ� �յ��ϰ� �й����ִ� ���� �ּ��̴�. �� �������� A�� ���ڶ����ٸ�
�ű⼭ �ٷ� �����ϸ� �ȴ�.

�ֿ� �˰��� : ����

��ó : �Ѿ��E 2018 P2��
*/

int main(void) {
    int l, r, a;
    scanf("%d %d %d", &l, &r, &a);
    if (l > r) {
        if (a < l - r) {
            printf("%d", (r + a) * 2);
            return 0;
        }
        else {
            a -= l - r;
            r = l;
        }
    }
    else if (r > l) {
        if (a < r - l) {
            printf("%d", (l + a) * 2);
            return 0;
        }
        else {
            a -= r - l;
            l = r;
        }
    }
    if (a & 1) printf("%d", l + r + a - 1);
    else printf("%d", l + r + a);
    return 0;
}