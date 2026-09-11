#include "Arduino.h"
#include "model/VoltageSensor.h"
#include "Mux.h"

VoltageSensor::VoltageSensor(int pin){
    this->pin = pin;
}

float VoltageSensor::voltageRead(int pin, admux::Mux& mux){
  const float CALIBRATION_FACTOR = 0.105; //valor do sensor q vai valer 1v de tensao
  long sampleCount = 0;
  double sumOfSquares = 0;
  int starterTime = micros(); //tempo em que essa amostra foi iniciada
  mux.channel(pin);

  //------------------------------------------------------------------
  //eu acho q vou mandar o valor do analogico ja lido pelo multiplex
  //------------------------------------------------------------------
  
  while (micros() - starterTime < 16666) { //aqui estara sendo lido um ciclo de um rede de 60hz (1,000,000 / 60 = 16666) (caso de algum numero esquisito ler 2 ciclos 33333)
    float rawValue = mux.read(); //valor do pino analogico recebido pelo sensor de tensao
    float voltageOffset = rawValue - 2048; //o numero maximo de bits q o esp32 le e 4096, sendo q o ponto 0 é no 2.5 entao é feito (- 2048) para ler apartir do ponto 0
    sumOfSquares += (double)(voltageOffset * voltageOffset); //os numeros sao elevados a dois para ignorar a diferença de sinais que a onda senoidal faz (1000 * 1000 = 1.000.000, (-1000) * (-1000) = 1.000.000 = 2.000.000)
    sampleCount++; //conta quantos ciclos foram contados (2), um positivo e outro negativo, pois em 16666 micros segundos é um ciclo completo
  }
  
  float meanSquare = sumOfSquares / sampleCount; //media da quantidade de cliclos com a soma dos quadrados que foram tiradas naquele ciclo (acima esta a explicaçao) (2.000.000 / 2 = 1.000.000)
  float rawRms = sqrt(meanSquare); //raiz quadrada que vai ser igual a media das amostras (continunado o exemplo de cima seria 1000)
  float realVoltageAC = rawRms * CALIBRATION_FACTOR; //aquilo q vai me dar o valor real em volts com a calibraçao do meu sensor (1000 * 0.105 = 105v)


  if (realVoltageAC < 5.0) {
    realVoltageAC = 0.0;
  }

  return realVoltageAC;
}