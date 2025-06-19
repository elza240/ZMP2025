// Użyj klas do zareprezentowania różnych typów pojazdów. W tym celu stwórz klasę bazową Pojazd z polami marka, model, rok produkcji; 
// oraz klasy dziedziczące Samochód z dodatkowym polem liczba drzwi i Rower z polem liczba przerzutek. Napisz dla nich odpowiednie metody 
// do generowania obiektów tych klas i ich wyświetlania. Zadbaj o hermetyzację. Użyj poprawnie konstruktorów. Wtedy, gdy ma to sens, 
// przeciąż metody klasy bazowej w klasach dziedziczących. Na potrzeby testów załóżmy, że na standardowym wejściu przyjdzie 8 argumentów 
// oznaczające kolejno dane samochodu i dane roweru, a na wyjściu zostaną one estetycznie wyświetlone.

#include <iostream>
using namespace std;

class Pojazd{

protected:
    string marka;
    string model;
    int rok_produkcji;

public:
    Pojazd();
    Pojazd(string a, string b, int c){
        marka = a;
        model = b;
        rok_produkcji = c; 
    }
    void show(){
        cout<<endl<<"Dane samochodu:\n";
        cout<<"Marka: " <<marka<<endl;
        cout<<"Model: "<<model<<endl;
    }
};

class Samochod:protected Pojazd{

private:
    int liczba_drzwi;

public:
    Samochod(){};
    Samochod(string a, string b, int c, int d) : Pojazd(a,b,c), liczba_drzwi(d) {}
    void show(){
        cout<<endl<<"Dane samochodu:\n";
        cout<<"Marka: " <<marka<<endl;
        cout<<"Model: "<<model<<endl;
        cout<<"Rok produkcji: "<<rok_produkcji<<endl;
        cout<<"Liczba drzwi: "<<liczba_drzwi<<endl;
    }
};

class Rower:protected Pojazd{

private:
    int liczba_przerzutek;

public:
    Rower(){};
    Rower(string a, string b, int c, int e) : Pojazd(a,b,c), liczba_przerzutek(e){};
    
    void show(){
        cout<<endl<<"Dane roweru:\n";
        cout<<"Marka: " <<marka<<endl;
        cout<<"Model: "<<model<<endl;
        cout<<"Rok produkcji: "<<rok_produkcji<<endl;
        cout<<"Liczba przerzutek: "<<liczba_przerzutek<<endl;
    }
};

int main(){

    string a,b, e,f; 
    int c,d,g,h;
    cin >> a>>b>>c>>d>>e>>f>>g>>h;
    
    Samochod samochod(a,b,c,d);
    samochod.show();
    Rower rower(e,f,g,h);
    rower.show();
    return 0;
}
