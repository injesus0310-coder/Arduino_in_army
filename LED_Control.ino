// C++ code
//

//3색LED
int R_value = 0;
int G_value = 0;
int B_value = 0;

//스위치
int flag = 0; 
int color = 0;

void setup()
{
  pinMode(11,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(7,INPUT);
  
  Serial.begin(9600);
}

void loop()
{
  int read_switch = digitalRead(7);
  if(read_switch == HIGH)
  {
    if(flag == 0)
    {
      flag = 1;
    }
  }
  else
  {
    if(flag == 1)
    {
      color++;
      Serial.println("Color is changed!");
      flag = 0;
      if(color>2)
      {
        color = 0;
      }
    }    
  }
  int READ_pot = analogRead(A0);
  int pot = map(READ_pot,0,1023,0,255);
  
  if(color == 0)
  {
    R_value = pot;
  }
  else if(color == 1)
  {
    G_value = pot;
  }    
  else
  {
    B_value = pot;
  }      
  analogWrite(11,R_value);
  analogWrite(10,B_value);
  analogWrite(9,G_value);
  
  Serial.print("R:");
  Serial.print(R_value);
  Serial.print("\tG:");
  Serial.print(G_value);
  Serial.print("\tB:");
  Serial.println(B_value);  
  
}
