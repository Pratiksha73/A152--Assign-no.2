//A152- Pratiksha Kashid
//Assignment no.2


#include <stdio.h>
#include <string.h>
int n;
struct scorecard 
{
	char name[100];
	int age;
	char country[100];
	char category[100];
	int odi;
	int t20;
	float avg_bat;
	int wickets;
};
void sortplayers(struct scorecard arr[]);
void n_country(struct scorecard arr[]);
void h_avg(struct scorecard arr[]);
void bowl_country(struct scorecard arr[]);
void maxwickets(struct scorecard arr[]);

int main(void) 
{
	printf("Enter no of players to take data of: \n");
	scanf("%d", &n);
	struct scorecard arr[n];
	for (int i = 0; i < n; i++) 
  {
		printf("Enter Name of Player %d: \n", i + 1);
		scanf("%s", arr[i].name);
		printf("Enter his age: \n");
		scanf("%d", &arr[i].age);
		printf("Enter his country: \n");
		scanf("%s", arr[i].country);
		printf("Enter his style of play, 'batsman','bowler','wk','all rounder\n");
		scanf("%s", arr[i].category);
		printf("Enter no of odis played: \n");
		scanf("%d", &arr[i].odi);
		printf("Enter no of T20Is played: \n");
		scanf("%d", &arr[i].t20);
		printf("Enter batting average: \n");
		scanf("%f", &arr[i].avg_bat);
		printf("Enter no of wickets taken: \n");
		scanf("%d", &arr[i].wickets);
	}
   printf("\n\n");
	int choice = 0;
	for (;;) 
  {
		printf("1.Find players from a particular country\n");
		printf("2.Find player with highest batting avg\n");
		printf("3.Find Bowlers from a particular country\n");
		printf("4.Find player with Maximum Wickets\n");
    printf("5.To sort the batsman acc to their batting avg\n");
		printf("6.To close the software\n");
		printf("Enter your choice\n");
		scanf("%d", &choice);
		switch (choice) 
    {
		case 1:
			n_country(arr);
			break;
		case 2:
			h_avg(arr);
			break;
		case 3:
			bowl_country(arr);
			break;
		case 4:
			maxwickets(arr);
			break;
      case 5:
      sortplayers(arr);
      break;
		case 6:
			goto label;
			break;
		default:
			printf("Invalid input try again\n");
		}
	}

label:
	return 0;
}
void n_country(struct scorecard arr[]) 
{
	char ch[100];
	printf("Enter the country to display its players\n");
	scanf("%s", ch);
	printf("Players playing for %s country are\n", ch);
	for (int i = 0; i < n; i++) 
  {
		if (strcmp(ch, arr[i].country) == 0)
			printf("%s\n", arr[i].name);
	}
}
void h_avg(struct scorecard arr[]) 
{
	float cont = arr[0].avg_bat;
	int c;
	for (int i = 0; i < n; i++) 
  {
		if (arr[i].avg_bat > cont) 
    {
			cont = arr[i].avg_bat;
			c = i;
		}
	}
	printf("Player with highest batting avg is %s with avg %.2f\n",arr[c].name, cont);
}
void bowl_country(struct scorecard arr[]) 
{
	char ch[100];
	printf("Enter Country\n");
	scanf("%s", ch);
	printf("Bowlers from %s are\n", ch);
	for (int i = 0; i < n; i++) 
  {
		if ((strcmp(ch, arr[i].country) == 0) &&
			strcmp(arr[i].category, "bowler") == 0)
			printf("%s\n", arr[i].name);
	}
}
void maxwickets(struct scorecard arr[]) 
{
	int cont = arr[0].wickets;
	int c = 0;
	for (int i = 0; i < n; i++) 
  {
		if (arr[i].wickets > cont)
     {
			cont = arr[i].wickets;
			c = i;
		}
	}
	printf("Players with most wickets is %s with wickets %d\n", arr[c].name, cont);
}
void sortplayers(struct scorecard arr[])
{
 int  min_idx;
 
   char temp[100];
   float tem=0;
    for (int i = 0; i < n-1; i++)
    {
     min_idx = i;
     for (int j = i+1; j < n; j++)
     if (arr[j].avg_bat > arr[min_idx].avg_bat)
     min_idx = j;

tem=arr[min_idx].avg_bat;
arr[min_idx].avg_bat=arr[i].avg_bat;
arr[i].avg_bat=tem;
  strcpy(temp, arr[min_idx].name);
  strcpy(arr[min_idx].name,arr[i].name);
  strcpy(arr[i].name,temp);
}
    printf("Name\tAvg\n");
    for(int i=0;i<n;i++)
    {
      printf("%s\t%.2f\n",arr[i].name,arr[i].avg_bat);
    }
}