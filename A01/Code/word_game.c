// --> ONLY FILE WE NEED TO CHANGE <--


//--------------------------------------------------
// INCLUDE LIBRARIES
//--------------------------------------------------
#include "word_game.h"
#include <stdio.h>
#include <ctype.h>
#include <process.h>
#include <stdlib.h>

//--------------------------------------------------
// my_getchar
//--------------------------------------------------
char my_get_char() {
    //1. We create the output variable with the value the user has input by keyboard
    char res = getchar();

    //2. We discard any extra character the user has input by keyboard
    boolean finish = False;
    char dummy_char = ' ';

    while (finish == False) {
        dummy_char = getchar();
        if (dummy_char == '\n')
            finish = True;
    }

    //3. We return the output variable
    return res;
}

//--------------------------------------------------
// ask_for_new_command
//--------------------------------------------------
char ask_for_new_command() {
    //1. We create the output variable with an initial value
    char res = ' ';

    //2. While we have not received a valid command

    //2.1 We ask the user for a new command
    printf("\nPlease enter a command:   (letter a-z or move position < > ");

    //2.2. We read the command entered by the user
    char command = my_get_char();

    //2.3. We check if the command is correct
    if (isalpha(command)) {
        printf("You entered the letter: %c", command);
        res = command;
    } else if (command == '<' || command == '>') {          // why can't you use "<"? must be '<'
        printf("You chose to move position.");
        res = command;
    } else {
        printf("Please enter a valid command.");
    }

    //3. We return the output variable
    return res;
}

//--------------------------------------------------
// process_movement
//--------------------------------------------------
void process_movement(char current_word[NUM_LETTERS], char** letter_ptr_ptr, int* num_movs_ptr, char command) {
    //1. We process the different commands

    //1.1. If it is a '<'
    if (command == '<') {

        //1.1.1. If we are not in the left border
        if (**letter_ptr_ptr != current_word[0]) {

            //I. We move the pointer to the left
            //letter_ptr_ptr--;
            *letter_ptr_ptr = *letter_ptr_ptr - 1;

            //II. We update the number of movements
            //letter_ptr_ptr++;
            *num_movs_ptr = *num_movs_ptr + 1;
        } else {
            printf("You are at the left-most letter.");
        }
    }

    //1.2. If it is a '>'
    if (command == '>') {

        //1.2.1. If we are not in the right border
        if (*letter_ptr_ptr != &current_word[NUM_LETTERS] - 1) {

            //I. We move the pointer to the right
            //letter_ptr_ptr++;
            *letter_ptr_ptr = *letter_ptr_ptr + 1;

            //II. We update the number of movements
            //num_movs_ptr++;
            *num_movs_ptr = *num_movs_ptr + 1;
        } else {
            printf("You are at the right-most letter.");
        }
    }

    //1.3. If it is a letter
    if (isalpha(command)) {

        //1.3.1. If the letter is different from the current one
        if (**letter_ptr_ptr != command) {

            //I. We modify the letter
            **letter_ptr_ptr = command;

            //II. We update the number of movements
            //num_movs_ptr++;
            *num_movs_ptr = *num_movs_ptr + 1;
        }
    }
}

//--------------------------------------------------
// print_status
//--------------------------------------------------
    void print_status(char current_word[NUM_LETTERS], char target_word[NUM_LETTERS], char *letter_ptr, int num_movs) {
        //1. We clean the screen
        system("cls");

        //2. We print the status
        printf("\n----- GAME STATUS -----\n");

        //3. We print the target word
        //printf("Target word:  %s", target_word);
        printf("Target word:\n");
        for (int i = 0; i < NUM_LETTERS; i = i + 1) {
            printf("%c", target_word[i]);
        }
        printf("\n");

        //4. We print the current word
        //printf("Current word:  %s", current_word);
        printf("Current word:\n");
        for (int i = 0; i < NUM_LETTERS; i = i + 1) {
            printf("%c", current_word[i]);
        }
        printf("\n");

        //5. We print the underscore associated to the pointer
        //printf("Position of pointer:  %s", letter_ptr);
        int i = 0;
        for (i = 0; i < NUM_LETTERS; i = i + 1) {
            if (letter_ptr == &current_word[i]) {
                printf("^");
            } else {
                printf(" ");
            }
        }

        //6. We print the number_of_movements
        printf("\nNumber of moves taken:  %d", num_movs);

        //7. We print a last line
        printf("\n-----------------------\n");
    }

//--------------------------------------------------
// is_game_over
//--------------------------------------------------
    int is_game_over(char current_word[NUM_LETTERS], char target_word[NUM_LETTERS], int num_movs, int max_movs) {
        //1. We create the output variable with an initial value.
        int res = 0;

        //2. Game is over if current_word matches target_word

        //2.1. By default we assume current_word and target_word are equal
        int game_over = 1;

        // 2.2. We traverse them to check if they are actually equal
        for (int q = 0; q < NUM_LETTERS; q = q + 1) {
            if (current_word[q] != target_word[q]) {
                game_over = 0;
            }
            res = game_over;
        }

        //2.3. In case they are equal we set the end of the game
        if (game_over == 1) {
            printf("\nCongratulations, you got it!");
            res = 1;
        }

        // 3. Game is over as we have done the max number of movements being allowed
        if (num_movs == max_movs) {
            printf("\nGame over. You have reached the maximum number of moves.");
            res = 1;
        }

        //4. We return the output variable
        return res;
    }

//--------------------------------------------------
// user_game_word
//--------------------------------------------------
    void user_game_word(char current_word[NUM_LETTERS], char target_word[NUM_LETTERS]) {
        //1. We initialise the pointer to the first position of the array
        char *letter_ptr;
        letter_ptr = &current_word[0];
        char **letter_ptr_ptr = &letter_ptr;

        //2. We initialise the num_movs and max_movs
        int num_movs = 0;
        int max_movs = 2 * NUM_LETTERS;
        int *num_movs_ptr = &num_movs;

        //3. We initialise the game to not to be over
        int game_over = 0;

        //4. We print the initial status of the game
        //my_get_char();
        print_status(current_word, target_word, letter_ptr, num_movs);

        //5. We perform the main loop
        do {
            //5.1. We ask for a new command
            char command = ask_for_new_command();

            //5.2. We process the command
            process_movement(current_word, letter_ptr_ptr, num_movs_ptr, command);

            //5.3. We print the current status
            print_status(current_word, target_word, letter_ptr, num_movs);

            //5.4. We determine if the game is over
            game_over = is_game_over(current_word, target_word, num_movs, max_movs);

        } while (game_over == 0);

        //6. Once the game is finished, we display the outcome of it
        if (game_over == 1) {
            print_status(current_word, target_word, letter_ptr, num_movs);
        }
    }