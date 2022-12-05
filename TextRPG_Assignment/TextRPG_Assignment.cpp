// Text RPG Assignment

#include "CharacterCreator.h"
#include "Location.h"
#include "Enemy.h"
#include "Item.h"
#include "TextTools.h"
#include <algorithm>
#include <cstdlib>
#include <iomanip>
#include <limits>
#include <conio.h>
#include <sstream>

int rollStat();
void DisplayInventory(std::vector<Item> inventory);
void DisplayObjectives(std::vector<std::string> objectives);

int main() {
	srand((unsigned)time(NULL));
	Location* currentLocation;
	Character player(8, 8, 8, 8, 8, 8, 10, 10, 15);
	std::vector<Item> PlayerInventory;
	std::vector<Item> MerchantInventory;
	std::vector<Item> GoblinInventory;
	std::vector<std::string> Objectives;
	std::vector<Item>::iterator itemIter;
	std::string name;
	std::string look = "(L)ook";
	std::string interact = "(I)nteract";
	std::string talk = "(T)alk";
	std::string fight = "(F)ight";
	std::string move = "(M)ove";
	char yesNo;
	int playerChoice = 0;
	int ancestryChoice = 0;
	int warriorChoice = 0;


	// build Locations
	Location preachersExterior("Preacher's: Exterior", "A small cottage belonging to the man known as Preacher.", "This small square home is nestled beyond the southern edge of Misty Hollow. It's seems like a safe location to rest.");
	Location preachersInterior("Preacher's: Interior", "The interior of Preacher's Cottage", "You are in a small square room dimly lit by candle light. A table lies in the middle of the room and Preacher sits reading a book in a comfortable chair. A small bedroom lies off to one side through a small doorway.");
	Location oldRoad("The Old Road", "A narrow road leading from Preacher's cottage to Misty Hollow.", "This old road is overgrown with weeds and brush. The forest around you seems to loom around. Its stifling.");
	Location mistyHollowSouth("Misty Hollow: South", "The southern edge of Misty Hollow.", "The town is shrouded in a dense fog. You can just make out a few flickering torches through the squat, packed buildings.");
	Location mistyHollowEast("Misty Hollow: East", "The eastern edge of Misty Hollow.", "The buildings here seem all but abandoned. And there is a strange glow pulsing down an alley.");
	Location mistyHollowWest("Misty Hollow: West", "The western edge of Misty Hollow.", "The squat buildings of the town thin out here as the forest encroaches the boundry.  A toppled guard tower lies in ruin next to the outer wall. A small opening in the wall leads to an old hunter's trail that leads off into the woods.");
	Location mistyHollowNorth("Misty Hollow: North", "The northern edge of Misty Hollow.", "A town gate sits here abandoned by any sort of guards. The rotted boards of the gate hanging limp on rusted hinges. A dirt road leads out of town towards a few farmsteads. You can see a strange glow pulsing in the distance.");
	Location boarsHeadExterior("The Boar's Head Inn: Exterior", "A large dilapidated building in the center of Misty Hollow.", "The roof seems to lean heavily to one side of this two story stone and wood building. Light flickers from behind the windows and you can hear raucus noises coming from within.");
	Location boarsHeadInterior("The Boar's Head Inn: Interior", "The interior of The Boar's Head Inn", "Smells of old food and ale permeate the air within the well lit room. Gruff people crowd the interior talking loudly about current events.");
	Location boarsHeadCellar("The Boar's Head Inn: Cellar", "The cellar of the Boar's Head Inn", "The Cellar door is locked but you can hear a clatter of noises coming from beyond.");
	Location farmRoad("The Farm Road", "A dirt road leading to a few farmsteads", "This dirt road seems to lead out of town passing a few farmsteads on the way. Crows surround the homes that seem abandoned. One farmhouse stands out a strange glow pulsing from the property.");
	Location jeremiahsFarmFront("Jeremiah's Farm", "The farm of a man known as Jeremiah.", "A squat farmhouse sits nestled between rows of dessicated crops. You can see a strange pulsing blue light emanating from behind the farmhouse.");
	Location jeremiahsFarmRear("", "", "");
	Location strangeLight("", "", "");
	Location jeremiahsHomesteadExteriorFront("Jeremiah's Homestead: Exterior Front", "A small home of a man known as Jeremiah.", "The front door of this farmhouse rests partially ajar, and you can hear a rustling within.");
	Location jeremiahsHomesteadExteriorRear("", "", "");
	Location jeremiahsHomesteadInterior("Jeremiah's Homestead: Interior", "", "");
	Location hunterPath("Hunter's Path", "An old hunter's path that leads into the woods.", "This path is overgrown but traversing it shouldn't be too difficult.");
	Location tradersHutExterior("Mysterious Hut", "A strange hut stands in a clearing beyond the edge of the forest.", "The rickety old house stands on what look like giant chicken legs. A rope ladder dangles from the porch to the ground.");
	Location tradersHutInterior("", "", "");
	Location tradersHutBackRoom("", "", "");
	// built exits
	preachersInterior.m_Exits.push_back(&preachersExterior);

	preachersExterior.m_Exits.push_back(&oldRoad);
	preachersExterior.m_Exits.push_back(&preachersInterior);

	oldRoad.m_Exits.push_back(&preachersExterior);
	oldRoad.m_Exits.push_back(&mistyHollowSouth);
	oldRoad.m_Exits.push_back(&hunterPath);

	mistyHollowSouth.m_Exits.push_back(&oldRoad);
	mistyHollowSouth.m_Exits.push_back(&boarsHeadExterior);
	mistyHollowSouth.m_Exits.push_back(&mistyHollowWest);
	mistyHollowSouth.m_Exits.push_back(&mistyHollowEast);

	mistyHollowWest.m_Exits.push_back(&mistyHollowSouth);
	mistyHollowWest.m_Exits.push_back(&mistyHollowNorth);
	mistyHollowWest.m_Exits.push_back(&boarsHeadExterior);
	mistyHollowWest.m_Exits.push_back(&hunterPath);

	mistyHollowNorth.m_Exits.push_back(&boarsHeadExterior);
	mistyHollowNorth.m_Exits.push_back(&mistyHollowEast);
	mistyHollowNorth.m_Exits.push_back(&mistyHollowWest);
	mistyHollowNorth.m_Exits.push_back(&farmRoad);

	hunterPath.m_Exits.push_back(&oldRoad);
	hunterPath.m_Exits.push_back(&tradersHutExterior);
	hunterPath.m_Exits.push_back(&mistyHollowWest);

	tradersHutExterior.m_Exits.push_back(&hunterPath);
	tradersHutExterior.m_Exits.push_back(&tradersHutInterior);

	tradersHutInterior.m_Exits.push_back(&tradersHutExterior);
	tradersHutInterior.m_Exits.push_back(&tradersHutBackRoom);

	boarsHeadExterior.m_Exits.push_back(&mistyHollowEast);
	boarsHeadExterior.m_Exits.push_back(&mistyHollowNorth);
	boarsHeadExterior.m_Exits.push_back(&mistyHollowSouth);
	boarsHeadExterior.m_Exits.push_back(&mistyHollowWest);
	boarsHeadExterior.m_Exits.push_back(&boarsHeadInterior);

	boarsHeadInterior.m_Exits.push_back(&boarsHeadExterior);
	boarsHeadInterior.m_Exits.push_back(&boarsHeadCellar);

	jeremiahsFarmFront.m_Exits.push_back(&farmRoad);
	jeremiahsFarmFront.m_Exits.push_back(&jeremiahsHomesteadExteriorFront);
	jeremiahsFarmFront.m_Exits.push_back(&jeremiahsFarmRear);

	jeremiahsFarmRear.m_Exits.push_back(&jeremiahsFarmFront);
	jeremiahsFarmRear.m_Exits.push_back(&jeremiahsHomesteadExteriorRear);
	jeremiahsFarmRear.m_Exits.push_back(&strangeLight);

	jeremiahsHomesteadExteriorFront.m_Exits.push_back(&jeremiahsFarmFront);
	jeremiahsHomesteadExteriorFront.m_Exits.push_back(&jeremiahsHomesteadInterior);
	jeremiahsHomesteadExteriorFront.m_Exits.push_back(&jeremiahsFarmRear);

	jeremiahsHomesteadExteriorRear.m_Exits.push_back(&jeremiahsFarmRear);
	jeremiahsHomesteadExteriorRear.m_Exits.push_back(&jeremiahsHomesteadExteriorFront);
	jeremiahsHomesteadExteriorRear.m_Exits.push_back(&jeremiahsHomesteadInterior);
	// build Items
	// Weapons
		// junk
	Weapon rustyRapier("Rusty Rapier", "A worn and rusty rapier.\nYou won't be skewering anything but a piece of soft cheese with this thing.\n\nTo Hit: 1d20 + DEX Mod\nDamage: 1d4 + DEX Mod", "Junk", .5, player.GetModifier(player.GetDexterity()), player.RollDice(1, 4) + player.GetModifier(player.GetDexterity()));
	Weapon rustyLongsword("Rusty Longsword", "A worn and rusty Longsword. \nYou could probably cut someone deep with this. Emotionally. If you insult them while you fail to cut them physically. \nTo Hit: 1d20 + STR Mod\nDamage: 1d4 + STR Mod", "Junk", .5, player.GetModifier(player.GetStrength()), player.RollDice(1, 4) + player.GetModifier(player.GetStrength()));
	Weapon rustyDagger("Rusty Dagger", "A worn and rusty Dagger. \nA butter knife is probably sharper \nTo Hit: 1d20 + DEX Mod\nDamage: 1d2 + DEX Mod", "Junk", .2, player.GetModifier(player.GetDexterity()), player.RollDice(1, 2) + player.GetModifier(player.GetDexterity()));
	Weapon rustyWarhammer("Rusty Warhammer", "A worn and rusty Warhammer. \nCareful, you'll get rust in someone's eye when this thing disintegrates on impact. \nTo Hit: 1d20 + STR Mod\nDamage: 1d4 + STR Mod", "Junk", .5, player.GetModifier(player.GetStrength()), player.RollDice(1, 4) + player.GetModifier(player.GetStrength()));
	Weapon splinteredWand("Splintered Wand", "A splintered Wand. \nIt might look like just a stick... But you have to admit, it's a very nice stick. Careful not to get a sliver. \nTo Hit: 1d20 + INT Mod\nDamage: 1d6 + INT Mod", "Junk", .5, player.GetModifier(player.GetIntelligence()), player.RollDice(1, 6) + player.GetModifier(player.GetIntelligence()));
	Weapon brokenLute("Broken Lute", "A cracked lute that is missing a few strings. \nLook, if you can't cast spells through is at least you can use it to bludgeon your enemies to death. \nTo Hit: 1d20 + CHA Mod\nDamage: 1d4 + CHA Mod", "Junk", 1, player.GetModifier(player.GetCharisma()), player.RollDice(1, 4) + player.GetModifier(player.GetCharisma()));
	Weapon bloodyKnuckles("Bloody Knuckles", "Some blood stained brass knuckles. \nYou don't know who's blood that is but at least you know they work. \nTo Hit: 1d20 + DEX Mod\nDamage: 1d2 + DEX Mod", "Junk", .5, player.GetModifier(player.GetDexterity()), player.RollDice(1, 2) + player.GetModifier(player.GetDexterity()));
	// common
	Weapon rapier("Rapier", "A rapier. \nClean metal, sharp point, this will do nicely. \nTo Hit: 1d20 + DEX Mod\nDamage: 1d8 + DEX Mod", "Common", 25, player.GetModifier(player.GetDexterity()), player.RollDice(1, 8) + player.GetModifier(player.GetDexterity()));
	Weapon longsword("Longsword", "A longsword. \nIt's sharp and looks pretty. Just point the sharp part away from you and you'll do fine. \nTo Hit: 1d20 + STR Mod\nDamage: 1d10 + STR Mod", "Common", 25, player.GetModifier(player.GetStrength()), player.RollDice(1, 10) + player.GetModifier(player.GetStrength()));
	Weapon dagger("Dagger", "A dagger. \nGreat for picking your teeth and cleaning your fingernails. Also works good for stabbing. I don't judge. \nTo Hit: 1d20 + DEX Mod\nDamage: 1d4 + DEX Mod", "Common", 2, player.GetModifier(player.GetDexterity()), player.RollDice(1, 4) + player.GetModifier(player.GetDexterity()));
	Weapon warhammer("Warhammer", "A warhammer. \nYou could use it to fix your house, but it's better at smashing femurs. \nTo Hit: 1d20 + STR Mod\nDamage: 1d8 + STR Mod", "Common", 15, player.GetModifier(player.GetStrength()), player.RollDice(1, 8) + player.GetModifier(player.GetStrength()));
	Weapon wand("Wand", "A wand. \nSmooth polished wood. Clean lines. Now your fireballs will be extra spicy. \nTo Hit: 1d20 + INT Mod\nDamage: 1d10 + INT Mod", "Common", 25, player.GetModifier(player.GetIntelligence()), player.RollDice(1, 10) + player.GetModifier(player.GetIntelligence()));
	Weapon lute("Lute", "A lute. \nIt's tuned, the wood is polished, and it has all its strings. You can finally hear the music. \nTo Hit: 1d20 + CHA Mod\nDamage: 1d4 + CHA Mod", "Common", 50, player.GetModifier(player.GetCharisma()), player.RollDice(1, 8) + player.GetModifier(player.GetCharisma()));
	Weapon brassKnuckles("Brass Knuckles", "A pair of brass knuckles. \nYou can feel the weight of them. And they're clean. Now go get some blood on them. \nTo Hit: 1d20 + DEX Mod\nDamage: 1d6 + DEX Mod", "Common", 10, player.GetModifier(player.GetDexterity()), player.RollDice(1, 6) + player.GetModifier(player.GetDexterity()));
	// Rare
	Weapon elvenRapier("Elven Rapier", "An elven rapier. \nYou've never seen a more beautiful Rapier. The subtle off-white colouring, the tasteful thickness of it. It even has a watermark. \nTo Hit: 1d20 + DEX Mod\nDamage: 1d8 + 1d4 + DEX Mod", "Rare", 500, player.GetModifier(player.GetDexterity()), player.RollDice(1, 8) + player.RollDice(1, 4) + player.GetModifier(player.GetDexterity()));
	Weapon commandersLongsword("Commander's Longsword", "A Commander's longsword. \nYou're pretty sure it sings as it cuts through the air. And laughs as it cuts through other things. \nTo Hit: 1d20 + STR Mod\nDamage: 1d10 + 1d6 + STR Mod", "Rare", 500, player.GetModifier(player.GetStrength()), player.RollDice(1, 10) + player.RollDice(1, 6) + player.GetModifier(player.GetStrength()));
	Weapon cutthroatDagger("Cutthroat Dagger", "A Cutthroat's dagger. \nGreat for, well, cutting throats. And so pretty you would probably steal it. If you were into that sort of thing. \nTo Hit: 1d20 + DEX Mod\nDamage: 2d4 + DEX Mod", "Rare", 300, player.GetModifier(player.GetDexterity()), player.RollDice(2, 4) + player.GetModifier(player.GetDexterity()));
	Weapon dwarvenWarhammer("Dwarven Warhammer", "A Dwarven warhammer. \nIt's beautiful, The embossed edges, the gold inlay, the heft of it. Now go smash some skulls \nTo Hit: 1d20 + STR Mod\nDamage: 2d8 + STR Mod", "Rare", 500, player.GetModifier(player.GetStrength()), player.RollDice(2, 8) + player.GetModifier(player.GetStrength()));
	Weapon wizardsWand("Wizard's Wand", "A wizard's wand. \nHow did they get the wood to look like that? I don't know, probably magic. Pretty though. \nTo Hit: 1d20 + INT Mod\nDamage: 1d10 + 1d6 + INT Mod", "Rare", 400, player.GetModifier(player.GetIntelligence()), player.RollDice(1, 10) + player.RollDice(1, 6) + player.GetModifier(player.GetIntelligence()));
	Weapon gibsonLute("Gibson Lute", "A Gibson lute. \nIf you know, you know. \nTo Hit: 1d20 + CHA Mod\nDamage: 1d8 + 1d4 + CHA Mod", "Rare", 750, player.GetModifier(player.GetCharisma()), player.RollDice(1, 8) + player.RollDice(1, 4) + player.GetModifier(player.GetCharisma()));
	Weapon spikedKnuckles("Spiked Knuckles", "A pair of spiked knuckles. \nThey do one thing, and, boy, do they do it well. \nTo Hit: 1d20 + DEX Mod\nDamage: 2d6 + DEX Mod", "Rare", 400, player.GetModifier(player.GetDexterity()), player.RollDice(2, 6) + player.GetModifier(player.GetDexterity()));
	// Armour
	// junk
	Armor wornLeather("Worn Leather", "Some worn leather armour. \nAt least it covers your body. Mostly. There are some holes. A lot of holes.\nAC Bonus: +1\nSTR Score Requirement: 8+", "Junk", 1, 1, -1);
	Armor dentedCuirass("Dented Cuirass", "A dented Cuirass. \nSure the chest is caved in, it still counts as armour.\nAC Bonus: +3\nSTR SCORE Requirement: 14+", "Junk", 1, 3, 2);
	Armor tornRobes("Torn Robes", "A torn robe. \nHonestly a towel would probably offer more protection. But, look on the bright side, at least you will look like you can cast spells in it.\nAC Bonus: 0\nSTR SCORE Requirement: NO", "Junk", 1, 0, -5);
	Armor rustyChainmail("Rusty Chainmail", "Some rusted chainmail. \nSo, most of the chain links are broken, the padding is worn, and the helmet is missing. If you were expecting a 'but' there isn't one.\nAC Bonus: +4\nSTR SCORE Requirement: 16+", "Junk", 2, 4, 3);
	Armor oldUniform("Old uniform", "An old martial arts uniform. \nIt smells like its never been washed and there is stains on it you are pretty sure aren't yours.\nAC Bonus: +1\nSTR SCORE Requirement: 8+", "Junk", .5, 1, -1);
	Armor wornShield("Worn Shield", "A worn and dented shield. \nIt's probably better than nothing.\nAC Bonus: +1\nSTR SCORE Requirement: 14+", "Junk", 1, 1, 2);
	// common
	Armor studdedLeather("Studded Leather", "Some studded leather armour. \nSmells like new leather and the studs are shiny. This is awesome.\nAC Bonus: +2\nSTR SCORE Requirement: 8+", "Common", 50, 2, -1);
	Armor breastplate("Breastplate", "A breastplate. \nIts so shiny you can see your face in it.\nAC Bonus: +4\nSTR SCORE Requirement: 14+", "Common", 100, 4, 2);
	Armor wizardsRobes("Wizard's Robes", "A set of wizard robes. \nThe cloth is soft and is that embroidery? Amazing\nAC Bonus: +1\nSTR SCORE Requirement: NO", "Common", 30, 1, -5);
	Armor scaleMail("Scale Mail", "Some Scalemail. \nThe scales shimmer in the light and best of all, there isn't any holes in it that aren't functional.\nAC Bonus: +5\nSTR SCORE Requirement: 16+", "Common", 200, 5, 3);
	Armor martialArtistsUniform("Martial Artist's Uniform", "The clothes of a matial artist. \nThey're clean. They're pressed. And you think there is even some padding in there.\nAC Bonus: +2\nSTR SCORE Requirement: 8+", "Common", 50, 2, -1);
	Armor buckler("Buckler", "A shield. It's a shield. \nUse it as intended.\nAC Bonus: +2\nSTR SCORE Requirement: 14+", "Common", 10, 2, 2);
	// Rare
	Armor elvenLeather("Elven Leather", "Elven leather armour. \nIf armour could be considered art, you're looking at it. And did it just change colour?\nAC Bonus: +3\nSTR SCORE Requirement: 8+", "Rare", 800, 3, -1);
	Armor draconicBreastplate("Draconic Breastplate", "Draconic breastplate. \nIt looks like a dragon. It. Looks. Like. A. DRAGON.\nAC Bonus: +4\nSTR SCORE Requirement: 14+", "Rare", 1000, 5, 2);
	Armor robeOfTheArchmage("Robe of the Archmage", "Archmage Robes. \nUNLIMITED POWER!!!!\nAC Bonus: +2\nSTR SCORE Requirement: NO", "Rare", 800, 2, -5);
	Armor dwarvenPlate("Dwarven Plate", "Dwarven Plate Armour. \nDid you ever want to be Iron Man? Well this armour is for you.\nAC Bonus: +6\nSTR SCORE Requirement: 16+", "Rare", 1500, 6, 3);
	Armor mastersRobe("Master's Robes", "The clothes of a Master. \nSo this is what inner peace feels like.\nAC Bonus: +3\nSTR SCORE Requirement: 8+", "Rare", 800, 3, -1);
	Armor kiteShield("Kite Shield", "More shield. More protection.\nAC Bonus: +3\nSTR SCORE Requirement: 14+", "Rare", 300, 3, 2);
	//Items
	Item waterskin("Waterskin", "A waterskin filled with water.", "Common", .1);

	Item goldPouch("Gold Pouch", "A pouch full of gold.", "Common", 100);

	// healing Items
	HealingPotion bread("Fresh Bread", "Some fresh bread. It smells good", "Common", 1, 5);
	HealingPotion rations("Rations", "Rations of food for the road. Looks better than it tastes and it does not look good.", "Common", .2, 2);
	HealingPotion ale("Pint of Ale", "A pint of ale. Its foamy and looks pretty good.", "Common", 1, 3);
	HealingPotion cheese("A wheel of cheese", "A wheel of cheese. It seems fresh. Great with bread.", "Common", 10, 10);
	HealingPotion healingpotion("Healing potion", "A vial of red liquid. It smells faintly of elderberries.", "Rare", 100, 25);
	//Useable Items
	UseableItems rope("Rope", "A length of rope. Very useful.", "Common", 1, "Use: to climb up or down something.");
	UseableItems bed("Bed", "A bed.", "Common", 50, "Use: for sleeping");
	UseableItems door("Door", "A door.", "Common", 20, "Use: Its a door");
	UseableItems chest("Chest", "A chest.", "Common", 100, "Use: It holds things");
	UseableItems oldKey("Old Key", "An old key found on Jeremiah's body.", "Uncommon", 1, "Use: Its a key. Find the keyhole it goes to.");
	UseableItems chestKey("Chest Key", "A key to a chest.", "Common", 1, "Use: It's a key. Find the keyhole it goes to.");
	UseableItems oldChest("Old Chest", "An old chest. Its wood is warped and it hinges rusty. You'll probably need a crowbar to open it", "Uncommon", 100, "Use: You can hear something inside");
	//build enemies
	Enemy corruptedDog("Strange Dog", "A angry and mangy looking dog. There are bulbous protrusions sticking out of its flesh. Something seems to writhe beneath the skin.", 12, 14, 9, 2, 10, 4, 10, 13, 0);
	Enemy huskOfJeremiah("Jeremiah", "What remains of the farmer Jeremiah. Three dark, slick tentacles protrude from where his head once was.", 15, 11, 13, 9, 12, 6, 27, 13, 50);
	Enemy corruptedFarmhand("Corrupted Farmhand", "What appears to have once been a farmhand. Black tentacles have torn out of its body. It hold a bloody sickle in one hand.", 12, 9, 12, 7, 11, 6, 16, 13, 10);
	Enemy corruptedPlowHorse("Corrupted Plow Horse", "A black plow horse whinnies angrily. Its skin seems to writhe beneath the fur.", 16, 12, 16, 2, 12, 5, 32, 12, 0);
	Enemy goblin("Goblin Bandit", "A goblin bandit. It is brandishing a dagger.", 8, 16, 12, 8, 14, 10, 7, 15, 20);
	Enemy goblinCaptain("Goblin Captain", "A larger goblin. He is wearing armor and brandishing a longsword.", 10, 18, 14, 8, 16, 10, 21, 16, 200);

	preachersInterior.m_InteractableItems.push_back(&bed);
	preachersInterior.m_InteractableItems.push_back(&chest);

	preachersExterior.m_Items.push_back(&rustyLongsword);
	preachersExterior.m_Items.push_back(&goldPouch);

	oldRoad.m_Enemies.push_back(&corruptedDog);
	oldRoad.m_Items.push_back(&oldChest);

	hunterPath.m_Enemies.push_back(&goblin);
	hunterPath.m_Enemies.push_back(&goblin);
	hunterPath.m_Enemies.push_back(&goblin);
	hunterPath.m_Enemies.push_back(&goblinCaptain);

	std::cout << std::right << std::setw(50) << "MISTY HOLLOW\n\n";
	std::cout << std::right << std::setw(58) << "A game by Trevor Turner\n\n\n";
	std::cout << "Press any key to continue\n";
	_getch();
	std::cout << "\n[1] NEW GAME";
	std::cout << "\n[2] QUIT\n";
	askNumber("Choose a Number: ", 2, 1);
	std::cin >> playerChoice;
	switch (playerChoice) {
	case 1:
		std::cout << "\nYour eyes open slowly. Your head is throbbing and you can feel a dampness to your clothing.\n";
		std::cout << "[1] Look";
		std::cout << "[2] Interact";
		std::cout << "[3] Talk";
		askNumber("> ", 3, 1);
		std::cin >> playerChoice;
		do {
			switch (playerChoice) {
			case 1:
				std::cout << "\nYou are in a small room lit dimly with flickering candlelight, laying on a wooden table.\n";
				_getch();
				std::cout << "The smells of antiseptic and iron are thick in the air.\n";
				_getch();
				std::cout << "A man sits near you reading a book.\n";
				_getch();
				std::cout << "He looks to you when your eyes flutter open.\n";
				do {
					std::cout << "[1] Look";
					std::cout << "[2] Interact";
					std::cout << "[3] Talk";
					askNumber("> ", 3, 1);
					std::cin >> playerChoice;

					switch (playerChoice) {
					case 1:
						std::cout << "\nHe appears to be in his mid to late fifties with deep, sunken eyes and a greying beard.\n";
						std::cout << "He smiles at you as you look at him.\n";
						continue;
					case 2:
						break;
					case 3:
						break;
					}
				} while (playerChoice != 2 || playerChoice != 3);
			case 2:
				std::cout << "\nYou try to move but your arms are heavy. Someone reaches out and grabs your arm, assiting you.\n";
				break;
			case 3:
				std::cout << "\nYou try and speak, a raspy, hollow sound coming from your mouth.\n";
				break;
			}
		} while (playerChoice != 2 || playerChoice != 3);
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
				do {
					player.SetStrength(8);
					player.SetDexterity(8);
					player.SetConstitution(8);
					player.SetIntelligence(8);
					player.SetWisdom(8);
					player.SetCharisma(8);
					player.SetMaxHP(10);
					player.SetArmorClass(10);
					player.SetCharacterGold(15);
					PlayerInventory.clear();
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
					askNumber("What is your Ancestry: ", 8, 1);
					std::cin >> ancestryChoice;

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
					case 8:
						std::cout << "\n\nPreacher: Oh. I'm sorry I must have misheard you. What is your name?\n";
						std::cout << "> ";
						std::cin >> name;
						player.SetPlayerName(name);
						continue;
					}
				} while (ancestryChoice == 8);

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
				askNumber("What is your class? ", 7, 0);
				std::cin >> warriorChoice;

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
					PlayerInventory.push_back(rustyRapier);
					PlayerInventory.push_back(brokenLute);
					PlayerInventory.push_back(wornLeather);
					PlayerInventory.push_back(waterskin);
					PlayerInventory.push_back(rations);
					PlayerInventory.push_back(rope);
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
					PlayerInventory.push_back(rustyWarhammer);
					PlayerInventory.push_back(dentedCuirass);
					PlayerInventory.push_back(wornShield);
					PlayerInventory.push_back(waterskin);
					PlayerInventory.push_back(rations);
					PlayerInventory.push_back(rope);
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
					PlayerInventory.push_back(bloodyKnuckles);
					PlayerInventory.push_back(oldUniform);
					PlayerInventory.push_back(waterskin);
					PlayerInventory.push_back(rations);
					PlayerInventory.push_back(rope);
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
					PlayerInventory.push_back(rustyLongsword);
					PlayerInventory.push_back(rustyChainmail);
					PlayerInventory.push_back(wornShield);
					PlayerInventory.push_back(waterskin);
					PlayerInventory.push_back(rations);
					PlayerInventory.push_back(rope);
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
					PlayerInventory.push_back(rustyRapier);
					PlayerInventory.push_back(wornLeather);
					PlayerInventory.push_back(rustyDagger);
					PlayerInventory.push_back(waterskin);
					PlayerInventory.push_back(rations);
					PlayerInventory.push_back(rope);
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
					PlayerInventory.push_back(splinteredWand);
					PlayerInventory.push_back(tornRobes);
					PlayerInventory.push_back(rustyDagger);
					PlayerInventory.push_back(waterskin);
					PlayerInventory.push_back(rations);
					PlayerInventory.push_back(rope);
					break;
				case 7:
					std::cout << "\nOh I must have misheard you.";
					continue;
				} break;
			} while (warriorChoice == 7);
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

			std::cout << "\n\nDo I have everything right?";
			do {
				std::cout << "\n(y/n)> ";
				std::cin >> yesNo;
				if (yesNo == 'y' || yesNo == 'Y') {
					std::cout << "\nPreacher: Ah, well it seems to me that there is no lasting damage. Your memory is working just fine.\n\n";
					break;
				}
				else if (yesNo == 'n' || yesNo == 'N') {
					std::cout << "\nPreacher: Hmm, perhaps we should start from the top.\n\n";
					break;;
				}
				else {
					std::cout << "\nPreacher: Terribly sorry, I do not understand. Perhaps you do have some brain damage.";
					continue;
				}
			} while (yesNo != 'Y' || yesNo != 'y' && yesNo != 'N' || yesNo != 'n');

		} while (yesNo == 'N' || yesNo == 'n');

		std::cout << "\nPreacher: Now that that is settled, I'm sure you have questions.\n";
		_getch();

		currentLocation = &preachersInterior;

		do {
			std::cout << std::endl << currentLocation->m_Name << "\n--------------------------\n";
			std::cout << currentLocation->m_ShortDescription << std::endl;
			do {
				std::cout << "[1] Look";
				std::cout << "[2] Interact";
				std::cout << "[3] Talk";
				std::cout << "[4] Move";
				askNumber("> ", 4, 1);
				std::cin >> playerChoice;
				std::vector<std::string>::iterator iter;
				iter = std::find(Objectives.begin(), Objectives.end(), Objectives);
				switch (playerChoice) {
				case 1:
					std::cout << "\n" << currentLocation->m_LongDescription << "\n";
					break;
				case 2:
					do {
						currentLocation->DisplayInteractableItems();
						std::cout << "[2] Back";
						askNumber("Choose a number: ", 2, 0);
						std::cout << "> ";
						std::cin >> playerChoice;
						switch (playerChoice) {
						case 0:
							std::cout << "\n\nYou rest.\n";
							player.SetHP(player.GetMaxHP());
							std::cout << player.GetHP();
							std::cout << "You are fully healed\n\n";
							break;
						case 1:
							itemIter = std::find(PlayerInventory.begin(), PlayerInventory.end(), chestKey);
							if (itemIter == PlayerInventory.end()) {
								std::cout << "\n\nYou try to open the chest. It's locked.";
								std::cout << "\nPreacher: Oh I lost the key for that thing ages ago. If you find it, you can have whats inside.";
							}
							else {
								std::cout << "\n\nYou place the chest key into the keyhole. The lock falls away!";
								std::cout << "\nItems collected!";
								PlayerInventory.push_back(longsword);
								PlayerInventory.push_back(rapier);
								PlayerInventory.push_back(buckler);
								PlayerInventory.push_back(healingpotion);
							}
							break;
						case 2:
							break;
						}
					} while (playerChoice != 2);
				case 3:
					do {
						std::cout << "\nPreacher: Yes?\n";
						std::cout << "\n\n[0] Good-bye, Preacher.";
						std::cout << "\n[1] Where am I?";
						std::cout << "\n[2] Who are you?";
						std::cout << "\n[3] What happened to me?";
						std::cout << "\n[4] Where is my equipment?";
						askNumber("Choose a number: ", 4, 0);
						std::cin >> playerChoice;
						switch (playerChoice) {
						case 0:
							std::cout << "Good-bye " << player.GetName() << ", until next time.";
							std::cout << "If you ever need a rest, feel free to return here. My door is always open.";
							break;
						case 1:
							std::cout << "\n\nPreacher: You are in a small town known as Misty Hollow.\n";
							std::cout << "Preacher: It was a quiet place once, but we've had nothing but problems of late. Ever since... the incident.\n\n";
							std::cout << "[0] Back\n";
							std::cout << "[1] Incident?\n";
							askNumber("> ", 1, 0);
							std::cin >> playerChoice;
							switch (playerChoice) {
							case 0:
								break;
							case 1:
								std::cout << "\n\nYes. Something fell out of the sky over near Jerimiah's farm. A large glowing rock of some kind. Since then there has been strange going ons.\n";
								std::cout << "\nThe folks in town will have more information. Why don't you head to The Boar's Head Inn if you're curious.\n\n";
								Objectives.push_back("Head to The Boars Head Inn in Misty Hollow and speak with the villagers.");
								Objectives.push_back("Investigate Jeremiah's farm");
								DisplayObjectives(Objectives);
								break;
							}
						case 2:
							std::cout << "\nI am Reverend Dorian. You can call me Preacher. I am a what this town has for a cleric.";
							break;
						case 3:
							std::cout << "\nI'm not sure. I found you lying on the old Hunter path with a nasty head wound. We have had problems with goblin's recently.\n\n";
							Objectives.push_back("Investigate the hunter's path");
							Objectives.push_back("Deal with the goblins");
							DisplayObjectives(Objectives);
							break;
						case 4:
							std::cout << "\n\nIt is here.\n";
							std::cout << "[0] Back.\n";
							std::cout << "[1] Collect.\n";
							askNumber("> ", 1, 0);
							std::cin >> playerChoice;
							switch (playerChoice) {
							case 0:
								break;
							case 1:
								std::cout << "Items Collected!\n\n";
								DisplayInventory(PlayerInventory);
								break;
							}
							break;
						}
					} while (playerChoice != 0);
				case 4:
					currentLocation->DisplayExits();
					std::cout << "[1] Back";
					askNumber("Where would you like to go?", 0, 1);
					std::cin >> playerChoice;
					switch (playerChoice) {
					case 0:
						currentLocation = currentLocation->m_Exits[playerChoice];
						break;
					case 1:
						break;
					}
				} 
					break;
			} while (playerChoice != 4);
		}while (playerChoice != 4);
	case 2:
		return 0;
	}
	return 0;
}
	





int rollStat() {
	return 8 + rand() % 11;
}

void DisplayInventory(std::vector<Item> inventory) {
	std::cout << std::endl << "Inventory" << std::endl;
	std::cout << "-----------------------------------" << std::endl;
	std::cout << std::left << std::setw(30) << "Item Name" << std::left << std::setw(12) << "Rarity"; 
	std::cout << std::right << std::setw(12) << "Value\n\n";
	std::vector<Item>::iterator iter;
	for (iter = inventory.begin(); iter < inventory.end(); ++iter ) {
		std::cout << std::left << std::setw(30) << iter->GetItemName() << std::left << std::setw(12) << iter->GetItemRarity();
		std::cout << std::right << std::setw(12) << iter->GetItemValue() << "\n\nDescription: " << iter->GetItemDescription() << std::endl << std::endl;
	}
}

void DisplayObjectives(std::vector<std::string> objectives) {
	std::cout << std::endl << "Objectives" << std::endl;
	std::cout << "-------------------------------------" << std::endl;
	for (int i = 0; i < objectives.size(); ++i) {
		std::cout << objectives[i] << std::endl;
	}
}