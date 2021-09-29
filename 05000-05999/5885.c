#include <stdio.h>
#include <stdlib.h>

/*
문제 : 연속한 N(N <= 100000)개 지점의 고도가 주어질 때, 일정 고도 이하의 지점들에 물을 채운다면 생기는 섬의 개수 가운데
가장 많은 것을 구한다. 고도의 범위는 10^9 이하의 자연수이다.

해결 방법 : N개의 지점들을 높이가 높은 순으로 정렬한 다음, 가장 높이가 높은 지점부터 물을 빼가며 생기는 섬의 개수를
구해나간다. 만약 새로 육지가 되는 지점의 양 옆이 모두 물(또는 빈 칸)이라면 새로운 섬이 생기게 된다. 반대로, 
양 옆이 모두 육지인 경우 두 섬을 이어주게 되므로 섬의 개수는 줄어든다. 한쪽만 육지라면 섬의 개수에는 변동이 없다.
섬의 개수를 높이의 변동이 생기는 지점마다 확인해 가장 많을 때의 값을 구하면 답이 된다.

주요 알고리즘 : 구현, 정렬

출처 : USACO 2012O B3번
*/

int land[103000][2], chk[103000];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai < bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    //freopen("E:\\PS\\Olympiad\\USA\\1_Bronze\\2012_04\\islands\\13.in", "r", stdin);
    int n, is = 0, r = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &land[i][0]);
        land[i][1] = i;
    }
    qsort(&land[1], n, sizeof(int) * 2, cmp1);
    for (int i = 1; i <= n; i++) {
        chk[land[i][1]] = 1;
        if (!chk[land[i][1] - 1] && !chk[land[i][1] + 1]) is++;
        else if (chk[land[i][1] - 1] && chk[land[i][1] + 1]) is--;
        if (land[i][0] != land[i + 1][0] && is > r) r = is;
    }
    printf("%d", r);
    return 0;
}