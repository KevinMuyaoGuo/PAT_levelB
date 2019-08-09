/*
 *小明 PAT 考了满分，高兴之余决定发起微博转发抽奖活动，从转发的网友中按顺序每隔 N 个人就发出一个红包。请你编写程序帮助他确定中奖名单。

输入格式：
输入第一行给出三个正整数 M（≤ 1000）、N 和 S，分别是转发的总量、小明决定的中奖间隔、以及第一位中奖者的序号（编号从 1 开始）。随后 M 行，顺序给出转发微博的网友的昵称（不超过 20 个字符、不包含空格回车的非空字符串）。

注意：可能有人转发多次，但不能中奖多次。所以如果处于当前中奖位置的网友已经中过奖，则跳过他顺次取下一位。

输出格式：
按照输入的顺序输出中奖名单，每个昵称占一行。如果没有人中奖，则输出 Keep going...。

输入样例 1：
9 3 2
Imgonnawin!
PickMe
PickMeMeMeee
LookHere
Imgonnawin!
TryAgainAgain
TryAgainAgain
Imgonnawin!
TryAgainAgain
输出样例 1：
PickMe
Imgonnawin!
TryAgainAgain
输入样例 2：
2 3 5
Imgonnawin!
PickMe
输出样例 2：
Keep going...
 */

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int m, n, s;//转发的总量m、决定的中奖间隔n、以及第一位中奖者的序号s（编号从 1 开始）
    cin >> m >> n >> s;
    string name[m];
    for (int i = 0; i < m; ++i) {
        cin >> name[i];
    }
    int flag[m];//是否已中奖的标志
    for (int i = 0; i < m; ++i) {
        flag[i] = 0;
    }

    int no_one_win = 1;//无人中奖标志
    for (int i = s - 1; i < m;) {
        if (!flag[i]) {
            no_one_win = 0;
            for (int j = 0; j < m; ++j) {
                if (name[j] == name[i]) {
                    flag[j] = 1;
                }
            }
            cout << name[i] << endl;
            i+=n;
        } else {
            i++;
        }
    }
    if (no_one_win) {
        cout << "Keep going...";
    }
}
