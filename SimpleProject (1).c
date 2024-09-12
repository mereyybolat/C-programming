#include <stdio.h>

int main() {
	setvbuf(stdout, NULL, _IONBF, 0);
	
	printf("______________________________________________\n");
	
	printf("\t=======================================\n");
	printf("\tWelcome to the Treasure Hunt Adventure!\n");
	printf("\t=======================================\n");
	printf("Rules:\n");
	printf("- You are an adventurer on a 3x3 grid. Each position on the grid may contain a treasure, a trap, a potion, or be empty.\n");
	printf("- Your goal is to navigate through the grid, collect treasures, avoid traps, and reach the exit at the bottom-right corner.\n");
	printf("- You start with 100 Health Points (HP) and 0 points. Treasures increase your score, traps reduce your HP, and potions restore your HP.\n");
	printf("- You can move in four directions: Up (W), Down (S), Left (A), or Right (D)./n");
	printf("- The game ends when you reach the exit (or user presses 'E' for quitting the game) or if your HP drops to 0./n");
	printf("Let's begin! Your adventure starts now.\n");
	printf("---------------------------------------------------");
	int hp = 100;
	int score = 0;
	int rows = 2, cols = 2;
	char move;

	while(1){
		printf("Your current position: (%d, %d). ", rows, cols);
		printf("HP: %d, Score: %d\n", hp, score);
		printf("Your move: ");
		scanf(" %c", &move);

		switch (move) {
			case 'W':
				if (rows > 1)
		           rows--;
		        else
		            printf("error\n");
		        break;
		    case 'S':
		    	if (rows < 3)
		           rows++;
		        else
		            printf("error\n");
		        break;
		    case 'A':
		    	if (cols > 1)
		    		cols--;
		        else
		            printf("error\n");
		        break;
		    case 'D':
		    	if (cols < 3)
		    		cols++;
		        else
		            printf("error\n");
		        break;
		    case 'E':
		        printf("The game quits. HP: %d, Score: %d.\n", hp, score);
		        return 0;
		    default:
		        printf("incorrect move. enter W, A, S, D, or E.\n");
		        continue;
		}

	if (rows == 1 && cols == 1)
		printf("Location (1, 1). It's empty. Nothing happens.\n");

	else if(rows == 1 && cols == 2){
		printf("Location (1,2): Oh no! You stepped on a trap! -20 HP.\n");
		hp -= 20;
	}
	else if(rows == 1 && cols == 3)
		printf("Location (1,3): It's empty. Nothing happens.\n");

	else if(rows == 2 && cols == 1){
		printf("Location (2,1): You found a potion! +20 HP\n");
		hp += 20;
	}
	else if(rows == 2 && cols == 2)
		printf("Location(2,2): Starting position. Nothing happens.\n");

	else if(rows == 2 && cols == 3){
		printf("Location (2,3): Oh no! You stepped on a trap! -30 HP\n");
		hp -= 30;
	}
	else if(rows == 3 && cols ==1){
		printf("Location (3,1): Congratulations! You found a treasure! +20 points.\n");
		score += 20;
	}
	else if(rows == 3 && cols == 2){
		printf("Location (3,2): It's empty. Nothing happens.\n");
	}
	else if(rows == 3 && cols == 3){
		printf("You've found the exit! The game ends.\n");
		printf("Final Score: %d \nFinal HP: %d\n", score, hp);
		return 0;
	}
	if (hp <= 0) {
		printf("Your health has dropped to zero. Game over.\n");
	    printf("Final Score: %d, Final HP: %d\n", score, hp);
	    return 0;
		}
	}
	return 0;

}
