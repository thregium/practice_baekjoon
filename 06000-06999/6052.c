#include <stdio.h>

/*
���� : �ڿ��� S(S <= 18000)�� �־��� ��, S �̻��� ���� ������ ���� ���� ģ�� �� ���� ���Ѵ�. ��, �������� �������� �ʴ´�.

�ذ� ��� : S�� ����� ���� ���� ����(S�� ����), �ش� ���� S���� Ȯ���ϰ�, S��� ���� ���� ã�´�.
�ƴ϶�� �ش� ������ ����� ���� ���ϰ�, �װ��� S�� �� �� ���� ����ؼ� �ݺ��ϸ� �ȴ�.

�ֿ� �˰��� : ����, ������, ���Ʈ ����

��ó : USACO 2010O B1��
*/

int getpal(int x) {
    int r = 0;
    for (int i = 1; i < x; i++) {
        if (x % i == 0) r += i;
    }
    return r;
}

int main(void) {
    int s, t;
    scanf("%d", &s);
    for (int i = s;; i++) {
        t = getpal(i);
        if (t == i) continue;
        if (getpal(t) == i) {
            printf("%d %d", i, t);
            break;
        }
    }
    return 0;
}