#include <stdio.h>

/*
���� : 2���� �ֻ��� 2������ ������ ��, ������ �־��� ��Ģ��θ� ���� �̱�� �� ���Ѵ�.

�ذ� ��� : �� ��쿡 ���� ������ �ű�� ������ �� ū���� ã���� �ȴ�.

�ֿ� �˰��� : ����

��ó : VTH 2014 A��
*/

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int score(int a, int b) {
    if (a == 2 && b == 1) return 103000;
    else if (a == b) return 100 + a;
    else return a * 10 + b;
}

int main(void) {
    int a, b, c, d;
    while (1) {
        scanf("%d %d %d %d", &a, &b, &c, &d);
        if (a == 0) break;
        if (a < b) swap(&a, &b);
        if (c < d) swap(&c, &d);
        if (score(a, b) > score(c, d)) printf("Player 1 wins.\n");
        else if (score(a, b) < score(c, d)) printf("Player 2 wins.\n");
        else printf("Tie.\n");
    }
    return 0;
}