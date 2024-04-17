#include <vector>
#include <iostream>
using namespace std;

void alterarLista(vector<int>* l)
{
    int num;
    for (int i = 1; i <= 5; i++) {
        cout << "digite numero" << endl;
        cin >> num ;
        l->push_back(num);
    }
}

int main()
{
    vector<int> lista;
    alterarLista(&lista);

    for (const auto& num : lista) {
        cout << "numeros: " << num << endl;
    }
    
    return 0;
}
