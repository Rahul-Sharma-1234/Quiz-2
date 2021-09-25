#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

    int main() 
    {
    //random time
        time_t t;
        srand((unsigned) time(&t));

    //set a Max Number for guesses to have
    static int MaxNumber = 15;
    int GuessAttempt = rand() % MaxNumber;

    //make a menu for the User to interact with
    printf("Number 1 to play a Game\nNumber 2 to change the Max Number\nNumber 3 to Quit\n");

    int Input = 0; 
    scanf("%d", &Input);
    char Guess[50];
    int GuessValue;

    //If the User chooses Option 1
    if(Input == 1){
        printf("Choose a Number between 1 and %d. ", MaxNumber);
        scanf("%s", &Guess);

        if(strcmp("q", Guess) == 0){
            main();
        }
        else {
            GuessValue = atoi(Guess);
        }
     while(GuessValue != GuessAttempt){ 
            while(GuessValue < GuessAttempt){
                printf("Pick a larger number!\n");
                scanf("%s", &Guess);
                if(strcmp("q", Guess) == 0)
                {
                    main(); 
                }
                GuessValue = atoi(Guess); 
            }
            while(GuessValue > GuessAttempt){
                printf("Pick a smaller Number!\n");
                scanf("%s", &Guess);
                if(strcmp("q", Guess) == 0){
                main(); 
                }    
                GuessValue = atoi(Guess);
            }
        }
        printf("Congraulations! You got the right number!\n");
        // recursive call back to the Main
        main(); 
    }
    // if user input =2, move into menu to change the max number 
    else if(Input == 2) {
        int Replacement; 
        printf("Pick a new Number to be your Max! ");
        scanf("%d", &Replacement); 
        if(Replacement>0 && Replacement< INT_MAX) {
            MaxNumber = Replacement;
            printf("\nThe Max Number is now %d\n", MaxNumber); 
            // recursive call 
            main();
        }
    
        else{
            printf("Incorrect! The Max Number will stay as %d",MaxNumber);
        // recursive call back to the Main
            main(); 
        }
    }
    
    // if input is 3, exit the program 
    else if(Input == 3)
    {
        printf("\nSee You Later Alligator");
        return 0; 
    }
    return 0;

}