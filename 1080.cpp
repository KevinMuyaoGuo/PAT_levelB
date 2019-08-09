/*
 * 对于在中国大学MOOC（http://www.icourse163.org/ ）学习“数据结构”课程的学生，想要获得一张合格证书，必须首先获得不少于200分的在线编程作业分，然后总评获得不少于60分（满分100）。总评成绩的计算公式为 G=(G
​mid−term
​​ ×40%+G
​final
​​ ×60%)，如果 G
​mid−term
​​ >G
​final
​​ ；否则总评 G 就是 G
​final
​​ 。这里 G
​mid−term
​​  和 G
​final
​​  分别为学生的期中和期末成绩。

现在的问题是，每次考试都产生一张独立的成绩单。本题就请你编写程序，把不同的成绩单合为一张。

输入格式：
输入在第一行给出3个整数，分别是 P（做了在线编程作业的学生数）、M（参加了期中考试的学生数）、N（参加了期末考试的学生数）。每个数都不超过10000。

接下来有三块输入。第一块包含 P 个在线编程成绩 G
​p
​​ ；第二块包含 M 个期中考试成绩 G
​mid−term
​​ ；第三块包含 N 个期末考试成绩 G
​final
​​ 。每个成绩占一行，格式为：学生学号 分数。其中学生学号为不超过20个字符的英文字母和数字；分数是非负整数（编程总分最高为900分，期中和期末的最高分为100分）。

输出格式：
打印出获得合格证书的学生名单。每个学生占一行，格式为：

学生学号 G
​p
​​  G
​mid−term
​​  G
​final
​​  G

如果有的成绩不存在（例如某人没参加期中考试），则在相应的位置输出“−1”。输出顺序为按照总评分数（四舍五入精确到整数）递减。若有并列，则按学号递增。题目保证学号没有重复，且至少存在1个合格的学生。

输入样例：
6 6 7
01234 880
a1903 199
ydjh2 200
wehu8 300
dx86w 220
missing 400
ydhfu77 99
wehu8 55
ydjh2 98
dx86w 88
a1903 86
01234 39
ydhfu77 88
a1903 66
01234 58
wehu8 84
ydjh2 82
missing 99
dx86w 81
输出样例：
missing 400 -1 99 99
ydjh2 200 98 82 88
dx86w 220 88 81 84
wehu8 300 55 84 84
 */

#include<iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

struct stu {
    string sno;
    int gp = -1;
    int gm = -1;
    int gf = -1;
    int g = -1;
};

int G(int gm, int gf) {
    double g;
    if (gm == -1) {
        gm = 0;
    }
    if (gf == -1) {
        gf = 0;
    }
    if (gm > gf) {
        g = gm * 0.4 + gf * 0.6;
    } else {
        g = gf;
    }
    return round(g);
}

bool compare(struct stu s1,struct stu s2){
    if (s1.g == s2.g) {
        return s1.sno < s2.sno;
    }
    return s1.g > s2.g;
}

int main() {
    int p, m, n;
    int no=1;
    cin >> p >> m >> n;
    map<string,int> mp;
    vector<struct stu> v;
    for (int i = 0; i < p; ++i) {
        struct stu s;
        cin >> s.sno >> s.gp;
        if (s.gp >= 200) {
            mp[s.sno]=no++;//no为录入string的序号，从1开始
            v.push_back(s);

        }
    }

    for (int i = 0; i < m; ++i) {
        struct stu s;
        cin >> s.sno >> s.gm;
        if (mp[s.sno]) {
            v[mp[s.sno]-1].gm = s.gm;
        }
    }

    for (int i = 0; i < n; ++i) {
        struct stu s;
        cin >> s.sno >> s.gf;
        if (mp[s.sno]) {
            v[mp[s.sno] - 1].gf = s.gf;
        }
    }

    for (int i = 0; i < v.size(); ++i) {
        v[i].g = G(v[i].gm, v[i].gf);
    }

    sort(v.begin(), v.end(), compare);

    for (int i = 0; i < v.size(); ++i) {
        if (v[i].g >= 60)
            cout << v[i].sno << " " << v[i].gp << " " << v[i].gm << " " << v[i].gf
                 << " " << v[i].g << endl;
    }
}


/* 不用map,最后一个测试点会超时
 *
 * #include<iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

struct stu {
    string sno;
    int gp = -1;
    int gm = -1;
    int gf = -1;
    int g = -1;
};

int G(int gm, int gf) {
    double g;
    if (gm == -1) {
        gm = 0;
    }
    if (gf == -1) {
        gf = 0;
    }
    if (gm > gf) {
        g = gm * 0.4 + gf * 0.6;
    } else {
        g = gf;
    }
    return round(g);
}

bool compare(struct stu s1,struct stu s2){
    if (s1.g == s2.g) {
        return s1.sno < s2.sno;
    }
    return s1.g > s2.g;
}

int main() {
    int p, m, n;
    cin >> p >> m >> n;
    vector<struct stu> v;
    for (int i = 0; i < p; ++i) {
        struct stu s;
        cin >> s.sno >> s.gp;
        v.push_back(s);
    }

    for (int i = 0; i < m; ++i) {
        struct stu s;
        cin >> s.sno >> s.gm;
        int flag = 1;
        for (int j = 0; j < p; ++j) {
            if (s.sno == v[j].sno) {
                v[j].gm = s.gm;
                flag = 0;
                break;
            }
        }
        if (flag) {
            v.push_back(s);
        }
    }

    for (int i = 0; i < n; ++i) {
        struct stu s;
        cin >> s.sno >> s.gf;
        int flag = 1;
        for (int j = 0; j < v.size(); ++j) {
            if (s.sno == v[j].sno) {
                v[j].gf = s.gf;
                flag = 0;
                break;
            }
        }
        if (flag) {
            v.push_back(s);
        }
    }

    for (int i = 0; i < v.size(); ++i) {
        v[i].g = G(v[i].gm, v[i].gf);
    }

    sort(v.begin(), v.end(), compare);

    for (int i = 0; i < v.size(); ++i) {
        if (v[i].gp >= 200 && v[i].g >= 60)
            cout << v[i].sno << " " << v[i].gp << " " << v[i].gm << " " << v[i].gf
                 << " " << v[i].g << endl;
    }
}*/
