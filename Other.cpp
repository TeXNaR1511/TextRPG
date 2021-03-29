#include "Other.h"
#include <iostream>
using namespace std;
Inventory::Inventory()
{
	NumberOfHealPotion = 0;
	NumberOfSword = 1;
	NumberOfStaff = 1;
	NumberOfBook = 1;
}
void Inventory::BuyHealPotion()
{
	NumberOfHealPotion = NumberOfHealPotion + 1;
}
int Inventory::ExistHealPotion()
{
	return NumberOfHealPotion;
}
void Inventory::DecreaseHealPotion()
{
	NumberOfHealPotion = NumberOfHealPotion - 1;
}
void Inventory::CoutInvent()
{
	cout << "Меч:" << NumberOfSword << " " << "Магический посох:" << NumberOfStaff << " " << "Молитвенник:" << NumberOfBook << " " << "Зелье регенерации:" << NumberOfHealPotion << endl;
}
HealPotion::HealPotion()
{
	AddHP = 400;
}
int HealPotion::GetAddHP()
{
	return AddHP;
}
void HealPotion::CoutAddHealPotion()
{
	cout << "Зелье регенерации восстанавливает ";
	cout << AddHP << " здоровья" << endl;
}
Sword::Sword()
{
	SwordDamage = 10;
}
void Sword::BuyNewSword(int a)
{
	SwordDamage = SwordDamage + a;
}
int Sword::ReturnSwD()
{
	return SwordDamage;
}
Staff::Staff()
{
	StaffDamage = 10;
}
void Staff::BuyNewStaff(int a)
{
	StaffDamage = StaffDamage + a;
}
int Staff::ReturnStD()
{
	return StaffDamage;
}
Book::Book()
{
	BookDamage = 10;
}
void Book::BuyNewBook(int a)
{
	BookDamage = BookDamage + a;
}
int Book::ReturnBD()
{
	return BookDamage;
}
Shop::Shop()
{
	IncreaseSwordDamage = 11;
	IncreaseStaffDamage = 12;
	IncreaseBookDamage = 10;
	SwordPrice = 35;
	StaffPrice = 35;
	BookPrice = 35;
	HealPotionPrice = 20;
	IncreaseSwordPrice = 11;
	IncreaseStaffPrice = 10;
	IncreaseBookPrice = 9;
}
int Shop::ReturnSwordPrice()
{
	return SwordPrice;
}
int Shop::ReturnStaffPrice()
{
	return StaffPrice;
}
int Shop::ReturnBookPrice()
{
	return BookPrice;
}
int Shop::ReturnIncreaseSwordDamage()
{
	return IncreaseSwordDamage;
}
int Shop::ReturnIncreaseStaffDamage()
{
	return IncreaseStaffDamage;
}
int Shop::ReturnIncreaseBookDamage()
{
	return IncreaseBookDamage;
}
void Shop::CoutBookPrice()
{
	cout << "Прокачка молитвенника стоит " << BookPrice << " золота" << endl;
}
void Shop::CoutIncreaseBookDamage()
{
	cout << "Прокачка молитвенника добавит " << IncreaseBookDamage << " урона" << endl;
}
void Shop::CoutSwordPrice()
{
	cout << "Прокачка меча стоит " << SwordPrice << " золота" << endl;
}
void Shop::CoutIncreaseSwordDamage()
{
	cout << "Прокачка меча добавит " << IncreaseSwordDamage << " урона" << endl;
}
void Shop::CoutStaffPrice()
{
	cout << "Прокачка магического посоха стоит " << StaffPrice << " золота" << endl;
}
void Shop::CoutIncreaseStaffDamage()
{
	cout << "Прокачка магического посоха добавит " << IncreaseStaffDamage << " урона" << endl;
}
void Shop::IncreasingSwordPrice()
{
	SwordPrice = SwordPrice + IncreaseSwordPrice;
}
void Shop::IncreasingStaffPrice()
{
	StaffPrice = StaffPrice + IncreaseStaffPrice;
}
void Shop::IncreasingBookPrice()
{
	BookPrice = BookPrice + IncreaseBookPrice;
}
void Shop::CoutHealPotionPrice()
{
	cout << "Зелье регенерации стоит ";
	cout << HealPotionPrice << " золота" << endl;
}
int Shop::ReturnHealPotionPrice()
{
	return HealPotionPrice;
}