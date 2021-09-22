#include <stdio.h>
#include <string.h>

/*
문제 : 10^9 이하의 자연수가 주어질 때, 이 자연수가 2018과 어떤 관계인지 구한다. (관계 생략)

해결 방법 : 자연수를 문자열로 입력받은 다음, 자릿수를 세고, 자릿수 개수를 이용해 어느 관계인지 찾으면 된다.

주요 알고리즘 : 구현, 케이스 워크

출처 : 고려대 2018 BB/IA번
*/

char n[16];
int cnt[10];

int main(void) {
    int l;
    scanf("%s", n);
    l = strlen(n);
    for (int i = 0; n[i]; i++) {
        cnt[n[i] - '0']++;
    }
    if (cnt[2] + cnt[0] + cnt[1] + cnt[8] != l) printf("0");
    else if (!(cnt[2] && cnt[0] && cnt[1] && cnt[8])) printf("1");
    else if (cnt[2] == cnt[0] && cnt[2] == cnt[1] && cnt[2] == cnt[8]) printf("8");
    else printf("2");
    return 0;
}