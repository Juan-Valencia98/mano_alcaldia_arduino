#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <Servo.h>


//SCL=A5   //SDA=A4
LiquidCrystal_I2C lcd(0x27, 20, 4);


//INICIALIZAR SERVOS//////////////////////////////////////////////////////////////////////////
Servo menique;//maximo = 130 - minimo= 90  -- medio = 115
Servo anular;//maximo = 120 - minimo= 90  -- medio = 110
Servo medio;//maximo = 120 - minimo= 80  -- medio = 100
Servo indice;//maximo = 120 - minimo= 80  -- medio = 100
Servo pulgar;//maximo = 130 - minimo= 50  -- medio = 100

Servo meniquel;//MAXIMO = ( Recoge: 70 delay: 2000)   MINIMO= (expande: 110  delay: 1700)
Servo anularl;//MAXIMO = ( Recoge: 70 delay: 2500)   MINIMO= (expande: 110  delay: 2400)
Servo mediol;//MAXIMO = ( Recoge: 70 delay: 2200)   MINIMO= (expande: 110  delay: 2100)
Servo indicel;//MAXIMO = ( Recoge: 70 delay: 2500)   MINIMO= (expande: 110  delay: 2400)
Servo pulgarl;//MAXIMO = ( Recoge: 70 delay: 3000)   MINIMO= (expande: 110  delay: 2000)
//INICIALIZAR SERVOS//////////////////////////////////////////////////////////////////////////


void setup()
{
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcdd();
  attachServos();
}

///INICIAR LCD
void lcdd(){
  lcd.setCursor(0, 0);
  lcd.print("IIIS: ");
}




String print = "";
void loop()
{
  int cont=0;
  if (Serial.available())
  {
    char dato = Serial.read();
    if (dato != '\r' && dato != '\n') // Filtra los caracteres no deseados ('\r' y '\n')
    {
      print.concat(dato);
    }
    processCommand(dato);
    Serial.print("Dato recibido: ");
    Serial.println(dato);
  }else{
    print="";
    // lcd.clear();
    lcd.setCursor(0, 1);
    lcd.print(print);
    lcdd();
  }


  lcd.setCursor(0, 1);
  lcd.print(print);
  
  delay(200);
}

///// DAR POSICIONES PARA MOVER POR ABECEDARIO
void processCommand(char cmd) {
  switch (cmd) {
    //////
    case 'a':
    case 'A':
      moveServosTo(100, 110, 100, 110, 30, 2100, 2300, 3500, 2500, 0);
      break;
      //////
    case 'b':
    case 'B':
      moveServosTo(100, 110, 100, 110, 130, 0, 0, 0, 0, 1500);
      break;
    case 'c':
    case 'C':
      moveServosTo(100, 110, 100, 110, 130, 1000, 1000, 1000, 1000, 800);
      break;
      /////////
    case 'd':
    case 'D':
      moveServosTo(100, 110, 100, 110, 0, 2100, 2300, 3500, 0, 1000);
      break;
    case 'e':
    case 'E':
      moveServosTo(100, 110, 100, 100, 30, 1200, 1200, 1200, 1200, 0);
      break;
      ////////////
    case 'f':
    case 'F':
      moveServosTo(115, 110, 100, 100, 50, 0, 0, 0, 2500, 1000);
      break;
    case 'g':
    case 'G':
      moveServosTo(115, 110, 100, 100, 140, 2100, 2300, 3500, 0, 1500);
      break;
    case 'h':
    case 'H':
      moveServosTo(115, 110, 100, 100, 140, 2100, 2300, 0, 0, 1500);
      break;
      /////////////////
    case 'i':
    case 'I':
      moveServosTo(115, 110, 100, 100, 140, 0, 2300, 3500, 2500, 1500);
      break;
    case 'j':
    case 'J':
      moveServosTo(115, 110, 100, 100, 140, 0, 2300, 3500, 2500, 1500);
      break;
    case 'k':
    case 'K':
      moveServosTo(115, 110, 100, 100, 40, 2100, 2300, 0, 0, 1000);
      break;
    case 'l':
    case 'L':
      moveServosTo(115, 110, 100, 100, 100, 2100, 2300, 3500, 0, 1000);
      break;
    case 'm':
    case 'M':
      moveServosTo(115, 110, 100, 100, 100, 1800, 1800, 2500, 1800, 800);
      break;
    case 'n':
    case 'N':
      moveServosTo(115, 110, 100, 100, 100, 1800, 1800, 2500, 1800, 1500);
      break;
    case 'ñ':
    case 'Ñ':
      moveServosTo(115, 110, 100, 100, 100, 1800, 1800, 2500, 1800, 1500);
      break;
    case 'o':
    case 'O':
      moveServosTo(115, 110, 100, 100, 100, 1000, 1100, 2000, 1800, 800);
      break;
    case 'p':
    case 'P':
      moveServosTo(115, 110, 100, 100, 100, 1100, 1300, 2500, 0, 500);
      break;
    case 'q':
    case 'Q':
      moveServosTo(115, 110, 100, 100, 100, 1800, 2000, 3000, 0, 1000);
      break;
    case 'r':
    case 'R':
      moveServosTo(115, 110, 90, 110, 90, 2100, 2300, 0, 0, 0);
      break;
    case 's':
    case 'S':
      moveServosTo(115, 110, 100, 100, 100, 2100, 2300, 3500, 2500, 1500);
      break;
    case 't':
    case 'T':
      moveServosTo(115, 110, 100, 100, 100, 2100, 2300, 3500, 2500, 1000);
      break;
    case 'u':
    case 'U':
      moveServosTo(115, 110, 95, 100, 100, 2100, 2300, 0, 0, 1000);
      break;
    case 'v':
    case 'V':
      moveServosTo(115, 110, 110, 100, 100, 2100, 2300, 0, 0, 1500);
      break;
    case 'w':
    case 'W':
      moveServosTo(115, 120, 100, 100, 100, 2100, 0, 0, 0, 1500);
      break;
    case 'x':
    case 'X':
      moveServosTo(115, 110, 100, 100, 100, 2100, 2300, 3500, 1500, 1000);
      break;
    case 'y':
    case 'Y':
      moveServosTo(115, 110, 100, 100, 100, 0, 2300, 3500, 2500, 0);
      break;
    case 'z':
    case 'Z':
      moveServosTo(115, 110, 100, 100, 100, 2100, 2300, 3500, 0, 1500);
      break;
    default:
      Serial.println("Comando no reconocido");
  }
}


////MOVER SERVOS
void moveServosTo(int meni, int anul,int medi, int indi, int pulg, long men_a,long anu_a,long med_a,long ind_a,long pul_a) {
  ///////////////////////////////////////////////////////////////////////////////////////
  menique.write(meni);
  delay(100);
  anular.write(anul);
  delay(100);
  medio.write(medi);
  delay(100);
  indice.write(indi);
  delay(100);
  pulgar.write(pulg);
  delay(100);
  ///////////////////////////////////////////////////////////////////////////////////////
  meniquel.write(110);
  delay(men_a);
  meniquel.write(90);
  anularl.write(70);
  delay(anu_a);
  anularl.write(90);
  mediol.write(70);
  delay(med_a);
  mediol.write(90);
  indicel.write(110);
  delay(ind_a);
  indicel.write(90);
  pulgarl.write(70);
  delay(pul_a);
  pulgarl.write(90);



  delay(5000);
  resetServosT(men_a,anu_a,med_a,pul_a,ind_a);
}



///RESET SERVOS POSICION ANTERIOR
void resetServosT(int men_a, int anu_a, int med_a, int pul_a, int ind_a) {
  anular.write(115);
  delay(100);
  menique.write(110);
  delay(100);
  medio.write(100);
  delay(100);
  indice.write(100);
  delay(100);
  pulgar.write(100);
  delay(100);

  if(men_a!=0){
    meniquel.write(70);
    delay(men_a-700);
    meniquel.write(90);
  }
  if(anu_a!=0){
    anularl.write(110);
    delay(anu_a-500);
    anularl.write(90);
  }
  if(med_a!=0){
    mediol.write(110);
    delay(med_a-800);
    mediol.write(90);
  }
  if(ind_a!=0){
    indicel.write(70);
    delay(ind_a-800);
    indicel.write(90);
  }
  if(pul_a!=0){
    pulgarl.write(110);
    delay(pul_a-100);
    pulgarl.write(90);
  }
}

///INICIALIZAR SERVOS
void attachServos() {
  menique.attach(5);
  anular.attach(4);
  medio.attach(3);
  indice.attach(2);
  pulgar.attach(11);

  meniquel.attach(6);
  anularl.attach(7);
  mediol.attach(8);
  indicel.attach(9);
  pulgarl.attach(10);


  ///SERVO RESET
  anular.write(115);
  delay(100);
  menique.write(110);
  delay(100);
  medio.write(100);
  delay(100);
  indice.write(100);
  delay(100);
  pulgar.write(100);
  delay(100);
}
  
