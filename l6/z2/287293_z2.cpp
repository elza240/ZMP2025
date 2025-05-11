#include <iostream>
using namespace std;

bool ValInTree(int tab[],int n,int s){
    bool wskaznik=false;
    for (int i=0;i<n;i++){
        if (tab[i]==s){
            wskaznik=true;
        }
    }
    return wskaznik;
    //idziemy po kazdym elemencie tablicy i sprawdzamy czy jest taki jak szukany, jesli tak to zwracamy true (s w tablicy)
}

struct node{
    int value;
    node *left;
    node *right;
    node(int w):value(w),left(nullptr),right(nullptr){}
}; //definiujemy strukture z wartoscia i wskaznikami prawo lewo
// na poczatku prawo lewo puste 

node* merge(node* root1, node* root2, int r){
    node* root = new node(r);
    root->left=root1;
    root->right=root2;
    return root;
} // robimy nowy wezel i do niego podlaczamy z jednej strony jedna drzewo
// a z drugiej drugie drzewo

node* tree(int liczby[],int leftend, int rightend){
    if (leftend>rightend){
        return nullptr;
    }
    node* root=new node(liczby[0]);
    int mid =(leftend+rightend)/2;
    root->left=tree(liczby,leftend+1,mid);
    root->right=tree(liczby, mid+1,rightend);
    
}//jesli wyszlismy poza zakres to koniec szukania
// jesli nie to znajdujemy srodek zakresu, dzielimy go na dwa,
// polowe wspiujemy po jednej stronie drzewa, polowe po drugiej

node* buildtree(int liczby[], int n){
    return tree(liczby, 0, n-1);
} //bierzemy tablice w przedziale od poczatku do konca i robimy rekurencyjnie drzewo

int height(node* root){
    if(!root){
        return 0;
    }
    else{
        return max(height(root->left), height(root->right))+1;
    }
} //jesli drzewo puste to 0, jesli nie to bierzemy najwieksza wartosc 
// z obu galezi + 1 bo r doliczamy


int main(){
    int n1, n2,r, s;
    cin>> n1 >> n2 >> r >> s;
    int *liczby1=new int [n1];
    int *liczby2=new int [n2];
    for (int i=0; i<n1;i++){
        cin >> liczby1[i];
    }
    for (int i=0; i<n2;i++){
        cin >> liczby2[i];
    } //wpisujemy dane wejsciowe
    node* root1=buildtree(liczby1,n1);
    node* root2=buildtree(liczby2,n2);
    node* root=merge(root1,root2, r); // robimy drzewa i je laczymy
    cout << height(root)<<endl; //sprawdzamy wysokosc drzewa
    if (ValInTree(liczby1,n1,s)==true || ValInTree(liczby2,n2,s)==true||r==s){
        cout<<s<< " należy do drzewa";
    }
    else{
        cout <<s<<" nie należy do drzewa";
    } //drzewo zawiera s jesli n1 lub n2 lub r zawieraja s

    return 0;
}