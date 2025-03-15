#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

struct Associado
{
    string nome;
    int idade;
    string cpf;
};
struct Dependente
{
    string nome;
    int idade;
    string cpf_associado;
};
struct Visitante
{
    string nome;
    int idade;
    string cpf_associado;
};
struct Visitas
{
    string nome;
    int idade;
    string cpf_associado;
    string dt_entrada;
    string dt_saida;
};

void cadastrar_associado(vector<Associado> &associados)
{
    int opc;
    cout << "Voce deseja adicionar um novo Associado ou fazer a manutenção do cadastro de um associado ja existente? " << endl;
    cout << "1 - Adicionar novo associado " << endl;
    cout << "2 - Fazer a manutenção de um Cadastro " << endl;
    cin >> opc;
    if (opc == 1)
    {
        Associado novoAssociado;

        cin.ignore();

        cout << "nome: ";
        getline(cin, novoAssociado.nome);

        cout << "idade: ";
        cin >> novoAssociado.idade;

        cin.ignore();

        cout << "cpf: ";
        getline(cin, novoAssociado.cpf);

        associados.push_back(novoAssociado);
    }
    else if (opc == 2)
    {
        cout << "Digite o índice do cadastro que deseja alterar: ";
        int indice;
        cin >> indice;

        if (indice >= 0 && indice < associados.size())
        {
            cin.ignore();

            cout << "Novo nome: ";
            getline(cin, associados[indice].nome);

            cout << "Nova idade: ";
            cin >> associados[indice].idade;

            cin.ignore();

            cout << "Novo cpf: ";
            getline(cin, associados[indice].cpf);

            cout << "Cadastro alterado com sucesso!" << endl;
        }
        else
        {
            cout << "Índice inválido." << endl;
        }
    }
}


int main()
{
    vector<Associado> associados;
    vector<Dependente> dependentes;
    vector<Visitante> visitantes;
    vector<Visitas> visitas;

    return 0;
}