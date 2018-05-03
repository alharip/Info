#include <math.h>
#include <stdlib.h>
#include "Matrice.h"

using namespace std;

ifstream fin("matrice.in");
ofstream fout("matrice.out");


void meniu ();
void stergeecran ();

int a[100][100],n,m,i,j;
Matrice A,B,C,D,E,F;
int main()
{


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



void stergeecran ()
{
    for(int i=0;i<=40;i++)
     cout<<'\n';

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
