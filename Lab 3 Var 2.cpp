#include <iostream>
#include <string>
using namespace std;

class IntPos
{
private:
    int i_pos;
public:
    IntPos()        //конструктор по умолчанию
    {
        i_pos = 0;
    }
    IntPos(int I_POS)       //конструктор инициализации
    {
        if (I_POS >= 0)
            i_pos = I_POS;
        else
            i_pos = -I_POS;
    };
    ~IntPos() {};       //деструктор
    IntPos(const IntPos& other)     //конструктор копирования
    {
        this->i_pos = other.i_pos;
    }

    IntPos& operator = (const IntPos& other)        //перегрузка оператора =
    {
        if (other.i_pos >= 0)
            this->i_pos = other.i_pos;
        else
            this->i_pos = other.i_pos;
        return *this;
    }

    IntPos& operator [] (int other)        //перегрузка оператора [] работает, как ()
    {
        if (other >= 0)
            this->i_pos = other;
        else
            this->i_pos = other;
        return *this;
    }

    IntPos& operator () (int other)        //перегрузка оператора [], добавляет к значению 10
    {
        if (other >= 0)
            this->i_pos = other+10;
        else
            this->i_pos = -other+10;
        return *this;
    }

    void operator ++()      //перегрузка оператора ++, добавляет к значению 2
    {
        this->i_pos = this->i_pos + 2;
    }

    void operator ++(int)      //перегрузка оператора ++, умножает значение на 2
    {
        this->i_pos = this->i_pos * 2;
    }

    IntPos& operator + (IntPos other)        //перегрузка оператора + работает, как -
    {
        IntPos that;
        that.i_pos = this->i_pos - other.i_pos;
        if (that.i_pos < 0)
            that.i_pos = 0;
        return that;
    }    

    IntPos& operator > (const IntPos other)        //перегрузка оператора > присваивает большее значение
    {
        if (i_pos < other.i_pos)
            i_pos = other.i_pos;
        return *this;
    }

    IntPos& operator < (const IntPos other)        //перегрузка оператора < присваивает меньшее значение
    {
        if (i_pos > other.i_pos)
            i_pos = other.i_pos;
        return *this;
    }

    friend IntPos operator - (IntPos, int);        //перегрузка оператора - работает, как +    
    friend IntPos operator - (int, IntPos);

    friend std::ostream& operator << (std::ostream& out, const IntPos& point);      //перегрузка оператора <<

    friend IntPos operator -- (IntPos&, int);

    operator int() { return i_pos; };

    void Output();
};

void IntPos::Output()
{
    cout << this->i_pos << endl;
}

IntPos operator -- (IntPos &value, int number)       //перегрузка оператора -- отнимает 2, если уходит в минус, обнуляет
{
    value.i_pos = value.i_pos - 2;
    if (value.i_pos < 0)
        value.i_pos=0;
    return value;
}

IntPos operator - (IntPos value, int number)
{
    value.i_pos = value.i_pos + number;
    return value;
}

IntPos operator - (int number, IntPos value)
{
    value.i_pos = value.i_pos + number;
    return value;
}

std::ostream& operator<< (std::ostream& out, const IntPos& value)
{
    out << "Value of this object is +" << value.i_pos<<endl;

    return out;
}

void printInt(int value)
{
    cout << value<<endl;
}

class multiplier
{
private:
    int result;
public:
    multiplier(int Result=0)
    {
        result = Result;
    }

    operator IntPos() { return IntPos(result * 100); }
};

void printIntPos(IntPos intpos)
{
    cout << intpos << endl;
}

int main()
{
    IntPos object, object1;
    object = -1;
    object1 = -5;
    object.Output();
    object[10];
    object.Output();
    object(10);
    object.Output();
    ++object;
    object.Output();
    object++;
    object.Output();
    object = object + object1;
    object.Output();
    object = object - 5;
    object.Output();
    object1 = 100;
    object > object1;
    object.Output();
    object1 = 10;
    object < object1;
    object.Output();
    object--;
    object.Output();
    object = object - 10;
    object.Output();
    cout << object;
    printInt(object);
    multiplier mult(100);
    printIntPos(mult);
}
