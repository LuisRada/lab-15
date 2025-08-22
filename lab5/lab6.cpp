#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

enum CharacterClass { WARRIOR, MAGE, ROGUE, ARCHER, CLERIC };
enum ItemType { SWORD, SHIELD, POTION, ARMOR, BOW };

class Character {
public:
    string name;
    int strength, dexterity, endurance, intelligence, charisma;
    CharacterClass characterClass;
    
    Character(string n, int str, int dex, int endu, int intl, int cha, CharacterClass cls)
        : name(n), strength(str), dexterity(dex), endurance(endu), intelligence(intl), charisma(cha), characterClass(cls) {}

    ~Character() {
        cout << "Character " << name << " deleted." << endl;
    }

    void save() {
        ofstream file((name + ".txt").c_str());
        if (file.is_open()) {
            file << name << endl;
            file << strength << endl;
            file << dexterity << endl;
            file << endurance << endl;
            file << intelligence << endl;
            file << charisma << endl;
            file << characterClass << endl;
            file.close();
            cout << "Character saved to " << name << ".txt" << endl;
        } else {
            cerr << "Unable to open file for writing." << endl;
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
            cerr << "Unable to open file for reading." << endl;
            return nullptr;
        }
    }

    void display() {
        cout << "Name: " << name << endl;
        cout << "Strength: " << strength << endl;
        cout << "Dexterity: " << dexterity << endl;
        cout << "Endurance: " << endurance << endl;
        cout << "Intelligence: " << intelligence << endl;
        cout << "Charisma: " << charisma << endl;
        cout << "Class: " << characterClass << endl;
    }
};

class Inventory {
public:
    string itemName;
    ItemType itemType;
    int quantity;
    double weight;
    string description;

    Inventory(string name, ItemType type, int qty, double wt, string desc)
        : itemName(name), itemType(type), quantity(qty), weight(wt), description(desc) {}

    ~Inventory() {
        cout << "Inventory item " << description << " deleted." << endl;
    }

    void displayItem() {
        cout << "Item: " << description << endl;
        cout << "Type: " << itemType << endl;
        cout << "Quantity: " << quantity << endl;
        cout << "Weight: " << weight << " kg" << endl;
    }
};

void createCharacter(Character*& character) {
    string name;
    int strength, dexterity, endurance, intelligence, charisma, cls;
    cout << "Enter character name: ";
    cin >> name;
    cout << "Enter strength: ";
    cin >> strength;
    cout << "Enter dexterity: ";
    cin >> dexterity;
    cout << "Enter endurance: ";
    cin >> endurance;
    cout << "Enter intelligence: ";
    cin >> intelligence;
    cout << "Enter charisma: ";
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
    if (character)
        character->display();
}

void deleteCharacter(Character*& character) {
    string filename;
    cout << "Enter character filename to delete: ";
    cin >> filename;

    if (remove(filename.c_str()) == 0) {
        cout << "Character file " << filename << " deleted successfully." << endl;
    } else {
        cerr << "Error: Could not delete file. File may not exist." << endl;
    }

    delete character;
    character = nullptr;
}

void manageInventory() {
    vector<Inventory*> items;
    int choice;
    do {
        cout << "\n1. Display Inventory\n2. Add Items\n3. Clear Inventory\n4. Exit" << endl;
        cin >> choice;
        
        switch (choice) {
            case 1:
                if (items.empty()) {
                    cout << "Inventory is empty." << endl;
                } else {
                    for (size_t i = 0; i < items.size(); i++) {
                        cout << "Item " << i+1 << ":" << endl;
                        items[i]->displayItem();
                    }
                }
                break;
                
            case 2: {
                int itemChoice;
                cout << "Select item type to add:" << endl;
                cout << "0. SWORD\n1. SHIELD\n2. POTION\n3. ARMOR\n4. BOW" << endl;
                cin >> itemChoice;
                int qty;
                cout << "Enter quantity to add: ";
                cin >> qty;
                string desc;
                double wt;
                switch(itemChoice) {
                    case 0: desc = "Sword"; wt = 3.0; break;
                    case 1: desc = "Shield"; wt = 5.0; break;
                    case 2: desc = "Health Potion"; wt = 0.5; break;
                    case 3: desc = "Armor"; wt = 10.0; break;
                    case 4: desc = "Bow"; wt = 2.5; break;
                    default: desc = "Unknown"; wt = 0.0; break;
                }
                Inventory* newItem = new Inventory(desc, static_cast<ItemType>(itemChoice), qty, wt, desc);
                items.push_back(newItem);
                cout << qty << " " << desc << "(s) added to inventory." << endl;
                break;
            }
                
            case 3:
                for (size_t i = 0; i < items.size(); i++) {
                    delete items[i];
                }
                items.clear();
                cout << "Inventory cleared." << endl;
                break;
                
            case 4:
                cout << "Exiting inventory management." << endl;
                break;
                
            default:
                cout << "Invalid choice. Try again." << endl;
                break;
        }
        
    } while (choice != 4); 

    
    for (size_t i = 0; i < items.size(); i++) {
        delete items[i];
    }
    items.clear();
}


int main() {
    Character* character = nullptr;
    int choice;
    
    cout << "1. Create new character\n2. Load character\n3. Delete character\nEnter your choice: ";
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
            return 0;
        default:
            cout << "Invalid choice." << endl;
            return 0;
    }

    int nextChoice;
    cout << "\n1. Manage Inventory\n2. Exit the Game\nEnter your choice: ";
    cin >> nextChoice;

    if (nextChoice == 1) {
        manageInventory();
    }

    delete character;
    return 0;
}
