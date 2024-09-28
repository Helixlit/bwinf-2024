#include <math.h>
#include <stdio.h>

int main() {
  int width;
  int length;
  int prospects;

  printf("Bitte gebe die Breite des Grundstücks an: ");
  scanf("%d", &width);

  printf("\nBitte gebe die Länge des Grundstücks an: ");
  scanf("%d", &length);

  printf("\nBitte gebe die Anzahl der Interessenten des Grundstücks an: ");
  scanf("%d", &prospects);


  double lot_width = ceil(sqrt(prospects * width / length));

  double lot_lenght = ceil(prospects / lot_width);

  printf("\nBreite: %f, Länge: %f", lot_width, lot_lenght);

  double n = 0.1;

  while (lot_width * lot_lenght > prospects * 1.1)
  {
    lot_width = ceil(sqrt(prospects * (width / length + n)));

    lot_lenght = ceil(prospects / lot_width);

    printf("\nBreite: %f, Länge: %f", lot_width, lot_lenght);

    printf("\nn: %f", n);
    n += 0.05;
  } 
}