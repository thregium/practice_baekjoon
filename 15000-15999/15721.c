#include <stdio.h>

/*
���� : A(A <= 2000)���� ������ ������ �� ��, T(T <= 10000)��° ���� �� �Ǵ� ����� �� ��° ����� ��ġ�� �Ǵ��� ���Ѵ�.

�ذ� ��� : T�� ���� ���̹Ƿ� ������ ���� ������ ������. �Ź� �� �Ǵ� ���⸦ ��ĥ �� ���� T���� �Ǿ����� Ȯ���ϰ�
T���� �Ǵ� ���� Ž���� �����ϰ� �ش� ��°������ Ƚ���� ����ϸ� �ȴ�.

�ֿ� �˰��� : ����, �ùķ��̼�

��ó : �߾Ӵ� 2018R 3��
*/

int check(int g, int t, int cb, int cd) {
    if ((g == 0 && cb < t) || (g == 1 && cd < t)) return 0;
    else return 1;
}

int main(void) {
    int a, t, g, cb = 0, cd = 0, cn = 2, r = 0;
    scanf("%d%d%d", &a, &t, &g);
    while (!check(g, t, cb, cd)) {
        for (int i = 0; i < 2; i++) {
            cb++;
            if (check(g, t, cb, cd)) break;
            r++;
            cd++;
            if (check(g, t, cb, cd)) break;
            r++;
        }
        for (int i = 0; i < cn; i++) {
            cb++;
            if (check(g, t, cb, cd)) break;
            r++;
        }
        if (check(g, t, cb, cd)) break;
        for (int i = 0; i < cn; i++) {
            cd++;
            if (check(g, t, cb, cd)) break;
            r++;
        }
        if (check(g, t, cb, cd)) break;
        cn++;
    }
    printf("%d", r % a);
    return 0;
}