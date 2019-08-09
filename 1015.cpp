/*
 *宋代史学家司马光在《资治通鉴》中有一段著名的“德才论”：“是故才德全尽谓之圣人，才德兼亡谓之愚人，德胜才谓之君子，才胜德谓之小人。凡取人之术，苟不得圣人，君子而与之，与其得小人，不若得愚人。”

现给出一批考生的德才分数，请根据司马光的理论给出录取排名。

输入格式：
输入第一行给出 3 个正整数，分别为：N（≤10
​5
​​ ），即考生总数；L（≥60），为录取最低分数线，即德分和才分均不低于 L 的考生才有资格被考虑录取；H（<100），为优先录取线——德分和才分均不低于此线的被定义为“才德全尽”，此类考生按德才总分从高到低排序；才分不到但德分到线的一类考生属于“德胜才”，也按总分排序，但排在第一类考生之后；德才分均低于 H，但是德分不低于才分的考生属于“才德兼亡”但尚有“德胜才”者，按总分排序，但排在第二类考生之后；其他达到最低线 L 的考生也按总分排序，但排在第三类考生之后。

随后 N 行，每行给出一位考生的信息，包括：准考证号 德分 才分，其中准考证号为 8 位整数，德才分为区间 [0, 100] 内的整数。数字间以空格分隔。

输出格式：
输出第一行首先给出达到最低分数线的考生人数 M，随后 M 行，每行按照输入格式输出一位考生的信息，考生按输入中说明的规则从高到低排序。当某类考生中有多人总分相同时，按其德分降序排列；若德分也并列，则按准考证号的升序输出。

输入样例：
14 60 80
10000001 64 90
10000002 90 60
10000011 85 80
10000003 85 80
10000004 80 85
10000005 82 77
10000006 83 76
10000007 90 78
10000008 75 79
10000009 59 90
10000010 88 45
10000012 80 100
10000013 90 99
10000014 66 60
输出样例：
12
10000013 90 99
10000012 80 100
10000003 85 80
10000011 85 80
10000004 80 85
10000007 90 78
10000006 83 76
10000005 82 77
10000002 90 60
10000014 66 60
10000008 75 79
10000001 64 90
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct stu {
    string no;
    int de;
    int cai;
};

bool cmp1(stu t1, stu t2) {
    if (t1.de + t1.cai == t2.de + t2.cai) {
        if (t1.de == t2.de) {
            return t1.no < t2.no;
        } else {
            return t1.de > t2.de;
        }
    } else {
        return t1.de + t1.cai > t2.de + t2.cai;
    }
}

int main() {
    int n, l, h;
    cin >> n >> l >> h;
    vector<stu> s1, s2, s3, s4;//第1，2，3，4类考生
    int m = 0;
    stu st;
    //输入
    for (int i = 0; i < n; ++i) {
        cin >> st.no >> st.de >> st.cai;
        if (st.de >= l && st.cai >= l) {
            if (st.de >= h && st.cai >= h) {
                s1.emplace_back(st);
            } else if (st.de >= h && st.cai < h) {
                s2.emplace_back(st);
            } else if (st.de < h && st.cai < h && st.de >= st.cai) {
                s3.emplace_back(st);
            } else {
                s4.emplace_back(st);
            }
            m++;
        }
    }

    //四类考生分别排序
    sort(s1.begin(), s1.end(), cmp1);
    sort(s2.begin(), s2.end(), cmp1);
    sort(s3.begin(), s3.end(), cmp1);
    sort(s4.begin(), s4.end(), cmp1);

    //打印
    cout<<m<<endl;
    for (int i = 0; i < s1.size(); ++i) {
        cout<<s1[i].no<<" "<<s1[i].de<<" "<<s1[i].cai<<endl;
    }
    for (int i = 0; i < s2.size(); ++i) {
        cout<<s2[i].no<<" "<<s2[i].de<<" "<<s2[i].cai<<endl;
    }
    for (int i = 0; i < s3.size(); ++i) {
        cout<<s3[i].no<<" "<<s3[i].de<<" "<<s3[i].cai<<endl;
    }
    for (int i = 0; i < s4.size(); ++i) {
        cout<<s4[i].no<<" "<<s4[i].de<<" "<<s4[i].cai<<endl;
    }
}