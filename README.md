# 🚦 Semáforo com Temporizador Usando Raspberry Pi Pico W

Este projeto implementa um **semáforo** utilizando a função **`add_repeating_timer_ms()`** do **Pico SDK**, garantindo a troca automática das cores dos LEDs em um intervalo de **3 segundos**.

## 📌 Funcionamento
1. O semáforo inicia na **cor vermelha**.
2. Após **3 segundos**, troca para **amarelo**.
3. Depois de mais **3 segundos**, muda para **verde**.
4. O ciclo se repete continuamente.

Além disso, a **mensagem de status do semáforo** é enviada via **porta serial a cada 1 segundo**.

## 🛠 Componentes Utilizados
- Raspberry Pi Pico W
- 3 LEDs (Vermelho, Amarelo e Verde)
- 3 Resistores de 330Ω

## 🖥️ Instalação e Configuração

### 1️⃣ Configurar o Pico SDK
Antes de compilar, o **Pico SDK** deve estar instalado. Se ainda não configurou, siga os passos:

```sh
export PICO_SDK_PATH=/<caminho_para_o_pico-sdk>
2️⃣ Clonar o Repositório

git clone https://github.com/seu-usuario/seu-repositorio.git
cd seu-repositorio

3️⃣ Compilar o Código

    Criar a pasta de build:

mkdir build && cd build

Executar o CMake:

cmake ..

Rodar o Make:

    make

Após a compilação, um arquivo .uf2 será gerado.
4️⃣ Executar no Hardware

    Conecte o Raspberry Pi Pico W ao PC segurando o BOOTSEL.
    Arraste o arquivo semaforo.uf2 para a unidade do Pico.
    O código será executado automaticamente. 🚦

5️⃣ Executar no Wokwi

Se quiser testar no simulador Wokwi, siga estes passos:

    Instale o Wokwi CLI (se ainda não tiver):

npm install -g wokwi-server

Rode o simulador com:

    wokwi-server diagram.json

📜 Código-Fonte
Arquivo: semaforo.c

O código principal está no arquivo semaforo.c e segue o seguinte fluxo:

    Usa add_repeating_timer_ms() → Alterna os LEDs a cada 3 segundos.
    Imprime mensagens na porta serial → A cada 1 segundo.
    Ciclo contínuo → O semáforo segue um fluxo vermelho → amarelo → verde → vermelho.

Arquivo: diagram.json

Define a simulação no Wokwi, com os componentes corretamente conectados.