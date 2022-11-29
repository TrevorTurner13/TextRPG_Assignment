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

	Character player;
	std::string look = "(L)ook";
	std::string interact = "(I)nteract";
	std::string talk = "(T)alk";
	std::string fight = "(F)ight";
	char playerAction;
	player.strength = rollStat();
	player.dexterity = rollStat();
	player.constitution = rollStat();
	player.intelligence = rollStat();
	player.wisdom = rollStat();
	player.charisma = rollStat();
	char yesNo;
	int ancestryChoice;
	int classChoice;


	std::cout << "\t\t\tMISTY HOLLOW\n\n";
	std::cout << "\t\tA game by Trevor Turner\n\n\n";
	std::cout << "Press any key to continue\n\n";
	_getch();

	std::cout << "Your eyes open slowly. Your head is throbbing and you can feel a dampness to your clothing.\n\n";
	std::cout << "" << look << "\t" << interact << "\t" << talk << "\n> ";
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
	std::cout << "Preacher: It was quite a nasty bump on the head.\n";
	_getch();
	std::cout << "Preacher: So, tell me, what is your name?\n\n";
	
	do {
			std::cout << "(Please enter the name of your character. It must be between 1 and 10 characters long.)\n";
			std::cout << "\n> ";
			std::cin >> player.characterName;
		} while (player.characterName == " " || player.characterName.size() > 10);
	do {
		std::cout << "\n" << player.characterName << " is it?\n";
		std::cout << " A fine name.\n";
	
		std::cout << "\nAnd could you tell me what your ancestry is?\n\n";
		_getch();

		std::cout << "[1] Don't you know a Dwarf when you see one?\n";
		std::cout << "[2] Surely the scales gave it away. I am a Dragonborn.\n";
			std::cout << "[3] Clearly I am an Elf.\n";
			std::cout << "[4] 100% Gnomish blood, right here. Though I'm told there's a bit of troll on my mother's side.\n";
			std::cout << "[5] Well, sir, and I don't mean to be rude, sir, but I'm definitely, maybe, a Halfling. I think anyway.\n";
			std::cout << "[5] Grade-A Human, my good man.\n";
			std::cout << "[6] Hrmm. Orc.\n";
			std::cout << "OR\n8. Change your character's name.\n\n";
			std::wcout << "(1 - 8)> ";
			while (true) {
				std::cin >> ancestryChoice;
				player.m_Ancestry == ancestryChoice;
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
					std::cout << "\n\nAh, a stout and hardy Dwarf! (+2 con, +1 str)\n";
					player.constitution = player.constitution + 2;
					player.strength = player.strength + 1;
					break;
				case DRAGONBORN:
					std::cout << "\n\nOh, a strong and proud Dragonborn! (+2 str, +1 cha)\n";
					player.strength = player.strength + 2;
					player.charisma = player.charisma + 1;
					break;
				case ELF:
					std::cout << "\n\nOf course, a swift and wise Elf! (+2 dex, +1 wis)\n";
					player.dexterity = player.dexterity + 2;
					player.wisdom = player.wisdom + 1;
					break;
				case GNOME:
					std::cout << "\n\nAha, a smart and quickfooted Gnome! (+2 int, +1 dex)\n";
					player.intelligence = player.intelligence + 2;
					player.dexterity = player.dexterity + 1;
					break;
				case HALFING:
					std::cout << "\n\nOh, a stealthy and friendly Halfling! (+2 dex, +1 cha)\n";
					player.dexterity = player.dexterity + 2;
					player.charisma = player.charisma + 1;
					break;
				case HUMAN:
					std::cout << "\n\nOf couse, an adaptable and hearty Human! (+2 wis, +1 con)\n";
					player.wisdom = player.wisdom + 2;
					player.constitution = player.constitution + 2;
					break;
				case ORC:
					std::cout << "\n\nAh, a powerful and canny Orc! (+2 str, +1 wis)\n";
					player.strength = player.strength + 2;
					player.wisdom = player.wisdom + 1;
					break;
				}
				break;
			}
			if (ancestryChoice == 8) {
				std::cout << "\n\nOh. I'm sorry I must have misheard you. What is your name?\n";
				std::cout << "> ";
				std::cin >> player.characterName;
				continue;
			}

		if (player.strength == 8 || player.strength == 9) {
			player.strModifier = -1;
		}
		else if (player.strength == 10 || player.strength == 11) {
			player.strModifier = 0;
		}
		else if (player.strength == 12 || player.strength == 13) {
			player.strModifier = 1;
		}
		else if (player.strength == 14 || player.strength == 15) {
			player.strModifier = 2;
		}
		else if (player.strength == 16 || player.strength == 17) {
			player.strModifier = 3;
		}
		else if (player.strength == 18 || player.strength == 19) {
			player.strModifier = 4;
		}
		else {
			player.strModifier = 5;
		}

		if (player.dexterity == 8 || player.dexterity == 9) {
			player.dexModifier = -1;
		}
		else if (player.dexterity == 10 || player.dexterity == 11) {
			player.dexModifier = 0;
		}
		else if (player.dexterity == 12 || player.dexterity == 13) {
			player.dexModifier = 1;
		}
		else if (player.dexterity == 14 || player.dexterity == 15) {
			player.dexModifier = 2;
		}
		else if (player.dexterity == 16 || player.dexterity == 17) {
			player.dexModifier = 3;
		}
		else if (player.dexterity == 18 || player.dexterity == 19) {
			player.dexModifier = 4;
		}
		else {
			player.dexModifier = 5;
		}

		if (player.constitution == 8 || player.constitution == 9) {
			player.conModifier = -1;
		}
		else if (player.constitution == 10 || player.constitution == 11) {
			player.conModifier = 0;
		}
		else if (player.constitution == 12 || player.constitution == 13) {
			player.conModifier = 1;
		}
		else if (player.constitution == 14 || player.constitution == 15) {
			player.conModifier = 2;
		}
		else if (player.constitution == 16 || player.constitution == 17) {
			player.conModifier = 3;
		}
		else if (player.constitution == 18 || player.constitution == 19) {
			player.conModifier = 4;
		}
		else {
			player.conModifier = 5;
		}

		if (player.intelligence == 8 || player.intelligence == 9) {
			player.intModifier = -1;
		}
		else if (player.intelligence == 10 || player.intelligence == 11) {
			player.intModifier = 0;
		}
		else if (player.intelligence == 12 || player.intelligence == 13) {
			player.intModifier = 1;
		}
		else if (player.intelligence == 14 || player.intelligence == 15) {
			player.intModifier = 2;
		}
		else if (player.intelligence == 16 || player.intelligence == 17) {
			player.intModifier = 3;
		}
		else if (player.intelligence == 18 || player.intelligence == 19) {
			player.intModifier = 4;
		}
		else {
			player.intModifier = 5;
		}

		if (player.wisdom == 8 || player.wisdom == 9) {
			player.wisModifier = -1;
		}
		else if (player.wisdom == 10 || player.wisdom == 11) {
			player.wisModifier = 0;
		}
		else if (player.wisdom == 12 || player.wisdom == 13) {
			player.wisModifier = 1;
		}
		else if (player.wisdom == 14 || player.wisdom == 15) {
			player.wisModifier = 2;
		}
		else if (player.wisdom == 16 || player.wisdom == 17) {
			player.wisModifier = 3;
		}
		else if (player.wisdom == 18 || player.wisdom == 19) {
			player.wisModifier = 4;
		}
		else {
			player.wisModifier = 5;
		}

		if (player.charisma == 8 || player.charisma == 9) {
			player.chaModifier = -1;
		}
		else if (player.charisma == 10 || player.charisma == 11) {
			player.chaModifier = 0;
		}
		else if (player.charisma == 12 || player.charisma == 13) {
			player.chaModifier = 1;
		}
		else if (player.charisma == 14 || player.charisma == 15) {
			player.chaModifier = 2;
		}
		else if (player.charisma == 16 || player.charisma == 17) {
			player.chaModifier = 3;
		}
		else if (player.charisma == 18 || player.charisma == 19) {
			player.chaModifier = 4;
		}
		else {
			player.chaModifier = 5;
		}
		_getch();

		std::cout << "\nClasses\n";
		std::cout << "--------------------\n";
		std::cout << "0. Quit\n";
		std::cout << "1. Bard\n";
		std::cout << "2. Fighter\n";
		std::cout << "3. Monk\n";
		std::cout << "5. Paladin\n";
		std::cout << "4. Rogue\n";
		std::cout << "6. Wizard\nOR\n";
		std::cout << "7. Change your ancestry.\n";
		std::cout << "\nNow, What is your class?\n(0 - 7)> ";
		while (true) {
			std::cin >> classChoice;
			player.m_WarriorClass == classChoice;
			if (std::cin.fail()) {
				std::cerr << "Sorry, I cannot read that. Please choose a number (0 - 7).\n> ";
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				continue;
			}
			if (ancestryChoice < 0 || ancestryChoice > 8) {
				std::cerr << "Sorry, the number is out of range. Please choose a number (0 - 7).\n> ";
				continue;
			}
			switch (classChoice) {
			case 0:
				std::cout << "Alright, well, I guess we'll see you around.\n\n";
				return 0;
			case BARD:
				std::cout << "\n\nThe charismatic and acrobatic Bard! Hmm, Perhaps you'll play me a song?\n";
				player.attack = 13 + player.strModifier;
				player.speed = 15 + player.dexModifier;
				player.defense = 8 + player.conModifier;
				player.mana = 12 + player.intModifier;
				player.specialAtk = 14 + player.wisModifier;
				player.diplomacy = 16 + player.chaModifier;
				player.maxHp = 10 + player.conModifier;
				break;
			case FIGHTER:
				std::cout << "\n\nThe strong and courageous Fighter! I'll be sure to stay on your good side!\n";
				player.attack = 16 + player.strModifier;
				player.speed = 12 + player.dexModifier;
				player.defense = 14 + player.conModifier;
				player.mana = 8 + player.intModifier;
				player.specialAtk = 10 + player.wisModifier;
				player.diplomacy = 13 + player.chaModifier;
				player.maxHp = 15 + player.conModifier;
				break;
			case MONK:
				std::cout << "\n\nThe swift and enlightened Monk! You'll have to tell me the secret to inner peace!\n";
				player.attack = 13 + player.strModifier;
				player.speed = 16 + player.dexModifier;
				player.defense = 12 + player.conModifier;
				player.mana = 14 + player.intModifier;
				player.specialAtk = 15 + player.wisModifier;
				player.diplomacy = 8 + player.chaModifier;
				player.maxHp = 10 + player.conModifier;
				break;
			case PALADIN:
				std::cout << "\n\nThe noble and mighty Paladin! I feel safer already with you around!\n";
				player.attack = 15 + player.strModifier;
				player.speed = 8 + player.dexModifier;
				player.defense = 16 + player.conModifier;
				player.mana = 12 + player.intModifier;
				player.specialAtk = 14 + player.wisModifier;
				player.diplomacy = 10 + player.chaModifier;
				player.maxHp = 13 + player.conModifier;
				break;
			case ROGUE:
				std::cout << "\n\nThe quickfooted and even quicker witted Rogue! I'll have keep an eye on my purse while you're around!\n";
				player.attack = 14 + player.strModifier;
				player.speed = 16 + player.dexModifier;
				player.defense = 8 + player.conModifier;
				player.mana = 10 + player.intModifier;
				player.specialAtk = 13 + player.wisModifier;
				player.diplomacy = 15 + player.chaModifier;
				player.maxHp = 12 + player.conModifier;
				break;
			case WIZARD:
				std::cout << "\n\nThe mystical and mysterious Wizard! Perhaps you could show me a magic trick?\n";
				player.attack = 12 + player.strModifier;
				player.speed = 13 + player.dexModifier;
				player.defense = 10 + player.conModifier;
				player.mana = 15 + player.intModifier;
				player.specialAtk = 16 + player.wisModifier;
				player.diplomacy = 14 + player.chaModifier;
				player.maxHp = 8 + player.conModifier;
				break;
			} break;
		}
		if (classChoice == 7) {
			std::cout << "\nOh I must have misheard you.";
			continue;
		}
		std::cout << "\n\nSo here is what I've gathered so far.\n\n";
		std::cout << "Your name is: " << player.characterName << "\n";
		std::cout << "\nYour ancestry is: ";

		switch (ancestryChoice) {
		case DWARF:
			std::cout << "Dwarf";
			break;
		case DRAGONBORN:
			std::cout << "Dragonborn";
			break;
		case ELF:
			std::cout << "Elf";
			break;
		case GNOME:
			std::cout << "Gnome";
			break;
		case HALFING:
			std::cout << "Halfling";
			break;
		case HUMAN:
			std::cout << "Human";
			break;
		case ORC:
			std::cout << "Orc";
			break;
		}
		std::cout << "\nYour class is: ";

		switch (classChoice) {
		case BARD:
			std::cout << "Bard";
			break;
		case FIGHTER:
			std::cout << "Fighter";
			break;
		case MONK:
			std::cout << "Monk";
			break;
		case PALADIN:
			std::cout << "Paladin";
			break;
		case ROGUE:
			std::cout << "Rogue";
			break;
		case WIZARD:
			std::cout << "Wizard";
			break;
		}

		std::cout << "\n\nABILITY SCORES\n";
		std::cout << "------------------------------";
		std::cout << "\nSTR: " << player.strength << "\t DEX: " << player.dexterity;
		std::cout << "\nCON: " << player.constitution << "\t INT: " << player.intelligence;
		std::cout << "\nWIS: " << player.wisdom << "\t CHA: " << player.charisma;

		std::cout << "\n\nSTATISTICS\n";
		std::cout << "------------------------------";
		std::cout << "\nHP: " << player.maxHp;
		std::cout << std::left << std::setw(15) << "\nAttack: " << player.attack << std::left << std::setw(15) << "\t Speed: " << player.speed;
		std::cout << std::left << std::setw(15) << "\nDefense: " << player.defense << std::left << std::setw(15) << "\t Mana: " << player.mana;
		std::cout << std::left << std::setw(15) << "\nSpecialAtk: " << player.specialAtk << std::left << std::setw(15) << "\t Diplomacy: " << player.diplomacy;
		std::cout << std::endl << std::endl;

		/*std::cout << "Does that sound about right?\n";
		do {
			std::cout << "(Y/N): ";
			std::cin >> yesNo;
			if (yesNo == 'y' || yesNo == 'Y') {
				std::cout << "\n\nWonderful! Well it's a pleasure to meet you " << player.characterName;
				std::wcout << "\nI hope the adventuring life treats you well!\n\n";
				break;
			}
			else if (yesNo == 'n' || yesNo == 'N') {
				std::cout << "\n\nOh? Well lets start from the top shall we?";
				break;
			}
			else {
				std::cout << "\n\nI'm sorry, I don't understand.";
				continue;
			}
		} while (yesNo != 'y' && yesNo != 'Y');*/

	} while (ancestryChoice == 8 || classChoice == 7) /*|| yesNo == 'N' || yesNo == 'n')*/;
	return 0;
}



int rollStat() {
	return 8 + rand() % 11;
}

