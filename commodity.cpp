#include "commodity.h"
using namespace std;



T_commodity::T_commodity(const int ID, const char* commodity_name, int quantity) : T_product(ID,commodity_name), _quantity(quantity)
{}
T_commodity::T_commodity( const int ID, const std::string& commodity_name, int quantity) : T_commodity(ID, commodity_name.c_str(), quantity)
{}
T_commodity::T_commodity(const T_commodity& commodity) : T_product(commodity)
{
    _quantity = commodity._quantity;
}
T_commodity::~T_commodity()
{
    if(!_commodity_name)
    delete[] _commodity_name;
}

ostream& T_commodity::print(std::ostream& out) const
{
    return out << std::setw(15) << this->_commodity_name << std::setw(10) << this->_ID << std::setw(10) << this->_quantity <<std::endl;
}


T_commodity& T_commodity::operator=(const T_commodity& product) 
{
	if (&product != this) // sprawdzenie czy kopiuje siebie samego
	{
		T_product::operator=(product); // wywolanie zaslonietego z klasy podstawowej operatorem zakresu
		this->_quantity = product._quantity;
	}
	
	return *this;
}

T_product* T_commodity::divide(double count)
{

    T_product* pointer = clone(); //gleboka kopia

    pointer->setAmount(x + count);
    x = pointer->getAmount(); //nowa wartosc x

    return pointer;
}

void T_commodity::merge(T_product* product)
{
    x = product->getAmount();
    setAmount(x + getAmount());

    delete product;
    product = nullptr;
}


