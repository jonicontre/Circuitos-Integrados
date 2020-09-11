/*
el codigo mostrado a continuacion tiene como finalidad
generar las señales para envarise al circuito L293D
para poder generar el giro o detencion del motor
*/

//Configuración de los pines como salidas, que envían las
//señales al circuito integrado
void setup()
{
  pinMode(8, OUTPUT); //pin 8 salida (para motor)
  pinMode(9, OUTPUT); //pin 9 salida (para motor)
  pinMode(13,OUTPUT); //pin 9 salida (para led integrado)
  
  //SALIDAS PARA LEDS
  pinMode(2, OUTPUT); //pin 8 salida (para motor)
  pinMode(3, OUTPUT); //pin 9 salida (para motor)
  pinMode(4,OUTPUT); //pin 9 salida (para led integrado)
  
  //ESTADO INICIAL LEDS APAGADOS
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
}

//funcion cuyo objetivo es encender y apagar led integrado
//en la placa arduino al finalizar el loop
void CambiaLed(){
  digitalWrite(13,!digitalRead(13));
}

void loop()
{
  //LED AZUL AVISO GIRO HORARIO
  digitalWrite(2, HIGH);
  //dos primeras lineas generan las señales para que el circuito
  //integrado permita el giro horario del motor
  digitalWrite(9, HIGH); //se envía señal en 9
  digitalWrite(8, LOW); //se deja de enviar señal en 8
  delay(2000); // Espera 1 segundo (1000 milisegundos)
  
  //LED ROJO AVISO DETENCION MOTOR
  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);
  //dos lineas siguientes generan las señales para que el circuito
  //integrado permita detenga el motor 
  digitalWrite(9, HIGH); //se envía señal en 9
  digitalWrite(8, HIGH); //y se envia señal en 8
  delay(1000); // Espera 1 segundo (1000 milisegundos)
  
  //LED AMARILLO AVISO GIRO ANTIHORARIO
  digitalWrite(3, LOW);
  digitalWrite(4, HIGH);
  //dos siguientes lineas generan las señales para que el circuito
  //integrado permita el giro antihorario del motor
  digitalWrite(8, HIGH); //se envia señal en 8
  digitalWrite(9, LOW); //se deja de enviar señal en 9
  delay(2000); // Espera 1 segundo (1000 milisegundos)
  
  digitalWrite(4, LOW);
  //se llama a funcion led de aviso de fin de loop
  CambiaLed();
}
