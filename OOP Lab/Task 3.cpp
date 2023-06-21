#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <cstring>
#include<string>

using namespace std;

class MyString {
public:
    char* cstr;
    int size;
    MyString()
    {
        size = 0;
        cstr = nullptr;
    }
    MyString(const string s)
    {
        size = s.length();
        cstr = new char[size + 1];
        strcpy(cstr, s.c_str());
    }

};
class Gun {
public:
    int ID;
    MyString title;
    int bulletCapacity;
    int noOfBullets;
    double fireSpeed;
    int damagePerBullet;
    Gun()
    {
        ID = 0;
        title;
        bulletCapacity = 0;
        fireSpeed = 0;
        damagePerBullet = 0;
        noOfBullets = 0;
    }
    Gun(int _ID, MyString _title, int _bulletCapacity, double _fireSpeed, int _damagePerBullet)
    {
        ID = _ID;
        title = _title;
        bulletCapacity = _bulletCapacity;
        fireSpeed = _fireSpeed;
        damagePerBullet = _damagePerBullet;
        noOfBullets = bulletCapacity;
    }
    void displayInfo()
    {
        cout << "Gun Id = " << ID << ", Title = " << title.cstr << ", BulletCapacity = " << bulletCapacity <<
            ", number of bullets = " << noOfBullets << ", Fire Speed = " << fireSpeed << ", Damage Per Bullet = " << damagePerBullet << endl;
    }
    void reload()
    {
        noOfBullets = bulletCapacity;
    }
    void fire()
    {
        noOfBullets--;
        if (noOfBullets < 0) noOfBullets = 0;
    }
};
class Player {
public:
    MyString userName;
    int health;
    Gun* Guns = new Gun[3];
    int activeGun;
    int totalPickedGun;
    Player() 
    {
        health = 0;
        activeGun = 0;
        totalPickedGun = 0;
    }
    Player(MyString _uName, int _health, int _activeGun)
    {
        userName = _uName;
        health = _health;
        activeGun = _activeGun;
        totalPickedGun = 0;
    }
    void fireTarget(Player& enemy)
    {
        Guns[activeGun].fire();
        enemy.health = enemy.health - Guns[activeGun].damagePerBullet;
    }
    void fireTarget()           //Random shots, No target
    {
        Guns[activeGun].fire();
    }
    void displayInfo()
    {
        cout << "User Name: " << userName.cstr << ", Health = " << health << ", ActiveGun = " << activeGun << endl;
        cout << "This Player's Gun info : " << endl;
        for (int i = 0; i < totalPickedGun; i++)
        {
            Guns[i].displayInfo();
        }
        cout << endl;
    }
    void receiveDamage(int damage)
    {
        health -= damage;
        if (health <= 0)
        {
            health = 0;
            this->~Player();
        }
    }
    void changeActiveGun(int activeGunNumber)
    {
        activeGun = activeGunNumber;
    }
    void exchangeGun(int oldGunId, Gun newGun)
    {
        for (int i = 0; i < 3; i++)
        {
            if (Guns[i].ID == oldGunId) {
                Guns[i] = newGun;
                return;
            }
        }
        //If no gun with the Id found we changed the first Gun
        Guns[0] = newGun;

    }
    void PickGun(Gun newGun)
    {
        if (totalPickedGun >= 3) return;
        Guns[totalPickedGun] = newGun;
        totalPickedGun++;
    }
    ~Player()
    {
        delete[] Guns;
    }
};
class Inventory {
public:
    Gun* gun = new Gun[100];
    bool gunStatus[100];
    int gunCount;
    Inventory()
    {
        for (int i = 0; i < 100; i++)
        {
            gunStatus[i] = 0;
        }
        gunCount = 0;
    }
    void addGun(Gun newGun)
    {
        gun[gunCount] = newGun;
        gunStatus[gunCount] = true;
        gunCount++;
    }
    Gun giveGun()
    {
        gunCount--;
        gunStatus[gunCount] = 0;
        return gun[gunCount];
    }
};

int main()
{
    //We will First Add some dummy guns to Inventory to check the correctness of program
    Gun gun1 = Gun(1, MyString("Gun-1"), 16, 9.8, 2);
    Gun gun2 = Gun(2, MyString("Gun-2"), 100, 4.8, 1);
    Gun gun3 = Gun(3, MyString("Gun-3"), 19, 45.9, 3);
    Gun gun4 = Gun(4, MyString("Gun-4"), 37, 5.2, 2);
    Gun gun5 = Gun(5, MyString("Gun-5"), 50, 2.2, 2);
    Gun gun6 = Gun(6, MyString("Gun-6"), 6, 5.2, 3);

    Inventory inventory = Inventory();

    inventory.addGun(gun1);
    inventory.addGun(gun2);
    inventory.addGun(gun3);
    inventory.addGun(gun4);
    inventory.addGun(gun5);
    inventory.addGun(gun6);

    //Task 1.1
    cout << "-------------Task 1.1-----------------------------------------------------------------" << endl;
    cout << "The information of inventory is ---------------------------" << endl;
    for (int i = 0; i < inventory.gunCount; i++)
    {
        inventory.gun[i].displayInfo();
    }
    cout << endl;

    //Task 1.2
    cout << "--------------Task 1.2-----------------------------------------------------------------" << endl;
    Player P1(MyString("Player-1"), 100, -1), P2(MyString("Player-2"), 30, -1);

    //P1 will first 3 guns from inventory
    P1.PickGun(inventory.giveGun());
    P1.PickGun(inventory.giveGun());
    P1.PickGun(inventory.giveGun());

    //Now P2 will pick 3 guns from inventory
    P2.PickGun(inventory.giveGun());
    P2.PickGun(inventory.giveGun());
    P2.PickGun(inventory.giveGun());

    cout << "Player 1 info : -----------------------------------" << endl;
    P1.displayInfo();
    cout << endl;
    cout << "Player 2 info : -----------------------------------" << endl;
    P2.displayInfo();
    cout << endl;

    //Task 1.3
    cout << "---------Task 1.3-----------------------------------------------------------------" << endl;
    //Now 2 shoots from each gun by Player 1
    P1.changeActiveGun(0);
    P1.fireTarget(P2);
    P1.fireTarget(P2);


    P1.changeActiveGun(1);
    P1.fireTarget(P2);
    P1.fireTarget(P2);

    P1.changeActiveGun(2);
    P1.fireTarget(P2);
    P1.fireTarget(P2);

    //Now 1 shoot from each gun by Player 2
    P2.changeActiveGun(0);
    P2.fireTarget(P1);

    P2.changeActiveGun(1);
    P2.fireTarget(P1);

    P2.changeActiveGun(2);
    P2.fireTarget(P1);

    cout << "After Firing each other (Task 1.3), The information of each player is : " << endl;
    P1.displayInfo();
    cout << endl;
    P2.displayInfo();
    cout << endl;

    //Task 1.4
    cout << "-------------------Task 1.4-----------------------------------------------------------------" << endl;
    while (P2.health > 0)
    {
        P1.fireTarget(P2);
        if (P1.Guns[P1.activeGun].bulletCapacity == 0) {
            P1.changeActiveGun((P1.activeGun + 1) % 3);
        }
    }
    cout << "Player 1 info : -----------------------------------" << endl;
    P1.displayInfo();
    cout << endl;
    cout << "Player 2 info : -----------------------------------" << endl;
    P2.displayInfo();
    cout << endl;

    return 0;
}