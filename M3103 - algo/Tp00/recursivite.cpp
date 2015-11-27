#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

bool estImpairCroise(int n);
bool estPairCroise(int n);
bool estPairQcqCroise(int n);
bool estImpairQcqCroise(int n);

template<class T>
T maxVectWorker(vector<T> v, int inf, int sup)
{
    int m;
    if(inf > sup)
        return 0;
    else if (inf == sup)
        return v[sup];
    else
    {
        int m = (inf + sup) / 2;
        return max(maxVectWorker(v, inf, m), maxVectWorker(v, m+1, sup));
       
    }
}

template<class T>
T maxVect(vector<T> v)
{
    int inf = 0;
    int sup = v.size()-1;
    if (inf > sup)
        return 0;
    else if(inf == sup)
        return v[sup];
    else
    {
       int m = (inf + sup) / 2;
       return max(maxVectWorker(v, inf, m), maxVectWorker(v, m+1, sup));
    }
}

void hanoi(int nbdisques, char depart, char intermediaire, char arrivee)
{
    if(nbdisques == 1)
        cout << "disque 1 de " << depart << " vers " << arrivee << endl;
    else
    {
        hanoi(nbdisques -1, depart, arrivee, intermediaire);
        cout << "disque " << nbdisques << " de " << depart << " vers " << arrivee << endl;
        hanoi(nbdisques-1, intermediaire, depart, arrivee);
    }
}

template<class T>
int dichoRecWorker(vector<T> v, int inf, int sup, T val)
{
    if(inf > sup)
    {
        if(v[inf] == val)
            return inf + 1;
        else
            return -(inf + 1);
    }
    else
    {
        int m = (inf + sup) / 2;
        if(v[m]  < val)
            return dichoRecWorker(v, m+1, sup, val);
        else
             return dichoRecWorker(v, inf, m-1, val);
    }
}

template<class T>
int dichoIter(vector<T> v, T val)
{
    int sup = v.size() -1;
    if(v[sup] < val)
        return -(sup+1);
    else
    {
        int m;
        int inf = 0;
        while(inf <= sup)
        {
            m = (inf + sup)/2;
            if(v[m] < val)
                inf = m + 1;
            else
                sup = m -1;
        }
        if(v[inf] == val)
            return inf + 1;
        else
            return -(inf + 1);
    }
}

template<class T>
int dichoRec(vector<T> v, T val)
{
    if(v[v.size() - 1] < val)
        return -(v.size());
    else
        return dichoRecWorker(v, 0, v.size()-1, val);
}
int f91(int n)
{
    if(n > 100)
        return n-10;
    else
        return f91(f91(n+11));
}

bool estPairQcqCroise(int n)
{
    if(n == 0)
        return true;
    else if(n == 1 || n == -1)
        return false;
    else if(n >= 0)
        return estImpairQcqCroise(n-1);
    else
        return estImpairQcqCroise(n+1);
                
}

bool estImpairQcqCroise(int n)
{
    if(n == 1 || n == -1)
        return true;
    else if(n == 0)
        return false;
    else if (n >= 0)
        return estPairQcqCroise(n-1);
    else
         return estPairQcqCroise(n+1);
}

bool estPairCroise(int n)
{
    if(n == 0)
        return true;
    else if(n == 1)
        return false;
    else
        return estImpairCroise(n-1);
                
}

bool estImpairCroise(int n)
{
    if(n == 1)
        return true;
    else if(n == 0)
        return false;
    else
        return estPairCroise(n-1);
}

bool estPairQcq(int val)
{
    if(val == 0)
        return true;
    else if(val == 1 || val == -1)
        return false;
    else if(val >= 0)
        return estPairQcq(val - 2);
    else
        return estPairQcq(val + 2);
}

bool estPair(int val)
{
    if(val == 0)
        return true;
    else if(val == 1)
        return false;
    else
        return estPair(val -2);
                
}
int factorielleRec(int n)
{
    if(n == 0)
        return 1;
    else
        return factorielleRec(n-1) * n;
}

int factorielle (int n)
{
    int r = 1;
    int i = 1;
    while (i <= n)
    {
        r *= i;
        i++;
    }
    return r;
            
}

double puissanceDRNMult(float x, int n, int& nbmult)
{
    if(n==0)
        return 1;
    else if(n==1)
        return x;
    else if(n > 1 && (n % 2 == 0))
    {
        nbmult++;
        return (puissanceDRNMult(x, n/2, nbmult)*puissanceDRNMult(x, n/2, nbmult));
    }
    else if(x < 0)
    {
        nbmult++;
        return x * (puissanceDRNMult(x, n/2, nbmult)*puissanceDRNMult(x, n/2, nbmult));
    }
}

double puissanceMult(float x, int n, int& nbmult)
{
    if(n==0)
        return 1;
    else if(n > 0)
    {
        nbmult++;
        return x * puissanceMult(x, n-1, nbmult);
    }
}

double puissance(float x, int n)
{
    if(n==0)
        return 1;
    else if(n > 0)
        return(x * puissance(x, n-1));
                
}



template<class T>
void minMaxIter(vector<T> v, T& min, T &max, int &nbComp)
{
    int inf = 0;
    int sup = v.size()-1;
    if (inf > sup)
    {
        min = 0;
        max = 0;
    }
    
    else if(inf == sup)
    {
        min = v[sup];
        max = v[sup];
    }
    
    else
    {
        int m = (inf + sup) / 2;
       
        while(min < max)
        {
            
            nbComp++;
        }
    }
}

int main()
{
    //cout << factorielleRec(5) << endl;
   // cout << estPair(5) << endl;
    //cout << estPairQcq(-6) << endl;
    //cout << estPairCroise(6);
   // cout << estImpairQcqCroise(-1) << endl;
   
    //cout << estImpairQcqCroise(-7)<< endl;
    //cout << f91(1190);
    
    //Test de dichoRec
    /*vector<int> v = {1, 2, 4, 6, 6, 9};
    cout << dichoRec(v, 1) << endl;
    cout << dichoRec(v, 9) << endl;
    cout << dichoRec(v, 6) << endl;
    cout << dichoRec(v, 5) << endl;*/
    
    //Test de hanoi
    /*hanoi(1, 'D', 'I', 'A');
    hanoi(6, 'D', 'I', 'A');*/
    
    //Test max
    /*vector<int> v = {1, 2, 4, 6, 6, 9};
    cout << maxVect(v);*/
    
    //Test puissance
    /*cout << puissance(5, 0) << endl;
    cout << puissance(5, 1) << endl;
    cout << puissance(5, 4) << endl;
    cout << puissance(5, 8) << endl;
    cout << puissance(5, 16) << endl;
    cout << puissance(5, 278) << endl;*/
    
    //Test puissancemult
   /* int mult = 0;
    int &nbMult = mult;
    puissanceMult(5, 16, nbMult);
    cout << mult << endl;  */
    
    //Test puissancemultDRTRUC
    /*int mult = 0;
    int &nbMult = mult;
    puissanceDRNMult(5, 16, nbMult);
    cout << mult << endl;*/
    
    //test de minMaxIter
    vector<int> v = {1, 2, 4, 6, 6, 9};
    int a = 0;
    int &min = a;
    int &max = a;
    int &nbComp = a;
    minMaxIter(v, min, max, nbComp);
    cout << "min : " << min << endl;
    cout << "max: " << min << endl;
    cout << "nbMult : " << min << endl;
    
    
    
}