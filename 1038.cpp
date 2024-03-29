/*
 * 本题要求读入 N 名学生的成绩，将获得某一给定分数的学生人数输出。

输入格式：
输入在第 1 行给出不超过 10
​5
​​  的正整数 N，即学生总人数。随后一行给出 N 名学生的百分制整数成绩，中间以空格分隔。最后一行给出要查询的分数个数 K（不超过 N 的正整数），随后是 K 个分数，中间以空格分隔。

输出格式：
在一行中按查询顺序给出得分等于指定分数的学生人数，中间以空格分隔，但行末不得有多余空格。

输入样例：
10
60 75 90 55 75 99 82 90 75 50
3 75 90 88
输出样例：
3 2 0
 */

#include<iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    int cnt[101]={0};
    int t;
    for (int i = 0; i < n; ++i) {
        cin >> t;
        cnt[t]++;
    }
    int k;
    cin>>k;
    int p;
    cin>>p;
    cout << cnt[p];
    for (int i = 1; i < k; ++i) {
        cin >> p;
        cout << " " << cnt[p];
    }
}