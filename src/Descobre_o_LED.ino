int Leds[2][9] ={ 
  {2,3,4,5,6,7,8,9,10} ,
  {LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW}
};

int Button1 = 11;
int Button2 = 12;

int count = 0;

bool status1 = false, previous1 = false;

void setup()
{
  Serial.begin(9600);
  for(int LED=0;LED<9;LED++){
   pinMode(Leds[0][LED], OUTPUT);
  }
  
  pinMode(Button1, INPUT_PULLUP);
  pinMode(Button2, INPUT_PULLUP);
  
}

void loop()
{

// Acender os LEDs(Funciona corretamente? Sim)
  
  for(int LED=0;LED<9;LED++){
    
    for(int i=0;i<150;i++){
      digitalWrite(Leds[0][LED], !Leds[1][LED]);
// Quando carregar no botao o LED mantem-se aceso(Funciona corretamente? +++/-)
      
      int status1 = !digitalRead(Button1);
       
       if(status1 != previous1){
         previous1=status1; 
         if(status1=previous1){ 
            count++;
            //Serial.println(count);
            if (Leds[0][LED] == 2){
              Leds[1][0] = HIGH;
            }
            if (Leds[0][LED] == 3){
              Leds[1][1] = HIGH;
            }
            if (Leds[0][LED] == 4){
              Leds[1][2] = HIGH;
            }
            if (Leds[0][LED] == 5){
              Leds[1][3] = HIGH;
            }   
            if (Leds[0][LED] == 6){
              Leds[1][4] = HIGH;
            }
            if (Leds[0][LED] == 7){
              Leds[1][5] = HIGH;
            }
            if (Leds[0][LED] == 8){
              Leds[1][6] = HIGH;
            }
            if (Leds[0][LED] == 9){
              Leds[1][7] = HIGH;
            }   
            if (Leds[0][LED] == 10){
              Leds[1][8] = HIGH;
            } 
         }
       delay(1);
       }
      
// Se não carregar no botao o LED apaga-se(Funciona corretamente? Sim)  
      
       else{
         delay(1);
         digitalWrite(Leds[0][LED], Leds[1][LED]);
       delay(1);
       }
    }
  
// Botão de Reset(Funciona corretamente? +/-)
    
  int status2 = digitalRead(Button2);
    
  if(status2 == LOW){    
    count = 0;
 
    for(int LED=0;LED<9;LED++){
      Leds[1][LED]=LOW;
        digitalWrite(Leds[0][LED], 0);
    }
   }
  }

  
// Funcionalidade Vitoria(Funciona corretamente? Sim)
  
  if(Leds[1][0] == HIGH && Leds[1][1] == HIGH && Leds[1][2] == HIGH && Leds[1][3] == HIGH && Leds[1][4] == HIGH && Leds[1][5] == HIGH && Leds[1][6] == HIGH && Leds[1][7] == HIGH && Leds[1][8] == HIGH){
    Serial.print("Deu ");
    Serial.print(count); 
    Serial.print(" cliques no botao");
    Serial.println(" ");
    
    for(int i=0;i<20;i++){
      digitalWrite(Leds[0][0], 1);
      digitalWrite(Leds[0][1], 1);
      digitalWrite(Leds[0][2], 1);
      digitalWrite(Leds[0][3], 1);
      digitalWrite(Leds[0][4], 1);
      digitalWrite(Leds[0][5], 1);
      digitalWrite(Leds[0][6], 1);
      digitalWrite(Leds[0][7], 1);
      digitalWrite(Leds[0][8], 1);
      delay(500);

      digitalWrite(Leds[0][0], 0);
      digitalWrite(Leds[0][1], 0);
      digitalWrite(Leds[0][2], 0);
      digitalWrite(Leds[0][3], 0);
      digitalWrite(Leds[0][4], 0);
      digitalWrite(Leds[0][5], 0);
      digitalWrite(Leds[0][6], 0);
      digitalWrite(Leds[0][7], 0);
      digitalWrite(Leds[0][8], 0);
      delay(500);
    }
    
    for(int LED=0;LED<9;LED++){
      Leds[1][LED]=LOW;
    }
    count = 0;
  }
}
