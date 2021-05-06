#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

/*
문제 : 좌표평면상에 N(N <= 5000)개의 점들이 있다. 이 점들을 이어서 만들 수 있는 모든 내각이 135도이고 XY축과 평향한 팔각형의 수를 구한다.

해결 방법 : 모든 점에 대해 그 지점에서 출발했을 때의 팔각형의 수를 구하고, 그 값들을 더하면 된다.
점들마다 미리 방향을 정해둔 다음 모든 점들에 대해 해당 지점이 X번째 점인 경우의 수를 다이나믹 프로그래밍을 통해 구하면 되는데, 
그러한 경우의 수는 X - 1번째 점에서 해당 점이 현재 방향으로 선을 그었을 때 일직선이 되는 경우의 수를 모두 더한 것과 같다.
그런데 그렇게 되면 시간 복잡도 상 시간 내 통과가 어려워진다.(N^3), 따라서, 이것을 빠르게 풀 수 있는 방법을 찾아야 하는데,
누적합을 이용하면 빠르게 찾을 수 있다. 먼저, 8방향에 대해 각각의 점들을 들어가는 선에 따라 분류한다.
그 다음 각 선의 점들을 이동 방향에 따라 정렬해 놓고, 점화식을 세울 때, 해당 선에서 그 점의 누적 합을 구한다.
X번째 점에서의 값은 해당 선에서 X - 1번째 값의 누적 합이 되는 것이다.
이를 반복한 다음, 원래 위치로 돌아온 점에서의 값들을 합하면 팔각형의 수를 얻을 수 있다.

주요 알고리즘 : 다이나믹 프로그래밍, 누적 합, 기하학

출처 : BAPC 2020P E번
*/

//방향 : 우 -> 우하 -> 하 -> 좌하 -> 좌 -> 좌상 -> 상 -> 우상
long long points[5120][2], mem[5120][9];
vector<vector<long long>> lines[8];
int sorting = 0;

int cmp1(int a, int b) {
    //정렬 함수. 이동 방향 순으로 정렬한다.
    int t = 0;
    switch (sorting & 3) {
    case 0:
        t = (points[a][1] < points[b][1]);
        break;
    case 1:
        t = (points[a][0] + points[a][1] < points[b][0] + points[b][1]);
        break;
    case 2:
        t = (points[a][0] < points[b][0]);
        break;
    case 3:
        t = (points[a][0] - points[a][1] < points[b][0] - points[b][1]);
        break;
    }
    if (sorting >= 4) t = !t;
    return t;
}

int main(void) {
    int n, tmp;
    long long sum, r = 0;
    //freopen("C:\\1_공부\\PS\\ICPC\\Europe\\BAPC Pre\\2020\\E\\data\\secret\\a-gridh-90-90-2200000.in", "r", stdin);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld %lld", &points[i][0], &points[i][1]);
    }
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < n; j++) {
            tmp = 1;
            for (int k = 0; k < lines[i].size(); k++) {
                //해당 방향에 있는 선들에 대해 지금 보는 점이 현재까지 있는 선에 들어갈 수 있는지 검사한다.
                if (!lines[i][k].size()) continue;
                switch (i & 3) {
                case 0:
                    if (points[j][0] == points[lines[i][k][0]][0]) {
                        lines[i][k].push_back(j);
                        tmp = 0;
                    }
                    break;
                case 1:
                    if (points[j][0] - points[j][1] == points[lines[i][k][0]][0] - points[lines[i][k][0]][1]) {
                        lines[i][k].push_back(j);
                        tmp = 0;
                    }
                    break;
                case 2:
                    if (points[j][1] == points[lines[i][k][0]][1]) {
                        lines[i][k].push_back(j);
                        tmp = 0;
                    }
                    break;
                case 3:
                    if (points[j][0] + points[j][1] == points[lines[i][k][0]][0] + points[lines[i][k][0]][1]) {
                        lines[i][k].push_back(j);
                        tmp = 0;
                    }
                    break;
                }
                if (!tmp) break;
            }
            if (!tmp) continue;

            lines[i].push_back(vector<long long>());
            lines[i][lines[i].size() - 1].push_back(j);
            //들어갈 수 없는 경우 새로운 선을 만든다.
        }
    }

    for (int i = 0; i < 8; i++) {
        sorting = i;
        for (int j = 0; j < lines[i].size(); j++) {
            sort(lines[i][j].begin(), lines[i][j].end(), cmp1); //각 선들을 정렬한다.
        }
    }

    for (int i = 0; i < n; i++) {
        mem[i][0] = 1; //시작점만 1로 맞춰둔다.
        for (int step = 1; step <= 8; step++) {
            for (int j = 0; j < lines[step - 1].size(); j++) {
                sum = 0; //누적합을 초기화한다.
                for (int k = 0; k < lines[step - 1][j].size(); k++) {
                    mem[lines[step - 1][j][k]][step] = sum; //해당 위치의 값은 현재 선에 있는 점들의 이전 단계의 누적 합과 같다.
                    sum += mem[lines[step - 1][j][k]][step - 1]; //누적 합을 업데이트한다.
                }
            }
        }
        r += mem[i][8]; //다시 돌아온 값이 해당 점에서 출발한 팔각형의 수와 같다.
        for (int j = 0; j < n; j++) {
            for (int k = 0; k <= 8; k++) {
                mem[j][k] = 0; //메모리를 초기화한다.
            }
        }
    }
    printf("%lld", r);
    return 0;
}