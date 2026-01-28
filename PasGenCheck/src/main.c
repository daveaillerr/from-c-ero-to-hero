#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>
#include <time.h>

#define STRONG_LENGTH 16

// Color codes for Windows
#define COLOR_RESET 7
#define COLOR_GREEN 10
#define COLOR_RED 12
#define COLOR_YELLOW 14
#define COLOR_CYAN 11
#define COLOR_MAGENTA 13
#define COLOR_BLUE 9

typedef int (*standardPassword)(const char *); 

const char *lowercase = "abcdefghijklmnopqrstuvwxyz";
const char *uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const char *digits = "1234567890";
const char *special = "!@#$^&*()_+-=";

void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void printWithDelay(const char *text, int delay_ms) {
    for (int i = 0; text[i] != '\0'; i++) {
        printf("%c", text[i]);
        fflush(stdout);
        Sleep(delay_ms);
    }
}

void loadingAnimation(const char *message, int dots) {
    setColor(COLOR_CYAN);
    printf("\n\t%s", message);
    fflush(stdout);
    for (int i = 0; i < dots; i++) {
        printf(".");
        fflush(stdout);
        Sleep(300);
    }
    setColor(COLOR_RESET);
}

void printSeparator() {
    setColor(COLOR_CYAN);
    printf("\n\t");
    for (int i = 0; i < 50; i++) {
        printf("═");
    }
    printf("\n");
    setColor(COLOR_RESET);
}

void greet(){
    setColor(COLOR_CYAN);
    printf("╔════════════════════════════════════════════════╗\n");
    printf("║                                                ║\n");
    setColor(COLOR_MAGENTA);
    printf("║     ██████╗  ███████╗  ██████╗  ███╗   ██╗     ║\n");
    printf("║     ██╔══██╗ ██╔════╝ ██╔════╝  ████╗  ██║     ║\n");
    printf("║     ██████╔╝ ███████╗ ██║  ███╗ ██╔██╗ ██║     ║\n");
    printf("║     ██╔═══╝       ██║ ██║   ██║ ██║╚██╗██║     ║\n");
    printf("║     ██║      ███████║ ╚██████╔╝ ██║ ╚████║     ║\n");
    printf("║     ╚═╝      ╚══════╝  ╚═════╝  ╚═╝  ╚═══╝     ║\n");
    setColor(COLOR_CYAN);
    printf("║        - Password Generator & Checker -        ║\n");
    printf("║                                                ║\n");
    printf("╚════════════════════════════════════════════════╝\n\n");
    setColor(COLOR_YELLOW);
    printf("\t1. Generate Password\n");
    printf("\t2. Check Password\n");
    printf("\t3. Exit");
    setColor(COLOR_RESET);
}

int repeatProgram(){
    char confirmationChoice[10];

    do{
        setColor(COLOR_YELLOW);
        printf("\n\n\tDo you want to try again? (Y/N): ");
        setColor(COLOR_RESET);
        if (fgets(confirmationChoice, sizeof(confirmationChoice), stdin) != NULL);
        confirmationChoice[strcspn(confirmationChoice, "\n")] = 0;

        if (strlen(confirmationChoice) == 1){
            char upperChoice = toupper(confirmationChoice[0]);

            if (upperChoice == 'Y'){
                return 1;
            }

            else if (upperChoice == 'N'){
                return 0;
            }
        }
        setColor(COLOR_RED);
        printf("\n\t [X] Please input valid fields (Y/N)...");
        setColor(COLOR_RESET);

    }while(1);

}

int generatePassword(){

    const char *rules_set[] = {
        lowercase,
        uppercase,
        digits,
        special
    };

    char generatedChar[256] = "";
    int min = 16, max = 24;

    int rangeNum = (rand() % (max - min + 1)) + min;

    printSeparator();
    loadingAnimation("Generating secure password", 5);
    printf("\n");
    printSeparator();

    setColor(COLOR_GREEN);
    printf("\n\t[!] Your Generated Password:\n\n\t");
    setColor(COLOR_YELLOW);
    printf("┌");
    for (int i = 0; i < rangeNum + 2; i++) printf("─");
    printf("┐\n\t│ ");
    setColor(COLOR_RESET);

    for (int i = 0; i < rangeNum; i++){
        int setIndex = rand() % 4;
        int charIndex = rand() % strlen(rules_set[setIndex]);

        generatedChar[i] = rules_set[setIndex][charIndex];
        
        printf("%c", generatedChar[i]);
        fflush(stdout);
        Sleep(50);
    }
    generatedChar[rangeNum] = '\0';

    setColor(COLOR_YELLOW);
    printf(" │\n\t└");
    for (int i = 0; i < rangeNum + 2; i++) printf("─");
    printf("┘\n");
    setColor(COLOR_RESET);

    setColor(COLOR_GREEN);
    printf("\n\t[/] Password length: %d characters\n", rangeNum);
    printf("\t[/] Password strength: ");
    setColor(COLOR_CYAN);
    printf("Strong\n");
    setColor(COLOR_RESET);

    printSeparator();

    if (repeatProgram() == 1){
        system("cls");
        generatePassword();
    }

}

int isPasswordLong(const char *password){
    return strlen(password) >= STRONG_LENGTH;
}

int isPasswordUp(const char *password){
    while (*password){
        if (isupper((unsigned char)*password)) return 1;
        *password++;
    }
    return 0;
}

int isPasswordDig(const char *password){
    while (*password){
        if (isdigit((unsigned char)*password)) return 1;
        *password++;
    }
    return 0;
}

int isPasswordSpecial(const char *password){
    while (*password){
        if (ispunct((unsigned char)*password)) return 1;
        *password++;
    }
    return 0;
}

int isPasswordwithSpace(const char *password){
    while(*password){
        if (isspace((unsigned char)*password)) return 1;
        *password++; 
    }
    return 0;
}

void checkPassword(){
    char password[100];

    standardPassword rules[] = {
        isPasswordLong,
        isPasswordUp,
        isPasswordDig,
        isPasswordSpecial,
        isPasswordwithSpace
    };

    const char *rulesName[] = {
        "Your password is not 16 characters long",
        "Your password does not contain uppercase letters",
        "Your password does not contain digits",
        "Your password does not contain special characters",
        "Your password contains spaces, don't include it"
    };

    printSeparator();
    setColor(COLOR_CYAN);
    printf("\n\t[!] Password Security Checker\n");
    printSeparator();
    
    setColor(COLOR_YELLOW);
    printf("\n\tPlease Enter Password: ");
    setColor(COLOR_RESET);
    fgets(password, sizeof(password),stdin);

    loadingAnimation("\tAnalyzing password", 3);
    printf("\n");
    printSeparator();

    int RULE_SIZE = sizeof(rules) / sizeof(rules[0]);
    int VALID = 1;

    setColor(COLOR_CYAN);
    printf("\n\t[!] Security Check Results:\n\n");
    setColor(COLOR_RESET);

    for (int i = 0; i < RULE_SIZE; i++){
        if (!rules[i](password)){
            setColor(COLOR_RED);
            printf("\t[X] %s\n", rulesName[i]);
            setColor(COLOR_RESET);
            VALID = 0;
        } else {
            if (i != 4) { 
                setColor(COLOR_GREEN);
                if (i == 0) printf("\t[/] Password length is sufficient\n");
                else if (i == 1) printf("\t[/] Contains uppercase letters\n");
                else if (i == 2) printf("\t[/] Contains digits\n");
                else if (i == 3) printf("\t[/] Contains special characters\n");
                setColor(COLOR_RESET);
            }
        }
    }

    printf("\n");
    printSeparator();

    if (VALID){
        setColor(COLOR_GREEN);
        printf("\n\t[!] Strong Password! Your password is secure.\n");
        setColor(COLOR_RESET);
    } else {
        setColor(COLOR_RED);
        printf("\n\t[X] Weak Password! Please address the issues above.\n");
        setColor(COLOR_RESET);
    }

    printSeparator();

    if (repeatProgram() == 1){
        system("cls");
        checkPassword();
    }
    
}

int exitProgram(){
    char confirmationChoice[10];

    do{
        printSeparator();
        setColor(COLOR_YELLOW);
        printf("\n\tDo you really want to exit? (Y/N): ");
        setColor(COLOR_RESET);
        if (fgets(confirmationChoice, sizeof(confirmationChoice), stdin) != NULL);
        confirmationChoice[strcspn(confirmationChoice, "\n")] = 0;

        if (strlen(confirmationChoice) == 1){
            char upperChoice = toupper(confirmationChoice[0]);

            if (upperChoice == 'Y'){
                printSeparator();
                setColor(COLOR_CYAN);
                printf("\n\t");
                printWithDelay("Thank you for using Password Generator!", 30);
                printf("\n\t");
                printWithDelay("Exiting Program", 100);
                printf("...\n");
                printSeparator();
                setColor(COLOR_RESET);
                Sleep(500);
                exit(0);
            }

            else if (upperChoice == 'N'){
                setColor(COLOR_GREEN);
                printf("\n\t[!] Continuing the program...\n");
                setColor(COLOR_RESET);
                printSeparator();
                Sleep(500);
                return 0;
            }
        }
        setColor(COLOR_RED);
        printf("\n\t[X] Please input valid fields (Y/N)...");
        setColor(COLOR_RESET);
    }while(1);

}

int main(){
    setlocale(LC_ALL, "en_US.UTF-8");
    srand(time(NULL));

    char userChoice;

    do{
        greet();
        setColor(COLOR_YELLOW);
        printf("\n\n\tEnter your choice: ");
        setColor(COLOR_RESET);

        if (scanf("%d", &userChoice) != 1) {
            while (getchar() != '\n');
            setColor(COLOR_RED);
            printf("\n\t[X] Please input valid fields...\n");
            setColor(COLOR_RESET);
            Sleep(1000);
        }
        while (getchar() != '\n');

        switch(userChoice){
            case 1:
                system("cls");
                generatePassword();
                Sleep(1000);
                system("cls");
            break;
            case 2: 
                system("cls");
                checkPassword();
                Sleep(1000);
                system("cls");
            break;
            case 3:
                system("cls");
                exitProgram();
                Sleep(1000);
                system("cls");
            break;
            default:
                setColor(COLOR_RED);
                printf("\n\t[X] Invalid choice! Please select 1, 2, or 3.\n");
                setColor(COLOR_RESET);
                Sleep(1500);
                system("cls");
            break;
        }

    }while(1);

    return 0;
}