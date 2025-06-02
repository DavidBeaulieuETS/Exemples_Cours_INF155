//
// Created by BEAULIED on 2025-05-27.
//

#include <stdio.h>

double aireCercle(double rayon);

void testAideCercle(void);

int main(void) {

    testAideCercle();

}

double aireCercle(double rayon) {
    return 3.1416 * rayon * rayon;
}

void testAideCercle(void) {

    double aire;
    double rayon;

    rayon = 0;
    aire = aireCercle(rayon);
    printf("Test 1 : Pour un rayon de %lf l'aire est de : %lf\n",rayon,aire);

    rayon = 12;
    aire = aireCercle(rayon);
    printf("Test 2 : Pour un rayon de %lf l'aire est de : %lf\n",rayon,aire);

}