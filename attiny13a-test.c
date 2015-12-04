//
// Programme de contrôle pour lampe «Tout-U»
// 
// Microcontrôleurs ATMEL ATtiny13 ou ATtiny13A
//
// Patrick Laurin & Alexandre Beauchesne
// GPA792 - Projet final d'études en GPA
// Automne 2015
//

#include <avr/io.h>
//#include <avr/interrupt.h>
#include <util/delay.h>
 
#define F_CPU 9600000

// Duty-Cycle initial
int i = 50;

// Programme principal
int main (void)
{
  // Configure Port 4 en sortie
  DDRB |= (1 << DDB4);
  // Configure Port 1 en entrée
  // DDRB &= ~(1<<DDB1);
  // Active résistance Pull-Up sur Port 1
  // PORTB |= (1<<PORTB1);
  // Active les interruptions sur le Port 1 (INT0)
  // GIMSK |= (1<<INT0);
  // Détection au front montant pour le Port 1 (INT0)
  // MCUCR = (1<<ISC01)|(1<<ISC00);
  // Démarre les interruptions globales
  // sei();
  // Compteur de microsecondes
  int us = 0;

  // Boucle d'exécution
  while (1)
  {

    // Génération du PWM
    // Met le port 4 à ON
    PORTB = (1 << PORTB4);

    // Délais ON
    us = (100-i)/2;
    while (0 < us)
    {
      _delay_us(1);
      us -= 1;
    }
 
    // Met le Port à OFF
    PORTB &= ~(1 << PORTB4);
 
    // Délais OFF
    us = i/2;
    while (0 < us)
    {
      _delay_us(1);
      us -= 1;
    }
  }
  return 1;
}

// Interruption du bouton momentané (Port 0)
/*ISR(INT0_vect)
{
  // Anti-rebondissement (debounce)
  PORTB &= ~(1<<PORTB4);
  _delay_ms(250);

  // Réduction du Duty Cycle (dim down)
  if (i==100)
  {
    i = 25;
  }

  // Augmentation du Duty Cycle (dim up)
  else
  {
    i = 100;
  }
}*/
