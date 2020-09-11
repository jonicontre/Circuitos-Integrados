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
}

//funcion cuyo objetivo es encender y apagar led integrado
//en la placa arduino al finalizar el loop
void CambiaLed(){
  digitalWrite(13,!digitalRead(13));
}

void loop()
{
  //dos primeras lineas generan las señales para que el circuito
  //integrado permita el giro horario del motor
  digitalWrite(9, HIGH); //se envía señal en 9
  digitalWrite(8, LOW); //se deja de enviar señal en 8
  delay(1000); // Espera 1 segundo (1000 milisegundos)
  //dos lineas siguientes generan las señales para que el circuito
  //integrado permita detenga el motor 
  digitalWrite(9, HIGH); //se envía señal en 9
  digitalWrite(8, HIGH); //y se envia señal en 8
  delay(500); // Espera 1 segundo (1000 milisegundos)
  //dos siguientes lineas generan las señales para que el circuito
  //integrado permita el giro antihorario del motor
  digitalWrite(8, HIGH); //se envia señal en 8
  digitalWrite(9, LOW); //se deja de enviar señal en 9
  delay(1000); // Espera 1 segundo (1000 milisegundos)
  //se llama a funcion led de aviso de fin de loop
  CambiaLed();
}