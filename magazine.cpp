#include "magazine.h"
#include "extra_vector.h"
using namespace std;

int T_product::last_index = -1;
double T_product::sum;


void T_warehouse::add_(T_product *product, double weight )
{
    product->setProductWeight(weight);
    //do prywatnej skladowej static odnosimy sie za pomoca funkcji skladowych
	product->set_new_index(++T_product::last_index); // z kazdym nowym produktem w magazynie jego ID zwiekszamy o 1; preinkrementacja bo I index musi byc 0
	warehouse.push_back(product);
}

int T_warehouse::findIndex(const int ID) //znajduje index obiektu w wektorze na podstawie ID
{
    try
    {
        int index = warehouse.at(ID)->_ID;
        return index;
    }
    catch(std::out_of_range&)
    {
        ID_not_found message;
        message._message = "Towar o podanym ID nie istnieje!\n";
        throw message;
    }
}


void T_warehouse::plus_v(const int ID, double count)
{
    try
    {
        int index = findIndex(ID);
        *warehouse.at(index) += count;
        print_v();
    }
    catch(ID_not_found& m)
    {
        cout << m;
        ID_not_found message;
        message._message = "Nalezy dodac nowy produkt do magazynu lub wybrac produkt sposrod juz istniejacych.\n";
        throw message;
    }
}

void T_warehouse::minus_v(const int ID, double count) {

    try
    {
        int index = findIndex(ID);
        if (!warehouse.at(index)->quantity_(count)) {
            cerr << "\nNie ma wystarczajacej ilosci towaru w magazynie!!!\n\n";
        } else{
            *warehouse.at(index) -= count;
            print_v();
        }
    }
    catch(ID_not_found& m)
    {
        cout << m;
        ID_not_found message;
        message._message = "Nalezy dodac nowy produkt do magazynu lub wybrac produkt sposrod juz istniejacych.\n";
        throw message;
    }
}


void T_warehouse::print_v() const
{
        cout << "\n        ----====SPIS PRODUKTOW====----           \n";
        cout << "-------------------------------------------------\n";
        cout << "            ( nazwa | ID | ilosc )               \n";
        cout << "-------------------------------------------------\n";


        for (int i = 0; i < warehouse.size(); i++) {

             cout << *warehouse.at(i) << "waga pojedycznej szt/l/kg: " << warehouse.at(i)->_product_weight << endl;
            cout << "-------------------------------------------------\n";
        }
}

void T_warehouse::bring_out(const int ID, double count, pallet_jack* palletJack)
{
    try
    {
        int index = findIndex(ID);
        T_product* copy;

        if(count <= warehouse.at(index)->getAmount()) //aby wykonac czynnosc musi byc spelniony warunek, nie mozna wydzielic wiekszej ilosci niz jest w magazynie
        {
            //sum jest to suma produktow ktore sa aktualnie na paleciaku
            warehouse.at(index)->sum += warehouse.at(index)->_product_weight * count;

           if( warehouse.at(index)->sum > palletJack->_lifting_capacity )
           {
               warehouse.at(index)->sum -= warehouse.at(index)->_product_weight * count;
               cerr << "Przekroczenie maksymalnego udzwigu paleciaka! Na paleciak mozna zaladowac jeszcze: " << (palletJack->_lifting_capacity-warehouse.at(index)->sum) << "kg " << endl; }
           else{

               try {

                   palletJack->findIndex_p(index);
                   minus_v( index, count );
                   copy = warehouse.at(index)->divide(count);
                   palletJack->update_p(index,copy); }

               catch(ID_not_found& m) {
                    minus_v( index, count );
                    copy = warehouse.at(index)->divide(count);
                    palletJack->add_p(copy); }
           }
           palletJack->print_p(); }
        else{ cerr << "Nalezy zmniejszyc ilosc produktu, ktora ma zostac wydana na paleciak!\n"; }
    }
    catch(ID_not_found& m)
    {
        cout << m;
        ID_not_found_pJ message;
        message._message = "Nalezy dodac nowy produkt do magazynu lub wybrac produkt sposrod juz istniejacych.\n";
        throw message;
    }

}

void T_warehouse::take_over(const int ID,pallet_jack* palletJack)
{
    try
    {
        int index = findIndex(ID);
        T_product* copy;

        try
        {
            palletJack->findIndex_p(index);
            warehouse.at(index)->sum -= palletJack->amount_p(index);
            copy = warehouse.at(index)->clone();
            copy->setAmount(palletJack->amount_p(index));
            palletJack->delete_p(copy);
            warehouse.at(index)->merge(copy);
            print_v();
            palletJack->print_p();
        }
        catch(ID_not_found& m)
        {
            cout << m;
            ID_not_found_pJ message;
            message._message = "Nalezy wybrac towar, ktory znajduje sie na paleciaku. Lista dostepnych produktow: \n";
            throw message;

        }
    }
    catch(ID_not_found& m)
    {
        cout << m;
        ID_not_found message;
        message._message = "Nalezy dodac nowy produkt do magazynu lub wybrac produkt sposrod juz istniejacych.\n";
        throw message;
    }
}

T_warehouse::T_warehouse( char* warehouse_name, int warehouse_ID ) : _warehouse_ID(warehouse_ID)
{
    T_product::copyString(warehouse_name, &this->_warehouse_name);
}
T_warehouse::T_warehouse( const std::string& warehouse_name )
{
    T_product::copyString(warehouse_name.c_str(), &this->_warehouse_name);
}
T_warehouse::T_warehouse(const T_warehouse& warehouse) : T_warehouse(warehouse._warehouse_name,warehouse._warehouse_ID)
{}

T_warehouse::~T_warehouse()
{
    if(!_warehouse_name)
        delete [] _warehouse_name;
}

