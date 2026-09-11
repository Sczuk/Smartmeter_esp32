#include "Arduino.h"
#include "model/CurrentSensor.h"
#include "Mux.h"

using namespace admux;

CurrentSensor::CurrentSensor(int pin){
    this->pin = pin;
}

float CurrentSensor::currentRead(int pin, admux::Mux& mux){
    float biggestVoltage = 0;
    const float sensi = 0.066; 
    mux.channel(pin);
    //a sensibilidade é a relaçao da tensao com o ganho na unidade ex:
    // para cada 0.066v é 1a, entao caso o sensor mande para o esp32 0.12 seria 2a
    //limitando o maximo q o sensor vai ser capaz de medir (no nosso caso 2.5v/0.066a = 37.8a) o ponto zero é 2.5v
    int starterTime = micros(); //contagem de tempo em milisegundos

    //------------------------------------------------------------------
    //eu acho q vou mandar o valor do analogico ja lido pelo multiplex
    //------------------------------------------------------------------
    
    while((micros() - starterTime) < 16666) { //numero aproximado para uma rede de 60hz ((1 segundo em mili)1000 ÷ 60 = 16,67 ms) (16666 microsegundos)
        int leituraADC = mux.read(); //faz a leitura do pino analogico, convertendo a tensao em bits fazendo uma regra de tres da tensao maxima do esp32 com a os bits maximos
        float voltage = (leituraADC * 5.0) / 4096.0; 
        // Converte para Volts, 
        //5.0 é a tensao que o sensor esta sendo carregado, 
        //4095 valor maximo do esp32 na porta analogica (12 bits) 
    
        // Procura o valor de pico (máximo) da onda
        if (voltage > biggestVoltage) {
          biggestVoltage = voltage;
        }
    }

    //calculos para descobrir a corrente:
    //primeiro descobrir a corrente pico
    //segundo descobrir a corrente eficaz (Eficaz = Pico * 0.707) (0.707 raiz de 0.5)

    float voltagePeak = biggestVoltage - 3.43; //Como a porta analogica nao pode receber uma tensao negativa, e ela esta sendo carergada por 5v o ponto "0" dela é 2.5, entao se subtrai 2.5 para q a leitura seja baaseada no ponto 0 real
    //coloquei 3.43 pois o ponto "0" nao esta em 2.5 volts
    if(voltagePeak < 0) voltagePeak = 0;
    float currentPeak = voltagePeak / sensi; //recebe a voltagem pico e converte com base na nossa sensibilidade para correntePico
    float currentEffective = currentPeak * 0.707; //converte a nossa correntePico para corrente eficaz
    //corrente eficaz seria o quanto a corrente ac(alternada) seria em dc(continua), o quanto "realmente" esta sendo usado
    return currentEffective;
}