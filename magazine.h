#ifndef _WAREHOUSE_H
#define _WAREHOUSE_H

#include "product.h"
#include <vector>
#include <iostream>
#include <iomanip>
#include <cstring>
#include "pallet_jack.h"
#include "helper.h"

class  T_warehouse
{
	myVector< T_product* > warehouse;
	
	int findIndex(int ID);

	//do wektora magazynow
	char* _warehouse_name;
    static int last_index_ve;
    int _warehouse_ID;


    friend class extra_vector;
	friend class pallet_jack;

public:

    explicit T_warehouse( char* warehouse_name = nullptr, int warehouse_ID = 0 );
    T_warehouse(const T_warehouse& warehouse);

    explicit T_warehouse( const std::string& warehouse_name );

    [[noreturn]] ~T_warehouse();
    void _set_new_index_ve(int index) { this->_warehouse_ID = index; }


    int ID() const { return _warehouse_ID;};
    void plus_v(const int ID, double count);
    void minus_v(const int ID, double count);
	void print_v() const;
	void add_(T_product *product, double weight );
	void bring_out(const int ID, double, pallet_jack* palletJack);
	void take_over(const int ID, pallet_jack* palletJack);

    friend std::ostream& operator<<(std::ostream& out, const T_warehouse& warehouse_)
    {
        return out << std::setw(15) << warehouse_._warehouse_name << std::setw(20) << warehouse_._warehouse_ID << std::setw(10) << std::endl;
    }
};


#endif

