#include <bits/stdc++.h>
using namespace std;

class myStr_198
{
   int len_198;
   char *c;

public:
   myStr_198()
   {
      len_198 = 0;
      c = new char;
   }
   myStr_198(char *c1, int l)
   {
      len_198 = l;
      c = new char[l + 1];
      strcpy(c, c1);
   }

   void display_198();
   void add_198(myStr_198 &c2);
   ~myStr_198()
   {
      cout << "Here destructor is invoked\n";
   }
};

void myStr_198 ::display_198()
{
   for (int i = 0; i < len_198; i++)
   {
      cout << c[i];
   }
   cout << endl;
}

void myStr_198::add_198(myStr_198 &c2)
{
   char *n = new char[len_198 + c2.len_198 - 1];
   strcpy(n, c);
   strcat(n, c2.c);
   cout << "The concenated strings are :-\n";
   cout << n << endl;
   delete[] n;
}
int main()
{
   char c1[100], c2[100];
   cout << "Enter two strings :\n";
   cin >> c1 >> c2;

   myStr_198 st1(c1, strlen(c1));
   myStr_198 st2(c2, strlen(c2));

   char *p[100];
   st1.add_198(st2);

   return 0;
}
