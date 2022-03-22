#include "magazine_conv.h"
#include <fstream>
using namespace std;



int main(int argc, const char *argv[])
{


    freopen(argv[1],"r",stdin);


    pallet_jack palletJack;
    T_warehouse warehouse;
    extra_vector warehouses;
    extra_vector pallet_jacks;

    T_warehouse_conv conversation;
    conversation.run(warehouse,warehouses,pallet_jacks,palletJack);


    return 0;
   
}

