#include <iostream>
#include <fstream>
#include <math.h>
#include <stdlib.h>

using namespace std;

ifstream fin("matrice.in");
ofstream fout("matrice.out");


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
     int Matrice::VMaxLin(int i)  ///2 2 2 2 2 2  2 2 2 2  2
     {
         if(i<=n && i != 0)
         {


         int lmax=0;
             for(int j=m*(i-1);j<m*i;j++)
        if(this->a[j] > lmax)
               lmax = this->a[j];
        return lmax;

         }
         else return 0;





     }


     int Matrice::VMinLin(int i)  ///4 4 4 4 4 4 4 4 4 4
     {
         if(i<=n && i != 0)
         {


         int lmin=2000000000;;
             for(int j=m*(i-1);j<m*i;j++)
        if(this->a[j] < lmin)
               lmin = this->a[j];
        return lmin;

         }
         else return 0;





     }

    int Matrice::VMaxCol(int j)  ///1 1 1 1 1 1 1 1 1 1
    {
        if(j<=m && j != 0)
        {


        int cmax = 0;
        for(int i=j-1;i<n*m;i=i+m)
        if(this->a[i] > cmax)
               cmax = this->a[i];
        return cmax;

}
else return 0;

    }
        int Matrice::VMinCol(int j)  ///3 3 3 3 3 3 3 3 3
    {
        if(j<=m && j != 0)
        {


        int cmin = 2000000000;
        for(int i=j-1;i<n*m;i=i+m)
        if(this->a[i] < cmin)
               cmin = this->a[i];
        return cmin;
        }
        else return 0;

    }

    bool Matrice::Search(int val)
    {
        for(int i = 0;i < n*m; ++i)
            if(this->a[i] == val)
            return true;
        return false;
    }

    int Matrice::VMin()
    {
        int vmin = 2000000000;
        for(int i = 0;i < n*m; ++i)
            if(this->a[i] < vmin)
               vmin = this->a[i];
        return vmin;
    }

    int Matrice::VMax()
    {
        int vmax = 0;
        for(int i = 0;i < n*m; ++i)
            if(this->a[i] > vmax)
               vmax = this->a[i];
        return vmax;
    }

    Matrice operator*(Matrice& x,Matrice& y)
    {
        if(x.m == y.n)
        {
            int l,c,S,a,b;
            l = x.n;
            c = y.m;
            Matrice A(l,c);
            for(int i = 0 ;i < l; ++i)
                for(int j = 0;j < c; ++j)
            {   S=0;
                for(int k = 0;k < x.m; ++k)
                {
                    a = x.vGet(i,k);
                    b = y.vGet(k,j);
                    S+= a*b;
                }
                A.vSet(i,j,S);
            }
            return A;
        }
        Matrice R;
           return R;

    }

    Matrice operator*(Matrice& x,int y)
    {
        int l,c,*z;
        l = x.n;
        c = x.m;
        z = new int[l*c];
        for(int i = 0;i < l*c; ++i)
            z[i] = x.a[i] * y;
        Matrice A(l,c,z);
        return A;
    }

    Matrice operator*(int x,Matrice& y)
    {
        int l,c,*z;
        l = y.n;
        c = y.m;
        z = new int[l*c];
        for(int i = 0;i < l*c; ++i)
            z[i] = y.a[i] * x;
        Matrice A(l,c,z);
        return A;
    }

    bool operator==(Matrice& x,Matrice& y)
    {
        if(x.n == y.n && x.m == y.m)
        {
            for(int i = 0;i < x.n*x.m; ++i)
                if(x.a[i] != y.a[i])
                return false;
            return true;
        }
        return false;
    }

    bool operator!=(Matrice& x,Matrice& y)
    {
        if(x.n == y.n && x.m == y.m)
        {
            for(int i = 0;i < x.n*x.m; ++i)
                if(x.a[i] != y.a[i])
                return true;
            return false;
        }
        return true;
    }

    Matrice operator-(Matrice& x,Matrice& y)
    {
        if(x.n == y.n && x.m == y.m)
        {
            int l,c;
            l=x.n;
            c=x.m;
            int *z;
            z = new int[l*c];
            for(int i = 0;i < l*c ; i++)
                z[i] = x.a[i] - y.a[i];
            Matrice R(l,c,z);
            return R;
        }
        Matrice R;
            return R;

    }

    Matrice operator+(Matrice& x,Matrice& y)
    {
        if(x.n == y.n && x.m == y.m)
        {
            int l,c;
            l=x.n;
            c=x.m;
            int *z;
            z = new int[l*c];
            for(int i = 0;i < l*c ; i++)
                z[i] = x.a[i] + y.a[i];
            Matrice R(l,c,z);
            return R;
        }
        Matrice R;
            return R;

    }

    Matrice::Matrice(int l,int c)
    {
        n = l;
        m = c;
        a = new int[n*m];
    }

    Matrice::Matrice()
    {
        n = 0;
        m = 0;
        a = NULL;
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
         delete a;
         this->n=ob.n;
         this->m=ob.m;
         this->a=new int[n*m];
         for(int i=0;i < n;i++)
            for(int j=0;j < m;j++)
            {
            b=ob.a[m*i+j];
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
       if(A.n != 0 && A.m != 0)
        for(int i=0;i<A.n;i++)
            {for(int j=0;j<A.m;j++)
            out<<A.vGet(i,j)<<' ';
            out<<endl;
            }
       return out;
    }

void stergeecran ()
{
    for(int i=0;i<=40;i++)
     cout<<'\n';

}
 int Matrice::SUMLin(int i)
 {
        if(i<=n && i != 0)
         {


         int s=0;
             for(int j=m*(i-1);j<m*i;j++)
               s =s + this->a[j];
        return s;

         }
         else return 0;

 }
 int Matrice::SUMCol(int j)
 {
        if(j<=n && j != 0)
         {


         int s=0;
           for(int i=j-1;i<n*m;i=i+m)
               s =s + this->a[i];
        return s;

         }
         else return 0;

 }
 int Matrice::SUMMAT()
 {
     int s= 0;
        for(int i = 0;i < n*m; ++i)

               s = s+this->a[i];
        return s;
 }


void meniu ()
{


    cout<< "                                               "<<"CLASA MATRICE"<<"         "<<endl;

    cout<<endl;

    cout<<endl;
    cout<<"COMENZI PROGRAM:"<<endl;
    cout<<"1.  citire matrice A"<<endl;
    cout<<"2.  citire matrice B"<<endl;
    cout<<"3.  afisarea matricii A"<<endl;
    cout<<"4.  afisarea matricii B"<<endl;
    cout<<"5.  adunarea matricii A cu matricea B"<<endl;
    cout<<"6.  scaderea matricii A din matricea B"<<endl;
    cout<<"7.  scaderea matricii B din matricea A"<<endl;
    cout<<"8.  inmultirea matricii A cu matricea B"<<endl;
    cout<<"9. inmultirea matricii B cu matricea A"<<endl;
    cout<<"10. inmultirea matricii A cu elementul x"<<endl;
    cout<<"11. inmultirea unui element x cu matricea A"<<endl;
    cout<<"12. verificare daca matricea A este egala cu matricea B"<<endl;
    cout<<"13. verificare daca matricea A este diferita fata de matricea B"<<endl;
    cout<<"14. afisarea maximului de pe coloana j a matricei A"<<endl;
    cout<<"15. afisarea maximului de pe coloana j a matricei B"<<endl;
    cout<<"16. afisarea maximului de pe linia i a matricei A"<<endl;
    cout<<"17. afisarea maximului de pe linia i a matricei B"<<endl;
    cout<<"18. afisarea minimului de pe linia i a matricei A"<<endl;
    cout<<"19. afisarea minimului de pe linia i a matricei B"<<endl;
    cout<<"20. afisarea minimului de pe coloana j a matricei A"<<endl;
    cout<<"21. afisarea minimului de pe coloana j a matricei B"<<endl;
    cout<<"22. afisarea maximului din matricea A"<<endl;
    cout<<"23. afisarea maximului din matricea B"<<endl;
    cout<<"24. afisarea minimului din matricea A"<<endl;
    cout<<"25. afisarea minimului din matricea B"<<endl;
    cout<<"26. verificarea daca elementul introdus apartinei matricii A"<<endl;
    cout<<"27. verificarea daca elementul introdus apartinei matricii B"<<endl;
    cout<<"28. suma de pe linia i a matricei A"<<endl;
    cout<<"29. suma de pe coloana j a matricei A"<<endl;
    cout<<"30. suma de pe linia i a matricei B"<<endl;
    cout<<"31. suma de pe coloana j a matricei B"<<endl;
    cout<<"32. suma elementelor din matricea A"<<endl;
    cout<<"33. suma elementelor din matricea B"<<endl;
    cout<<endl;
    cout<<"COMENZI SPECIALE PROGRAM:"<<endl;
    cout<<" -1. terminare program "<<endl;
    cout<<"  0. stergerea ecranului"<<endl;
    cout<<"100. REAFISARE MENIU"<<endl;






}

int a[100][100],n,m,i,j;

int main()
{

  Matrice A,B,C,F,X;
/*  fin >> A;
  fout << A;

    fout << A.VMaxCol(3) << '\n';
    fout << A.VMinCol(2) << '\n';
    fout << A.VMaxLin(1) << '\n';
    fout << A.VMinLin(2) << '\n';
  Matrice D(A);
  fin >> n >> m;
  for(i = 0;i < n; i++)
    for(j = 0;j < m; j++)
        fin >> a[i][j];
  Matrice E(n,m,a);
  fout << A << D << E;
  fin >> F;
  C = F*F;
  fout << C.VMax() << '\n';
  C = 2*C;
  fout << C.VMax() << '\n';
  fout << C.VMin() << '\n';
  fout << C;

  if(C.Search(300))
    fout << "DA\n";
  else
    fout << "NU\n";

  if(C.Search(41))
    fout << "DA\n";
  else
    fout << "NU\n";

*/


 meniu();
 int opt,x,a,i,j;
 do{

 cin>>opt;
 switch(opt){

 case 0 : stergeecran(); break;
 case 1 : cin>>A; cout<<endl; break;
 case 2 : cin>>B; cout<<endl; break;
 case 3 : cout<<A; cout<<endl; break;
 case 4 : cout<<B; cout<<endl; break;
 case 5 : A=A+B; break;
 case 6 : A=A-B; break;
 case 7 : B=B-A; break;
 case 8 : A=A*B; break;
 case 9 : B=B*A; break;
 case 10: cin>>x; A=A*x; break;
 case 11: cin>>x; A=x*A; break;
 case 12: if(A==B) cout<<"SUNT EGALE"<<endl;
           else cout<<"NU SUNT EGALE"<<endl;
            break;
 case 13: if(A!=B) cout<<"NU SUNT EGALE"<<endl;
          else cout <<"SUNT EGALE"<<endl;
          break;

case 14:  cin>>j;  cout<<A.VMaxCol(j); break;
case 15:  cin>>j; cout<<B.VMaxCol(j); break;
case 16:  cin>>i; cout<<A.VMaxLin(i); break;
case 17:  cin>>i; cout<<B.VMaxLin(i); break;
case 18:  cin>>i; cout<<A.VMinLin(i); break;
case 19:  cin>>i; cout<<B.VMinLin(i); break;
case 20:  cin>>j; cout<<A.VMinCol(j); break;
case 21:  cin>>j; cout<<B.VMinCol(j); break;
case 22: cout<<A.VMax(); break;
case 23: cout<<B.VMax(); break;
case 24: cout<<A.VMin(); break;
case 25: cout<<B.VMin(); break;
case 26: cin>>a; if(A.Search(a))
                   cout << "DA\n";
                   else
                  cout << "NU\n";
                  break;
case 27: cin>>a; if(B.Search(a))
                   cout << "DA\n";
                   else
                  cout << "NU\n";
case 28: cin>>i; cout<<A.SUMLin(i); break;
case 29: cin>>j; cout<<A.SUMCol(j); break;
case 30: cin>>i; cout<<B.SUMLin(i); break;
case 31: cin>>j; cout<<B.SUMCol(j); break;
case 32: cout<<A.SUMMAT(); break;
case 33: cout<<B.SUMMAT(); break;
case 100: meniu(); break;







            }



}while (opt!=-1);


}
