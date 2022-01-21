#include <stdio.h>
#include <string>
#include <unordered_map>
using namespace std;

/*
���� : H * W(H <= 10, W <= 20) ũ���� ���ڿ� ���ڵ��� ���� �ִ�. �̶�, �� ���ڿ��� ������ ��ġ����
�����¿�밢������ �������� ������ ���� �� �ִ� 2�� �̻��� ���ڿ� ��� 2ȸ �̻� ��Ÿ��
���� �� ���ڿ��� ���Ѵ�. �׷��� ���ڿ��� ������ ��� ���������� ���� ���� ���� ���Ѵ�.
�������� �����̸� �迭�� ������ ����� ȯ������ �̾�����. ����, ó�� ������ ��ġ�� �ǵ��ƿ���
�������� ���ڿ��� ���� �� �ִ�. �׷��� ���� ���ٸ� 0�� ����Ѵ�.

�ذ� ��� : �� ������ 8�� �� ���⿡ ���� ���� �� �ִ� ��ŭ ���ڿ��� �����.
���ڿ��� ����� �� ���ڿ��� ���� Ƚ���� �Բ� �ؽøʿ� �����Ѵ�. �̹� �ؽøʿ� �ִ� ���
���� Ƚ���� 1 �ø��� �ȴ�. �̸� �ݺ��� ����, 2ȸ �̻� ��Ÿ�� ���� �� ���ڿ���
�ؽøʿ��� ã�Ƽ� ����ϸ� �ȴ�.

�ֿ� �˰��� : ���ڿ�, �ؽø�, ���Ʈ ����

��ó : Fukuoka 2011 B��
*/

char pat[16][32], vis[16][32];
int dxy[8][2] = { {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1} };
unordered_map<string, int> u;

void clearmat(char* s, int h, int w, int ww) {
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) s[i * ww + j] = 0;
    }
}

int main(void) {
    int h, w, x, y;
    string s;
    while (1) {
        scanf("%d %d", &h, &w);
        if (h == 0) break;
        for (int i = 0; i < h; i++) {
            scanf("%s", pat[i]);
        }
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                for (int d = 0; d < 8; d++) {
                    x = i, y = j;
                    s = "";
                    while (!vis[x][y]) {
                        vis[x][y] = 1;
                        s += pat[x][y];
                        if (s.length() > 1) {
                            if (u.find(s) == u.end()) u.insert(pair<string, int>(s, 1));
                            else u[s]++;
                        }
                        x += dxy[d][0];
                        y += dxy[d][1];
                        if (x < 0) x += h;
                        if (x >= h) x -= h;
                        if (y < 0) y += w;
                        if (y >= w) y -= w;
                    }
                    clearmat((char*)vis, h, w, 32);
                }
            }
        }

        s = "";
        for (auto i : u) {
            if (i.second > 1) {
                if (i.first.length() > s.length()) s = i.first;
                else if (i.first.length() == s.length() && s.compare(i.first) > 0) s = i.first;
            }
        }
        u.clear();
        if (s.length() < 2) printf("0\n");
        else printf("%s\n", s.c_str());
    }
    return 0;
}