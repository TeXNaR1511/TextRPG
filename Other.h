#pragma once
class Inventory
{
private:
	int NumberOfHealPotion;
	int NumberOfSword;
	int NumberOfStaff;
	int NumberOfBook;
public:
	Inventory();
	void BuyHealPotion();
	int ExistHealPotion();
	void DecreaseHealPotion();
	void CoutInvent();
};
class HealPotion
{
private:
	int AddHP;
public:
	HealPotion();
	int GetAddHP();
	void CoutAddHealPotion();
};
class Sword
{
private:
	int SwordDamage;
public:
	Sword();
	void BuyNewSword(int a);
	int ReturnSwD();
};
class Staff
{
private:
	int StaffDamage;
public:
	Staff();
	void BuyNewStaff(int a);
	int ReturnStD();
};
class Book
{
private:
	int BookDamage;
public:
	Book();
	void BuyNewBook(int a);
	int ReturnBD();
};
class Shop
{
private:
	int IncreaseSwordDamage;
	int IncreaseStaffDamage;
	int IncreaseBookDamage;
	int SwordPrice;
	int StaffPrice;
	int BookPrice;
	int HealPotionPrice;
	int IncreaseSwordPrice;
	int IncreaseStaffPrice;
	int IncreaseBookPrice;
public:
	Shop();
	int ReturnSwordPrice();
	int ReturnStaffPrice();
	int ReturnBookPrice();
	int ReturnIncreaseSwordDamage();
	int ReturnIncreaseStaffDamage();
	int ReturnIncreaseBookDamage();
	void CoutBookPrice();
	void CoutIncreaseBookDamage();
	void CoutSwordPrice();
	void CoutIncreaseSwordDamage();
	void CoutStaffPrice();
	void CoutIncreaseStaffDamage();
	void IncreasingSwordPrice();
	void IncreasingStaffPrice();
	void IncreasingBookPrice();
	void CoutHealPotionPrice();
	int ReturnHealPotionPrice();
};

