#define trig 7
#define echo 8
#define m1_R 5
#define m1_L 6
#define m2_R 10
#define m2_L 11
#define buzzer 2
#define switch_1 3
#define switch_1 4
void check_password(void);
void Entry(void);
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);  

pinMode ( buzzer , OUTPUT ) ;
pinMode ( m1_R , OUTPUT )   ;
pinMode ( m1_L , OUTPUT )   ;
pinMode ( m2_R , OUTPUT )   ;
pinMode ( m2_L , OUTPUT )   ;
pinMode ( trig , OUTPUT )   ;
pinMode ( echo , INPUT  )   ;
pinMode ( switch_1 , INPUT );
pinMode ( switch_1 , INPUT );

}

void loop() {
  // put your main code here, to run repeatedly:
  
 Entry(); 

  
}
void Entry(void) {
  delay (2000);
  Serial.println("Welcome to our smart cotrolling car");
  delay (2000);
  Serial.println("Please enter your username ");
  delay (2000);
    if (Serial.available()>0){
    String x = Serial.readString();
    x.trim();
    if(x == "ahmed"){
      check_password();
      }
    else{
    Serial.println("Wrong username ... Try again");
    delay (2000);

}
  }
}

void check_password(void){
  char i ;
  char flag0 = 0 ;
  
  for(i = 0 ; i < 3 ; i++ ){
    Serial.println("Please enter your password .. : ");
    delay (3000);
    String pass = Serial.readString();
    pass.trim();
    if ( pass == "123"){
      Serial.println("welcome .. Ahmed");
      car();
      flag0 = 1 ;
      break;
    }
    else {
      Serial.println("Wrong password .. Try again \n");
    }
  }
  if (flag0 == 0)
  {
    Serial.println("Incorrect password for 3 times, No more tries ");
    Serial.println("you are blocked for 2 seconds .. ");
    delay(2000);
    digitalWrite(buzzer , HIGH);
   unsigned char flag2 = 0 ;
     while(digitalRead(3) == 0 || digitalRead(4) == 0 ){
      if (flag2 == 0){
    Serial.println("Press ..\n 1- switch 1 to stop the buzzer \n 2- switch 2 To remove the block ");  }
    else {
    Serial.println("Press .. switch 2 To remove the block ");
      }
    delay(2000);  
    if (digitalRead(3) == 1){
      digitalWrite(buzzer , LOW);
      Serial.println("buzzer stopped .. but stell blocked");
      delay(2000);  
      flag2 = 1 ;
      }
    else if (digitalRead(4) == 1 ) {
       Serial.println("block removed .. ");
       break ;
       
    }
     }
  }
}

void car (void){
 while(1){
 Serial.println("Please Choise ...\n 1- Start with user contol \n 2- Ultrasonic mode \n 3- Close .. : ");
 delay (2000);  
 String c = Serial.readString();
 c.trim(); 
  if (c == "1" && c != "3" ){
  while (1){
   delay (2000);  
   Serial.println("Please Choise ...\n 1- Speed up \n 2- Speed down \n 3- Stop \n 4- Move right \n 5- Move left .. : ");
   delay (2000);  
   String z = Serial.readString();
   z.trim();   
    if (z =="1"){
    Serial.println(" Fast .. ");
    delay (1000);  
//m1 r
   analogWrite(m1_R , 200);
   digitalWrite(m1_L , LOW);
// m2
    digitalWrite(m2_R , LOW);
    analogWrite(m2_L , 200);
       delay (2000);  
    
      }
    else if (z =="2"){
      Serial.println(" Slow .. ");
          delay (1000);  
      //m1 r
   analogWrite(m1_R , 100);
   digitalWrite(m1_L , LOW);
// m2
    digitalWrite(m2_R , LOW);
    analogWrite(m2_L , 100);
       delay (2000);      
      }
    else if (z =="3"){
      Serial.println(" stop .. ");
          delay (1000);  
     digitalWrite(m1_R , LOW);
     digitalWrite(m1_L , LOW);

     digitalWrite(m2_R , LOW);
     digitalWrite(m2_L , LOW);
     break ;   
      }
    else if (z =="4"){
      // right 
      Serial.println(" Right .. ");
          delay (1000);  
   digitalWrite(m1_R , HIGH);
   digitalWrite(m1_L , LOW);

   digitalWrite(m2_R , LOW);
   digitalWrite(m2_L , LOW );
          delay (2000);  
      }
    else if (z =="5"){
      // left
      Serial.println(" Left .. "); 
          delay (1000);       
   digitalWrite(m1_R , LOW);
   digitalWrite(m1_L , LOW);

   digitalWrite(m2_R , LOW);
   digitalWrite(m2_L , HIGH);
          delay (2000);  
      }
    else {
   digitalWrite(m1_R , LOW);
   digitalWrite(m1_L , LOW);

   digitalWrite(m2_R , LOW);
   digitalWrite(m2_L , LOW);
          
      }
    }
  }
  else if (c == "2") {
    unsigned long int duration ;
long distance;
digitalWrite( trig , LOW );
delay(1);


digitalWrite( trig , HIGH );
delayMicroseconds(10);
digitalWrite( trig , LOW );

duration = pulseIn(echo , HIGH );
distance = duration * 0.034 / 2 ;
Serial.println(distance);

if (distance < 5){
   Serial.println("Too short distance");
   Serial.println(" Back .. ");
   delay (1000);  
   digitalWrite(m1_R , LOW);
   analogWrite(m1_L , 100);

   analogWrite(m2_R , 100);
   digitalWrite(m2_L , LOW );
   delay (2000);  
  }
else if ((distance > 5)&&(distance < 25)){
   Serial.println(" Right .. ");
   delay (1000);  
   analogWrite(m1_R , 100);
   digitalWrite(m1_L , LOW);

   digitalWrite(m2_R , LOW);
   digitalWrite(m2_L , LOW );
   delay (2000);  
  }
else if ((distance > 25)&&(distance < 2000)){
    Serial.println(" Slow .. ");
    delay (1000);  
    analogWrite(m1_R , 100);
    digitalWrite(m1_L , LOW);
// m2
    digitalWrite(m2_R , LOW);
    analogWrite(m2_L , 100);  
    delay (2000);   
  }  
  else if (distance > 2000){
   Serial.println("Too long distance .. run");
   delay (1000);    
   analogWrite(m1_R , 200);
   digitalWrite(m1_L , LOW);
// m2
   digitalWrite(m2_R , LOW);
   analogWrite(m2_L , 200); 
    delay (2000);  
  }
else {
   digitalWrite(m1_R , LOW);
   digitalWrite(m1_L , LOW);

   digitalWrite(m2_R , LOW);
   digitalWrite(m2_L , LOW);
  }  
    }
  else if (c == "3") {
   digitalWrite(m1_R , LOW);
   digitalWrite(m1_L , LOW);

   digitalWrite(m2_R , LOW);
   digitalWrite(m2_L , LOW);
    break ;
    }
 }
  }
