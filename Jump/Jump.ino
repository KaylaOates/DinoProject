#include <LiquidCrystal.h> 
LiquidCrystal bounch(7, 8, 9, 10, 11, 12); 
LiquidCrystal slide(7, 8, 9, 10, 11, 12); 

int button = 13;
int buttonL = A5;
int buttonR = A4;

void setup() 
{
  bounch.begin(16, 2); 
  slide.begin(16, 2); 
  pinMode(button, INPUT);
  pinMode(buttonL, INPUT);
  pinMode(buttonR, INPUT); 
}

void loop() 
{
  int asterick = 0;
  bool locBounch = false;
  
  while(asterick >= 0 && asterick < 15) {  //left to right

    //collides w sliding one
    if(asterick == 8 && locBounch == false){ 
      bounch.clear();
      slide.clear();

      slide.setCursor(4, 1);
      slide.print("Game Over");
      delay(1000);
      
      //game over screen
      while(digitalRead(button) == HIGH) {
           
      }
      asterick = -1;
      
    }else{ //they did not collide
      
      //if button is pressed:
      if(digitalRead(button) == LOW){
       
        //jump:
        bounch.clear();
        slide.clear();
        bounch.setCursor(8, 0);
        bounch.print("*");
        locBounch = true;
        slide.setCursor(asterick, 1);
        slide.print("*");
        delay(700);
  
        //reset
        asterick++;
        bounch.clear();
        slide.clear();
        bounch.setCursor(8, 1);
        bounch.print("*");
        locBounch = false;
        slide.setCursor(asterick, 1);
        slide.print("*");
        delay(700);
  
        asterick++;
      }
      else //button is not pressed
      {
        
        //clear to see
        slide.clear();
        bounch.clear();

        //runs loop for half a second, unless the button is pressed
        for(int i = 0; i < 500; i++)
        {
          if(digitalRead(button) == LOW)
          {
            i = 10000;
          }
          
          //move slider one
          slide.setCursor(asterick, 1);
          slide.print("*");
          
          bounch.setCursor(8, 1);
          bounch.print("*");
          locBounch = false;
        }
    
        //if not pressed:
        asterick++;
      }
    }
 }


 //reverse
 while(asterick <= 15 && asterick >= 0) {

    if(asterick == 8 && locBounch == false){
      bounch.clear();
      slide.clear();
  
      slide.setCursor(4, 1);
      slide.print("Game Over");
      delay(1000);
      
      //game over screen
      while(digitalRead(button) == HIGH) {
           
      }
      
      asterick = -1;
      
    }else{
      //if button is pressed:
      if(digitalRead(button) == LOW){
        //jump:
        bounch.clear();
        slide.clear();
        bounch.setCursor(8, 0);
        bounch.print("*");
        locBounch = true;
        slide.setCursor(asterick, 1);
        slide.print("*");
        delay(700);
  
        //reset
        asterick--;
        bounch.clear();
        slide.clear();
        bounch.setCursor(8, 1);
        bounch.print("*");
        locBounch = false;
        slide.setCursor(asterick, 1);
        slide.print("*");
        delay(700);
  
        asterick--;
      }
      else
      {
        //clear to see
        slide.clear();
        bounch.clear();
  
        for(int i = 0; i < 500; i++)
        {
          if(digitalRead(button) == LOW)
          {
            i = 10000;
          }
          //move slider one
          slide.setCursor(asterick, 1);
          slide.print("*");
          bounch.setCursor(8, 1);
          bounch.print("*");
          locBounch = false;
        }
    
        //if not pressed:
        asterick--;
      }
    }
 }

}
