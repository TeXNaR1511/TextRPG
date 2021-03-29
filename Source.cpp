#include <iostream>
#include <locale.h>
#include <Windows.h>
#include <fstream>
#include <string>
#include <chrono>
#include "Character.h"
#include "Enemy.h"
#include "Other.h"
using namespace std;
using namespace std::chrono;
int getValue()
{
	while (true)
	{
		int a;
		cin >> a;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(32767, '\n');
		}
		else
		{
			return a;
		}
	}
}
enum Commands
{
	PLAYER,
	WARRIOR,
	MAGICIAN,
	PRIEST,
	HINT_HOME,
	HINT_DUNGEON,
	DUNGEON,
	EXIT,
	EXIT_DUNGEON,
	HEAL,
	ATTACK,
	SWORD,
	STAFF,
	BOOK,
	SHOP,
	EXIT_SHOP,
	HINT_SHOP,
	BOSS,
	EXIT_BOSS,
	HINT_BOSS,
	BUY_SWORD,
	BUY_STAFF,
	BUY_HEAL_POTION,
	COST_SWORD,
	COST_STAFF,
	COST_HEAL_POTION,
	INVENT,
	BUY_BOOK,
	COST_BOOK,
	HINT_HINTS
};
int main()
{
	milliseconds ms = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
	srand((unsigned)ms.count());
	setlocale(LC_ALL, "Russian");
	string line;
	ifstream file;
	int i;
	file.open("Introduction.txt");
	if (file.is_open())
	{
		while (getline(file, line))
		{
			cout << line << endl;
		}
	}
	file.close();
	int ClassOfCharacter;
	ClassOfCharacter = getValue();
	Player* P = nullptr;
	switch (ClassOfCharacter)
	{
	case WARRIOR:
		P = new Warrior();
		cout << "�� ������� �����" << endl;
		break;
	case MAGICIAN:
		P = new Magician();
		cout << "�� ������� ����" << endl;
		break;
	case PRIEST:
		P = new Priest();
		cout << "�� ������� �����" << endl;
		break;
	default:
		return 0;
	}
	file.open("AllHints.txt");
	if (file.is_open())
	{
		while (getline(file, line))
		{
			cout << line << endl;
		}
	}
	file.close();
	cout << "���:" << endl;
	Inventory I{};
	HealPotion RegenPotion{};
	Sword Sw{};
	Staff St{};
	Book BPrayer{};
	Boss B{};
	Shop Sh{};
	int command;
	int function;
	command=getValue();
	while (1 > 0)
	{
		switch (command)
		{
		case EXIT:
			delete P;
			return 0;
		case PLAYER:
			P->CoutCharacteristics();
			break;
		case DUNGEON:
		{
			cout << "����������:" << endl;
			Monster* M = nullptr;
			switch (M->GetMonster(M->getRandomNumber()))
			{
			case 1:
				M = new Spider();
				cout << "���� - �������" << endl;
				break;
			case 2:
				M = new Ghost();
				cout << "������� - ������" << endl;
				break;
			case 3:
				M = new Devil();
				cout << "׸�� - �������" << endl;
				break;
			case 4:
				M = new Skeleton();
				cout << "������ - ������" << endl;
				break;
			case 5:
				M = new Zombie();
				cout << "����� - ������" << endl;
				break;
			case 6:
				M = new Wolfman();
				cout << "��������� - �������" << endl;
				break;
			case 7:
				M = new Mummy();
				cout << "����� - ������" << endl;
				break;
			case 8:
				M = new Ghoul();
				cout << "���� - ������" << endl;
				break;
			case 9:
				M = new Vampire();
				cout << "������ - ������" << endl;
				break;
			default:
				M = new Demon();
				cout << "����� - �������" << endl;
				break;
			}
			i = 0;
			cout << "��� " << i << endl;
			i++;
			cout << "�������� ������:";
			P->CoutHP();
			cout << " �������� �������:";
			M->MonsterCoutCharacteristics();
			cout << endl;
			while (P->PlayerDeath() == false && M->MonsterDeath() == false && i >= 0)
			{
				function = getValue();
				switch (function)
				{
				case ATTACK:
					P->MonsterAttack(M->GetMonsterDamage());
					M->PlayerAttack(P->GetPlayerDamage());
					cout << "��� " << i << endl;
					i++;
					cout << "�������� ������:";
					P->CoutHP();
					cout << " �������� �������:";
					M->MonsterCoutCharacteristics();
					cout << endl;
					break;
				case HEAL:
					if (I.ExistHealPotion() > 0)
					{
						P->Heal(RegenPotion.GetAddHP());
						I.DecreaseHealPotion();
					}
					else
					{
						cout << "����� ����������� ���" << endl;
					}
					break;
				case SWORD:
					P->ComeBackPlayerDamage();
					P->IncreasePlayerDamage(P->ReturnBFSw(), Sw.ReturnSwD());
					P->DamageFromWeapon(M->ReturnDamageFromSword());
					break;
				case STAFF:
					P->ComeBackPlayerDamage();
					P->IncreasePlayerDamage(P->ReturnBFSt(), St.ReturnStD());
					P->DamageFromWeapon(M->ReturnDamageFromStaff());
					break;
				case BOOK:
					P->ComeBackPlayerDamage();
					P->IncreasePlayerDamage(P->ReturnBFB(), BPrayer.ReturnBD());
					P->DamageFromWeapon(M->ReturnDamageFromBook());
					break;
				case HINT_DUNGEON:
					file.open("HintDungeon.txt");
					if (file.is_open())
					{
						while (getline(file, line))
						{
							cout << line << endl;
						}
					}
					file.close();
					break;
				case HINT_HINTS:
					file.open("HintHints.txt");
					if (file.is_open())
					{
						while (getline(file, line))
						{
							cout << line << endl;
						}
					}
					file.close();
					break;
				case PLAYER:
					P->CoutCharacteristics();
					break;
				case INVENT:
					I.CoutInvent();
					break;
				case EXIT_DUNGEON:
					cout << "�������� ������:";
					P->CoutHP();
					cout << endl;
					cout << "������� ����:0" << endl;
					cout << "�������� ������:0" << endl;
					i = -1;
					cout << "���:" << endl;
					break;
				default:
					P->MonsterAttack(M->GetMonsterDamage());
					cout << "��� " << i << endl;
					i++;
					cout << "�������� ������:";
					P->CoutHP();
					cout << " �������� �������:";
					M->MonsterCoutCharacteristics();
					cout << endl;
					break;
				}
			}
			P->ComeBackPlayerDamage();
			if (M->MonsterDeath() == true)
			{
				P->GetExperience(M->GetMonsterExperience());
				P->GetGold(M->GetMonsterGold());
				cout << "������� ����:" << M->GetMonsterExperience() << endl;
				cout << "�������� ������:" << M->GetMonsterGold() << endl;
				cout << "���:" << endl;
			}
			delete M;
			break;
		}
		case HEAL:
			if (I.ExistHealPotion() > 0)
			{
				P->Heal(RegenPotion.GetAddHP());
				I.DecreaseHealPotion();
			}
			else
			{
				cout << "����� ����������� ���" << endl;
			}
			break;
		case HINT_HOME:
			file.open("HintHome.txt");
			if (file.is_open())
			{
				while (getline(file, line))
				{
					cout << line << endl;
				}
			}
			file.close();
			break;
		case BOSS:
			cout << "������ ���� ��������� � ������:" << endl;
			i = 0;
			cout << "��� " << i << endl;
			i++;
			cout << "�������� ������:";
			P->CoutHP();
			cout << " �������� �����:";
			B.BossCoutCharacteristics();
			cout << endl;
			while (P->PlayerDeath() == false && B.BossDeath() == false && i >= 0)
			{
				function = getValue();
				switch (function)
				{
				case ATTACK:
					P->MonsterAttack(B.GetBossDamage());
					B.PlayerAttack(P->GetPlayerDamage());
					cout << "��� " << i << endl;
					i++;
					cout << "�������� ������:";
					P->CoutHP();
					cout << " �������� �������:";
					B.BossCoutCharacteristics();
					cout << endl;
					break;
				case HEAL:
					if (I.ExistHealPotion() > 0)
					{
						P->Heal(RegenPotion.GetAddHP());
						I.DecreaseHealPotion();
					}
					else
					{
						cout << "����� ����������� ���" << endl;
					}
					break;
				case EXIT_BOSS:
					cout << "�������� ������:";
					P->CoutHP();
					cout << endl;
					cout << "������� ����:0" << endl;
					cout << "�������� ������:0" << endl;
					i = -1;
					cout << "���:" << endl;
					B.ComeBackBossHP();
					break;
				case SWORD:
					P->ComeBackPlayerDamage();
					P->IncreasePlayerDamage(P->ReturnBFSw(), Sw.ReturnSwD());
					P->DamageFromWeapon(B.ReturnDamageFromSword());
					break;
				case STAFF:
					P->ComeBackPlayerDamage();
					P->IncreasePlayerDamage(P->ReturnBFSt(), St.ReturnStD());
					P->DamageFromWeapon(B.ReturnDamageFromStaff());
					break;
				case BOOK:
					P->ComeBackPlayerDamage();
					P->IncreasePlayerDamage(P->ReturnBFB(), BPrayer.ReturnBD());
					P->DamageFromWeapon(B.ReturnDamageFromBook());
					break;
				case HINT_BOSS:
					file.open("HintBoss.txt");
					if (file.is_open())
					{
						while (getline(file, line))
						{
							cout << line << endl;
						}
					}
					file.close();
					break;
				case HINT_HINTS:
					file.open("HintHints.txt");
					if (file.is_open())
					{
						while (getline(file, line))
						{
							cout << line << endl;
						}
					}
					file.close();
					break;
				case PLAYER:
					P->CoutCharacteristics();
					break;
				case INVENT:
					I.CoutInvent();
					break;
				default:
					P->MonsterAttack(B.GetBossDamage());
					cout << "��� " << i << endl;
					i++;
					cout << "�������� ������:";
					P->CoutHP();
					cout << " �������� �����:";
					B.BossCoutCharacteristics();
					cout << endl;
					break;
				}
			}
			P->ComeBackPlayerDamage();
			if (B.BossDeath() == true)
			{
				P->GetExperience(B.GetBossExperience());
				P->GetGold(B.GetBossGold());
				cout << "������� ����:" << B.GetBossExperience() << endl;
				cout << "�������� ������:" << B.GetBossGold() << endl;
				cout << "�� �������� �����" << endl;
				cout << "���� ��������" << endl;
				Sleep(10000);
				delete P;
				return 0;
			}
			break;
		case SHOP:
			cout << "�������:" << endl;
			cout << "����� ����������, �����" << endl;
			cout << "����� �� ������ ���������� ��, ��� ���� �����" << endl;
			i = 0;
			while (i >= 0)
			{
				function = getValue();
				switch (function)
				{
				case EXIT_SHOP:
					cout << "���:" << endl;
					i = -1;
					break;
				case HINT_SHOP:
					file.open("HintShop.txt");
					if (file.is_open())
					{
						while (getline(file, line))
						{
							cout << line << endl;
						}
					}
					file.close();
					break;
				case HINT_HINTS:
					file.open("HintHints.txt");
					if (file.is_open())
					{
						while (getline(file, line))
						{
							cout << line << endl;
						}
					}
					file.close();
					break;
				case BUY_SWORD:
					if (P->ReturnGold() >= Sh.ReturnSwordPrice())
					{
						P->Pay(Sh.ReturnSwordPrice());
						Sw.BuyNewSword(Sh.ReturnIncreaseSwordDamage());
						Sh.IncreasingSwordPrice();
					}
					else
					{
						cout << "������������ ������ ��� �������" << endl;
					}
					break;
				case BUY_STAFF:
					if (P->ReturnGold() >= Sh.ReturnStaffPrice())
					{
						P->Pay(Sh.ReturnStaffPrice());
						St.BuyNewStaff(Sh.ReturnIncreaseStaffDamage());
						Sh.IncreasingStaffPrice();
					}
					else
					{
						cout << "������������ ������ ��� �������" << endl;
					}
					break;
				case BUY_HEAL_POTION:
					if (P->ReturnGold() >= Sh.ReturnHealPotionPrice())
					{
						P->Pay(Sh.ReturnHealPotionPrice());
						I.BuyHealPotion();
					}
					else
					{
						cout << "������������ ������ ��� �������" << endl;
					}
					break;
				case COST_SWORD:
					Sh.CoutIncreaseSwordDamage();
					Sh.CoutSwordPrice();
					break;
				case COST_STAFF:
					Sh.CoutIncreaseStaffDamage();
					Sh.CoutStaffPrice();
					break;
				case COST_HEAL_POTION:
					RegenPotion.CoutAddHealPotion();
					Sh.CoutHealPotionPrice();
					break;
				case BUY_BOOK:
					if (P->ReturnGold() >= Sh.ReturnBookPrice())
					{
						P->Pay(Sh.ReturnBookPrice());
						BPrayer.BuyNewBook(Sh.ReturnIncreaseBookDamage());
						Sh.IncreasingBookPrice();
					}
					else
					{
						cout << "������������ ������ ��� �������" << endl;
					}
					break;
				case COST_BOOK:
					Sh.CoutIncreaseBookDamage();
					Sh.CoutBookPrice();
					break;
				case INVENT:
					I.CoutInvent();
					break;
				case PLAYER:
					P->CoutCharacteristics();
					break;
				default:
					break;
				}
			}
			break;
		case INVENT:
			I.CoutInvent();
			break;
		case HINT_HINTS:
			file.open("HintHints.txt");
			if (file.is_open())
			{
				while (getline(file, line))
				{
					cout << line << endl;
				}
			}
			file.close();
			break;
		default:
			break;
		}
		if (P->PlayerDeath() == true)
		{
			cout << "���� ��������" << endl;
			delete P;
			Sleep(10000);
			return 0;
		}
		if (P->ReturnMaxExperience() <= P->ReturnExperience())
		{
			while (P->ReturnMaxExperience() <= P->ReturnExperience())
			{
				cout << "��� ������� �������" << endl;
				P->IncreasePlayerLevel();
				P->IncreaseMaxHP();
				P->IncreaseHealPointsLVLUP();
				P->IncreaseMaxExperience();
				P->IncreaseBasicPlayerDamage();
				P->ComeBackPlayerDamage();
			}
		}
		command = getValue();
	}
}