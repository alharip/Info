#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("matrice.in");
ofstream fout("matrice.out");


class Matrice{
 private:
    int n, m, *a;
 public:
    Matrice();
    Matrice(Matrice& x);
    Matrice(int l,int c,int x[]);
    Matrice(int l,int c,int x[100][100]);
    ~Matrice();
    void vSet(int i,int j,int val);
    int vGet(int i,int j);
    friend istream& operator>>(istream &in, Matrice &A);
    friend ostream& operator<<(ostream &out, Matrice &A);
    friend Matrice& operator+(Matrice& x,Matrice& y);
    friend Matrice& operator-(Matrice& x,Matrice& y);
    friend bool operator==(Matrice& x,Matrice& y);
    friend bool operator!=(Matrice& x,Matrice& y);
    friend Matrice& operator*(Matrice& x,Matrice& y);
    friend Matrice& operator*(int x,Matrice& y);
    friend Matrice& operator*(Matrice& x,int y);
    Matrice& operator=(const Matrice &ob);

    };

    Matrice::Matrice()
    {
        n=0;m=0;
    }

    Matrice::Matrice(Matrice &x)
    {
        this->n = x.n;
        this->m = x.m;
        this->a = new int[n*m];
        for(int i = 0;i < n*m; i++)
            a[i] = x.a[i];
    }
    Matrice::Matrice(int l,int c,int x[])
    {
        this->n = l;
        this->m = c;
        this->a = new int[l*c];
        for(int i = 0;i < l*c; i++)
            this->a[i] = x[i];
    }

    Matrice::Matrice(int l,int c,int x[100][100])
    {
        this->n = l;
        this->m = c;
        this->a = new int[l*c];
        for(int i = 0;i < l; i++)
            for(int j = 0;j < c; j++)
            this->vSet(i,j,x[i][j]);
    }

    Matrice::~Matrice()
    {
        delete this->a;
    }

    Matrice& Matrice::operator=(const Matrice &ob){
     if( this != &ob)
     {
         int b;
         this->~Matrice();
         this->n=ob.n;
         this->m=ob.m;
         this->a=new int[n*m];
         for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            {
            b=ob.a[n*i+j];
            this->vSet(i,j,b);
            }
     }
     return *this;
    }

    void  Matrice::vSet(int i,int j,int val)
    {
        a[m*i+j]=val;
    }

    int Matrice::vGet(int i,int j)
    {
        return a[m*i+j];
    }

    istream& operator>>(istream &in, Matrice &A)
    {
        int b;
        in>>A.n>>A.m;
        A.a = new int[A.n*A.m];
        for(int i = 0;i < A.n; i++)
            for(int j = 0;j< A.m; j++)
           {    in >> b;
                A.vSet(i,j,b);
           }
        return in;
    }
    ostream& operator<<(ostream &out, Matrice &A)
    {
       out<<A.n<<" "<<A.m<<'\n';
       for(int i=0;i<A.n;i++)
        {for(int j=0;j<A.m;j++)
        out<<A.vGet(i,j)<<' ';
        out<<endl;
        }
       return out;
    }




int a[100][100],n,m,i,j;

int main()
{
  Matrice A,B,C;
  fin>>A;
  fout<<A;
  Matrice D(A);
  fin>>n>>m;
  for(i = 0;i < n; i++)
    for(j = 0;j < m; j++)
    fin>>a[i][j];
  Matrice E(n,m,a);
  fout<<A<<D<<E;

}
