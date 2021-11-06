#include <stdio.h>
#include <string>
#include <map>
using namespace std;

/*
문제 : 두 크기 100000 이하의 단어(길이 15 이하, 소문자) 집합이 주어질 때, 두 집합 사이 일치하는 원소의 개수를 구한다.

해결 방법 : 먼저, 첫 번째 집합에서 각 단어들과 단어들의 입력 횟수를 맵에 저장한다. 두 번째 집합의 원소들을 입력받으면
첫 번째 집합에 해당 원소가 남아있는지 확인하고 있다면 해당 원소의 남은 개수에서 1을 줄이고 결괏값을 1 늘린다.
만약 남은 개수가 0이 되면 해당 원소를 지우도록 한다.

주요 알고리즘 : 자료구조, 맵

출처 : NWERC 2014 J번
*/

char buff[32];
map<string, int> mp;

int main(void) {
    int n, r = 0;
    string s;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", buff);
        s.assign(buff);
        if (mp.find(s) != mp.end()) {
            (mp.find(s)->second)++;
        }
        else mp.insert(pair<string, int>(s, 1));
    }
    for (int i = 0; i < n; i++) {
        scanf("%s", buff);
        s.assign(buff);
        if (mp.find(s) != mp.end()) {
            r++;
            if (mp.find(s)->second == 1) {
                mp.erase(mp.find(s));
            }
            else {
                (mp.find(s)->second)--;
            }
        }
    }
    printf("%d", r);
    return 0;
}