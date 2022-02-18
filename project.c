/* 
 * File:   project.c
 * Authors: riwakaram & taniaaoude & tiyajreige
 *
 * Created on December 1, 2021, 9:38 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "worldCup.h"

int main(int argc, char** argv) {

    const int ROW = 20;
    worldCup wCups[ROW];

    readWorldCups(ROW, wCups);
    printWorldCups(ROW, wCups);

    while (true) {
        printMenu();
        char c;
        scanf("%1s", &c);

        if (c == 'A' || c == 'a') {
            printMenuWorldCup();
            int choice;
            scanf("%d", &choice);
            int r = getWorldCup(ROW, wCups, choice);
            if (r == -2) {
                printf("Wrong input.\n");
            }
        } else if (c == 'B' || c == 'b') {
            printf("Please press:\n"
                    "   1. To print the wins of all the countries\n"
                    "   2. To choose to print the wins of a specific country\n");
            int choice;
            scanf("%d", &choice);
            if (choice != 1 && choice != 2) {
                printf("Wrong Input.\n");
            }
            if (choice == 1) {
                getWins(ROW, wCups, 1, "All");
            } else if (choice == 2) {
                char country[20];
                printMenuWins();
                scanf("%s", country);
                int r = getWins(ROW, wCups, 2, country);
                if (r == -3 || strcmp(country, "All") == 0) {
                    printf("Wrong input");
                }
            }
        } else if (c == 'C' || c == 'c') {
            printf("Please press:\n"
                    "   1. To print the number of times each country was a "
                    "runner-up\n"
                    "   2. To choose to print the number of times a specific "
                    "country was a runner-up\n");
            int choice;
            scanf("%d", &choice);
            if (choice != 1 && choice != 2) {
                printf("Wrong Input.\n");
            }
            if (choice == 1) {
                getRunnerUp(ROW, wCups, 1, "All");
            } else if (choice == 2) {
                char country[20];
                printMenuRunnerUp();
                scanf("%s", country);
                int r = getRunnerUp(ROW, wCups, 2, country);
                if (r == -3 || strcmp(country, "All") == 0) {
                    printf("Wrong Input.\n");
                }
            }
        } else if (c == 'D' || c == 'd') {
            printf("Please press:\n"
                    "   1. To print the number of times each country came "
                    "third\n"
                    "   2. To choose to print the number of times a specific "
                    "country came third\n");
            int choice;
            scanf("%d", &choice);
            if (choice != 1 && choice != 2) {
                printf("Wrong Input.\n");
            }
            if (choice == 1) {
                getThird(ROW, wCups, 1, "All");
            } else if (choice == 2) {
                char country[20];
                printMenuThird();
                scanf("%s", country);
                int r = getThird(ROW, wCups, 2, country);
                if (r == -3 || strcmp(country, "All") == 0) {
                    printf("Wrong Input.\n");
                }
            }
        } else if (c == 'E' || c == 'e') {
            printf("Please press:\n"
                    "   1. To print the number of times each country came "
                    "fourth\n"
                    "   2. To choose to print the number of times a specific "
                    "country came fourth\n");
            int choice;
            scanf("%d", &choice);
            if (choice != 1 && choice != 2) {
                printf("Wrong Input.\n");
            }
            if (choice == 1) {
                getFourth(ROW, wCups, 1, "All");
            } else if (choice == 2) {
                char country[20];
                printMenuFourth();
                scanf("%s", country);
                int r = getFourth(ROW, wCups, 2, country);
                if (r == -3 || strcmp(country, "All") == 0) {
                    printf("Wrong Input.\n");
                }
            }
        } else if (c == 'F' || c == 'f') {
            getGoalsMaximums(ROW, wCups);
        } else if (c == 'G' || c == 'g') {
            getGoalsMinimums(ROW, wCups);
        } else if (c == 'H' || c == 'h') {
            getGoalsAverage(ROW, wCups);
        } else if (c == 'I' || c == 'i') {
            printf("Please press:\n"
                    "   1. To print the number of qualified teams for the world"
                    " cups throughout the years\n"
                    "   2. To choose to print the number qualified teams for "
                    "the world cup of a specific years\n");
            int choice;
            scanf("%d", &choice);
            if (choice != 1 && choice != 2) {
                printf("Wrong Input.\n");
            }
            if (choice == 1) {
                getYearsQualifiedTeams(ROW, wCups, 1, 0);
            } else if (choice == 2) {
                int y;
                printMenuQualifiedTeams();
                scanf("%d", &y);
                int r = getYearsQualifiedTeams(ROW, wCups, 2, y);
                if (r == -3 || y == 0) {
                    printf("Wrong Input.\n");
                }
            }
        } else if (c == 'J' || c == 'j') {
            getAttendancesMaximums(ROW, wCups);
        } else if (c == 'K' || c == 'k') {
            getAttendancesMinimums(ROW, wCups);
        } else if (c == 'L' || c == 'l') {
            getAttendancesAverage(ROW, wCups);
        } else if (c == 'M' || c == 'm') {
            printf("Please press:\n"
                    "   1. To print all the countries where the world cups took"
                    " place throughout the year\n"
                    "   2. To print the country where the world cup took place "
                    "in a specific year\n");
            int choice;
            scanf("%d", &choice);
            if (choice != 1 && choice != 2) {
                printf("Wrong Input.\n");
            }
            if (choice == 1) {
                getCountries(ROW, wCups, 1, 0);
            } else if (choice == 2) {
                int y;
                printMenuCountries();
                scanf("%d", &y);
                int r = getCountries(ROW, wCups, 2, y);
                if (r == -3 || y == 0) {
                    printf("Wrong Input.\n");
                }
            }
        } else if (c == 'Z' || c == 'z') {
            printf("Thank you!\nExiting...\n");
            break;
        } else {
            printf("Wrong input. Try again please.\n");
        }
    }

    return (EXIT_SUCCESS);
}
