/*
 * 本题要求将给定的 N 个正整数按非递增的顺序，填入“螺旋矩阵”。所谓“螺旋矩阵”，是指从左上角第 1 个格子开始，按顺时针螺旋方向填充。要求矩阵的规模为 m 行 n 列，满足条件：m×n 等于 N；m≥n；且 m−n 取所有可能值中的最小值。

输入格式：
输入在第 1 行中给出一个正整数 N，第 2 行给出 N 个待填充的正整数。所有数字不超过 10
​4
​​ ，相邻数字以空格分隔。

输出格式：
输出螺旋矩阵。每行 n 个数字，共 m 行。相邻数字以 1 个空格分隔，行末不得有多余空格。

输入样例：
12
37 76 20 98 76 42 53 95 60 81 58 93
输出样例：
98 95 93
42 37 81
53 20 76
58 60 76
 */

#include <iostream>
#include <cmath>
#include <algorithm>
//#include <vector>

using namespace std;

bool cmp(int a, int b) {
    return a > b;
}

void get_mn(int *m, int *n, int N) {
    int i = 0;
    do {

        *n = sqrt(N) - i;
        *m = N / *n;
        i++;
    } while (*m * *n != N);
}

int b[10000][1000] = {0};

int main() {

    int N;
    cin >> N;
    int a[N];
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }
    sort(a, a + N, cmp);

    int m, n;
    get_mn(&m, &n, N);

    b[1][1] = a[0];
    int x = 1, y = 1;
    for (int tot = 0; tot < m * n - 1;) {
        while (y + 1 <= n && !b[x][y + 1]) {//向右遍历
            b[x][++y] = a[++tot];
        }
        while (x + 1 <= m && !b[x + 1][y]) {//向下遍历
            b[++x][y] = a[++tot];
        }
        while (y - 1 > 0 && !b[x][y - 1]) {//向左遍历
            b[x][--y] = a[++tot];
        }
        while (x - 1 > 0 && !b[x - 1][y]) {//向右遍历
            b[--x][y] = a[++tot];
        }
    }

    for (int i = 1; i <= m; ++i) {
        cout << b[i][1];
        for (int j = 2; j <= n; ++j) {
            cout << " " << b[i][j];
        }
        cout << endl;
    }

}
