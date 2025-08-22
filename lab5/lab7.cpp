#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>
using namespace std;

enum CharacterClass { WARRIOR, MAGE, ROGUE, ARCHER, CLERIC };
enum ItemType { SWORD, SHIELD, POTION, ARMOR, BOW };

class Inventory;

class Character {
private:
    string name;
    int strength, dexterity, endurance, intelligence, charisma;
    CharacterClass characterClass;
    Character() : name(""), strength(), dexterity(), endurance(), intelligence(), charisma(), characterClass() {}
public:
    Character(string n, int str, int dex, int endu, int intl, int cha, CharacterClass cls)
        : name(n), strength(str), dexterity(dex), endurance(endu), intelligence(intl), charisma(cha), characterClass(cls) {}
    ~Character() {
        cout << "Character " << name << " deleted.\n";
    }
    void save() {
        ofstream file((name + ".txt").c_str());
        if (file.is_open()) {
            file << name << '\n' << strength << '\n' << dexterity << '\n' << endurance << '\n'
                 << intelligence << '\n' << charisma << '\n' << characterClass << '\n';
            file.close();
            cout << "Character saved successfully.\n";
        } else {
            cerr << "Error saving character.\n";
        }
    }
    static Character* load(const string& filename) {
        ifstream file(filename.c_str());
        if (file.is_open()) {
            string name;
            int str, dex, endu, intl, cha, cls;
            file >> name >> str >> dex >> endu >> intl >> cha >> cls;
            file.close();
            return new Character(name, str, dex, endu, intl, cha, static_cast<CharacterClass>(cls));
        } else {
            cerr << "Error loading character.\n";
            return nullptr;
        }
    }
    void display() const {
        cout << "Name: " << name << "\nStrength: " << strength << "\nDexterity: " << dexterity 
             << "\nEndurance: " << endurance << "\nIntelligence: " << intelligence 
             << "\nCharisma: " << charisma << "\nClass: " << characterClass << endl;
    }
    friend void boostStrength(Character&, int);
    friend void resetCharacter(Character&);
    friend void displayCharacterAndInventory(Character&, Inventory&);
    friend class InventoryManager;
    friend void createCharacter(Character*&);
    friend void loadCharacter(Character*&);
    friend void deleteCharacter(Character*&);
};

class Inventory {
private:
    string itemName;
    ItemType itemType;
    int quantity;
    double weight;
    string description;
    Inventory(string name, ItemType type, int qty, double wt, string desc)
        : itemName(name), itemType(type), quantity(qty), weight(wt), description(desc) {}
public:
    ~Inventory() {
        cout << "Inventory item " << description << " deleted.\n";
    }
    void displayItem() const {
        cout << "Item: " << description << "\nType: " << itemType
             << "\nQuantity: " << quantity << "\nWeight: " << weight << " kg\n";
    }
    friend class InventoryManager;
    friend void manageInventory(Inventory&);
    friend void displayCharacterAndInventory(Character&, Inventory&);
    static Inventory* createInventory(string name, ItemType type, int qty, double wt, string desc) {
        return new Inventory(name, type, qty, wt, desc);
    }
};

void boostStrength(Character& c, int amount) {
    c.strength += amount;
    cout << c.name << "'s strength increased by " << amount << ".\n";
    c.dexterity += amount;
    cout << c.name << "'s dexterity increased by " << amount << ".\n";
    c.endurance += amount;
    cout << c.name << "'s endurance increased by " << amount << ".\n";
    c.intelligence += amount;
    cout << c.name << "'s intelligence increased by " << amount << ".\n";
    c.charisma += amount;
    cout << c.name << "'s charisma increased by " << amount << ".\n";
}

void resetCharacter(Character& c) {
    c.strength = c.dexterity = c.endurance = c.intelligence = c.charisma = 1;
    cout << c.name << "'s stats have been reset.\n";
}

void displayCharacterAndInventory(Character& c, Inventory& i) {
    c.display();
    i.displayItem();
}

class InventoryManager {
public:
    static void addItem(Inventory& i, int qty) {
        i.quantity += qty;
        cout << qty << " " << i.description << "(s) added to inventory.\n";
    }
};

void createCharacter(Character*& character) {
    string name;
    int strength, dexterity, endurance, intelligence, charisma, cls;
    cout << "Enter character name: ";
    cin >> name;
    cout << "Enter strength (1-100): ";
    cin >> strength;
    cout << "Enter dexterity (1-100): ";
    cin >> dexterity;
    cout << "Enter endurance (1-100): ";
    cin >> endurance;
    cout << "Enter intelligence (1-100): ";
    cin >> intelligence;
    cout << "Enter charisma (1-100): ";
    cin >> charisma;
    cout << "Enter class (0=WARRIOR, 1=MAGE, 2=ROGUE, 3=ARCHER, 4=CLERIC): ";
    cin >> cls;
    character = new Character(name, strength, dexterity, endurance, intelligence, charisma, static_cast<CharacterClass>(cls));
    character->save();
}

void loadCharacter(Character*& character) {
    string filename;
    cout << "Enter character filename: ";
    cin >> filename;
    character = Character::load(filename);
    if (character) character->display();
}

void deleteCharacter(Character*& character) {
    delete character;
    character = nullptr;
    cout << "Character deleted successfully.\n";
}

void manageInventory(Inventory& inventory) {
    int choice;
    do {
        cout << "\n1. Display Inventory\n2. Add Items\n3. Exit\nChoice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                inventory.displayItem();
                break;
            case 2: {
                int qty;
                cout << "Enter quantity to add: ";
                cin >> qty;
                InventoryManager::addItem(inventory, qty);
                break;
            }
        }
    } while (choice != 3);
}

int main() {
    Character* character = nullptr;
    Inventory* inventory = Inventory::createInventory("Sword", SWORD, 1, 3.0, "A sharp blade");
    int choice;
    while (true) {
        cout << "\n--- Main Menu ---\n1. Create Character\n2. Load Character\n3. Delete Character\n4. Boost Stats\n5. Reset Stats\n6. Manage Inventory\n7. Display Character & Inventory\n8. Exit\nChoice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                createCharacter(character);
                break;
            case 2:
                loadCharacter(character);
                break;
            case 3:
                deleteCharacter(character);
                break;
            case 4:
                if (character) boostStrength(*character, 5);
                else cout << "No character loaded.\n";
                break;
            case 5:
                if (character) resetCharacter(*character);
                else cout << "No character loaded.\n";
                break;
            case 6:
                manageInventory(*inventory);
                break;
            case 7:
                if (character) displayCharacterAndInventory(*character, *inventory);
                else cout << "No character loaded.\n";
                break;
            case 8:
                deleteCharacter(character);
                delete inventory;
                return 0;
            default:
                cout << "Invalid choice.\n";
        }
    }
}
