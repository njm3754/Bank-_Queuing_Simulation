#include <iostream>
#include "Queue.h"
using namespace std;


//Function to find the shortest queue for the customers to join.
int shortest_line(Queue q[], int);
int queue_total(Queue q[], int);

int main()
{
    int pairs, Duration_Total, MAX_TRANS_TIME, seed, Arrival_Probability, time_entered, wait_sum, longest_wait, Count, avg_wait;

    //Output statements to prompt the user for inputs

    cout<<"Entered these parameters of the simulation";
    cout<<"\n  Enter the number of servers/pairs";
    cin>>pairs;

    cout<<"\n  The probability that a customer arrives in one tick (%)";
    cin>>Arrival_Probability;

    cout<<"    The maximum duration of transaction is ticks: ";
    cin>>MAX_TRANS_TIME;

    cout<<"\n  The duration of the simulation in ticks: ";
    cin>>Duration_Total;

    cout<<"\nEnter a random number seed: ";
    cin>>seed;

    //Declaration of number of objects.
    int const Number_of_Servers = pairs;

    //Declaration of number classes and arrays of teller times
    //which will be set to 0 at beginning.

    Queue q[Number_of_Servers];
    int tellers[Number_of_Servers];

    //for loop which creates the array of tellers
    for(int i=0; i<Number_of_Servers; i++)
    {
        tellers[i]=0;
    }

    srand(seed);

    Count=0;
    wait_sum=0;
    longest_wait=0;
    int s;

    //Main loop which calculates all the results
    for(int time=0; time<Duration_Total; time++)
    {
        s=shortest_line(q, Number_of_Servers);
        q[s].enqueue(time);
    }

    for(int k=0; k<Number_of_Servers; k++)
    {
        if (tellers[k]==0)
        {
            if(!q[k].check_if_empty())
            {
                time_entered=q[k].dequeue();
                wait_sum+=(time-time_entered);
                Count++;
                tellers[k]=(rand()%MAX_TRANS_TIME)+1;

                if ((time-time_entered)>longest_wait)
                    longest_wait=(time-time_entered);
            }

        }
       else
            --tellers[k];
    }

    //This part prints the time and the queues with the transaction time.

    cout<<"\n\nTime: "<<(time+1)<<endl;

    for(int i=0; i<Number_of_Servers; i++)
    {
        cout<<"\n   "<<tellers[i]<<"    "<<q[i];
    }

    //Final output statement which prints the summary of the program.
    cout<<"\n\nThe amount of people served: "<<Count<<endl;
    avg_wait=wait_sum/Count;
    cout<<"The average wait time: "<<avg_wait<<endl;
    cout<<"The longest time a customer waited: "<<longest_wait<<endl;
    cout<<"The amount of people left in the line at the end of the duration: "<<queue_total(q, Number_of_Servers)<<endl;


    return 0;
}

int queue_total(Queue q[], int Number_of_Servers)
{
    int customers_left=0;
    for(int i=0; i<Number_of_Servers; ++i)
        customers_left += q[i].size_queue();
    return customers_left;
}

int shortest_line(Queue q[], int Total_Servers)
{
    int shortest_size=0;
    for(int i=1; i<Total_Servers; i++)
    {
        if(q[i].size_queue()<q[shortest_size].size_queue())
            shortest_size=1;
    }
    return shortest_size;
}
