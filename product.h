//
// Created by Olga on 18.12.2020.
//

#ifndef _PRODUCT_H
#define _PRODUCT_H
#include <iostream>
#include <iomanip>


class T_product {

protected:
    static int last_index; //wspolny dla wszystkich obiektow
    static double sum;

    int _ID;
    char* _commodity_name;

    //pomocnicze dane-skladowe
    double _product_weight;
    double x = 0;


    friend class T_warehouse;
    friend class pallet_jack;

    void setProductWeight(double weight) {this->_product_weight = weight;}
    virtual bool quantity_(double count) const = 0;
    virtual void operator+=(double count) = 0;
    virtual void operator-=(double count) = 0;

    virtual T_product* divide(double count) = 0; // dzielenie
    virtual void merge(T_product* product) = 0; //scalanie


    virtual std::ostream& print(std::ostream& out) const = 0;


    int getproductID() const { return _ID; }

public:

    static void copyString(const char* in, char** out);

    void set_new_index(int index);

    explicit T_product(const int ID = 0, const char* commodity_name = nullptr);
    T_product(const int ID, const std::string& commodity_name);
    T_product(const T_product & commodity);

    virtual T_product* clone() const = 0;

    explicit T_product(const std::string& commodity_name);

    virtual ~T_product();
    friend std::ostream& operator<<(std::ostream& out, const T_product& product) { return product.print(out); }

    T_product& operator=( const T_product& );

    virtual void setAmount(double count) = 0;
    virtual double getAmount() = 0;

};


#endif //_PRODUCT_H
