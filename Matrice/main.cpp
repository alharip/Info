#include <iostream>

using namespace std;

class Matrice{
 private:
    int n, m, *a;
 public:
    Matrice();
    Matrice(Matrice& x);
    Matrice(int l,int c,int x[]);
    Matrice(int l,int c,int &x);
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
        a[n*i+j]=val;
    }

    int Matrice::vGet(int i,int j)
    {
        return a[n*i+j];
    }

    istream& operator>>(istream &in, Matrice &A)
    {
        int b;
        in>>A.n>>A.m;
        A.a = new int[A.n*A.m];
        for(int i=0;i<A.n;i++)
            for(int j=0;j<=A.m;j++)
           {    in>>b;
                A.vSet(i,j,b);
           }
        return in;
    }
    ostream& operator<<(ostream &out, Matrice &A)
    {
       out<<A.n<<" "<<A.m<<'\n';
       for(int i=0;i<A.n;i++)
        for(int j=0;j<A.m;j++)
        out<<A.vGet(i,j);
       return out;
    }






int main()
{

}
