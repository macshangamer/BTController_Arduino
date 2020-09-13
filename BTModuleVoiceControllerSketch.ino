
//const int ledpin_pos= 13;
//const int ledpin_neg= 12;

 //bluetooth junk captured
char junk; 

//bluetooth input string variable
String inputString="";

//Blutooth Command Defined here
String BTCMD_one = "1";
String BTCMD_two = "2";

void setup() 
{
  Serial.begin(9600);
  Serial.println("Initializing\n");
  //pinMode(ledpin_pos,OUTPUT);
  //pinMode(ledpin_neg,OUTPUT);
  //digitalWrite(ledpin_pos,LOW);
  //digitalWrite(ledpin_neg,LOW);
  Serial.println("Initialized");
}
void loop() 
{
  if(Serial.available())
  {
    Serial.println("Getting Bluetooth Input");
    while(Serial.available())
    {
      char inChar = (char)Serial.read(); //read the input
      inputString += inChar;             //make a string of the characters coming on serial
    }
    while(Serial.available()>0)
    {
      junk = Serial.read();
    }
  }
  if(inputString.length() > 2)
  {
    ExecuteBTCMD(inputString);
    inputString = "";
  }
}

void ExecuteBTCMD(String command)
{
  String cmd = command;
  //Removes last 2 underscores from command recieved
  cmd.remove(cmd.length() - 1);
  cmd.remove(cmd.length() - 1);
  Serial.println("Command Recieved : ");
  Serial.println(cmd);
  if(cmd.equals(BTCMD_one))
  {
    Serial.println("Task 1");
    //digitalWrite(ledpin_pos,HIGH);
  }

  if(cmd.equals(BTCMD_two))
  {
    Serial.println("Task 2");
    //digitalWrite(ledpin_pos,LOW);
    
  }
}
