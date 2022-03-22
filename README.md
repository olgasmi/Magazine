# Magazine
Projekt był wykonywany stopniowo, poniżej znajduje się opis poszczególnych etapów.

OPIS ETAPU TRZECIEGO.
Projekt został wzbogacony o dwie klasy, zatem aktulanie składa się z 10 klas oraz pliku main.cpp.

*klasa helper - zawiera definicję dwóch struktur, które są stosowane przy rzucaniu wyjątków lub ich łapaniu. W funkcji findIndex, której odpowienie
implementacje znajdują się m.in. w klasie extra_vector, pallet_jack czy T_warehouse, stosujemy sprawdzenie dla funckji at(), która rzuca wyjątek 
std::out_of_range w przypadku wyjścia poza zakres wektora, czyli próby dostania się do indeksu < 0 lub > wektor.size() - 1. Wyjątek jest łapany blokiem
catch(), w którym tworzony jest obiekt odpowiedniej struktury, zawierający informację dla użytkownika co poszło nie tak, a następnie obiekt jest rzucany i
łapany przez kolejne funckj, które korzystają z odpowieniej funkcji składowej findIndex. Ważnym przykładem jest funckcja składowa findIndex_ve klasy 
extra_vector, która jest wykorzystywana w funkcjach takich jak choose_warehouse lub choose_palletJack, które są sprawdzane w niemalże każej funkcji 
interfejsu użytkownika.

*klasa myVector - zawiera implementacje szablonu klasy, która jest kontenerem. Zawiera funkcje składowe odzwierciedlające pracę na wektorze tj. 
push_back, erase, at, size oraz przeładowanie operatora[]. Składowa vector_size określa aktualny rozmiar wektora (ilość elementów, które się w nim
aktulanie znajdują), natomiast vector_capacity jest to liczba elementów, które mogą zostać dodane do wektora bez konieczności realokacji pamięci. 
Początkowo vector=capacity ustawiam na 3, potem z każdym przekroczeniem tej wartości następuje realokacja pamięci za pomocą funkcji składowej 
reallocation(), która polega na przekopiowaniu starego bloku pamięco do nowego bloku pamięci, którego vector_capacity przyjmuje nową, większa wartość.
Funkcja składowa push_back, sprawdza czy rozmiar wektora na pewno nie przekracza vector_capacity - w takim przypadku nastepuje powiększenie wartości 
vector_capacity dwukrotnie. ( np. wraz z dodaniem 4 elementu, vector_capacity zwiększa swoją wartość dwukrotnie, czyli 
vector_capacity = 6).



OPIS ETAPU DRUGIEGO.
Projekt zostały wzbogacony o 5 nowych klas, zatem aktualnie składa sie z 8 klas oraz pliku main.cpp.

W większości klas został zaprzyjaźniony operator<<, ze względu na fakt, że przyjaźń nie jest dziedziczona!

*klasa T_product - klasa abstrakcyjna oraz podstawowa, na podstawie której dziedziczyć bedą takie klasy jak: T_commodity, T_dry, T_liquid. 
Oprócz wymaganych składowych tj. _ID, _commodity_product, dodatkowo stworzyłam dwie składowe pomocnicze _product_weight - reprezntujaca 
wage pojedycznego produktu np. 1 sztuka czekolady waży 0.1kg lub 1 litr zupy pomidorowej waży 1.2kg ( _product_weight ma na celu późniejsze
operacje związane z udźwigiem paleciaka; _product_weight jest ustawiane przez użytkownika za pomocą funckji składowej setProductWieght).
Składowa x - pomocnicza składowa, która ma zapamiętywać wagę w danym momencie. Większość funkcji składowych klasy T_product została uczyniona 
czysto-wirtualnymi ( co czyni klasę abstrakcyjną ), czego celem jest ulepszona wersja każdej z funkcji, która zostanie zaimplementowana w 
odpowiednich klasach pochodnych. Funkcja czysto-wirtualna virtual T_product* clone() const = 0 ma na celu umożliwienie tworzenia tzw. kopii
głębokiej.

*klasy T_commodity, T_dry oraz T_liquid - klasy pochone od klasy T_product. Reprezentują kolejno towar na sztuki, towar suchy (kg) oraz towar płynny (litry).
W tych klasach zostały zaimplementowane odpowienie wersje funckji wirtualnych oraz operator przypisania, a także konstruktor kopiujący (nie są one dziedziczone).
Przy funkcjach wirtulanych widzimy przydomek 'override', który "prosi" kompilator o ostrzeżenie, w przypadku gdy funckja powinna być zacierana, a nie jest.
Funkcja divide() służy do wydzielenia odpowieniej części towaru( określonej przez użytkownika) z magazynu na paleciak-> utworzenie kopii głębokiej towaru za 
pomocą clone(),a następnie zmiana parametru będącego ilością (x- ilość towaru, która znajduje się już na paleciaku). Natomiast, zadaniem funkcji merge() jest
scalenie towaru z paleciaka z towarem w magazynie. 


*klasa pallet_jack - klasa reprezentująca paleciak. Zawiera wektor wskaźników do obiektów typu T_product ( za sprawą polimorfizmu T_product może być także 
T_commodity, T_dry, T_liqiud). Składowa lifting_capacity określa ilość towaru, która może zostać przyjęta na dany paleciak tj. jeśli udźwig paleciaka wynosi 
2kg to może on przyjąć np. 10 czekolad o wadze(_product_weight)=0.1kg i jakieś produkty, których łączna waga nie przekracza 1kg.
Funckja składowa delete_p usuwa dany produkt z paleciaka.

*klasa T_warehouse - klasa reprezentująca magazyn. Identycznie jak palley_jack zawiera wektor wskaźników do obiektów typu T_product. Klasa T_warehouse została
wzbogacona o funckje składowe bring_out oraz take_over, które odzwierciedlają działania pomiędzy magazynem a paleciakiem. W obu funkjach użyta została
statyczna składowa sum klasy T_product, której definicję widzimy na samej górze pliku .cpp ( tak jak zmienna globalna jest ona inicjalizowana zerem).
Składowa sum jest sumą produktów, znajdujących się na paleciaku - pórwnujemy ją z udźwigiem palciaka, aby zapobiec jego przeciązeniu. Następnie w zależności od
faktu, czy dany towar znajduje się już na paleciaku lub nie, podejmowane są odpowienie działania. Funkcja take_over ściąga dany produkt i scala go z
produktem znajdującym się już w magazynie. Oczywiście, owe "ściągnięcie" należy uzwględnić odejmując produkt od sum. Prodkut jest całkowicie usuwany z paleciaka
za pomocą funckji składowej delete_p.

*klasa extra_vector - zawiera dwa wektory - wektor wskaźników do obiektów typu T_warehouse oraz pallet_jack. Dzięki takiemu rozwiązaniu, użytkownik może 
dodać więcej niż jeden magazyn. Wraz z utworzeniem nowego magazynu, tworzony jest paleciak - obiekty mają takie samo ID. Klasa ta zawiera dwie ważne metody, a
mianowicie choose_warehouse oraz choose_palletJack, które umożliwiają użytkownikowi wybranie magazynu (automatycznie dobierany jest paleciak o odpowiadającym
ID).

*klasa T_warehouse_conv - interfejs użytkownika, został uzupełniony o dwie metody bring_out_ oraz take_over_, które umożliwiają użytkownikowi decyzję o działaniach
między odpowienim magazynem i odpowiadającemu mu paleciakowi. Teraz praktycznie każde działanie jest podjemowane dla magazynu o wybranym ID.



OPIS ETAPU PIERWSZEGO.
Projekt składa się z trzech klas oraz pliku main.cpp.

*klasa T_commodity- opisuje cechy danego produktu; posiada funkcje składowe, które zajmują się poprawnym skonstruowaniem produktu oraz umożliwiają modyfikację składników obiektu tej klasy.
Przeładowanie operatora >> umożliwia wygodne wypisywanie obiektu tej klasy na ekran. Klasa zawiera deklarację statycznego składnika, który jest wspólny dla wszystkich obiektów tej 
klasy, co znacznie ułatwia ustalenie indeksu tego obiektu w wektorze, przy dodawaniu nowego towaru do magazynu. 

*klasa T_magazine- reprezentuje wektor zawierający obiekty klasy T_commodity. Funckja składowa findIndex umożliwia odnalezienie indeksu danego obiektu w wektorze na podstawie ID.
Składnik id_not_found pozwala na sprawdzanie czy poszczególne instrukcje (dodawnie(odejmowanie) towaru do magazynu) mają sens.
W pliku właściwym magazine.cpp znajduje się definicja składowej statycznej klasy T_commodity, ponieważ powinna mieć ona zakres pliku.

*klasa T_magazine_conv-interfejs obsługi użytkownika. Funkcje składowe umieszczone w tej klasie mają na celu optymalizację main'a. Klasa ta zawiera funckję run(), która za pomocą instrukcji
'switch' wywołuje odpowiednie zachowania, o czym decyduje sam użytkownik. 

W main.cpp znajdują się deklaracje obiektów klas T_magazine oraz T_magazine_conv. Na rzecz obiektu klasy T_magazine_conv wywoływana jest funckja składowe run(), która jako argument przyjmuje
referencję do obiektu klasy T_magazine.
