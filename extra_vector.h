
#ifndef SMISTEKOLGA_ETAP1_EXTRA_VECTOR_H
#define SMISTEKOLGA_ETAP1_EXTRA_VECTOR_H


#include <iostream>
#include <iomanip>
#include "myVector.h"
#include "vector"
#include "magazine.h"
#include "helper.h"
#include "pallet_jack.h"
#include <stdexcept>
class extra_vector {

    myVector< T_warehouse* > warehouses;
    myVector< pallet_jack* > pallet_jacks;

public:
    void _add_ve( T_warehouse* warehouse, pallet_jack* palletJack);
    void _add_ve_p( pallet_jack* palletJack);

    int findIndex_ve(int warehouse_ID);
    void print_ve_() const;
    T_warehouse* choose_warehouse(int index);
    pallet_jack* choose_palletJack(int index);

};


#endif
