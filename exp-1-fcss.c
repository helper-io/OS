# include<stdio.h>

int main()
{
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    int at[n];
    int bt[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter the arrival time of process %d: ", i + 1);
        scanf("%d", &at[i]);
        printf("Enter the burst time of process %d: ", i + 1);
        scanf("%d", &bt[i]);
    }
    
    int ct[n];
    int temp = at[0];
    for (int i = 0; i < n; i++)
    {
        ct[i]  = temp + bt[i];
        if(ct[i]<at[i+1]){
            temp = at[i+1];
        }else{
            temp = ct[i];
        }
    }
    
    printf("Process\t|AT\t|BT\t|CT\n");
    for(int i = 0; i < n; i++)
    {
        printf("%d\t|%d\t|%d\t|%d\n", i + 1, at[i], bt[i], ct[i]);
    }

    int total_waiting_time = 0;
    int total_turnaround_time = 0;

    for (int i = 0; i < n; i++)
    {
        total_waiting_time += ct[i] - bt[i] - at[i];
        total_turnaround_time += ct[i] - at[i];
    }

    printf("Average waiting time: %f\n", (float)total_waiting_time / n);
    printf("Average turnaround time: %f\n", (float)total_turnaround_time / n);
    return 0;
}