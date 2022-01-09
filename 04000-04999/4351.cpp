#include <stdio.h>
#include <string>
#include <unordered_map>
using namespace std;

/*
문제 : M(M <= 1000)개의 단어(<= 16자, 소문자)로 이루어진 단어장에 각 단어별 점수(<= 10^6, 음이 아닌 정수)가 주어진다.
이때, N(N <= 100)개의 문장에 대한 점수를 각각 구한다. 각 문장의 점수는 단어장에 있는 단어들의 단어별 점수 합과 같다.

해결 방법 : 해시맵에 단어별 점수를 기록한 후 각 문장의 점수를 계산한다. 이는 맵에서 단어가 있는 지 확인한 후
그 단어와 연결된 점수를 보는 것으로 간단히 풀 수 있다.

주요 알고리즘 : 문자열, 자료 구조, 해시맵

출처 : Waterloo 20020601 A번
*/

char buff[1024];
unordered_map<string, int> u;

int main(void) {
    int m, n, d;
    string s;
    scanf("%d %d", &m, &n);
    for (int i = 0; i < m; i++) {
        scanf("%s %d", buff, &d);
        s.assign(buff);
        u.insert(pair<string, int>(buff, d));
    }
    for (int i = 0; i < n; i++) {
        d = 0;
        while (1) {
            scanf("%s", buff);
            s.assign(buff);
            if (s == ".") break;
            if (u.find(s) != u.end()) d += u[s];
        }
        printf("%d\n", d);
    }
    return 0;
}