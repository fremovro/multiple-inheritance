#include <iostream>
#include <string>
#include "Class.cpp"
using namespace std;
//
struct Node
{
    const Citchen* field;
    Node* left, * right;
}tree;
//
struct Node* AddNode(const Citchen* obj, Node* tree)
{
    if (tree == NULL)
    {
        tree = new Node;
        tree->field = obj;
        tree->left = NULL;
        tree->right = NULL;
    }
    else  if (obj->get_num() < tree->field->get_num())
        tree->left = AddNode(obj, tree->left);
    else
        tree->right = AddNode(obj, tree->right);
    return(tree);
}
//
Node* del(Node* tree, int val)
{
    if (tree == NULL)
        return tree;
    if (val == tree->field->get_num())
    {
        Node* tmp;
        if (tree->right == NULL)
            tmp = tree->left;
        else {
            Node* ptr = tree->right;
            if (ptr->left == NULL) {
                ptr->left = tree->left;
                tmp = ptr;
            }
            else {
                Node* pmin = ptr->left;
                while (pmin->left != NULL) {
                    ptr = pmin;
                    pmin = ptr->left;
                }
                ptr->left = pmin->right;
                pmin->left = tree->left;
                pmin->right = tree->right;
                tmp = pmin;
            }
        }
        delete tree;
        return tmp;
    }
    else if (val < tree->field->get_num())
        tree->left = del(tree->left, val);
    else
        tree->right = del(tree->right, val);
    return tree;
}
//
void print(Node* tree, int val, bool& f)
{
    if (tree != NULL) 
    {
        if (tree->field->get_num() == val) { tree->field->all_print(); f = true; }
        print(tree->left, val, f);
        print(tree->right, val, f);
    }
}
//
void num_check(Node* tree, int num, bool& f)
{
    if (tree != NULL)
    {
        if (tree->field->get_num() == num) f = true;
        num_check(tree->left, num, f);
        num_check(tree->right, num, f);
    }
}
//
void UI(Node*& my_tree, int x)
{
    switch (x)
    {
        case 1:
        {
            int my_c, num; const Citchen* obj; bool f = false;
            cout << "Выберите утварь(1-плита; 2-кастрюля; 3-электрическая плита; 4-газовая плита; 5-мультиварка): "; cin >> my_c; cout << endl;
            cout << "Введите инвентарный номер: "; cin >> num; cout << endl;
            num_check(my_tree, num, f);
            if (!f)
                switch (my_c)
                {
                case 1:
                {
                    string colour;
                    cout << "Введите цвет плиты: "; cin >> colour; cout << endl;
                    const Stove* ob = new Stove(colour, num);
                    my_tree = AddNode(ob, my_tree);
                    break;
                }
                case 2:
                {
                    int volume;
                    cout << "Введите объём кастрюли: "; cin >> volume; cout << endl;
                    obj = new Pan(volume, num);
                    my_tree = AddNode(obj, my_tree);
                    break;
                }
                case 3:
                {
                    string colour; int power;
                    cout << "Введите цвет плиты: "; cin >> colour; cout << endl;
                    cout << "Введите мощность плиты: "; cin >> power; cout << endl;
                    obj = new eStove(power, colour, num);
                    my_tree = AddNode(obj, my_tree);
                    break;
                }
                case 4:
                {
                    string colour; int gcons;
                    cout << "Введите цвет плиты: "; cin >> colour; cout << endl;
                    cout << "Введите расход газа плиты: "; cin >> gcons; cout << endl;
                    obj = new gStove(gcons, colour, num);
                    my_tree = AddNode(obj, my_tree);
                    break;
                }
                case 5:
                {
                    string colour; int power, volume; bool pressure;
                    cout << "Введите цвет мультиварки: "; cin >> colour; cout << endl;
                    cout << "Введите объём мультиварки: "; cin >> volume; cout << endl;
                    cout << "Введите мощность мультиварки: "; cin >> power; cout << endl;
                    cout << "Имеет ли функцию скороварки: "; cin >> pressure; cout << endl;
                    obj = new mCooker(pressure, volume, colour, power, num);
                    my_tree = AddNode(obj, my_tree);
                    break;
                }
                }
            else
            {
                cout << "Утварь с таким номером уже существует!" << endl;
                print(my_tree, num, f);
            }
            break;
        }
        case 2:
        {
            int val;
            cout << "Введите инвентарный номер: "; cin >> val; cout << endl;
            my_tree = del(my_tree, val);
            break;
        }
        case 3:
        {
            int val; bool f = false;
            cout << "Введите инвентарный номер: "; cin >> val; cout << endl;
            print(my_tree, val, f);
            if (!f) cout << "Нету такой утвари" << endl << endl;
            break;
        }
    }
    int f;
    cout << "Хотите продолжить работу с утварью(1/0)? "; cin >> f; cout << endl;
    if (f == 1)
    {
        cout << "Выберите действие с утварью(1-добавить; 2-удалить; 3-вывести инфу): "; cin >> x; cout << endl;
        UI(my_tree, x);
    }
}
//
void treeprint(Node* tree)
{
    if (tree != NULL) 
    {
        tree->field->all_print();
        treeprint(tree->left);
        treeprint(tree->right);
    }
}
//
int main()
{
    setlocale(LC_ALL, "Russian");
    Node* my_tree; int x; my_tree = NULL; Node* head = my_tree;
    cout << "Выберите действие с утварью(1-добавить; 2-удалить; 3-вывести инфу): "; cin >> x; cout << endl;
    UI(my_tree, x);
    treeprint(my_tree);
}