#include "magazine_conv.h"
using namespace std;


int T_warehouse_conv::readInt()
{
    string line;
    getline( cin, line);
    return atoi(line.c_str());
}

double T_warehouse_conv::readDouble()
{
    string line;
    getline( cin, line);
    return atof(line.c_str()); //atof - convert string to double
}

string T_warehouse_conv::readString()
{
    string line;
    getline(cin, line);
    return line;
}

void T_warehouse_conv::show_menu()
{
	std::cout << "\n---====== MENU =====---\n"
		"1. Dodaj nowy magazyn. \n"
        "2. Dodaj towar do wybranego magazynu.\n"
		"3. Spis produktow w danym magazynie.\n"
		"4. Dodaj okreslona ilosc towaru do wybranego magazynu.\n"
		"5. Usun okreslona ilosc towaru z wybranego magazynu.\n"
        "6. Zaladuj towar z magazynu na paleciaka.\n"
        "7. Przenies towar z paleciaka do magazynu.\n\n"

        "0. Zakonczenie dzialania programu.\n"
		"\nWybierz akcje: ";
}

void T_warehouse_conv::increase_quantity(extra_vector* warehouses,T_warehouse* warehouse)
{
    try
    {
        warehouse = choose_warehouse_(warehouses);
        cout << "\nPodaj ID produktu, ktorego ilosc chcesz zwiekszyc: ";
        int ID = readInt();
        cout << "\nPodaj liczbe sztuk, ktora chcesz dodac do magazynu: ";
        int count = readInt();

        try{ warehouse->plus_v(ID, count); }
        catch(ID_not_found& m) { cout << m; }
    }
    catch(ID_not_found& m)
    {
        cout << m;
        warehouses->print_ve_();
    }
}
void T_warehouse_conv::decrease_quantity(extra_vector* warehouses,T_warehouse* warehouse)
{
    try
    {
        warehouse = choose_warehouse_(warehouses);
        cout << "\nPodaj ID produktu, ktorego ilosc chcesz zmniejszyc: ";
        int ID = readInt();
        cout << "\nPodaj liczbe sztuk, ktora chcesz usunac z magazynu: ";
        int count = readInt();

        try{ warehouse->minus_v(ID, count); }
        catch(ID_not_found& m) { cout << m; }
    }
    catch(ID_not_found& m)
    {
        cout << m;
        warehouses->print_ve_();
    }
}

void T_warehouse_conv::add_new_product( T_warehouse* warehouse,extra_vector* warehouses )
{
    try
    {
        warehouse = choose_warehouse_(warehouses);
        cout << "Podaj nazwe towaru, ktory chcesz dodac do magazynu: \n";
        string name = readString();

        cout << "Podaj wage towaru, ktory zostanie dodany do magazynu, w celu przeliczenia wagi jednego litra lub wagi jednej sztuki towaru: \n";
        double weight = readDouble();

        cout << "\n---===Towar na:===---\n"
                "1. SZTUKI\n"
                "2. LITRY\n"
                "3. WAGE\n"
                "\n\nWybierz akcje: ";

        int choice = readInt();

        T_product *wsk;
        if (choice == 1) {
            wsk = new T_commodity{0, name, 0};
            warehouse->add_(wsk,weight);
        } else if (choice == 2) {
            wsk = new T_liquid{0, name, 0};
            warehouse->add_(wsk,weight);
        } else if (choice == 3) {
            wsk = new T_dry{0, name, 0};
            warehouse->add_(wsk,weight);
        } else {
            cerr << "Niepoprawny wybor!" << endl;
        }

        cout << endl;
        warehouse->print_v();
    }
    catch(ID_not_found& m)
    {
        cout << m;
        warehouses->print_ve_();
    }
}
void T_warehouse_conv::bring_out_(T_warehouse* warehouse, extra_vector* warehouses, pallet_jack* palletJack)
{

   try
    {
        warehouse = choose_warehouse_(warehouses);
        palletJack = warehouses->choose_palletJack(warehouse->ID());

        cout << "\nPodaj ID produktu, ktory zostanie zaladowana na paleciaka: ";
        int ID = readInt();
        cout << "\n Podaj ilosc produktu, ktora zostanie zaladowana na paleciaka: ";
        int count = readInt();


        warehouse->bring_out(ID, count, palletJack);

    }
    catch(ID_not_found& m)
    {
        cout << m;
        warehouses->print_ve_();
    }
    catch(ID_not_found_pJ& m)
    {
        cout << m;
        warehouse->print_v();
    }

}

void T_warehouse_conv::take_over_(T_warehouse* warehouse, extra_vector* warehouses,pallet_jack* palletJack)
{
    try
    {
        warehouse = choose_warehouse_(warehouses);
        palletJack = warehouses->choose_palletJack(warehouse->ID());

        cout << "\nPodaj ID produktu, ktory zostanie rozladowana z paleciaka: ";
        int ID = readInt();

        warehouse->take_over(ID,palletJack);
    }
    catch(ID_not_found& m)
    {
        cout << m;
        warehouses->print_ve_();
    }
    catch(ID_not_found_pJ& m)
    {
        cout << m;
        palletJack->print_p();
    }

}

void T_warehouse_conv::add_new_warehouse_ve(extra_vector* warehouses)
{
    std::cout << "Podaj nazwe magazynu, ktory chcesz utworzyc: \n";
    std::string name = readString();

    std:: cout << "Podaj maksymalny udzwig paleciaka [ kg ]: \n";
    double lifting_capacity = readDouble();
    auto* wsk = new T_warehouse{name};
    auto* ptr = new pallet_jack{lifting_capacity};

    warehouses->_add_ve(wsk,ptr);
}

T_warehouse* T_warehouse_conv::choose_warehouse_(extra_vector* warehouses)
{

        std::cout << "Podaj ID magazynu, ktory chcesz wybrac: \n";
        int choice = readInt();

      try
        {
            T_warehouse* warehouse = warehouses->choose_warehouse(choice);
            return warehouse;
        }
        catch(ID_not_found& m)
        {
            cout << m;
            ID_not_found message;
            message._message = "Oto lista dostepnych magazynow: \n";
            throw message;
        }
}

void T_warehouse_conv::read(extra_vector* warehouses,T_warehouse* warehouse)
{
    try
    {
        warehouse = choose_warehouse_(warehouses);
        cout << endl;
        warehouse->print_v();

    }
    catch(ID_not_found& m)
    {
        cout << m;
        warehouses->print_ve_();
    }
}
void T_warehouse_conv::run(T_warehouse& warehouse,extra_vector& warehouses,extra_vector& pallet_jacks, pallet_jack& palletJack)
{
        int choice;
        do {
            show_menu();
            choice = readInt();

    switch (choice) {
        case 0:
            break;
        case 1:
            add_new_warehouse_ve(&warehouses);
            cout << endl;
            warehouses.print_ve_();
            break;
        case 2:
            add_new_product(&warehouse, &warehouses);
            break;
        case 3:
            read(&warehouses,&warehouse);
            break;
        case 4:
            if (!isEmpty(&warehouse)) { cout << "ERROR! Magazyn jest pusty!"; }
            else { increase_quantity(&warehouses, &warehouse); }

            break;
        case 5:
            if (!isEmpty(&warehouse)) { cout << "ERROR! Magazyn jest pusty!"; }
            else { decrease_quantity(&warehouses, &warehouse); }
            break;

        case 6:
            bring_out_(&warehouse, &warehouses, &palletJack);
            break;

        case 7:
            take_over_(&warehouse, &warehouses, &palletJack);
            break;

        default:
            std::cout << "Niepoprawny wybor" << std::endl;
    }
}while (choice != 0);

}

