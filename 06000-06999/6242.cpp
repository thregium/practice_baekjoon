#include <stdio.h>
#include <stdlib.h>
#include <map>
using namespace std;

/*
문제 : 좌표평면상에 N(N <= 40000)개의 직사각형이 주어진다. 각 직사각형은 X축을 한 변으로 하고 있다.
이때, 각 직사각형의 높이(<= 10^9)와 X좌표의 시작, 끝(<= 10^9)이 주어지면 직사각형의 합집합의 넓이를 구한다.

해결 방법 : 각 직사각형의 시작점과 끝점들을 X축의 좌표를 기준으로 정렬한다. 그 후 각 점들을 차례로 살펴보면서
시작점이 나오면 높이의 목록에 해당 점을 추가하고, 끝점이 나오면 해당 점을 제거한다.
이때, 매번 이를 시행하기 전 이전 점과의 X축 차이를 확인하고 가장 높은 높이의 점 * 이전 점과의 차이만큼을
결괏값에 더해나간다. 이것이 그 구간에서 가장 높은 직사각형의 구간일 것이고, 따라서 그 만큼의 넓이가 추가된다.
이를 반복해 나온 결괏값이 답이 된다.

주요 알고리즘 : 자료구조, 맵, 스위핑

출처 : USACO 2007O S1번
*/

int vert[103000][3];
map<int, int> mp;

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
        scanf("%d %d %d", &vert[i * 2][0], &vert[i * 2 + 1][0], &vert[i * 2][1]);
        vert[i * 2 + 1][1] = vert[i * 2][1];
        vert[i * 2 + 1][2] = 1;
    }
    qsort(vert, n * 2, sizeof(int) * 3, cmp1);
    for (int i = 0; i < n * 2; i++) {
        if (i > 0 && mp.size()) {
            r += (long long)(vert[i][0] - vert[i - 1][0]) * (--mp.end())->first;
        }
        if (vert[i][2]) {
            if (mp.empty()) return 1;
            if (mp.find(vert[i][1]) != mp.end()) {
                (mp.find(vert[i][1])->second)--;
                if (mp.find(vert[i][1])->second == 0) mp.erase(vert[i][1]);
            }
            else return 1;
        }
        else {
            if (mp.find(vert[i][1]) != mp.end()) {
                (mp.find(vert[i][1])->second)++;
            }
            else mp.insert(pair<int, int>(vert[i][1], 1));
        }
    }
    printf("%lld", r);
    return 0;
}