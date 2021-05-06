#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

/*
���� : ��ǥ���� N(N <= 5000)���� ������ �ִ�. �� ������ �̾ ���� �� �ִ� ��� ������ 135���̰� XY��� ������ �Ȱ����� ���� ���Ѵ�.

�ذ� ��� : ��� ���� ���� �� �������� ������� ���� �Ȱ����� ���� ���ϰ�, �� ������ ���ϸ� �ȴ�.
���鸶�� �̸� ������ ���ص� ���� ��� ���鿡 ���� �ش� ������ X��° ���� ����� ���� ���̳��� ���α׷����� ���� ���ϸ� �Ǵµ�, 
�׷��� ����� ���� X - 1��° ������ �ش� ���� ���� �������� ���� �׾��� �� �������� �Ǵ� ����� ���� ��� ���� �Ͱ� ����.
�׷��� �׷��� �Ǹ� �ð� ���⵵ �� �ð� �� ����� ���������.(N^3), ����, �̰��� ������ Ǯ �� �ִ� ����� ã�ƾ� �ϴµ�,
�������� �̿��ϸ� ������ ã�� �� �ִ�. ����, 8���⿡ ���� ������ ������ ���� ���� ���� �з��Ѵ�.
�� ���� �� ���� ������ �̵� ���⿡ ���� ������ ����, ��ȭ���� ���� ��, �ش� ������ �� ���� ���� ���� ���Ѵ�.
X��° �������� ���� �ش� ������ X - 1��° ���� ���� ���� �Ǵ� ���̴�.
�̸� �ݺ��� ����, ���� ��ġ�� ���ƿ� �������� ������ ���ϸ� �Ȱ����� ���� ���� �� �ִ�.

�ֿ� �˰��� : ���̳��� ���α׷���, ���� ��, ������

��ó : BAPC 2020P E��
*/

//���� : �� -> ���� -> �� -> ���� -> �� -> �»� -> �� -> ���
long long points[5120][2], mem[5120][9];
vector<vector<long long>> lines[8];
int sorting = 0;

int cmp1(int a, int b) {
    //���� �Լ�. �̵� ���� ������ �����Ѵ�.
    int t = 0;
    switch (sorting & 3) {
    case 0:
        t = (points[a][1] < points[b][1]);
        break;
    case 1:
        t = (points[a][0] + points[a][1] < points[b][0] + points[b][1]);
        break;
    case 2:
        t = (points[a][0] < points[b][0]);
        break;
    case 3:
        t = (points[a][0] - points[a][1] < points[b][0] - points[b][1]);
        break;
    }
    if (sorting >= 4) t = !t;
    return t;
}

int main(void) {
    int n, tmp;
    long long sum, r = 0;
    //freopen("C:\\1_����\\PS\\ICPC\\Europe\\BAPC Pre\\2020\\E\\data\\secret\\a-gridh-90-90-2200000.in", "r", stdin);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld %lld", &points[i][0], &points[i][1]);
    }
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < n; j++) {
            tmp = 1;
            for (int k = 0; k < lines[i].size(); k++) {
                //�ش� ���⿡ �ִ� ���鿡 ���� ���� ���� ���� ������� �ִ� ���� �� �� �ִ��� �˻��Ѵ�.
                if (!lines[i][k].size()) continue;
                switch (i & 3) {
                case 0:
                    if (points[j][0] == points[lines[i][k][0]][0]) {
                        lines[i][k].push_back(j);
                        tmp = 0;
                    }
                    break;
                case 1:
                    if (points[j][0] - points[j][1] == points[lines[i][k][0]][0] - points[lines[i][k][0]][1]) {
                        lines[i][k].push_back(j);
                        tmp = 0;
                    }
                    break;
                case 2:
                    if (points[j][1] == points[lines[i][k][0]][1]) {
                        lines[i][k].push_back(j);
                        tmp = 0;
                    }
                    break;
                case 3:
                    if (points[j][0] + points[j][1] == points[lines[i][k][0]][0] + points[lines[i][k][0]][1]) {
                        lines[i][k].push_back(j);
                        tmp = 0;
                    }
                    break;
                }
                if (!tmp) break;
            }
            if (!tmp) continue;

            lines[i].push_back(vector<long long>());
            lines[i][lines[i].size() - 1].push_back(j);
            //�� �� ���� ��� ���ο� ���� �����.
        }
    }

    for (int i = 0; i < 8; i++) {
        sorting = i;
        for (int j = 0; j < lines[i].size(); j++) {
            sort(lines[i][j].begin(), lines[i][j].end(), cmp1); //�� ������ �����Ѵ�.
        }
    }

    for (int i = 0; i < n; i++) {
        mem[i][0] = 1; //�������� 1�� ����д�.
        for (int step = 1; step <= 8; step++) {
            for (int j = 0; j < lines[step - 1].size(); j++) {
                sum = 0; //�������� �ʱ�ȭ�Ѵ�.
                for (int k = 0; k < lines[step - 1][j].size(); k++) {
                    mem[lines[step - 1][j][k]][step] = sum; //�ش� ��ġ�� ���� ���� ���� �ִ� ������ ���� �ܰ��� ���� �հ� ����.
                    sum += mem[lines[step - 1][j][k]][step - 1]; //���� ���� ������Ʈ�Ѵ�.
                }
            }
        }
        r += mem[i][8]; //�ٽ� ���ƿ� ���� �ش� ������ ����� �Ȱ����� ���� ����.
        for (int j = 0; j < n; j++) {
            for (int k = 0; k <= 8; k++) {
                mem[j][k] = 0; //�޸𸮸� �ʱ�ȭ�Ѵ�.
            }
        }
    }
    printf("%lld", r);
    return 0;
}