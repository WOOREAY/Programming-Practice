/*
C:魔兽世界之二：装备
查看提交统计提问
总时间限制: 1000ms 内存限制: 65536kB
描述
魔兽世界的西面是红魔军的司令部，东面是蓝魔军的司令部。两个司令部之间是依次排列的若干城市。

红司令部，City 1，City 2，……，City n，蓝司令部

两军的司令部都会制造武士。武士一共有 dragon 、ninja、iceman、lion、wolf 五种。每种武士都有编号、生命值这两种属性。
有的武士可以拥有武器。武器有三种，sword, bomb,和arrow，编号分别为0,1,2。
双方的武士编号都是从1开始计算。红方制造出来的第 n 个武士，编号就是n。同样，蓝方制造出来的第 n 个武士，编号也是n。

不同的武士有不同的特点。
dragon 可以拥有一件武器。编号为n的dragon降生时即获得编号为 n%3 的武器。dragon还有“士气”这个属性，是个浮点数，其值为它降生后其司令部剩余生命元的数量除以造dragon所需的生命元数量。
ninja可以拥有两件武器。编号为n的ninja降生时即获得编号为 n%3 和 (n+1)%3的武器。
iceman有一件武器。编号为n的iceman降生时即获得编号为 n%3 的武器。
lion 有“忠诚度”这个属性，其值等于它降生后其司令部剩余生命元的数目。
wolf没特点。
请注意，在以后的题目里，武士的士气，生命值，忠诚度在其生存期间都可能发生变化，都有作用，武士手中的武器随着使用攻击力也会发生变化。

武士在刚降生的时候有一个生命值。

在每个整点，双方的司令部中各有一个武士降生。

红方司令部按照 iceman、lion、wolf、ninja、dragon 的顺序循环制造武士。

蓝方司令部按照 lion、dragon、ninja、iceman、wolf 的顺序循环制造武士。

制造武士需要生命元。

制造一个初始生命值为 m 的武士，司令部中的生命元就要减少 m 个。

如果司令部中的生命元不足以制造某个按顺序应该制造的武士，那么司令部就试图制造下一个。如果所有武士都不能制造了，则司令部停止制造武士。
给定一个时间，和双方司令部的初始生命元数目，要求你将从0点0分开始到双方司令部停止制造武士为止的所有事件按顺序输出。
一共有两种事件，其对应的输出样例如下：

1) 武士降生
输出样例： 004 blue lion 5 born with strength 5,2 lion in red headquarter
表示在 4点整，编号为5的蓝魔lion武士降生，它降生时生命值为5,降生后蓝魔司令部里共有2个lion武士。(为简单起见，不考虑单词的复数形式)注意，每制造出一个新的武士，都要输出此时司令部里共有多少个该种武士。
如果造出的是dragon，那么还要输出一行，例：
It has a arrow,and it's morale is 23.34
表示该dragon降生时得到了arrow,其士气是23.34（为简单起见，本题中arrow前面的冠词用a,不用an，士气精确到小数点后面2位，四舍五入）
如果造出的是ninja，那么还要输出一行，例：
It has a bomb and a arrow
表示该ninja降生时得到了bomb和arrow。
如果造出的是iceman，那么还要输出一行，例：
It has a sword
表示该iceman降生时得到了sword。
如果造出的是lion，那么还要输出一行，例：
It's loyalty is 24
表示该lion降生时的忠诚度是24。
2) 司令部停止制造武士
输出样例： 010 red headquarter stops making warriors
表示在 10点整，红方司令部停止制造武士

输出事件时：

首先按时间顺序输出；

同一时间发生的事件，先输出红司令部的，再输出蓝司令部的。

输入
第一行是一个整数,代表测试数据组数。

每组测试数据共两行。

第一行，一个整数M。其含义为： 每个司令部一开始都有M个生命元( 1 <= M <= 10000)

第二行：五个整数，依次是 dragon 、ninja、iceman、lion、wolf 的初始生命值。它们都大于0小于等于10000
输出
对每组测试数据，要求输出从0时0分开始，到双方司令部都停止制造武士为止的所有事件。
对每组测试数据，首先输出“Case:n" n是测试数据的编号，从1开始
接下来按恰当的顺序和格式输出所有事件。每个事件都以事件发生的时间开头，时间以小时为单位，有三位。
样例输入
1
20
3 4 5 6 7
样例输出
Case:1
000 red iceman 1 born with strength 5,1 iceman in red headquarter
It has a bomb
000 blue lion 1 born with strength 6,1 lion in blue headquarter
It's loyalty is 14
001 red lion 2 born with strength 6,1 lion in red headquarter
It's loyalty is 9
001 blue dragon 2 born with strength 3,1 dragon in blue headquarter
It has a arrow,and it's morale is 3.67
002 red wolf 3 born with strength 7,1 wolf in red headquarter
002 blue ninja 3 born with strength 4,1 ninja in blue headquarter
It has a sword and a bomb
003 red headquarter stops making warriors
003 blue iceman 4 born with strength 5,1 iceman in blue headquarter
It has a bomb
004 blue headquarter stops making warriors
查看 提交 统计 提问
*/

#include <iostream>
#include <cstring>
#include <iomanip>
 
using namespace std;

class Weapon {
public:
    char _name[20]{};
    int _id;
 
    Weapon(int id, const char *name) {
        _id = id;
        strcpy(_name, name);
    }
 
    Weapon(const Weapon &weapon) {
        _id = weapon._id;
        strcpy(_name, weapon._name);
    }
};
 
Weapon *weaponPool[3] = {new Weapon(0, "sword"), new Weapon(1, "bomb"),
                         new Weapon(2, "arrow")};
 
class Soldier {
private:
    int _hp;
 
    friend class HeadQuarter;
 
protected:
    char _name[20]{};
    int _seqNum;
 
public:
    explicit Soldier(const char *name, int hp = -1, int seqNum = 0) {
        strcpy(_name, name);
        _hp = hp;
        _seqNum = seqNum;
    }
 
    void SetHp(int hp) {
        _hp = hp;
    }
 
    void PrintBasicInfo() const {
        cout << _seqNum << " " << _name;
    }
 
    virtual void PrintSpecialInfo() const {};
};
 
class Dragon : public Soldier {
private:
    Weapon *_weapon1;
    double _morale;
public:
    explicit Dragon(int seqNum = 0, int totalNum = 0, int leftPower = 0, int hp = -1) : Soldier("dragon", hp, seqNum),
                                                             _morale((double) leftPower / hp) {
        switch (totalNum % 3) {
            case 0:
                _weapon1 = new Weapon(*weaponPool[0]);
                break;
            case 1:
                _weapon1 = new Weapon(*weaponPool[1]);
                break;
            case 2:
                _weapon1 = new Weapon(*weaponPool[2]);
                break;
            default:
                cout << "Fail to generate illegal weapon!" << endl;
                exit(0);
        }
    }
 
    void PrintSpecialInfo() const override {
        cout << "It has a " << _weapon1->_name << ",and it's morale is " << _morale << endl;
    }
};
 
class Ninja : public Soldier {
private:
    Weapon *_weapon1;
    Weapon *_weapon2;
public:
    explicit Ninja(int seqNum = 0, int totalNum = 0, int hp = -1) : Soldier("ninja", hp, seqNum) {
        switch (totalNum % 3) {
            case 0:
                _weapon1 = new Weapon(*weaponPool[0]);
                _weapon2 = new Weapon(*weaponPool[1]);
                break;
            case 1:
                _weapon1 = new Weapon(*weaponPool[1]);
                _weapon2 = new Weapon(*weaponPool[2]);
                break;
            case 2:
                _weapon1 = new Weapon(*weaponPool[2]);
                _weapon2 = new Weapon(*weaponPool[0]);
                break;
            default:
                cout << "Fail to generate illegal weapon!" << endl;
                exit(0);
        }
    }
 
    void PrintSpecialInfo() const override {
        cout << "It has a " << _weapon1->_name << " and a " << _weapon2->_name << endl;
    }
};
 
class Iceman : public Soldier {
private:
    Weapon *_weapon1;
public:
    explicit Iceman(int seqNum = 0, int totalNum = 0, int hp = -1) : Soldier("iceman", hp, seqNum) {
        switch (totalNum % 3) {
            case 0:
                _weapon1 = new Weapon(*weaponPool[0]);
                break;
            case 1:
                _weapon1 = new Weapon(*weaponPool[1]);
                break;
            case 2:
                _weapon1 = new Weapon(*weaponPool[2]);
                break;
            default:
                cout << "Fail to generate illegal weapon!" << endl;
                exit(0);
        }
    }
 
    void PrintSpecialInfo() const override {
        cout << "It has a " << _weapon1->_name << endl;
    }
};
 
class Lion : public Soldier {
private:
    int _loyalty;
public:
    explicit Lion(int seqNum = 0, int totalNum = 0, int leftPower = 0, int hp = -1) : Soldier("lion", hp, seqNum),
                                                           _loyalty(leftPower) {}
 
    void PrintSpecialInfo() const override {
        cout << "It's loyalty is " << setiosflags(ios::fixed) << setprecision(2) << _loyalty << endl;
    }
};
 
class Wolf : public Soldier {
public:
    explicit Wolf(int seqNum = 0, int totalNum = 0, int hp = -1) : Soldier("wolf", hp, seqNum) {}
 
    void PrintSpecialInfo() const override {}
};
 
Soldier *soldierPool[5] = {new Dragon(), new Ninja(),
                           new Iceman(), new Lion(), new Wolf()};
 
class HeadQuarter {
private:
    char _name[20]{};
    int _power;
    int _seq[5]{};
    int _pos;
    int _count[5]{};
    int _totalNum;
    Soldier *_soldierList[50];
    int _seqNumTotal;
public:
    HeadQuarter(const char name[], int power, const int seq[]) : _soldierList() {
        _totalNum = 0;
        _pos = 0;
        _seqNumTotal = 0;
        for (int i = 0; i < 5; ++i) _count[i] = 0;
        strcpy(_name, name);
        _power = power;
        for (int i = 0; i < 5; i++) {
            _seq[i] = seq[i];
        }
    }
 
    bool CanBornSoldier() {
        for (int i = 0; i < 5; ++i) {
            if (_power >= soldierPool[i]->_hp)
                return true;
        }
        return false;
    }
 
    int BornSoldier(int time) {
        if (_pos >= 5) _pos -= 5;
        for (int i = 0; i < 5; ++i) {
            if (_power >= soldierPool[_seq[_pos]]->_hp) {
                _power -= soldierPool[_seq[_pos]]->_hp;
                ++_count[_seq[_pos]];
                ++_totalNum;
                Soldier *newSoldier = soldierPool[_seq[_pos]];
                newSoldier = AddSoldier(newSoldier, _count[_seq[_pos]]);
                PrintBornInfo(newSoldier, time);
                int tempPos = _pos;
                ++_pos;
                return _seq[tempPos];
            } else {
                ++_pos;
                if (_pos >= 5) _pos -= 5;
            }
        }
        return -1;
    }
 
    Soldier *AddSoldier(Soldier *soldierPtr, int seq) {
        if (!strcmp(soldierPtr->_name, "dragon")) {
            _soldierList[_seqNumTotal] = new Dragon(seq, _totalNum, _power, soldierPtr->_hp);
        } else if (!strcmp(soldierPtr->_name, "ninja")) {
            _soldierList[_seqNumTotal] = new Ninja(seq, _totalNum, soldierPtr->_hp);
        } else if (!strcmp(soldierPtr->_name, "iceman")) {
            _soldierList[_seqNumTotal] = new Iceman(seq, _totalNum, soldierPtr->_hp);
        } else if (!strcmp(soldierPtr->_name, "lion")) {
            _soldierList[_seqNumTotal] = new Lion(seq, _totalNum, _power, soldierPtr->_hp);
        } else if (!strcmp(soldierPtr->_name, "wolf")) {
            _soldierList[_seqNumTotal] = new Wolf(seq, _totalNum, soldierPtr->_hp);
        } else {
            cerr << "Fail to generate legal soldier!" << endl;
            exit(0);
        }
        ++_seqNumTotal;
        return _soldierList[_seqNumTotal - 1];
    }
 
    void PrintBornInfo(const Soldier *soldier, int time) {
        cout << setfill('0') << setw(3) << right << time << " " << _name << " "
             << soldier->_name << " " << _totalNum << " born with strength "
             << soldier->_hp << ",";
        soldier->PrintBasicInfo();
        cout << " in " << _name << " headquarter" << endl;
        soldier->PrintSpecialInfo();
    }
 
    void PrintStopInfo(int time) {
        cout << setfill('0') << setw(3) << right << time << " " << _name << " headquarter stops making warriors"
             << endl;
    }
};
 
int main() {
    int caseTotal;
    cin >> caseTotal;
    int caseNum = 0;
    while (caseNum < caseTotal) {
        ++caseNum;
        int time = 0;
        int power;
        cin >> power;
        int redSeq[5] = {2, 3, 4, 1, 0}, blueSeq[5] = {3, 0, 1, 2, 4};
        HeadQuarter red("red", power, redSeq);
        HeadQuarter blue("blue", power, blueSeq);
        int tempHp;
        for (int i = 0; i < 5; ++i) {
            cin >> tempHp;
            soldierPool[i]->SetHp(tempHp);
        }
        cout << "Case:" << caseNum << endl;
        bool flag1 = true, flag2 = true;
        while (true) {
            if (red.CanBornSoldier()) {
                red.BornSoldier(time);
            } else {
                if (flag1)
                    red.PrintStopInfo(time);
                flag1 = false;
            }
            if (blue.CanBornSoldier()) {
                blue.BornSoldier(time);
            } else {
                if (flag2)
                    blue.PrintStopInfo(time);
                flag2 = false;
            }
            if (!red.CanBornSoldier() && !blue.CanBornSoldier() && !flag1 && !flag2) break;
            ++time;
        }
    }
    return 0;
}