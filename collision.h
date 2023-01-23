#ifndef COLLISION_H_INCLUDED
#define COLLISION_H_INCLUDED

#include "variables.h"

struct FP{
	char name[30];
	int score;
}player[5];

void bulletCollision(){ //collision through bullet
	if (throwBullet){
		if (bulletX >= enemyX){
			enemyShow = false;
			score += 10;
			if (bulletX >= 1280)
				throwBullet = false;

		}
	}
	if (!enemyShow){
		enemyX = 1700;
		enemyShow = true;
	}
}

void enemyAttack(){ //collision by enemy
	if (!groundStop){
		if (enemyX <= charX + 80 && enemyX>=charX){
			if (dx > 0)
				dx -= 40;
		}
	}
}

void fireOfBird(){ //collision by dragon fire ball
	if (charY >= birdFireY && charX + 92 >= birdFireX && charX <= birdFireX + 30){
		if (dx>0)
			dx -= 40;

	}
}

void obsCollision(){ //collision by obstacle
	if (!groundStop){
		if ((charX + 80 >= obsX&&charX <= obsX + 50) && charY + jumpPosition < obsY + 20){
			if (dx > 0)
				dx -= 40;
		}
	}
}
void fileHRead()
{

}


void fileWrite(){

	int i = 0;
	FILE *fptr = fopen("highscore.txt", "r");
	if (fptr == NULL)
	{
		printf("Cannot open file \n");
	}

	while (fscanf(fptr, "%s %d", &player[i].name, &player[i].score) != EOF)
	{
		printf("%s %d\n", player[i].name, player[i].score);
		i++;
	}
	
	fclose(fptr);
	FP temp;
	for (int i = 0; i <= 2; i++)
	{
		for (int j = i + 1; j <= 3; j++){
			if (player[i].score<player[j].score){
				temp = player[i];
				player[i] = player[j];
				player[j] = temp;
			}
		}
	}
	FILE *fp = fopen("highscore.txt", "w");
	for (int i = 0; i<3; i++){
		fprintf(fp, "%s %d\n", player[i].name, player[i].score);
	}
	len = 0;
	//player[3].name[0] = '\0';
	fclose(fp);

}



#endif