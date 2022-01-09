#include <stdio.h>
#include <string>
#include <unordered_map>
using namespace std;

/*
문제 : P(P <= 50)개의 정당에 대해 지지율이 소숫점 아래 1자리까지 주어진다. 각 정당의 이름은 소문자 20자 이하다.
이때, G(G <= 10000)개의 예상이 맞는 지 확인한다.
각 예상은 정당들의 연합시 지지도가 특정 값 이상/이하/미만/초과/동일인지 여부이다.

해결 방법 : 실수 오차가 생기기 쉬우므로 정수형으로 바꾸어 저장하도록 한다. 이는 정수 부분에 10을 곱하고,
소수 부분을 더하여 10을 곱한 것과 유사한 형태가 되도록 하는 것으로 충분하다.
그리고 각 정당마다의 지지도를 해시맵에 저장한다.
그 후 각 예상마다 정당들의 지지도 합을 더해나간다. 그러다가 비교 연산자가 나오면 종류를 확인하고,
지지도를 비교하여 그 값이 맞는 지 여부를 확인하면 된다.

주요 알고리즘 : 자료 구조, 해시맵, 파싱, 임의 정밀도?

출처 : Ulm 2009 B번
*/

unordered_map<string, int> party;
char buff[64];

int main(void) {
    int p, g, x, y, r;
    string s;
    //freopen("E:\\PS\\Contest\\Ulm\\2009\\ballot.in", "r", stdin);
    //freopen("E:\\PS\\Contest\\Ulm\\2009\\ballot_t.out", "w", stdout);
    scanf("%d %d", &p, &g);
    for (int i = 0; i < p; i++) {
        scanf("%s %d.%d", buff, &x, &y);
        s.assign(buff);
        party.insert(pair<string, int>(s, x * 10 + y));
    }
    for (int i = 1; i <= g; i++) {
        r = 0;
        while (1) {
            scanf("%s", buff);
            s.assign(buff);
            if (s == "=" || s == "<" || s == ">" || s == "<=" || s == ">=") {
                scanf("%d", &x);
                if (s == "=" && r == x * 10) r = 1;
                else if (s == "<" && r < x * 10) r = 1;
                else if (s == ">" && r > x * 10) r = 1;
                else if (s == "<=" && r <= x * 10) r = 1;
                else if (s == ">=" && r >= x * 10) r = 1;
                else r = 0;
                printf("Guess #%d was %s.\n", i, r ? "correct" : "incorrect");
                break;
            }
            else if (s == "+") continue;
            else if (party.find(s) == party.end()) return 1;
            else r += party[s];
        }
    }
    return 0;
}