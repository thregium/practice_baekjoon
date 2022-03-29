#include <stdio.h>
#include <string.h>

/*
문제 : 스펠링 비의 알파벳 7개(소문자)와 N(N <= 102305)개의 단어(<= 24자, 소문자)가 주어질 때,
조건을 만족하는 단어를 모두 출력한다. 조건을 만족하는 단어는 스펠링 비의 첫 알파벳을 포함하고,
스펠링 비에 있는 7개의 알파벳으로만 이루어진 4자 이상의 단어이다.

해결 방법 : 문제에 쓰인 조건을 구현하고 조건을 만족하는 지 확인한 다음 출력하면 된다.

주요 알고리즘 : 구현, 문자열

출처 : VTH 2019 C번
*/

char bee[16], dict[32], chk[26];

int main(void) {
    int n, r;
    scanf("%s", bee);
    for (int i = 0; i < 7; i++) chk[bee[i] - 'a'] = 1;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", dict);
        r = 0;
        for (int j = 0; dict[j]; j++) {
            if (dict[j] == bee[0]) r = 1;
        }
        for (int j = 0; dict[j]; j++) {
            if (!chk[dict[j] - 'a']) r = 0;
        }
        if (strlen(dict) < 4) r = 0;
        if (r) printf("%s\n", dict);
    }
    return 0;
}