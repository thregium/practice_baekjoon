#include <stdio.h>
#include <string>
#include <map>
using namespace std;

/*
문제 : N(N <= 1000)대의 서로 다른 자동차가 출발점과 도착점에 들어온 순서가 주어진다. 이때, 추월한 자동차의 수를 구한다.
자동차 이름은 6글자 이상 8글자 이하의 숫자와 대문자로 주어진다.

해결 방법 : 각 자동차의 이름과 출발점에서의 도착 순서를 맵을 통해 짝지어준다. 그리고 도착점에 들어온 순서대로
뒤의 자동차 가운데 출발점에서 앞에 있던 자동차가 있는지 확인한다. 그러한 자동차의 개수를 세면 답이 된다.

주요 알고리즘 : 자료 구조, 맵

출처 : CHCI 2002N1S 1번
*/

char buff[16];
int a[1024], mem[1024];
map<string, int> mp;

int main(void) {
    int n, r = 0;
    string s;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", buff);
        s.assign(buff);
        mp.insert(pair<string, int>(s, i + 1));
    }
    for (int i = 0; i < n; i++) {
        scanf("%s", buff);
        s.assign(buff);
        if (mp.find(s) == mp.end()) return 1;
        a[i] = mp[s];
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[i]) {
                r++;
                break;
            }
        }
    }
    printf("%d", r);
    return 0;
}