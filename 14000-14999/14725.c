#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

/*
문제 : N(N <= 1000)개의 먹이에 대한 경로 정보가 주어질 때, 모든 먹이의 위치를 오름차순으로 전위 출력한다.
각 먹이는 길이 15 이하의 문자열로 주어지며, 각 먹이로 가는 길에는 최대 15개의 먹이가 있다.
각 방에서 같은 먹이로 가는 방은 1개씩만 있어야 한다.

해결 방법 : 트라이를 이용하여 경로를 저장한 다음, 각 경로를 정렬하고 전위 순회하며 경로를 출력하면 된다.

주요 알고리즘 : 문자열, 트라이, 자료 구조

출처 : 충남대 1회 J번
*/

typedef struct trie {
    char feed[16];
    struct trie** link;
    int linksize;
    int linkcap;
} trie;

char buff[16];

int cmp1(const void* a, const void* b) {
    trie* ai = *(trie**)a;
    trie* bi = *(trie**)b;
    assert(!(ai == NULL || bi == NULL));
    return strcmp(ai->feed, bi->feed);
}

void printtrie(trie* node, int depth) {
    assert(node != NULL);
    for (int i = 0; i < depth; i++) printf("--");
    if (depth >= 0) printf("%s\n", node->feed);
    assert(node->link != NULL);
    qsort(node->link, node->linksize, sizeof(trie*), cmp1);
    for (int i = 0; i < node->linksize; i++) {
        printtrie(node->link[i], depth + 1);
    }
}

int main(void) {
    int n, k, t;
    trie* root = calloc(1, sizeof(trie));
    assert(root != NULL);
    root->link = calloc(1, sizeof(trie*));
    assert(root->link != NULL);
    root->linkcap = 1;
    root->linksize = 0;
    trie* node, * nnd;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &k);
        node = root;
        for (int j = 0; j < k; j++) {
            scanf("%s", buff);
            t = 0;
            assert(node->link != NULL);
            for (int l = 0; l < node->linksize; l++) {
                assert(node->link[l] != NULL);
                if (!strcmp(buff, node->link[l]->feed)) {
                    t = 1;
                    node = node->link[l];
                    break;
                }
            }

            if (!t) {
                nnd = calloc(1, sizeof(trie));
                assert(nnd != NULL);
                nnd->link = calloc(1, sizeof(trie*));
                assert(nnd->link != NULL);
                nnd->linkcap = 1;
                nnd->linksize = 0;
                strcpy(nnd->feed, buff);
                assert(node->link != NULL);
                if (node->linksize >= node->linkcap) {
                    node->link = realloc(node->link, (sizeof(trie*)) * (node->linkcap) * 2);
                    for (int l = node->linkcap; l < (node->linkcap) * 2; l++) node->link[l] = NULL;
                    node->linkcap *= 2;
                }
                assert(node->linksize + 1 <= node->linkcap);
                node->link[node->linksize++] = nnd;
                node = nnd;
            }
        }
    }

    printtrie(root, -1);
    return 0;
}