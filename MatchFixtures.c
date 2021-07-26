#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#include<time.h>

int teams[20] = {10,20,30,40,50,60,70,80,90,100,110,120,130,140,150,160,170,180,190,200},byeTeams[16],firstGlobalArr[10],secondGlobalArr[10],groupStageIwin[16];

void shuffle(int* array, size_t n)
{
    if (n > 1)
    {
        size_t i;
        srand(time(NULL));
        for (i = 0; i < n - 1; i++)
        {
            size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
            int t = array[j];
            array[j] = array[i];
            array[i] = t;
        }
    }
}



void group_fixtures(int* array, size_t n) {
    if (n > 1) {
        int *firstHalf = malloc((n/2) * sizeof(int));
        memcpy(firstHalf, array, (n / 2) * sizeof(int));
        int* secondHalf = malloc((n / 2) * sizeof(int));
        memcpy(secondHalf, array+(n/2), (n / 2) * sizeof(int));
        
        
        
        memcpy(firstGlobalArr,firstHalf, (n / 2) * sizeof(int));
        memcpy(secondGlobalArr, secondHalf, (n / 2) * sizeof(int));

        /*for (int i = 0;i < 10;i=i++) {
            printf("\nGame %d : \t %d \t vs \t %d",i+1, firstHalf[i], secondHalf[i]);
        }*/


    }

}


int main() {
    /*for (int i = 0;i < 20;i++) {
        scanf_s("%d", &teams[i]);
    }*/

    /*printf(teams);*/



    //Group - I playoffs
    shuffle(teams, 20);
    memcpy(byeTeams, teams + 8, 12);
    printf("There are 20 teams in total and every match is a knockout match therefore 8 ransom teams first compete to get into the top 16!\n");
    printf("Those 8 teams are:");
    for (int i = 0;i < 8;i++) {
        printf("\nTeam:%d ", teams[i]);
    }



    group_fixtures(teams, 8);
    printf("\n\t\t\t\t\tGroup Stage - I\n");
    for (int i = 0;i < 4;i++) {
        printf("\n\t\t\tGame %d : \t %d \t vs \t %d", i + 1, firstGlobalArr[i], secondGlobalArr[i]);
    }


    //Winner of Group Playoffs - I
    for (int i = 0; i < 4; i++) {
        printf("\n\t\t\t\tEnter the winner of Game %d of Group Match - I\t\t", i + 1);
        scanf("%d", &groupStageIwin[i]);
        while (!(firstGlobalArr[i] == groupStageIwin[i] || secondGlobalArr[i] == groupStageIwin[i])) {
            printf("\n\t\tEnter the team which played in Game %d\t\t", i + 1);
            scanf("%d", &groupStageIwin[i]);
        }
    }
    printf("---------------------------------------------------------------------------------------");
    //Concat bye-teams and winner teams
    int index1 = 5, index2 = 9;
    while (index1 <= 16) {
        groupStageIwin[index1] = teams[index2];
        index1++;
        index2++;
    }

    /*for (int i = 0; i < 16; i++) {
        printf("\n\t\t%d", groupStageIwin[i]);
    }*/
    //Group Second Playoffs
    shuffle(groupStageIwin, 16);
    group_fixtures(groupStageIwin, 16);
    printf("\n\t\t\t\t\tGroup Stage - II\n");
    for (int i = 0;i < 8;i++) {
        printf("\n\t\t\tGame %d : \t %d \t vs \t %d", i + 1, firstGlobalArr[i], secondGlobalArr[i]);
    }

    //Winner of Group Playoffs - II
    for (int i = 0; i < 8; i++) {
        printf("\n\t\t\t\tEnter the winner of Game %d of Group Match - II\t\t", i + 1);
        scanf("%d", &groupStageIwin[i]);
        while (!(firstGlobalArr[i] == groupStageIwin[i] || secondGlobalArr[i] == groupStageIwin[i])) {
            printf("\n\t\tEnter the team which played in Game %d\t\t", i + 1);
            scanf("%d", &groupStageIwin[i]);
        }
    }

    printf("---------------------------------------------------------------------------------------");


    //Quarter Finals
    shuffle(groupStageIwin, 8);
    group_fixtures(groupStageIwin, 8);
    printf("\n\t\t\t\t\tQuarter Finals\n");
    for (int i = 0;i < 4;i++) {
        printf("\n\t\t\tGame %d : \t %d \t vs \t %d", i + 1, firstGlobalArr[i], secondGlobalArr[i]);
    }

    //Winner of Quarter Finals
    for (int i = 0; i < 4; i++) {
        printf("\n\t\t\t\tEnter the winner of Game %d of Quarter Finals\t\t", i + 1);
        scanf("%d", &groupStageIwin[i]);
        while (!(firstGlobalArr[i] == groupStageIwin[i] || secondGlobalArr[i] == groupStageIwin[i])) {
            printf("\n\t\tEnter the team which played in Game %d\t\t", i + 1);
            scanf("%d", &groupStageIwin[i]);
        }
    }

    printf("---------------------------------------------------------------------------------------\n");
    
    //Semi Finals

    printf("\n\t\t\t-----THE SEMI FINALS-----");
    shuffle(groupStageIwin, 4);
    group_fixtures(groupStageIwin, 4);
    printf("\n\t\t\t\t\tSemi Finals\n");
    for (int i = 0;i < 2;i++) {
        printf("\n\t\t\tGame %d : \t %d \t vs \t %d", i + 1, firstGlobalArr[i], secondGlobalArr[i]);
    }
    //Winner of Semi Finals
    int Thirdpos[2] = {0,1};
    for (int i = 0; i < 2; i++) {
        printf("\n\t\t\t\tEnter the winner of the Game %d!\t\t",i+1);
        scanf("%d", &groupStageIwin[i]);
        while (!(firstGlobalArr[i] == groupStageIwin[i] || secondGlobalArr[i] == groupStageIwin[i])) {
            printf("\n\t\tEnter the team which played in Game %d\t\t", i + 1);
            scanf("%d", &groupStageIwin[i]);
        }
        if ((firstGlobalArr[i] == groupStageIwin[i])) {
            Thirdpos[i] = secondGlobalArr[i];
        }
        else {
            Thirdpos[i] = firstGlobalArr[i];
        }
    }

    printf("---------------------------------------------------------------------------------------\n");

    //Third Position
    printf("\n\t\t\t-----Competation for Third Position-----");
    shuffle(Thirdpos, 2);
    group_fixtures(Thirdpos, 2);
    for (int i = 0;i < 1;i++) {
        printf("\n\t\t\tGame %d : \t %d \t vs \t %d", i + 1, firstGlobalArr[i], secondGlobalArr[i]);
    }
    //Third and 4th position
    printf("\n\t\t\t\tEnter the winner of the Game\t\t");
    scanf("%d", &groupStageIwin[2]);
    while (!(firstGlobalArr[0] == Thirdpos[0] || secondGlobalArr[0] == Thirdpos[1])) {
        printf("\n\t\tEnter the team which played in Game");
        scanf("%d", &groupStageIwin[2]);
    }
    if (groupStageIwin[2] == Thirdpos[0]) {
        groupStageIwin[3] = secondGlobalArr[0];
    }
    else {
        groupStageIwin[3] = firstGlobalArr[0];
    }
    
    printf("---------------------------------------------------------------------------------------\n");

    //Grand Finalae
    printf("\n\t\t\t-----GRAND FINALAE-----");
    shuffle(groupStageIwin, 2);
    group_fixtures(groupStageIwin, 2);
    for (int i = 0;i < 1;i++) {
        printf("\n\t\t\tGame %d : \t %d \t vs \t %d", i + 1, firstGlobalArr[i], secondGlobalArr[i]);
    }
    //Winner of Grand Finalae
    for (int i = 0; i < 1; i++) {
        printf("\n\t\t\t\tEnter the winner of Game %d of Group Match - I\t\t", i + 1);
        scanf("%d", &groupStageIwin[i]);
        while (!(firstGlobalArr[i] == groupStageIwin[i] || secondGlobalArr[i] == groupStageIwin[i])) {
            printf("\n\t\tEnter the team which played in Game %d\t\t", i + 1);
            scanf("%d", &groupStageIwin[i]);
        }
        if (firstGlobalArr[i] == groupStageIwin[i]) {
            groupStageIwin[i + 1] = secondGlobalArr[i];
        }
        else {
            groupStageIwin[i + 1] = firstGlobalArr[i];
        }
    }
    printf("---------------------------------------------------------------------------------------\n");
    printf("---------------------------------------------------------------------------------------\n");
    printf("\n\t\t------PRESENTING YOU THE WINNERS------\n\n");
    for (int i = 0; i < 4;i++) {
        printf("\t\t----------Position: %d, Team number : %d--------------\n",i+1,groupStageIwin[i]);
    }
    return 0;
}
