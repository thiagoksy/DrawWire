#define pin_font A0
#define pin_signal_sensor A1
#define range 500   //500 mm
/* 
    ***Variable / what is***
    tfont / voltage from a power supply
    tDraw_wire /  generated voltage
    distance /  distance in real lige (depend to range)
    error/ errors in the readings, because for each variation of 10 -20 mm there was an error
*/


float tfont, tDraw_Wire; // i recomend use a variable float or double
double distance, error; 


void setup()
{
  Serial.begin(9600);   //To read in serial monitor
}
void loop()
{
  tfont= analogRead(pin_font);                  //read the value the font
  tDraw_Wire= analogRead(pin_signal_sensor);    //normalizar sinal
  distance = tDraw_Wire*range/tfont;
  error = -1.676 +0.03*distance
    
  Serial.print(distance-error);
  Serial.print("\t mm\n");
}
