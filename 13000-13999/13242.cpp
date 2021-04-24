#include <stdio.h>
#include <set>
#include <vector>
using namespace std;

/*
문제 : N * M(N, M <= 1000) 크기의 비트들을 열 단위로 뒤집어 0인 행이 가장 많도록 할 때 0인 행의 수를 출력한다.

해결 방법 : 열 단위로 뒤집기 때문에 비트가 완전히 같은 행에서 한 열을 뒤집더라도 그 둘은 비트가 같을 것이다.
또한, 비트가 어떤 상태더라도 전부 0으로 만드는 것은 가능하고, 비트가 다른 열이라면 전부 0이 아닐 것이므로
비트가 완전히 같은 행의 갯수 가운데 가장 많은 것을 출력하면 되고, 이는 multiset을 이용해 빠르게 구할 수 있다.

주요 알고리즘 : 그리디 알고리즘

출처 : AIPO 2016F 3번
*/

multiset<vector<char>> s;

int main(void) {
    int n, m, r = 0;
    char c;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        vector<char> v;
        for (int j = 0; j < m; j++) {
            scanf(" %c", &c);
            v.push_back(c);
        }
        s.insert(v);
        if (s.count(v) > r) r = s.count(v);
    }
    printf("%d", r);
    return 0;
}