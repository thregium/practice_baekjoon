#include <stdio.h>

/*
문제 : N * M(N, M <= 1000) 크기의 격자로 동전들이 놓여 있다. 모든 행의 동전에 대해 뒷면의 수가 짝수이고,
모든 열에 대해 뒷면의 수가 짝수가 되도록 행, 열의 동전들을 뒤집을 때, 그렇게 하기 위해
필요한 최소 뒤집는 줄의 수를 구한다.

해결 방법 : 가로와 세로 각각에 대해 뒷면이 짝수 개 있는 줄과 홀수 개 있는 줄의 개수를 센다.
이렇게 되면 양쪽의 홀짝성은 반드시 같도록 나온다.
짝수 개 있는 줄이 짝수라면 양쪽의 짝수 개 있는 줄 또는 양쪽의 홀수 개 있는 줄을 모두 뒤집으면
모든 줄이 짝수 개가 된다. 짝수 개 있는 줄이 홀수개라면 한쪽은 짝수 개 있는 줄, 다른 쪽은 홀수 개 있는 줄로
뒤집으면 모든 줄이 짝수 개가 된다. 그렇게 만드는 방법 가운데 더 작은 쪽을 선택하면 된다.

주요 알고리즘 : 애드 혹?
*/

char s[1024][1024];

int small(int a, int b) {
    return a < b ? a : b;
}

int main(void) {
    int n, m, cnt, he = 0, ho = 0, ve = 0, vo = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s", s[i]);
        cnt = 0;
        for (int j = 0; j < m; j++) cnt += s[i][j] - '0';
        if (cnt & 1) ho++;
        else he++;
    }
    for (int i = 0; i < m; i++) {
        cnt = 0;
        for (int j = 0; j < n; j++) cnt += s[j][i] - '0';
        if (cnt & 1) vo++;
        else ve++;
    }

    if ((he ^ ve) & 1) return 1;
    if (he & 1) printf("%d", small(he + ve, ho + vo));
    else printf("%d", small(he + vo, ho + ve));
    return 0;
}