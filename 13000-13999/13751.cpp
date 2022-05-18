#include <stdio.h>
#include <stdlib.h>
#include <unordered_set>
using namespace std;

/*
문제 : B개의 봉과 P(B, P <= 14)개의 판이 있다. 이때, 판을 적절히 양쪽에 넣어(넣지 않을 수도 있음)
양쪽의 무게를 같게 만들 때, 전체 바벨의 무게 합이 될 수 있는 모든 경우를 오름차순으로 출력한다.
봉과 판의 무게는 모두 10^8 이하의 자연수이다.

해결 방법 : 각 판을 왼쪽/오른쪽에 넣는 모든 경우의 수를 따져보며 양쪽의 무게가 같은 경우를 살핀다.
이 과정에서 무게가 같은 경우가 많이 나올 수 있기 때문에 이때는 해시셋을 이용해 같은 무게인 경우는
한 가지로만 저장한다. 다시 이 값들을 정렬하여 출력하면 답이 된다.

주요 알고리즘 : 자료 구조, 해시셋, 브루트 포스

출처 : PacNW 2016 N번
*/

unordered_set<int> hs;
int bar[16], plate[16], tri[16], res[1048576];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int b, p, end, lt, rt, rcnt = 0;
    scanf("%d %d", &b, &p);
    for (int i = 0; i < b; i++) {
        scanf("%d", &bar[i]);
    }
    for (int i = 0; i < p; i++) {
        scanf("%d", &plate[i]);
    }
    end = 0;
    while (!end) {
        lt = 0, rt = 0;
        for (int i = 0; i < p; i++) {
            if (tri[i] == 1) lt += plate[i];
            else if (tri[i] == 2) rt += plate[i];
        }

        if (lt == rt) {
            for (int i = 0; i < b; i++) {
                hs.insert(lt + rt + bar[i]);
            }
        }

        tri[0]++;
        for (int i = 0; tri[i] == 3; i++) {
            if (i == p - 1) end = 1;
            tri[i + 1]++;
            tri[i] = 0;
        }
    }
    for (int i : hs) res[rcnt++] = i;
    qsort(res, rcnt, sizeof(int), cmp1);
    for (int i = 0; i < rcnt; i++) {
        printf("%d\n", res[i]);
    }
    return 0;
}