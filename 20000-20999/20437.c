#include <stdio.h>

/*
문제 : 길이 10000 이하의 소문자로 이루어진 문자열과 자연수 K(K <= 10000)가 주어질 때,
시작점과 끝점 사이 어떤 문자가 정확히 K개이며 그 문자가 맨 앞과 맨 뒤에 있는 문자열 가운데
가장 짧은 문자열과 가장 긴 문자열의 길이를 각각 구한다. 그러한 문자열 없는 경우 -1을 출력한다.

해결 방법 : 각 문자별로 등장한 위치를 배열에 저장한 다음, 거리를 K - 1씩 두며 각 위치의 차이를
확인하면서 가장 먼 것과 가장 가까운 것을 각각 찾아나가면 도니다.

주요 알고리즘 : 문자열, 슬라이딩 윈도우

출처 : 한양대E 2020Z B번
*/

char s[10240];
int pos[26][10240], pcnt[26];

int main(void) {
    int t, k, lo, hi;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%s", s);
        scanf("%d", &k);
        for (int i = 0; s[i]; i++) {
            pos[s[i] - 'a'][pcnt[s[i] - 'a']++] = i;
        }

        lo = 103000, hi = -1;
        for (int i = 0; i < 26; i++) {
            for (int j = k - 1; j < pcnt[i]; j++) {
                if (pos[i][j] - pos[i][j - k + 1] < lo) lo = pos[i][j] - pos[i][j - k + 1];
                if (pos[i][j] - pos[i][j - k + 1] > hi) hi = pos[i][j] - pos[i][j - k + 1];
            }
            pcnt[i] = 0;
        }
        if (lo == 103000) printf("-1\n");
        else printf("%d %d\n", lo + 1, hi + 1);
    }
    return 0;
}