# include <stdio.h>
#include <stdlib.h>
# include <stdbool.h>
# include <string.h>
# include <windows.h>

// declaration of team name and the team batting
char fteam[50], steam[50], batting[50], bowling[50];

// storing the overs and batsmen on strike
int overs, striker[]={1,2};  

// a long message to be sent 
char prereq[1000] = "Enter the output of the ball:\n[0] 0 run\n[1] 1 run\n[2] 2 runs\n[3] 3 runs\n[4] FOUR!\n[5] SIX!\n[6] Wicket\n";

// storing data of each over of the team in 1 and 2
struct all_overs1 
{
    int over_1[12];
}over1[90];

struct all_overs2 
{
    int over_2[12];
}over2[90];

// info on team 1 of the innning 1
struct team1
{
    int runs, six, fours, balls_played;
    float s_rate;
}; 

// making all values of the team 0
struct team1 players1[12] = { 0 };

// info on team 2 of the innning 2
struct team2
{
    int runs, six, fours, balls_played;
    float s_rate;
};

// making all values of the team 0
struct team2 players2[12] = { 0 };

// change striker 
void change_striker()
{
    int s = striker[0];
    striker[0] = striker[1];
    striker[1] = s;
}

// setting the strikers back to { 1 , 2}
void reset_striker()
{
    striker[0] = 1;
    striker[1] = 2;
}

// swap the team for batting and bowling
void swap_team_name()
{
    char temp[25];
    strcpy(temp, bowling);
    strcpy(bowling, batting);
    strcpy(batting, temp);
    printf("Swaping sides\n");
    for(int i = 1; i<5; i++)
    {
        printf(".");
        Sleep(1000);
        printf("..");
        Sleep(1000);
        printf("...");
        Sleep(1000);
    }
    printf("\nSwaped Sides for inning 2\n");
}

// Enter New Bastmen
int batsmen = 3;
void new_batsmen()
{
    striker[0] = batsmen;
    batsmen++;
}

// Function Declaration 
int first_inning(); 
int second_inning(); 
void ask_ques();
void batsmen_info();
void overs_info();
void inning_info();

// data on inning 1
struct inning1 
{
        int target, no_balls, wickets, fours, sixes, total_runs;
        char team_name[50];
}i1;

// data on inning 2
struct inning2 
{
        int target, no_balls, wickets, fours, sixes, total_runs;
        char team_name[50];
}i2;

// Adding runs to each batsmen playing and also adding balls played 
// adding total runs of the team aswell as the innning 1
void add_runs1(int run)
{
    i1.total_runs = i1.total_runs + run;
    players1[striker[0]-1].runs += run;
    players1[striker[0]-1].balls_played += 1;
}

// Adding runs to each batsmen playing and also adding balls played 
// adding total runs of the team aswell as the innning 2
void add_runs2(int run)
{
    i2.total_runs = i2.total_runs + run;
    players2[striker[0]-1].runs += run;
    players2[striker[0]-1].balls_played += 1;
}

// Storing Each ball of the over of inning 1
void update_overs1(int pos, int value, int over_ball)
{
    over1[pos].over_1[over_ball] = value;
}

// Storing Each ball of the over of inning 1
void update_overs2(int pos, int value, int over_ball)
{
    over2[pos].over_2[over_ball] = value;
}

// main start of the program
int main() 
{
    // Stage I
    int i;
    printf("Enter the name of the first team: ");
    gets(fteam);
    printf("Enter the name of the second team: ");
    gets(steam);

    printf("Enter No. of overs in the innings: ");
    scanf("%d", &overs);

    system("cls");
    int ans;
    printf("Which Team is batting?\n(Enter no. of team)\n[1]%s\n[2]%s\n",fteam, steam);
    scanf("%d", &ans);


    if (ans==1){
        strcpy(batting, fteam);
        strcpy(bowling, steam);
    }else{
        strcpy(batting, steam);
        strcpy(bowling, fteam);
    }
    for(i=3; i>=0; i--){
        printf("Starting Inning 1 in %d seconds...\r", i);
        Sleep(1000);
    }
    Sleep(500);
    system("cls");
    // Stage II
    first_inning();

    // Stage III
    second_inning();
    
    // Stage IV
    ask_ques();

    return 0;
}

// Start of the first innning
int first_inning()
{
    int i, m, n;
    int over_ball = 0;

    for(i=0; i<overs; i++)
    {
        for(m=0; m<6; m++)
        {
            if (i1.wickets==10)
            {
                printf("ALL batsmen are out!\n");
                break;
            }
            printf("Enter the previous ball info:\n[1] Valid Ball\n[2] Wide ball/No ball\n");
            scanf("%d", &n);
            if (n == 1)
            {
                printf("%s", prereq);
                printf("\tBastmen%d on Strike\n\tRun - %d | score - %d-%d\n\tCurrent Over - %d.%d\n", striker[0], players1[striker[0]-1].runs, i1.total_runs, i1.wickets, i,m);
                int ans;
                scanf("%d", &ans);

                switch (ans)
                {
                    case 0:
                        update_overs1(i, 101, over_ball);
                        add_runs1(0);
                        break;
                    case 1:
                        update_overs1(i, 1, over_ball);
                        add_runs1(1);
                        change_striker();
                        break;
                    case 2:
                        update_overs1(i, 2, over_ball);
                        add_runs1(2);
                        break;
                    case 3:
                        update_overs1(i, 3, over_ball);
                        add_runs1(3);
                        change_striker();
                        break;
                    case 4:
                        update_overs1(i, 4, over_ball);
                        add_runs1(4);
                        players1[striker[0]-1].fours+=1;
                        i1.fours += 1;
                        break;
                    case 5:
                        update_overs1(i, 6, over_ball);
                        add_runs1(6);
                        players1[striker[0]-1].six+=1;
                        i1.sixes+=1;
                        break;
                    case 6:
                        update_overs1(i, 69, over_ball);
                        i1.wickets+=1;
                        add_runs1(0);
                        new_batsmen();
                        break;
                    default:
                        break;
                }
            }
            else
            {
                m = m-1;
                i1.total_runs+=1;
                i1.no_balls+=1;
                update_overs1(i, 96, over_ball);
                printf("Invalid ball +1 run\n"); 
            }
        
            over_ball++;
        }
    printf("Over completed\nRemaining overs %d\n\tChanging Sides\n", (overs-(i+1)));
    change_striker();
    }
    
    // End of first Innings 
    
    strcpy(i1.team_name, batting);
    i1.target = i1.total_runs+1; 
    printf("Run scored by the %s in the first inning is %d\nTarget to %s is %d\n", batting, i1.total_runs, bowling, i1.target);
    swap_team_name(); 
    reset_striker();
    batsmen = 3;
    return 0;
}

// Start of the second innning
int second_inning()
{
    int i, m, n;
    int over_ball = 0;
    strcpy(i2.team_name, batting);
    for(i=0; i<overs; i++){
        for(m=0; m<6; m++){
            if (i2.wickets==10){
                printf("ALL batsmen are out!\n");
                break;
            }
            if (i2.total_runs >= i1.target){
                printf("%s won the match\n", batting);
                break;
            }
            
            printf("Enter the previous ball info:\n[1] Valid Ball\n[2] Wide ball/No ball\n");
            scanf("%d", &n);
            if (n == 1){
                printf("%s", prereq);
                printf("\tBastmen%d on Strike\n\tRun - %d | Score - %d-%d\n\tCurrent Over - %d.%d\n", striker[0], players2[striker[0]-1].runs,i2.total_runs, i2.wickets, i,m);
                int ans;
                scanf("%d", &ans);

                switch (ans){
                    case 0:
                        add_runs2(0);
                        update_overs2(i, 101, over_ball);
                        break;
                    case 1:
                        add_runs2(1);
                        change_striker();
                        update_overs2(i, 1, over_ball);
                        break;
                    case 2:
                        add_runs2(2);
                        update_overs2(i, 2, over_ball);
                        break;
                    case 3:
                        add_runs2(3);
                        change_striker();
                        update_overs2(i, 3, over_ball);
                        break;
                    case 4:
                        add_runs2(4);
                        players2[striker[0]-1].fours+=1;
                        update_overs2(i, 4, over_ball);
                        i2.fours+=1;
                        break;
                    case 5:
                        add_runs2(6);
                        players2[striker[0]-1].six+=1;
                        update_overs2(i, 6, over_ball);
                        i2.sixes+=1;
                        break;
                    case 6:
                        i2.wickets+=1;
                        add_runs2(0);
                        update_overs2(i, 69, over_ball);
                        new_batsmen();
                        break;
                    default:
                        break;}
            }else{
                m = m-1;
                i2.total_runs+=1;
                i2.no_balls+=1;
                update_overs2(i, 96, over_ball);
                printf("Invalid ball +1 run\n");
                }
            over_ball++;
            }

    printf("Over completed\nRemaining overs %d\n", (overs-(i+1)));
    // change_striker();
    }
    

    
    // End of second Innings
    if (i2.total_runs>= i1.target){
        printf("\n%s won the match against %s by %d wickets\n", batting, bowling, 10-i2.wickets);
    }else if (i2.total_runs == i1.target){
        printf("\nThe match is a Draw between %s and %s\n", batting, bowling);
    }else{
        printf("%s lost the match to %s by %d runs\n", batting, bowling, i1.target-i2.total_runs);
    }
    return 0;
}

// start of the question and answers
void ask_ques()
{
    char ques[200] = "\n\t[1] - Batsmen Info\n\t[2] - Over Info\n\t[3] - Innning Information\n\t[4] - Exit\n\n";
    int ans;
    printf("%s Enter Your Choice\n", ques);
    scanf("%d", &ans);

    if (ans == 1){
        batsmen_info();
    }
    else if (ans == 2){
        overs_info();
    }
    else if (ans == 3) {
        inning_info();
    }
    else if (ans == 4){
        printf("\nTaking a Leave...\n");
    }
    else{
        printf("Wrong choice select from 1-4 only!");
        system("cls");
        ask_ques();
    }

}

// shows batsmen details of each team of the inning 1 and 2
void batsmen_info()
{
    // bastmen info
    printf("Which Team batsmen info would you like to have?\n[1] - %s\n[2] - %s\n", i1.team_name, i2.team_name);
    int ans = 0; 
    scanf("%d", &ans);
    if (ans == 1){
        printf("========================================================================================================\n");
        printf("|      Batsman Name    |     Runs    |    Balls Played    |    Fours   |    Six    |    Strike Rate    |\n");
        printf("========================================================================================================\n");
        for (int i = 0; i<12; i++){
            
            int run = players1[i].runs;
            int ball_played = players1[i].balls_played;
            int fours = players1[i].fours;
            int six = players1[i].six;
            float strike_rate = (run*100.00/ball_played);
            if (ball_played > 0){
                printf("|       batsman%-2d              %-18d%-16d%-12d%-14d%-6.2lf      |\n"
                
                , (i+1), run, ball_played, fours, six, strike_rate);
            }
        }
        ask_ques();
    }
    else if (ans == 2){
        printf("========================================================================================================\n");
        printf("|      Batsman Name    |     Runs    |    Balls Played    |    Fours   |    Six    |    Strike Rate    |\n");
        printf("========================================================================================================\n");
        for (int i = 0; i<12; i++){
            int run = players2[i].runs;
            int ball_played = players2[i].balls_played;
            int fours = players2[i].fours;
            int six = players2[i].six;
            float strike_rate = (run*100.00/ball_played);
            if (ball_played > 0){
                printf("|       batsman%-2d              %-18d%-16d%-12d%-14d%-6.2lf      |\n", (i+1), run, ball_played, fours, six, strike_rate);
            }
        }
        ask_ques();

    }else{
        printf("Wrong Input\n");
        Sleep(2000);
        system("cls");
        ask_ques();
    }

}

// shows over details of the team inning 1 and 2
void overs_info()
{
    // Bowling overs info
    printf("Which Team overs info would you like to have?\n[1] - %s\n[2] - %s\n", i1.team_name, i2.team_name);
    int ans = 0;
    scanf("%d", &ans);

    if (ans == 1){
        // overs for inning 1
        printf("Over for %s team\n", i1.team_name);
        for (int k = 0; k<overs; k++){
            printf("\nOver [%-1d] - |",k+1);
            for (int l = 0; l<=12; l++){
                int o = over1[k].over_1[l];
                if (o!=0){
                    if (o == 69){
                        printf(" W |");
                    }
                    else if (o == 96){
                        printf(" NB |");
                    }else if (o == 101){
                        printf(" 0 |");
                    }else{
                        printf(" %d |", o);
                    }
                }
            }
            printf("\n");
        }
        ask_ques();
    }else if (ans == 2){
        // show each over of inning 2
        printf("Over for %s team\n", i2.team_name);
        for (int k = 0; k<overs; k++){
            printf("\nOver [%d] - |",k+1);
            for (int l = 0; l<=12; l++){
                int o = over2[k].over_2[l];
                if (o!=0){
                    if (o == 69){
                        printf(" W |");
                    }
                    else if (o == 96){
                        printf(" NB |");
                    }else if (o == 101){
                        printf(" 0 |");
                    }else{
                        printf(" %d |", o);
                    }
                }
            }
            printf("\n");
        }
        ask_ques();
    }else{
        printf("Wrong Input\n");
        Sleep(2000);
        system("cls");
        ask_ques();
    }

}

// shows overall info on the inning 1 and 2
void inning_info()
{
    // printing Inning details for each team by their batting order
    printf("\nInning Details Between the two team\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("|  Team Name     Inning     Runs     Fours     Sixes     No balls/Wide Balls     Target     Wickets |\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("| %-16s %-8d %-9d %-10d %-15d %-17d %-10d %-5d |\n", i1.team_name,1, i1.total_runs, i1.fours, i1.sixes, i1.no_balls, i1.target, i1.wickets);
    printf("|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
    printf("| %-16s %-8d %-9d %-10d %-15d %-17d %-10d %-5d |\n", i2.team_name,2, i2.total_runs, i2.fours, i2.sixes, i2.no_balls, i2.target, i2.wickets);
    ask_ques();
}   


