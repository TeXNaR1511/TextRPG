#pragma once
class Player
{
protected:
	int Experience;
	int PlayerDamage;
	int HealthPoints;
	int Gold;
	int MaxHP;
	int BonusFromSword;
	int BonusFromStaff;
	int BonusFromBook;
	int PlayerLevel;
	int MaxExperience;
	int IncreaseToPlayerDamageBasic;
	int BasicPlayerDamage;
public:
	Player();
	int ReturnGold();
	void Pay(int a);
	void IncreaseMaxHP();
	void IncreaseHealPointsLVLUP();
	void IncreaseBasicPlayerDamage();
	int ReturnMaxExperience();
	int ReturnExperience();
	void IncreasePlayerLevel();
	void IncreaseMaxExperience();
	void CoutCharacteristics();
	void CoutHP();
	bool PlayerDeath();
	void MonsterAttack(int a);
	void Heal(int a);
	int GetPlayerDamage();
	void GetExperience(int a);
	void GetGold(int a);
	void IncreasePlayerDamage(int a, int b);
	void ComeBackPlayerDamage();
	void DamageFromWeapon(int a);
	int ReturnBFSw();
	int ReturnBFSt();
	int ReturnBFB();
};
class Warrior :public Player
{
public:
	Warrior();
};
class Magician :public Player
{
public:
	Magician();
};
class Priest :public Player
{
public:
	Priest();
};
