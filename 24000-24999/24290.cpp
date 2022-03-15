#include <stdio.h>
#include <unordered_set>
using namespace std;

/*
문제 : N(N <= 1000)개의 점이 좌표평면상에 주어질 때, 점들을 이어 만들 수 있는 직사각형의 개수를 구한다.
축과 평행할 필요는 없다. 각 점의 좌표 범위는 10000 이하의 자연수이다.

해결 방법 : 각 점들의 위치를 해시셋에 저장한 다음, 모든 점 3개의 쌍에 대해 직각인지 여부를 확인한다.
직각이라면 다른 1개의 점을 해시셋에서 찾고 있다면 답을 1씩 올려나간다.
그 후 나온 답이 최종 결과가 된다.

주요 알고리즘 : 자료 구조, 해시셋, 기하학

출처 : IATI 2021C 3번
*/

long long point[1024][2];
unordered_set<int> ps;

int isright(int a, int b, int c) {
    if ((point[b][0] - point[a][0]) * (point[c][0] - point[a][0]) +
        (point[b][1] - point[a][1]) * (point[c][1] - point[a][1]) == 0) return 1;
    else return 0;
}

int main(void) {
    int n, r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        //point[i][0] = i + 1, point[i][1] = i + 1;
        scanf("%lld %lld", &point[i][0], &point[i][1]);
        ps.insert((point[i][0] << 14) + point[i][1]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (isright(i, j, k)) {
                    r += (ps.find(((point[j][0] + (point[k][0] - point[i][0])) << 14) +
                        (point[j][1] + (point[k][1] - point[i][1]))) != ps.end());
                }
                else if (isright(j, i, k)) {
                    r += (ps.find(((point[i][0] + (point[k][0] - point[j][0])) << 14) +
                        (point[i][1] + (point[k][1] - point[j][1]))) != ps.end());
                }
                else if (isright(k, i, j)) {
                    r += (ps.find(((point[j][0] + (point[i][0] - point[k][0])) << 14) +
                        (point[j][1] + (point[i][1] - point[k][1]))) != ps.end());
                }
            }
        }
    }
    if (r & 3) return 1;
    printf("%d", r >> 2);
    return 0;
}