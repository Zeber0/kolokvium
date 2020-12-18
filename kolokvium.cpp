// kolokvium.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <set>
class Kladovshikov
{
public:
    int* a;
    Kladovshikov()
    {
        int t;
        std::cin >> t;
        a=new int(t);
    }
    Kladovshikov(const Kladovshikov& obj)
    {
        *a = *obj.a;
    }
    virtual void Copy(std::set <Kladovshikov*>& set)
    {

    }

    ~Kladovshikov()
    {
        delete a;
    }
};
class Dmitry : public Kladovshikov
{
public:
    float b;
    Dmitry()
    {
        std::cin >> b;
    }
    Dmitry(const Dmitry& obj)
    {
        b = obj.b;
    }
    void Copy(std::set <Kladovshikov*>& set)
    {
        set.insert(new Dmitry(*this));
    }
    ~Dmitry() {}
};
int main()
{
    {
        std::set <Kladovshikov*> db1, db2;
        db1.insert(new Kladovshikov());
        db1.insert(new Dmitry());
        for (std::set <Kladovshikov*>::iterator it = db1.begin(); it != db1.end(); ++it)
        {
            (*it)->Copy(db2);
        }
        for (std::set <Kladovshikov*>::iterator it = db1.begin(); it != db1.end(); ++it)
        {
            delete* it;
        }
        for (std::set <Kladovshikov*>::iterator it = db2.begin(); it != db2.end(); ++it)
        {
            delete* it;
        }
        db1.clear();
        db2.clear();
    }
    _CrtDumpMemoryLeaks();
    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
