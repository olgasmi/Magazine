//
// Created by Olga on 18.12.2020.
//

#include "product.h"
#include <cstring>

using namespace std;


T_product::T_product(const int ID, const char* commodity_name) : _ID(ID)
{
    copyString(commodity_name, &this->_commodity_name);
}
//konstruktor delegujacy
T_product::T_product( const int ID, const std::string& commodity_name) : T_product(ID, commodity_name.c_str())
{}
//kopiujacy
T_product::T_product(const T_product& product) : T_product(product._ID, product._commodity_name)
{}
T_product::T_product(const std::string& commodity_name)
{
    copyString(commodity_name.c_str(), &this->_commodity_name);
}
//destruktor
T_product::~T_product()
{

    if(!_commodity_name)
    delete[] _commodity_name;
}
void T_product::copyString(const char* in, char** out)
{
    if (in)
    {
        *out = new char[strlen(in) + 1]{};
        strcpy(*out, in);
    }
    else {
        *out = nullptr;
    }
}

T_product&  T_product::operator=(const T_product& product)
{
    if (&product != this) // sprawdzenie czy kopiuje siebie samego
    {
        //czesc destruktorowa
        delete [] _commodity_name;

        //czesc konstruktorowa
        copyString( product._commodity_name, & this->_commodity_name);
        this->_ID = product._ID;
    }
    return *this;
}

void T_product::set_new_index(int index)
{
    this->_ID = index;
}