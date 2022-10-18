#include <bits/stdc++.h>
#include <string.h>
#include <conio.h>
using namespace std;

struct student
{
  int roll;
  string name;
  int b_id;
  int cgpa;
  struct student *next;
} *sfirst = NULL;

struct university
{
  int u_id;
  string u_name;
  string u_loc;
  int u_year;
  struct university *next;
} *ufirst = NULL;

struct branch
{
  int b_id;
  int u_id;
  string b_name;
  struct branch *next;
} *bfirst = NULL;

// 1) Keep the Roll No, University ID and Branch ID Unique (Duplicated entry should not be allowed and prompted)

int check_branch(int b)
{
  int ctr = 0;
  branch *p = bfirst;
  while (p)
  {
    if (p->b_id == b)
    {
      ctr++;
    }
    p = p->next;
  }
  if (ctr > 0)
  {
    return 1;
  }
  else
    return 0;
}

int check_roll(int b)
{
  int ctr = 0;
  student *p = sfirst;
  while (p)
  {
    if (p->roll == b)
    {
      ctr++;
    }
    p = p->next;
  }
  if (ctr > 0)
  {
    return 1;
  }
  else
    return 0;
}
int check_uid(int b)
{
  int ctr = 0;
  university *p = ufirst;
  while (p)
  {
    if (p->u_id == b)
    {
      ctr++;
    }
    p = p->next;
  }
  if (ctr > 0)
  {
    return 1;
  }
  else
    return 0;
}

int check_bid(int bid)
{
  int ctr = 0;
  branch *p = bfirst;
  while (p)
  {
    if (p->b_id == bid)
    {
      ctr++;
    }
    p = p->next;
  }
  if (ctr > 0)
  {
    return 1;
  }
  else
    return 0;
}

void display_student()
{
  cout << endl;
  student *p = sfirst;
  while (p)
  {
    cout << p->name << " ";
    cout << p->roll << " ";
    cout << p->b_id << " ";
    cout << p->cgpa << " ";
    p = p->next;
  }
  cout << endl
       << endl
       << "Press any key";
  getch();
}

void insert_student(string name, int roll, int bid, int cgpa)
{
  student *t = new student;
  transform(name.begin(), name.end(), name.begin(), ::toupper); // to convert stuident name in capital
  t->name = name;
  t->roll = roll;
  t->b_id = bid;
  t->cgpa = cgpa;
  t->next = NULL;
  student *p = sfirst;
  if (sfirst == NULL)
  {
    sfirst = t;
    cout << endl
         << "Student data inserted ";
    display_student();
  }
  else
  {
    p = sfirst;
    while (p->next != NULL)
    {
      p = p->next;
    }

    p->next = t;

    cout << endl
         << "Student data inserted ";
    display_student();
    getch();
  }
}

void display_university()
{

  //	//sorting
  //
  //	 struct university *current = ufirst, *index = NULL;
  //
  //        int tid ;
  //		string tname;
  //		string tloc;
  //		int tyear;
  //
  //        if(ufirst == NULL) {
  //            return;
  //        }
  //        else {
  //            while(current != NULL) {
  //                //Node index will point to node next to current
  //                index = current->next;
  //
  //                while(index != NULL) {
  //                    //If current node's data is greater than index's node data, swap the data between them
  //                    if(current->u_year > index->u_year) {
  //
  //						tid =current->u_id;
  //						tname=current->u_name;
  //					    tloc=current->u_loc;
  //						tyear=current->u_year;
  //
  //
  //                        current->u_id=index->u_id;
  //						current->u_name=index->u_name;
  //					    current->u_loc=index->u_loc;
  //						current->u_year=index->u_year;
  //
  //                        index->u_id = tid;
  //						index->u_name=tname;
  //						index->u_loc=tloc;
  //						index->u_year=tyear;
  //                    }
  //                    index = index->next;
  //                }
  //                current = current->next;
  //            }
  //        }
  //sorting
  cout << endl;
  university *p = ufirst;
  while (p)
  {
    cout << p->u_id << " ";
    cout << p->u_name << " ";
    cout << p->u_loc << " ";
    cout << p->u_year << " ";
    cout << endl;
    p = p->next;
  }
  cout << endl
       << endl
       << "Press any key";
  getch();
}

void insert_u(string uname, int uid, int year, string uloc)
{

  university *t = new university;
  transform(uname.begin(), uname.end(), uname.begin(), ::toupper);
  t->u_name = uname;
  t->u_id = uid;
  t->u_loc = uloc;
  t->u_year = year;
  t->next = NULL;
  university *p = ufirst;

  if (ufirst == NULL)
  {
    ufirst = t;
    cout << endl
         << "University data inserted ";
    display_university();
  }
  else
  {
    p = ufirst;
    while (p->next != NULL)
    {
      p = p->next;
    }

    p->next = t;

    cout << endl
         << "University data inserted ";
    display_university();
    getch();
  }
}

void display_branch()
{

  cout << endl;
  branch *p = bfirst;
  while (p)
  {
    cout << p->b_id << " ";
    cout << p->b_name << " ";
    cout << p->u_id << " ";

    cout << endl;
    p = p->next;
  }
  cout << endl
       << endl
       << "Press any key";
  getch();
}

void insert_b(string bname, int bid, int uid)
{

  branch *t = new branch;
  transform(bname.begin(), bname.end(), bname.begin(), ::toupper);
  t->b_id = bid;
  t->b_name = bname;
  t->u_id = uid;

  t->next = NULL;
  branch *p = bfirst;

  if (bfirst == NULL)
  {
    bfirst = t;
    cout << endl
         << "Branch data inserted ";
    display_branch();
  }
  else
  {
    p = bfirst;
    while (p->next != NULL)
    {
      p = p->next;
    }

    p->next = t;

    cout << endl
         << "Branch data inserted ";
    display_branch();
    getch();
  }
}

void del_name(string sname)
{
  if (sfirst == NULL)
  {
    return;
  }
  struct student *temp = sfirst;
  struct student *before = sfirst;
  while (temp->name != sname)
  {
    before = temp;
    temp = temp->next;
  }
  before->next = temp->next;
  free(temp);
  cout << endl
       << "record deleted" << endl;
  display_student();
}
void del_roll(int roll1)
{
  if (sfirst == NULL)
  {
    return;
  }
  struct student *temp = sfirst;
  struct student *before = sfirst;
  while (temp->roll != roll1)
  {
    before = temp;
    temp = temp->next;
  }
  before->next = temp->next;
  free(temp);
  cout << endl
       << "record deleted" << endl;
  display_student();
}

void delete_u(int uid)
{
  if (ufirst == NULL)
  {
    return;
  }
  struct university *temp = ufirst;
  struct university *before = ufirst;
  while (temp->u_id != uid)
  {
    before = temp;
    temp = temp->next;
  }
  before->next = temp->next;
  free(temp);
  cout << endl
       << "record deleted" << endl;
  display_university();
}

void mod_name(string name1)
{
  cout << endl
       << "What you have to modify ?";
  cout << endl
       << "1. name";
  cout << endl
       << "2. branch";
  cout << endl
       << "3. cgpa";
  cout << endl
       << "Enter coise(1-3) : ";
  int ans;
  cin >> ans;
  switch (ans)
  {
  case 1:
  {
    cout << endl
         << "Enter New name : \n";
    string nname;
    cin >> nname;
    cout << endl
         << "Enter old name need to be updated : \n";
    string oname;
    cin >> oname;
    student *temp = sfirst;
    while (temp->name != oname)
    {
      temp = temp->next;
    }
    temp->name = nname;
    cout << endl
         << "Name Updated";
    display_student();

    break;
  }
  case 2:
  {
    cout << endl
         << "Enter New Branch id : ";
    int nbranch;
    cin >> nbranch;
    student *temp = sfirst;
    while (temp->b_id != nbranch)
    {
      temp = temp->next;
    }
    temp->b_id = nbranch;
    cout << endl
         << "Branch Updated";
    display_student();

    break;
  }
  case 3:
  {
    cout << endl
         << "Enter New CGPA : ";
    int ncgpa;
    cin >> ncgpa;
    student *temp = sfirst;
    while (temp->cgpa != ncgpa)
    {
      temp = temp->next;
    }
    temp->cgpa = ncgpa;
    cout << endl
         << "CGPA Updated";
    display_student();

    break;
  }
  }
}

void dis_name(string cname)
{
  cout << endl;
  student *p = sfirst;
  while (p)
  {

    if (p->name == cname)
    {
      cout << p->name << " ";
      cout << p->roll << " ";
      cout << p->b_id << " ";
      cout << p->cgpa << " ";
    }
    p = p->next;
  }
  cout << endl
       << endl
       << "Press any key";
  getch();
}

void dis_branch_uni(int uid)
{
  cout << endl;
  branch *p = bfirst;
  while (p)
  {
    if (p->u_id == uid)
    {
      cout << p->b_name << " ";
    }

    cout << endl;
    p = p->next;
  }
  cout << endl
       << endl
       << "Press any key";
  getch();
}

void search(string name)
{
}

void search_all(string name)
{

  cout << endl
       << "Students :" << endl;
  transform(name.begin(), name.end(), name.begin(), ::toupper);
  cout << endl;
  student *p = sfirst;
  while (p)
  {

    if (p->name == name)
    {
      cout << p->name << " ";
      cout << p->roll << " ";
      cout << p->b_id << " ";
      cout << p->cgpa << " ";
    }
    p = p->next;
  }

  cout << endl
       << "University :" << endl;
  university *p1 = ufirst;
  while (p1)
  {

    if (p1->u_name == name)
    {
      cout << p1->u_name << " ";
      cout << p1->u_id << " ";
      cout << p1->u_loc << " ";
      cout << p1->u_year << " ";
    }
    p1 = p1->next;
  }
  cout << endl
       << endl
       << "Press any key";
  getch();
}

//no

int main()
{
  char cont = 'y';
  int choise = 0;
  while (cont == 'y')
  {
  main:
    system("cls");
    cout << endl
         << "Main Menu";
    cout << endl
         << "1. Student Database";
    cout << endl
         << "2. University Database";
    cout << endl
         << "3. Branch Database";
    cout << endl
         << "4. Display All Data";
    cout << endl
         << "5. Search";
    cout << endl
         << "Chose option : ";
    cin >> choise;
    switch (choise)
    {
    case 1:
    {
      system("cls");
      char y1 = 'y';
      int c1 = 0;
      while (y1 == 'y')
      {
      smain:
        cout << endl
             << "Student Database";
        cout << endl
             << "1. Insert";
        cout << endl
             << "2. Delete";
        cout << endl
             << "3. Modify";
        cout << endl
             << "4. Search";
        cout << endl
             << "5. Display";
        cout << endl
             << "6. Goto main Menu";
        cout << endl
             << "Chose option : ";
        cin >> c1;
        switch (c1)
        {
        case 1:
        {
          int roll, bid, cgpa;
          string name;
          cout << endl
               << "Enter name : ";
          cin >> name;
          cout << endl
               << "Enter Roll : ";
          cin >> roll;
          cout << endl
               << "Enter Branch ID : ";
          cin >> bid;
          cout << endl
               << "Enter CGPA : ";
          cin >> cgpa;
          int c = 0;
          c = check_bid(bid);
          if (c > 0)
          {

            int d = 0;
            d = check_roll(roll);
            if (d == 0)
            {
              insert_student(name, roll, bid, cgpa);
            }
            else
            {
              cout << "Roll no. already exist . (Press any key)" << endl;
              getch();
              goto smain;
            }
          }
          else
          {
            cout << "Branch does not exist . (Press any key)" << endl;
            getch();
            goto smain;
          }

          break;
        }
        case 2:
        {

          cout << endl
               << "Choose deleting Parameter";
          cout << endl
               << "1. Name";
          cout << endl
               << "2. roll no.";
          cout << endl
               << "Choose(1-2)";
          int dc = 0;
          cin >> dc;
          switch (dc)
          {
          case 1:
          {
            cout << "Enter name : ";
            string name1;
            cin >> name1;
            del_name(name1);
            goto smain;
            break;
          }
          case 2:
          {
            cout << "Enter roll no. : ";
            int roll1;
            cin >> roll1;
            del_roll(roll1);
            goto smain;
            break;
          }
          default:
          {

            goto smain;
            break;
          }
          }

          break;
        }
        case 3:
        {

          cout << endl
               << "Choose Modifying Parameter";
          cout << endl
               << "1. Name";
          cout << endl
               << "2. roll no.";
          cout << endl
               << "Choose(1-2)";
          int dc = 0;
          cin >> dc;
          switch (dc)
          {
          case 1:
          {
            cout << "Enter name : ";
            string name1;
            cin >> name1;
            mod_name(name1);
            goto smain;
            break;
          }
          case 2:
          {
            cout << "Enter roll no. : ";
            int roll1;
            cin >> roll1;
            //mod_roll(roll1);
            goto smain;
            break;
          }
          default:
          {

            goto smain;
            break;
          }
          }
          break;
        }
        case 4:
        {
          cout << "Enter Name of the Student : " << endl;
          string name;
          cin >> name;
          search(name);

          break;
        }
        case 5:
        {
          cout << "1. Display By College name" << endl;
          cout << "2.Display all students" << endl;
          cout << "Choose (1/2)" << endl;
          int ans = 0;
          cin >> ans;
          switch (ans)
          {
          case 1:
          {
            cout << "Enter College Name : " << endl;
            string cname;
            dis_name(cname);
            break;
          }
          case 2:
          {
            display_student();
            break;
          }
          default:
          {
            goto smain;
            break;
          }
          }

          break;
        }
        case 6:
        {
          goto main;
          break;
        }
        default:
        {
          goto main;
          break;
        }
        }

        cout << "want to continue(y/n) ?" << endl;
        cin >> y1;
      }

      break;
    }
    case 2:
    {
      system("cls");
      char y2 = 'y';
      int c3;
      while (y2 == 'y')
      {
        int uid, year;
        string uname, uloc;
      umain:
        cout << endl
             << "University Database";
        cout << endl
             << "1. Insert data";
        cout << endl
             << "2. Delete Data";
        cout << endl
             << "3. modify Data";
        cout << endl
             << "4. Display University data";
        cout << endl
             << "5. Display all branch in a university";
        cout << endl
             << "6. Go to main menu";
        cout << endl
             << "Enter Choise(1-5) : ";
        cin >> c3;
        switch (c3)
        {
        case 1:
        {
          int uid, year;
          string uname, uloc;
          cout << endl
               << "1. Enter University name : ";
          cin >> uname;
          cout << endl
               << "1. Enter University ID : ";
          cin >> uid;
          cout << endl
               << "1. Enter Year of Start : ";
          cin >> year;
          cout << endl
               << "1. Enter Location : ";
          cin >> uloc;
          int c = check_uid(uid);
          if (c > 0)
          {
            cout << endl
                 << "University ID already exist ";
            goto umain;
          }
          else
          {

            insert_u(uname, uid, year, uloc);
          }
          break;
        }
        case 2:
        {
          int uid = 0;
          cout << endl
               << "Enter University ID";
          cin >> uid;
          int c = check_uid(uid);
          if (c > 0)
          {
            delete_u(uid);
            goto umain;
          }
          else
          {

            cout << endl
                 << "University does not exist" << endl;
            goto umain;
          }

          break;
        }
        case 3:
        {

          break;
        }
        case 4:
        {
          display_university();
          break;
        }
        case 5:
        {
          cout << endl
               << "Enter University ID : ";
          int uid;
          cin >> uid;
          dis_branch_uni(uid);
          break;
        }
        case 6:
        {
          goto main;
          break;
        }
        default:
        {
          goto main;
          break;
        }
        }

        cout << endl
             << "Would you like to continue (y/n)";
        cin >> y2;
      }

      break;
    }
    case 3:
    {
      system("cls");
      char y3 = 'y';
      while (y3 == 'y')
      {
      bmain:
        cout << endl
             << "Branch Database :";
        cout << endl
             << "1. Add Branch";
        cout << endl
             << "2. Delete Branch";
        cout << endl
             << "3. Display Branch";
        cout << endl
             << "4. Go to main Menu";
        cout << endl
             << "Enter Choise (1-4)";
        int ans = 0;
        cin >> ans;
        switch (ans)
        {
        case 1:
        {
          cout << endl;
          int bid, uid;
          string bname;
          cout << endl
               << "Enter branch name : ";
          cin >> bname;
          cout << endl
               << "Enter branch ID : ";
          cin >> bid;
          cout << endl
               << "Enter University ID of respective branch : ";
          cin >> uid;
          int c = 0, d = 0;
          c = check_branch(bid);
          d = check_uid(uid);
          if (c > 0)
          {
            cout << endl
                 << "Branch already exist ";
            goto bmain;
          }
          else
          {
            if (d > 0)
            {
              insert_b(bname, bid, uid);
            }
            else
            {
              cout << endl
                   << "University do not Exist";
              goto bmain;
            }
          }

          break;
        }
        case 2:
        {

          break;
        }
        case 3:
        {
          display_branch();
          break;
        }
        case 4:
        {
          goto main;
          break;
        }
        default:
        {
          goto main;
          break;
        }
        }

        cout << endl
             << "Would you like to contiue ? (y/n)";
        cin >> y3;
      }

      break;
    }
    case 4:
    {
      cout << endl
           << "Student Details";
      display_student();
      cout << endl;
      cout << endl
           << "University Details";
      display_university();
      cout << endl;
      cout << endl
           << "Branch Details";
      display_branch();

      break;
    }
    case 5:
    {

      cout << endl
           << "Enter Student/University Name : ";
      string name;
      cin >> name;
      search_all(name);
      break;
    }

    default:
    {
      exit(0);
      break;
    }
    }
  }
  //node *q;
  //p=q;

  int a = 10;
  return 0;
}