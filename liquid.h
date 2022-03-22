//
// Created by Olga on 18.12.2020.
//

#ifndef _LIQUID_H
#define _LIQUID_H

#include "product.h"
#include <iostream>

class T_liquid : public T_product {

    double _liter;


    bool quantity_(double count) const override { return (count <= _liter); }
    void operator+=(double count) override { _liter = _liter + count; }
    void operator-=(double count) override { _liter = _liter - count; }

    double getAmount() override { return _liter; }
    void setAmount(double count) override { _liter = count; }

    T_product* divide(double count) override;// scalanie
    void merge(T_product* product) override; //dzielenie

public:

    std::ostream& print(std::ostream& out) const override;

    explicit T_liquid(int ID = 0, const char* commodity_name = nullptr, double liter = 0);
    T_liquid(int ID, std::string & commodity_name, double liter);
    T_liquid(const T_liquid& liquid);
    explicit T_liquid(const std::string& commodity_name)  : T_product(commodity_name) {}

    T_product* clone() const override { return new T_liquid(*this); } // tworzy kopie gleboka


    ~T_liquid() override;

    T_liquid& operator=(const T_liquid& liquid);
};


#endif
