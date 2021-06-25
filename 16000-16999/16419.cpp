#include <stdio.h>
#include <vector>
#define INF 987654321
using namespace std;

/*
���� : 1���� 9������ ���� ���� ���̰� �ִ�. �ֻ��� 2���� ������ ����� ���� ���� �ֻ��� ���� �հ� ���� ���� �ǵ��� �� ��� �����.
�̸� �ݺ��ϴٰ� ���� �� ���� ���� ������ ���� ���� ���� ���ڷ� �����Ͽ� ������ ��´�. ���� ������ ���°� �־��� ��,
���� ������ ���� ��� ������ ���� ���� ��� ������ ���� �����ؾ� �ϴ� ���� �׶� ���� �� �ִ� ������ ����� ���Ѵ�.

�ذ� ��� : ����, �ֻ����� �� �պ��� ���� �� �ִ� ���� ������ ���Ѵ�. �� �������δ� ��� ���� ����(2^9����)�� ����
���� ���� �� �ִ� ���� ������ �ֻ����� �պ��� ���� ����, �̰��� �������� ������ �׷����� �����.
���� �� �׷������� �ֻ����� �պ��� ��츦 ������ ���� ���� ���� ���� ū ���� ���� ���� ����� ���Ѵ�.
��Ʈ����ŷ�� ���� ���¸� ������ٸ� 0���� ������� ������ ����� ���� �׻� ���� �۾����� �����̹Ƿ� DP�� �����ϴ� ���� ����������.
DP�� ������ �������� ��μ� ������ �Է¹ް� ���� ���¸� Ȯ���� �� ���� ���¿��� ������ �ִ񰪰� �ּڰ��� ã�� ����
�׷� ���� ����� �׿� ���� ����� ���ϸ� �ȴ�.

�ֿ� �˰��� : DP, Ʈ��DP, Ȯ����, ���շ�, ����

��ó : PacNW 2018 K/X�� // SEUSA 2018 F�� / 2018D2 E��
*/

int nums[9], ins[512], ends[512];
double tlow[16], thigh[16], prob[16], lowest[512], highest[512];
vector<int> rev[512];
vector<pair<int, int>> cango[512];
vector<vector<int>> comb[16];

int main(void) {
    for (int i = 2; i <= 12; i++) {
        for (int a = 1; a <= 9; a++) {
            if (a == i) comb[i].push_back(vector<int>{a});
            for (int b = a + 1; b <= 9; b++) {
                if(a + b == i) comb[i].push_back(vector<int>{a, b});
                for (int c = b + 1; c <= 9; c++) {
                    if(a + b + c == i) comb[i].push_back(vector<int>{a, b, c});
                    for (int d = c + 1; d <= 9; d++) {
                        if (a + b + c + d == i) comb[i].push_back(vector<int>{a, b, c, d}); //���� 12 ������ ���� �߰�
                    }
                }
            }
        }
    }

    int ok, ito;
    for (int i = 0; i < 512; i++) {
        for (int j = 0; j < 9; j++) {
            nums[j] = ((i >> j) & 1) * (j + 1);
            if (nums[j]) ends[i] = ends[i] * 10 + nums[j]; //�ڸ���
        }
        for (int j = 2; j <= 12; j++) {
            for (auto k : comb[j]) {
                ok = 1;
                ito = i;
                for (int l : k) {
                    if (!nums[l - 1]) ok = 0; //�ش� ���� ���� ��� ���� ó��
                    else ito -= (1 << (l - 1));
                }
                if (ok) {
                    cango[i].push_back(pair<int, int>(j, ito));
                    rev[ito].push_back(i);
                    ins[i]++;
                }
            }
        }
    }

    for (int i = 2; i <= 12; i++) {
        if (i < 7) prob[i] = 1.0 / 36 * (i - 1); //Ȯ�� �߰�
        else prob[i] = 1.0 / 36 * (13 - i);
    }

    for (int j = 0; j < 512; j++) {
        //DAG DP
        for (int k = 2; k <= 12; k++) {
            tlow[k] = INF;
            thigh[k] = -INF;
        }

        for (int k = 0; k < cango[j].size(); k++) {
            //�ֻ����� �պ��� ���� ���� ���� ���� ū ���� ���´�.
            if (lowest[cango[j][k].second] < tlow[cango[j][k].first]) {
                tlow[cango[j][k].first] = lowest[cango[j][k].second];
            }
            if (highest[cango[j][k].second] > thigh[cango[j][k].first]) {
                thigh[cango[j][k].first] = highest[cango[j][k].second];
            }
        }
        for (int k = 2; k <= 12; k++) {
            //���� ���� ���� ū ���� �ش� ���� ���� Ȯ���� ���ؼ� ���ϵ�, �� ���� ���� ����� ���ٸ� ���� ���� ��� �����.
            if (tlow[k] > 234567890) {
                lowest[j] += ends[j] * prob[k];
            }
            else lowest[j] += tlow[k] * prob[k];
            if (thigh[k] < -100) {
                highest[j] += ends[j] * prob[k];
            }
            else highest[j] += thigh[k] * prob[k];
        }
        for (int k : rev[j]) ins[k]--;
        ins[j]--;
    }

    int d, a, b, start = -1, lt = -1, ht = -1, ln = 0, hn = 0;
    double l = INF, h = -INF;
    scanf("%d %d %d", &d, &a, &b);
    for (int i = 0; i < 512; i++) {
        if (d == ends[i]) start = i; //������ Ȯ��
    }
    for (int i = 0; i < cango[start].size(); i++) {
        if (cango[start][i].first != a + b) continue;
        if (lowest[cango[start][i].second] < l) {
            //���� ���� �� Ȯ��
            l = lowest[cango[start][i].second];
            lt = cango[start][i].second;
        }
        if (highest[cango[start][i].second] > h) {
            //���� ū �� Ȯ��
            h = highest[cango[start][i].second];
            ht = cango[start][i].second;
        }
    }
    if (l == INF) {
        l = ends[start];
        h = ends[start];
    }
    for (int i = 1; i <= 9; i++) {
        if (lt < 0) {
            ln = -1;
            hn = -1;
            break;
        }
        if ((start - lt) & (1 << (i - 1))) ln = ln * 10 + i;
        if ((start - ht) & (1 << (i - 1))) hn = hn * 10 + i;
    }
    printf("%d %.5f\n", ln, l);
    printf("%d %.5f", hn, h);
    return 0;
}