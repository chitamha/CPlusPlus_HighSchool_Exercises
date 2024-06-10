#include <bits/stdc++.h>
using namespace std;

int n, day;
struct job{
    int id, deadline, profit;
};
vector<job> jobs;

bool cmp(job A, job B){
    return A.deadline>B.deadline;
}

int main(){
    cin>> n;
    for (int i=0; i<n; i++){
        job A;
        cin>> A.id>> A.deadline>> A.profit;
        jobs.push_back(A);
    }
    sort(jobs.begin(), jobs.end(), cmp);
    cout<< "After Sorting"<< endl;
    for (int i=0; i<n; i++)
        cout<< jobs[i].id<< " "<< jobs[i].deadline<< " "<< jobs[i].profit<< endl;
    priority_queue<int> Q;
    int loinhuan=0, i=0;
    day=jobs[0].deadline;
    cout<< "Max Deadline is "<< day<< endl;
    while (day>=1){
        while (jobs[i].deadline>=day && i<=n-1){
            cout<< "Push "<< jobs[i].deadline<< " "<< jobs[i].profit<< endl;
            Q.push(jobs[i].profit);
            i++;
        }
        if (!Q.empty()){
            loinhuan+=Q.top();
            cout<< "Day "<< day<< ": "<< Q.top()<< ". Total: "<< loinhuan<< endl;
            Q.pop();
        }
        day--;
    }
    cout<< loinhuan;
    return 0;
}
