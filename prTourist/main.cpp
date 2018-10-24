#include <iostream>
#include <fstream>

using namespace std;

ifstream in("lug.txt");
int n,m,st[10];
char tip[10];

void init()
{
    in >> n >> m;
    for(int i = 1; i <= n; i++)
        in >> tip[i];
}

void write(int p)
{
    for(int i = 1; i <= p; i++)
        cout << st[i] << ' ' << tip[st[i]] << endl;

    cout << "\n\n";
}

bool isValid(int p)
{
    int c = 1, i;
    for(i = 1; i < p; i++)
        if(tip[st[i]] == tip[st[p]])
            c++;

    if((tip[st[i]] == 't' || tip[st[i]] == 'i') && c > 2)
        return false;

    return true;
}

bool isFinalSolution(int p)
{
    if(p == m){

        int a = 0, i = 0, t = 0;
        for(int j = 1; j <= p; j++)
        switch(tip[st[j]])
        {
            case 'a': a++;break;
            case 'i': i++;break;
            case 't': t++;break;
        }

        if(a == 0 || t == 0 || i == 0 || a < 3 || t > 2 || i > 2)
            return false;

    } else return false;

    return true;
}

void bcktr(int p)
{
    for(int v = st[p-1] + 1; v <= n; v++){

        st[p] = v;
        if(isValid(p)){
            if(isFinalSolution(p))
                write(p);
            else
                bcktr(p+1);

        }
    }
}

int main()
{
    init();
    bcktr(1);

    return 0;
}
