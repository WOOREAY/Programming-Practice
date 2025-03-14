/*
E:魔兽世界三(开战)
查看提交统计提问
总时间限制: 2000ms 内存限制: 65536kB
描述
魔兽世界的西面是红魔军的司令部，东面是蓝魔军的司令部。两个司令部之间是依次排列的若干城市，城市从西向东依次编号为1,2,3 .... N ( N <= 20)。红魔军的司令部算作编号为0的城市，蓝魔军的司令部算作编号为N+1的城市。司令部有生命元，用于制造武士。


两军的司令部都会制造武士。武士一共有dragon 、ninja、iceman、lion、wolf 五种。每种武士都有编号、生命值、攻击力这三种属性。


双方的武士编号都是从1开始计算。红方制造出来的第n 个武士，编号就是n。同样，蓝方制造出来的第n 个武士，编号也是n。


武士在刚降生的时候有一个初始的生命值，生命值在战斗中会发生变化，如果生命值减少到0（生命值变为负数时应当做变为0处理），则武士死亡（消失）。

武士可以拥有武器。武器有三种，sword, bomb,和arrow，编号分别为0,1,2。

sword的攻击力是使用者当前攻击力的20%(去尾取整)。

bomb的攻击力是使用者当前攻击力的40%(去尾取整)，但是也会导致使用者受到攻击，对使用者的攻击力是对敌人取整后的攻击力的1/2(去尾取整)。Bomb一旦使用就没了。

arrow的攻击力是使用者当前攻击力的30%(去尾取整)。一个arrow用两次就没了。



武士降生后就朝对方司令部走，在经过的城市如果遇到敌人（同一时刻每个城市最多只可能有1个蓝武士和一个红武士），就会发生战斗。战斗的规则是：

在奇数编号城市，红武士先发起攻击

在偶数编号城市，蓝武士先发起攻击

战斗开始前，双方先对自己的武器排好使用顺序，然后再一件一件地按顺序使用。编号小的武器，排在前面。若有多支arrow，用过的排在前面。排好序后，攻击者按此排序依次对敌人一件一件地使用武器。如果一种武器有多件，那就都要用上。每使用一件武器，被攻击者生命值要减去武器攻击力。如果任何一方生命值减为0或小于0即为死去。有一方死去，则战斗结束。

双方轮流使用武器，甲用过一件，就轮到乙用。某一方把自己所有的武器都用过一轮后，就从头开始再用一轮。如果某一方没有武器了，那就挨打直到死去或敌人武器用完。武器排序只在战斗前进行，战斗中不会重新排序。

如果双方武器都用完且都还活着，则战斗以平局结束。如果双方都死了，也算平局。

有可能由于武士自身攻击力太低，而导致武器攻击力为0。攻击力为0的武器也要使用。如果战斗中双方的生命值和武器的状态都不再发生变化，则战斗结束，算平局。

战斗的胜方获得对方手里的武器。武士手里武器总数不超过10件。缴获武器时，按照武器种类编号从小到大缴获。如果有多件arrow，优先缴获没用过的。

如果战斗开始前双方都没有武器，则战斗视为平局。如果先攻击方没有武器，则由后攻击方攻击。

不同的武士有不同的特点。

编号为n的dragon降生时即获得编号为n%3 的武器。dragon在战斗结束后，如果还没有战死，就会欢呼。


编号为n的ninjia降生时即获得编号为n%3 和(n+1)%3的武器。ninja 使用bomb不会让自己受伤。


编号为n的iceman降生时即获得编号为n%3 的武器。iceman每前进一步，生命值减少10%(减少的量要去尾取整)。


编号为n的lion降生时即获得编号为n%3 的武器。lion 有“忠诚度”这个属性，其初始值等于它降生之后其司令部剩余生命元的数目。每前进一步忠诚度就降低K。忠诚度降至0或0以下，则该lion逃离战场,永远消失。但是已经到达敌人司令部的lion不会逃跑。lion在己方司令部可能逃跑。


wolf降生时没有武器，但是在战斗开始前会抢到敌人编号最小的那种武器。如果敌人有多件这样的武器，则全部抢来。Wolf手里武器也不能超过10件。如果敌人arrow太多没法都抢来，那就先抢没用过的。如果敌人也是wolf，则不抢武器。


以下是不同时间会发生的不同事件：


在每个整点，即每个小时的第0分， 双方的司令部中各有一个武士降生。


红方司令部按照iceman、lion、wolf、ninja、dragon 的顺序制造武士。


蓝方司令部按照lion、dragon、ninja、iceman、wolf 的顺序制造武士。


制造武士需要生命元。


制造一个初始生命值为m 的武士，司令部中的生命元就要减少m 个。


如果司令部中的生命元不足以制造某本该造的武士，那就从此停止制造武士。


在每个小时的第5分，该逃跑的lion就在这一时刻逃跑了。


在每个小时的第10分：所有的武士朝敌人司令部方向前进一步。即从己方司令部走到相邻城市，或从一个城市走到下一个城市。或从和敌军司令部相邻的城市到达敌军司令部。


在每个小时的第35分：在有wolf及其敌人的城市，wolf要抢夺对方的武器。


在每个小时的第40分：在有两个武士的城市，会发生战斗。


在每个小时的第50分，司令部报告它拥有的生命元数量。


在每个小时的第55分，每个武士报告其拥有的武器情况。


武士到达对方司令部后就算完成任务了，从此就呆在那里无所事事。


任何一方的司令部里若是出现了敌人，则认为该司令部已被敌人占领。

任何一方的司令部被敌人占领，则战争结束。战争结束之后就不会发生任何事情了。


给定一个时间，要求你将从0点0分开始到此时间为止的所有事件按顺序输出。事件及其对应的输出样例如下：


1) 武士降生

输出样例：000:00 blue dragon 1 born

表示在0点0分，编号为1的蓝魔dragon武士降生


如果造出的是lion，那么还要多输出一行，例:

000:00 blue lion 1 born

Its loyalty is 24

表示该lion降生时的忠诚度是24


2) lion逃跑

输出样例：000:05 blue lion 1 ran away

表示在0点5分，编号为1的蓝魔lion武士逃走


3) 武士前进到某一城市


输出样例：



000:10 red iceman 1 marched to city 1 with 20 elements and force 30

表示在0点10分，红魔1号武士iceman前进到1号城市，此时他生命值为20,攻击力为30

对于iceman,输出的生命值应该是变化后的数值


4) wolf抢敌人的武器

000:35 blue wolf 2 took 3 bomb from red dragon 2 in city 4

表示在0点35分，4号城市中，红魔1号武士wolf 抢走蓝魔2号武士dragon 3个bomb。为简单起见，武器不写复数形式


5) 报告战斗情况

战斗只有3种可能的输出结果：


000:40 red iceman 1 killed blue lion 12 in city 2 remaining 20 elements

表示在0点40分，1号城市中，红魔1号武士iceman 杀死蓝魔12号武士lion后，剩下生命值20


000:40 both red iceman 1 and blue lion 12 died in city 2

注意，把红武士写前面

000:40 both red iceman 1 and blue lion 12 were alive in city 2

注意，把红武士写前面


6) 武士欢呼

输出样例：003:40 blue dragon 2 yelled in city 4


7) 武士抵达敌军司令部

输出样例：001:10 red iceman 1 reached blue headquarter with 20 elements and force 30

（此时他生命值为20,攻击力为30）对于iceman,输出的生命值和攻击力应该是变化后的数值


8) 司令部被占领

输出样例：003:10 blue headquarter was taken


9)司令部报告生命元数量

000:50 100 elements in red headquarter

000:50 120 elements in blue headquarter

表示在0点50分，红方司令部有100个生命元，蓝方有120个


10)武士报告情况

000:55 blue wolf 2 has 2 sword 3 bomb 0 arrow and 7 elements

为简单起见，武器都不写复数形式。elements一律写复数，哪怕只有1个


交代武器情况时，次序依次是：sword,bomb, arrow。


输出事件时：


首先按时间顺序输出；

同一时间发生的事件，按发生地点从西向东依次输出. 武士前进的事件, 算是发生在目的地。

在一次战斗中有可能发生上面的 5 至 6 号事件。这些事件都算同时发生，其时间就是战斗开始时间。一次战斗中的这些事件，序号小的应该先输出。

两个武士同时抵达同一城市，则先输出红武士的前进事件，后输出蓝武士的。

对于同一城市，同一时间发生的事情，先输出红方的，后输出蓝方的。

显然，8号事件发生之前的一瞬间一定发生了7号事件。输出时，这两件事算同一时间发生，但是应先输出7号事件

虽然任何一方的司令部被占领之后，就不会有任何事情发生了。但和司令部被占领同时发生的事件，全都要输出。



输入
第一行是t,代表测试数据组数

每组样例共三行。

第一行，4个整数 M,N,K, T。其含义为：
每个司令部一开始都有M个生命元( 1 <= M <= 100000)
两个司令部之间一共有N个城市( 1 <= N <= 20 )
lion每前进一步，忠诚度就降低K。(0<=K<=100)
要求输出从0时0分开始，到时间T为止(包括T) 的所有事件。T以分钟为单位，0 <= T <= 6000

第二行：五个整数，依次是 dragon 、ninja、iceman、lion、wolf 的初始生命值。它们都大于0小于等于200

第三行：五个整数，依次是 dragon 、ninja、iceman、lion、wolf 的攻击力。它们都大于0小于等于200
输出
对每组数据，先输出一行：

Case n:

如对第一组数据就输出 Case 1:

然后按恰当的顺序和格式输出到时间T为止发生的所有事件。每个事件都以事件发生的时间开头，时间格式是“时: 分”，“时”有三位，“分”有两位。
样例输入
1
20 1 10 400
20 20 30 10 20
5 5 5 5 5
样例输出
Case 1:
000:00 blue lion 1 born
Its loyalty is 10
000:10 blue lion 1 marched to city 1 with 10 elements and force 5
000:50 20 elements in red headquarter
000:50 10 elements in blue headquarter
000:55 blue lion 1 has 0 sword 1 bomb 0 arrow and 10 elements
001:05 blue lion 1 ran away
001:50 20 elements in red headquarter
001:50 10 elements in blue headquarter
002:50 20 elements in red headquarter
002:50 10 elements in blue headquarter
003:50 20 elements in red headquarter
003:50 10 elements in blue headquarter
004:50 20 elements in red headquarter
004:50 10 elements in blue headquarter
005:50 20 elements in red headquarter
005:50 10 elements in blue headquarter
提示
请注意浮点数精度误差问题。OJ上的编译器编译出来的可执行程序，在这方面和你电脑上执行的程序很可能会不一致。5 * 0.3 的结果，有的机器上可能是 15.00000001，去尾取整得到15,有的机器上可能是14.9999999，去尾取整后就变成14。因此,本题不要写 5 * 0.3，要写 5 * 3 / 10。
来源
Guo Wei
查看 提交 统计 提问
*/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<iomanip>
#include<unordered_map>
using namespace std;
const int inf = 0x3f3f3f3f;

unordered_map<const char*, int>life, atk;
class cweapon {
public:
	const char* name;
	int id, usetime;
public:
	cweapon(int _id):id(_id),usetime(0) {
		name = new char[7];
		if (_id == 0)name = "sword", usetime = inf;
		if (_id == 1)name = "bomb", usetime = 1;
		if (_id == 2)name = "arrow", usetime = 2;
	}
	virtual ~cweapon() {
		//delete name;
	}
	virtual int get_atk(int user_atk) = 0;
	void modify_usetime() {
		usetime--;
	}
};
class csword :public cweapon {
public:
	csword():cweapon(0){}
	virtual ~csword(){}
	int get_atk(int user_atk) {return user_atk * 2 / 10;}
	void modify_usetime(){}
};
class cbomb :public cweapon {
public:
	cbomb():cweapon(1){}
	virtual ~cbomb() {}
	int get_atk(int user_atk) {return user_atk * 4 / 10;}
	void modify_usetime() {usetime--;}
};
class carrow :public cweapon {
public:
	carrow():cweapon(2){}
	virtual ~carrow() {}
	int get_atk(int user_atk) {return user_atk * 3 / 10;}
	void modify_usetime() { usetime--; }
};
class  cwarrior{
public:
	int id,life, atk, city;
	const char* name;
	cweapon* weapon[11];
	int weapon_count;
	int weapon_pos;
	int warrior_count;
	cwarrior(int _id,int _life,int _atk,const char* _name,int _warrior_count):
		id(_id),life(_life),atk(_atk),weapon_count(0),name(_name),warrior_count(_warrior_count) {}
	virtual ~cwarrior() {
		//delete[] weapon;
	}
	void new_weapon(int _id) {
		++weapon_count;
		if (_id == 0)weapon[weapon_count] = new csword;
		if (_id == 1)weapon[weapon_count] = new cbomb;
		if (_id == 2)weapon[weapon_count] = new carrow;
	}
	virtual void lifelose() = 0;
	virtual void loyaltylose(int _loyaltylose) = 0;
	void hurt(int damage) {
		life -= damage;
	}
	virtual void back_hurt(int damage) = 0;
	virtual int get_loyalty() = 0;
};
class cdragon :public cwarrior {
public:
	cdragon(int _id,int _life,int _atk, int _warrior_count) :
		cwarrior(_id, _life, _atk,"dragon", _warrior_count) {
		new_weapon(id % 3);
	}
	virtual ~cdragon(){}
	void lifelose(){}
	void loyaltylose(int _loyaltylose){}
	void back_hurt(int damage) {
		life -= damage;
	}
	int get_loyalty() { return 0; }
};
class cninja :public cwarrior {
public:
	cninja(int _id,int _life,int _atk,  int _warrior_count) :
		cwarrior(_id, _life, _atk, "ninja", _warrior_count) {
		new_weapon(id % 3); new_weapon((id + 1) % 3);
	}
	virtual ~cninja() {}
	void lifelose() {}
	void loyaltylose(int _loyaltylose){}
	void back_hurt(int damage) {}
	int get_loyalty() { return 0; }
};
class ciceman :public cwarrior {
public:
	ciceman(int _id, int _life, int _atk,  int _warrior_count) :
		cwarrior(_id, _life, _atk, "iceman", _warrior_count) {
		new_weapon(id % 3);
	}
	virtual ~ciceman() {}
	void lifelose() {
		life = life - life / 10;
	}
	void loyaltylose(int _loyaltylose){}
	void back_hurt(int damage) {
		life -= damage;
	}
	int get_loyalty() { return 0; }
};
class clion :public cwarrior {
public:
	int loyalty;
	clion(int _id, int _life, int _atk,int _rest,  int _warrior_count) :
		cwarrior(_id, _life, _atk, "lion", _warrior_count) {
		new_weapon(id % 3); loyalty = _rest;
	}
	virtual ~clion() {}
	void lifelose() {}
	void loyaltylose(int _loyaltylose) {
		loyalty -= _loyaltylose;
	}
	void back_hurt(int damage) {
		life -= damage;
	}
	int get_loyalty() { return loyalty; }
};
class cwolf :public cwarrior {
public:
	cwolf(int _id, int _life, int _atk,int _warrior_count) :
		cwarrior(_id, _life, _atk,"wolf",_warrior_count) {}
	virtual ~cwolf() {}
	void lifelose() {}
	void loyaltylose(int _loyaltylose){}
	void back_hurt(int damage) {
		life -= damage;
	}
	int get_loyalty() { return 0; }
};

unordered_map<const char*, cwarrior* > City[22];
class cheadquarter {
public:
	int flag;
	int hp;
	cwarrior* warrior[22];
	int warrior_count;
	int warrior_id;
	unordered_map<int, const char*> new_baby;
	int new_pos;
	cheadquarter(int _hp,char c){
		hp = _hp;
		warrior_count = 0; new_pos = 0; warrior_id = 0; flag = 0;
		if (c == 'R') {
			new_baby.insert({ 0,"iceman" });
			new_baby.insert({ 1,"lion" });
			new_baby.insert({ 2,"wolf" });
			new_baby.insert({ 3,"ninja" });
			new_baby.insert({ 4,"dragon" });
		}
		else {
			new_baby.insert({ 0,"lion" });
			new_baby.insert({ 1,"dragon" });
			new_baby.insert({ 2,"ninja" });
			new_baby.insert({ 3,"iceman" });
			new_baby.insert({ 4,"wolf" });
		}
	}
	~cheadquarter() {
		//delete[] warrior;
	}
	bool new_warrior(const char* _headquarter,int city_count) {
		const char* name = new_baby[new_pos]; 
		int _life = life[name];
		if (_life > hp)return false;
		++warrior_id;
		hp -= _life;
		++warrior_count;
		if (name == "dragon") {
			warrior[warrior_count] = new cdragon(warrior_id, life["dragon"], atk["dragon"], warrior_count);
		}
		else if (name == "ninja") {
			warrior[warrior_count] = new cninja(warrior_id, life["ninja"], atk["ninja"],  warrior_count);
		}
		else if (name == "iceman") {
			warrior[warrior_count] = new ciceman(warrior_id, life["iceman"], atk["iceman"],  warrior_count);
		}
		else if (name == "lion") {
			warrior[warrior_count] = new clion(warrior_id, life["lion"], atk["lion"], hp, warrior_count);
		}
		else if (name == "wolf") {
			warrior[warrior_count] = new cwolf(warrior_id, life["wolf"], atk["wolf"],  warrior_count);
		}
		++new_pos;
		new_pos %= 5;
		if (_headquarter == "red")City[0]["red"] = warrior[warrior_count];
		else City[city_count+1]["blue"] = warrior[warrior_count];
		return true;
	}
};
void print_2num(int t) {
	if (t < 10)cout << "0";
	cout << t;
}
void print_3num(int Hour) {
	if (Hour < 10)cout << "00";
	else if (Hour < 100)cout << "0";
	cout << Hour;
}
void print_time(int Hour, int t) {
	print_3num(Hour); cout << ":"; print_2num(t); cout << " ";
}
void print_lion_born(int loyalty) {
	cout << "Its loyalty is " << loyalty << endl;
}
void print_headquarter_newwarrior(const char* name, cheadquarter& headquarter,int Hour) {
	print_time(Hour, 0);
	cout << name << " ";
	int pos = headquarter.warrior_count;
	cout << headquarter.warrior[pos]->name << " " << headquarter.warrior[pos]->id << " born" << endl;
	if (headquarter.warrior[pos]->name == "lion") {
		print_lion_born(headquarter.warrior[pos]->get_loyalty());
	}
}
void print_lion_escaped(const char* name, cwarrior* warrior, int Hour) {
	print_time(Hour, 5);
	cout << name << " " << "lion " << warrior->id << " ran away" << endl;
}
void print_who_is_reached(const char* winner_name,const char* loser_name, cwarrior* warrior, int Hour) {
	print_time(Hour, 10);
	cout << winner_name << " " << warrior->name << " " << warrior->id <<
		" reached "<<loser_name<<" headquarter with " << warrior->life << " elements and force " << warrior->atk << endl;
}
void print_who_is_taken(const char* name, int Hour) {
	print_time(Hour, 10);
	cout << name << " headquarter was taken" << endl;
}
void print_marched(const char* name, cwarrior* warrior, int city_number, int Hour) {
	print_time(Hour, 10);
	cout << name << " " << warrior->name << " " << warrior->id << " marched to city " << city_number
		<< " with " << warrior->life << " elements and force " << warrior->atk<<endl;
}
void print_headquarter_hp(cheadquarter& headquarter,const char* name, int Hour) {
	print_time(Hour, 50);
	cout << headquarter.hp << " elements in " << name << " headquarter" << endl;
}
void print_warrior_weapon(const char* name,cwarrior* warrior, int Hour) {
	print_time(Hour, 55);
	cout << name << " " << warrior->name << " " << warrior->id << " has ";
	int weapon_count[3] = { 0 };
	for (int i = 1; i <= warrior->weapon_count; ++i) {
		weapon_count[warrior->weapon[i]->id]++;
	}
	cout << weapon_count[0] << " sword ";
	cout << weapon_count[1] << " bomb ";
	cout << weapon_count[2] << " arrow ";
	cout << "and " << warrior->life << " elements";
	cout << endl;
}
void print_grab_weapon(const char* graber, const char* be_grabeder,
	cwarrior* a, cwarrior* b, const char* weapon_name, int taken_count, int city_number, int Hour) {
	print_time(Hour, 35);
	cout << graber << " " << a->name << " " << a->id << " took " << taken_count << " "
		<< weapon_name << " from " << be_grabeder << " " << b->name << " " << b->id 
		<< " in city " << city_number << endl;
}
void print_win_lose(const char* winner_name, cwarrior* winner,
	const char* loser_name, cwarrior* loser, int city_number,int Hour) {
	print_time(Hour, 40);
	cout << winner_name << " " << winner->name << " " << winner->id << " killed " <<
		loser_name << " " << loser->name << " " << loser->id << " in city " <<
		city_number << " remaining " << winner->life << " elements" << endl;
}
void print_die_together(cwarrior* a, cwarrior* b,int city_number,int Hour) {
	print_time(Hour, 40);
	cout << "both red " << a->name << " " << a->id
		<< " and blue " << b->name << " " << b->id << " died in city " << city_number << endl;
}
void print_alive_together(cwarrior* a, cwarrior* b, int city_number, int Hour) {
	print_time(Hour, 40);
	cout << "both red " << a->name << " " << a->id
		<< " and blue " << b->name << " " << b->id << " were alive in city " << city_number << endl;
}
void print_yelled(const char* name, cwarrior* warrior, int city_number, int Hour) {
	print_time(Hour, 40);
	cout << name << " " << warrior->name << " " << warrior->id << " yelled in city " << city_number << endl;
}
void prepare(int N) {
	int _life, _atk;
	cin >> _life; life.insert({ "dragon", _life });
	cin >> _life; life.insert({ "ninja",_life });
	cin >> _life; life.insert({ "iceman", _life });
	cin >> _life; life.insert({ "lion",_life });
	cin >> _life; life.insert({ "wolf",_life });

	cin >> _atk; atk.insert({ "dragon", _atk });
	cin >> _atk; atk.insert({ "ninja",_atk });
	cin >> _atk; atk.insert({ "iceman", _atk });
	cin >> _atk; atk.insert({ "lion",_atk });
	cin >> _atk; atk.insert({ "wolf",_atk });


	for (int i = 0; i <= N + 1; ++i) {
		City[i]["red"] = NULL;
		City[i]["blue"] = NULL;
	}
}

void Delete_warrior(cwarrior* poorguy, cheadquarter& headquarter) {
	int warrior_count = poorguy->warrior_count;
	for (int i = warrior_count; i < headquarter.warrior_count; ++i) {
		headquarter.warrior[i] = headquarter.warrior[i + 1];
		headquarter.warrior[i]->warrior_count = i;
	}
	headquarter.warrior[headquarter.warrior_count] = NULL;
	headquarter.warrior_count--;
}
bool cweapon_cmp_attack(cweapon* a, cweapon* b) {
	if (a->id != b->id)return a->id < b->id;
	if (a->id == 2)return a->usetime < b->usetime;
	return true;
}
bool cweapon_cmp_grab(cweapon* a, cweapon* b) {
	if (a->id != b->id)return a->id < b->id;
	if (a->id == 2)return a->usetime > b->usetime;
	return true;
}
void sort_weapon_grab(cweapon** weapon, int size,bool(*cmp)(cweapon*, cweapon*)) {
	for (int i = 1; i < size; ++i) {
		for (int j = 1; j <=size-i; ++j) {
			if (cmp(weapon[j], weapon[j+1])) {
				swap(weapon[j], weapon[j+1]);
			}
		}
	}
}
void sort_weapon_battle(cweapon** weapon, int size, bool(*cmp)(cweapon*, cweapon*)) {
	for (int i = 1; i < size; ++i) {
		for (int j = 1; j <=size-i; ++j) {
			if (!cmp(weapon[j], weapon[j+1])) {
				swap(weapon[j], weapon[j+1]);
			}
		}
	}
}
void weapon_steal(const char* graber,const char* be_grabeder,cwarrior* a, cwarrior* b, int city_number,int Hour) {
	sort_weapon_grab(b->weapon,b->weapon_count, cweapon_cmp_grab);
	if (!b->weapon_count)return;
	int bpos = b->weapon_count+1;
	int weapon_id = b->weapon[bpos - 1]->id;
	const char* weapon_name = b->weapon[bpos - 1]->name;
	int taken_count = 0;
	for (int i = a->weapon_count + 1; i <= 10; ++i) {
		--bpos;
		if (!bpos)break;
		if (b->weapon[bpos]->id != weapon_id)break;
		++a->weapon_count; ++taken_count;
		a->weapon[i] = b->weapon[bpos];
		b->weapon[bpos] = NULL;
		--b->weapon_count;
	}
	print_grab_weapon(graber, be_grabeder, a, b, weapon_name, taken_count, city_number,Hour);
}
bool check_before(cwarrior* fighter, cwarrior* be_fighteder) {
	if (!fighter->weapon_count && !be_fighteder->weapon_count)return false;
	bool all_sword_fighter = true;
	int fighter_weapon_count = 0;
	int be_fighteder_weapon_count = 0;
	for (int i = 1; i <= fighter->weapon_count; ++i) {
		if (!fighter->weapon[i]->usetime)continue;
		++fighter_weapon_count;
		if (fighter->weapon[i]->name != "sword") {
			all_sword_fighter = false; break;
		}
	}
	bool all_sword_be_fighteder = true;
	for (int i = 1; i <= be_fighteder->weapon_count; ++i) {
		if (!be_fighteder->weapon[i]->usetime)continue;
		++be_fighteder_weapon_count;
		if (be_fighteder->weapon[i]->name != "sword") {
			all_sword_be_fighteder = false; break;
		}
	}
	if (!fighter_weapon_count && !be_fighteder_weapon_count)
	{
		return false;
	}
	if (all_sword_fighter && all_sword_be_fighteder) {
		bool no_atk = true;
		if (fighter->weapon_count) {
			if (fighter->weapon[1]->get_atk(fighter->atk)) {
				no_atk = false;
			}
		}
		if (be_fighteder->weapon_count) {
			if (be_fighteder->weapon[1]->get_atk(be_fighteder->atk)) {
				no_atk = false;
			}
		}
		if (no_atk)return false;
	}
	return true;
}
bool choose_weapon(cwarrior* fighter,cweapon* &choice) {
	if (!fighter->weapon_count)return false;
	choice = fighter->weapon[fighter->weapon_pos];
	for (int i = 1; i <= fighter->weapon_count;++i) {
		if (choice->usetime)return true;
		++fighter->weapon_pos;
		if (fighter->weapon_pos == fighter->weapon_count+1)
			fighter->weapon_pos = 1;
		choice = fighter->weapon[fighter->weapon_pos];
	}
	return false;
}
void reorganize_weapon(cwarrior* warrior) {
	cweapon* temp[12];
	int now_size = 0;
	for (int i = 1; i <= warrior->weapon_count; ++i) {
		if (warrior->weapon[i]->usetime)temp[++now_size] = warrior->weapon[i];
		//else delete warrior->weapon[i];
	}
	warrior->weapon_count = now_size;
	for (int i = 1; i <= now_size; ++i)
		warrior->weapon[i] = temp[i];
}
void pick_up_weapon(cwarrior* a, cwarrior* b) {
	sort_weapon_grab(b->weapon, b->weapon_count, cweapon_cmp_grab);
	if (!b->weapon_count)return;
	int bpos = b->weapon_count + 1;
	const char* weapon_name = b->weapon[bpos - 1]->name;
	int taken_count = 0;
	for (int i = a->weapon_count + 1; i <= 10; ++i) {
		--bpos;
		if (!bpos)break;
		if (!b->weapon[bpos]->usetime)continue;
		
		++a->weapon_count; ++taken_count;
		a->weapon[i] = b->weapon[bpos];
		b->weapon[bpos] = NULL;
		--b->weapon_count;
	}
}
void battle(cheadquarter& R, cheadquarter& B, cwarrior* red_warrior, cwarrior* blue_warrior, int city_number, int Hour) {
	cwarrior* fighter;
	cwarrior* be_fighteder;
	cwarrior* winner=red_warrior;
	cwarrior* loser=blue_warrior;
	int win_lose = 0;//0都活，1分出胜负，2都死
	if (city_number & 1) {
		fighter = red_warrior;
		be_fighteder = blue_warrior;
	}
	else {
		fighter = blue_warrior;
		be_fighteder = red_warrior;
	}
	sort_weapon_battle(fighter->weapon, fighter->weapon_count, cweapon_cmp_attack);
	sort_weapon_battle(be_fighteder->weapon, be_fighteder->weapon_count, cweapon_cmp_attack);
	fighter->weapon_pos = 1; be_fighteder->weapon_pos = 1;
	while (check_before(fighter, be_fighteder)) {
		cweapon* weapon_choice=fighter->weapon[1];
		if (!choose_weapon(fighter, weapon_choice)) {
			swap(fighter, be_fighteder);
			continue;
		}
		++fighter->weapon_pos;
		if (fighter->weapon_pos == fighter->weapon_count + 1)
			fighter->weapon_pos = 1;
		int atk = weapon_choice->get_atk(fighter->atk);
		be_fighteder->hurt(atk);
		if (weapon_choice->name == "bomb") {
			fighter->back_hurt(atk / 2);
	  	}
		weapon_choice->modify_usetime();

		if (fighter->life <= 0 && be_fighteder->life > 0) {
			winner = be_fighteder; loser = fighter;
			win_lose = 1;
			break;
		}
		if (fighter->life <= 0 && be_fighteder->life <= 0) {
			win_lose = 2;
			break;
		}
		if (fighter->life > 0 && be_fighteder->life <= 0) {
			winner = fighter; loser = be_fighteder;
			win_lose = 1;
			break;
		}
		swap(fighter, be_fighteder);

	}
	reorganize_weapon(winner); reorganize_weapon(loser);
	if (win_lose==1) {
		if (loser == red_warrior)
			print_win_lose("blue", winner, "red", loser, city_number,Hour);
		else print_win_lose("red", winner, "blue", loser, city_number,Hour);
		pick_up_weapon(winner, loser);
		if (loser == red_warrior)
		{
			Delete_warrior(loser, R);
			City[city_number]["red"] = NULL;
			if (winner->name == "dragon") {
				print_yelled("blue", blue_warrior, city_number, Hour);
			}
		}
		else 
		{
			Delete_warrior(loser, B);
			City[city_number]["blue"] = NULL;
			if (winner->name == "dragon") {
				print_yelled("red", red_warrior, city_number, Hour);
			}
		}
	}
	else {//未分出胜负
		if (win_lose == 2) {//同归于尽
			print_die_together(red_warrior, blue_warrior,city_number,Hour);
			City[city_number]["red"] = NULL;
			City[city_number]["blue"] = NULL;
		}
		else {
			print_alive_together(red_warrior,blue_warrior,city_number,Hour);
			if (red_warrior->name == "dragon") {
				print_yelled("red", red_warrior, city_number, Hour);
			}
			if (blue_warrior->name == "dragon") {
				print_yelled("blue", blue_warrior, city_number, Hour);
			}
		}
	}
}
bool work(cheadquarter& R,cheadquarter& B,int _life,int city_count,int K,int T,int Hour) {
//00:士兵生产
	if (!R.flag) {
		if (!R.new_warrior("red", city_count))R.flag = 1;
		else 
			print_headquarter_newwarrior("red", R,Hour);
	}
	if (!B.flag) {
		if (!B.new_warrior("blue", city_count))B.flag = 1;
		else print_headquarter_newwarrior("blue", B, Hour);
	}
//05：lion逃跑
	if (T < 5)return true;
	for (int i = 0; i <= city_count + 1; ++i) {
		if (City[i]["red"]!=NULL&&City[i]["red"]->name == "lion") {
			if (City[i]["red"]->get_loyalty() <= 0) {
				print_lion_escaped("red", City[i]["red"], Hour);
				Delete_warrior(City[i]["red"],R);
				City[i]["red"] = NULL;
			}
		}
		if (City[i]["blue"] != NULL && City[i]["blue"]->name == "lion") {
			if (City[i]["blue"]->get_loyalty() <= 0) {
				print_lion_escaped("blue", City[i]["blue"], Hour);
				Delete_warrior(City[i]["blue"],B);
				City[i]["blue"] = NULL;
			}
		}
	}
//10:士兵前进,iceman生命值丢失，lion忠诚度丢失
	if (T < 10)return true;
	for (int i = city_count + 1; i >= 1; --i) {
		City[i]["red"] = City[i - 1]["red"];
		if (City[i]["red"] != NULL) {
			City[i]["red"]->lifelose();
			City[i]["red"]->loyaltylose(K);
		}
	}
	City[0]["red"] = NULL;
	for (int i = 0; i <= city_count; ++i) {
		City[i]["blue"] = City[i + 1]["blue"];
		if (City[i]["blue"] != NULL) {
			City[i]["blue"]->lifelose();
			City[i]["blue"]->loyaltylose(K);
		}
	}
	City[city_count + 1]["blue"] = NULL;
	int flag = 0;
	if (City[0]["blue"] != NULL) {
		print_who_is_reached("blue","red", City[0]["blue"], Hour);
		print_who_is_taken("red", Hour);
		flag = 1;
	}
	for (int i = 1; i <= city_count; ++i) {
		if (City[i]["red"] != NULL) {
			print_marched("red", City[i]["red"], i, Hour);
		}
		if (City[i]["blue"] != NULL) {
			print_marched("blue", City[i]["blue"], i, Hour);
		}
	}
	if (City[city_count + 1]["red"] != NULL) {
		print_who_is_reached("red","blue", City[city_count+1]["red"], Hour);
		print_who_is_taken("blue", Hour);
		flag = 1;
	}
	if (flag)return false;
//35:wolf抢武器
	if (T < 35)return true;
	for (int i = 1; i <= city_count; ++i) {
		if (City[i]["red"] == NULL || City[i]["blue"] == NULL)continue;
		if (City[i]["red"]->name == "wolf" && City[i]["blue"]->name != "wolf") {
			weapon_steal("red","blue",City[i]["red"], City[i]["blue"], i,Hour);
			//输出在weapon_steal中进行
		}
		if (City[i]["blue"]->name == "wolf" && City[i]["red"]->name != "wolf") {
			weapon_steal("blue","red",City[i]["blue"], City[i]["red"], i,Hour);
			//输出在weapon_steal中进行
		}
	}
//40:战斗
	if (T < 40)return true;
	for (int i = 1; i <= city_count; ++i) {
		if (City[i]["red"] != NULL && City[i]["blue"] != NULL) {
			battle(R,B,City[i]["red"],City[i]["blue"],i,Hour);
		}
	}
//50:玩家报告生命元状态
	if (T < 50)return true;
	print_headquarter_hp(R, "red",Hour); print_headquarter_hp(B,"blue", Hour);
//55:士兵报告武器状态
	if (T < 55)return true;
	for (int i = 1; i <= city_count; ++i) {
		if (City[i]["red"] != NULL)print_warrior_weapon("red",City[i]["red"], Hour);
		if (City[i]["blue"] != NULL)print_warrior_weapon("blue",City[i]["blue"], Hour);
	}
	return true;
}
signed main() {
	int t;
	cin >> t;
	
	for(int Case=1;Case<=t;++Case){
		life.clear(); atk.clear();
		cout << "Case " << Case << ":" << endl;
		int M, N, K, T;
		cin >> M >> N >> K >> T;
		for (int i = 0; i <= N + 1; ++i)City[i].clear();
		cheadquarter R(M,'R'), B(M,'B');
		prepare(N);
		int Hour = 0;
		while (T>=0) {
			int _hour = T / 60;
			if (_hour)
			{
				if (!work(R, B, M, N, K, 60,Hour))break;
			}
			else if (!work(R, B, M, N, K, T,Hour))break;
			++Hour; T -= 60;
		}
	}
	return 0;
}
