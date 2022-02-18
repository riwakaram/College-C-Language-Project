/* 
 * File:   worldCup.c
 * Authors: riwakaram & taniaaoude & tiyajreige
 *
 * Created on December 4, 2021, 7:54 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "worldCup.h"

int readWorldCups(int row, worldCup wCup[row]) {
    if (!wCup || row <= 0) return -1;

    char file_name[] = "WorldCups.csv";
    FILE *fd = fopen(file_name, "r");

    if (!fd) {
        printf("ERROR reading file %s", file_name);
        return (EXIT_FAILURE);
    }

    char buffer[5000];
    int i;

    fgets(buffer, 5000, fd);

    for (i = 0; fgets(buffer, 5000, fd); i++) {
        char *data = strtok(buffer, ",");

        sscanf(data, "%d", &wCup[i].year);
        data = strtok(NULL, ",");

        strcpy(wCup[i].country, data);
        data = strtok(NULL, ",");

        strcpy(wCup[i].winner, data);
        data = strtok(NULL, ",");

        strcpy(wCup[i].runnerUp, data);
        data = strtok(NULL, ",");

        strcpy(wCup[i].third, data);
        data = strtok(NULL, ",");

        strcpy(wCup[i].fourth, data);
        data = strtok(NULL, ",");

        sscanf(data, "%d", &wCup[i].goalsScored);
        data = strtok(NULL, ",");

        sscanf(data, "%d", &wCup[i].qualifiedTeams);
        data = strtok(NULL, ",");

        sscanf(data, "%d", &wCup[i].matchesPlayed);
        data = strtok(NULL, ",");

        int k, j = 0;
        char temp[10];
        for (k = 0; data[k] != '\n'; k++) {
            temp[k] = 0;
            if (data[k] != '.') {
                temp[j] = data[k];
                j++;
            }
        }
        sscanf(temp, "%d", &wCup[i].attendance);
    }

    fclose(fd);

    return 0;
}

int printWorldCups(int row, worldCup wCup[row]) {
    if (!wCup || row <= 0) return -1;

    printf("%5s%14s%12s%17s%14s%17s%15s%18s%17s%13s\n", "Year", "Country",
            "Winner", "Runners-Up", "Third", "Fourth", "Goals Scored",
            "Qualified Teams", "Matches Played", "Attendance");
    for (int i = 0; i < 142; i++) {
        printf("-");
    }
    printf("\n");

    int i;
    for (i = 0; i < row; i++) {
        printf("%5d%14s%12s%17s%14s%17s%15d%18d%17d%13d\n", wCup[i].year,
                wCup[i].country, wCup[i].winner, wCup[i].runnerUp,
                wCup[i].third, wCup[i].fourth, wCup[i].goalsScored,
                wCup[i].qualifiedTeams, wCup[i].matchesPlayed,
                wCup[i].attendance);
    }

    printf("\n");

    return 0;
}

void printMenu() {
    printf("\nPlease choose one of the options below:\n\n");
    printf("    A. Getting the information for a specific year\n");
    printf("    B. Getting the number of wins per country\n");
    printf("    C. Getting the number of times a country has been a "
            "runner-up\n");
    printf("    D. Getting the number of times a country came in third "
            "place\n");
    printf("    E. Getting the number of times a country came in fourth "
            "place\n");
    printf("    F. Getting the year(s) in which the maximum number of goals "
            "were scored\n");
    printf("    G. Getting the year(s) in which the minimum number of goals "
            "were scored\n");
    printf("    H. Getting the average goals throughout the years\n");
    printf("    I. Getting the number of qualified teams per year\n");
    printf("    J. Getting the year(s) that had the most number of "
            "attendees\n");
    printf("    K. Getting the year(s) that had the least number of "
            "attendees\n");
    printf("    L. Getting the average of attendees throughout the years\n");
    printf("    M. Getting the country where the world cup took place by "
            "year(s)\n");
    printf("    Z. Exit\n");
}

int getWorldCup(int row, worldCup wCup[row], int year) {
    if (!wCup || row <= 0) return -1;
    if (year != 1930 && year != 1934 && year != 1938 && year != 1950
            && year != 1954 && year != 1958 && year != 1962 && year != 1966
            && year != 1970 && year != 1974 && year != 1978 && year != 1982
            && year != 1986 && year != 1990 && year != 1994 && year != 1998
            && year != 2002 && year != 2006 && year != 2010 && year != 2014)
        return -2;

    int i, index;
    for (i = 0; i < row; i++) {
        if (year == wCup[i].year) {
            index = i;
        }
    }

    printf("Year: %d\n", wCup[index].year);
    printf("Country: %s\n", wCup[index].country);
    printf("Winner: %s\n", wCup[index].winner);
    printf("Runner-up: %s\n", wCup[index].runnerUp);
    printf("Third: %s\n", wCup[index].third);
    printf("Fourth: %s\n", wCup[index].fourth);
    printf("Goals Scored: %d\n", wCup[index].goalsScored);
    printf("Qualified Teams: %d\n", wCup[index].qualifiedTeams);
    printf("Matches Played: %d\n", wCup[index].matchesPlayed);
    printf("Attendance: %d\n", wCup[index].attendance);

    return 0;
}

void printMenuWorldCup() {
    printf("The years during which a world cup occurred are:\n");
    printf("1930, 1934, 1938, 1950, 1954, 1958, 1962, 1966, 1970, "
            "1974, 1978, 1982, 1986, 1990, 1994, 1998, 2002, 2006, 2010, "
            "2014\n");
    printf("Please choose a year to display all its details:\n");
}

int getCountries(int row, worldCup wCup[row], int choice, int year) {
    if (!wCup || row <= 0) return -1;
    if (choice != 1 && choice != 2) return -2;
    if (year != 1930 && year != 1934 && year != 1938 && year != 1950
            && year != 1954 && year != 1958 && year != 1962 && year != 1966
            && year != 1970 && year != 1974 && year != 1978 && year != 1982
            && year != 1986 && year != 1990 && year != 1994 && year != 1998
            && year != 2002 && year != 2006 && year != 2010 && year != 2014
            && year != 0)
        return -3;

    if (choice == 1) {
        int i;
        for (i = 0; i < row; i++) {
            printf("In year %d, the world cup took place in %s.\n",
                    wCup[i].year, wCup[i].country);
        }
    } else if (choice == 2) {
        int i, index;
        for (i = 0; i < row; i++) {
            if (year == wCup[i].year) {
                index = i;
            }
        }
        printf("In year %d, the world cup took place in %s.\n", year,
                wCup[index].country);
    }

    return 0;
}

void printMenuCountries() {
    printf("The years during which a world cup occurred are:\n");
    printf("1930, 1934, 1938, 1950, 1954, 1958, 1962, 1966, 1970, "
            "1974, 1978, 1982, 1986, 1990, 1994, 1998, 2002, 2006, 2010, "
            "2014\n");
    printf("Please choose a year to display the country it took place in:\n");
}

int getWins(int row, worldCup wCup[row], int choice, char *country) {
    if (!wCup || row <= 0 || !country) return -1;
    if (choice != 1 && choice != 2) return -2;
    if (strcmp(country, "Uruguay") != 0
            && strcmp(country, "Italy") != 0
            && strcmp(country, "Germany") != 0
            && strcmp(country, "Germany FR") != 0
            && strcmp(country, "Brazil") != 0
            && strcmp(country, "England") != 0
            && strcmp(country, "Argentina") != 0
            && strcmp(country, "France") != 0
            && strcmp(country, "Spain") != 0
            && strcmp(country, "All") != 0) return -3;

    int countUru = 0, countIta = 0, countGer = 0, countBraz = 0, countEng = 0,
            countArg = 0, countFra = 0, countSpa = 0, yearsUru[row],
            yearsIta[row], yearsGer[row], yearsBraz[row], yearsEng[row],
            yearsArg[row], yearsFra[row], yearsSpa[row];

    yearsIta[0] = 0;
    yearsGer[0] = 0;
    yearsBraz[0] = 0;
    yearsEng[0] = 0;
    yearsArg[0] = 0;
    yearsFra[0] = 0;
    yearsSpa[0] = 0;

    int i;
    for (i = 0; i < row; i++) {
        char *temp = wCup[i].winner;
        if (strcmp(temp, "Uruguay") == 0) {
            yearsUru[countUru] = wCup[i].year;
            countUru++;
        } else if (strcmp(temp, "Italy") == 0) {
            yearsIta[countIta] = wCup[i].year;
            countIta++;
        } else if (strcmp(temp, "Germany") == 0
                || strcmp(temp, "Germany FR") == 0) {
            yearsGer[countGer] = wCup[i].year;
            countGer++;
        } else if (strcmp(temp, "Brazil") == 0) {
            yearsBraz[countBraz] = wCup[i].year;
            countBraz++;
        } else if (strcmp(temp, "England") == 0) {
            yearsEng[countEng] = wCup[i].year;
            countEng++;
        } else if (strcmp(temp, "Argentina") == 0) {
            yearsArg[countArg] = wCup[i].year;
            countArg++;
        } else if (strcmp(temp, "France") == 0) {
            yearsFra[countFra] = wCup[i].year;
            countFra++;
        } else if (strcmp(temp, "Spain") == 0) {
            yearsSpa[countSpa] = wCup[i].year;
            countSpa++;
        }
    }

    if (choice == 1) {
        printf("Number of wins for each country\n");

        int i;
        for (i = 0; i < 31; i++) {
            printf("-");
        }
        printf("\n");

        printf("Uruguay has %d %s in the following %s:\n", countUru,
                countUru == 1 ? "win" : "wins",
                countUru == 1 ? "year" : "years");
        for (i = 0; i < countUru; i++) {
            printf("%d\n", yearsUru[i]);
        }
        printf("\n");

        printf("Italy has %d %s in the following %s:\n", countIta,
                countIta == 1 ? "win" : "wins",
                countIta == 1 ? "year" : "years");
        for (i = 0; i < countIta; i++) {
            printf("%d\n", yearsIta[i]);
        }
        printf("\n");

        printf("Germany has %d %s in the following %s:\n", countGer,
                countGer == 1 ? "win" : "wins",
                countGer == 1 ? "year" : "years");
        for (i = 0; i < countGer; i++) {
            printf("%d\n", yearsGer[i]);
        }
        printf("\n");

        printf("Brazil has %d %s in the following %s:\n", countBraz,
                countBraz == 1 ? "win" : "wins",
                countBraz == 1 ? "year" : "years");
        for (i = 0; i < countBraz; i++) {
            printf("%d\n", yearsBraz[i]);
        }
        printf("\n");

        printf("England has %d %s in the following %s:\n", countEng,
                countEng == 1 ? "win" : "wins",
                countEng == 1 ? "year" : "years");
        for (i = 0; i < countEng; i++) {
            printf("%d\n", yearsEng[i]);
        }
        printf("\n");

        printf("Argentina has %d %s in the following %s:\n", countArg,
                countArg == 1 ? "win" : "wins",
                countArg == 1 ? "year" : "years");
        for (i = 0; i < countArg; i++) {
            printf("%d\n", yearsArg[i]);
        }
        printf("\n");

        printf("France has %d %s in the following %s:\n", countFra,
                countFra == 1 ? "win" : "wins",
                countFra == 1 ? "year" : "years");
        for (i = 0; i < countFra; i++) {
            printf("%d\n", yearsFra[i]);
        }
        printf("\n");

        printf("Spain has %d %s in the following %s:\n", countSpa,
                countSpa == 1 ? "win" : "wins",
                countSpa == 1 ? "year" : "years");
        for (i = 0; i < countSpa; i++) {
            printf("%d\n", yearsSpa[i]);
        }
        printf("\n");
    } else if (choice == 2) {
        if (strcmp(country, "Uruguay") == 0) {
            printf("Uruguay has %d %s in the following %s:\n", countUru,
                    countUru == 1 ? "win" : "wins",
                    countUru == 1 ? "year" : "years");
            for (i = 0; i < countUru; i++) {
                printf("%d\n", yearsUru[i]);
            }
            printf("\n");
        } else if (strcmp(country, "Italy") == 0) {
            printf("Italy has %d %s in the following %s:\n", countIta,
                    countIta == 1 ? "win" : "wins",
                    countIta == 1 ? "year" : "years");
            for (i = 0; i < countIta; i++) {
                printf("%d\n", yearsIta[i]);
            }
            printf("\n");
        } else if (strcmp(country, "Germany") == 0) {
            printf("Germany has %d %s in the following %s:\n", countGer,
                    countGer == 1 ? "win" : "wins",
                    countGer == 1 ? "year" : "years");
            for (i = 0; i < countGer; i++) {
                printf("%d\n", yearsGer[i]);
            }
            printf("\n");
        } else if (strcmp(country, "Brazil") == 0) {
            printf("Brazil has %d %s in the following %s:\n", countBraz,
                    countBraz == 1 ? "win" : "wins",
                    countBraz == 1 ? "year" : "years");
            for (i = 0; i < countBraz; i++) {
                printf("%d\n", yearsBraz[i]);
            }
            printf("\n");
        } else if (strcmp(country, "England") == 0) {
            printf("England has %d %s in the following %s:\n", countEng,
                    countEng == 1 ? "win" : "wins",
                    countEng == 1 ? "year" : "years");
            for (i = 0; i < countEng; i++) {
                printf("%d\n", yearsEng[i]);
            }
            printf("\n");
        } else if (strcmp(country, "Argentina") == 0) {
            printf("Argentina has %d %s in the following %s:\n", countArg,
                    countArg == 1 ? "win" : "wins",
                    countArg == 1 ? "year" : "years");
            for (i = 0; i < countArg; i++) {
                printf("%d\n", yearsArg[i]);
            }
            printf("\n");
        } else if (strcmp(country, "France") == 0) {
            printf("France has %d %s in the following %s:\n", countFra,
                    countFra == 1 ? "win" : "wins",
                    countFra == 1 ? "year" : "years");
            for (i = 0; i < countFra; i++) {
                printf("%d\n", yearsFra[i]);
            }
            printf("\n");
        } else if (strcmp(country, "Spain") == 0) {
            printf("Spain has %d %s in the following %s:\n", countSpa,
                    countSpa == 1 ? "win" : "wins",
                    countSpa == 1 ? "year" : "years");
            for (i = 0; i < countSpa; i++) {
                printf("%d\n", yearsSpa[i]);
            }
            printf("\n");
        }
        printf("\n");
    }

    return 0;
}

void printMenuWins() {
    printf("The countries that won at least once are:\n");
    printf("Uruguay, Italy, Germany, Brazil, England, Argentina, "
            "France, Spain\n");
    printf("Please choose the country whose number of wins you'd "
            "like to view:\n");
}

int getRunnerUp(int row, worldCup wCup[row], int choice, char *country) {
    if (!wCup || row <= 0 || !country) return -1;
    if (choice != 1 && choice != 2) return -2;
    if (strcmp(country, "Argentina") != 0
            && strcmp(country, "Czechoslovakia") != 0
            && strcmp(country, "Hungary") != 0
            && strcmp(country, "Brazil") != 0
            && strcmp(country, "Sweden") != 0
            && strcmp(country, "Germany") != 0
            && strcmp(country, "Germany FR") != 0
            && strcmp(country, "Italy") != 0
            && strcmp(country, "Netherlands") != 0
            && strcmp(country, "France") != 0
            && strcmp(country, "All") != 0) return -3;

    int countArg = 0, countCze = 0, countHun = 0, countBraz = 0, countSwe = 0,
            countGer = 0, countIta = 0, countNeth = 0, countFra = 0,
            yearsArg[row], yearsCze[row], yearsHun[row], yearsBraz[row],
            yearsSwe[row], yearsGer[row], yearsIta[row], yearsNeth[row],
            yearsFra[row];

    yearsArg[0] = 0;
    yearsCze[0] = 0;
    yearsHun[0] = 0;
    yearsBraz[0] = 0;
    yearsSwe[0] = 0;
    yearsGer[0] = 0;
    yearsIta[0] = 0;
    yearsNeth[0] = 0;
    yearsFra[0] = 0;

    int i;
    for (i = 0; i < row; i++) {
        char *temp = wCup[i].runnerUp;
        if (strcmp(temp, "Argentina") == 0) {
            yearsArg[countArg] = wCup[i].year;
            countArg++;
        } else if (strcmp(temp, "Czechoslovakia") == 0) {
            yearsCze[countCze] = wCup[i].year;
            countCze++;
        } else if (strcmp(temp, "Hungary") == 0) {
            yearsHun[countHun] = wCup[i].year;
            countHun++;
        } else if (strcmp(temp, "Brazil") == 0) {
            yearsBraz[countBraz] = wCup[i].year;
            countBraz++;
        } else if (strcmp(temp, "Sweden") == 0) {
            yearsSwe[countSwe] = wCup[i].year;
            countSwe++;
        } else if (strcmp(temp, "Germany") == 0
                || strcmp(temp, "Germany FR") == 0) {
            yearsGer[countGer] = wCup[i].year;
            countGer++;
        } else if (strcmp(temp, "Italy") == 0) {
            yearsIta[countIta] = wCup[i].year;
            countIta++;
        } else if (strcmp(temp, "Netherlands") == 0) {
            yearsNeth[countNeth] = wCup[i].year;
            countNeth++;
        } else if (strcmp(temp, "France") == 0) {
            yearsFra[countFra] = wCup[i].year;
            countFra++;
        }
    }

    if (choice == 1) {
        printf("Number of times each country was a runner-up:\n");
        int i;
        for (i = 0; i < 45; i++) {
            printf("-");
        }
        printf("\n");

        printf("Argentina was %d %s a runner-up in the following %s:\n",
                countArg, countArg == 1 ? "time" : "times",
                countArg == 1 ? "year" : "years");
        for (i = 0; i < countArg; i++) {
            printf("%d\n", yearsArg[i]);
        }
        printf("\n");

        printf("Czechoslovakia was %d %s a runner-up in the following %s:\n",
                countCze, countCze == 1 ? "time" : "times",
                countCze == 1 ? "year" : "years");
        for (i = 0; i < countCze; i++) {
            printf("%d\n", yearsCze[i]);
        }
        printf("\n");

        printf("Hungary was %d %s a runner-up in the following %s:\n",
                countHun, countHun == 1 ? "time" : "times",
                countHun == 1 ? "year" : "years");
        for (i = 0; i < countHun; i++) {
            printf("%d\n", yearsHun[i]);
        }
        printf("\n");

        printf("Brazil was %d %s a runner-up in the following %s:\n",
                countBraz, countBraz == 1 ? "time" : "times",
                countBraz == 1 ? "year" : "years");
        for (i = 0; i < countBraz; i++) {
            printf("%d\n", yearsBraz[i]);
        }
        printf("\n");

        printf("Sweden was %d %s a runner-up in the following %s:\n",
                countSwe, countSwe == 1 ? "time" : "times",
                countSwe == 1 ? "year" : "years");
        for (i = 0; i < countSwe; i++) {
            printf("%d\n", yearsSwe[i]);
        }
        printf("\n");

        printf("Germany was %d %s a runner-up in the following %s:\n",
                countGer, countGer == 1 ? "time" : "times",
                countGer == 1 ? "year" : "years");
        for (i = 0; i < countGer; i++) {
            printf("%d\n", yearsGer[i]);
        }
        printf("\n");

        printf("Italy was %d %s a runner-up in the following %s:\n",
                countIta, countIta == 1 ? "time" : "times",
                countIta == 1 ? "year" : "years");
        for (i = 0; i < countIta; i++) {
            printf("%d\n", yearsIta[i]);
        }
        printf("\n");

        printf("Netherlands was %d %s a runner-up in the following %s:\n",
                countNeth, countNeth == 1 ? "time" : "times",
                countNeth == 1 ? "year" : "years");
        for (i = 0; i < countNeth; i++) {
            printf("%d\n", yearsNeth[i]);
        }
        printf("\n");

        printf("France was %d %s a runner-up in the following %s:\n",
                countFra, countFra == 1 ? "time" : "times",
                countFra == 1 ? "year" : "years");
        for (i = 0; i < countFra; i++) {
            printf("%d\n", yearsFra[i]);
        }
        printf("\n");
    } else if (choice == 2) {
        if (strcmp(country, "Argentina") == 0) {
            printf("Argentina was %d %s a runner-up in the following %s:\n",
                    countArg, countArg == 1 ? "time" : "times",
                    countArg == 1 ? "year" : "years");
            for (i = 0; i < countArg; i++) {
                printf("%d\n", yearsArg[i]);
            }
            printf("\n");
        } else if (strcmp(country, "Czechoslovakia") == 0) {
            printf("Czechoslovakia was %d %s a runner-up in the following %s:\n",
                    countCze, countCze == 1 ? "time" : "times",
                    countCze == 1 ? "year" : "years");
            for (i = 0; i < countCze; i++) {
                printf("%d\n", yearsCze[i]);
            }
            printf("\n");
        } else if (strcmp(country, "Hungary") == 0) {
            printf("Hungary was %d %s a runner-up in the following %s:\n",
                    countHun, countHun == 1 ? "time" : "times",
                    countHun == 1 ? "year" : "years");
            for (i = 0; i < countHun; i++) {
                printf("%d\n", yearsHun[i]);
            }
            printf("\n");
        } else if (strcmp(country, "Brazil") == 0) {
            printf("Brazil was %d %s a runner-up in the following %s:\n",
                    countBraz, countBraz == 1 ? "time" : "times",
                    countBraz == 1 ? "year" : "years");
            for (i = 0; i < countBraz; i++) {
                printf("%d\n", yearsBraz[i]);
            }
            printf("\n");
        } else if (strcmp(country, "Sweden") == 0) {
            printf("Sweden was %d %s a runner-up in the following %s:\n",
                    countSwe, countSwe == 1 ? "time" : "times",
                    countSwe == 1 ? "year" : "years");
            for (i = 0; i < countSwe; i++) {
                printf("%d\n", yearsSwe[i]);
            }
            printf("\n");
        } else if (strcmp(country, "Germany") == 0) {
            printf("Germany was %d %s a runner-up in the following %s:\n",
                    countGer, countGer == 1 ? "time" : "times",
                    countGer == 1 ? "year" : "years");
            for (i = 0; i < countGer; i++) {
                printf("%d\n", yearsGer[i]);
            }
            printf("\n");
        } else if (strcmp(country, "Italy") == 0) {
            printf("Italy was %d %s a runner-up in the following %s:\n",
                    countIta, countIta == 1 ? "time" : "times",
                    countIta == 1 ? "year" : "years");
            for (i = 0; i < countIta; i++) {
                printf("%d\n", yearsIta[i]);
            }
            printf("\n");
        } else if (strcmp(country, "Netherlands") == 0) {
            printf("Netherlands was %d %s a runner-up in the following %s:\n",
                    countNeth, countNeth == 1 ? "time" : "times",
                    countNeth == 1 ? "year" : "years");
            for (i = 0; i < countNeth; i++) {
                printf("%d\n", yearsNeth[i]);
            }
            printf("\n");
        } else if (strcmp(country, "France") == 0) {
            printf("France was %d %s a runner-up in the following %s:\n",
                    countFra, countFra == 1 ? "time" : "times",
                    countFra == 1 ? "year" : "years");
            for (i = 0; i < countFra; i++) {
                printf("%d\n", yearsFra[i]);
            }
            printf("\n");
        }
    }

    return 0;
}

void printMenuRunnerUp() {
    printf("The countries that were a runner-up at least once are:\n");
    printf("Argentina, Czechoslovakia, Hungary, Brazil, Sweden, Germany, Italy,"
            " Netherlands, France\n");
    printf("Please choose a country to display its number of reoccurrence as "
            "a runner-up:\n");
}

int getThird(int row, worldCup wCup[row], int choice, char *country) {
    if (!wCup || row <= 0 || !country) return -1;
    if (choice != 1 && choice != 2) return -2;
    if (strcmp(country, "USA") != 0
            && strcmp(country, "Germany") != 0
            && strcmp(country, "Germany FR") != 0
            && strcmp(country, "Brazil") != 0
            && strcmp(country, "Sweden") != 0
            && strcmp(country, "Austria") != 0
            && strcmp(country, "France") != 0
            && strcmp(country, "Chile") != 0
            && strcmp(country, "Portugal") != 0
            && strcmp(country, "Poland") != 0
            && strcmp(country, "Croatia") != 0
            && strcmp(country, "Turkey") != 0
            && strcmp(country, "Netherlands") != 0
            && strcmp(country, "All") != 0) return -3;

    int countUSA = 0, countGer = 0, countBraz = 0, countSwe = 0, countAus = 0,
            countFra = 0, countChi = 0, countPor = 0, countPol = 0,
            countCro = 0, countTur = 0, countNeth = 0, yearsUSA[row],
            yearsGer[row], yearsBraz[row], yearsSwe[row], yearsAus[row],
            yearsFra[row], yearsChi[row], yearsPor[row], yearsPol[row],
            yearsCro[row], yearsTur[row], yearsNeth[row];

    yearsUSA[0] = 0;
    yearsGer[0] = 0;
    yearsBraz[0] = 0;
    yearsSwe[0] = 0;
    yearsAus[0] = 0;
    yearsFra[0] = 0;
    yearsChi[0] = 0;
    yearsPor[0] = 0;
    yearsPol[0] = 0;
    yearsCro[0] = 0;
    yearsTur[0] = 0;
    yearsNeth[0] = 0;

    int i;
    for (i = 0; i < row; i++) {
        char *temp = wCup[i].third;
        if (strcmp(temp, "USA") == 0) {
            yearsUSA[countUSA] = wCup[i].year;
            countUSA++;
        } else if (strcmp(temp, "Germany") == 0
                || strcmp(temp, "Germany FR") == 0) {
            yearsGer[countGer] = wCup[i].year;
            countGer++;
        } else if (strcmp(temp, "Brazil") == 0) {
            yearsBraz[countBraz] = wCup[i].year;
            countBraz++;
        } else if (strcmp(temp, "Sweden") == 0) {
            yearsSwe[countSwe] = wCup[i].year;
            countSwe++;
        } else if (strcmp(temp, "Austria") == 0) {
            yearsAus[countAus] = wCup[i].year;
            countAus++;
        } else if (strcmp(temp, "France") == 0) {
            yearsFra[countFra] = wCup[i].year;
            countFra++;
        } else if (strcmp(temp, "Chile") == 0) {
            yearsChi[countChi] = wCup[i].year;
            countChi++;
        } else if (strcmp(temp, "Portugal") == 0) {
            yearsPor[countPor] = wCup[i].year;
            countPor++;
        } else if (strcmp(temp, "Poland") == 0) {
            yearsPol[countPol] = wCup[i].year;
            countPol++;
        } else if (strcmp(temp, "Croatia") == 0) {
            yearsCro[countCro] = wCup[i].year;
            countCro++;
        } else if (strcmp(temp, "Turkey") == 0) {
            yearsTur[countTur] = wCup[i].year;
            countTur++;
        } else if (strcmp(temp, "Netherlands") == 0) {
            yearsNeth[countNeth] = wCup[i].year;
            countNeth++;
        }
    }

    if (choice == 1) {
        printf("Number of times each country came third:\n");
        for (int i = 0; i < 40; i++) {
            printf("-");
        }
        printf("\n");

        printf("USA came third %d %s in the following %s:\n", countUSA,
                countUSA == 1 ? "time" : "times",
                countUSA == 1 ? "year" : "years");
        for (i = 0; i < countUSA; i++) {
            printf("%d\n", yearsUSA[i]);
        }
        printf("\n");

        printf("Germany came third %d %s in the following %s:\n", countGer,
                countGer == 1 ? "time" : "times",
                countGer == 1 ? "year" : "years");
        for (i = 0; i < countGer; i++) {
            printf("%d\n", yearsGer[i]);
        }
        printf("\n");

        printf("Brazil came third %d %s in the following %s:\n", countBraz,
                countBraz == 1 ? "time" : "times",
                countBraz == 1 ? "year" : "years");
        for (i = 0; i < countBraz; i++) {
            printf("%d\n", yearsBraz[i]);
        }
        printf("\n");

        printf("Sweden came third %d %s in the following %s:\n", countSwe,
                countSwe == 1 ? "time" : "times",
                countSwe == 1 ? "year" : "years");
        for (i = 0; i < countSwe; i++) {
            printf("%d\n", yearsSwe[i]);
        }
        printf("\n");

        printf("Austria came third %d %s in the following %s:\n", countAus,
                countAus == 1 ? "time" : "times",
                countAus == 1 ? "year" : "years");
        for (i = 0; i < countAus; i++) {
            printf("%d\n", yearsAus[i]);
        }
        printf("\n");

        printf("France came third %d %s in the following %s:\n", countFra,
                countFra == 1 ? "time" : "times",
                countFra == 1 ? "year" : "years");
        for (i = 0; i < countFra; i++) {
            printf("%d\n", yearsFra[i]);
        }
        printf("\n");

        printf("Chile came third %d %s in the following %s:\n", countChi,
                countChi == 1 ? "time" : "times",
                countChi == 1 ? "year" : "years");
        for (i = 0; i < countChi; i++) {
            printf("%d\n", yearsChi[i]);
        }
        printf("\n");

        printf("Portugal came third %d %s in the following %s:\n", countPor,
                countPor == 1 ? "time" : "times",
                countPor == 1 ? "year" : "years");
        for (i = 0; i < countPor; i++) {
            printf("%d\n", yearsPor[i]);
        }
        printf("\n");

        printf("Poland came third %d %s in the following %s:\n", countPol,
                countPol == 1 ? "time" : "times",
                countPol == 1 ? "year" : "years");
        for (i = 0; i < countPol; i++) {
            printf("%d\n", yearsPol[i]);
        }
        printf("\n");

        printf("Croatia came third %d %s in the following %s:\n", countCro,
                countCro == 1 ? "time" : "times",
                countCro == 1 ? "year" : "years");
        for (i = 0; i < countCro; i++) {
            printf("%d\n", yearsCro[i]);
        }
        printf("\n");

        printf("Turkey came third %d %s in the following %s:\n", countTur,
                countTur == 1 ? "time" : "times",
                countTur == 1 ? "year" : "years");
        for (i = 0; i < countTur; i++) {
            printf("%d\n", yearsTur[i]);
        }
        printf("\n");

        printf("Netherlands came third %d %s in the following %s:\n", countNeth,
                countNeth == 1 ? "time" : "times",
                countNeth == 1 ? "year" : "years");
        for (i = 0; i < countNeth; i++) {
            printf("%d\n", yearsNeth[i]);
        }
        printf("\n");
    } else if (choice == 2) {
        if (strcmp(country, "USA") == 0) {
            printf("USA came third %d %s in the following %s:\n", countUSA,
                    countUSA == 1 ? "time" : "times",
                    countUSA == 1 ? "year" : "years");
            for (i = 0; i < countUSA; i++) {
                printf("%d\n", yearsUSA[i]);
            }
            printf("\n");
        } else if (strcmp(country, "Germany") == 0) {
            printf("Germany came third %d %s in the following %s:\n", countGer,
                    countGer == 1 ? "time" : "times",
                    countGer == 1 ? "year" : "years");
            for (i = 0; i < countGer; i++) {
                printf("%d\n", yearsGer[i]);
            }
            printf("\n");
        } else if (strcmp(country, "Brazil") == 0) {
            printf("Brazil came third %d %s in the following %s:\n", countBraz,
                    countBraz == 1 ? "time" : "times",
                    countBraz == 1 ? "year" : "years");
            for (i = 0; i < countBraz; i++) {
                printf("%d\n", yearsBraz[i]);
            }
            printf("\n");
        } else if (strcmp(country, "Sweden") == 0) {
            printf("Sweden came third %d %s in the following %s:\n", countSwe,
                    countSwe == 1 ? "time" : "times",
                    countSwe == 1 ? "year" : "years");
            for (i = 0; i < countSwe; i++) {
                printf("%d\n", yearsSwe[i]);
            }
            printf("\n");
        } else if (strcmp(country, "Austria") == 0) {
            printf("Austria came third %d %s in the following %s:\n", countAus,
                    countAus == 1 ? "time" : "times",
                    countAus == 1 ? "year" : "years");
            for (i = 0; i < countAus; i++) {
                printf("%d\n", yearsAus[i]);
            }
            printf("\n");
        } else if (strcmp(country, "France") == 0) {
            printf("France came third %d %s in the following %s:\n", countFra,
                    countFra == 1 ? "time" : "times",
                    countFra == 1 ? "year" : "years");
            for (i = 0; i < countFra; i++) {
                printf("%d\n", yearsFra[i]);
            }
            printf("\n");
        } else if (strcmp(country, "Chile") == 0) {
            printf("Chile came third %d %s in the following %s:\n", countChi,
                    countChi == 1 ? "time" : "times",
                    countChi == 1 ? "year" : "years");
            for (i = 0; i < countChi; i++) {
                printf("%d\n", yearsChi[i]);
            }
            printf("\n");
        } else if (strcmp(country, "Portugal") == 0) {
            printf("Portugal came third %d %s in the following %s:\n", countPor,
                    countPor == 1 ? "time" : "times",
                    countPor == 1 ? "year" : "years");
            for (i = 0; i < countPor; i++) {
                printf("%d\n", yearsPor[i]);
            }
            printf("\n");
        } else if (strcmp(country, "Poland") == 0) {
            printf("Poland came third %d %s in the following %s:\n", countPol,
                    countPol == 1 ? "time" : "times",
                    countPol == 1 ? "year" : "years");
            for (i = 0; i < countPol; i++) {
                printf("%d\n", yearsPol[i]);
            }
            printf("\n");
        } else if (strcmp(country, "Croatia") == 0) {
            printf("Croatia came third %d %s in the following %s:\n", countCro,
                    countCro == 1 ? "time" : "times",
                    countCro == 1 ? "year" : "years");
            for (i = 0; i < countCro; i++) {
                printf("%d\n", yearsCro[i]);
            }
            printf("\n");
        } else if (strcmp(country, "Turkey") == 0) {
            printf("Turkey came third %d %s in the following %s:\n", countTur,
                    countTur == 1 ? "time" : "times",
                    countTur == 1 ? "year" : "years");
            for (i = 0; i < countTur; i++) {
                printf("%d\n", yearsTur[i]);
            }
            printf("\n");
        } else if (strcmp(country, "Netherlands") == 0) {
            printf("Netherlands came third %d %s in the following %s:\n", countNeth,
                    countNeth == 1 ? "time" : "times",
                    countNeth == 1 ? "year" : "years");
            for (i = 0; i < countNeth; i++) {
                printf("%d\n", yearsNeth[i]);
            }
            printf("\n");
        }
    }
    return 0;
}

void printMenuThird() {
    printf("The countries that came third at least once are:\n");
    printf("USA, Germany, Brazil, Sweden, Austria, France, Chile,"
            " Portugal, Poland, Croatia, Turkey, Netherlands\n");
    printf("Please choose a country to display the number of times it placed "
            "third :\n");
}

int getFourth(int row, worldCup wCup[row], int choice, char *country) {
    if (!wCup || row <= 0 || !country) return -1;
    if (choice != 1 && choice != 2) return -2;
    if (strcmp(country, "Yugoslavia") != 0
            && strcmp(country, "Austria") != 0
            && strcmp(country, "Sweden") != 0
            && strcmp(country, "Spain") != 0
            && strcmp(country, "Uruguay") != 0
            && strcmp(country, "Germany") != 0
            && strcmp(country, "Germany FR") != 0
            && strcmp(country, "Soviet Union") != 0
            && strcmp(country, "Brazil") != 0
            && strcmp(country, "Italy") != 0
            && strcmp(country, "France") != 0
            && strcmp(country, "Belgium") != 0
            && strcmp(country, "England") != 0
            && strcmp(country, "Bulgaria") != 0
            && strcmp(country, "Netherlands") != 0
            && strcmp(country, "Korea Republic") != 0
            && strcmp(country, "Portugal") != 0
            && strcmp(country, "All") != 0) return -3;

    int countYugo = 0, countAus = 0, countSwe = 0, countSpa = 0, countUru = 0,
            countGer = 0, countSU = 0, countBraz = 0, countIta = 0,
            countFra = 0, countBelg = 0, countEng = 0, countBul = 0,
            countNeth = 0, countKR = 0, countPor = 0, yearsYugo[row],
            yearsAus[row], yearsSwe[row], yearsSpa[row], yearsUru[row],
            yearsGer[row], yearsSU[row], yearsBraz[row], yearsIta[row],
            yearsFra[row], yearsBelg[row], yearsEng[row], yearsBul[row],
            yearsNeth[row], yearsKR[row], yearsPor[row];

    yearsYugo[0] = 0;
    yearsAus[0] = 0;
    yearsSwe[0] = 0;
    yearsSpa[0] = 0;
    yearsUru[0] = 0;
    yearsGer[0] = 0;
    yearsSU[0] = 0;
    yearsBraz[0] = 0;
    yearsIta[0] = 0;
    yearsFra[0] = 0;
    yearsBelg[0] = 0;
    yearsEng[0] = 0;
    yearsBul[0] = 0;
    yearsNeth[0] = 0;
    yearsKR[0] = 0;
    yearsPor[0] = 0;

    int i;
    for (i = 0; i < row; i++) {
        char *temp = wCup[i].fourth;
        if (strcmp(temp, "Yugoslavia") == 0) {
            yearsYugo[countYugo] = wCup[i].year;
            countYugo++;
        } else if (strcmp(temp, "Austria") == 0) {
            yearsAus[countAus] = wCup[i].year;
            countAus++;
        } else if (strcmp(temp, "Sweden") == 0) {
            yearsSwe[countSwe] = wCup[i].year;
            countSwe++;
        } else if (strcmp(temp, "Spain") == 0) {
            yearsSpa[countSpa] = wCup[i].year;
            countSpa++;
        } else if (strcmp(temp, "Uruguay") == 0) {
            yearsUru[countUru] = wCup[i].year;
            countUru++;
        } else if (strcmp(temp, "Germany") == 0
                || strcmp(temp, "Germany FR") == 0) {
            yearsGer[countGer] = wCup[i].year;
            countGer++;
        } else if (strncmp(temp, "Soviet Union", 6) == 0) {
            yearsSU[countSU] = wCup[i].year;
            countSU++;
        } else if (strcmp(temp, "Brazil") == 0) {
            yearsBraz[countBraz] = wCup[i].year;
            countBraz++;
        } else if (strcmp(temp, "Italy") == 0) {
            yearsIta[countIta] = wCup[i].year;
            countIta++;
        } else if (strcmp(temp, "France") == 0) {
            yearsFra[countFra] = wCup[i].year;
            countFra++;
        } else if (strcmp(temp, "Belgium") == 0) {
            yearsBelg[countBelg] = wCup[i].year;
            countBelg++;
        } else if (strcmp(temp, "England") == 0) {
            yearsEng[countEng] = wCup[i].year;
            countEng++;
        } else if (strcmp(temp, "Bulgaria") == 0) {
            yearsBul[countBul] = wCup[i].year;
            countBul++;
        } else if (strcmp(temp, "Netherlands") == 0) {
            yearsNeth[countNeth] = wCup[i].year;
            countNeth++;
        } else if (strncmp(temp, "Korea Republic", 5) == 0) {
            yearsKR[countKR] = wCup[i].year;
            countKR++;
        } else if (strcmp(temp, "Portugal") == 0) {
            yearsPor[countPor] = wCup[i].year;
            countPor++;
        }
    }

    if (choice == 1) {
        printf("Number of times each country came fourth:\n");
        for (int i = 0; i < 40; i++) {
            printf("-");
        }
        printf("\n");

        printf("Yugoslavia came fourth %d %s the following %s:\n", countYugo,
                countYugo == 1 ? "time" : "times",
                countYugo == 1 ? "year" : "years");
        for (i = 0; i < countYugo; i++) {
            printf("%d\n", yearsYugo[i]);
        }
        printf("\n");

        printf("Austria came fourth %d %s the following %s:\n", countAus,
                countAus == 1 ? "time" : "times",
                countAus == 1 ? "year" : "years");
        for (i = 0; i < countAus; i++) {
            printf("%d\n", yearsAus[i]);
        }
        printf("\n");

        printf("Sweden came fourth %d %s the following %s:\n", countSwe,
                countSwe == 1 ? "time" : "times",
                countSwe == 1 ? "year" : "years");
        for (i = 0; i < countSwe; i++) {
            printf("%d\n", yearsSwe[i]);
        }
        printf("\n");

        printf("Spain came fourth %d %s the following %s:\n", countSpa,
                countSpa == 1 ? "time" : "times",
                countSpa == 1 ? "year" : "years");
        for (i = 0; i < countSpa; i++) {
            printf("%d\n", yearsSpa[i]);
        }
        printf("\n");

        printf("Uruguay came fourth %d %s the following %s:\n", countUru,
                countUru == 1 ? "time" : "times",
                countUru == 1 ? "year" : "years");
        for (i = 0; i < countUru; i++) {
            printf("%d\n", yearsUru[i]);
        }
        printf("\n");

        printf("Germany came fourth %d %s the following %s:\n", countGer,
                countGer == 1 ? "time" : "times",
                countGer == 1 ? "year" : "years");
        for (i = 0; i < countGer; i++) {
            printf("%d\n", yearsGer[i]);
        }
        printf("\n");

        printf("The Soviet Union came fourth %d %s the following %s:\n", countSU,
                countSU == 1 ? "time" : "times",
                countSU == 1 ? "year" : "years");
        for (i = 0; i < countSU; i++) {
            printf("%d\n", yearsSU[i]);
        }
        printf("\n");

        printf("Brazil came fourth %d %s the following %s:\n", countBraz,
                countBraz == 1 ? "time" : "times",
                countBraz == 1 ? "year" : "years");
        for (i = 0; i < countBraz; i++) {
            printf("%d\n", yearsBraz[i]);
        }
        printf("\n");

        printf("Italy came fourth %d %s the following %s:\n", countIta,
                countIta == 1 ? "time" : "times",
                countIta == 1 ? "year" : "years");
        for (i = 0; i < countIta; i++) {
            printf("%d\n", yearsIta[i]);
        }
        printf("\n");

        printf("France came fourth %d %s the following %s:\n", countFra,
                countFra == 1 ? "time" : "times",
                countFra == 1 ? "year" : "years");
        for (i = 0; i < countFra; i++) {
            printf("%d\n", yearsFra[i]);
        }
        printf("\n");

        printf("Belgium came fourth %d %s the following %s:\n", countBelg,
                countBelg == 1 ? "time" : "times",
                countBelg == 1 ? "year" : "years");
        for (i = 0; i < countBelg; i++) {
            printf("%d\n", yearsBelg[i]);
        }
        printf("\n");

        printf("England came fourth %d %s the following %s:\n", countEng,
                countEng == 1 ? "time" : "times",
                countEng == 1 ? "year" : "years");
        for (i = 0; i < countEng; i++) {
            printf("%d\n", yearsEng[i]);
        }
        printf("\n");

        printf("Bulgaria came fourth %d %s the following %s:\n", countBul,
                countBul == 1 ? "time" : "times",
                countBul == 1 ? "year" : "years");
        for (i = 0; i < countBul; i++) {
            printf("%d\n", yearsBul[i]);
        }
        printf("\n");

        printf("Netherlands came fourth %d %s the following %s:\n", countNeth,
                countNeth == 1 ? "time" : "times",
                countNeth == 1 ? "year" : "years");
        for (i = 0; i < countNeth; i++) {
            printf("%d\n", yearsNeth[i]);
        }
        printf("\n");

        printf("The Korean Republic came fourth %d %s the following %s:\n",
                countKR, countKR == 1 ? "time" : "times",
                countKR == 1 ? "year" : "years");
        for (i = 0; i < countKR; i++) {
            printf("%d\n", yearsKR[i]);
        }
        printf("\n");

        printf("Portugal came fourth %d %s the following %s:\n", countPor,
                countPor == 1 ? "time" : "times",
                countPor == 1 ? "year" : "years");
        for (i = 0; i < countPor; i++) {
            printf("%d\n", yearsPor[i]);
        }
        printf("\n");

    } else if (choice == 2) {
        if (strcmp(country, "Yugoslavia") == 0) {
            printf("Yugoslavia came fourth %d %s the following %s:\n", countYugo,
                    countYugo == 1 ? "time" : "times",
                    countYugo == 1 ? "year" : "years");
            for (i = 0; i < countYugo; i++) {
                printf("%d\n", yearsYugo[i]);
            }
            printf("\n");
        } else if (strcmp(country, "Austria") == 0) {
            printf("Austria came fourth %d %s the following %s:\n", countAus,
                    countAus == 1 ? "time" : "times",
                    countAus == 1 ? "year" : "years");
            for (i = 0; i < countAus; i++) {
                printf("%d\n", yearsAus[i]);
            }
            printf("\n");
        } else if (strcmp(country, "Sweden") == 0) {
            printf("Sweden came fourth %d %s the following %s:\n", countSwe,
                    countSwe == 1 ? "time" : "times",
                    countSwe == 1 ? "year" : "years");
            for (i = 0; i < countSwe; i++) {
                printf("%d\n", yearsSwe[i]);
            }
            printf("\n");
        } else if (strcmp(country, "Spain") == 0) {
            printf("Spain came fourth %d %s the following %s:\n", countSpa,
                    countSpa == 1 ? "time" : "times",
                    countSpa == 1 ? "year" : "years");
            for (i = 0; i < countSpa; i++) {
                printf("%d\n", yearsSpa[i]);
            }
            printf("\n");
        } else if (strcmp(country, "Uruguay") == 0) {
            printf("Uruguay came fourth %d %s the following %s:\n", countUru,
                    countUru == 1 ? "time" : "times",
                    countUru == 1 ? "year" : "years");
            for (i = 0; i < countUru; i++) {
                printf("%d\n", yearsUru[i]);
            }
            printf("\n");
        } else if (strcmp(country, "Germany") == 0) {
            printf("Germany came fourth %d %s the following %s:\n", countGer,
                    countGer == 1 ? "time" : "times",
                    countGer == 1 ? "year" : "years");
            for (i = 0; i < countGer; i++) {
                printf("%d\n", yearsGer[i]);
            }
            printf("\n");
        } else if (strcmp(country, "Soviet Union") == 0) {
            printf("The Soviet Union came fourth %d %s the following %s:\n",
                    countSU, countSU == 1 ? "time" : "times",
                    countSU == 1 ? "year" : "years");
            for (i = 0; i < countSU; i++) {
                printf("%d\n", yearsSU[i]);
            }
            printf("\n");
        } else if (strcmp(country, "Brazil") == 0) {
            printf("Brazil came fourth %d %s the following %s:\n", countBraz,
                    countBraz == 1 ? "time" : "times",
                    countBraz == 1 ? "year" : "years");
            for (i = 0; i < countBraz; i++) {
                printf("%d\n", yearsBraz[i]);
            }
            printf("\n");
        } else if (strcmp(country, "Italy") == 0) {
            printf("Italy came fourth %d %s the following %s:\n", countIta,
                    countIta == 1 ? "time" : "times",
                    countIta == 1 ? "year" : "years");
            for (i = 0; i < countIta; i++) {
                printf("%d\n", yearsIta[i]);
            }
            printf("\n");
        } else if (strcmp(country, "France") == 0) {
            printf("France came fourth %d %s the following %s:\n", countFra,
                    countFra == 1 ? "time" : "times",
                    countFra == 1 ? "year" : "years");
            for (i = 0; i < countFra; i++) {
                printf("%d\n", yearsFra[i]);
            }
            printf("\n");
        } else if (strcmp(country, "Belgium") == 0) {
            printf("Belgium came fourth %d %s the following %s:\n", countBelg,
                    countBelg == 1 ? "time" : "times",
                    countBelg == 1 ? "year" : "years");
            for (i = 0; i < countBelg; i++) {
                printf("%d\n", yearsBelg[i]);
            }
            printf("\n");
        } else if (strcmp(country, "England") == 0) {
            printf("England came fourth %d %s the following %s:\n", countEng,
                    countEng == 1 ? "time" : "times",
                    countEng == 1 ? "year" : "years");
            for (i = 0; i < countEng; i++) {
                printf("%d\n", yearsEng[i]);
            }
            printf("\n");
        } else if (strcmp(country, "Bulgaria") == 0) {
            printf("Bulgaria came fourth %d %s the following %s:\n", countBul,
                    countBul == 1 ? "time" : "times",
                    countBul == 1 ? "year" : "years");
            for (i = 0; i < countBul; i++) {
                printf("%d\n", yearsBul[i]);
            }
            printf("\n");
        } else if (strcmp(country, "Netherlands") == 0) {
            printf("Netherlands came fourth %d %s the following %s:\n",
                    countNeth, countNeth == 1 ? "time" : "times",
                    countNeth == 1 ? "year" : "years");
            for (i = 0; i < countNeth; i++) {
                printf("%d\n", yearsNeth[i]);
            }
            printf("\n");
        } else if (strcmp(country, "Korea Republic") == 0) {
            printf("The Korean Republic came fourth %d %s the following %s:\n",
                    countKR, countKR == 1 ? "time" : "times",
                    countKR == 1 ? "year" : "years");
            for (i = 0; i < countKR; i++) {
                printf("%d\n", yearsKR[i]);
            }
            printf("\n");
        } else if (strcmp(country, "Portugal") == 0) {
            printf("Portugal came fourth %d %s the following %s:\n", countPor,
                    countPor == 1 ? "time" : "times",
                    countPor == 1 ? "year" : "years");
            for (i = 0; i < countPor; i++) {
                printf("%d\n", yearsPor[i]);
            }
            printf("\n");
        }
    }

    return 0;
}

void printMenuFourth() {
    printf("The countries that came fourth at least once are:\n");
    printf("Yugoslavia, Austria, Sweden, Spain, Uruguay, Germany, Soviet Union,"
            " Brazil, Italy, France, Belgium, England, Bulgaria, Netherlands,"
            " Korea Republic, Portugal\n");
    printf("Please choose a country to display the number of times it placed "
            "fourth :\n");
}

int getGoalsMaximums(int row, worldCup wCup[row]) {
    if (!wCup || row <= 0) return -1;

    int max = wCup[0].goalsScored;
    int i;
    for (i = 1; i < row; i++) {
        if (wCup[i].goalsScored > max) {
            max = wCup[i].goalsScored;
        }
    }

    int years[row];
    years[0] = 0;

    int j = 0;
    for (i = 0; i < row; i++) {
        if (wCup[i].goalsScored == max) {
            years[j] = wCup[i].year;
            j++;
        }
    }

    printf("The maximum number of goals, which is %d, was scored in the "
            "following year(s):\n", max);
    for (i = 0; i < j; i++) {
        printf("%d\n", years[i]);
    }

    return 0;
}

int getGoalsMinimums(int row, worldCup wCup[row]) {
    if (!wCup || row <= 0) return -1;

    int i;
    int min = wCup[0].goalsScored;
    for (i = 1; i < row; i++) {
        if (wCup[i].goalsScored < min) {
            min = wCup[i].goalsScored;
        }
    }

    int years[row];
    years[0] = 0;

    int j = 0;
    for (i = 0; i < row; i++) {
        if (wCup[i].goalsScored == min) {
            years[j] = wCup[i].year;
            j++;
        }
    }

    printf("The minimum number of goals, which is %d, was scored in the "
            "following year(s):\n", min);
    for (i = 0; i < j; i++) {
        printf("%d\n", years[i]);
    }

    return 0;
}

int getGoalsAverage(int row, worldCup wCup[row]) {
    if (!wCup || row <= 0) return -1;

    double avg;
    int i, sum = 0;
    for (i = 0; i < row; i++) {
        sum += wCup[i].goalsScored;
    }
    avg = (float) sum / row;

    printf("The average of goals scored throughout the years is %f\n", avg);

    return 0;
}

int getYearsQualifiedTeams(int row, worldCup wCup[row], int choice, int num) {
    if (!wCup || row <= 0) return -1;
    if (choice != 1 && choice != 2) return -2;
    if (num != 13 && num != 15 && num != 16
            && num != 24 && num != 32 && num != 0) return -3;

    int years13[row], years15[row], years16[row], years24[row], years32[row],
            j13 = 0, j15 = 0, j16 = 0, j24 = 0, j32 = 0;

    years13[0] = 0;
    years15[0] = 0;
    years16[0] = 0;
    years24[0] = 0;
    years32[0] = 0;

    int i;
    for (i = 0; i < row; i++) {
        if (wCup[i].qualifiedTeams == 13) {
            years13[j13] = wCup[i].year;
            j13++;
        } else if (wCup[i].qualifiedTeams == 15) {
            years15[j15] = wCup[i].year;
            j15++;
        } else if (wCup[i].qualifiedTeams == 16) {
            years16[j16] = wCup[i].year;
            j16++;
        } else if (wCup[i].qualifiedTeams == 24) {
            years24[j24] = wCup[i].year;
            j24++;
        } else if (wCup[i].qualifiedTeams == 32) {
            years32[j32] = wCup[i].year;
            j32++;
        }
    }

    if (choice == 1) {
        printf("\n13 qualified teams were in the world cup %d %s in the "
                "following %s: \n", j13, j13 == 1 ? "time" : "times",
                j13 == 1 ? "year" : "years");
        for (i = 0; i < j13; i++) {
            printf("%d\n", years13[i]);
            if (years13[i] == 0) {
                break;
            }
        }
        printf("\n15 qualified teams were in the world cup %d %s in the "
                "following %s: \n", j15, j15 == 1 ? "time" : "times",
                j15 == 1 ? "year" : "years");
        for (i = 0; i < j15; i++) {
            printf("%d\n", years15[i]);
            if (years15[i] == 0) {
                break;
            }
        }
        printf("\n16 qualified teams were in the world cup %d %s in the "
                "following %s: \n", j16, j16 == 1 ? "time" : "times",
                j16 == 1 ? "year" : "years");
        for (i = 0; i < j16; i++) {
            printf("%d\n", years16[i]);
            if (years16[i] == 0) {
                break;
            }
        }
        printf("\n24 qualified teams were in the world cup %d %s in the "
                "following %s: \n", j24, j24 == 1 ? "time" : "times",
                j24 == 1 ? "year" : "years");
        for (i = 0; i < j24; i++) {
            printf("%d\n", years24[i]);
            if (years24[i] == 0) {
                break;
            }
        }
        printf("\n32 qualified teams were in the world cup %d %s in the "
                "following %s: \n", j32, j32 == 1 ? "time" : "times",
                j32 == 1 ? "year" : "years");
        for (i = 0; i < j32; i++) {
            printf("%d\n", years32[i]);
            if (years32[i] == 0) {
                break;
            }
        }
    } else if (choice == 2) {
        if (num == 13) {
            printf("\n13 qualified teams were in the world cup %d %s in the "
                    "following %s: \n", j13, j13 == 1 ? "time" : "times",
                    j13 == 1 ? "year" : "years");
            for (i = 0; i < j13; i++) {
                printf("%d\n", years13[i]);
                if (years13[i] == 0) {
                    break;
                }
            }
        } else if (num == 15) {
            printf("\n15 qualified teams were in the world cup %d %s in the "
                    "following %s: \n", j15, j15 == 1 ? "time" : "times",
                    j15 == 1 ? "year" : "years");
            for (i = 0; i < j15; i++) {
                printf("%d\n", years15[i]);
                if (years15[i] == 0) {
                    break;
                }
            }
        } else if (num == 16) {
            printf("\n16 qualified teams were in the world cup %d %s in the "
                    "following %s: \n", j16, j16 == 1 ? "time" : "times",
                    j16 == 1 ? "year" : "years");
            for (i = 0; i < j16; i++) {
                printf("%d\n", years16[i]);
                if (years16[i] == 0) {
                    break;
                }
            }
        } else if (num == 24) {
            printf("\n24 qualified teams were in the world cup %d %s in the "
                    "following %s: \n", j24, j24 == 1 ? "time" : "times",
                    j24 == 1 ? "year" : "years");
            for (i = 0; i < j24; i++) {
                printf("%d\n", years24[i]);
                if (years24[i] == 0) {
                    break;
                }
            }
        } else if (num == 32) {
            printf("\n32 qualified teams were in the world cup %d %s in the "
                    "following %s: \n", j32, j32 == 1 ? "time" : "times",
                    j32 == 1 ? "year" : "years");
            for (i = 0; i < j32; i++) {
                printf("%d\n", years32[i]);
                if (years32[i] == 0) {
                    break;
                }
            }
        }
    }

    printf("\n");

    return 0;
}

void printMenuQualifiedTeams() {
    printf("The number of qualified teams for the world cups throughout the "
            "years are:\n");
    printf("13, 15, 16, 24, 32\n");
    printf("Please choose a number to display the years according to that "
            "number:\n");
}

int getAttendancesMaximums(int row, worldCup wCup[row]) {
    if (!wCup || row <= 0) return -1;

    int i;
    int max = wCup[0].attendance;
    for (i = 1; i < row; i++) {
        if (wCup[i].attendance > max) {
            max = wCup[i].attendance;
        }
    }

    int years[row];
    years[0] = 0;

    int j = 0;
    for (i = 0; i < row; i++) {
        if (wCup[i].attendance == max) {
            years[j] = wCup[i].year;
            j++;
        }
    }

    printf("The maximum number of attendees, which was %d, was scored in the "
            "following year(s):\n", max);
    for (i = 0; i < j; i++) {
        printf("%d\n", years[i]);
    }

    return 0;
}

int getAttendancesMinimums(int row, worldCup wCup[row]) {
    if (!wCup || row <= 0) return -1;

    int i;
    int min = wCup[0].attendance;
    for (i = 1; i < row; i++) {
        if (wCup[i].attendance < min) {
            min = wCup[i].attendance;
        }
    }

    int years[row];
    years[0] = 0;

    int j = 0;
    for (i = 0; i < row; i++) {
        if (wCup[i].attendance == min) {
            years[j] = wCup[i].year;
            j++;
        }
    }

    printf("The minimum number of attendees, which is %d, was scored in the "
            "following year(s):\n", min);
    for (i = 0; i < j; i++) {
        printf("%d\n", years[i]);
    }

    return 0;
}

int getAttendancesAverage(int row, worldCup wCup[row]) {
    if (!wCup || row <= 0) return -1;

    int i, sum = 0;
    for (i = 0; i < row; i++) {
        sum += wCup[i].attendance;
    }
    float avg = (float) sum / row;

    printf("The average of goals scored throughout the years is %f\n", avg);

    return 0;
}
