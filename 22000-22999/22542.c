#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
문제 : N(N <= 50)개의 작물이 있고, 각 작물의 이름, 가격, 열매의 단가, 열매의 개수, 생장 시간, 수확 횟수 등이 주어질 때,
각 작물을 효율이 좋은 순으로 출력한다. 작물의 효율은 수익 / 전체 생장 시간이다. 효율이 같다면 이름의 오름차순으로 출력한다.

해결 방법 : 각 작물의 생장 시간과 수익을 계산해 구조체에 넣는다. 그리고 효율 -> 이름 순으로 정렬하면 된다.
이때, 생장 시간과 수익을 모두 비교해야 하는 이유는 효율만으로 비교하면 실수 오차로 문제가 생길 수 있기 때문이다.

주요 알고리즘 : 수학, 정렬

출처 : JAG 2010D B번
*/

typedef struct species {
    char l[32];
    long long rev;
    long long tm;
} species;

species spe[64];

int cmp1(const void* a, const void* b) {
    species ai = *(species*)a;
    species bi = *(species*)b;
    if (ai.rev * bi.tm != ai.tm * bi.rev) return ai.rev * bi.tm < ai.tm * bi.rev ? 1 : -1;
    else return strcmp(ai.l, bi.l);
}

int main(void) {
    int n, p, a, b, c, d, e, f, s, m;
    //freopen("E:\\PS\\Contest\\Japanese Alumni Group\\2010D\\domestic-2010-judge-data\\domestic-2010-judge-data\\contest\\B\\B4", "r", stdin);
    //freopen("E:\\PS\\Contest\\Japanese Alumni Group\\2010D\\domestic-2010-judge-data\\domestic-2010-judge-data\\contest\\B\\B4_t.out", "w", stdout);
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        for (int i = 0; i < n; i++) {
            scanf("%s %d %d %d %d %d %d %d %d %d", spe[i].l, &p, &a, &b, &c, &d, &e, &f, &s, &m);
            spe[i].tm = a + b + c;
            for (int j = 0; j < m; j++) {
                spe[i].tm += d + e;
            }
            spe[i].rev = f * m * s - p;
        }
        qsort(spe, n, sizeof(species), cmp1);
        for (int i = 0; i < n; i++) {
            printf("%s\n", spe[i].l);
        }
        printf("#\n");
    }
    return 0;
}