;/* ===============================================================================
;Program untuk konversi pulsa jarak ke tegangan
;------------------------------------------------------------------------------------
; Komponen :
; Encoder
; Arduino Nano
; Resistor 1K
; Kapasitor 220uF
;------------------------------------------------------------------------------------*/

;=== Deklarasi Variabel ===
#define CHB 2     ;pin 2 sebagai Channel B
#define CHA 3     ;pin 3 sebagai Channel A 
#define arah 4    ;pin 4 sebagai keluaran digital untuk arah motor
#define PWM 5     ;pin 5 sebagai output PWM
#define PPR 500   ;deklarasi nilai PPR

int distance, pulse, tegangan ;
bool direction,

;=== Program ===
void setup() {
  pinMode (CHA, INPUT);
  pinMode (CHB, INPUT);
  pinMode (arah, 4);
  pinMode (PWM, 4);
  attachInterrupt(digitalPinToInterrupt(CHB), encoder, RISING);

}

void loop() {
  distance = (500/pulse)*250;
  tegangan = map (distane, 0,250,0,255);
  analogWrite (PWM, tegangan);
  digitalWrite (arah, direction);
}


void encoder1 ()
{
  if (digitalRead(CHA) == 0)
  {
    pulse --;
    direction = 0; // Putar maju
  }
  else
  {
    pulse ++;
    direction = 1;  // Putar mundur
  }
}
