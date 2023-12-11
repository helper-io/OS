#include<stdio.h>

int q[50];
int rear = -1;

void enque(int a)
{
    rear++;
    q[rear]=a;
}


int dequeue(){
    if(rear==-1){
        return -1;
    }else{
        int ele = q[0];
        for(int i=0;i<rear;i++){
            q[i] = q[i+1];
        }
        rear = rear -1;
        return ele;
    }
}

int main(){
    int n;
    int tq;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter time quantum: ");
    scanf("%d",&tq);
    int at[n];
    int bt[n];
    int tbt[n];
    int visited[n];
    int queued[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter the arrival time of process %d: ", i + 1);
        scanf("%d", &at[i]);
        printf("Enter the burst time of process %d: ", i + 1);
        scanf("%d", &bt[i]);
        tbt[i] = bt[i];
        visited[i] = 0;
        queued[i] = 0;
    }

    int ct[n];
    int temp = at[0];
    int ps = 0;
    enque(0);
    queued[0] = 1;

    printf("\n----------------------\n");
    printf("Process Sequence\n");
    
    while(ps<n){
        if(rear != -1){
            int index = dequeue();
            printf("P%d ",index+1);
            queued[index] = 0;
            if(bt[index]<=tq){
                ct[index] = temp+bt[index];
                temp = ct[index];
                visited[index] = 1;
               
                ps++;
            }else{
                bt[index] -= tq;
                temp += tq;
            }
            for(int i=0;i<n;i++){
                if(i!=index && visited[i]==0 && queued[i]==0 && at[i]<=temp){
                    enque(i);
                    queued[i]=1;
                    
                }
            }
            if(visited[index]==0){
                enque(index);
                queued[index] = 1;
            }
        }else{
            for(int i=0;i<n;i++){
                if(visited[i]==0){
                    temp = at[i];
                    enque(i);
                    queued[i] =1;
                    break;
                }
            }
        }
    }

    printf("\n----------------------\n");
    printf("Process\t|AT\t|BT\t|CT\n");
    for(int i = 0; i < n; i++)
    {
        printf("P%d\t|%d\t|%d\t|%d\n", i + 1, at[i], tbt[i], ct[i]);
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