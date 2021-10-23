#include <stdio.h>
#include <string.h>

/*
문제 : N(N <= 300000)명의 이름이 성적 순으로 주어질 때, 성적 순위가 K 이하며 이름의 길이가 같은 쌍의 개수를 구한다.
이름의 길이는 20 이하다.

해결 방법 : 먼저, 성적 순으로 각 사람의 이름의 길이만 정보로 남긴다. 그 다음, 성적 순으로 이름의 길이를 살피며
앞쪽 K명의 이름의 개수를 세 나간다. 또한, 앞쪽 K명 가운데 현재 이름의 길이와 같은 사람의 수를 결괏값에 추가한다.
이를 반복하다가 K명이 넘어가면 K명 전의 사람 이름과 같은 길이의 개수를 1씩 줄이면 된다.
이를 모든 사람에 대해 반복하면 모든 쌍의 수를 구할 수 있다.

주요 알고리즘 : 투 포인터

출처 : COCI 12/13#3 3번
*/

char buff[32];
int name[327680], cnt[32];

int main(void) {
    int n, k;
    long long r = 0;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%s", buff);
        name[i] = strlen(buff);
    }
    for (int i = 0; i < n; i++) {
        r += cnt[name[i]];
        cnt[name[i]]++;
        if (i >= k) cnt[name[i - k]]--;
    }
    printf("%lld", r);
    return 0;
}