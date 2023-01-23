#ifndef SAVELOAD_H_INCLUDED
#define SAVELOAD_H_INCLUDED

#include "variables.h"

void save(){
	FILE *fp1 = fopen("save.txt", "w");
	fprintf(fp1, "%d %d %d %d %d %d %d %d %d %d", dx, score, charX, charY, bulletX, enemyX, obsX, dragonX, birdFireX, birdFireY);
	fclose(fp1);
}

void load(){

	FILE *fp2 = fopen("save.txt", "r");
	if (fp2 == NULL){
		dx = 200, score = 0, charX = 0, charY = 155, bulletX = charX + 86, enemyX = 1280, obsX = 1280, dragonX = 0, birdFireX = dragonX + 182, birdFireY = dragonY + 30;
	}
	else{
		fscanf(fp2, "%d %d %d %d %d %d %d %d %d %d", &dx, &score, &charX, &charY, &bulletX, &enemyX, &obsX, &dragonX, &birdFireX, &birdFireY);
	}
	fclose(fp2);
}

#endif