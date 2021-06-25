#include <stdio.h>
#include <vector>
#define INF 987654321
using namespace std;

/*
문제 : 1부터 9까지의 수가 쓰인 종이가 있다. 주사위 2개를 던져서 지우는 수의 합이 주사위 수의 합과 같은 수가 되도록 수 몇개를 지운다.
이를 반복하다가 지울 수 없는 수가 나오면 현재 쓰인 수를 숫자로 생각하여 점수로 얻는다. 현재 게임의 상태가 주어질 때,
가장 점수를 높게 얻는 전략과 가장 낮게 얻는 전략에 대해 선택해야 하는 수와 그때 얻을 수 있는 점수의 기댓값을 구한다.

해결 방법 : 먼저, 주사위의 각 합별로 지울 수 있는 수의 조합을 구한다. 그 다음으로는 모든 수의 상태(2^9가지)에 대해
역시 지울 수 있는 수의 조합을 주사위의 합별로 구한 다음, 이것을 간선으로 연결해 그래프를 만든다.
이제 이 그래프에서 주사위의 합별로 경우를 나누어 가장 작은 수와 가장 큰 수가 나올 때의 기댓값을 구한다.
비트마스킹을 통해 상태를 만들었다면 0부터 순서대로 나가면 지우는 것은 항상 수가 작아지는 방향이므로 DP를 수행하는 것이 가능해진다.
DP를 수행한 다음에는 비로소 수들을 입력받고 현재 상태를 확인한 후 현재 상태에서 가능한 최댓값과 최솟값을 찾은 다음
그로 가는 방법과 그에 대한 기댓값을 구하면 된다.

주요 알고리즘 : DP, 트리DP, 확률론, 조합론, 구현

출처 : PacNW 2018 K/X번 // SEUSA 2018 F번 / 2018D2 E번
*/

int nums[9], ins[512], ends[512];
double tlow[16], thigh[16], prob[16], lowest[512], highest[512];
vector<int> rev[512];
vector<pair<int, int>> cango[512];
vector<vector<int>> comb[16];

int main(void) {
    for (int i = 2; i <= 12; i++) {
        for (int a = 1; a <= 9; a++) {
            if (a == i) comb[i].push_back(vector<int>{a});
            for (int b = a + 1; b <= 9; b++) {
                if(a + b == i) comb[i].push_back(vector<int>{a, b});
                for (int c = b + 1; c <= 9; c++) {
                    if(a + b + c == i) comb[i].push_back(vector<int>{a, b, c});
                    for (int d = c + 1; d <= 9; d++) {
                        if (a + b + c + d == i) comb[i].push_back(vector<int>{a, b, c, d}); //합이 12 이하인 조합 추가
                    }
                }
            }
        }
    }

    int ok, ito;
    for (int i = 0; i < 512; i++) {
        for (int j = 0; j < 9; j++) {
            nums[j] = ((i >> j) & 1) * (j + 1);
            if (nums[j]) ends[i] = ends[i] * 10 + nums[j]; //자릿수
        }
        for (int j = 2; j <= 12; j++) {
            for (auto k : comb[j]) {
                ok = 1;
                ito = i;
                for (int l : k) {
                    if (!nums[l - 1]) ok = 0; //해당 수가 없는 경우 실패 처리
                    else ito -= (1 << (l - 1));
                }
                if (ok) {
                    cango[i].push_back(pair<int, int>(j, ito));
                    rev[ito].push_back(i);
                    ins[i]++;
                }
            }
        }
    }

    for (int i = 2; i <= 12; i++) {
        if (i < 7) prob[i] = 1.0 / 36 * (i - 1); //확률 추가
        else prob[i] = 1.0 / 36 * (13 - i);
    }

    for (int j = 0; j < 512; j++) {
        //DAG DP
        for (int k = 2; k <= 12; k++) {
            tlow[k] = INF;
            thigh[k] = -INF;
        }

        for (int k = 0; k < cango[j].size(); k++) {
            //주사위의 합별로 가장 작은 값과 가장 큰 값을 얻어온다.
            if (lowest[cango[j][k].second] < tlow[cango[j][k].first]) {
                tlow[cango[j][k].first] = lowest[cango[j][k].second];
            }
            if (highest[cango[j][k].second] > thigh[cango[j][k].first]) {
                thigh[cango[j][k].first] = highest[cango[j][k].second];
            }
        }
        for (int k = 2; k <= 12; k++) {
            //가장 작은 값과 큰 값에 해당 합이 나올 확률을 곱해서 더하되, 그 값을 지울 방법이 없다면 현재 수를 대신 사용함.
            if (tlow[k] > 234567890) {
                lowest[j] += ends[j] * prob[k];
            }
            else lowest[j] += tlow[k] * prob[k];
            if (thigh[k] < -100) {
                highest[j] += ends[j] * prob[k];
            }
            else highest[j] += thigh[k] * prob[k];
        }
        for (int k : rev[j]) ins[k]--;
        ins[j]--;
    }

    int d, a, b, start = -1, lt = -1, ht = -1, ln = 0, hn = 0;
    double l = INF, h = -INF;
    scanf("%d %d %d", &d, &a, &b);
    for (int i = 0; i < 512; i++) {
        if (d == ends[i]) start = i; //시작점 확인
    }
    for (int i = 0; i < cango[start].size(); i++) {
        if (cango[start][i].first != a + b) continue;
        if (lowest[cango[start][i].second] < l) {
            //가장 작은 수 확인
            l = lowest[cango[start][i].second];
            lt = cango[start][i].second;
        }
        if (highest[cango[start][i].second] > h) {
            //가장 큰 수 확인
            h = highest[cango[start][i].second];
            ht = cango[start][i].second;
        }
    }
    if (l == INF) {
        l = ends[start];
        h = ends[start];
    }
    for (int i = 1; i <= 9; i++) {
        if (lt < 0) {
            ln = -1;
            hn = -1;
            break;
        }
        if ((start - lt) & (1 << (i - 1))) ln = ln * 10 + i;
        if ((start - ht) & (1 << (i - 1))) hn = hn * 10 + i;
    }
    printf("%d %.5f\n", ln, l);
    printf("%d %.5f", hn, h);
    return 0;
}