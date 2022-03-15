#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string>
#include <queue>
#include <unordered_map>
using namespace std;

/*
���� : 8������ A���� F������ ���ĺ� ��� �ϳ��� �̷���� ���ڿ��� 2�� �־�����. ������ �־��� ������
����Ͽ� �� ���ڿ��� �� ���ڿ��� �ٲ� �� �ִ� �� Ȯ���ϰ�, �׷��� ��� �ٲٱ� ���� �ʿ��� ������
�ּ� Ƚ���� ���Ѵ�.

�ذ� ��� : ������ ���ڿ��� ������ �ִ� �� 160������ ���� Ȯ�� ������ ���̱� ������
BFS�� ���� �� ������ �غ��� �ؽøʿ� ���ڿ� ���� �ʿ��� ������ Ƚ���� �����ϰ�,
�ٲ� �� �ִ� ��� ���� Ƚ����, ���� ��� -1�� ����ϸ� �ȴ�.
�������� �����Ƿ� ������ �����Ѵ�.

�ֿ� �˰��� : �׷��� �̷�, BFS, ���ڿ�, �ؽø�, ����

��ó : MidC 2018 G�� // SEUSA 2018D1 D�� / 2018D2 D��
*/

char buffs[16], bufft[16];
unordered_map<string, int> dist;
queue<string> q;

char rot(char c) {
    if (c == 'F') return 'A';
    else return c + 1;
}

void bfs(string s) {
    int d;
    string t;
    q.push(s);
    dist.insert(make_pair(s, 0));
    while (q.size()) {
        s = q.front();
        q.pop();
        d = dist[s];
        for (int i = 0; i < 8; i++) {
            t = s;
            if (s[i] == 'A') {
                if (i > 0) t[i - 1] = rot(s[i - 1]);
                if (i < 7) t[i + 1] = rot(s[i + 1]);
            }
            else if (s[i] == 'B') {
                if (0 < i && i < 7) t[i + 1] = s[i - 1];
            }
            else if (s[i] == 'C') {
                t[7 - i] = rot(s[7 - i]);
            }
            else if (s[i] == 'D') {
                if (i < 4) {
                    for (int j = 0; j < i; j++) t[j] = rot(s[j]);
                }
                else {
                    for (int j = i + 1; j < 8; j++) t[j] = rot(s[j]);
                }
            }
            else if (s[i] == 'E') {
                if (0 < i && i < 4) {
                    t[0] = rot(s[0]);
                    t[i << 1] = rot(s[i << 1]);
                }
                else if (4 <= i && i < 7) {
                    t[7] = rot(s[7]);
                    t[(i << 1) - 7] = rot(s[(i << 1) - 7]);
                }
            }
            else if (s[i] == 'F') {
                if (i & 1) t[i >> 1] = rot(s[i >> 1]);
                else t[(i >> 1) + 4] = rot(s[(i >> 1) + 4]);
            }

            if (dist.find(t) == dist.end()) {
                dist.insert(make_pair(t, d + 1));
                q.push(t);
            }
        }
    }
}

int main(void) {
    string s, t;
    scanf("%s%s", buffs, bufft);
    s.assign(buffs);
    t.assign(bufft);
    bfs(s);
    if (dist.find(t) == dist.end()) printf("-1");
    else printf("%d", dist[t]);
    return 0;
}