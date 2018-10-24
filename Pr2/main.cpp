#include <iostream>
#include <fstream>

using namespace std;

ifstream in("mat.txt");
int n, S, m[11][11];

void init()
{
    in >> n >> S;
}

void write(int p, int q)
{
    for(int i = 1; i <= p; i++){
    for(int j = 1; j <= q; j++)
        cout << m[i][j] << ' ';

        cout << endl;
    }

    cout << endl;
}

bool isValid(int p, int q)
{
    for(int j = 1; j < q; j++)
        if(m[p][j] == m[p][q])
            return false;

    for(int i = 1; i < p; i++)
        if(m[i][q] == m[p][q])
            return false;

    if(q == n){

        int s = 0;
        for(int j = 1; j <= n; j++)
            s += m[p][j];

        if(s != S)
            return false;
    }

    if(p == n){

        int s = 0;
        for(int i = 1; i <= n; i++)
            s += m[i][q];

        if(s != S)
            return false;
    }

    if(p == n && q == n){

        int s1 = 0, s2 =0;
        for(int i = 1; i <= n; i++){
            s1 += m[i][i];
            s2 += m[i][n-i+1];
        }

        if(s1 != S || s2 != S)
            return false;
    }

    return true;
}

void bcktr(int p, int q)
{
    for(int val = 1; val <= S; val++){

        m[p][q] = val;
        if(isValid(p,q)){
            if(p == n && q == n)
                write(p,q);

            else {

                if(q < n)
                    bcktr(p, q+1);

                if(p < n)
                    bcktr(p+1, 1);
            }
        }
    }
}

int main()
{
    init();
    bcktr(1,1);

    return 0;
}
