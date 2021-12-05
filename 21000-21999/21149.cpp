#include <stdio.h>
#include <unordered_set>
using namespace std;

/*
문제 : N(N <= 10^9)명의 사람들이 있고, 메시지를 보낸 기록이 M(M <= 1000)개 있다. 각 메시지를 보낼 때 마다
보내는 사람은 그 메시지와 이전에 있는 읽지 않은 메시지를 전부 읽는다고 할 때, 각 메시지를 보낼 때 마다
모든 사람의 읽지 않은 메시지의 개수를 출력한다.

해결 방법 : 해시셋을 통해 각 메시지별로 읽은 사람의 수를 관리한다. 메시지를 보낼 때 마다 해당 메시지와
이전 메시지의 읽은 사람 목록에 그 사람을 추가하고, 전체 메시지에 대해 N - 읽은 사람 수를 더하면
읽지 않은 메시지의 합이 된다.

주요 알고리즘 : 자료 구조, 해시셋

출처 : SEUSA 2020 P번 // MidC 2020 M번 // MidAtl 2020 B번 // SCUSA 2020 P번
*/

unordered_set<int> read[1024];

int main(void) {
    int n, m, x;
    long long r;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &x);
        r = 0;
        for (int j = 0; j <= i; j++) {
            if (read[j].find(x) == read[j].end()) read[j].insert(x);
            r += n - read[j].size();
        }
        printf("#%lld\n", r);
    }
    return 0;
}