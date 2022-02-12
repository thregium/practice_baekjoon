#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

/*
���� : N(N <= 1000)���� ���̿� ���� ��� ������ �־��� ��, ��� ������ ��ġ�� ������������ ���� ����Ѵ�.
�� ���̴� ���� 15 ������ ���ڿ��� �־�����, �� ���̷� ���� �濡�� �ִ� 15���� ���̰� �ִ�.
�� �濡�� ���� ���̷� ���� ���� 1������ �־�� �Ѵ�.

�ذ� ��� : Ʈ���̸� �̿��Ͽ� ��θ� ������ ����, �� ��θ� �����ϰ� ���� ��ȸ�ϸ� ��θ� ����ϸ� �ȴ�.

�ֿ� �˰��� : ���ڿ�, Ʈ����, �ڷ� ����

��ó : �泲�� 1ȸ J��
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