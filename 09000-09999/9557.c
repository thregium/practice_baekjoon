#include <stdio.h>

/*
문제 : N(N <= 100)개의 아랍어 또는 영어 단어가 주어진다. 각 단어의 길이는 10 이하고,
아랍어 단어는 '#'으로만 이루어진 문자열로 주어지며, 영어 단어는 소문자로만 이루어져 있다. 영어 단어는 최대 1번만 주어진다.
이때, 순서를 제대로 된 순서로 옮긴다.

해결 방법 : 영어 단어 이후에 있는 아랍어 단어를 영어 단어 이전으로 옮기고, 영어 단어 이전에 있는 아랍어 단어를
영어 단어 이후로 옮기면 된다. 먼저 영어 단어의 위치를 찾아 놓으면 간단히 풀 수 있다.

주요 알고리즘 : 구현, 문자열

출처 : Arab 2011 A번
*/

char word[128][16];

int main(void) {
    int t, n, a, e;
    //freopen("E:\\PS\\ICPC\\Africa and Arab\\Arab Collegiate\\2011\\acpc2011-IO-A\\arabic.in", "r", stdin);
    //freopen("E:\\PS\\ICPC\\Africa and Arab\\Arab Collegiate\\2011\\acpc2011-IO-A\\arabic_t.out", "w", stdout);
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d", &n);
        e = -1;
        for (int i = 0; i < n; i++) {
            scanf("%s", &word[i]);
            if (word[i][0] != '#') {
                e = i;
            }
        }
        if (e < 0) {
            for (int i = 0; i < n; i++) {
                printf("%s ", word[i]);
            }
            printf("\n");
        }
        else {
            for (int i = e + 1; i < n; i++) {
                printf("%s ", word[i]);
            }
            printf("%s ", word[e]);
            for (int i = 0; i < e; i++) {
                printf("%s ", word[i]);
            }
            printf("\n");
        }
    }
    return 0;
}