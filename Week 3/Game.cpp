#include<bits/stdc++.h>
using namespace std;

class MonsterSlayer {



public:
    vector<string> vstr;
    int heroHealth;
    int monsterHealth;
    MonsterSlayer() {

    }
    MonsterSlayer(int heroHealth, int monsterHealth) {
        this->heroHealth = heroHealth;
        this->monsterHealth = monsterHealth;
    }

    void PlayGame(vector<string> heroAbility, vector<string> monsterAbility) {
        int chooseHeroAbility;
        int chooseMonsterAbility;
        int chooseAttack;

        while (true) {
            cout << "1. Player 1 Chance" << endl;
            cout << "2. Player 2 Chance" << endl;
            int playerno;
            cout << "Enter the Player Number: " << endl;
            cin >> playerno;
            switch (playerno) {
            case 1:
                cout << " HERO CHANCE (choose the Attack): " << endl;
                cout << "1. Basic Attack (Stab)" << endl;
                cout << "2. Scroll Power " << endl;
                cin >> chooseAttack;

                switch (chooseAttack) {
                case 1:
                    monsterHealth = monsterHealth + AttackOfHeroes(2, 1);
                    if (monsterHealth < 0) {
                        cout << "HERO WINS ! FATALITY.." << endl;
                        break;
                    }

                    cout << endl;
                    break;
                case 2:
                    if (!heroAbility.empty()) {
                        for (int i = 0; i < heroAbility.size(); i++) {
                            cout << i << heroAbility[i] << endl;
                        }
                        cin >> chooseHeroAbility;

                        monsterHealth = monsterHealth + AttackOfHeroes(heroAbility[chooseHeroAbility]);
                        if (monsterHealth < 0) {
                            cout << "HERO WINS ! FATALITY.." << endl;
                            break;
                        }

                        cout << endl;
                        heroAbility.erase(heroAbility.begin() + chooseHeroAbility);

                    }
                    else {
                        cout << " No Scroll in the Inventory Automatically using Basic Attack" << endl;

                        monsterHealth = monsterHealth + AttackOfHeroes(2, 1);
                        if (monsterHealth < 0) {
                            cout << "HERO WINS ! FATALITY.." << endl;
                            break;
                        }
                        cout << endl;
                    }
                    break;

                }

                break;

            case 2:
                cout << "MONSTER CHANCE (choose the Attack): " << endl;
                cout << "1. Basic Attack " << endl;
                cout << "2. Scroll Power " << endl;
                cin >> chooseAttack;
                switch (chooseAttack) {
                case 1:
                    heroHealth = heroHealth + AttackOfMonster(2, 1);
                    if (heroHealth < 0) {
                        cout << "MONSTER WINS ! FATALITY.." << endl;
                        break;
                    }
                    break;
                case 2:
                    if (!monsterAbility.empty()) {
                        for (int i = 0; i < monsterAbility.size(); i++) {
                            cout << i << monsterAbility[i] << endl;
                        }
                        cin >> chooseMonsterAbility;

                        heroHealth = heroHealth + AttackOfMonster(monsterAbility[chooseMonsterAbility]);
                        if (heroHealth < 0) {
                            cout << "MONSTER WINS ! FATALITY.." << endl;
                            break;
                        }
                        monsterAbility.erase(monsterAbility.begin() + chooseMonsterAbility);
                    }
                    else {
                        cout << " No Scroll in the Inventory AutoMatically using Basic Attack" << endl;
                        heroHealth = heroHealth + AttackOfMonster(2, 1);
                        if (heroHealth < 0) {
                            cout << "MONSTER WINS ! FATALITY.." << endl;
                            break;
                        }

                    }
                    break;
                }


            }
        }
    }

    int AttackOfHeroes(string power) {

        if (power == "Scroll Of healing") {
            heroHealth = heroHealth + 5;
            cout << "Hero Health: " << heroHealth << endl;

        }
        else if (power == "Scroll Of FireBall") {
            monsterHealth = monsterHealth - 4;
            cout << "Monster Health: " << monsterHealth << endl;
            return monsterHealth;
        }
        else if (power == "Scroll Of LightingStrike") {
            monsterHealth = monsterHealth - 3;
            cout << "Monster Health: " << monsterHealth << endl;
            return monsterHealth;
        }
        else if (power == "Scroll Of DoubleDamage") {
            AttackOfHeroes(2, 2);
            cout << "Monster Health: " << monsterHealth << endl;
            return monsterHealth;
        }


    }

    int AttackOfHeroes(int damage, int multiplier) {

        monsterHealth = monsterHealth - (damage * multiplier);
        cout << "Monster Health: " << monsterHealth << endl;
        return monsterHealth;


    }

    int AttackOfMonster(string power) {

        if (power == "Scroll Of healing") {
            monsterHealth = monsterHealth + 5;
            cout << "Monster Health: " << monsterHealth << endl;
        }
        else if (power == "Scroll Of FireBall") {
            heroHealth = heroHealth - 4;
            cout << "Hero Health: " << heroHealth << endl;
            return heroHealth;
        }
        else if (power == "Scroll Of LightingStrike") {
            heroHealth = heroHealth - 3;
            cout << "Hero Health: " << heroHealth << endl;
            return heroHealth;
        }
        else if (power == "Scroll Of DoubleDamage") {
            AttackOfMonster(2, 2);
            cout << "Hero Health: " << heroHealth << endl;
            return heroHealth;
        }


    }


    int AttackOfMonster(int damage, int multiplier) {

        heroHealth = heroHealth - (damage * multiplier);
        cout << "Hero Health: " << heroHealth << endl;
        return heroHealth;



    }



};

int main() {
    string Swordman;
    string Monster;

    cout << "Enter the Name of our Sword man (player1): ";
    cin >> Swordman;
    cout << endl;

    cout << "Enter the Name of out Monster (player2):  ";
    cin >> Monster;
    cout << endl;

    map<int, string> mpp;
    mpp[0] = "Scroll Of healing";
    mpp[1] = "Scroll Of FireBall";
    mpp[2] = "Scroll Of LightingStrike";
    mpp[3] = "Scroll Of DoubleDamage";

    for (int i = 0; i < mpp.size(); i++) {
        cout << i << " => " << mpp[i] << endl;
    }


    vector<string> HeroAbility(2);
    vector<string> MonsterAbility(2);
    int ch;
    cout << "Choose 2 Abilities From Above" << endl;

    cout << endl;
    for (int i = 0; i < 2; i++) {
        cout << "Enter Ability number you want to choose(Hero): ";
        cin >> ch;

        if (mpp[ch] == HeroAbility[0] || mpp[ch] == MonsterAbility[1]) {
            cout << "Please Choose 2 Different Abilities " << endl;
            continue;
        }
        else {
            HeroAbility.push_back(mpp[ch]);
        }
    }

    cout << endl;

    for (int i = 0; i < 2; i++) {
        cout << "Enter Ability number you want to choose(Monster): ";
        cin >> ch;
        if (mpp[ch] == MonsterAbility[0] || mpp[ch] == MonsterAbility[1]) {
            cout << "Please Choose 2 Different Abilities " << endl;
            continue;
        }
        else {
            MonsterAbility.push_back(mpp[ch]);
        }

    }

    cout << "Summary Of players 1 Name and Abilty: " << endl;

    cout << "Name Of Heroes: " << Swordman << endl;
    for (auto x : HeroAbility) {
        cout << "HeroAbility: " << x << endl;
    }
    cout << endl;

    cout << "Summary Of players 2 Name and Abilty: " << endl;

    cout << "Name of Monster: " << Monster << endl;
    for (auto y : MonsterAbility) {
        cout << "MonsterAbility: " << y << endl;
    }


    MonsterSlayer MS(10, 10);
    MS.PlayGame(HeroAbility, MonsterAbility);


    return 0;
}
