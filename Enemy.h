#pragma once
class Monster
{
protected:
	int MonsterDamage;
	int MonsterHealthPoints;
	int MonsterExperience;
	int MonsterGold;
	int DamageFromSword;
	int DamageFromStaff;
	int DamageFromBook;
public:
	Monster();
	int getRandomNumber();
	int GetMonster(int a);
	void MonsterCoutCharacteristics();
	bool MonsterDeath();
	int GetMonsterDamage();
	void PlayerAttack(int a);
	int GetMonsterExperience();
	int GetMonsterGold();
	int ReturnDamageFromSword();
	int ReturnDamageFromStaff();
	int ReturnDamageFromBook();
};
class Spider :public Monster
{
public:
	Spider();
};
class Wolfman :public Monster
{
public:
	Wolfman();
};
class Devil :public Monster
{
public:
	Devil();
};
class Demon :public Monster
{
public:
	Demon();
};
class Zombie :public Monster
{
public:
	Zombie();
};
class Ghost :public Monster
{
public:
	Ghost();
};
class Vampire :public Monster
{
public:
	Vampire();
};
class Skeleton :public Monster
{
public:
	Skeleton();
};
class Ghoul :public Monster
{
public:
	Ghoul();
};
class Mummy :public Monster
{
public:
	Mummy();
};
class Boss
{
protected:
	int BossDamage;
	int BossHealthPoints;
	int BossExperience;
	int BossGold;
	int BDamageFromSword;
	int BDamageFromStaff;
	int BDamageFromBook;
public:
	Boss();
	void ComeBackBossHP();
	void BossCoutCharacteristics();
	bool BossDeath();
	int GetBossDamage();
	void PlayerAttack(int a);
	int GetBossExperience();
	int GetBossGold();
	int ReturnDamageFromSword();
	int ReturnDamageFromStaff();
	int ReturnDamageFromBook();
};
