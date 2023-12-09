#include <stdio.h>
#include <string.h>
#include <locale.h>


// Função para responder à pergunta
const char* responderPergunta(const char* pergunta) {
    const char* resposta = "Desculpe, não entendi a pergunta.";

    if (strstr(pergunta, "horário") != NULL || strstr(pergunta, "horario") != NULL || strstr(pergunta, "horarios") != NULL) {
        resposta = "Estamos abertos de segunda a sexta, das 8h às 18h, e aos sábados, das 8h às 14h.";
    } else if (strstr(pergunta, "produtos") != NULL || strstr(pergunta, "produto") != NULL) {
        resposta = "Oferecemos uma variedade de produtos naturais, incluindo suplementos, alimentos orgânicos e produtos de cuidados pessoais.";
    } else if (strstr(pergunta, "pedido") != NULL) {
        resposta = "Sim, aceitamos pedidos online através do nosso site. Você pode fazer seu pedido e escolher a opção de entrega.";
    } else if (strstr(pergunta, "localização") != NULL || strstr(pergunta, "localizacao") != NULL) {
        resposta = "Estamos localizados na Avenida Couto Magalhães, 1776, Cidade Várzea Grande | \nRua Feliciano Galdino, 585, Cidade Cuiabá | \nRua Joaquin Murtinho, 319, Cidade Cuiabá | \n. Venha nos visitar!";
    }

    return resposta;
}

int main() {
    setlocale(LC_ALL, "Portuguese");

    char pergunta[256];

    // Loop para continuar a conversa até que a pessoa digite "sair"
    while (1) {
        // Solicitação da pergunta a partir do terminal
        printf("Digite sua pergunta (ou 'sair' para encerrar): ");
        fgets(pergunta, sizeof(pergunta), stdin);

        // Remover o caractere de nova linha (\n) no final da pergunta, se existir
        if (pergunta[strlen(pergunta) - 1] == '\n') {
            pergunta[strlen(pergunta) - 1] = '\0';
        }

        // Verificar se a pessoa deseja sair
        if (strcmp(pergunta, "sair") == 0) {
            printf("Encerrando a conversa. Até mais!\n");
            break;
        }

        // Chamada da função responderPergunta
        const char* respostaDoChatbot = responderPergunta(pergunta);

        // Exibição da resposta no terminal
        printf("Resposta: %s\n", respostaDoChatbot);
    }

    return 0;
}
