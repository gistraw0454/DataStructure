#ifndef ITEMTYPE_H
#define ITEMTYPE_H

#include <iostream>
#include <string>

using namespace std;

const int MAX_ITEMS = 5;
enum RelationType {LESS, GREATER, EQUAL};

class ItemType
{
public:
    ItemType();
    RelationType ComparedTo(ItemType) const;
    void Print() const;
    void Initialize(ItemType& item);
    friend istream& operator >>(istream& inStream, ItemType& item);
    friend ostream& operator<<(ostream& os, const ItemType& item);
private:
    string country;
    string capital;
};

ItemType::ItemType()
{
    country = "";
    capital = "";
}

RelationType ItemType::ComparedTo(ItemType otherItem) const
{
    if (country < otherItem.country)
        return LESS;
    else if (country > otherItem.country)
        return GREATER;
    else return EQUAL;
}

void ItemType::Initialize(ItemType& item)
{
    country = item.country;
    capital = item.capital;
}

void ItemType::Print() const
// pre:  out has been opened.
// post: value has been sent to the stream out.
{
    cout << "[ " << country << " : " << capital << " ]";
}

istream& operator >>(istream& inStream, ItemType& item)
{
    string line;
    getline(inStream, line);

    size_t dashPos = line.find(':');
    item.country = line.substr(1, dashPos-2);
    item.capital = line.substr(dashPos+2);

    return inStream;
}

ostream& operator<<(ostream& os, const ItemType& item) {
    os << "Country: " << item.country << ", Capital: " << item.capital;
    return os;
}
#endif