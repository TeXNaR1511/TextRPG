#include "Character.h"
#include <iostream>
using namespace std;
Player::Player()
{
	HealthPoints = 0;
	Experience = 0;
	PlayerDamage = 0;
	Gold = 0;
	MaxHP = 1000;
	BonusFromSword = 0;
	BonusFromStaff = 0;
	BonusFromBook = 0;
	PlayerLevel = 0;
	MaxExperience = 3;
	IncreaseToPlayerDamageBasic = 0;
	BasicPlayerDamage = 1;
}
int Player::ReturnGold()
{
	return Gold;
}
void Player::Pay(int a)
{
	Gold = Gold - a;
}
void Player::IncreaseMaxHP()
{
	MaxHP = MaxHP + 8 * PlayerLevel;
}
void Player::IncreaseHealPointsLVLUP()
{
	HealthPoints = HealthPoints + 8 * PlayerLevel;
}
void Player::IncreaseBasicPlayerDamage()
{
	BasicPlayerDamage = BasicPlayerDamage + IncreaseToPlayerDamageBasic;
}
int Player::ReturnMaxExperience()
{
	return MaxExperience;
}
int Player::ReturnExperience()
{
	return Experience;
}
void Player::IncreasePlayerLevel()
{
	PlayerLevel = PlayerLevel + 1;
	Experience = Experience - MaxExperience;
}
void Player::IncreaseMaxExperience()
{
	MaxExperience = MaxExperience + 2 * PlayerLevel;
}
void Player::CoutCharacteristics()
{
	cout << "Здоровье:" << HealthPoints << " " << "Опыт:" << Experience << " " << "Следующий уровень:" << MaxExperience << " " << "Уровень:" << PlayerLevel << " " << "Урон:" << PlayerDamage << " " << "Золото:" << Gold << " " << endl;
}
void Player::CoutHP()
{
	cout << HealthPoints;
}
bool Player::PlayerDeath()
{
	if (HealthPoints <= 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void Player::MonsterAttack(int a)
{
	HealthPoints = HealthPoints - a;
}
void Player::Heal(int a)
{
	HealthPoints = HealthPoints + a;
	if (HealthPoints > MaxHP)
	{
		HealthPoints = MaxHP;
	}
}
int Player::GetPlayerDamage()
{
	return PlayerDamage;
}
void Player::GetExperience(int a)
{
	Experience = Experience + a;
}
void Player::GetGold(int a)
{
	Gold = Gold + a;
}
void Player::IncreasePlayerDamage(int a, int b)
{
	PlayerDamage = PlayerDamage + a * b;
}
void Player::ComeBackPlayerDamage()
{
	PlayerDamage = BasicPlayerDamage;
}
void Player::DamageFromWeapon(int a)
{
	PlayerDamage = PlayerDamage * a;
}
int Player::ReturnBFSw()
{
	return BonusFromSword;
}
int Player::ReturnBFSt()
{
	return BonusFromStaff;
}
int Player::ReturnBFB()
{
	return BonusFromBook;
}
Warrior::Warrior()
{
	HealthPoints = 1000;
	PlayerDamage = BasicPlayerDamage;
	BonusFromSword = 7;
	BonusFromStaff = 1;
	BonusFromBook = 4;
	IncreaseToPlayerDamageBasic = 4;
}
Magician::Magician()
{
	HealthPoints = 1000;
	PlayerDamage = BasicPlayerDamage;
	BonusFromSword = 4;
	BonusFromStaff = 7;
	BonusFromBook = 1;
	IncreaseToPlayerDamageBasic = 2;
}
Priest::Priest()
{
	HealthPoints = 1000;
	PlayerDamage = BasicPlayerDamage;
	BonusFromSword = 4;
	BonusFromStaff = 1;
	BonusFromBook = 7;
	IncreaseToPlayerDamageBasic = 3;
}