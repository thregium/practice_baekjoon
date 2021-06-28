#include <stdio.h>

/*
문제 : 주사위의 두 수가 주어질 때, 두 수를 뜻하는 고유 말을 출력한다.(이하 생략)

해결 방법 : 주어진대로 구현한다.

주요 알고리즘 : 구현, 케이스 워크

출처 : Arab 2014 B번
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