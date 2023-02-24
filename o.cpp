#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
using namespace std;
class ship {
        private:
            string name;
            int health;
        public:
            int damage, range, x, y, xDist, yDist;
            void input(string, int, int, int, int, int);
            void output();
            void forward();
            void backward();
            void right();
            void left();
            void updateDist(int, int);
            bool isDead();
            void takeDamage(int);
};
void printMap(int, int, int, int);
int input, killCount;
int main()
{
    srand(time(0));
    ship cakru, musuh;
    cakru.input("Cakru", 10, 2, 2, 0, 0);
    musuh.input("Musuh", 4, 1, 2, -5 + (rand() % 11), -5 + (rand() % 11));
    while (cakru.isDead() == false)
    {
        system("cls");
        cakru.updateDist(musuh.x, musuh.y);
        musuh.updateDist(cakru.x, cakru.y);
        printMap(cakru.x, cakru.y, musuh.x, musuh.y);
        cakru.output();
        cout << endl;
        musuh.output();
        cout << endl;
        cout << "Sekarang adalah giliran Anda. Apa yang ingin Anda lakukan?" << endl;
        cout << "[1] Bergerak maju\n[2] Bergerak mundur\n[3] Bergerak ke kanan\n[4] Bergerak ke kiri\n[5] Serang musuh\n[6] Diam di tempat\n";
        cin >> input;
        switch (input)
        {
            case 1:
                cakru.forward();
                break;
            case 2:
                cakru.backward();
                break;
            case 3:
                cakru.right();
                break;
            case 4:
                cakru.left();
                break;
            case 5:
                if (abs(cakru.xDist) <= 2 && abs(cakru.yDist) <= 2)
                {
                    cout << "Serangan kena!" << endl;
                    musuh.takeDamage(cakru.damage);
                    system("pause");
                }
                else
                {
                    cout << "Yah serangan tidak kena!" << endl;
                    system("pause");
                }
                break;
            case 6:
                break;
        }
        cakru.updateDist(musuh.x, musuh.y);
        musuh.updateDist(cakru.x, cakru.y);
        cout << "Sekarang adalah giliran musuh" << endl;
        if (abs(musuh.xDist) <= 2 && abs(musuh.yDist) <= 2)
        {
            cakru.takeDamage(musuh.damage);
            cout << "Musuh menyerang kapal Cakru!" << endl;
            system("pause");
        }
        else if (musuh.xDist > musuh.range)
        {
            musuh.right();
            cout << "Musuh bergerak ke kanan" << endl;
            system("pause");
        }
        else if (musuh.xDist < -1*musuh.range)
        {
            musuh.left();
            cout << "Musuh bergerak ke kiri" << endl;
            system("pause");
        }
        else if (musuh.yDist > musuh.range)
        {
            musuh.forward();
            cout << "Musuh bergerak maju" << endl;
            system("pause");
        }
        else if (musuh.yDist < -1*musuh.range)
        {
            musuh.backward();
            cout << "Musuh bergerak mundur" << endl;
            system("pause");
        }
    }
    cout << "Permainan bagus!" << endl;
}

void ship::input(string n, int h, int d, int r, int posX, int posY)
{
    name = n;
    health = h;
    damage = d;
    range = r;
    x = posX;
    y = posY;
}

void ship::output()
{
    cout << "Nama Kapal: " << name << endl;
    cout << "Nyawa: " << health << endl;
    cout << "Damage: " << damage << endl;
    cout << "Jarak Serangan: " << range << endl;
    cout << "Posisi: " << "(" << x << "," << y << ")" << endl;
    cout << "Jarak dengan Musuh: " << "(" << xDist << "," << yDist << ")" << endl;

}

void ship::forward()
{
    y+=1;
}

void ship::backward()
{
    y-=1;
}

void ship::right()
{
    x+=1;
}

void ship::left()
{
    x-=1;
}

bool ship::isDead()
{
    if (health <=0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void ship::updateDist(int xEnemy, int yEnemy)
{
    xDist = xEnemy - x;
    yDist = yEnemy - y;
}

void ship::takeDamage(int damage)
{
    health-=damage;
}

void printMap(int xCakru, int yCakru, int xMusuh, int yMusuh)
{
    for (int i = 5; i >= -5; i--)
    {
        for (int j = -5; j <= 5; j++)
        {
            if (xCakru == j && yCakru == i)
            {
                cout << "C";
            }
            else if (xMusuh == j && yMusuh == i)
            {
                cout << "M";
            }
            else
            {
                cout << ".";
            }
        }
        cout << endl;
    }
}
