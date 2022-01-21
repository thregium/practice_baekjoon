#include <stdio.h>

/*
문제 : 원본 글과 N - 1(N <= 1000)개의 댓글이 주어질 때, 각 글을 주어진 형식대로 출력한다.
각 댓글은 댓글을 단 상대가 번호로 주어진다. 댓글을 단 상대의 번호는 댓글의 번호보다 작다.
주어진 형식은 댓글의 단계수만큼 앞에 '.'을 찍는 것이다. 원본 글은 .이 0개, 거기에 단 댓글은 .이 1개이다.
각 글과 댓글의 내용은 50자 이하의 대소문자 또는 숫자로 주어진다.

해결 방법 : 각 댓글마다 대댓글의 개수와 목록, 댓글의 내용을 구조체로 가지고 있는다.
댓글을 달 때 마다 상대의 댓글에서 대댓글을 연결해 오면 된다.
전부 작성한 후에는 원본 글에서 시작해서 트리를 전위 순회하며 대댓글들을 출력한다.
재귀 과정에서 재귀의 깊이를 가지고 있으면 .의 개수를 알맞게 찍을 수 있다.

주요 알고리즘 : 구현, 트리, 재귀

출처 : JAG 2013S4 A번
*/

typedef struct post {
    char s[64];
    int cc;
    int child[1024];
} post;

post p[1024];

void printtree(int x, int l) {
    for (int i = 0; i < l; i++) printf(".");
    printf("%s\n", p[x].s);
    for (int i = 0; i < p[x].cc; i++) {
        printtree(p[x].child[i], l + 1);
    }
}

int main(void) {
    int n, k;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &k);
        p[k].child[p[k].cc++] = i;
        scanf("%s", p[i].s);
    }
    printtree(1, 0);
    return 0;
}
