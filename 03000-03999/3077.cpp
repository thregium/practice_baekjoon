#include <stdio.h>
#include <string>
#include <unordered_map>
using namespace std;

/*
문제 : 두 N(N <= 2500)개의 문자열 순열에 대해 모든 문자열 쌍 마다의 순서가 앞 순열의 순서와 일치하는지 확인하고,
그러한 것의 비율을 출력한다.

해결 방법 : 해시맵에 첫 번째 순열의 문자열마다 순서를 저장한다. 그 다음, 두 번째 문자열 순열을 저장하고,
각 문자열 쌍마다 순서를 해시맵에서 꺼내서 둘의 순서가 일치하는 것의 개수를 세면 된다.

주요 알고리즘 : 자료 구조, 해시맵

출처 : COCI 12/13#3 2번
*/

char buff[32], ans[2560][32];
unordered_map<string, int> um;

int main(void) {
    int n, r = 0, a, b;
    string s;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", buff);
        s.assign(buff);
        um.insert(pair<string, int>(s, i));
    }
    for (int i = 0; i < n; i++) {
        scanf("%s", ans[i]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            s.assign(ans[i]);
            a = um.find(s)->second;
            s.assign(ans[j]);
            b = um.find(s)->second;
            if (a < b) r++;
        }
    }
    printf("%d/%d", r, (n - 1) * n / 2);
    return 0;
}