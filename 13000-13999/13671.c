#include <stdio.h>
#include <stdlib.h>

/*
문제 : 두 사람이 각각 A, B(A, B <= 10000)개의 카드를 갖고 있다. 두 사람이 서로 카드를 최대 몇 번이나 교한 가능한지 구한다.
둘 모두 갖고 있는 카드나 이미 교환했던 카드는 교환할 수 없다.

해결 방법 : 두 사람의 상대방이 갖지 않은 카드의 종류를 센다. 이 카드의 개수가 각 사람이 교환할 수 있는 카드의 수이고,
따라서, 둘 중 더 작은 수가 교환 가능한 횟수이다. 상대가 해당 카드를 갖고 있는지는 정렬 후 이분 탐색을 통해 구할 수 있다.

주요 알고리즘 : 그리디 알고리즘, 정렬, 이분 탐색

출처 : Brasil 2009 C번
*/

int alice[10240], beatriz[10240];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int a, b, ap, bp;
    int* key;
    //freopen("E:\\PS\\ICPC\\Latin America\\Brasil\\2009\\troca.in", "r", stdin);
    while (1) {
        scanf("%d %d", &a, &b);
        if (a == 0) break;
        for (int i = 0; i < a; i++) {
            scanf("%d", &alice[i]);
        }
        for (int i = 0; i < b; i++) {
            scanf("%d", &beatriz[i]);
        }
        qsort(alice, a, sizeof(int), cmp1);
        qsort(beatriz, b, sizeof(int), cmp1);
        ap = 0;
        bp = 0;
        for (int i = 0; i < a; i++) {
            if (i > 0 && alice[i] == alice[i - 1]) continue;
            key = &alice[i];
            if (bsearch(key, beatriz, b, sizeof(int), cmp1)) continue;
            else ap++;
        }
        for (int i = 0; i < b; i++) {
            if (i > 0 && beatriz[i] == beatriz[i - 1]) continue;
            key = &beatriz[i];
            if (bsearch(key, alice, a, sizeof(int), cmp1)) continue;
            else bp++;
        }
        if (ap > bp) printf("%d\n", bp);
        else printf("%d\n", ap);
    }
    return 0;
}