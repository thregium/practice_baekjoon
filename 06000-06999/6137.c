#include <stdio.h>

/*
문제 : 길이 N(N <= 2000)의 문자열이 주어질 때, 이 문자열에서 양쪽 끝 문자 가운데 하나를 차례로 떼어내
만든 문자열 가운데 가장 사전순으로 앞선 문자열을 한 줄에 80자씩 출력한다.

해결 방법 : 만약 양쪽 끝 문자가 다르다면 더 사전순으로 앞선 문자를 떼어내면 된다. 양쪽 끝 문자가 같은 경우에는
안쪽 문자를 차례로 살펴보며 그 안쪽 문자도 같은지 살펴본다. 안쪽 문자가 다르게 되는 지점 또는
안쪽 문자들도 순서대로 전부 같음을 발견한 시점에서 멈춘다. 안쪽 문자가 다르게 되는 지점에 도달하면
더 사전순으로 작은 안쪽 문자가 있는 쪽의 문자를 떼어내고, 안쪽도 전부 같다면 아무거나 하나를 떼어내도록 한다.
이를 반복해 모든 문자를 떼어낸 다음 80자씩 출력해 나가면 된다.

주요 알고리즘 : 그리디 알고리즘, 투 포인터

출처 : USACO 2007N S3번
*/

char s[2048], s2[2048];

int main(void) {
    int n, l, r, l2, r2;
    //freopen("E:\\PS\\Olympiad\\USA\\2_Silver\\2007_11\\nov07\\testdata\\allnov07\\bcl.7.in", "r", stdin);
    //freopen("E:\\PS\\Olympiad\\USA\\2_Silver\\2007_11\\nov07\\testdata\\allnov07\\bcl.7_t.out", "w", stdout);
    scanf("%d", &n);
    l = 0, r = n - 1;
    for (int i = 0; i < n; i++) {
        scanf(" %c", &s[i]);
    }
    for (int i = 0; i < n; i++) {
        if (s[l] < s[r]) s2[i] = s[l++];
        else if (s[l] > s[r]) s2[i] = s[r--];
        else {
            l2 = l, r2 = r;
            while (l2 < r2 && s[l2] == s[r2]) {
                l2++, r2--;
            }
            if (s[l2] <= s[r2]) s2[i] = s[l++];
            else s2[i] = s[r--];
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%c", s2[i]);
        if (i % 80 == 79) printf("\n");
    }
    return 0;
}