#ifndef LED_h
#define LED_h

#include <Arduino.h>

/**
 * @class Led
 * @brief CLasse para controle não bloqueante de um LED.
 * Permite ligar, desligar, ligar por tempo determinado,
 * piscar continuamentee piscar por quantidade definida.
 *
 * @note O método update() deve ser chamado continuamente dentro do loop().
 */
class Led
{
private:
    uint8_t pino;
    bool estado;
    bool desligarPorTempo = false;
    uint32_t desligarNoMomento;

    uint32_t tempoAnteriorPiscar;
    uint32_t tempoEspera;
    bool estadoPiscar;
    uint16_t repeticoes;

    /**
     * @brief Processa a lógica de piscada do LED.
     */
    void funcaoPiscar();

    /**
     * @brief Processa o desligamento temporizado.
     */
    void funcaoDesligamento();

public:
    /**
     * @brief Constrói um objeto LED.
     * @param pin Número do pino digital onde o LED está conectado.
     */
    Led(uint8_t pin);
    /**
     * @brief Liga o LED continuamente.
     */
    void ligar();

    /**
     *  @brief Liga o LED por um tempo determinado.
     *   @param tempoLigado_ms Tempo, em milissegundos que o LED ficará ligado.
     */
    void ligar(uint32_t tempoLigado_ms);

    /**
     *  @brief Desliga o LED e cancela os modos automáticos.
     */
    void desligar();
    /**
     * @brief Inicia a piscada contínua em 1 Hz.
     */
    void piscar();
    /**
     * @brief Pisca o LED em uma freqência definida e uma quantidade indefinida.
     * @param frequencia Frequência da piscada em Hz.
     */
    void piscar(float frequencia);
    /**
     * @brief Pisca o LED uma quantidade e uma frequência definida de vezes.
     * @param frequencia Frequência da piscada em Hz.
     * @param repeticoes Quantidade de piscadas completas.
     */
    void piscar(float frequencia, uint16_t repeticoes);
    /**
     * @brief Pega o estado do LED.
     */
    bool getEstado();
    /**
     * @brief Pega o pino do LED.
     */
    uint8_t getPino();
    /**
     * @brief Define o estado do LED.
     * @param estado true para ligado, falso para desligado.
     */
    void setEstado(bool estado);
    /**
     * @brief altera o estado do LED.
     */
    void alternar();
    /**
     * @brief Coloca as mudanças em prática.
     */
    void update();
};

#endif