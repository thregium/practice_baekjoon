#include <stdio.h>
#include <math.h>
#include <queue>
using namespace std;

/*
문제 : N(N <= 1000)명의 사람이 있고, 2가지 물건이 각각 M개, P(N <= M, P <= 1000)개 있다.
각 물건들은 2차원 평면상의 절댓값 10000 이하 정수 점에 있다.
이때, 각 사람을 가장 가까운 물건과 사람의 쌍부터 차례로 매칭시킬 때, 모든 매칭의 거리 합을 구한다.
가장 가까운 쌍이 여럿인 경우 앞 번호의 사람 먼저, 여전히 여럿이라면 앞 번호의 물건 먼저 매칭시킨다.

해결 방법 : 우선순위 큐에 모든 매치를 작은 값이 위로 오도록 담아두고 각 매치에 대해
사람과 물건이 매치되지 않은 경우 그 거리를 결과에 더하고 사람과 물건의 방문 처리를 한다.
이를 두 가지 물건에 대해 반복하고 답을 출력하면 된다.

주요 알고리즘 : 자료 구조, 우선순위 큐

출처 : ECNA 2019 A번
*/

int posj[1024][2], post[1024][2], chkj[1024], chkt[1024];
priority_queue<pair<double, pair<int, int>>, vector<pair<double, pair<int, int>>>, greater<>> pq;

double getdist(int a, int b) {
    return sqrt(pow(abs(posj[a][0] - post[b][0]), 2) + pow(abs(posj[a][1] - post[b][1]), 2));
}

int main(void) {
    int n, m, p, a, b;
    double dist, res = 0.0;
    scanf("%d %d %d", &n, &m, &p);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &posj[i][0], &posj[i][1]);
    }
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &post[i][0], &post[i][1]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            pq.push({ getdist(i, j), {i, j} });
        }
    }
    while (pq.size()) {
        a = pq.top().second.first;
        b = pq.top().second.second;
        dist = pq.top().first;
        pq.pop();
        if (chkj[a] || chkt[b]) continue;
        res += dist;
        chkj[a] = 1, chkt[b] = 1;
    }
    for (int i = 0; i < 1024; i++) {
        chkj[i] = 0, chkt[i] = 0;
    }

    for (int i = 0; i < p; i++) {
        scanf("%d %d", &post[i][0], &post[i][1]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++) {
            pq.push({ getdist(i, j), {i, j} });
        }
    }
    while (pq.size()) {
        a = pq.top().second.first;
        b = pq.top().second.second;
        dist = pq.top().first;
        pq.pop();
        if (chkj[a] || chkt[b]) continue;
        res += dist;
        chkj[a] = 1, chkt[b] = 1;
    }
    printf("%.9f", res);
    return 0;
}