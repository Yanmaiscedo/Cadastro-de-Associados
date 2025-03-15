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


int main()
{
    vector<Associado> associados;
    vector<Dependente> dependentes;
    vector<Visitante> visitantes;
    vector<Visitas> visitas;

    return 0;
}