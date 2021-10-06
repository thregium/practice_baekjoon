#include <stdio.h>
#include <map>
#include <set>
#include <string>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)
using namespace std;

/*
���� : N(N <= 1000)���� �� �ܾ �־�����. �̶�, ���� ���� ���� �ܾ� ������ ���� Ƚ���� ���Ѵ�.
������ �ٸ� ���� ���� �����̰�, �� �ܾ���� 10�� ������ �빮���̴�.

�ذ� ��� : �� �ܾ� ������ �¿� ������ ��, �̵��� ���� Ƚ���� �Բ� �� ������ �ʿ� �����Ѵ�.
���� �ʿ� �ܾ� ������ ������ ���� Ƚ���� 1�� �ؼ� �����ϰ�, �ִٸ� �ش��ϴ� ������ ���� Ƚ���� �ø��鼭 �ִ��� �����ϸ� �ȴ�.

�ֿ� �˰��� : �ڷᱸ��, ��, ��, ���ڿ�

��ó : USACO 2013D B1��
*/

map<set<string>, int> mp;
char buff[3][16];

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("records.in", "r");
        fo = fopen("records.out", "w");
    }

    int n, r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        set<string> st;
        string s;
        scanf("%s %s %s", buff[0], buff[1], buff[2]);
        for (int j = 0; j < 3; j++) {
            s.assign(buff[j]);
            st.insert(s);
        }
        if (mp.find(st) == mp.end()) {
            mp.insert(pair<set<string>, int>(st, 1));
        }
        else {
            (mp.find(st)->second)++;
            if (mp.find(st)->second > r) r = mp.find(st)->second;
        }
    }

    printf("%d", r);
    return 0;
}