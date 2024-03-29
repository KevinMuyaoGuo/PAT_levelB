/*
 * 下图是上海某校的新学期开学寄语：天将降大任于斯人也，必先删其微博，卸其 QQ，封其电脑，夺其手机，收其 ipad，断其 wifi，使其百无聊赖，然后，净面、理发、整衣，然后思过、读书、锻炼、明智、开悟、精进。而后必成大器也！

jiyu.JPG

本题要求你写个程序帮助这所学校的老师检查所有学生的物品，以助其成大器。

输入格式：
输入第一行给出两个正整数 N（≤ 1000）和 M（≤ 6），分别是学生人数和需要被查缴的物品种类数。第二行给出 M 个需要被查缴的物品编号，其中编号为 4 位数字。随后 N 行，每行给出一位学生的姓名缩写（由 1-4 个大写英文字母组成）、个人物品数量 K（0 ≤ K ≤ 10）、以及 K 个物品的编号。

输出格式：
顺次检查每个学生携带的物品，如果有需要被查缴的物品存在，则按以下格式输出该生的信息和其需要被查缴的物品的信息（注意行末不得有多余空格）：

姓名缩写: 物品编号1 物品编号2 ……
最后一行输出存在问题的学生的总人数和被查缴物品的总数。

输入样例：
4 2
2333 6666
CYLL 3 1234 2345 3456
U 4 9966 6666 8888 6666
GG 2 2333 7777
JJ 3 0012 6666 2333
输出样例：
U: 6666 6666
GG: 2333
JJ: 6666 2333
3 5
 */

#include <iostream>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    string no[m];
    for (int i = 0; i < m; ++i) {
        cin >> no[i];
    }
    string name[n];
    int k[n];
    string item[n][10];
    for (int i = 0; i < n; ++i) {
        cin>>name[i]>>k[i];
        for (int j = 0; j < k[i]; ++j) {
            cin >> item[i][j];
        }
    }

    int stu_count=0,item_count=0;
    for (int i = 0; i < n; ++i) {
        bool f=true;
        for (int j = 0; j < k[i]; ++j) {
            for (int l = 0; l < m; ++l) {
                if (item[i][j] == no[l]) {
                    if(f) {
                        cout << name[i] << ":";
                        stu_count++;
                    }
                    f=false;
                    cout << " "<<item[i][j];
                    item_count++;
                }
            }
        }
        if(!f) cout<<endl;
    }

    cout<<stu_count<<" "<<item_count;
}