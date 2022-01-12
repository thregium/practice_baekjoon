#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 100)개의 투표지가 주어지고, 각 투표지에는 알파벳 대문자가 적혀 있다. 이때, 1위를 하는 후보가 있는 지 구하고,
있다면 그 후보와 1위가 확정된 투표지 번호를, 없다면 TIE를 출력한다.

해결 방법 : 매 투표지마다 투표된 후보의 득표수를 1 올리고 순위를 정렬한다. 그리고 매번 1위 후보와 2위 후보의 격차를
확인한 다음, 남은 투표지 수보다 많으면 그때의 후보와 투표지 번호를 출력한다. 끝까지 그러한 적이 없다면
TIE를 출력하면 된다.

주요 알고리즘 : 구현, 시뮬레이션, 정렬

출처 : JDC 2016 B번
*/

int cand[26][2];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai < bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, r;
    char c;
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        for (int i = 0; i < 26; i++) {
            cand[i][0] = 0;
            cand[i][1] = i;
        }
        r = 0;
        for (int i = 0; i < n; i++) {
            scanf(" %c", &c);
            for (int j = 0; j < 26; j++) {
                if (c - 'A' == cand[j][1]) cand[j][0]++;
            }
            qsort(cand, 26, sizeof(int) * 2, cmp1);
            if (cand[0][0] - cand[1][0] > n - i - 1 && !r) {
                printf("%c %d\n", cand[0][1] + 'A', i + 1);
                r = 1;
            }
        }
        if (r == 0) printf("TIE\n");
    }
    return 0;
}