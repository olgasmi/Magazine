//
// Created by Olga on 18.12.2020.
//

#include "dry.h"

using namespace std;


T_dry::T_dry(const int ID, const char* commodity_name, double kg) : T_product(ID, commodity_name), _kg(kg)
{}
T_dry::T_dry(const int ID, std::string & commodity_name, double kg) : T_dry(ID, commodity_name.c_str(), kg)
{}
T_dry::T_dry(const T_dry& dry) : T_product(dry)
{
    _kg = dry._kg;
}

T_dry::~T_dry()
{
    cout << "dry";

    if(!_commodity_name)
    delete [] _commodity_name;
}

ostream& T_dry::print(std::ostream& out) const
{
    return out << std::setw(15) << this->_commodity_name << std::setw(10) << this->_ID << std::setw(10) << this->_kg <<std::endl;
}

T_dry& T_dry::operator=(const T_dry& dry)
{
    if(this != &dry)
    {
        T_product::operator=(dry);
        _kg = dry._kg;
    }

    return *this;

}

T_product* T_dry::divide(double count)
{
    T_product* pointer = clone();


    pointer->setAmount(x + count);
    x = pointer->getAmount();

    return pointer;
}

void T_dry::merge(T_product *product)
{
    x = product->getAmount();
    setAmount(x + getAmount());

    delete product;
}
