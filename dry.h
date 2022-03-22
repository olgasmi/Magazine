//
// Created by Olga on 18.12.2020.
//

#ifndef _DRY_H
#define _DRY_H
#include "product.h"
#include <iostream>

class T_dry : public T_product {

    double _kg;

    bool quantity_(double count) const override { return (count <= _kg); }
    void operator+=(double count) override { _kg = _kg + count; }
    void operator-=(double count) override { _kg = _kg - count; }

    double getAmount() override { return _kg; }
    void setAmount(double count) override { _kg = count; }


    T_product* divide(double count) override;// scalanie
    void merge(T_product* product) override; //dzielenie

public:

    std::ostream& print(std::ostream& out) const override;


    explicit T_dry(int ID = 0 , const char* commodity_name = nullptr, double kg = 0);
    T_dry(int ID, std::string & commodity_name, double kg);
    T_dry(const T_dry& dry);
    explicit T_dry(const std::string& commodity_name)  : T_product(commodity_name) {}

    T_product* clone() const override { return new T_dry(*this); } // tworzy kopie gleboka


    ~T_dry() override;


    T_dry& operator=(const T_dry& dry);
};


#endif
