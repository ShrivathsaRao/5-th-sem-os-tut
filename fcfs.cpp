#include <bits/stdc++.h>

using namespace std;

struct process {
    int pid;
    int arrival_time;
    int burst_time;
    int start_time;
    int completion_time;
    int turnaround_time;
    int waiting_time;
    int response_time;
};

bool cmp_arrival(process const &a,process const &b){
    return a.arrival_time<b.arrival_time;
}
bool cmp_process(process const &a,process const &b){
    return a.pid<b.pid;
}
int main(){
    int num_process;
    cout<<"Enter the number of processes: ";
    cin>>num_process;
    struct process p[n];
    float avg_turnaround_time;
    float avg_waiting_time;
    float avg_response_time;
    int total_turnaround_time = 0;
    int total_waiting_time = 0;
    int total_response_time = 0;
    int is_completed[num_process];
    memset(is_completed,0,sizeof(is_completed));
    for(int i = 0; i < num_process; i++) {
        cout<<"Enter arrival time of process "<<i+1<<": ";
        cin>>p[i].arrival_time;
        cout<<"Enter burst time of process "<<i+1<<": ";
        cin>>p[i].burst_time;
        p[i].pid = i+1;
        cout<<endl;
    }
    sort(p,p+n,cmp_arrival);
    int current_time = 0;
    for(int i=0;i<n;i++)
    {
        if(current_time<p[i].arrival_time){
            current_time=p[i].arrival_time;
        }
        p[i].start_time=current_time;
        p[i].completion_time=current_time+p[i].burst_time;
        p[i].turnaround_time=p[i].completion_time-p[i].arrival_time;
        total_turnaround_time+=p[i].turnaround_time;
        p[i].waiting_time=p[i].turnaround_time-p[i].burst_time;
        total_waiting_time+=p[i].waiting_time;
        p[i].response_time=p[i].waiting_time;
        total_response_time+=p[i].response_time;
        current_time+=p[i].burst_time;
    }
    avg_turnaround_time = (float) total_turnaround_time / n;
    avg_waiting_time = (float) total_waiting_time / n;
    avg_response_time = (float) total_response_time / n;
    cout<<endl<<endl;
    cout<<"Process ID\t"<<"AT\t"<<"BT\t"<<"ST\t"<<"CT\t"<<"TAT\t"<<"WT\t"<<"RT\t"<<"\n"<<endl;
    sort(p,p+n,cmp_process);
    for(int i = 0; i < n; i++) {
            cout<<"P"<<p[i].pid<<"\t\t"<<p[i].arrival_time<<"\t"<<p[i].burst_time<<"\t"<<p[i].start_time<<"\t"<<p[i].completion_time<<"\t"<<p[i].turnaround_time<<"\t"<<p[i].waiting_time<<"\t"<<p[i].response_time<<"\t"<<"\n"<<endl;
    }
    cout<<"Average Turnaround Time = "<<avg_turnaround_time<<endl;
    cout<<"Average Waiting Time = "<<avg_waiting_time<<endl;
    cout<<"Average Response Time = "<<avg_response_time<<endl;

    return 0;
}
