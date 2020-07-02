//Creado por: Kevin Martinez
//E-mail: kevin.martinez1@udea.edu.co

//Ejemplo de interrupciones

//Resumen:
//El codigo consiste en un sistema que constantemente esta
//sacando por el puerto serial la palabra "Hola" y cada dos
//segundos el sistema se interrumpe para encernder o apagar
//el LED que viene ligado al Pin 13 de Arduino (Sí el LEd esta
//apagado se va a encender, si está encendido se va a apagar).

//Variables que determinan cuando van a pasar los
//dos segundos para hacer la interrupción.
long long int tiempo1=0, tiempo2=0;

//Variables boolenanas:
//*cont: controla el tiempo inicial
//*estado: controla el estado del LED para que sea alternante
bool estado=false, cont=true;

void setup()
{
  //Se usa el pin 13 que tiene ligado el LED de Arduino
  pinMode(13, OUTPUT);
  
  //Se inicializa el puesto serial a 9600 baudios
  Serial.begin(9600);
}

void loop()
{
  //Esta condicion solo se cumple cuando debemos
  //tomar el tiempo inicial porque una vez entra a este IF
  //la variable cont se niega y no entra hasta que concluyan
  //los dos segundos de la interrupcion.
  if(cont){
  	tiempo1=millis(); //Toma el tiempo inicial
    cont=!cont; //Niega la variable cont
  }
  
  tiempo2=millis(); //Toma el tiempo final
  
  //Aqui se verifica si el tiempo final menos el tiempo
  //inicial es dos segundos, en caso de que lo sea se
  //hace la interrupcion.
  if(tiempo2-tiempo1>=2000){
  	estado=!estado; //Se alterna el estado del LED
    digitalWrite(13,estado); //Se lee el pin digital 13
    
    //Se invierte el estado de cont para poder tomar
    //de nuevo un tiempo inicial
    cont=!cont;
  }
  else{
    //En caso de no haber pasado los dos segundos se sigue
    //ejecutando la orden normal de imprimir "Hola"
    Serial.print("Hola\n");
  }
}