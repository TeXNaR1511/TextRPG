#include "Enemy.h"
#include <iostream>
using namespace std;
Monster::Monster()
{
	MonsterHealthPoints = 0;
	MonsterDamage = 0;
	MonsterExperience = 0;
	MonsterGold = 0;
	DamageFromSword = 0;
	DamageFromStaff = 0;
	DamageFromBook = 0;
}
int Monster::getRandomNumber()
{
	static const double fraction = 1 / (static_cast<double>(RAND_MAX) + 1);
	return static_cast<int>(rand() * fraction * 100 + 1);
}
int Monster::GetMonster(int a)
{
	if (a >= 1 && a <= 19)
	{
		return 1;
	}
	else if (a >= 20 && a <= 36)
	{
		return 2;
	}
	else if (a >= 37 && a <= 51)
	{
		return 3;
	}
	else if (a >= 52 && a <= 64)
	{
		return 4;
	}
	else if (a >= 65 && a <= 75)
	{
		return 5;
	}
	else if (a >= 76 && a <= 84)
	{
		return 6;
	}
	else if (a >= 85 && a <= 91)
	{
		return 7;
	}
	else if (a >= 92 && a <= 96)
	{
		return 8;
	}
	else if (a >= 97 && a <= 99)
	{
		return 9;
	}
	else
	{
		return 10;
	}
}
void Monster::MonsterCoutCharacteristics()
{
	cout << MonsterHealthPoints;
}
bool Monster::MonsterDeath()
{
	if (MonsterHealthPoints <= 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
int Monster::GetMonsterDamage()
{
	return MonsterDamage;
}
void Monster::PlayerAttack(int a)
{
	MonsterHealthPoints = MonsterHealthPoints - a;
}
int Monster::GetMonsterExperience()
{
	return MonsterExperience;
}
int Monster::GetMonsterGold()
{
	return MonsterGold;
}
int Monster::ReturnDamageFromSword()
{
	return DamageFromSword;
}
int Monster::ReturnDamageFromStaff()
{
	return DamageFromStaff;
}
int Monster::ReturnDamageFromBook()
{
	return DamageFromBook;
}
Spider::Spider()
{
	MonsterHealthPoints = 150;
	MonsterDamage = 5;
	MonsterExperience = 15;
	MonsterGold = 5;
	DamageFromSword = 1;
	DamageFromStaff = 1;
	DamageFromBook = 0;
}
Wolfman::Wolfman()
{
	MonsterHealthPoints = 900;
	MonsterDamage = 30;
	MonsterExperience = 60;
	MonsterGold = 30;
	DamageFromSword = 1;
	DamageFromStaff = 1;
	DamageFromBook = 0;
}
Devil::Devil()
{
	MonsterHealthPoints = 450;
	MonsterDamage = 15;
	MonsterExperience = 30;
	MonsterGold = 15;
	DamageFromSword = 1;
	DamageFromStaff = 1;
	DamageFromBook = 0;
}
Demon::Demon()
{
	MonsterHealthPoints = 1500;
	MonsterDamage = 50;
	MonsterExperience = 100;
	MonsterGold = 50;
	DamageFromSword = 1;
	DamageFromStaff = 1;
	DamageFromBook = 0;
}
Zombie::Zombie()
{
	MonsterHealthPoints = 750;
	MonsterDamage = 25;
	MonsterExperience = 50;
	MonsterGold = 25;
	DamageFromSword = 0;
	DamageFromStaff = 1;
	DamageFromBook = 1;
}
Ghost::Ghost()
{
	MonsterHealthPoints = 300;
	MonsterDamage = 10;
	MonsterExperience = 20;
	MonsterGold = 10;
	DamageFromSword = 0;
	DamageFromStaff = 1;
	DamageFromBook = 1;
}
Vampire::Vampire()
{
	MonsterHealthPoints = 1350;
	MonsterDamage = 45;
	MonsterExperience = 90;
	MonsterGold = 45;
	DamageFromSword = 0;
	DamageFromStaff = 1;
	DamageFromBook = 1;
}
Skeleton::Skeleton()
{
	MonsterHealthPoints = 600;
	MonsterDamage = 20;
	MonsterExperience = 40;
	MonsterGold = 20;
	DamageFromSword = 0;
	DamageFromStaff = 1;
	DamageFromBook = 1;
}
Ghoul::Ghoul()
{
	MonsterHealthPoints = 1200;
	MonsterDamage = 40;
	MonsterExperience = 80;
	MonsterGold = 40;
	DamageFromSword = 0;
	DamageFromStaff = 1;
	DamageFromBook = 1;
}
Mummy::Mummy()
{
	MonsterHealthPoints = 1050;
	MonsterDamage = 35;
	MonsterExperience = 70;
	MonsterGold = 35;
	DamageFromSword = 0;
	DamageFromStaff = 1;
	DamageFromBook = 1;
}
Boss::Boss()
{
	BossHealthPoints = 10000;
	BossDamage = 300;
	BossExperience = 1000;
	BossGold = 500;
	BDamageFromSword = 1;
	BDamageFromStaff = 1;
	BDamageFromBook = 1;
}
void Boss::ComeBackBossHP()
{
	BossHealthPoints = 10000;
}
void Boss::BossCoutCharacteristics()
{
	cout << BossHealthPoints;
}
bool Boss::BossDeath()
{
	if (BossHealthPoints <= 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
int Boss::GetBossDamage()
{
	return BossDamage;
}
void Boss::PlayerAttack(int a)
{
	BossHealthPoints = BossHealthPoints - a;
}
int Boss::GetBossExperience()
{
	return BossExperience;
}
int Boss::GetBossGold()
{
	return BossGold;
}
int Boss::ReturnDamageFromSword()
{
	return BDamageFromSword;
}
int Boss::ReturnDamageFromStaff()
{
	return BDamageFromStaff;
}
int Boss::ReturnDamageFromBook()
{
	return BDamageFromBook;
}