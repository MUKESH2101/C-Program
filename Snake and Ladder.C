#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
struct Name{
	char name[15];
	int box,ftime;
};
int game_board(int box){
	switch(box){
		case 4:
			printf("you have ladder,so you are safe\n");
			return 22;
			break;
		case 8:
			printf("you have ladder,so you are safe\n");
			return 34;
			break;
		case 12:
			printf("you have ladder,so you are safe\n");
			return 30;
			break;
		case 23:
			printf("you are not safe because, there is a snake!!!\n");
			return 2;
			break;
		case 25:
			printf("you have ladder,so you are safe\n");
			return 87;
			break;
		case 27:
			printf("you have ladder,so you are safe\n");
			return 45;
			break;
		case 32:
			printf("you are not safe because, there is a snake!!!\n");
			return 13;
			break;
		case 41:
			printf("you have ladder,so you are safe\n");
			return 77;
			break;
		case 47:
			printf("you are not safe because, there is a snake!!!\n");
			return 24;
			break;
		case 48:
			printf("you have ladder,so you are safe\n");
			 return 52;
			break;
	    case 56:
	    	printf("you have ladder,so you are safe\n");
			return 67;
			break;
		case 59:
			printf("you are not safe because, there is a snake!!!\n");
			return 21;
			break;
		case 61:
			printf("you have ladder,so you are safe\n");
			return 82;
			break;
		case 69:
			printf("you are not safe because, there is a snake!!!\n");
			return 43;
			break;
		case 74:
			printf("you are not safe because, there is a snake!!!\n");
			return 64;
			break;
		case 75:
			printf("you have ladder,so you are safe\n");
			return 96;
			break;	
		case 84:
			printf("you are not safe because, there is a snake!!!\n");
			return 26;
			break;
		case 89:
			printf("you are not safe because, there is a snake!!!\n");
			return 71;
			break;
		case 94:
			printf("you are not safe because, there is a snake!!!\n");
			return 53;
			break;
		case 98:
			printf("you are not safe because, there is a snake!!!\n");
			return 79;
			break;
		default:
			return box;
																					
	}
}
int main(){ 
	int members,frontbox=100,winers=1;
	char ch;
	printf("How many member will play (2-4): ");
	scanf("%d",&members);
	if(members>0){
		struct Name players[members];
		for(int i=0;i<members;i++){
			printf("Enter Player %d Name : ",i+1) && scanf("%s",players[i].name);
			players[i].ftime=1;
			players[i].box=1;
		}
		printf("Game is started!\n");
		nextround:
		for(int i=0;i<members;i++){
			nextplayer:
			if(players[i].box!=100){
			six:
			printf("\n\nPlayer %s can roll the dice\n",players[i].name);
			ch=getch();
			while(ch!='\r'){
			ch=getch();
			}
			srand(time(NULL));
			int moves=rand()%(6-1+1)+1;
			if(moves==1&&players[i].ftime==1){
				printf("%s are entered the Game Board\nyou are in the %dst box\n",players[i].name,moves);
				players[i].ftime=0;
				if(i==members-1){
				goto nextround;
				}
				i++;
				goto six;
			}
			if(players[i].ftime==0&&frontbox>=players[i].box+moves){
				players[i].box+=moves;
			printf("%s can moves %d steps\n",players[i].name,moves);
			players[i].box=game_board(players[i].box);
			if(players[i].box==100){
				printf("%s,You have finished your game at <-------> %d th Place <--------> & Wait till the end\n",players[i].name,winers);
				winers++;
				if(winers==members){
					return 0;
				}
			}else{
			printf("%s are in the %d-th Box\n",players[i].name,players[i].box);}
			}else{
				printf("%s are get %d So,you can not move!!!\n",players[i].name,moves);
			}
			if(moves==6){
				goto six;
			}
			printf("\n----\t-----------\t----\n\n");
		}
		
		}
		goto nextround;
		
	}else if(members<5){
		printf("Too much members\n");
	}else{
		printf("Invalid members\n");
	}
}
