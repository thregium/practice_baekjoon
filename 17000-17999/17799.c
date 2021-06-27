#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 100000)개의 자연수가 주어질 때, 두 자연수의 합이 C 이하가 되도록 두 자연수를 합친 집합을 만들거나,
한 자연수만으로 집합을 만들 수 있다. 집합의 수를 가능하면 적게 만들려고 할 때, 집합의 개수를 구한다.

해결 방법 : 가능한 큰 수까지 혼자 떨어지지 않도록 하는 것이 집합의 개수를 줄이는 방법임을 알 수 있다.
따라서, 자연수를 정렬한 후, 양쪽 끝에서 포인터를 좁혀가며 현재 두 개의 포인터가 가리키는 값의 합이 C 이하가 되면
양쪽에서 포인터를 좁히고, 안된다면 오른쪽에서만 포인터를 좁히는 방식을 통해 집합을 구할 수 있고, 이를 행한 횟수를 구하면 답이 된다.

주요 알고리즘 : 그리디 알고리즘, 투 포인터

출처 : UKIEPC 2019 F번
*/

int bucket[103000];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, c, p1, p2, r = 0;
    scanf("%d %d", &n, &c);
    for (int i = 0; i < n; i++) {
        scanf("%d", &bucket[i]);
    }
    qsort(bucket, n, sizeof(int), cmp1);
    p1 = 0;
    p2 = n - 1;
    while (p1 < p2) {
        if (bucket[p1] + bucket[p2] <= c) p1++;
        r++;
        p2--;
    }
    if (p1 == p2) r++;
    printf("%d", r);
    return 0;
}