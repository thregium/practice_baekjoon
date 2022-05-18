#include <stdio.h>
#include <stdlib.h>
#include <unordered_map>
using namespace std;

/*
문제 : N(N <= 10^6)개의 물건 목록이 주어진다. 중복된 물건들을 합친 다음, 각 물건들의 번호와 개수를
나온 순서대로 출력한다.

해결 방법 : 해시맵을 사용하여 각 물건의 등장 순서와 개수를 번호에 대응시킨 다음,
해시맵의 모든 값들을 꺼내서 등장 순서 순으로 정렬한 후 출력하면 된다.

주요 알고리즘 : 자료 구조, 해시맵, 정렬

출처 : JPOI 2007 3-3번
*/

long long res[1048576][3];
unordered_map<int, pair<int, long long>> stor;

int cmp1(const void* a, const void* b) {
    long long ai = *(long long*)a;
    long long bi = *(long long*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, a, k, rp = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &a, &k);
        if (stor.find(a) == stor.end()) {
            stor.insert({ a, {i, k} });
        }
        else stor[a].second += k;
    }
    for (auto& i : stor) {
        res[rp][0] = i.second.first;
        res[rp][1] = i.first;
        res[rp++][2] = i.second.second;
    }
    qsort(res, rp, sizeof(long long) * 3, cmp1);
    printf("%d\n", rp);
    for (int i = 0; i < rp; i++) {
        printf("%lld %lld\n", res[i][1], res[i][2]);
    }
    return 0;
}