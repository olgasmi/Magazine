
#ifndef _PALLET_JACK_H
#define _PALLET_JACK_H

#include "myVector.h"
#include <vector>
#include "product.h"


class pallet_jack {

    int _pallet_jack_ID;
    static int last_index_vep;
    double _lifting_capacity;

    myVector< T_product* > pallet_jack_;

    friend class T_warehouse;
    friend class extra_vector;
    double amount_p(int ID);

    void add_p(T_product* product);
    void delete_p(T_product* product);


    // funkcja uaktualniajaca stan towaru na paleciaku tzn. jego ilosc
    void update_p(int index, T_product* product) { pallet_jack_.at(index) = product;}

public:

    void print_p();
    int findIndex_p(const int ID);

    void _set_new_index_vep(int index) { this->_pallet_jack_ID = index; }

    explicit pallet_jack( double lifting_capacity = 0, int pallet_jack_ID = 0 );
    pallet_jack(const pallet_jack& warehouse);
    ~pallet_jack() = default;
    friend std::ostream& operator<<(std::ostream& out, const pallet_jack& palletJack)
    {
        return out << std::setw(15) << palletJack._lifting_capacity << std::setw(20) << palletJack._pallet_jack_ID << std::setw(10) << std::endl;
    }


};


#endif
