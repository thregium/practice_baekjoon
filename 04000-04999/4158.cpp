#include <stdio.h>
#include <stdlib.h>
#include <unordered_set>
using namespace std;

/*
문제 : N개의 CD 번호와 M(N, M <= 10^6)개의 CD 번호가 각각 오름차순으로 주어진다. 두 집합에서 동시에 존재하는
CD 번호의 개수를 출력한다. 단, 각 집합 내에서는 CD 번호가 같은 것이 존재하지 않는다.

해결 방법 : 해시셋을 이용해서 첫 번째 집합의 CD들을 해시 셋에 넣은 다음, 두 번째 집합의 원소들을 입력받을 때 마다
그 해시셋에 있던 것인지 확인하면 된다. 있는 경우 결괏값을 1씩 올려나간다.
입출력이 크기 때문에 fgets()를 사용하는 것이 좋다.

주요 알고리즘 : 자료 구조, 해시셋, 파싱

출처 : Waterloo 100926 A번
*/

unordered_set<int> us1;
char buff[128];

int main(void) {
    int n, m, x, r;
    while (1) {
        scanf("%d %d", &n, &m);
        if (n == 0 && m == 0) break;
        r = 0;
        getchar();
        for (int i = 0; i < n; i++) {
            fgets(buff, 100, stdin);
            x = strtoll(buff, NULL, 10);
            us1.insert(x);
        }
        for (int i = 0; i < m; i++) {
            fgets(buff, 100, stdin);
            x = strtoll(buff, NULL, 10);
            if (us1.find(x) != us1.end()) r++;
        }
        printf("%d\n", r);
        us1.clear();
    }
    return 0;
}