// Text RPG Assignment


#include <algorithm>
#include "CharacterCreator.h"
#include "Location.h"
#include <cstdlib>
#include <iomanip>
#include <limits>
#include <conio.h>

int rollStat();


int main() {
	srand((unsigned)time(NULL));

	Character player(8, 8, 8, 8, 8, 8, 10, 10, 15);
	std::string name;
	std::string look = "(L)ook";
	std::string interact = "(I)nteract";
	std::string talk = "(T)alk";
	std::string fight = "(F)ight";
	char playerAction;
	char yesNo;
	int playerChoice;
	int ancestryChoice;
	int warriorChoice;


	std::cout << "\t\t\tMISTY HOLLOW\n\n";
	std::cout << "\t\tA game by Trevor Turner\n\n\n";
	std::cout << "Press any key to continue\n";
	_getch();
	std::cout << "\n[1] NEW GAME";
	std::cout << "\n[2] QUIT\n";
	std::cout << "\n> ";
	std::cin >> playerChoice;
	switch (playerChoice) {
	case 1:
		std::cout << "\nYour eyes open slowly. Your head is throbbing and you can feel a dampness to your clothing.\n";
		std::cout << "\n" << look << "\t" << interact << "\t" << talk << "\n\n> ";
		std::cin >> playerAction;
		do {
			if (playerAction == 'l' || playerAction == 'L') {
				std::cout << "\nYou are in a small room lit dimly with flickering candlelight, laying on a wooden table.\n";
				_getch();
				std::cout << "The smells of antiseptic and iron are thick in the air.\n";
				_getch();
				std::cout << "A man sits near you reading a book.\n";
				_getch();
				std::cout << "He looks to you when your eyes flutter open.\n";
				do {
					std::cout << "\n" << look << "\t" << interact << "\t" << talk << "\n\n> ";
					std::cin >> playerAction;

					if (playerAction == 'l' || playerAction == 'L') {
						std::cout << "\nHe appears to be in his mid to late fifties with deep, sunken eyes and a greying beard.\n";
						std::cout << "He smiles at you as you look at him.\n";
						continue;
					}
					if (playerAction == 'i' || playerAction == 'I') {
						break;
					}
					if (playerAction == 't' || playerAction == 'T') {
						break;
					}
				} while (playerAction != 't' && playerAction != 'T' || playerAction != 'i' && playerAction != 'I');
			}if (playerAction == 'i' || playerAction == 'I') {
				std::cout << "\nYou try to move but your arms are heavy. Someone reaches out and grabs your arm, assiting you.\n";
				break;
			}if (playerAction == 't' || playerAction == 'T') {
				std::cout << "\nYou try and speak, a raspy, hollow sound coming from your mouth.\n";
			}
		} while (playerAction != 't' && playerAction != 'T');
		std::cout << "\nStranger: Oh, you're finally awake.\n";
		_getch();
		std::cout << "Stranger: I thought we'd lost you there. Dangerous times. Dangerous times, indeed.\n";
		_getch();
		std::cout << "Stranger: My name is Reverend Dorion. But you can call me Preacher.\n";
		_getch();
		std::cout << "Preacher: Most everyone does. Well everyone who is still left.\n\n";
		_getch();
		std::cout << "Preacher helps to get you into a seated position.\n\n";
		_getch();
		std::cout << "Preacher: I found you lying in the woods with a rather nasty head wound.\n";
		_getch();
		std::cout << "Preacher: It is honestly amazing you are alive. But, truly you are a fighter.\n\n";
		_getch();
		std::cout << "He smiles at you and moves to sit back down in a chair near the table you are on.\n\n";
		_getch();
		std::cout << "Preacher: You are probably wondering what is going on, and I will tell you, but first I need to test your memory.\n";
		_getch();
		std::cout << "Preacher: Afterall, it was quite a nasty bump on the head.\n";
		_getch();
		do {
			std::cout << "Preacher: So, tell me, what is your name?\n\n";

			do {
				std::cout << "(Please enter the name of your character. It must be between 1 and 10 characters long.)\n";
				std::cout << "\n> ";

				std::cin >> name;
				player.SetPlayerName(name);
			} while (player.GetName() == " " || player.GetName().size() > 10);
			do {
				std::cout << "\n" << player.GetName() << " is it?\n";
				std::cout << "A fine name.\n";
				_getch();
				std::cout << "\nAnd could you tell me what your ancestry is?\n\n";
				_getch();
				std::cout << "[1] Don't you know a Dwarf when you see one?\n";
				std::cout << "[2] Surely the scales gave it away. I am a Dragonborn.\n";
				std::cout << "[3] Clearly I am an Elf.\n";
				std::cout << "[4] 100% Gnomish blood, right here. Though I'm told there's a bit of troll on my mother's side.\n";
				std::cout << "[5] Well, sir, and I don't mean to be rude, sir, but I'm definitely, maybe, a Halfling. I think anyway.\n";
				std::cout << "[6] Grade-A Human, my good man.\n";
				std::cout << "[7] Hrmm. Orc.\n";
				std::cout << "OR\n8. Change your character's name.\n\n";
				std::wcout << "(1 - 8)> ";
				while (true) {
					std::cin >> ancestryChoice;
					player.SetCharacterAncestry(ancestryChoice);
					if (std::cin.fail()) {
						std::cerr << "Please choose a number (1 - 8).\n> ";
						std::cin.clear();
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						continue;
					}
					if (ancestryChoice < 1 || ancestryChoice > 8) {
						std::cerr << "Please choose a number (1 - 8).\n> ";
						continue;
					}

					switch (ancestryChoice) {
					case DWARF:
						std::cout << "\n\nPreacher: Ah, a stout and hardy Dwarf! (+2 con, +1 str)\n";
						player.SetConstitution(player.GetConstitution() + 2);
						player.SetStrength(player.GetStrength() + 1);
						break;
					case DRAGONBORN:
						std::cout << "\n\nPreacher: Oh, a strong and proud Dragonborn! (+2 str, +1 cha)\n";
						player.SetStrength(player.GetStrength() + 2);
						player.SetCharisma(player.GetCharisma() + 1);
						break;
					case ELF:
						std::cout << "\n\nPreacher: Of course, a swift and wise Elf! (+2 dex, +1 wis)\n";
						player.SetDexterity(player.GetDexterity() + 2);
						player.SetWisdom(player.GetWisdom() + 1);
						break;
					case GNOME:
						std::cout << "\n\nPreacher: Aha, a smart and quickfooted Gnome! (+2 int, +1 dex)\n";
						player.SetIntelligence(player.GetIntelligence() + 2);
						player.SetDexterity(player.GetDexterity() + 1);
						break;
					case HALFING:
						std::cout << "\n\nPreacher: Oh, a stealthy and friendly Halfling! (+2 dex, +1 cha)\n";
						player.SetDexterity(player.GetDexterity() + 2);
						player.SetCharisma(player.GetCharisma() + 1);
						break;
					case HUMAN:
						std::cout << "\n\nPreacher: Of couse, an adaptable and hearty Human! (+2 wis, +1 con)\n";
						player.SetWisdom(player.GetWisdom() + 2);
						player.SetConstitution(player.GetConstitution() + 1);
						break;
					case ORC:
						std::cout << "\n\nPreacher: Ah, a powerful and canny Orc! (+2 str, +1 wis)\n";
						player.SetStrength(player.GetStrength() + 2);
						player.SetWisdom(player.GetWisdom() + 1);
						break;
					}
					break;
				}
				if (ancestryChoice == 8) {
					std::cout << "\n\nPreacher: Oh. I'm sorry I must have misheard you. What is your name?\n";
					std::cout << "> ";
					std::cin >> name;
					player.SetPlayerName(name);
					continue;
				}
				_getch();

				std::cout << "\nPreacher: You seem like a warrior of some kind. Could you tell me what sort of warrior you are?\n\n";
				_getch();
				std::cout << "[1] I feel that music is the magic of this world, I am a Bard!\n";
				std::cout << "[2] I feel like a mighty warrior, I must be a Fighter!\n";
				std::cout << "[3] I feel at peace with myself and the world, surely I am a Monk!\n";
				std::cout << "[4] I feel that it is my duty to protect the innocent, I must be a Paladin!\n";
				std::cout << "[5] I feel quick and quiet with a penchant for mischief, I'm definitely a Rogue!\n";
				std::cout << "[6] I can feel the power of magic flowing through me, obviously I am a Wizard!\nOR\n";
				std::cout << "7. Change your ancestry.\n";
				std::cout << "\nNow, What is your class?\n(0 - 7)> ";
				while (true) {
					std::cin >> warriorChoice;
					player.SetCharacterWarrior(warriorChoice);
					if (std::cin.fail()) {
						std::cerr << "Please choose a number (0 - 7).\n> ";
						std::cin.clear();
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						continue;
					}
					if (warriorChoice < 0 || warriorChoice > 8) {
						std::cerr << "Please choose a number (0 - 7).\n> ";
						continue;
					}
					switch (warriorChoice) {
					case BARD:
						std::cout << "\n\nPreacher: The charismatic and acrobatic Bard! Hmm, Perhaps you'll play me a song?\n";
						player.SetStrength(player.GetStrength() + 0);
						player.SetDexterity(player.GetDexterity() + 6);
						player.SetConstitution(player.GetConstitution() + 4);
						player.SetIntelligence(player.GetIntelligence() + 5);
						player.SetWisdom(player.GetWisdom() + 2);
						player.SetCharisma(player.GetCharisma() + 7);
						player.SetMaxHP(player.GetMaxHP() + player.GetModifier(player.GetConstitution()));
						player.SetSpellAbility(warriorChoice);
						player.SetSpellModifier(warriorChoice);
						player.SetArmorClass(player.GetArmorClass() + player.GetModifier(player.GetDexterity()));
						break;
					case FIGHTER:
						std::cout << "\n\nThe strong and courageous Fighter! I'll be sure to stay on your good side!\n";
						player.SetStrength(player.GetStrength() + 7);
						player.SetDexterity(player.GetDexterity() + 5);
						player.SetConstitution(player.GetConstitution() + 6);
						player.SetIntelligence(player.GetIntelligence() + 2);
						player.SetWisdom(player.GetWisdom() + 4);
						player.SetCharisma(player.GetCharisma() + 0);
						player.SetMaxHP(player.GetMaxHP() + player.GetModifier(player.GetConstitution()));
						player.SetSpellAbility(warriorChoice);
						player.SetSpellModifier(warriorChoice);
						player.SetArmorClass(player.GetArmorClass() + player.GetModifier(player.GetDexterity()));
						break;
					case MONK:
						std::cout << "\n\nThe swift and enlightened Monk! You'll have to tell me the secret to inner peace!\n";
						player.SetStrength(player.GetStrength() + 4);
						player.SetDexterity(player.GetDexterity() + 7);
						player.SetConstitution(player.GetConstitution() + 5);
						player.SetIntelligence(player.GetIntelligence() + 0);
						player.SetWisdom(player.GetWisdom() + 6);
						player.SetCharisma(player.GetCharisma() + 2);
						player.SetMaxHP(player.GetMaxHP() + player.GetModifier(player.GetConstitution()));
						player.SetSpellAbility(warriorChoice);
						player.SetSpellModifier(warriorChoice);
						player.SetArmorClass(player.GetArmorClass() + player.GetModifier(player.GetDexterity()));
						break;
					case PALADIN:
						std::cout << "\n\nThe noble and mighty Paladin! I feel safer already with you around!\n";
						player.SetStrength(player.GetStrength() + 7);
						player.SetDexterity(player.GetDexterity() + 0);
						player.SetConstitution(player.GetConstitution() + 5);
						player.SetIntelligence(player.GetIntelligence() + 2);
						player.SetWisdom(player.GetWisdom() + 4);
						player.SetCharisma(player.GetCharisma() + 6);
						player.SetMaxHP(player.GetMaxHP() + player.GetModifier(player.GetConstitution()));
						player.SetSpellAbility(warriorChoice);
						player.SetSpellModifier(warriorChoice);
						player.SetArmorClass(player.GetArmorClass() + player.GetModifier(player.GetDexterity()));
						break;
					case ROGUE:
						std::cout << "\n\nThe quickfooted and even quicker witted Rogue! I'll have keep an eye on my purse while you're around!\n";
						player.SetStrength(player.GetStrength() + 0);
						player.SetDexterity(player.GetDexterity() + 7);
						player.SetConstitution(player.GetConstitution() + 2);
						player.SetIntelligence(player.GetIntelligence() + 6);
						player.SetWisdom(player.GetWisdom() + 4);
						player.SetCharisma(player.GetCharisma() + 5);
						player.SetMaxHP(player.GetMaxHP() + player.GetModifier(player.GetConstitution()));
						player.SetSpellAbility(warriorChoice);
						player.SetSpellModifier(warriorChoice);
						player.SetArmorClass(player.GetArmorClass() + player.GetModifier(player.GetDexterity()));
						break;
					case WIZARD:
						std::cout << "\n\nThe mystical and mysterious Wizard! Perhaps you could show me a magic trick?\n";
						player.SetStrength(player.GetStrength() + 0);
						player.SetDexterity(player.GetDexterity() + 4);
						player.SetConstitution(player.GetConstitution() + 5);
						player.SetIntelligence(player.GetIntelligence() + 7);
						player.SetWisdom(player.GetWisdom() + 6);
						player.SetCharisma(player.GetCharisma() + 2);
						player.SetMaxHP(player.GetMaxHP() + player.GetModifier(player.GetConstitution()));
						player.SetSpellAbility(warriorChoice);
						player.SetSpellModifier(warriorChoice);
						player.SetArmorClass(player.GetArmorClass() + player.GetModifier(player.GetDexterity()));
						break;
					} break;
				}
				if (warriorChoice == 7) {
					std::cout << "\nOh I must have misheard you.";
					continue;
				}
				_getch();
				std::cout << "\n\nSo here is what I've gathered so far.\n\n";
				_getch();
				std::cout << "Your name is: " << player.GetName() << "\n";
				_getch();
				std::cout << "Your ancestry is: " << player.GetCharacterAncestry(ancestryChoice);
				_getch();
				std::cout << "\nYour class is: " << player.GetCharacterWarrior(warriorChoice);
				_getch();
				std::cout << "\n\nMax Hit Points: " << player.GetMaxHP();
				std::cout << "\nBase Armor Class (10 + Dex Modifier): " << player.GetArmorClass();
				std::cout << "\nCurrent Gold: " << player.GetCharacterGold();
				std::cout << "\n\nABILITY SCORES\n";
				std::cout << "------------------------------";
				std::cout << "\nSTR: " << player.GetStrength() << "\t\tModifier = " << player.GetModifier(player.GetStrength());
				std::cout << "\nDEX: " << player.GetDexterity() << "\t\tModifier = " << player.GetModifier(player.GetDexterity());
				std::cout << "\nCON: " << player.GetConstitution() << "\t\tModifier = " << player.GetModifier(player.GetConstitution());
				std::cout << "\nINT: " << player.GetIntelligence() << "\t\tModifier = " << player.GetModifier(player.GetIntelligence());
				std::cout << "\nWIS: " << player.GetWisdom() << "\t\tModifier = " << player.GetModifier(player.GetWisdom());
				std::cout << "\nCHA: " << player.GetCharisma() << "\t\tModifier = " << player.GetModifier(player.GetCharisma());
				std::cout << "\n\nSpell Attack Ability: " << player.GetSpellAbility(warriorChoice);
				std::cout << "\nSpell Attack Modifier: " << player.GetSpellModifier(warriorChoice);
				_getch();

			} while (ancestryChoice == 8 || warriorChoice == 7);
			std::cout << "\n\nDo I have everything right?";
			std::cout << "\n(y/n)> ";
			std::cin >> yesNo;
			if (yesNo == 'y' || yesNo == 'Y') {
				std::cout << "\nPreacher: Ah, well it seems to me that there is no lasting damage. Your memory is working just fine.\n\n";
				break;
			}
			else if (yesNo == 'n' || yesNo == 'N') {
				std::cout << "\nPreacher: Hmm, perhaps we should start from the top.\n\n";
				continue;
			}
		} while (yesNo == 'N' || yesNo == 'n');
		break;
		std::cout << "\nNow that that is settled, I'm sure you have questions. Please, ask them.\n";
		std::cout << "\n\n[0] Leave";
		std::cout << "\n[1] Where am I?";
		std::cout << "\n[2] Who are you?";
		std::cout << "\n[3] ";
		std::cout << "\n";
		std::cout << "\n";

	case 2:
		return 0;
	}
	
	return 0;
}



int rollStat() {
	return 8 + rand() % 11;
}

