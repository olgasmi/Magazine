
#include "extra_vector.h"
using namespace std;

int T_warehouse::last_index_ve = -1;
int pallet_jack::last_index_vep = T_warehouse::last_index_ve;


void extra_vector::_add_ve( T_warehouse* warehouse, pallet_jack* palletJack )
{
    _add_ve_p(palletJack);

    warehouse->_set_new_index_ve(++T_warehouse::last_index_ve);
    warehouses.push_back(warehouse);
}
void extra_vector::_add_ve_p( pallet_jack* palletJack)
{
    palletJack->_set_new_index_vep(++pallet_jack::last_index_vep);
    pallet_jacks.push_back(palletJack);

}
int extra_vector::findIndex_ve(const int warehouse_ID)
{
    try
    {
        int index = warehouses.at(warehouse_ID)->_warehouse_ID;
        return index;
    }
    catch(std::out_of_range&)
    {
        ID_not_found message;
        message._message = "Obiekt o podanym ID nie istnieje!\n";
        throw message;
    }
}

void extra_vector::print_ve_() const
{
        cout << "\n\n     --====SPIS MAGAZYNOW + PALECIAKOW====--     \n";
        cout << "-------------------------------------------------\n";
        cout << "       ( nazwa magazynu   | ID magazynu  )       \n";
        cout << "       ( udzwig paleciaka | ID paleciaka )       \n";
        cout << "-------------------------------------------------\n";

        for (int i = 0; i < warehouses.size(); i++) {

            cout << *(warehouses.at(i)) << endl;
            cout << *(pallet_jacks.at(i)) << endl;
        }
        cout << "-------------------------------------------------\n\n\n";
}

T_warehouse* extra_vector::choose_warehouse(int index)
{

    try
    {
        int warehouse_ID = findIndex_ve(index);
        return warehouses.at(warehouse_ID);
    }
    catch(ID_not_found& m)
    {
        cout << m;
        ID_not_found message;
        message._message = "Nalezy utworzyc nowy magazyn lub wybrac magazyn sposrod juz istniejacych.\n";
        throw message;
    }
}

pallet_jack* extra_vector::choose_palletJack(int index)
{

    try
    {
        T_warehouse* warehouse = choose_warehouse(index);
        return pallet_jacks.at(warehouse->_warehouse_ID);
    }
    catch(ID_not_found& m)
    {
        cout << m;
        return nullptr;
    }
}





