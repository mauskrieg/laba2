#include "PRICE.h"

using namespace std;

PRICE::PRICE()
{
    cout<<"Вызов конструктора без параметров\n";
    goods = new char [20];
    shops = new char [20];
}
PRICE::PRICE(char *a, char *b, int c)
{
    cout<<"Вызов конструктора с параметрами\n";
    goods = new char [20];
    shops = new char [20];
    strcpy(goods, a);
    strcpy(shops, b);
    cost=c;
}
PRICE::PRICE(const PRICE & object)
{
    cout<<"Вызов конструктора копирования\n";
    goods = new char [20];
    shops = new char [20];
    for(int q=0; q<20; q++)
        goods[q]=object.goods[q];
    for(int q=0; q<20; q++)
        shops[q]=object.shops[q];
    cost=object.cost;
}
bool PRICE::ret(char *inp)
{
    return !strcmp(goods, inp);
}

int bsort(PRICE &obj1, PRICE &obj2)
{
    return strcmp(obj1.goods, obj2.goods);
}

ostream& operator << (ostream& os, PRICE& pr)
{
    os<<pr.goods<<"   ";
    os<<pr.shops<<"   ";
    os<<pr.cost<<"р.\n";
    return os;
}

istream& operator >> (istream& is, PRICE& pr)
{
    cout<<"Введите название товара: ";
    is>>pr.goods;
    cout<<"Введите название магазина, в которм продается товар: ";
    is>>pr.shops;
    while(1)
    {
        try
        {
            cout<<"Введите стоимость товара: ";
            is>>pr.cost;
            if(pr.cost<0)
                throw 1;
            else
                break;
        }
        catch(int i)
        {
            cout<<"Цена не может быть отрицательной!\n";
        }
    }
    cout<<"\n\n";
    return is;
}

PRICE::~PRICE()
{
    cout<<"Вызов деструктора\n";
    delete [] goods;
    delete [] shops;
}
