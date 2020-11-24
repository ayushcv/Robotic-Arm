/*

 */
                                                                                

int redLed = 6; 
int blueLed = 3; 
int greenLed = 4; 



//-------------------- My Gas Sensors 
#define anInput     A0                        //analog feed from MQ135
#define digTrigger   2                        //digital feed from MQ135
#define co2Zero     55                        //calibrated CO2 0 level
#define piezoPin   8  
float sensor=A1;
float gas_value;
const int AOUTpin=2;//the AOUT pin of the hydrogen sensor goes into analog pin A0 of the arduino
const int DOUTpin=9;//the DOUT pin of the hydrogen sensor goes into digital pin D8 of the arduino
int limitS;
int valueS;


//----------------



void setup()                                       // Built-in initialization block
{

 
  
  pinMode(anInput,INPUT);                     //MQ135 analog feed set for input
  pinMode(digTrigger,INPUT);                  //MQ135 digital feed set for input                 //led set for output      

        // MQ-5
        pinMode(sensor,INPUT);
          Serial.begin(9600);    
       int limit;
        int value;
        
                      //MQ-8 Hydrogen 
                      pinMode(DOUTpin, INPUT);//sets the pin as an input to the arduino

     pinMode(redLed,OUTPUT);        
     pinMode(blueLed,OUTPUT);   
     pinMode(greenLed,OUTPUT);             
  
}  
 
void loop()                                        // Main loop auto-repeats
{
  

int co2now[10];                               //int array for co2 readings
int co2raw = 0;                               //int for raw value of co2
int co2comp = 0;                              //int for compensated co2 
int co2ppm = 0;                               //int for calculated ppm
int zzz = 0;                                  //int for averaging
int grafX = 0;                                //int for x value of graph

          // MQ-5
            gas_value=analogRead(sensor);
            Serial.print("     Natural Gas Level   "); 
            Serial.println(gas_value);
               

  for (int x = 0;x<10;x++){                   //samplpe co2 10x over 2 seconds
    co2now[x]=analogRead(A0);
    delay(100);
  }

for (int x = 0;x<10;x++){                     //add samples together
    zzz=zzz + co2now[x];
    
  }
  co2raw = zzz/10;                            //divide samples by 10
  co2comp = co2raw - co2Zero;                 //get compensated value
  co2ppm = map(co2comp,0,1023,400,5000);      //map value for atmospheric levels


  
  Serial.print("CO2 Level");               //print title
  Serial.print(" ");                       //skip a line
  Serial.print(co2ppm);                      //print co2 ppm
  Serial.print(" PPM   ");                      //print units
  grafX = map(co2ppm,0,1000,0,127);           //map value to screen width

      valueS= analogRead(AOUTpin);//reads the analaog value from the hydrogen sensor's AOUT pin
      limitS= digitalRead(DOUTpin);//reads the digital value from the hydrogen sensor's DOUT pin
      Serial.print("     Hydrogen value: ");
      Serial.println(valueS);//prints the hydrogen value

      delay(100);


  

  if(co2ppm>3000){                             //if co2 ppm > 1000
 tone(piezoPin, 100, 50);          
   digitalWrite (redLed, HIGH); 
  // turn on led
  }
  else{                                       //if not
      digitalWrite (redLed, LOW);                 //turn off led
  } 

    if(gas_value>1000){                             //if co2 ppm > 1000
   tone(piezoPin, 1000, 100);      
   digitalWrite (blueLed, HIGH); //turn on led
  }
  else{                                       //if not
         digitalWrite (blueLed,LOW);               //turn off led
  } 


          if(valueS>75){                             //if co2 ppm > 1000
        tone(piezoPin, 10000, 1000);       
         digitalWrite (greenLed, HIGH); //turn on led
        }
        else{                                       //if not
                digitalWrite (greenLed, LOW);            //turn off led
        } 
          
       // -------------------------------------------------------------- ^^^^ Gas Stuff 
  



  
} 
