#include "pallet_jack.h"
#include "magazine.h"
using namespace std;


void pallet_jack::add_p(T_product* product)
{
    pallet_jack_.push_back(product);
}

void pallet_jack::print_p()
{

    cout << "\n\n        ----====   PALECIAK   ====----           \n";
    cout << "-------------------------------------------------\n";
    cout << "            ( nazwa | ID | ilosc )               \n";
    cout << "-------------------------------------------------\n";


    for( int i = 0; i < pallet_jack_.size(); i++ )
    {
         cout << *pallet_jack_.at(i);
         cout << endl;
    }
    cout << "-------------------------------------------------\n\n\n";
}

int pallet_jack::findIndex_p(const int ID)
{
    try
    {
        int index = pallet_jack_.at(ID)->_ID;
        return index;
    }
    catch(std::out_of_range)
    {
        ID_not_found message;
        message._message = "Towar o podanym ID nie istnieje!\n";
        throw message;
    }
}

double pallet_jack::amount_p(int ID)
{
    try
    {
        int index = findIndex_p(ID);
        return pallet_jack_.at(index)->getAmount();
    }
    catch(ID_not_found& m)
    {
        cout << m;
        ID_not_found message;
        message._message = "Na paleciaku nie ma towaru o podanym ID, dlatego zostanie on dodany.\n";
        throw message;
    }
}

pallet_jack::pallet_jack( double lifting_capacity, int pallet_jack_ID) : _lifting_capacity(lifting_capacity),_pallet_jack_ID(pallet_jack_ID)
{}

pallet_jack::pallet_jack(const pallet_jack &palletJack) : pallet_jack( palletJack._lifting_capacity)//, palletJack._pallet_jack_ID)
{}

void pallet_jack::delete_p(T_product *product)
{
    int index = findIndex_p(product->getproductID());
    pallet_jack_.erase(index);
}
