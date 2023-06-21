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
