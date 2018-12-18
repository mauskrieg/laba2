#pragma once

using namespace std;

class PRICE
{
private:
    char *goods;
    char *shops;
    int cost;
public:
    PRICE();
    PRICE(char *a, char *b, int c);
    PRICE(const PRICE & object);
    bool ret(char *inp);
    friend int bsort(PRICE&, PRICE&);
    friend ostream& operator << (ostream&, PRICE&);
    friend istream& operator >> (istream&, PRICE&);
    ~PRICE();
};
