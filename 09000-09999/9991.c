#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
���� : W���� ���ڿ��� �־�����. �ش��ϴ� ���ڿ��� ���ĺ� �ҹ��ڷ� �̷���� �ְ�, �־����� ���ڿ��� ���� ���� 10^6 ���ϴ�.
�� �� N(N <= 1000)���� ���ڿ���� K�� �־�����. �ش��ϴ� ���ڿ����� 1000�� ������ �ҹ��ڷ� �̷���� �ִ�.
�� ���ڿ����� �ش� ���ڿ��� �����ϴ� K��° �ܾ�(ó�� ���� ���ڿ���)�� ���Ѵ�. �ش��ϴ� �ܾ ���ٸ� -1�� ����Ѵ�.

�ذ� ��� : Ʈ���� �ڷᱸ���� �̿��Ѵ�. �̶�, �޸𸮸� �����ϱ� ���� ���� ����� ����� �������� �Ҵ��ؾ� �Ѵ�.
�� ���ڿ����� Ʈ���̿� ������ ����, �� ���ڿ����� �Է¹����� �ش� ���ڿ����� �����ϴ� ���ڿ��� ������ Ȯ���ϸ�
�ش��ϴ� ���ڿ��� ã�Ƴ�����.

�ֿ� �˰��� : �ڷ� ����, Ʈ����, ���ڿ�

��ó : USACO 2014F B2/S1��
*/

typedef struct trie {
    int cnt; //�ش� ���ڿ��� �����ϴ� ���ڿ��� ����
    int fin; //�ش� ���ڿ��� ������ ���ڿ��̶�� �� ���ڿ��� ��ȣ�� ����, ������ 0
    char msz; //���� Ʈ���� �޸��� ũ��
    char sz; //���� Ʈ������ ����
    char last; //�ֱ� ����
    struct trie** nxt; //���� Ʈ���̵��� ���
} trie;

char buff[1048576];
int ccc = 0, error = 0;

int cmp1(const void* a, const void* b) {
    //Ʈ������ ����� �����Ѵ�.
    trie* ai = *(trie**)a;
    trie* bi = *(trie**)b;
    return ai->last > bi->last ? 1 : ai->last == bi->last ? 0 : -1;
}

void assign(trie* tr, int p, int ki) {
    //�ش��ϴ� ���ڸ� Ʈ���̿� �����Ѵ�.
    int li;
    trie** tmp;
    (tr->cnt)++;
    while (buff[p]) {
        li = -1;
        for (int i = 0; i < tr->sz; i++) {
            if (tr->nxt[i]->last == buff[p]) {
                li = i; //���� ���ڸ� ã��
                break;
            }
        }
        if (li < 0) {
            //���� ���ڸ� ã�� �� ���ٸ�
            if (tr->sz == 0) {
                tr->nxt = calloc(1, sizeof(trie*)); //���� �迭�� ���� ���
                tr->msz = 1;
            }
            else if (tr->sz == tr->msz) {
                tmp = realloc(tr->nxt, sizeof(trie*) * ((long long)tr->msz << 1)); //�޸𸮰� ���� ���� 2��� ���Ҵ�
                if (tmp == NULL) {
                    error = 1; //�Ҵ翡 ������ ���?
                    return;
                }
                tr->nxt = tmp;
                tr->msz <<= 1;
            }
            ((tr->nxt)[tr->sz]) = calloc(1, sizeof(trie)); //���ο� ��� �Ҵ�
            ((tr->nxt)[tr->sz])->last = buff[p];
            li = (tr->sz)++;
        }
        tr = tr->nxt[li];
        (tr->cnt)++;
        p++;
    }
    tr->fin = ki; //���ڿ��� ��
}

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("auto.in", "r");
        fo = fopen("auto.out", "w");
    }
    //freopen("E:\\PS\\Olympiad\\USA\\1_Bronze\\2014_02\\auto\\6.in", "r", stdin);
    int w, n, k, li, eend;
    trie* tr = calloc(1, sizeof(trie));
    trie* tx;
    scanf("%d %d", &w, &n);
    for (int i = 0; i < w; i++) {
        scanf("%s", buff);
        assign(tr, 0, i + 1); //�� ���ڿ����� Ʈ���̿� �����Ѵ�.
        if (error) return -1;
    }
    for (int i = 0; i < n; i++) {
        scanf("%d %s", &k, buff);
        tx = tr;
        eend = 0;
        for (int j = 0; buff[j]; j++) {
            li = -1;
            for (int jj = 0; jj < tx->sz; jj++) {
                if (tx->nxt[jj]->last == buff[j]) {
                    li = jj; //�־��� ���ڿ��� ������ �̵��Ѵ�.
                    break;
                }
            }
            if (li < 0) {
                printf("%d\n", -1); //�̵��� �Ұ����ϴٸ� �����ϴ� ���ڿ��� 0����� �ǹ��̹Ƿ� -1�� ����Ѵ�.
                eend = 1;
                break;
            }
            tx = tx->nxt[li];
        }
        if (eend) continue;
        if (tx->cnt < k) printf("%d\n", -1); //�Ǵ� �����ϴ� ���ڿ��� K�� �̸��� ��쿡�� -1�� ����Ѵ�.
        else {
            while (k > 0) {
                if (tx->fin) k--;
                if (k == 0) printf("%d\n", tx->fin); //�ش��ϴ� ���ڿ��� ã�� ��� ����ϰ� �����Ѵ�.
                else {
                    qsort(tx->nxt, tx->sz, sizeof(trie*), cmp1);
                    for (int j = 0; j < tx->sz; j++) {
                        if (tx->nxt[j] == NULL) return 2;
                        if (tx->nxt[j]->cnt < k) k -= tx->nxt[j]->cnt; //�� �ܿ��� ���������� ���캻��.
                        else {
                            tx = tx->nxt[j];
                            break;
                        }
                    }
                }
            }
        }
    }
    return 0;
}