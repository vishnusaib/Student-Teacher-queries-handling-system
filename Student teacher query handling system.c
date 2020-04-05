#include<stdio.h>
#include<string.h>
 
struct process_Struct {
    char process_name[20];
    int arrival_time, burst_time, completion_time, remaining;
}temp_Struct;
 
 
void faculty_Queue(int np) {
 
    int count, arrival_Time, burst_Time, quantum_time;
    struct process_Struct f_p[np];
 
    for(count = 0; count < np; count++) {
        printf("Enter the details of Process[%d]", count+1);
        puts("");
        printf("Process Name : ");
        scanf("%s", f_p[count].process_name);
 
        printf("Arrival Time : ");
        scanf("%d", &f_p[count].arrival_time);
 
        printf("Burst Time : ");
        scanf("%d", &f_p[count].burst_time);
        puts("");
    }
    printf("Now, enter the quantum time for FACULTY queue : ");
    scanf("%d", &quantum_time);
 
 
    for(count = 0; count < np; count++) 
	{
        int x;
		for( x = count +1; x < count; x++)
		{
            if(f_p[count].arrival_time > f_p[x].arrival_time) 
			{
                temp_Struct = f_p[count];
                f_p[count] = f_p[x];
                f_p[x] = temp_Struct;
            }
        }
    }
 
 
    for(count = 0; count < np; count++) {
        f_p[count].remaining = f_p[count].burst_time;
        f_p[count].completion_time = 0;
    }
 
    int total_time, queue, round_robin[20];
    total_time = 0;
    queue = 0;
    round_robin[queue] = 0;
 
   
    int flag, x, n, z, waiting_time = 0;
    do {
        for(count = 0; count < np; count++){
            if(total_time >= f_p[count].arrival_time){
                z = 0;
                for(x = 0; x <= queue; x++) {
                    if(round_robin[x] == count) {
                        z++;
                    }
                }
                if(z == 0) {
                    queue++;
                    round_robin[queue] == count;
                }
            }
        }
 
        if(queue == 0) {
            n = 0;
        }
        if(f_p[n].remaining == 0) {
            n++ ;
        }
        if(n > queue) {
            n = (n - 1) % queue;
        }
        if(n <= queue) {
            if(f_p[n].remaining > 0) {
                if(f_p[n].remaining < quantum_time){
                    total_time += f_p[n].remaining;
                    f_p[n].remaining = 0;
                }else {
                    total_time += quantum_time;
                    f_p[n].remaining -= quantum_time;
                }
                f_p[n].completion_time = total_time;
            }
            n++;
        }
        flag = 0;
       
        for(count = 0; count < np; count++) {
            if(f_p[count].remaining > 0) {
                flag++;
            }
        }
    }while(flag != 0);
 
    puts("\t\t\t*****   ROUND ROBIN ALGORITHM OUTPUT   *****");
    printf("\n|\tProcess Name  |\tArrival Time  |\tBurst Time |\tCompletion Time |\n");
 
    for(count = 0; count < np; count++){
        waiting_time = f_p[count].completion_time - f_p[count].burst_time - f_p[count].arrival_time;
 
        printf("\n|\t  %s\t    |\t  %d\t   |\t  %d\t   |\t  %d\t   |\n", 
		f_p[count].process_name, f_p[count].arrival_time, f_p[count].burst_time,
		 f_p[count].completion_time);
    }
 
}
 
 
void student_Queue(int np) {
 
    int count, arrival_Time, burst_Time, quantum_time;
    struct process_Struct s_p[np];
 
    for(count = 0; count < np; count++) {
        printf("Enter the details of Process[%d]", count+1);
        puts("");
        printf("Process Name : ");
        scanf("%s", s_p[count].process_name);
 
        printf("Arrival Time : ");
        scanf("%d", &s_p[count].arrival_time);
 
        printf("Burst Time : ");
        scanf("%d", &s_p[count].burst_time);
    }
    printf("Now, enter the quantum time for STUDENT queue : ");
    scanf("%d", &quantum_time);
 
 
    for(count = 0; count < np; count++) {
        int x;
		for(x = count +1; x < count; x++){
            if(s_p[count].arrival_time > s_p[x].arrival_time) {
                temp_Struct = s_p[count];
                s_p[count] = s_p[x];
                s_p[x] = temp_Struct;
            }
        }
    }
 
 
    for(count = 0; count < np; count++) {
        s_p[count].remaining = s_p[count].burst_time;
        s_p[count].completion_time = 0;
    }
 
    int total_time, queue, round_robin[20];
    total_time = 0;
    queue = 0;
    round_robin[queue] = 0;
    
	int flag, x, n, z, waiting_time = 0;
    do {
        for(count = 0; count < np; count++){
            if(total_time >= s_p[count].arrival_time){
                z = 0;
                for(x = 0; x <= queue; x++) {
                    if(round_robin[x] == count) {
                        z++;
                    }
                }
                if(z == 0) {
                    queue++;
                    round_robin[queue] == count;
                }
            }
        }
 
        if(queue == 0) {
            n = 0;
        }
        if(s_p[n].remaining == 0) {
            n++ ;
        }
        if(n > queue) {
            n = (n - 1) % queue;
        }
        if(n <= queue) {
            if(s_p[n].remaining > 0) {
                if(s_p[n].remaining < quantum_time){
                    total_time += s_p[n].remaining;
                    s_p[n].remaining = 0;
                }else {
                    total_time += quantum_time;
                    s_p[n].remaining -= quantum_time;
                }
                s_p[n].completion_time = total_time;
            }
            n++;
        }
        flag = 0;
       
        for(count = 0; count < np; count++) {
            if(s_p[count].remaining > 0) {
                flag++;
            }
        }
    }while(flag != 0);
 
    puts("\t\t\t*****   ROUND ROBIN ALGORITHM OUTPUT   *****");
    printf("\n|\tProcess Name  |\tArrival Time  |\tBurst Time |\tCompletion Time |\n");
 
    for(count = 0; count < np; count++){
        waiting_time = s_p[count].completion_time - s_p[count].burst_time - s_p[count].arrival_time;
 
        printf("\n|\t  %s\t    |\t  %d\t   |\t  %d\t   |\t  %d\t   |\n",
		 s_p[count].process_name, s_p[count].arrival_time, s_p[count].burst_time,
		  s_p[count].completion_time);
    }
}
 
 
int main(int argc, char const *argv[]) {
    int select_queue, np;
 
    puts("Please choose a queue to post your query : ");
    puts("1. FACULTY queue.");
    puts("2. STUDENT queue.");
    printf("> ");
    scanf("%d", &select_queue);
 
    switch(select_queue) {
        case 1 :
                printf("Enter number of process for FACULTY queue : ");
                scanf("%d", &np);
               
                faculty_Queue(np);
               
                break;
 
        case 2 :
                printf("Enter number of process for STUDENT queue : ");
                scanf("%d", &np);
 
                student_Queue(np);
               
                break;
 
        default :
                printf("Please selet the correct option by running the program again.");
    }
 
    return 0;
}
