#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 100000)명의 명예 점수(<= 100000, 자연수)가 주어진다. 모든 사람의 명예 점수를 1씩 깎는 행동을 반복하며
모든 라운드에서 명예 점수가 0이 되는 사람이 나오도록 하려면, 특정한 사람들의 명예 점수를 미리 깎는 일이 필요할 수 있다.
깎아야 하는 명예 점수 값의 합을 구한다. 명예 점수를 올려줄 수는 없다.

해결 방법 : 명예 점수를 오름차순으로 정렬한 다음, 맨 앞 사람의 명예 점수를 1로 바꾼다.
그 이후 사람들은 앞 사람과 명예 점수가 같다면 그대로 두고 그 외에는 앞 사람 + 1로 바꾼다.
이를 깎은 명예 점수의 합을 구하면 된다.

주요 알고리즘 : 그리디 알고리즘, 정렬

출처 : 고려대 2018B F번 / 2018I C번
*/

int a[103000];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n;
    long long r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    qsort(a, n, sizeof(int), cmp1);
    r += a[0] - 1;
    a[0] = 1;
    for (int i = 1; i < n; i++) {
        if (a[i] == a[i - 1]) continue;
        r += a[i] - a[i - 1] - 1;
        a[i] = a[i - 1] + 1;
    }
    printf("%lld", r);
    return 0;
}