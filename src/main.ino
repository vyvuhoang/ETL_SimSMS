#define ledPin (22)
#define ledPin (23)
#define ledPin (24)
#define ledPin (25)
void setup() 
{
  Serial.begin(9600);
  Serial3.begin(9600);
  pinMode(22,OUTPUT);
  pinMode(23,OUTPUT);
  pinMode(24,OUTPUT);
  pinMode(25,OUTPUT);

}
int period = 1000;
unsigned long time_now = 0;
char x;
char msg[150];
int i = 0;
bool isOK = false;
char sdt[] = "394937686";
const char insert[6] = "IN";
const char sodau_dt[4] = "84";

char* Repairsdt;
char* Repairsdt1;
char str1[20];
void loop() 
{
  
  if(Serial3.available()>0)
  {
   x = Serial3.read();  
   if('\r' != x || '\n' != x)
    {
    Serial.print(x);
    msg[i] = x;
    i++;
    if( '?' == x)
      { 
      isOK = true;
      i = 0;
      }
    }
  }
   
  if(isOK)
  {
    Repairsdt = strstr(msg, insert);
    if(Repairsdt != NULL)
    {
      delay(1000);
      Repairsdt1 = strstr(Repairsdt, sodau_dt);
      strncpy(str1, Repairsdt1, strlen(Repairsdt1) - 1);
      Serial.print("\r\n Đã thêm sdt ");  
      Serial.print(str1); 
           
    }
    if(strstr(msg,sdt) || strstr(msg,str1))
    {

      Serial.print("\r\n PHONE CORRECT\r\n");   
 
    {
      if(strstr(msg, "TB1ON"))
      {
        Serial.print("\r\n Turn on TB1\r\n");
        digitalWrite(22, HIGH);
        sendSMS(2);
      }
      else if(strstr(msg, "TB1OFF"))
      {
        Serial.print("\r\n Turn off TB1\r\n");
        digitalWrite(22, LOW);  
        sendSMS(1);
      }
     }
     {
      if(strstr(msg, "TB2ON"))
      {
        Serial.print("\r\n Turn on TB2\r\n");
        digitalWrite(23, HIGH);
        sendSMS(4);
      }
      else if(strstr(msg, "TB2OFF"))
      {
        Serial.print("\r\n Turn off TB2\r\n");
        digitalWrite(23, LOW);
        sendSMS(3);
      }
    }
    {
      if(strstr(msg, "TB3ON"))
      {
        Serial.print("\r\n Turn on TB3\r\n");
        digitalWrite(24, HIGH);
        sendSMS(6);
      }
      else if(strstr(msg, "TB3OFF"))
      {
        Serial.print("\r\n Turn off TB3\r\n");
        digitalWrite(24, LOW); 
        sendSMS(5);
      }
    }
    {
      if(strstr(msg, "TB4ON"))
      {
        Serial.print("\r\n Turn on TB4\r\n");
        digitalWrite(25, HIGH);
        sendSMS(8);
      }
      else if(strstr(msg, "TB4OFF"))
      {
        Serial.print("\r\n Turn off TB4\r\n");
        digitalWrite(25, LOW);
        sendSMS(7);
      }
    }
    memset(msg,'\0', sizeof(msg));
    isOK = false;
    if(millis() > time_now + period)
    {
      time_now = millis();
      memset(msg, '\0', sizeof(msg));
      i = 0;
    }
  }       
}
}
void sendSMS(unsigned char style) {

  delay(10000);
  Serial3.print("AT+CMGF=1\r\n");
  Serial3.println("AT+CMGS=\"+84394937686\""); //My number in International Format
  delay(100);
  switch(style)
   {  
    case 0:
      {
        Serial3.println("Message example from Arduino.");
        Serial3.println((char)26);
        delay(100);
        Serial3.println();
        //Give module time to send SMS
        delay(5000);
        Serial.println("DONE");         
        return(0);
      }
      case 1:
      {
        Serial3.println("Turn off TB1!");
        Serial3.println((char)26);
        delay(100);
        Serial3.println();
        //Give module time to send SMS
        delay(5000);
        Serial.println("DONE");         
         return(0);
      }
      case 2:
      {
         Serial3.println("Turn off TB2 ");
        Serial3.println((char)26);
        delay(100);
        Serial3.println();
        //Give module time to send SMS
        delay(5000);
        Serial.println("DONE");         
         return(0);
      }
      case 3:
      {
         Serial3.println("Turn off TB3");
        Serial3.println((char)26);
        delay(100);
        Serial3.println();
        //Give module time to send SMS
        delay(5000);
        Serial.println("DONE");         
         return(0);
      }
      case 4:
      {
         Serial3.println("Turn off TB4 ");
        Serial3.println((char)26);
        delay(100);
        Serial3.println();
        //Give module time to send SMS
        delay(5000);
        Serial.println("DONE");  
         return(0);
      }
      case 5:
      {
         Serial3.println("Turn On TB1");
        Serial3.println((char)26);
        delay(100);
        Serial3.println();
        //Give module time to send SMS
        delay(5000);
        Serial.println("DONE");         
         return(0);
      }
      case 6:
      {
        Serial3.println("Turn On TB2");
        Serial3.println((char)26);
        delay(100);
        Serial3.println();
        //Give module time to send SMS
        delay(5000);
        Serial.println("DONE");         
         return(0);
      }
      case 7:
      {
        Serial3.println("Turn On TB3");
        Serial3.println((char)26);
        delay(100);
        Serial3.println();
        //Give module time to send SMS
        delay(5000);
        Serial.println("DONE");         
         return(0);
      }
      case 8:
      {
        Serial3.println("Turn On TB4");
        Serial3.println((char)26);
        delay(100);
        Serial3.println();
        //Give module time to send SMS
        delay(5000);
        Serial.println("DONE");
        return(0);
      }
   }

}