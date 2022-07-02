#include <iostream>
#include <string>
using namespace std;
//
class Citchen
{
protected:
    int num;
    Citchen(int my_num)
    {
        num = my_num;
    }
public:
    virtual int get_num() const { return num; }
    virtual void all_print() const {}
};
//
class Stove : virtual public Citchen
{
public:
    string colour;
    Stove(string my_colour, int my_num)
        :Citchen(my_num)
    {
        colour = my_colour;
    }
    virtual void all_print() const override { cout << "�����: " << num << endl << "����: " << colour << endl << endl; }
};
//
class Pan : virtual public Citchen
{
public:
    int volume;
    Pan(int my_volume, int my_num)
        :Citchen(my_num)
    {
        volume = my_volume;
    }
    virtual void all_print() const override { cout << "�����: " << num << endl << "�����: " << volume << endl << endl; }
};
//
class eStove : public Stove
{
public:
    int power;
    eStove(int my_power, string my_colour, int my_num)
        :Stove(my_colour, my_num), Citchen(my_num)
    {
        power = my_power;
    }
    virtual void all_print() const override { cout << "�����: " << num << endl << "����: " << colour << endl << "��������: " << power << endl << endl; }
};
//
class gStove : public Stove
{
public:
    int gcons;
    gStove(int my_gcons, string my_colour, int my_num)
        :Stove(my_colour, my_num), Citchen(my_num)
    {
        gcons = my_gcons;
    }
    virtual void all_print() const override { cout << "�����: " << num << endl << "����: " << colour << endl << "������ ����: " << gcons << endl << endl; }
};
//
class mCooker : public Pan, public eStove
{
public:
    bool pressure;
    mCooker(bool my_pressure, int my_volume, string my_colour, int my_power, int my_num)
        :Pan(my_volume, my_num), eStove(my_power, my_colour, my_num), Citchen(my_num)
    {
        pressure = my_pressure;
    }
    virtual void all_print() const override { cout << "�����: " << num << endl << "����: " << colour << endl << "�����: " << volume << endl << "��������: " << power << endl << "����������: " << pressure << endl << endl; }
};