/*
 *每次 PAT 考试结束后，考试中心都会发布一个考生单位排行榜。本题就请你实现这个功能。

输入格式：
输入第一行给出一个正整数 N（≤10
​5
​​ ），即考生人数。随后 N 行，每行按下列格式给出一个考生的信息：

准考证号 得分 学校
其中准考证号是由 6 个字符组成的字符串，其首字母表示考试的级别：B代表乙级，A代表甲级，T代表顶级；得分是 [0, 100] 区间内的整数；学校是由不超过 6 个英文字母组成的单位码（大小写无关）。注意：题目保证每个考生的准考证号是不同的。

输出格式：
首先在一行中输出单位个数。随后按以下格式非降序输出单位的排行榜：

排名 学校 加权总分 考生人数
其中排名是该单位的排名（从 1 开始）；学校是全部按小写字母输出的单位码；加权总分定义为乙级总分/1.5 + 甲级总分 + 顶级总分*1.5的整数部分；考生人数是该属于单位的考生的总人数。

学校首先按加权总分排行。如有并列，则应对应相同的排名，并按考生人数升序输出。如果仍然并列，则按单位码的字典序输出。

输入样例：
10
A57908 85 Au
B57908 54 LanX
A37487 60 au
T28374 67 CMU
T32486 24 hypu
A66734 92 cmu
B76378 71 AU
A47780 45 lanx
A72809 100 pku
A03274 45 hypu
输出样例：
5
1 cmu 192 2
1 au 192 3
3 pku 100 1
4 hypu 81 2
4 lanx 81 2
 */


#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct student {
    string no;
    int score;
    string school;
};

struct school {
    int B = 0;
    int A = 0;
    int T = 0;
    int cnt = 0;
    int tot = 0;//总分
    string name;
};

bool cmp(pair<string,school> p1,pair<string,school> p2) {
    if (p1.second.tot == p2.second.tot) {
        if (p1.second.cnt == p2.second.cnt) {
            return p1.second.name < p2.second.name;
        } else {
            return p1.second.cnt < p2.second.cnt;
        }
    } else {
        return p1.second.tot > p2.second.tot;
    }
}

int main() {
    int n;
    cin >> n;
    map<string, school> m;
    map<string, school>::iterator it;
    for (int i = 0; i < n; ++i) {
        student s;
        cin >> s.no >> s.score >> s.school;
        transform(s.school.begin(), s.school.end(), s.school.begin(), ::tolower);
        it = m.find(s.school);
        if (it == m.end()) {
            school sc;
            if (s.no[0] == 'B') {
                sc.B = s.score;
            } else if (s.no[0] == 'A') {
                sc.A = s.score;
            } else {
                sc.T = s.score;
            }
            sc.cnt++;
            sc.name = s.school;
            m.insert(pair<string, school>(s.school, sc));
        } else {
            if (s.no[0] == 'B') {
                it->second.B += s.score;
            } else if (s.no[0] == 'A') {
                it->second.A += s.score;
            } else {
                it->second.T += s.score;
            }
            it->second.cnt++;
        }
    }

    for (it = m.begin(); it != m.end(); ++it) {
        it->second.tot = it->second.B / 1.5 + it->second.A + it->second.T * 1.5;
    }

    vector<pair<string,school>> v;
    for (it = m.begin(); it != m.end(); ++it) {
        v.emplace_back(pair<string, school>(it->first, it->second));
    }

    sort(v.begin(), v.end(), cmp);

    cout<<v.size()<<endl;
    cout<<"1"<<" "<<v[0].first<<" "<<v[0].second.tot<<" "<<v[0].second.cnt<<endl;
    int count=1,tmp=1;
    for (int i = 1; i < v.size(); ++i) {
        if (v[i].second.tot == v[i - 1].second.tot) {
            tmp++;
            cout<<count<<" "<<v[i].first<<" "<<v[i].second.tot<<" "<<v[i].second.cnt<<endl;
        }else{
            count+=tmp;
            tmp=1;
            cout<<count<<" "<<v[i].first<<" "<<v[i].second.tot<<" "<<v[i].second.cnt<<endl;
        }
    }
}