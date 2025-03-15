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

void cadastrar_dependente(vector<Dependente> &dependentes)
{
    int opc;
    cout << "Voce deseja adicionar um novo Dependente ou fazer a manutenção do cadastro de um dependente ja existente? " << endl;
    cout << "1 - Adicionar novo Dependente " << endl;
    cout << "2 - Fazer a manutenção de um Cadastro " << endl;
    cin >> opc;
    if (opc == 1)
    {
        Dependente novoDependente;

        cin.ignore();

        cout << "nome: ";
        getline(cin, novoDependente.nome);

        cout << "idade: ";
        cin >> novoDependente.idade;

        cin.ignore();

        cout << "cpf: ";
        getline(cin, novoDependente.cpf_associado);

        dependentes.push_back(novoDependente);
    }
    else if (opc == 2)
    {
        cout << "Digite o índice do cadastro que deseja alterar: ";
        int indice;
        cin >> indice;

        if (indice >= 0 && indice < dependentes.size())
        {
            cin.ignore();

            cout << "Novo nome: ";
            getline(cin, dependentes[indice].nome);

            cout << "Nova idade: ";
            cin >> dependentes[indice].idade;

            cin.ignore();

            cout << "Novo cpf: ";
            getline(cin, dependentes[indice].cpf_associado);

            cout << "Cadastro alterado com sucesso!" << endl;
        }
        else
        {
            cout << "Índice inválido." << endl;
        }
    }
}

void cadastrar_visitante(vector<Visitante> &visitantes)
{
    int opc;
    cout << "Voce deseja adicionar um novo visitante ou fazer a manutenção do cadastro de um visitante ja existente? " << endl;
    cout << "1 - Adicionar novo visitante " << endl;
    cout << "2 - Fazer a manutenção de um Cadastro " << endl;
    cin >> opc;
    if (opc == 1)
    {
        Visitante novoV;

        cin.ignore();

        cout << "nome: ";
        getline(cin, novoV.nome);

        cout << "idade: ";
        cin >> novoV.idade;

        cin.ignore();

        cout << "cpf: ";
        getline(cin, novoV.cpf_associado);

        visitantes.push_back(novoV);
    }
    else if (opc == 2)
    {
        cout << "Digite o índice do cadastro que deseja alterar: ";
        int indice;
        cin >> indice;

        if (indice >= 0 && indice < visitantes.size())
        {
            cin.ignore();

            cout << "Novo nome: ";
            getline(cin, visitantes[indice].nome);

            cout << "Nova idade: ";
            cin >> visitantes[indice].idade;

            cin.ignore();

            cout << "Novo cpf: ";
            getline(cin, visitantes[indice].cpf_associado);

            cout << "Cadastro alterado com sucesso!" << endl;
        }
        else
        {
            cout << "Índice inválido." << endl;
        }
    }
}

void cadastrar_visita(vector<Visitas> &visitas)
{
    Visitas novaVisita;

    cin.ignore();
    cout << "===Nova Visita===" << endl;

    cout << "nome: ";
    getline(cin, novaVisita.nome);

    cout << "idade: ";
    cin >> novaVisita.idade;

    cin.ignore();

    cout << "cpf: ";
    getline(cin, novaVisita.cpf_associado);

    cout << "data de entrada: ";
    getline(cin, novaVisita.dt_entrada);

    cout << "data de saida: ";
    getline(cin, novaVisita.dt_saida);

    visitas.push_back(novaVisita);
}

void relatorio_associados(const std::vector<Associado> &associados, const vector<Dependente> &dependentes)
{
    cout << endl
         << "Relatório de Associados:" << endl;
    for (size_t i = 0; i < associados.size(); ++i)
    {
        cout << "Associado - "
             << "Índice: " << i << ", Nome: " << associados[i].nome << ", Idade: " << associados[i].idade << ", cpf: " << associados[i].cpf << endl;
        for (size_t i = 0; i < dependentes.size(); ++i)
        {
            if (dependentes[i].cpf_associado == associados[i].cpf)
            {
                cout << "  "
                     << "Dependente - "
                     << "Índice: " << i << ", Nome: " << dependentes[i].nome << ", Idade: " << dependentes[i].idade << ", cpf: " << dependentes[i].cpf_associado << endl;
            }
        }
        cout << endl;
    }
    cout << endl;
}

void relatorio_visitas(const vector<Visitas> &visitas, const std::vector<Associado> &associados) // IGUALAR AO DE ASSOCIADO
{
    cout << endl
         << "Relatório de visitas:" << endl;
    for (size_t i = 0; i < associados.size(); ++i)
    {
        cout << "Associado - "
             << "Índice: " << i << ", Nome: " << associados[i].nome << ", Idade: " << associados[i].idade << ", cpf: " << associados[i].cpf << endl;
        for (size_t i = 0; i < visitas.size(); ++i)
        {
            cout << "    Índice: " << i << ", Nome: " << visitas[i].nome << ", Idade: " << visitas[i].idade << ", cpf: " << visitas[i].cpf_associado << endl
                 << "     entrada: " << visitas[i].dt_entrada << ", saida: " << visitas[i].dt_saida << endl;
        }
        cout << endl;
    }
    cout << endl;
}




int main()
{
    vector<Associado> associados;
    vector<Dependente> dependentes;
    vector<Visitante> visitantes;
    vector<Visitas> visitas;

    return 0;
}