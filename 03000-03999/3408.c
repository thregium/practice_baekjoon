#include <stdio.h>
#include <stdlib.h>

/*
문제 : 길이 N(N <= 200000)의 수열이 주어질 때, 모든 부분 문자열에 유일한 원소가 있는 수열(non-boring sequence)인지 구한다.

해결 방법 : 만약 어떤 부분 문자열 내에서 유일한 원소가 있다면, 그 부분 문자열 내의 해당 원소를 포함하는 모든 부분 문자열은
non-boring이다. 그러므로 그 주변의 값들을 범위로 살펴보는 분할 정복을 통해 모든 부분 문자열이 그러한지 살펴보면 된다.

이를 위해서는 각 수들의 가장 가까운 왼쪽/오른쪽 위치가 어디인지를 알아야 한다. 좌표 압축을 한다면 각 수들의 마지막 위치를
확인함을 통해 정렬을 제외하고 O(N)에 전부 알아낼 수 있다. 그 값들을 아는 생태에서 가장 가까운 왼쪽 위치가
범위의 시작점보다 앞이고, 오른쪽이 범위의 끝점보다 뒤라면 해당 수는 유일한 것이다.

이때, 분할 정복을 하는 과정에서 수들이 계속 뒤쪽에서 나오면 시간 복잡도가 O(N^2)이 되어버린다.
이는 범위의 앞뒤로 확인을 하여 시간 복잡도를 줄일 수 있다. 만약 가운데 쯤에서 나오는 경우에는 범위가 크게 줄기 때문에
마지막에 살펴보더라도 여전히 O(N^2)이 보장되는 것이다.

주요 알고리즘 : 분할 정복

출처 : CERC 2012 D번
*/

int a[204800][3], same[204800][2], last[204800]; //a[][0] : 원래 수, a[][1] : 압축된 수, a[][2] : 원래 순서
//same[][0] : 왼쪽에서 가장 가까운 같은 수의 위치. 없으면 0, same[][1] : 오른쪽에서 ''. 없으면 203900
//last : 마지막으로 확인한 해당 수

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int cmp2(const void* a, const void* b) {
    int ai = *((int*)a + 2);
    int bi = *((int*)b + 2);
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int isboring(int s, int e) {
    //분할 정복을 통해 확인, 앞뒤로 이동하며 확인시 시간 복잡도 보장 가능
    if (s >= e) return 1;
    for (int i = s, j = e; i <= j; i++, j--) {
        if (same[i][0] < s && same[i][1] > e) return (isboring(s, i - 1) & isboring(i + 1, e));
        if (same[j][0] < s && same[j][1] > e) return (isboring(s, j - 1) & isboring(j + 1, e));
    }
    return 0;
}

int main(void) {
    int t, n, r;
    //freopen("E:\\PS\\ICPC\\Europe\\CERC\\2012\\d\\7.in", "r", stdin);
    //freopen("E:\\PS\\ICPC\\Europe\\CERC\\2012\\d\\7_t.out", "w", stdout);
    scanf("%d", &t);
    a[0][0] = -1;
    for (int tt = 0; tt < t; tt++) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i][0]);
            a[i][2] = i;
        }
        //좌표 압축
        qsort(a + 1, n, sizeof(int) * 3, cmp1);
        for (int i = 1; i <= n; i++) {
            if (a[i][0] == a[i - 1][0]) a[i][1] = a[i - 1][1];
            else a[i][1] = a[i - 1][1] + 1;
        }
        qsort(a + 1, n, sizeof(int) * 3, cmp2);
        //앞/뒤의 가장 가까운 수 전처리
        for (int i = 1; i <= n; i++) last[i] = 0;
        for (int i = 1; i <= n; i++) {
            same[i][0] = last[a[i][1]];
            last[a[i][1]] = i;
        }
        for (int i = 1; i <= n; i++) last[i] = 203900;
        for (int i = n; i > 0; i--) {
            same[i][1] = last[a[i][1]];
            last[a[i][1]] = i;
        }
        r = isboring(1, n);
        if (r) printf("non-boring\n");
        else printf("boring\n");
    }
    return 0;
}