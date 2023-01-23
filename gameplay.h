#ifndef GAMEPLAY_H_INCLUDED
#define GAMEPLAY_H_INCLUDED
#include "variables.h"
#include "collision.h"

void nameInfo(){
	iShowBMP(0, 0, nm);
	iSetColor(255, 0, 0);

	iFilledRectangle(400, 300, 400, 60);
	iSetColor(255, 255, 255);
	iText(405, 325, str, GLUT_BITMAP_HELVETICA_18);
	iText(400, 365, "Enter Name", GLUT_BITMAP_HELVETICA_18);


}

void showScore()
{
	char Name[10][10];
	char Score[10][10];

	FILE *fpp = fopen("highscore.txt", "r");

	for (int loop = 0; loop<3; loop++)
	{
		fscanf(fpp, "%s %s", &Name[loop], &Score[loop]);

	}


	fclose(fpp);


	iSetColor(255, 255, 255);
	iText(400, 620, Name[0], GLUT_BITMAP_HELVETICA_18);
	iText(500, 620, Score[0], GLUT_BITMAP_HELVETICA_18);
	iText(400, 560, Name[1], GLUT_BITMAP_HELVETICA_18);
	iText(500, 560, Score[1], GLUT_BITMAP_HELVETICA_18);
	iText(400, 500, Name[2], GLUT_BITMAP_HELVETICA_18);
	iText(500, 500, Score[2], GLUT_BITMAP_HELVETICA_18);


}

void jumpChange(){ //for jumping in the air than come back to the ground
	if (jump){
		if (jumpUp){
			if (jumpLimit == 75)
				jumpPosition += 5;
		//	if (jumpLimit == 100)
			//	jumpPosition += 10;
			if (jumpPosition >= jumpLimit){
				jumpUp = false;

			}
		}
		else{
			if (jumpLimit == 75)
				jumpPosition -= 5;
		//	if (jumpLimit == 100)
			//	jumpPosition -= 10;
			if (jumpPosition < 0){
				jump = false;
				jumpPosition = 0;

			}
		}
	}

}

void gameScene(){
	iShowBMP(0, 0, play);//for behind background
	iShowBMP2(0, 0, lowerBG, 0);//for the ground 
	iSetColor(255, 255, 255);
	iRectangle(9, 689, 201, 16);
	if (dx > 80){
		iSetColor(0, 0, 255);
	}
	else
		iSetColor(255, 0, 0);
	iFilledRectangle(10, 690, dx, 15);
	iSetColor(255, 0, 0);
	_itoa(score, scorearray, 10);
	iText(1080, 690, "SCORE:", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(1170, 690, scorearray, GLUT_BITMAP_TIMES_ROMAN_24);

	if (jump){
		jumpChange();
		if (jumpUp){ //for getting upside from the ground
			if (dir == 1){ //for the direction right
				iShowBMP2(charX, charY + jumpPosition, jum[0], 0);

			}
			else{	//for the direction left
				iShowBMP2(charX, charY + jumpPosition, jum[2], 0);

			}
		}
		else{ //for coming back to the ground
			if (dir == 1){ //for the direction right
				iShowBMP2(charX, charY + jumpPosition, jum[1], 0);

			}
			else{ //for the direction left
				iShowBMP2(charX, charY + jumpPosition, jum[3], 0);

			}
		}
	}

	else{
		if (!standPosition){	//if the buttons are pressed which means the character is not standing anymore
			if (dir == 1){	//for going forward
				iShowBMP2(charX, charY, run[index], 0);
			}
			else if (dir == 2){		//for going backward
				iShowBMP2(charX, charY, runBack[index], 0);
			}
			standCounter++;              //for the standing position when not using left or right arrow
			if (standCounter >= 15){
				standCounter = 0;
				index = 0;
				standPosition = true;
			}
		}
		else
			iShowBMP2(charX, charY, stand, 0);//if the character is standing
	}


	if (throwBullet){
		if (dir == 1){ //for the direction right

			if (!jump){  //for throwing bullets while standing
				bulletY = charY + 65;
				iShowBMP2(bulletX, bulletY, bullet, 0);

				bulletX += 70;
				if (bulletX >= 1280){
					throwBullet = false;
					bulletX = charX + 86;
				}
			}
			if (jump){ //for throwing bullets while jumping;
				bulletY = charY + jumpPosition + 65;
				iShowBMP2(bulletX, bulletY, bullet, 0);
				bulletX += 70;


				if (bulletX >= 1280){
					throwBullet = false;
					bulletX = charX + 86;
				}
			}




		}

		if (dir == 2){ //for the direction right

			if (!jump){ //for throwing bullets while standing
				iShowBMP2(bulletX, bulletY, bullet, 0);

				bulletX -= 70;
				if (bulletX <= 0){
					throwBullet = false;
					bulletX = charX - 86;
				}
			}
			if (jump){ //for throwing bullets while jumping;
				bulletY = charY + jumpPosition + 65;
				bulletX -= 70;
				iShowBMP2(bulletX, bulletY, bullet, 0);
			}




		}
	}

	if (!groundStop){
		if (enemyShow){ //for the enemy

			iShowBMP2(enemyX, enemyY, en[enemyIndex], 0);
			enemyIndex++;
			if (enemyIndex >= 4)
				enemyIndex = 0;

			if (!pause){
				enemyX -= 15;   /////////////////////////
			}
			if (enemyX <= 0){
				enemyX = 1280;
			}
		}

		iShowBMP2(obsX, obsY, obstacle[obsIndex], 0); //for obstacle
		obsIndex++;
		if (obsIndex >= 4){
			obsIndex = 0;
		}
		if (!pause){
			obsX -= 15;   ////////////////////////////////
		}
		if (obsX <= 0)
			obsX = 1280;
	}




	iShowBMP2(dragonX, dragonY, dragon[dragonIndex], 0); //for dragon
	dragonIndex++;

	if (dragonIndex >= 9){
		dragonIndex = 0;
	}
	if (!pause){
		dragonX += 5;    /////////////////
	}
	if (dragonX >= 1280)
		dragonX = 0;
	if (birdFireShow){  //for the fire that comes from the dragon
		if (birdFireY > 155){
			iShowBMP2(birdFireX, birdFireY, birdFire, 0);
			if (!pause){
				birdFireY -= 20;   ////////////////
			}
		}
		else{
			birdFireX = dragonX + 182;
			birdFireY = dragonY + 30;
			iShowBMP2(birdFireX, birdFireY, birdFire, 0);
		}
	}


	bulletCollision();

	fireOfBird();

	if (dx == 0){
		//iShowBMP(0, 0, gameOver);
		nameInfo();

	}
}

#endif