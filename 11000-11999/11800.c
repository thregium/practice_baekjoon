#include <stdio.h>

/*
���� : �ֻ����� �� ���� �־��� ��, �� ���� ���ϴ� ���� ���� ����Ѵ�.(���� ����)

�ذ� ��� : �־������ �����Ѵ�.

�ֿ� �˰��� : ����, ���̽� ��ũ

��ó : Arab 2014 B��
*/

char* s1[6] = { "Yakk", "Doh", "Seh", "Ghar", "Bang", "Sheesh" };
char* s2[6] = { "Habb Yakk", "Dobara", "Dousa", "Dorgy", "Dabash", "Dosh" };

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int main(void) {
    int t, a, b;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        scanf("%d %d", &a, &b);
        printf("Case %d: ", tt);

        if (a < b) swap(&a, &b);
        if (a == b) {
            printf("%s\n", s2[a - 1]);
        }
        else if (a == 6 && b == 5) printf("Sheesh Beesh\n");
        else printf("%s %s\n", s1[a - 1], s1[b - 1]);
    }
    return 0;
}