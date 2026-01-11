#include <iostream>
#include <cstdlib>
#include <ctime>
#include <array>

using namespace std;

class Tabuleiro {
    char tabuleiro[3][3];

    public:
        Tabuleiro() {
            redefinir();
        }

        void redefinir() {
            for(int i = 0; i < 3; i++) {
                for(int j = 0; j < 3; j++) {
                    tabuleiro[i][j] = ' ';
                }
            }
        }

        void exibir() {
            cout << "\n\n|-------------|" << endl;
            cout << "|  Tabuleiro  |" << endl;
            cout << "|-------------|\n" << endl;
            cout << "     0 1 2\n" << endl;
            for(int i = 0; i < 3; i++) {
                cout << " " << i << "   ";
                for(int j = 0; j < 3; j++) {
                    cout << tabuleiro[i][j];
                    if(j != 2) cout << "|";
                }
                cout << endl;
                if(i != 2) cout << "    -------" << endl;
            }
        }

        bool estaLivre(int linha, int coluna) {
            return tabuleiro[linha][coluna] == ' ';
        }

        bool atualizar(char peca, int linha, int coluna) {
            if(estaLivre(linha, coluna)) {
                tabuleiro[linha][coluna] = peca;
                return true;
            }

            return false;
        }

        bool verificarSequencia(char peca) {
            int contador = 0;
            for(int i = 0; i < 3; i++) {
                if(tabuleiro[0][i] == peca) {
                    contador++;
                }
            }
            if(contador == 3) return true;


            contador = 0;
            for(int i = 0; i < 3; i++) {
                if(tabuleiro[1][i] == peca) {
                    contador++;
                }
            }
            if(contador == 3) return true;

            contador = 0;
            for(int i = 0; i < 3; i++) {
                if(tabuleiro[2][i] == peca) {
                    contador++;
                }
            }
            if(contador == 3) return true;

            contador = 0;
            for(int i = 0; i < 3; i++) {
                if(tabuleiro[i][0] == peca) {
                    contador++;
                }
            }
            if(contador == 3) return true;

            contador = 0;
            for(int i = 0; i < 3; i++) {
                if(tabuleiro[i][1] == peca) {
                    contador++;
                }
            }
            if(contador == 3) return true;

            contador = 0;
            for(int i = 0; i < 3; i++) {
                if(tabuleiro[i][2] == peca) {
                    contador++;
                }
            }
            if(contador == 3) return true;

            contador = 0;
            for(int i = 0; i < 3; i++) {
                if(tabuleiro[i][i] == peca) {
                    contador++;
                }
            }
            if(contador == 3) return true;

            contador = 0;
            for(int i = 0; i < 3; i++) {
                for(int j = 2; j >= 0; j--) {
                    if(tabuleiro[i][j]) {
                        contador++;
                    }
                }
            }
            if(contador == 3) return true;

            return false;
        }
};

class JogoDaVelha {
    inline static Tabuleiro tabuleiro;
    inline static int jogadasPossiveis[9][2] = {
        {0,0},
        {0,1},
        {0,2},
        {1,0},
        {1,1},
        {1,2},
        {2,0},
        {2,1},
        {2,2}
    };

    inline static int jogadasRestantes = 9;

    public:
        static void iniciar() {
            char op;
            cout << "Deseja jogar o 'Jogo da Velha' (S/N)? ";
            cin >> op;
            if(op == 's' || op == 'S') {
                while(true) {
                    cout << "\n           v\n           v\n           v" << endl;

                    int opcao = exibirMenu();

                    switch(opcao) {
                    case 1:
                        jogar(true);
                        break;
                    case 2:
                        jogar(false);
                        break;
                    default:
                        cout << "\nOpção inválida!" << endl;
                    }
                    cout << "\nSair (S/N)? ";
                    cin >> op;
                    if(op == 's' || op == 'S') { 
                        cout << "\n\nSaindo..." << endl;
                        break;
                    }

                    tabuleiro.redefinir();
                    redefinirJogadasPossiveis();
                }
            }
        }

        static void jogar(bool solo) {
            bool haVencedor = false;
            int jogadas = 0;
            int vencedor = -1;
            int linha;
            int coluna;
            bool ok;

            while(jogadas < 9) {
                tabuleiro.exibir();
                ok = true;

                if(jogadas > 4) {
                    vencedor = buscarVencedor();
                    if(vencedor == 1 || vencedor == 2) {
                        haVencedor = true;
                        break;
                    }
                }

                if(jogadas % 2 == 0) {
                    do {
                        cout << "\nPeça X:" << endl;
                        cout << "  -> Linha: ";
                        cin >> linha;
                        cout << "  -> Coluna: ";
                        cin >> coluna;
                        int jogada[2] = {linha, coluna};
                        int indiceJogada = obterIndiceJogada(jogada);
                        if(removerJogada(indiceJogada)) {
                           fazerJogada('X', linha, coluna);
                           ok = true;
                        } else {
                            ok = false;
                        }
                    } while(!ok);
                } else {
                    if(solo) {
                        cout << "\n\nComputador pensando...\n" << endl;
                        do {
                            int indice = gerarIndice();
                            auto jogada = obterJogada(indice);
                            if(removerJogada(indice)) {
                                fazerJogada('O', jogada[0], jogada[1]);
                                ok = true;
                            } else {
                                ok = false;
                            }
                        } while(!ok);
                    } else {
                        do {
                            cout << "\nPeça O:" << endl;
                            cout << "  -> Linha: ";
                            cin >> linha;
                            cout << "  -> Coluna: ";
                            cin >> coluna;
                            int jogada[2] = {linha, coluna};
                            int indiceJogada = obterIndiceJogada(jogada);
                            if(removerJogada(indiceJogada)) {
                            fazerJogada('O', linha, coluna);
                            ok = true;
                            } else {
                                ok = false;
                            }
                        } while(!ok);
                    }
                }

                if(jogadas > 4) {
                    vencedor = buscarVencedor();
                    if(vencedor == 1 || vencedor == 2) {
                        haVencedor = true;
                        break;
                    }
                }
                jogadas++;
            }

            cout << "\n\n\n ---> Fim de jogo! <---" << endl;
            tabuleiro.exibir();
            cout << endl;
            if(haVencedor) {
                if(vencedor == 1) cout << "'X' venceu!" << endl;
                else cout << "'O' venceu!" << endl;
            } else {
                cout << "Deu Velha!" << endl;
            }
            cout << " -------->  <--------" << endl;
        }

        static int exibirMenu() {
            int opcao;
            cout << "\n|---------------------|" << endl;
            cout << "|    Jogo da Velha    |" << endl;
            cout << "|---------------------|" << endl;
            cout << "| Escolha uma opção:  |" << endl;
            cout << "|  1 - Um jogador     |" << endl;
            cout << "|  2 - Dois jogadores |" << endl;
            cout << "|---------------------|" << endl;
            cout << "--> ";
            cin >> opcao;

            return opcao;
        }

        static int buscarVencedor() {
            if(tabuleiro.verificarSequencia('X')) return 1;

            if(tabuleiro.verificarSequencia('O')) return 2;

            return 0;
        }

        static bool fazerJogada(char peca, int linha, int coluna) {
            if((linha < 0 || linha > 2) || (coluna < 0 || coluna > 2)) return false;

            return tabuleiro.atualizar(peca, linha, coluna);
        }

        static int gerarIndice() {
            srand(time(0));

            return rand() % jogadasRestantes;
        }

        static void redefinirJogadasPossiveis() {
            int a, b, c;
            a = b = c = 0;
            for(int i = 0; i < 9; i++) {
                if(i < 3) {
                    jogadasPossiveis[i][0] = 0;
                    jogadasPossiveis[i][1] = a++; // 'a' só será incrementada depois que essa instrução (instrução é aquilo que terminar com ;) for executada
                } else if(i < 6) {
                    jogadasPossiveis[i][0] = 1;
                    jogadasPossiveis[i][1] = b++; // 'b' só será incrementada depois que essa instrução (instrução é aquilo que terminar com ;) for executada
                } else {
                    jogadasPossiveis[i][0] = 2;
                    jogadasPossiveis[i][1] = c++; // 'c' só será incrementada depois que essa instrução (instrução é aquilo que terminar com ;) for executada
                }
            }

            jogadasRestantes = 9;
        }

        static int obterIndiceJogada(int (&jogada)[2]) {
            int indice = -1;

            for(int i = 0; i < jogadasRestantes; i++) {
                if(jogada[0] == jogadasPossiveis[i][0] && jogada[1] == jogadasPossiveis[i][1]) indice = i;
            }

            return indice;
        }

        static bool removerJogada(int indice) {
            if(indice < 0 || indice >= jogadasRestantes) return false;

            for(int i = indice; i < jogadasRestantes - 1; i++) {
                jogadasPossiveis[i][0] = jogadasPossiveis[i+1][0];
                jogadasPossiveis[i][1] = jogadasPossiveis[i+1][1];
            }
            jogadasRestantes--;

            return true;
        }

        static std::array<int, 2> obterJogada(int indice) {
            int linha;
            int coluna;

            for(int i = 0; i < jogadasRestantes; i++) {
                if(indice == i) {
                    linha = jogadasPossiveis[i][0];
                    coluna = jogadasPossiveis[i][1];
                }
            }
            return {linha, coluna};
        }
};

int main() {
    JogoDaVelha::iniciar();
    return 0;
}