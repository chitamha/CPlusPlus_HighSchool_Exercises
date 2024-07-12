#include <bits/stdc++.h>
#define ll long long
#define maxn 1000006
using namespace std;

int n, m;
ll R[maxn], V[maxn];

ll getscore(int x){
    ll score=0;
    for (int i=1; i<=m; i++) score+=abs(x-V[i]);
    return score;
}

int main(){
    //freopen("ROBOT.INP", "r", stdin);
    //freopen("ROBOT.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n>> m;
    for (int i=1; i<=n; i++) cin>> R[i];
    for (int i=1; i<=m; i++) cin>> V[i];
    sort(R+1, R+1+n);
    for (int i=1; i<=n; i++) cout<< getscore(R[i])<< " ";

    return 0;
}

/*
Program ROBOT;
Const
    fin = 'ROBOT.INP';
    fout = 'ROBOT.OUT';
Var
    Left, Right, R, V: Array[0..1000001] of Int64;
    n, m, i, dau, giua, cuoi: Longint;
    S, max: Int64;
    f: Text;

Procedure QuickSort (L,R: Longint);
Var
    i,j,temp,gt: Longint;
Begin
    i:=L; j:=R; gt:=V[(L+R) div 2];
    Repeat
        While V[i] < gt do Inc(i);
        While gt < V[j] do Dec(j);
        If i <= j then
        Begin
            temp:=V[i];
            V[i]:=V[j];
            V[j]:=temp;
            Inc(i);
            Dec(j);
        End;
    Until i > j;
    If L < j then QuickSort(L, j);
    If i < R then QuickSort(i, R);
End;

Begin
    Assign(f, fin);
    Reset(f);
    Readln(f, N, M);
    For i := 1 to N do Read(f, R[i]);
    Readln(f);
    For i := 1 to M do Read(f, V[i]);
    Close(f);

    QuickSort(1, M);

    Left[1] := 0;
    For i := 2 to M do Left[i] := Left[i-1] + (V[i] - V[i-1]) * (i-1);

    Right[M] := 0;
    For i := M-1 downto 1 do Right[i] := Right[i+1] + (V[i+1] - V[i]) * (M-i);

    max := 0;
    V[0] := -trunc(1E9 + 5);
    V[M+1] := trunc(1E9 + 5);

    For i := 1 to N do
    Begin
        dau := 0;
        cuoi := M + 1;
        Repeat
            giua := (dau + cuoi) div 2;
            If V[giua] <= R[i] then dau := giua
            Else cuoi := giua;
        Until dau + 1 = cuoi;

        S := 0;
        If dau > 0 then S := S + Left[dau] + (R[i] - V[dau]) * dau;
        If cuoi <= M then S := S + Right[cuoi] + (V[cuoi] - R[i]) * (M - dau);
        If max < S then max := S;
    End;

    Assign(f, fout);
    ReWrite(f);
    Write(f, max);
    Close(f);
End.
*/
