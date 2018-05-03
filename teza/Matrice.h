#include <iostream>
#include <fstream>

using namespace std;

class Matrice{
 private:
    int n, m, *a;
 public:
    Matrice();

    Matrice(int l,int c);
    Matrice(Matrice& x);
    Matrice(int l,int c,int x[]);
    Matrice(int l,int c,int x[100][100]);
    ~Matrice();
    void vSet(int i,int j,int val);
    int vGet(int i,int j);
    int VMaxCol(int j); /// 1 1 1 1 1 1 1 1 1 1 1 1
    int VMaxLin(int i); /// 2 2 2 2 2 2 2 2 2 2 2 2
    int VMinCol(int j); /// 3 3 3 3 3 3 3 3 3 3 3 3
    int VMinLin(int i); /// 4 4 4 4 4 4 4 4 4 4 4 4
    int SUMLin(int i);
    int SUMCol(int j);
    int SUMMAT();
    int VMax();
    int VMin();
    bool Search(int val);
    friend istream& operator>>(istream &in, Matrice &A);
    friend ostream& operator<<(ostream &out, Matrice &A);
    friend Matrice operator+(Matrice& x,Matrice& y);
    friend Matrice operator-(Matrice& x,Matrice& y);
    friend bool operator==(Matrice& x,Matrice& y);
    friend bool operator!=(Matrice& x,Matrice& y);
    friend Matrice operator*(Matrice& x,Matrice& y);
    friend Matrice operator*(int x,Matrice& y);
    friend Matrice operator*(Matrice& x,int y);
    Matrice& operator=(const Matrice &ob);


    };

