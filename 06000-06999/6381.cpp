#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <queue>
using namespace std;

/*
문제 : 문자열이 주어질 때, 이 문자열을 아스키 코드로 표현할 때와 최선의 부호화를 시행할 때의 비트 수를 구하고 그 둘의 배수를 구한다.

해결 방법 : 허프만 부호화를 하면 비트 수를 최소한으로 줄일 수 있다. 가장 등장 빈도가 적은 수부터 차례로 합쳐나가고,
합친 순서의 역순으로 각 문자를 부호화한 비트들을 얻는 방식이다.

주요 알고리즘 : 그리디 알고리즘, 우선순위 큐, 허프만 부호화

출처 : GNY 2000 F번
*/

priority_queue<int, vector<int>, greater<int>> pq;

char buff[1024];
int cnt[27];

int main(void) {
    int r, a, b;
    while (1) {
        scanf("%s", buff);
        if (!strcmp(buff, "END")) break;
        for (int i = 0; buff[i]; i++) {
            if (isupper(buff[i])) cnt[buff[i] - 'A']++;
            else cnt[26]++;
        }
        for (int i = 0; i < 27; i++) {
            if (cnt[i] == 0) continue;
            pq.push(cnt[i]);
        }

        r = 0;
        while (pq.size() >= 2) {
            a = pq.top();
            pq.pop();
            b = pq.top();
            pq.pop();
            r += a + b;
            pq.push(a + b);
        }
        if (r == 0) r += strlen(buff);

        printf("%d %d %.1f\n", strlen(buff) * 8, r, strlen(buff) * 8 / (double)r);

        while (pq.size()) pq.pop();
        for (int i = 0; i < 27; i++) cnt[i] = 0;
    }
    return 0;
}