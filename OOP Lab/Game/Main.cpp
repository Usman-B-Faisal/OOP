#include"Class.h"

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