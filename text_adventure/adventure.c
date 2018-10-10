#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char hacker[200];

int room1(){

    char wanna_cry[] = "I know the competition as a hacker is tough, but does it make you WannaCry?\n What was the name of the exploit that led this attack?\n You will just be eternally blue...\n";
    printf(wanna_cry);
    return 1;
}

int room2(){

    char programmer[] = "Where is a programmers favorite place to program an android app?\n Coffee Shop, obivously. Java! \n";
    printf(programmer);
    return 1;
}

int room3(){
    return 1;
}

int room4() {
    return 1;
}

int endGame(){


 // %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x
    char attack[] = "Congrats on finishing the quest... but the reward has been forgotten... Maybe it still lives on the stack.\n";


    printf("%s", attack);

    char secret[] = "jackie moon!";

    printf(hacker);
    printf("%s", "You have fought very bravily, but I am sorry...Hack the planet!\n");

    exit(0);
}

void intro(){
    char hackers[] = "They all scream...\n"
                "Hack the planet!\n"
                "Hack the planet!\n";
    printf("%s", hackers);

    // pause


    char alias[] = "Alright man, what is your hacker alias?\nLet the bad puns begin...\n\n" ;
    printf("%s",alias);

    fgets(hacker,200,stdin);

    // if it doesn't include dark, then reject it.
    printf(hacker);

}

int main() {
    intro();

    int contributions[4] = {0,0,0,0};

    while(1){


        char room[20];
        printf("Which room would you like to visit? 1-4 are options\n");

        fgets(room, 20, stdin);

        if(room[0] == '1'){
            contributions[0] = room1();
        }

        else if(room[0] == '2'){
            contributions[1] = room2();
        }
        else if(room[0] == '3'){
            contributions[2] = room3();
        }

        else if(room[0] == '4'){
            contributions[3] = room4();
        }

        if(contributions[0] == 1 && contributions[1] == 1 && contributions[2] == 1 && contributions[3] == 1){
            endGame();
        }
    }
    return 0;
}
