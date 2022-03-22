//
// Created by Olga on 18.12.2020.
//

#include "liquid.h"

using namespace std;

T_liquid::T_liquid(const int ID, const char* commodity_name, double liter) : T_product(ID,commodity_name), _liter(liter)
{}
T_liquid::T_liquid(const int ID, std::string & commodity_name, double liter) : T_liquid(ID, commodity_name.c_str(),liter)
{}
T_liquid::T_liquid(const T_liquid& liquid) : T_product(liquid)
{
    _liter = liquid._liter;
}


T_liquid::~T_liquid()
{
    if(!_commodity_name)
    delete [] _commodity_name;
}

ostream& T_liquid::print(std::ostream &out) const
{
    return out << std::setw(15) << this->_commodity_name << std::setw(10) << this->_ID << std::setw(10) << this->_liter << std::endl;
}

T_liquid& T_liquid::operator=(const T_liquid& liquid){
    if(this != &liquid)
    {
        T_product::operator=(liquid);
        _liter = liquid._liter;
    }
    return *this;
}


T_product* T_liquid::divide(double count)
{
    T_product* pointer = clone();


    pointer->setAmount(x + count);
    x = pointer->getAmount();

    return pointer;
}

void T_liquid::merge(T_product *product)
{
    x = product->getAmount();
    setAmount(x + getAmount());

    delete product;
}

