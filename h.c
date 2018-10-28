#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define COLS  36
#define ROWS  50
#define MAX_ROADS 5
#define INIT 177
#define SPACE 32
#define vertical '|' 
#define horizontal '-'
#define STEP 46
#define NO_WAY 176



void InitMap(char m[COLS][ROWS]);
void PrintMap(char m[COLS][ROWS]);
int SetAdress(int Adressmap[MAX_ROADS * 2][4], int count);
void AddAdressToMap(char map[COLS][ROWS], int Adressmap[MAX_ROADS * 2][4], int count);
void addNode(char map[COLS][ROWS]);



void main() {
	int count = 0;
	int count2 = 0;
	int Adressmap[MAX_ROADS * 2][4];
	char map[COLS][ROWS];

	//PrintMatrix1(map);
	InitMap(map);
	count2 = SetAdress(Adressmap, count);
	AddAdressToMap(map, Adressmap, count2);
	addNode(map);

	printf("The map is:\n");
	PrintMap(map);
}

void InitMap(char m[COLS][ROWS])
{
	int i, j;
	for (i = 0; i < COLS; i++)
		for (j = 0; j < ROWS; j++)
			m[i][j] = INIT;

}
int SetAdress(int Adressmap[MAX_ROADS * 2][4], int count) {

	int  i = 0, j = 0, startNum, startNum2, endNum, endNum2, continueAsk;
	char exit;

	do {

		printf("Enter indices <i,j> of road start:");
		scanf("%d %d", &startNum, &startNum2);
		printf("Enter indices <i,j> of road end:");
		scanf("%d %d", &endNum, &endNum2);
		Adressmap[i][j] = startNum;
		Adressmap[i][++j] = startNum2;
		Adressmap[i][++j] = endNum;
		Adressmap[i][++j] = endNum2;
		i++;
		j = 0;

		printf("Do you want to enter another road?");
		scanf(" %c", &exit);
		count++;
		switch (exit)
		{
		case 'y':
			continueAsk = 1;
			printf("until now you write %d street, you can write more %d \n", count, (MAX_ROADS * 2) - count);
			break;
		case 'Y':
			continueAsk = 1;
			printf("until now you write %d street, you can write more %d \n", count, (MAX_ROADS * 2) - count);
			break;
		case 'n':
			continueAsk = 0;
			printf("you write %d street \n", count);
			break;
		case 'N':
			continueAsk = 0;
			printf("you write %d street \n", count);
			break;
		default:
			printf("Wrong answer only y/n | Y/N \n");
			continueAsk = 0;
			break;
		}
	} while (continueAsk == 1 && count < MAX_ROADS * 2);
	return count;
}
void PrintMap(char m[COLS][ROWS])
{
	int i, j;

	for (i = 0; i < COLS; i++)
	{
		for (j = 0; j < ROWS; j++)
		{
			printf("%c", m[i][j]);
		}
		printf("\n");
	}
}
void AddAdressToMap(char map[COLS][ROWS], int Adressmap[MAX_ROADS * 2][4], int count) {
	int temp = 0, w, m, k = 0, i, j, temp2 = 0, temp3 = 0, temp4 = 0;

	for (i = 0; i <= count; i++) {
		for (j = 0; j < 1; j++)
		{
			temp = Adressmap[i][j];
			temp2 = Adressmap[i][++j];
			temp3 = Adressmap[i][++j];
			temp4 = Adressmap[i][++j];
			//printf("%d /n", &temp);
			//printf("%d /n", &temp2);

			if (temp == temp3) {
				k = temp2;
				m = temp;
				if (temp2 > temp) {
					for (w = temp2; w > temp4; w--) {
						map[m][k--] = horizontal;
					}
				}
				else {
					for (w = temp2; w < temp4; w++) {
						map[m][k++] = horizontal;
					}

				}
			}


			else {
				k = temp;
				m = temp2;
				//w = temp;
				if (temp3>temp) {
					for (w = temp; w < temp4; w++) {
						map[k++][m] = vertical;

					}

				}
				else {
					for (w = temp; w > temp4; w--) {
						map[k--][m] = vertical;

					}
				}


			}
		}

	}
}
void addNode(char map[COLS][ROWS]) {

	int i, j;
	for (i = 0; i < COLS; i++) {
		for (j = 0; j < ROWS; j++) {

			if (map[i][j] == '|') {
				if (map[i][j-1] == '-'&& map[i][j+1] == '-') {
					map[i][j] = SPACE;
				}
				if (map[i][j+1] == '-' || map[i][j-1] == '-') {
					map[i][j] = SPACE;
				}

			}

			if (map[i][j] == '-') {
				if (map[i+1][j] == '|' && map[i-1][j ] == '|') {
					map[i][j] = SPACE;
				}
				if (map[i + 1][j] == '|'&& map[i - 1][j] == '|') {
					map[i][j] = SPACE;
				}

			}

		}
	}
}





