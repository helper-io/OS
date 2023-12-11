#include<stdio.h>

int main()
{
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    int at[n];
    int bt[n];
    int visited[n];

    for (int i = 0; i < n; i++)
    {
        printf("Enter the arrival time of process %d: ", i + 1);
        scanf("%d", &at[i]);
        printf("Enter the burst time of process %d: ", i + 1);
        scanf("%d", &bt[i]);
        visited[i] = 0;
    }
    int ct[n];
    int time = at[0];
    int ps=0;

    while(ps<n)
    {
        int tid = 0;
        int tbt = bt[0];
        for (int i = 0; i < n; i++)
        {
            if(visited[i]==0)
            {
                tid=i;
                tbt=bt[i];
                break;
            }
        }
        
        int flag=0;
        for (int i = 0; i < n; i++)
        {   
            
            if(at[i]<=time && visited[i]==0)
            {
                flag=1;
                if(bt[i]<tbt)
                {
                    tbt=bt[i];
                    tid=i;
                }
            }
        }
        
        if(flag==1){
            ct[tid] = tbt+time;
            visited[tid] = 1;
            time = ct[tid];
            ps++;
        }else{
            time++;
        }
           
        
        
    }
    printf("----------------------\n");
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