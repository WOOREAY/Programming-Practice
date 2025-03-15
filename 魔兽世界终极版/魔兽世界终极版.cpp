/*
A:魔兽世界终极版
查看提交统计提问
总时间限制: 6000ms 内存限制: 65536kB
描述
魔兽世界的西面是红魔军的司令部，东面是蓝魔军的司令部。两个司令部之间是依次排列的若干城市，城市从西向东依次编号为1,2,3 .... N ( N <= 20 )。红魔军的司令部算作编号为0的城市，蓝魔军的司令部算作编号为N+1的城市。司令部有生命元，用于制造武士。

两军的司令部都会制造武士。武士一共有 dragon 、ninja、iceman、lion、wolf 五种。每种武士都有编号、生命值、攻击力这三种属性。

双方的武士编号都是从1开始计算。红方制造出来的第 n 个武士，编号就是n。同样，蓝方制造出来的第 n 个武士，编号也是n。

武士在刚降生的时候有一个初始的生命值，生命值在战斗中会发生变化，如果生命值减少到0（生命值变为负数时应当做变为0处理），则武士死亡（消失）。

有的武士可以拥有武器。武器有三种，sword, bomb,和arrow，编号分别为0,1,2。

武士降生后就朝对方司令部走，在经过的城市如果遇到敌人（同一时刻每个城市最多只可能有1个蓝武士和一个红武士），就会发生战斗。每次战斗只有一方发起主动进攻一次。被攻击者生命值会减去进攻者的攻击力值和进攻者手中sword的攻击力值。被进攻者若没死，就会发起反击，被反击者的生命值要减去反击者攻击力值的一半(去尾取整)和反击者手中sword的攻击力值。反击可能致敌人于死地。

如果武士在战斗中杀死敌人（不论是主动进攻杀死还是反击杀死），则其司令部会立即向其发送8个生命元作为奖励，使其生命值增加8。当然前提是司令部得有8个生命元。如果司令部的生命元不足以奖励所有的武士，则优先奖励距离敌方司令部近的武士。

如果某武士在某城市的战斗中杀死了敌人，则该武士的司令部立即取得该城市中所有的生命元。注意，司令部总是先完成全部奖励工作，然后才开始从各个打了胜仗的城市回收生命元。对于因司令部生命元不足而领不到奖励的武士，司令部也不会在取得战利品生命元后为其补发奖励。

如果一次战斗的结果是双方都幸存(平局)，则双方都不能拿走发生战斗的城市的生命元。

城市可以插旗子，一开始所有城市都没有旗子。在插红旗的城市，以及编号为奇数的无旗城市，由红武士主动发起进攻。在插蓝旗的城市，以及编号为偶数的无旗城市，由蓝武士主动发起进攻。

当某个城市有连续两场战斗都是同一方的武士杀死敌人(两场战斗之间如果有若干个战斗时刻并没有发生战斗，则这两场战斗仍然算是连续的；但如果中间有平局的战斗，就不算连续了) ，那么该城市就会插上胜方的旗帜，若原来插着败方的旗帜，则败方旗帜落下。旗帜一旦插上，就一直插着，直到被敌人更换。一个城市最多只能插一面旗帜，旗帜没被敌人更换前，也不会再次插同颜色的旗。

各种武器有其特点：

sword武器的初始攻击力为拥有它的武士的攻击力的20%（去尾取整）。但是sword每经过一次战斗(不论是主动攻击还是反击)，就会变钝，攻击力变为本次战斗前的80% (去尾取整)。sword攻击力变为0时，视为武士失去了sword。如果武士降生时得到了一个初始攻击力为0的sword，则视为武士没有sword.

arrow有一个攻击力值R。如果下一步要走到的城市有敌人，那么拥有arrow的武士就会放箭攻击下一个城市的敌人（不能攻击对方司令部里的敌人）而不被还击。arrow使敌人的生命值减少R，若减至小于等于0，则敌人被杀死。arrow使用3次后即被耗尽，武士失去arrow。两个相邻的武士可能同时放箭把对方射死。

拥有bomb的武士，在战斗开始前如果判断自己将被杀死（不论主动攻击敌人，或者被敌人主动攻击都可能导致自己被杀死，而且假设武士可以知道敌人的攻击力和生命值），那么就会使用bomb和敌人同归于尽。武士不预测对方是否会使用bomb。

武士使用bomb和敌人同归于尽的情况下，不算是一场战斗，双方都不能拿走城市的生命元，也不影响城市的旗帜。

不同的武士有不同的特点。

dragon可以拥有一件武器。编号为n的dragon降生时即获得编号为 n%3 的武器。dragon还有“士气”这个属性，是个浮点数，其值为它降生后其司令部剩余生命元的数量除以造dragon所需的生命元数量。dragon 在一次在它主动进攻的战斗结束后，如果还没有战死，而且士气值大于0.8，就会欢呼。dragon每取得一次战斗的胜利(敌人被杀死)，士气就会增加0.2，每经历一次未能获胜的战斗，士气值就会减少0.2。士气增减发生在欢呼之前。

ninja可以拥有两件武器。编号为n的ninja降生时即获得编号为 n%3 和 (n+1)%3的武器。ninja 挨打了也从不反击敌人。

iceman有一件武器。编号为n的iceman降生时即获得编号为 n%3 的武器。iceman 每前进两步，在第2步完成的时候，生命值会减少9，攻击力会增加20。但是若生命值减9后会小于等于0，则生命值不减9,而是变为1。即iceman不会因走多了而死。

lion 有“忠诚度”这个属性，其初始值等于它降生之后其司令部剩余生命元的数目。每经过一场未能杀死敌人的战斗，忠诚度就降低K。忠诚度降至0或0以下，则该lion逃离战场,永远消失。但是已经到达敌人司令部的lion不会逃跑。Lion在己方司令部可能逃跑。lion 若是战死，则其战斗前的生命值就会转移到对手身上。所谓“战斗前”，就是每个小时的40分前的一瞬间。

wolf降生时没有武器，但是在战斗中如果获胜（杀死敌人），就会缴获敌人的武器，但自己已有的武器就不缴获了。被缴获的武器当然不能算新的，已经被用到什么样了，就是什么样的。

以下是不同时间会发生的不同事件：

在每个整点，即每个小时的第0分， 双方的司令部中各有一个武士降生。

红方司令部按照 iceman、lion、wolf、ninja、dragon 的顺序制造武士。

蓝方司令部按照 lion、dragon、ninja、iceman、wolf 的顺序制造武士。

制造武士需要生命元。

制造一个初始生命值为 m 的武士，司令部中的生命元就要减少 m 个。

如果司令部中的生命元不足以制造某武士，那么司令部就等待，直到获得足够生命元后的第一个整点，才制造该武士。例如，在2:00，红方司令部本该制造一个 wolf ，如果此时生命元不足，那么就会等待，直到生命元足够后的下一个整点，才制造一个 wolf。

在每个小时的第5分，该逃跑的lion就在这一时刻逃跑了。

在每个小时的第10分：所有的武士朝敌人司令部方向前进一步。即从己方司令部走到相邻城市，或从一个城市走到下一个城市。或从和敌军司令部相邻的城市到达敌军司令部。

在每个小时的第20分：每个城市产出10个生命元。生命元留在城市，直到被武士取走。

在每个小时的第30分：如果某个城市中只有一个武士，那么该武士取走该城市中的所有生命元，并立即将这些生命元传送到其所属的司令部。

在每个小时的第35分，拥有arrow的武士放箭，对敌人造成伤害。放箭事件应算发生在箭发出的城市。注意，放箭不算是战斗，因此放箭的武士不会得到任何好处。武士在没有敌人的城市被箭射死也不影响其所在城市的旗帜更换情况。

在每个小时的第38分，拥有bomb的武士评估是否应该使用bomb。如果是，就用bomb和敌人同归于尽。

在每个小时的第40分：在有两个武士的城市，会发生战斗。 如果敌人在5分钟前已经被飞来的arrow射死，那么仍然视为发生了一场战斗，而且存活者视为获得了战斗的胜利。此情况下不会有“武士主动攻击”，“武士反击”，“武士战死”的事件发生，但战斗胜利后应该发生的事情都会发生。如Wolf一样能缴获武器，旗帜也可能更换，等等。在此情况下,Dragon同样会通过判断是否应该轮到自己主动攻击来决定是否欢呼。

在每个小时的第50分，司令部报告它拥有的生命元数量。

在每个小时的第55分，每个武士报告其拥有的武器情况。

武士到达对方司令部后就算完成任务了，从此就呆在那里无所事事。

任何一方的司令部里若是出现了2个敌人，则认为该司令部已被敌人占领。

任何一方的司令部被敌人占领，则战争结束。战争结束之后就不会发生任何事情了。

给定一个时间，要求你将从0点0分开始到此时间为止的所有事件按顺序输出。事件及其对应的输出样例如下：



1) 武士降生
输出样例： 000:00 blue lion 1 born

表示在 0点0分，编号为1的蓝魔lion武士降生
如果造出的是dragon，那么还要多输出一行，例：

000:00 blue dragon 1 born
Its morale is 23.34

表示该该dragon降生时士气是23. 34(四舍五入到小数点后两位)

如果造出的是lion，那么还要多输出一行，例:
000:00 blue lion 1 born
Its loyalty is 24

表示该lion降生时的忠诚度是24

2) lion逃跑
输出样例： 000:05 blue lion 1 ran away
表示在 0点5分，编号为1的蓝魔lion武士逃走

3) 武士前进到某一城市
输出样例： 000:10 red iceman 1 marched to city 1 with 20 elements and force 30
表示在 0点10分，红魔1号武士iceman前进到1号城市，此时他生命值为20,攻击力为30
对于iceman,输出的生命值和攻击力应该是变化后的数值

4)武士放箭
输出样例： 000:35 blue dragon 1 shot
表示在 0点35分，编号为1的蓝魔dragon武士射出一支箭。如果射出的箭杀死了敌人，则应如下输出：
000:35 blue dragon 1 shot and killed red lion 4
表示在 0点35分，编号为1的蓝魔dragon武士射出一支箭，杀死了编号为4的红魔lion。

5)武士使用bomb
输出样例： 000:38 blue dragon 1 used a bomb and killed red lion 7
表示在 0点38分，编号为1的蓝魔dragon武士用炸弹和编号为7的红魔lion同归于尽。

6) 武士主动进攻
输出样例：000:40 red iceman 1 attacked blue lion 1 in city 1 with 20 elements and force 30
表示在0点40分，1号城市中，红魔1号武士iceman 进攻蓝魔1号武士lion,在发起进攻前，红魔1号武士iceman生命值为20，攻击力为 30

7) 武士反击
输出样例：001:40 blue dragon 2 fought back against red lion 2 in city 1
表示在1点40分，1号城市中，蓝魔2号武士dragon反击红魔2号武士lion

8) 武士战死
输出样例：001:40 red lion 2 was killed in city 1
被箭射死的武士就不会有这一条输出。

9) 武士欢呼
输出样例：003:40 blue dragon 2 yelled in city 4

10) 武士获取生命元( elements )
输出样例：001:40 blue dragon 2 earned 10 elements for his headquarter

输出不包括在30分不是通过战斗获取的elements

11) 旗帜升起
输出样例：004:40 blue flag raised in city 4

12) 武士抵达敌军司令部
输出样例：001:10 red iceman 1 reached blue headquarter with 20 elements and force 30
(此时他生命值为20,攻击力为30）对于iceman,输出的生命值和攻击力应该是变化后的数值

13) 司令部被占领
输出样例：003:10 blue headquarter was taken

14)司令部报告生命元数量
000:50 100 elements in red headquarter
000:50 120 elements in blue headquarter
表示在0点50分，红方司令部有100个生命元，蓝方有120个

15)武士报告武器情况
000:55 blue wolf 2 has arrow(2),bomb,sword(23)
000:55 blue wolf 4 has no weapon
000:55 blue wolf 5 has sword(20)
表示在0点55分，蓝魔2号武士wolf有一支arrow（这支arrow还可以用2次），一个bomb，还有一支攻击力为23的sword。
蓝魔4号武士wolf没武器。
蓝魔5号武士wolf有一支攻击力为20的sword。
交代武器情况时，次序依次是：arrow,bomb,sword。如果没有某种武器，某种武器就不用提。报告时，先按从西向东的顺序所有的红武士报告，然后再从西向东所有的蓝武士报告。

输出事件时：

首先按时间顺序输出；

同一时间发生的事件，按发生地点从西向东依次输出. 武士前进的事件, 算是发生在目的地。

在一次战斗中有可能发生上面的 6 至 11 号事件。这些事件都算同时发生，其时间就是战斗开始时间。一次战斗中的这些事件，序号小的应该先输出。

两个武士同时抵达同一城市，则先输出红武士的前进事件，后输出蓝武士的。

显然，13号事件发生之前的一瞬间一定发生了12号事件。输出时，这两件事算同一时间发生，但是应先输出12号事件

虽然任何一方的司令部被占领之后，就不会有任何事情发生了。但和司令部被占领同时发生的事件，全都要输出。

输入
第一行是t,代表测试数据组数
每组样例共三行。
第一行，五个整数 M,N,R,K, T。其含义为：

每个司令部一开始都有M个生命元( 1 <= M <= 10000)
两个司令部之间一共有N个城市( 1 <= N <= 20 )
arrow的攻击力是R
lion每经过一场未能杀死敌人的战斗，忠诚度就降低K。
要求输出从0时0分开始，到时间T为止(包括T) 的所有事件。T以分钟为单位，0 <= T <= 5000

第二行：五个整数，依次是 dragon 、ninja、iceman、lion、wolf 的初始生命值。它们都大于0小于等于10000

第三行：五个整数，依次是 dragon 、ninja、iceman、lion、wolf 的攻击力。它们都大于0小于等于10000

输出
对每组数据，先输出一行：
Case n:
如对第一组数据就输出 Case1:
然后按恰当的顺序和格式输出到时间T为止发生的所有事件。每个事件都以事件发生的时间开头，时间格式是“时: 分”，“时”有三位，“分”有两位。

样例输入
1
20 1 10 10 1000
20 20 30 10 20
5 5 5 5 5
样例输出
Case 1:
000:00 blue lion 1 born
Its loyalty is 10
000:10 blue lion 1 marched to city 1 with 10 elements and force 5
000:30 blue lion 1 earned 10 elements for his headquarter
000:50 20 elements in red headquarter
000:50 20 elements in blue headquarter
000:55 blue lion 1 has no weapon
001:00 blue dragon 2 born
Its morale is 0.00
001:10 blue lion 1 reached red headquarter with 10 elements and force 5
001:10 blue dragon 2 marched to city 1 with 20 elements and force 5
001:30 blue dragon 2 earned 10 elements for his headquarter
001:50 20 elements in red headquarter
001:50 10 elements in blue headquarter
001:55 blue lion 1 has no weapon
001:55 blue dragon 2 has arrow(3)
002:10 blue dragon 2 reached red headquarter with 20 elements and force 5
002:10 red headquarter was taken
查看 提交 统计 提问
*/
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<iomanip>
#include<unordered_map>
#include<vector>
#include<fstream>

using namespace std;
class CCity;
vector <string> Weapon_Name={"sword","bomb","arrow"};
vector <string> Knight_Name={"dragon","ninja","iceman","lion","wolf"};
vector <string> Red_Name_Order={"iceman","lion","wolf","ninja","dragon"};
vector <string> Blue_Name_Order={"lion","dragon","ninja","iceman","wolf"};
vector <int> Red_Order={2,3,4,1,0};
vector <int> Blue_Order={3,0,1,2,4};
unordered_map<int,string> Weapon_Order={
    {0,"sword"},
    {1,"arrow"},
    {2,"bomb"}
};
unordered_map<int,string> Initial_Knight_Order={
    {0,"dragon"},
    {1,"ninja"},
    {2,"iceman"},
    {3,"lion"},
    {4,"wolf"}
};
unordered_map<int,string> Red_Knight_Order={
    {0,"iceman"},
    {1,"lion"},
    {2,"wolf"},
    {3,"ninja"},
    {4,"dragon"}
};
unordered_map<int,string> Blue_Knight_Order={
    {0,"lion"},
    {1,"dragon"},
    {2,"ninja"},
    {3,"iceman"},
    {4,"wolf"}
};
unordered_map<string,unordered_map<int,string>> Knight_Order={
    {"red",Red_Knight_Order},
    {"blue",Blue_Knight_Order}
};
vector <CCity> city;
vector<CCity>::iterator it_city;
vector<CCity>::reverse_iterator re_it_city;
enum Battle{
    BATTLE,
    NO_BATTLE
};
enum Flag{
    NO_FLAG,
    RED_FLAG,
    BLUE_FLAG
};
enum Battle_Result{
    NO_RESULT,
    BOTH_DIED,
    RED_WIN,
    BLUE_WIN,
    BOTH_ALIVE
};
//数据类
class CinputData{
    public:
    int M;//每个司令部一开始都有M个生命元( 1 <= M <= 10000)
    int N;//两个司令部之间一共有N个城市( 1 <= N <= 20 )
    int R;//arrow的攻击力是R
    int K;//lion每经过一场未能杀死敌人的战斗，忠诚度就降低K。
    int T;//要求输出从0时0分开始，到时间T为止(包括T) 的所有事件。T以分钟为单位，0 <= T <= 5000
    unordered_map<string,int> Knight_Initial_Hp;
    unordered_map<string,int> Knight_Initial_Atk;
    void iuputdata(){
        scanf("%d%d%d%d%d",&M,&N,&R,&K,&T);
        Knight_Initial_Hp.clear();
        Knight_Initial_Atk.clear();
        for(int i=0;i<5;i++){
            int hp;
            scanf("%d",&hp);
            Knight_Initial_Hp.insert(make_pair(Initial_Knight_Order[i],hp));
        }
        for(int i=0;i<5;i++){
            int atk;
            scanf("%d",&atk);
            Knight_Initial_Atk.insert(make_pair(Initial_Knight_Order[i],atk));
        }
        return;
    }
};
CinputData Input_Data;
class CWeapon;
class CArrow;

//时间类，调配时间
class CTime{
    public:
    int h;
    int min;
    CTime(){
        h=0;
        min=0;
    }
    void printTime();
    void addTimeH();
    void addTimeMin();
    bool NotTimeout();
    void initializeTime();
};
void CTime::printTime(){
    printf("%03d:%02d ",h,min);
}
void CTime::addTimeH(){
    h++;
    min=0;
    return;
}
void CTime::addTimeMin(){
    return;    
}
bool CTime::NotTimeout(){
    return(h*60+min<=Input_Data.T);
}
void CTime::initializeTime(){
    h=0;
    min=0;
    return;
}
CTime Time;

//武士类基类
class CKnight{
public:
    string color;  // 阵营
    string name;  // 种类
    int id;  // 编号
    int atk;  // 攻击力
    int hp;  // 生命值
    int city;  // 城市编号
    bool alive;
    unordered_map<string, CWeapon*> weapon;  // 持有的武器

    CKnight(string color_, string name_, int id_, int atk_, int hp_, int city_): 
        color(color_), 
        name(name_), 
        id(id_), 
        atk(atk_), 
        hp(hp_), 
        city(city_), 
        alive(true){
        for (string& name : Weapon_Name) {
            weapon[name] = nullptr;
        }
    }
    virtual void march();
    virtual void attack(CKnight* self,CKnight* enemy);
    virtual void counterattack(CKnight* self,CKnight* enemy);
    virtual void declareWeapon();
    virtual void loseWeapon();
    virtual void getWeapon();
};

class CLion : public CKnight {
public:
    int loyalty;  // 忠诚度
    bool battleresult;
    int temphp;
    CLion(string color_, string name_, int id_, int atk_, int hp_, int city_, int loyalty_)
        : CKnight(color_, name_, id_, atk_, hp_, city_), loyalty(loyalty_) {
            getWeapon();
        }
    void changeLoyalty();
    void escapeLion();
    void transHp(CKnight* self,CKnight* enemy);
    // virtual void attack(CKnight* self,CKnight* enemy);
    // virtual void counterattack(CKnight* self,CKnight* enemy);
    virtual void getWeapon();
};
void CLion::changeLoyalty(){
    loyalty-=Input_Data.K;
    return;
}
void CLion::escapeLion(){
    if(loyalty<=0){
        //escape
        Time.printTime();
        printf("%s lion %d ran away\n",color.c_str(),id);
    }
    return;
}
void CLion::transHp(CKnight* self,CKnight* enemy){
    if(hp<=0){
        enemy->hp+=temphp;
    }
    return;
}
void CLion::getWeapon(){
    return;
}

//城市类
class CCity{
    public:
    int id;//城市编号
    CKnight* red;
    CKnight* blue;
    Flag flag;
    Battle_Result battleResult;
    Battle_Result lastBattleResult;
    Battle battle;
    string firstAttackColor;
    bool ArrowKillKnight;
    int hp;
    CCity(int id_):id(id_){
        red=nullptr;
        blue=nullptr;
        flag=NO_FLAG;
        battleResult=NO_RESULT;
        lastBattleResult=NO_RESULT;
        battle=NO_BATTLE;
        hp=0;
    }
    ~CCity(){
        if(red!=NULL){
            delete red;
            red=NULL;
        }
        if(blue!=NULL){
            delete blue;
            blue=NULL;
        }
    }
    CKnight* decideFirstAttack();
};
CKnight* CCity::decideFirstAttack(){
    if(flag==RED_FLAG||(flag==NO_FLAG&&id%2==1)){
        return red;
    }
    if(flag==BLUE_FLAG||(flag==NO_FLAG&&id%2==0)){
        return blue;
    }
    return nullptr;
}

//武器类基类及其派生类
class CWeapon{
    public:
    string name;//武器名称
    int id;//武器编号
    CWeapon(int id_):id(id_){
        name=Weapon_Name[id];
    }
    virtual bool decideRemainWeapon();//在使用武器前判断武器能不能使用，减少了丢弃武器的操作
    virtual void useWeapon(CKnight* self, CKnight* enemy);//攻击逻辑，武士调用武器的函数实现具体的攻击
};
bool CWeapon::decideRemainWeapon(){
    return false; 
}
void CWeapon::useWeapon(CKnight* self, CKnight* enemy){
    return;
}

class CSword:public CWeapon{
    public:
    int atk;
    CSword(int id_,int atk_):atk(atk_/5),CWeapon(id_){}
    virtual void useWeapon(CKnight* self, CKnight* enemy);
    virtual void abraseWeapon();//剑的磨损
    virtual bool decideRemainWeapon();
};
bool CSword::decideRemainWeapon(){
    return atk;
}
void CSword::useWeapon(CKnight* self, CKnight* enemy){
    enemy->hp -= atk;
    abraseWeapon();
    return;
}
void CSword::abraseWeapon(){
    atk=atk*4/5;
    return;
}

class CArrow:public CWeapon{
    public:
    int atk;
    int useCount;
    CArrow(int id_):atk(Input_Data.R),useCount(3),CWeapon(id_){}
    virtual bool decideRemainWeapon();
    virtual void useWeapon(CKnight* self, CKnight* enemy); 
    virtual void abraseWeapon(); 
};
bool CArrow::decideRemainWeapon(){
    return useCount;
}
void CArrow::useWeapon(CKnight* self, CKnight* enemy){
    if(enemy->name=="lion"){
        dynamic_cast <CLion*> (enemy)-> temphp=dynamic_cast <CLion*> (enemy)->hp;
    }
    enemy->hp-=atk;
    abraseWeapon();
    Time.printTime();
    if(enemy->hp > 0){
        printf("%s %s %d shot\n",self->color.c_str(),self->name.c_str(),self->id);
    }
    else{
        printf("%s %s %d shot and killed %s %s %d\n",self->color.c_str(),self->name.c_str(),self->id,enemy->color.c_str(),enemy->name.c_str(),enemy->id);
    }
    return;
}
void CArrow::abraseWeapon(){
    useCount--;
    return;
}

class CBomb:public CWeapon{
    public:
    bool useable;
    CBomb(int id_):CWeapon(id_){
        useable=true;
    }
    virtual bool decideRemainWeapon();
    bool decideUseWeapon(CKnight* self,CKnight* enemy,CKnight* firstAttack);
    virtual void useWeapon(CKnight* self, CKnight* enemy);
};
bool CBomb::decideUseWeapon(CKnight* self,CKnight* enemy,CKnight* firstAttack){
    if(self->color==firstAttack->color){
        if(enemy->name=="ninja"){
            return false;
        }
        if(self->weapon["sword"]){
            if(self->atk+dynamic_cast<CSword*> (self->weapon["sword"])->atk < enemy->hp ){
                if(enemy->weapon["sword"]){
                    if(self->hp <= enemy -> atk/2 + dynamic_cast<CSword*>(enemy->weapon["sword"])->atk){
                        return true;
                    }
                }
                else{
                    if(self->hp<=enemy->atk/2){
                        return true;
                    }
                }
            }
        }
        else{
            if(self->atk < enemy->hp){
                if(enemy->weapon["sword"]){
                    if(self->hp <= enemy -> atk/2 + dynamic_cast<CSword*>(enemy->weapon["sword"])->atk){
                        return true;
                    }
                }
                else{
                    if(self->hp<=enemy->atk/2){
                        return true;
                    }
                }
            }
        }
    }
    else{
        if(enemy->weapon["sword"]){
            // cout<<dynamic_cast<CSword*> (enemy->weapon["sword"])->atk<<endl;
            if(self->hp <= enemy->atk + dynamic_cast<CSword*> (enemy->weapon["sword"])->atk){
                return true;
            }
        }
        else{
            if(self->hp<=enemy->atk){
                return true;
            }
        }
    }
    return false;
}
bool CBomb::decideRemainWeapon(){
    return useable;
}
void CBomb::useWeapon(CKnight* self, CKnight* enemy){
    self->hp=0;
    enemy->hp=0;
    for (auto& pair : self-> weapon) {
        delete pair.second;
        pair.second = nullptr; // 可选，将指针置为空指针
    }
    self->weapon.clear();
    for (auto& pair : enemy-> weapon) {
        delete pair.second;
        pair.second = nullptr; // 可选，将指针置为空指针
    }
    enemy->weapon.clear();
    Time.printTime();
    printf("%s %s %d used a bomb and killed %s %s %d\n",self->color.c_str(),self->name.c_str(),self->id,enemy->color.c_str(),enemy->name.c_str(),enemy->id);
    delete self;
    delete enemy;
    return;
}



//武士类派生类
void CKnight::attack(CKnight* self,CKnight* enemy){
    if(self->weapon["sword"]){
        self->weapon["sword"]->useWeapon(self,enemy);
    }
    enemy->hp-=self->atk;
    Time.printTime();
    printf("%s %s %d attacked %s %s %d in city %d with %d elements and force %d\n",
        self->color.c_str(),self->name.c_str(),self->id,enemy->color.c_str(),enemy->name.c_str(),enemy->id,self->city,self->hp,self->atk);
    if(enemy->hp>0){
        enemy->counterattack(enemy,self);
    }
    return;
}
void CKnight::counterattack(CKnight* self,CKnight* enemy){
    if(self->name=="ninja") return;
    if(self->weapon["sword"]){
        self->weapon["sword"]->useWeapon(self,enemy);
    }
    enemy->hp-=self->atk/2;
    Time.printTime();
    printf("%s %s %d fought back against %s %s %d in city %d\n",
        self->color.c_str(),self->name.c_str(),self->id,enemy->color.c_str(),enemy->name.c_str(),enemy->id,self->city);
    return;
}
void CKnight::march(){
    Time.printTime();
    printf("%s %s %d marched to city %d with %d elements and force %d\n",color.c_str(),name.c_str(),id,city,hp,atk);
    return;
}
void CKnight::getWeapon(){
    return;
}

class CDragon : public CKnight {
public:
    double morale;  // 士气
    CDragon(string color_, string name_, int id_, int atk_, int hp_, int city_, double morale_): 
        CKnight(color_, name_, id_, atk_, hp_, city_), 
        morale(morale_),
        battleresult(false) {}
    void changeMorale();
    void yell();
    bool battleresult;
    virtual void getWeapon();
    // virtual void attack(CKnight* self,CKnight* enemy);
    // virtual void counterattack(CKnight* self,CKnight* enemy);
};
void CDragon::changeMorale(){
    if(battleresult){
        morale+=0.2;
    }
    else{
        morale-=0.2;
    }
    return;
}
void CDragon::yell(){
    if(hp>0&&morale>=0.8){
        //yell
        Time.printTime();
        printf("%s %s %d yelled in city %d\n",color.c_str(),name.c_str(),id,city);
    }
    return;
}
void CDragon::getWeapon(){
    switch(id%3){
        case 0:{
            weapon["sword"]=new CSword(0,atk);
            break;
        }
        case 1:{
            weapon["bomb"]=new CBomb(1);
            break;
        }
        case 2:{
            weapon["arrow"]=new CArrow(2);
            break;
        }
    }
    return;
}

class CNinja : public CKnight {
public:
    CNinja(string color_, string name_, int id_, int atk_, int hp_, int city_)
        : CKnight(color_, name_, id_, atk_, hp_, city_) {}
    // virtual void attack(CKnight* self,CKnight* enemy);
    // virtual void counterattack(CKnight* self,CKnight* enemy);
    virtual void getWeapon();
};
void CNinja::getWeapon(){
    switch(id%3){
        case 0:{
            weapon["sword"]=new CSword(0,atk);
            break;
        }
        case 1:{
            weapon["bomb"]=new CBomb(1);
            break;
        }
        case 2:{
            weapon["arrow"]=new CArrow(2);
            break;
        }
    }
    switch((id+1)%3){
        case 0:{
            weapon["sword"]=new CSword(0,atk);
            break;
        }
        case 1:{
            weapon["bomb"]=new CBomb(1);
            break;
        }
        case 2:{
            weapon["arrow"]=new CArrow(2);
            break;
        }
    }
    return;
}

class CIceman : public CKnight {
public:
    int step;
    CIceman(string color_, string name_, int id_, int atk_, int hp_, int city_)
        : step(0),CKnight(color_, name_, id_, atk_, hp_, city_) {}
    void changeHp();
    virtual void march();
    // virtual void attack(CKnight* self,CKnight* enemy);
    // virtual void counterattack(CKnight* self,CKnight* enemy);
    virtual void getWeapon();
};
void CIceman::changeHp(){
    step++;
    if(step&&step%2==0) {
        if(hp>9){
            hp-=9;
        }
        else{
            hp=1;
        }
        atk+=20;
    }
    return;
}
void CIceman::march(){
    changeHp();
    Time.printTime();
    printf("%s %s %d marched to city %d with %d elements and force %d\n",color.c_str(),name.c_str(),id,city,hp,atk);
    return;
}
void CIceman::getWeapon(){
    switch(id%3){
        case 0:{
            weapon["sword"]=new CSword(0,atk);
            break;
        }
        case 1:{
            weapon["bomb"]=new CBomb(1);
            break;
        }
        case 2:{
            weapon["arrow"]=new CArrow(2);
            break;
        }
    }
    return;
}

class CWolf : public CKnight {
public:
    bool battleresult;
    CWolf(string color_, string name_, int id_, int atk_, int hp_, int city_)
        : CKnight(color_, name_, id_, atk_, hp_, city_) {}
    void caputureWeapon(CKnight* self,CKnight* enemy);
    // virtual void attack(CKnight* self,CKnight* enemy);
    // virtual void counterattack(CKnight* self,CKnight* enemy); 
    //void getWeapon(CKnight* self,CKnight* enemy);
};
void CWolf::caputureWeapon(CKnight* self,CKnight* enemy){
    for(string& name : Weapon_Name){
        if (weapon[name] == nullptr) {
            weapon[name] = enemy->weapon[name];
            enemy->weapon[name] = nullptr;
        }
    }
    return;
}

//阵营类
class CCamp{
    public:
    string color;//阵营
    int currentHp;//当前生命元
    int initialHp;//初始生命元
    int countKnight;//武士计数
    int KnightOrderNum;//武士顺序
    vector <CKnight*> enemy;
    int enemynum;
    int HpbeforeBattle;
    unordered_map<int,string> KnightOrder;
    CCamp(string color_,int& initialHp_):color(color_),initialHp(initialHp_),currentHp(initialHp_){
        countKnight=0;
        KnightOrderNum=0;
        KnightOrder=Knight_Order[color];
    }
    void initializeCamp();
    void declareHp();
    void makeKnight();
    void awardKnight();
    
};
void CCamp::initializeCamp(){
    initialHp=Input_Data.M;
    currentHp=Input_Data.M;
    countKnight=0;
    KnightOrderNum=0;
    enemynum=0;
    enemy.clear();
    return;
}
void CCamp::makeKnight(){
    if(currentHp>=Input_Data.Knight_Initial_Hp[KnightOrder[KnightOrderNum%5]]){
        countKnight++;
        currentHp-=Input_Data.Knight_Initial_Hp[KnightOrder[KnightOrderNum%5]];
        it_city=city.begin()+(color=="red" ? 0 : Input_Data.N+1);
        CKnight* temp=nullptr;
        string color_=color;
        string name_=KnightOrder[KnightOrderNum%5];
        int id_=countKnight;
        int atk_=Input_Data.Knight_Initial_Atk[KnightOrder[KnightOrderNum%5]];
        int hp_=Input_Data.Knight_Initial_Hp[KnightOrder[KnightOrderNum%5]];
        int city_=color=="red" ? 0 : Input_Data.N+1;
        if(KnightOrder[KnightOrderNum%5]=="dragon"){
            double morale_=(currentHp*1.0)/(Input_Data.Knight_Initial_Hp[KnightOrder[KnightOrderNum%5]]*1.0);
            temp=new CDragon(color_,name_,id_,atk_,hp_,city_,morale_);
        }
        if(KnightOrder[KnightOrderNum%5]=="ninja"){
            temp=new CNinja(color_,name_,id_,atk_,hp_,city_);
        }
        if(KnightOrder[KnightOrderNum%5]=="iceman"){
            temp=new CIceman(color_,name_,id_,atk_,hp_,city_);
        }
        if(KnightOrder[KnightOrderNum%5]=="lion"){
            int loyalty_=currentHp;
            temp=new CLion(color_,name_,id_,atk_,hp_,city_,loyalty_);
        }
        if(KnightOrder[KnightOrderNum%5]=="wolf"){
            temp=new CWolf(color_,name_,id_,atk_,hp_,city_);
        }

        if(temp){
            if(color=="red"){
                it_city->red=temp;
                it_city->red->getWeapon();
            }
            else{
                it_city->blue=temp;
                it_city->blue->getWeapon();
            }
            Time.printTime();
            printf("%s %s %d born\n",color.c_str(),KnightOrder[KnightOrderNum%5].c_str(),countKnight);
            if(temp->name=="dragon"){
                printf("Its morale is %.2lf\n",dynamic_cast<CDragon*> (temp)->morale);
            }
            if(temp->name=="lion"){
                printf("Its loyalty is %d\n",dynamic_cast<CLion*>(temp)->loyalty);
            }
        }
        KnightOrderNum++;
    }
    return;
}
void CCamp::awardKnight(){
    return;
}
void CCamp::declareHp(){
    Time.printTime();
    printf("%d elements in %s headquarter\n",currentHp,color.c_str());
    return;
}
CCamp CampRed("red",Input_Data.M);
CCamp CampBlue("blue",Input_Data.M);

//事件类
class CEvent{
    public:
    bool gameover;
    void prepareBattle();
    void Time00_makeKnight();
    void Time05_escapeLion();
    void Time10_march();
    void Time20_creatHp();
    void Time30_getHp();
    void Time35_releaseArrow();
    void Time38_useBomb();
    void Time40_battle();
    void sweepBattleField(vector<CCity>::iterator temp_it_city);
    void awardHp();
    void Time40_yellDragon(vector<CCity>::iterator temp_it_city);
    void Time40_getHp(vector<CCity>::iterator temp_it_city);
    void Time40_raiseFlag(vector<CCity>::iterator temp_it_city);
    void Time40_dealBattleResult();
    void judgeArriveCamp(vector<CCity>::iterator te_it_city);
    void Time50_declareHp();
    void Time55_declareWeapon();
};
void CEvent::prepareBattle(){
    gameover=false;
    Time.initializeTime();
    CampRed.initializeCamp();
    CampBlue.initializeCamp();
    city.clear();
    for(int i=0;i<=Input_Data.N+1;++i){
        city.push_back(i);
    }
    return;
}
void CEvent::Time00_makeKnight(){
    Time.min=0;
    CampRed.makeKnight();
    CampBlue.makeKnight();
    return;
}
void CEvent::Time05_escapeLion(){
    Time.min=5;
    for(it_city=city.begin();it_city!=city.end();++it_city){
        if(it_city->red && it_city->red->name=="lion"){
            if(dynamic_cast<CLion*> (it_city->red) -> loyalty<=0){
                dynamic_cast<CLion*> (it_city->red)->escapeLion();
                delete it_city->red;
                it_city->red=nullptr;
            }
        }
        if(it_city->blue && it_city->blue->name=="lion"){
            if(dynamic_cast<CLion*> (it_city->blue) -> loyalty<=0){
                dynamic_cast<CLion*> (it_city->blue)->escapeLion();
                delete it_city->blue;
                it_city->blue=nullptr;
            }
        }
    }
    return;
}
void CEvent::Time10_march(){
    Time.min=10;
    for(re_it_city=city.rbegin()+1;re_it_city!=city.rend();++re_it_city){
        if((re_it_city)->red!=nullptr){
            (re_it_city-1)->red=re_it_city->red;
            (re_it_city-1)->red->city++;
            re_it_city->red=nullptr;
        }
    }
    for(it_city=city.begin()+1;it_city!=city.end();++it_city){
        if(it_city->blue!=nullptr){
            (it_city-1)->blue=it_city->blue;
            (it_city-1)->blue->city--;
            it_city->blue=nullptr;
        }
    }
    for(it_city=city.begin();it_city!=city.end();++it_city){
        if(it_city->red!=nullptr){
            if(it_city==city.end()-1){
                judgeArriveCamp(it_city);
            }
            else it_city->red->march();
        }
        if(it_city->blue!=nullptr){
            if(it_city==city.begin()){
                judgeArriveCamp(it_city);
            }
            else it_city->blue->march();
        }
    }
    return;
}
void CEvent::Time20_creatHp(){
    Time.min=20;
    for(it_city=city.begin();it_city!=city.end();++it_city){
        it_city->hp+=10;
    }
    return;
}
void CEvent::Time30_getHp(){
    Time.min=30;
    for(it_city=city.begin()+1;it_city!=city.end()-1;++it_city){
        if(it_city->red&&!it_city->blue){
            Time.printTime();
            printf("%s %s %d earned %d elements for his headquarter\n",
                it_city->red->color.c_str(),it_city->red->name.c_str(),it_city->red->id,it_city->hp);
            CampRed.currentHp+=it_city->hp;
            it_city->hp=0;
        }
        if(it_city->blue&&!it_city->red){
            Time.printTime();
            printf("%s %s %d earned %d elements for his headquarter\n",
                it_city->blue->color.c_str(),it_city->blue->name.c_str(),it_city->blue->id,it_city->hp);
            CampBlue.currentHp+=it_city->hp;
            it_city->hp=0;
        }
    }
    return;
}
void CEvent::Time35_releaseArrow(){
    Time.min=35;
    for(it_city=city.begin()+1;it_city!=city.end()-1;++it_city){
        if(it_city->red&&it_city->red->weapon["arrow"]&&(it_city+1)->blue){
            it_city->red->weapon["arrow"]->useWeapon(it_city->red,(it_city+1)->blue);
            if((it_city+1)->blue->hp<=0){
                (it_city+1)->ArrowKillKnight=true;
            }
        }
        if((it_city)->blue&&(it_city)->blue->weapon["arrow"]&&(it_city-1)->red){
            it_city->blue->weapon["arrow"]->useWeapon(it_city->blue,(it_city-1)->red);
            if((it_city-1)->red->hp<=0){
                (it_city-1)->ArrowKillKnight=true;
            }
        }
    }
    for(it_city=city.begin()+1;it_city!=city.end()-1;++it_city){
        if(it_city->blue&&it_city->blue->hp<=0&&it_city->red&&it_city->red->hp<=0){
            delete it_city->blue;
            delete it_city->red;
            it_city->blue=nullptr;
            it_city->red=nullptr;
            it_city->ArrowKillKnight=false;
        }
    }
    return;
}
void CEvent::Time38_useBomb(){
    Time.min=38;
    for(it_city=city.begin();it_city!=city.end();++it_city){
        if(it_city->ArrowKillKnight){
            continue;
        }
        if(it_city->blue&&it_city->red){
            if(it_city->red->weapon["bomb"]){
                // CKnight* tempfirst=it_city->decideFirstAttack();
                // CBomb* tempbomb=dynamic_cast<CBomb*>(it_city->red->weapon["bomb"]);
                // bool temp;
                // temp=tempbomb->decideUseWeapon(it_city->red,it_city->blue,tempfirst);
                // cout<<dynamic_cast<CBomb*>(it_city->red->weapon["bomb"])->decideUseWeapon(it_city->red,it_city->blue,it_city->decideFirstAttack())<<endl;
                if(dynamic_cast<CBomb*>(it_city->red->weapon["bomb"])->decideUseWeapon(it_city->red,it_city->blue,it_city->decideFirstAttack())){
                    dynamic_cast<CBomb*> (it_city->red->weapon["bomb"])->useWeapon(it_city->red,it_city->blue);
                    it_city->red=nullptr;
                    it_city->blue=nullptr;
                    continue;
                }
            }
            if(it_city->blue->weapon["bomb"]){
                if(dynamic_cast<CBomb*>(it_city->blue->weapon["bomb"])->decideUseWeapon(it_city->blue,it_city->red,it_city->decideFirstAttack())){
                    dynamic_cast<CBomb*> (it_city->blue->weapon["bomb"])->useWeapon(it_city->blue,it_city->red);
                    it_city->red=nullptr;
                    it_city->blue=nullptr;
                }
            }
        }
    }
    return;
}
void CEvent::Time40_battle(){
    Time.min=40;
    CampRed.HpbeforeBattle=CampRed.currentHp;
    CampBlue.HpbeforeBattle=CampBlue.currentHp;
    for(it_city=city.begin();it_city!=city.end();++it_city){
        if(it_city->blue&&it_city->red){
            if(it_city->blue->name=="lion"){
                if(it_city->blue->hp>0){
                    dynamic_cast<CLion*>(it_city->blue)->temphp=dynamic_cast<CLion*>(it_city->blue)->hp;
                }
                else {
                    dynamic_cast<CLion*>(it_city->blue)->temphp=0;
                }
            }
            if(it_city->red->name=="lion"){
                if(it_city->red->hp>0){
                    dynamic_cast<CLion*>(it_city->red)->temphp=dynamic_cast<CLion*>(it_city->red)->hp;
                }
                else{
                    dynamic_cast<CLion*>(it_city->red)->temphp=0;
                }
            }
            it_city->battle=BATTLE;
            it_city->firstAttackColor=it_city->decideFirstAttack()->color;
            if(it_city->red->hp>0&&it_city->blue->hp>0){
                it_city->ArrowKillKnight=false;
                if(it_city->red->color==it_city->decideFirstAttack()->color){
                    it_city->red->attack(it_city->red,it_city->blue);
                }
                else{
                    it_city->blue->attack(it_city->blue,it_city->red);
                }
            }
            else{
                it_city->ArrowKillKnight=true;
            }
            sweepBattleField(it_city);
            Time40_yellDragon(it_city);
            Time40_getHp(it_city);
            Time40_raiseFlag(it_city);
        }
        else {
            it_city->battle=NO_BATTLE;
            it_city->firstAttackColor="NON";
        }
    }
    return;
}
void CEvent::sweepBattleField(vector<CCity>::iterator temp_it_city){
    if (temp_it_city->battle == BATTLE){
        if (temp_it_city->red && temp_it_city->red->hp > 0 && temp_it_city->blue && temp_it_city->blue->hp <= 0){
            temp_it_city->battleResult = RED_WIN;
            if (temp_it_city->red->name == "wolf"){
                dynamic_cast<CWolf *>(temp_it_city->red)->caputureWeapon(temp_it_city->red, temp_it_city->blue);
            }
            if (temp_it_city->blue->name == "lion"){
                dynamic_cast<CLion *>(temp_it_city->blue)->transHp(temp_it_city->blue, temp_it_city->red);
            }
        }
        if (temp_it_city->blue && temp_it_city->blue->hp > 0 && temp_it_city->red && temp_it_city->red->hp <= 0){
            temp_it_city->battleResult = BLUE_WIN;
            if (temp_it_city->blue->name == "wolf"){
                dynamic_cast<CWolf *>(temp_it_city->blue)->caputureWeapon(temp_it_city->blue, temp_it_city->red);
            }
            if (temp_it_city->red->name == "lion"){
                dynamic_cast<CLion *>(temp_it_city->red)->transHp(temp_it_city->red, temp_it_city->blue);
            }
        }
        if (temp_it_city->red && temp_it_city->red->hp > 0 && temp_it_city->blue && temp_it_city->blue->hp > 0){
            temp_it_city->battleResult = BOTH_ALIVE;
            if(temp_it_city->red->name == "lion"){
                dynamic_cast<CLion *>(temp_it_city->red)->changeLoyalty();
            }
            if(temp_it_city->blue->name == "lion"){
                dynamic_cast<CLion *>(temp_it_city->blue)->changeLoyalty();
            }
        }
        if (temp_it_city->red && temp_it_city->red->hp <= 0 && temp_it_city->blue && temp_it_city->blue->hp <= 0){
            temp_it_city->battleResult = BOTH_DIED;
        }
        if (temp_it_city->red && temp_it_city->red->hp <= 0){
            if(!temp_it_city->ArrowKillKnight){
                Time.printTime();
                printf("%s %s %d was killed in city %d\n", 
                    temp_it_city->red->color.c_str(), temp_it_city->red->name.c_str(), temp_it_city->red->id, temp_it_city->red->city);
            }
            for (auto &pair : temp_it_city->red->weapon)
            {
                delete pair.second;
                pair.second = nullptr; // 可选，将指针置为空指针
            }
            delete temp_it_city->red;
            temp_it_city->red = nullptr;
        }
        if (temp_it_city->blue && temp_it_city->blue->hp <= 0){
            if(!temp_it_city->ArrowKillKnight){
                Time.printTime();
                printf("%s %s %d was killed in city %d\n", 
                    temp_it_city->blue->color.c_str(), temp_it_city->blue->name.c_str(), temp_it_city->blue->id, temp_it_city->blue->city);
            }
            for (auto &pair : temp_it_city->blue->weapon)
            {
                delete pair.second;
                pair.second = nullptr; // 可选，将指针置为空指针
            }
            delete temp_it_city->blue;
            temp_it_city->blue = nullptr;
        }
    }
    return;
}
void CEvent::awardHp(){
    for(it_city=city.begin();it_city!=city.end();++it_city){
        if(it_city->battle==BATTLE&&it_city->battleResult==RED_WIN){
            if(CampRed.HpbeforeBattle>=8){
                it_city->red->hp+=8;
                CampRed.HpbeforeBattle-=8;
                CampRed.currentHp-=8;
            }
            else break;
        }
    }
    for(re_it_city=city.rbegin();re_it_city!=city.rend();++re_it_city){
        if(re_it_city->battle==BATTLE&&re_it_city->battleResult==BLUE_WIN){
            if(CampBlue.HpbeforeBattle>=8){
                re_it_city->blue->hp+=8;
                CampBlue.HpbeforeBattle-=8;
                CampBlue.currentHp-=8;
            }
            else break;
        }
    }
    return;
}
void CEvent::Time40_yellDragon(vector<CCity>::iterator temp_it_city){
    if(temp_it_city->battle==BATTLE){
        if(temp_it_city->red&&temp_it_city->red->name=="dragon"){
            if(temp_it_city->battleResult==RED_WIN){
                dynamic_cast<CDragon*> (temp_it_city->red)->battleresult=true;
            }
            else{
                dynamic_cast<CDragon*> (temp_it_city->red)->battleresult=false;
            }
            dynamic_cast<CDragon*> (temp_it_city->red)->changeMorale();
            if(temp_it_city->firstAttackColor=="red"){
                dynamic_cast<CDragon*> (temp_it_city->red)->yell();
            }
            dynamic_cast<CDragon*> (temp_it_city->red)->battleresult=false;
        }
        if(temp_it_city->blue&&temp_it_city->blue->name=="dragon"){
            if(temp_it_city->battleResult==BLUE_WIN){
                dynamic_cast<CDragon*> (temp_it_city->blue)->battleresult=true;
            }
            else{
                dynamic_cast<CDragon*> (temp_it_city->blue)->battleresult=false;
            }
            dynamic_cast<CDragon*> (temp_it_city->blue)->changeMorale();
            if(temp_it_city->firstAttackColor=="blue"){
                dynamic_cast<CDragon*> (temp_it_city->blue)->yell();
            }
            dynamic_cast<CDragon*> (temp_it_city->blue)->battleresult=false;
        }
    } 
    return;
}
void CEvent::Time40_getHp(vector<CCity>::iterator temp_it_city){
    if(temp_it_city->battle==BATTLE){
        if(temp_it_city->battleResult==RED_WIN){
            Time.printTime();
            printf("%s %s %d earned %d elements for his headquarter\n",
            temp_it_city->red->color.c_str(),temp_it_city->red->name.c_str(),temp_it_city->red->id,temp_it_city->hp);
            CampRed.currentHp+=temp_it_city->hp;
            temp_it_city->hp=0;
        }
        if(temp_it_city->battleResult==BLUE_WIN){
            Time.printTime();
            printf("%s %s %d earned %d elements for his headquarter\n",
                temp_it_city->blue->color.c_str(),temp_it_city->blue->name.c_str(),temp_it_city->blue->id,temp_it_city->hp);
            CampBlue.currentHp+=temp_it_city->hp;
            temp_it_city->hp=0;
       }
    }
    return;
}
void CEvent::Time40_raiseFlag(vector<CCity>::iterator temp_it_city){
    if(temp_it_city->battle==BATTLE){
        if((temp_it_city->battleResult==temp_it_city->lastBattleResult)){
            if(temp_it_city->battleResult==RED_WIN&&temp_it_city->flag==NO_FLAG){
                temp_it_city->flag=RED_FLAG;
                Time.printTime();
                printf("red flag raised in city %d\n",temp_it_city->id);
            }
            if(temp_it_city->battleResult==RED_WIN&&temp_it_city->flag==BLUE_FLAG){
                temp_it_city->flag=RED_FLAG;
                Time.printTime();
                printf("red flag raised in city %d\n",temp_it_city->id);
            }
            if(temp_it_city->battleResult==BLUE_WIN&&temp_it_city->flag==NO_FLAG){
                temp_it_city->flag=BLUE_FLAG;
                Time.printTime();
                printf("blue flag raised in city %d\n",temp_it_city->id);
            }
            if(temp_it_city->battleResult==BLUE_WIN&&temp_it_city->flag==RED_FLAG){
                temp_it_city->flag=BLUE_FLAG;
                Time.printTime();
                printf("blue flag raised in city %d\n",temp_it_city->id);
            }
        }
    }
    return;
}
void CEvent::Time40_dealBattleResult(){
    for(it_city=city.begin();it_city!=city.end();++it_city){
        if(it_city->red&&it_city->red->hp<=0){
            delete it_city->red;
            it_city->red=nullptr;
        }
        if(it_city->blue&&it_city->blue->hp<=0){
            delete it_city->blue;
            it_city->blue=nullptr;
        }
        it_city->ArrowKillKnight=false;
        if(it_city->battle==BATTLE){
            it_city->battle=NO_BATTLE;
            it_city->firstAttackColor="";
            it_city->lastBattleResult=it_city->battleResult;
            it_city->battleResult=NO_RESULT;
        }
    }
    return;
}
void CEvent::judgeArriveCamp(vector<CCity>::iterator te_it_city){
    if(te_it_city==city.begin())
    {
    if(city.begin()->blue){
        if(city.begin()->blue->name=="iceman"){
            dynamic_cast<CIceman*>(city.begin()->blue)->changeHp();
        }
        Time.printTime();
        printf("%s %s %d reached red headquarter with %d elements and force %d\n",
            city.begin()->blue->color.c_str(),city.begin()->blue->name.c_str(),city.begin()->blue->id,city.begin()->blue->hp,city.begin()->blue->atk);
        CampRed.enemynum++;
        CampRed.enemy.push_back(city.begin()->blue);
        city.begin()->blue=nullptr;
    }
    }
    else{
    if(city.rbegin()->red){
        if(city.rbegin()->red->name=="iceman"){
            dynamic_cast<CIceman*>(city.rbegin()->red)->changeHp();
        }
        Time.printTime();
        printf("%s %s %d reached blue headquarter with %d elements and force %d\n",
            city.rbegin()->red->color.c_str(),city.rbegin()->red->name.c_str(),city.rbegin()->red->id,city.rbegin()->red->hp,city.rbegin()->red->atk);
        CampBlue.enemynum++;
        CampBlue.enemy.push_back(city.rbegin()->red);
        city.rbegin()->red=nullptr;
    }
    }
    if(te_it_city==city.begin()){
    if(CampRed.enemynum>=2){
        Time.printTime();
        printf("red headquarter was taken\n");
        gameover=true;
    }
    }
    else{
    if(CampBlue.enemynum>=2){
        Time.printTime();
        printf("blue headquarter was taken\n");
        gameover=true;
    }
    }
}
void CEvent::Time50_declareHp(){
    Time.min=50;
    CampRed.declareHp();
    CampBlue.declareHp();
    return;
}
void CEvent::Time55_declareWeapon(){
    Time.min=55;
    for (it_city=city.begin();it_city!=city.end();++it_city) {
        if(it_city->red!=nullptr){
            it_city->red->declareWeapon();
        }
    }
    if(CampBlue.enemynum){
        CampBlue.enemy[0]->declareWeapon();
    }
    if(CampRed.enemynum){
        CampRed.enemy[0]->declareWeapon();
    }
    for(it_city=city.begin();it_city!=city.end();++it_city){
        if(it_city->blue!=nullptr){
            it_city->blue->declareWeapon();
        }
    }
    return;
}
CEvent Event;

void CKnight::declareWeapon(){
    loseWeapon();
    Time.printTime();
    if(weapon["arrow"]||weapon["bomb"]||weapon["sword"]){
        bool arrowflag=false;
        bool bombflag=false;
        if(weapon["arrow"]){
            printf("%s %s %d has arrow(%d)",color.c_str(),name.c_str(),id,dynamic_cast<CArrow*>(weapon["arrow"])->useCount);
            arrowflag=true;
        }
        if(weapon["bomb"]){
            if(arrowflag){
                printf(",bomb");
            }
            else{
                printf("%s %s %d has bomb",color.c_str(),name.c_str(),id);
            }
            bombflag=true;
        }
        if(weapon["sword"]){
            if(arrowflag||bombflag){
                printf(",sword(%d)",dynamic_cast<CSword*>(weapon["sword"])->atk);
            }
            else{
                printf("%s %s %d has sword(%d)",color.c_str(),name.c_str(),id,dynamic_cast<CSword*>(weapon["sword"])->atk);
            }
        }
        printf("\n");
    }
    else{
        printf("%s %s %d has no weapon\n",color.c_str(),name.c_str(),id);
    }
    return;
}

void CKnight::loseWeapon(){
    for(string& name : Weapon_Name){
        if (weapon[name] != nullptr &&!weapon[name]->decideRemainWeapon()) {
            delete weapon[name];
            weapon[name] = nullptr;
        }
    }
}

int main(){
    //SetConsoleOutputCP(65001);
    // FILE* pfin;
    // FILE* pfout;
    // pfin=fopen("Warcraftin.txt","r");
    // pfout=fopen("Warcraftout.txt","w");
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        printf("Case %d:\n",i);
        Input_Data.iuputdata();
        Event.prepareBattle();
        while(Time.NotTimeout()){
            Time.min=0;
            if(!Time.NotTimeout())break;
            Event.Time00_makeKnight();
            Time.min=5;
            if(!Time.NotTimeout())break;
            Event.Time05_escapeLion();
            Time.min=10;
            if(!Time.NotTimeout())break;
            Event.Time10_march();
            if(Event.gameover) break;
            Time.min=20;
            if(!Time.NotTimeout())break;
            Event.Time20_creatHp();
            Time.min=30;
            if(!Time.NotTimeout())break;
            Event.Time30_getHp();
            Time.min=35;
            if(!Time.NotTimeout())break;
            Event.Time35_releaseArrow();
            Time.min=38;
            if(!Time.NotTimeout())break;
            Event.Time38_useBomb();
            Time.min=40;
            if(!Time.NotTimeout())break;
            Event.Time40_battle();
            Event.awardHp();
            Event.Time40_dealBattleResult();
            Time.min=50;
            if(!Time.NotTimeout())break;
            Event.Time50_declareHp();
            Time.min=55;
            if(!Time.NotTimeout())break;
            Event.Time55_declareWeapon();
            Time.addTimeH();
        }
    }
    // fclose(pfin);
    // fclose(pfout);
    return 0;
}
