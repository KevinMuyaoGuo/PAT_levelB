/*
 * 给定 N 张卡片，正面分别写上 1、2、……、N，然后全部翻面，洗牌，在背面分别写上 1、2、……、N。将每张牌的正反两面数字相减（大减小），得到 N 个非负差值，其中是否存在相等的差？

输入格式：
输入第一行给出一个正整数 N（2 ≤ N ≤ 10 000），随后一行给出 1 到 N 的一个洗牌后的排列，第 i 个数表示正面写了 i 的那张卡片背面的数字。

输出格式：
按照“差值 重复次数”的格式从大到小输出重复的差值及其重复的次数，每行输出一个结果。

输入样例：
8
3 5 8 6 2 1 4 7
输出样例：
5 2
3 3
2 2
 */

#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.first > b.first;
}

int main() {
    int n;
    cin >> n;
    int a[n], b[n];
    for (int j = 0; j < n; ++j) {
        b[j] = 0;
    }
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        b[abs(a[i] - (i + 1))]++;
    }
    vector<pair<int,int>> v;
    for (int i = 0; i < n; ++i) {
        if (b[i] >= 2) {
            v.push_back(pair<int, int>(i, b[i]));
        }
    }
    sort(v.begin(), v.end(), cmp);
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i].first << " " << v[i].second << endl;
    }
}