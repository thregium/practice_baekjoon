#include <stdio.h>
#include <string.h>
#include <string>
#include <unordered_map>
using namespace std;

/*
문제 : 100000명 이하의 투표지에 적힌 사람 이름들이 주어질 때, 유일하게 가장 많은 사람이 있는 지 구하고,
있다면 그 이름을, 없다면 'Runoff!'를 출력한다.

해결 방법 : 각 사람의 이름과 등장 횟수를 해시맵에 저장한다. 들어오지 않은 이름이 있다면
그 이름을 해시맵에 1회로 추가하고, 들어온 이름이 있다면 등장 횟수를 1씩 늘려 나간다.
이를 반복한 다음, 모든 사람 가운데 등장 횟수의 최댓값을 찾고, 동시에 그와 같은 횟수로 등장한 다른 사람이
있는 지 확인한다. 없다면 그 사람의 이름을, 있다면 'Runoff!'를 출력하면 된다.

주요 알고리즘 : 문자열, 해시맵

출처 : VTH 2015 B번
*/

char buff[103000];
unordered_map<string, int> cand;

int main(void) {
    int bcnt = 0, major = 0;
    string s;
    while (1) {
        fgets(buff, 101300, stdin);
        if (buff[strlen(buff) - 1] == '\n') buff[strlen(buff) - 1] = '\0';
        if (buff[0] == '*') break;
        s.assign(buff);
        if (cand.find(s) != cand.end()) cand[s]++;
        else cand.insert({ s, 1 });
    }
    for (auto& i : cand) {
        if (i.second > bcnt) {
            major = 1;
            bcnt = i.second;
            s = i.first;
        }
        else if (i.second == bcnt) major = 0;
    }
    if (major) printf("%s", s.c_str());
    else printf("Runoff!");
    return 0;
}
