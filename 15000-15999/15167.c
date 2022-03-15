#include <stdio.h>
#include <stdlib.h>

/*
���� : ������ ������ �迭���� A��° ���� B(A, B <= 10^9)��° �� ������ ����ư �Ÿ��� ���Ѵ�.

�ذ� ��� : �켱 �� ��° ������ �� Ȯ���ϰ� �迭�� �������� �� ���� ��ǥ�� ���Ѵ�.
�׸��� ����ư �Ÿ��� ���ϸ� �ȴ�.

�ֿ� �˰��� : ����

��ó: SPPC 2016 A��
*/

typedef struct xy {
    int x, y;
} xy;

xy getpos(int n) {
    int sz = 0;
    xy res = { 0, 0 };
    if (n == 1) return res;
    while ((sz * 2 + 1) * (sz * 2 + 1) < n) sz++;
    n -= (sz * 2 - 1) * (sz * 2 - 1);
    
    for (int i = 0; i < 4; i++) {
        if (n <= sz * 2) {
            if (i == 0) {
                res.x = sz, res.y = n - sz;
            }
            else if (i == 1) {
                res.x = sz - n, res.y = sz;
            }
            else if (i == 2) {
                res.x = -sz, res.y = sz - n;
            }
            else if (i == 3) {
                res.x = n - sz, res.y = -sz;
            }
            break;
        }
        else n -= sz * 2;
    }
    return res;
}

int main(void) {
    int a, b;
    xy posa, posb;
    scanf("%d %d", &a, &b);
    posa = getpos(a);
    posb = getpos(b);
    printf("%d", abs(posa.x - posb.x) + abs(posa.y - posb.y));
    return 0;
}