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
		cout << "Вы выбрали воина" << endl;
		break;
	case MAGICIAN:
		P = new Magician();
		cout << "Вы выбрали мага" << endl;
		break;
	case PRIEST:
		P = new Priest();
		cout << "Вы выбрали жреца" << endl;
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
	cout << "Дом:" << endl;
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
			cout << "Подземелье:" << endl;
			Monster* M = nullptr;
			switch (M->GetMonster(M->getRandomNumber()))
			{
			case 1:
				M = new Spider();
				cout << "Паук - нечисть" << endl;
				break;
			case 2:
				M = new Ghost();
				cout << "Призрак - нежить" << endl;
				break;
			case 3:
				M = new Devil();
				cout << "Чёрт - нечисть" << endl;
				break;
			case 4:
				M = new Skeleton();
				cout << "Скелет - нежить" << endl;
				break;
			case 5:
				M = new Zombie();
				cout << "Зомби - нежить" << endl;
				break;
			case 6:
				M = new Wolfman();
				cout << "Оборотень - нечисть" << endl;
				break;
			case 7:
				M = new Mummy();
				cout << "Мумия - нежить" << endl;
				break;
			case 8:
				M = new Ghoul();
				cout << "Гуль - нежить" << endl;
				break;
			case 9:
				M = new Vampire();
				cout << "Вампир - нежить" << endl;
				break;
			default:
				M = new Demon();
				cout << "Демон - нечисть" << endl;
				break;
			}
			i = 0;
			cout << "Ход " << i << endl;
			i++;
			cout << "Здоровье игрока:";
			P->CoutHP();
			cout << " Здоровье монстра:";
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
					cout << "Ход " << i << endl;
					i++;
					cout << "Здоровье игрока:";
					P->CoutHP();
					cout << " Здоровье монстра:";
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
						cout << "Зелий регенерации нет" << endl;
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
					cout << "Здоровье игрока:";
					P->CoutHP();
					cout << endl;
					cout << "Получен опыт:0" << endl;
					cout << "Получено золото:0" << endl;
					i = -1;
					cout << "Дом:" << endl;
					break;
				default:
					P->MonsterAttack(M->GetMonsterDamage());
					cout << "Ход " << i << endl;
					i++;
					cout << "Здоровье игрока:";
					P->CoutHP();
					cout << " Здоровье монстра:";
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
				cout << "Получен опыт:" << M->GetMonsterExperience() << endl;
				cout << "Получено золото:" << M->GetMonsterGold() << endl;
				cout << "Дом:" << endl;
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
				cout << "Зелий регенерации нет" << endl;
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
			cout << "Пришла пора сражаться с боссом:" << endl;
			i = 0;
			cout << "Ход " << i << endl;
			i++;
			cout << "Здоровье игрока:";
			P->CoutHP();
			cout << " Здоровье босса:";
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
					cout << "Ход " << i << endl;
					i++;
					cout << "Здоровье игрока:";
					P->CoutHP();
					cout << " Здоровье монстра:";
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
						cout << "Зелий регенерации нет" << endl;
					}
					break;
				case EXIT_BOSS:
					cout << "Здоровье игрока:";
					P->CoutHP();
					cout << endl;
					cout << "Получен опыт:0" << endl;
					cout << "Получено золото:0" << endl;
					i = -1;
					cout << "Дом:" << endl;
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
					cout << "Ход " << i << endl;
					i++;
					cout << "Здоровье игрока:";
					P->CoutHP();
					cout << " Здоровье босса:";
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
				cout << "Получен опыт:" << B.GetBossExperience() << endl;
				cout << "Получено золото:" << B.GetBossGold() << endl;
				cout << "Вы победили босса" << endl;
				cout << "Игра окончена" << endl;
				Sleep(10000);
				delete P;
				return 0;
			}
			break;
		case SHOP:
			cout << "Магазин:" << endl;
			cout << "Добро пожаловать, герой" << endl;
			cout << "Здесь ты можешь приобрести всё, что тебе нужно" << endl;
			i = 0;
			while (i >= 0)
			{
				function = getValue();
				switch (function)
				{
				case EXIT_SHOP:
					cout << "Дом:" << endl;
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
						cout << "Недостаточно золота для покупки" << endl;
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
						cout << "Недостаточно золота для покупки" << endl;
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
						cout << "Недостаточно золота для покупки" << endl;
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
						cout << "Недостаточно золота для покупки" << endl;
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
			cout << "Игра окончена" << endl;
			delete P;
			Sleep(10000);
			return 0;
		}
		if (P->ReturnMaxExperience() <= P->ReturnExperience())
		{
			while (P->ReturnMaxExperience() <= P->ReturnExperience())
			{
				cout << "Ваш уровень повышен" << endl;
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