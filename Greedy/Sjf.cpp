#include<bits/stdc++.h>
using namespace std;

struct Process
{
    int id;
    int at,bt,ct{0},tat{0},wt{0},rt{0};
    bool pushed {false};
};

bool sortBasedOnAT(Process* a,Process* b)
{
    return a->at < b->at;
}
bool sortBasedOnBT(Process* a,Process* b)
{
    if(a->bt != b->bt)
    {
        return a->bt < b->bt;
    }
    else
    {
        return a->at < b->at;
    }
}
int main()
{
   
    Process p1{ 1,0,5};
    Process p2{ 2,8,4};
    Process p3{ 3,9,6};
    Process p4{ 4,8,2};
    Process p5{ 5,10,3};
   
    vector<Process*> processQ  = {&p1,&p2,&p3,&p4,&p5};
    
  

       
    // sort based on at
   // sort(processQ.begin(),processQ.end(),sortBasedOnAT);
    queue<Process*> readyQ;

    // readyQ.push(processQ[0]);
    int t = 0;
    int numProcessRemaining = processQ.size();
    while(numProcessRemaining > 0)
    {
        // add new processes to ready queue
       
            for(int i=0;i<processQ.size();i++)
            {
                if(!processQ[i]->pushed && processQ[i]->at <= t )
                {
                    // cout<<" pushed in readyqueue p"<<i+1<<" t is = "<<t<<endl;
                    // cout<<" at is "<<processQ[i]->at<<endl;
                    processQ[i]->pushed = true;
                    readyQ.push(processQ[i]);
                }
            }
        
        
        if(readyQ.empty())
        {
            t++;
            continue;
        }
        // sort ready queue
        vector<Process*> temp = {};
        while(!readyQ.empty())
        {
            temp.push_back(readyQ.front());
            readyQ.pop();
        }
        sort(temp.begin(),temp.end(),sortBasedOnBT);

        for(int i=0;i<temp.size();i++)
        {
            readyQ.push(temp[i]);
        }

        //execute first process in queue
        Process *running = readyQ.front();
        // cout <<running->id <<" is chosen "<<endl;
        readyQ.pop();
        // time at which process 1st gets cpu
        // later we will subtract arriva time from it
        running->rt = t;
        t = t + (*running).bt;
        // cout<<"ct = "<<t<<" \n";
        running->ct = t;
       
        // running->executed = true;
        numProcessRemaining--;
        
    }
    cout<<"sjf finished calculating Completion times \n";
    // calculate tat , wt ,rt
    for(int i=0;i<processQ.size();i++)
    {
        
        processQ[i]->tat = processQ[i]->ct - processQ[i]->at;
        processQ[i]->wt = processQ[i]->tat - processQ[i]->bt;
        processQ[i]->rt = processQ[i]->rt - processQ[i]->at;

        cout<<"Process : "<<processQ[i]->id<<" \n";
        cout<<"ct : "<<processQ[i]->ct<<"   ";
        cout<<"tat : "<<processQ[i]->tat<<"   ";
        cout<<"wt : "<<processQ[i]->wt<<"   ";
        cout<<"rt : "<<processQ[i]->rt<<"\n";
    }
   
}
