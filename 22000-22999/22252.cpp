#include <stdio.h>
#include <string>
#include <unordered_map>
#include <queue>
using namespace std;

/*
문제 : Q(Q <= 100000)개의 쿼리에 응답한 후 현재 정보 가치의 합을 구한다.
1. (String)이 K(K <= 100000)개의 새로운 정보를 얻는다. 각 정보의 가치는 C(C <= 100000)이다.
2. (String)에게서 K(K <= 100000)개의 정보를 얻어온다. 그가 갖고 있는 가장 가치가 높은 순으로 K개이며,
갖고 있는 정보가 없거나 K개보다 적다면 있는 만큼만 얻어온다.
모든 정보의 개수는 10^6개 이하다. 각 (String)은 15자 이하다.

해결 방법 : 문자열과 우선순위 큐를 해시맵에 연결시켜 놓는다. 우선순위 큐는 최대 힙으로 만든다.
새로운 자가 정보를 얻으면 해시맵에 그 문자열을 등록시킨다. 그리고 새 정보마다 우선순위 큐에 추가한다.
그에게서 정보를 얻어올 때에는 해시맵에 없는 경우 그대로 넘어간다. 있는 경우에는 상위 K개 또는,
정보가 없어질 때 까지 전부 얻어와서 더한 다음 종료하면 된다.

주요 알고리즘 : 자료 구조, 해시맵, 우선순위 큐

출처 : 류호석 3회 2번
*/

unordered_map<string, priority_queue<int>> gori;
char buff[32];

int main(void) {
    int q, o, k, c;
    long long r = 0;
    string s;
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        scanf("%d %s %d", &o, buff, &k);
        s.assign(buff);
        if (o == 1) {
            if (gori.find(s) == gori.end()) gori.insert(make_pair(s, priority_queue<int>()));
            for (int j = 0; j < k; j++) {
                scanf("%d", &c);
                gori[s].push(c);
            }
        }
        else if (o == 2) {
            if (gori.find(s) == gori.end()) continue;
            for (int j = 0; j < k; j++) {
                if (gori[s].size() == 0) break;
                r += gori[s].top();
                gori[s].pop();
            }
        }
        else return 1;
    }
    printf("%lld", r);
    return 0;
}