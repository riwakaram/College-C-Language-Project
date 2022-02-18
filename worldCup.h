/* 
 * File:   worldCup.h
 * Authors: riwakaram & taniaaoude & tiyajreige
 *
 * Created on December 4, 2021, 7:37 PM
 */

#ifndef WORLDCUP_H
#define WORLDCUP_H

#ifdef __cplusplus
extern "C" {
#endif

    typedef struct {
        int year;
        char country[20];
        char winner[20];
        char runnerUp[20];
        char third[20];
        char fourth[20];
        int goalsScored;
        int qualifiedTeams;
        int matchesPlayed;
        int attendance;
    } worldCup;

    int readWorldCups(int row, worldCup wCup[row]);
    int printWorldCups(int row, worldCup wCup[row]);
    void printMenu();
    int getWorldCup(int row, worldCup wCup[row], int year);
    void printMenuWorldCup();
    int getCountries(int row, worldCup wCup[row], int choice, int year);
    void printMenuCountries();
    int getWins(int row, worldCup wCup[row], int choice, char *country);
    void printMenuWins();
    int getRunnerUp(int row, worldCup wCup[row], int choice, char *country);
    void printMenuRunnerUp();
    int getThird(int row, worldCup wCup[row], int choice, char *country);
    void printMenuThird();
    int getFourth(int row, worldCup wCup[row], int choice, char *country);
    void printMenuFourth();
    int getGoalsMaximums(int row, worldCup wCup[row]);
    int getGoalsMinimums(int row, worldCup wCup[row]);
    int getGoalsAverage(int row, worldCup wCup[row]);
    int getYearsQualifiedTeams(int row, worldCup wCup[row], int choice, int num);
    void printMenuQualifiedTeams();
    int getAttendancesMaximums(int row, worldCup wCup[row]);
    int getAttendancesMinimums(int row, worldCup wCup[row]);
    int getAttendancesAverage(int row, worldCup wCup[row]);

#ifdef __cplusplus
}
#endif

#endif /* WORLDCUP_H */
