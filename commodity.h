#ifndef _COMMODITY_H
#define _COMMODITY_H

#include <iostream>
#include <cstring>
#include "product.h"


class T_commodity : public T_product
{

    int _quantity = 0;

	friend class  T_warehouse; //T_magazine moze teraz korzystac z private T_ commodity

	bool quantity_(double count) const override { return (count <= _quantity); }
	void operator+=(double count) override {  _quantity = _quantity + count; }
    void operator-=(double count) override { _quantity = _quantity - count; }



    double getAmount() override { return _quantity; }
    void setAmount(double count) override { _quantity = count; }

    T_product* divide(double count) override;// scalanie
    void merge(T_product* product) override; //dzielenie

public:

    std::ostream& print(std::ostream& out) const override;

    explicit T_commodity(int ID = 0, const char* commodity_name = nullptr, int quantity = 0);
	T_commodity(int ID, const std::string& commodity_name, int quantity );
	T_commodity(const T_commodity & commodity);


	T_product* clone() const override { return new T_commodity(*this); } // tworzy kopie gleboka


	explicit T_commodity(const std::string& commodity_name)  : T_product(commodity_name)
    {}

	~T_commodity() override;


	T_commodity& operator=( const T_commodity& ); 

};

#endif

