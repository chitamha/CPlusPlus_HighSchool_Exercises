class Solution {
public:
    struct job{
        int st, en, pro;
        friend bool operator < (job A, job B){
            return A.en<B.en;
        }
    };

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n=startTime.size(), ma=0;
        int F[50005]; job Temp[n];
        memset(F, 0, sizeof F);
        for (int i=0; i<n; i++) Temp[i]={startTime[i], endTime[i], profit[i]};
        sort(Temp, Temp+n);
        for (int i=0; i<n; i++){
            startTime[i]=Temp[i].st;
            endTime[i]=Temp[i].en;
            profit[i]=Temp[i].pro;
        }
        for (int i=0; i<n; i++){
            F[i]=profit[i];
            for (int j=i-1; j>=0; j--){
                if (endTime[j]<=startTime[i]){
                    F[i]=max(F[i], F[j]+profit[i]);
                    //break;
                }
            }
            ma=max(ma, F[i]);
            cout<< F[i]<< " ";
        }
        return ma;
    }
};
