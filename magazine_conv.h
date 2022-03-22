#ifndef _WAREHOUSE_CONVERSATION
#define _WAREHOUSE_CONVERSATION


#include <iostream>
#include "magazine.h"
#include "product.h"
#include "commodity.h"
#include "dry.h"
#include "liquid.h"
#include "extra_vector.h"
#include "pallet_jack.h"
#include <cstring>
class T_warehouse_conv
{
	static void show_menu();

	static void increase_quantity(extra_vector* warehouses,T_warehouse* warehouse);
	static void decrease_quantity(extra_vector* warehouses,T_warehouse* warehouse);

	static bool isEmpty(T_warehouse* warehouse) { return warehouse; }

    static void bring_out_(T_warehouse* warehouse, extra_vector* warehouses, pallet_jack* palletJack);
	static void take_over_(T_warehouse* warehouse, extra_vector* warehouses,pallet_jack* palletJack);

	static void add_new_warehouse_ve(extra_vector* warehouses);
    static void add_new_product( T_warehouse* warehouse, extra_vector* warehouses);

	static T_warehouse* choose_warehouse_(extra_vector* warehouses);
    static void read(extra_vector* warehouses, T_warehouse* warehouse);



public:
	static int readInt();
    static double readDouble();
    static std::string readString();
	void run(T_warehouse& warehouse,extra_vector& warehouses, extra_vector& pallet_jacks, pallet_jack& palletJack);
};


#endif