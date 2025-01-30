#include <iostream>
#include <vector>
#include <string>

class conta {
    protected:
        int saldo;
        std::string tipoconta;
        std::string tipocliente;
    public:
        conta(int saldo, std::string tipoconta, std::string tipocliente) 
            : saldo(saldo), tipoconta(tipoconta), tipocliente(tipocliente) {}

        void deposito(int valor) {
            saldo += valor;
        }

        void saque(int valor) {
            if (valor <= saldo) {
                saldo -= valor;
            } else {
                std::cout << "Saldo insuficiente!" << std::endl;
            }
        }

        void extrato() const {
            std::cout << "Tipo de conta: " << tipoconta << "\n"
                      << "Tipo de cliente: " << tipocliente << "\n"
                      << "Saldo: " << saldo << std::endl;
        }

        int getSaldo() const {
            return saldo;
        }
};

class poupanca : public conta {
    public:
        poupanca(int saldo, std::string tipoconta, std::string tipocliente) 
            : conta(saldo, tipoconta, tipocliente) {}
};

class investimento : public conta {
    public:
        investimento(int saldo, std::string tipoconta, std::string tipocliente) 
            : conta(saldo, tipoconta, tipocliente) {}
};

bool verificarsaldototal(const std::vector<conta*>& contas, int valortransacao) {
    int saldoTotal = 0;
    for (const auto& conta : contas) {
        saldoTotal += conta->getSaldo();
    }

    return saldoTotal >= valortransacao;
}

int main() {
    std::vector<conta*> contas;

    poupanca p1(1000, "poupanca", "fisica");
    investimento i1(1000, "investimento", "fisica");

    p1.deposito(100);
    p1.saque(1000);

    i1.deposito(100);
    i1.saque(1000);

    contas.push_back(&p1);
    contas.push_back(&i1);

    
    if (verificarsaldototal(contas, 200)) {
        std::cout << "Transacao realizada com sucesso!" << std::endl;
    } else {
        std::cout << "Saldo total insuficiente!" << std::endl;
    }

    return 0;
}
