#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
struct student
{
    int roll;
    char name[20];
    int b_id;
    float cgpa;
    struct student *next;
};
struct head_node
{
    int data;
    struct student *next;
};
struct head_node *head;
struct head_node *head_temp;
struct university
{
    int univ_id;
    char univ_name[20];
    char univ_loc[20];
    int year;
    struct university *next;
};
struct university *start1 = NULL;
struct university *start1_temp = NULL;
struct branch
{
    int b_id;
    int univ_id;
    char b_name[20];
    struct branch *next;
};
struct branch *start2 = NULL;
struct branch *start2_temp = NULL;

void insert_student(struct head_node **he, int r, char n[20], int b, float c)
{
    struct student *new;
    new = (struct student *)malloc(sizeof(struct student));
    new->roll = r;
    strcpy(new->name, n);
    new->b_id = b;
    new->cgpa = c;
    new->next = NULL;
    if ((*he)->next == NULL)
    {
        (*he)->next = new;
    }
    else
    {
        struct student *temp;
        temp = (*he)->next;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new;
    }
}
void insertUniv(struct university **st1, int u, char un[20], char ul[20], int y)
{
    struct university *new1;
    new1 = (struct university *)malloc(sizeof(struct university));
    new1->univ_id = u;
    strcpy(new1->univ_name, un);
    strcpy(new1->univ_loc, ul);
    new1->year = y;
    new1->next = NULL;
    if (*st1 == NULL)
    {
        *st1 = new1;
    }
    else
    {
        struct university *temp;
        temp = *st1;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new1;
    }
}
void insertBranch(struct branch **st2, int b, int u, char bn[20])
{
    struct branch *new2;
    new2 = (struct branch *)malloc(sizeof(struct branch));
    new2->b_id = b;
    new2->univ_id = u;
    strcpy(new2->b_name, bn);
    new2->next = NULL;
    if (*st2 == NULL)
    {
        *st2 = new2;
    }
    else
    {
        struct branch *temp;
        temp = *st2;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new2;
    }
}
void check_unique_id()
{
    struct student *temp, *t;
    t = temp = (head)->next;
    struct university *uemp, *u;
    uemp = u = start1;
    struct branch *bemp, *b;
    bemp = b = start2;
    while (temp != NULL && uemp != NULL && bemp != NULL)
    {
        while (t->next != NULL && u->next != NULL && b->next != NULL)
        {
            if (temp->roll == t->next->roll)
            {
                printf("\nduplicate roll no. should not be allowed.");
                printf("\npls change the roll no. of %s or %s.", temp->name, t->next->name);
            }
            if (uemp->univ_id == u->next->univ_id || bemp->univ_id == b->next->univ_id)
            {
                printf("\nduplicate university ID should not be allowed.");
                printf("\npls change the university ID of %s or %s.", temp->name, t->next->name);
            }
            if (temp->b_id == t->next->b_id || bemp->b_id == b->next->b_id)
            {
                printf("\nduplicate branch ID should not be allowed.");
                printf("\npls change the branch ID of %s or %s.", temp->name, t->next->name);
            }
            t = t->next;
            u = u->next;
            b = b->next;
        }
        temp = temp->next;
        uemp = uemp->next;
        bemp = bemp->next;
    }
}
void display(struct head_node **he, struct university **st1, struct branch **st2)
{
    printf("\nstudent information: \n\n");
    printf("ROLL\t\tNAME\tCGPA\tB id\tBRANCH\tUn id\tUniversity\t\tLocation\tYear\n");
    printf("------------------------------------------------------------------------------------------------------\n");
    struct student *temp;
    temp = (*he)->next;
    struct university *t1;
    t1 = *st1;
    struct branch *t2;
    t2 = *st2;
    while (temp != NULL)
    {
        while ((t2 != NULL) && (temp->b_id == t2->b_id))
        {
            while ((t1 != NULL) && (t2->univ_id == t1->univ_id))
            {
                /**********************************************************************************************/
                char *word = (char *)malloc(strlen(temp->name) * sizeof(char));
                strcpy(word, temp->name);
                int i = 0;
                for (i; word[i]; i++)
                {
                    if (word[i] >= 97 && word[i] <= 122)
                        word[i] -= 32;
                }
                //to convert student name into capital letters
                char *word1 = (char *)malloc(strlen(t2->b_name) * sizeof(char));
                strcpy(word1, t2->b_name);
                int j = 0;
                for (j; word1[j]; j++)
                {
                    if (word1[j] >= 97 && word1[j] <= 122)
                        word1[j] -= 32;
                }
                //to convert branch name into capital letters
                char *word2 = (char *)malloc(strlen(t1->univ_name) * sizeof(char));
                strcpy(word2, t1->univ_name);
                int k = 0;
                for (k; word2[k]; k++)
                {
                    if (word2[k] >= 97 && word2[k] <= 122)
                        word2[k] -= 32;
                }
                //to convert university name into capital letters
                /*********************************************************************************************/
                printf("%d%17s%9.3f%7d%10s%5d%15s%22s%12d\n", temp->roll, word, temp->cgpa, t2->b_id, word1, t1->univ_id, word2, t1->univ_loc, t1->year);
                t1 = t1->next;
            }
            t2 = t2->next;
        }
        temp = temp->next;
    }
}
void display_college()
{
    int t = 1;
    printf("ROLL\t\tNAME\tCGPA\tB id\tBRANCH\tUn id\tUniversity\t\tLocation\tYear\n");
    printf("------------------------------------------------------------------------------------------------------\n");
    struct student *temp;
    temp = (head)->next;
    struct university *t1;
    t1 = start1;
    struct branch *t2;
    t2 = start2;
    while (temp != NULL)
    {
        while ((t2 != NULL) && (temp->b_id == t2->b_id))
        {
            while ((t1 != NULL) && (t2->univ_id == t1->univ_id))
            {
                /**********************************************************************************************/
                char *word = (char *)malloc(strlen(temp->name) * sizeof(char));
                strcpy(word, temp->name);
                int i = 0;
                for (i; word[i]; i++)
                {
                    if (word[i] >= 97 && word[i] <= 122)
                        word[i] -= 32;
                }
                //to convert student name into capital letters
                char *word1 = (char *)malloc(strlen(t2->b_name) * sizeof(char));
                strcpy(word1, t2->b_name);
                int j = 0;
                for (j; word1[j]; j++)
                {
                    if (word1[j] >= 97 && word1[j] <= 122)
                        word1[j] -= 32;
                }
                //to convert branch name into capital letters
                char *word2 = (char *)malloc(strlen(t1->univ_name) * sizeof(char));
                strcpy(word2, t1->univ_name);
                int k = 0;
                for (k; word2[k]; k++)
                {
                    if (word2[k] >= 97 && word2[k] <= 122)
                        word2[k] -= 32;
                }
                //to convert university name into capital letters
                /*********************************************************************************************/
                if ((strcmp(t1->univ_name, "KIIT") == 0) || (strcmp(t1->univ_name, "kiit") == 0))
                {
                    printf("%d%17s%9.3f%7d%10s%5d%15s%22s%12d\n", temp->roll, word, temp->cgpa, t2->b_id, word1, t1->univ_id, word2, t1->univ_loc, t1->year);
                    t = 2;
                }
                t1 = t1->next;
            }
            t2 = t2->next;
        }
        temp = temp->next;
    }
    if (t == 1)
    {
        printf("\nNO DATA IS AVAILABLE FOR KIIT UNIVERSITY.");
    }
}
void display_college_branch()
{
    int t = 1;
    printf("ROLL\t\tNAME\tCGPA\tB id\tBRANCH\tUn id\tUniversity\t\tLocation\tYear\n");
    printf("------------------------------------------------------------------------------------------------------\n");
    struct student *temp;
    temp = (head)->next;
    struct university *t1;
    t1 = start1;
    struct branch *t2;
    t2 = start2;
    while (temp != NULL)
    {
        while ((t2 != NULL) && (temp->b_id == t2->b_id))
        {
            while ((t1 != NULL) && (t2->univ_id == t1->univ_id))
            {
                /**********************************************************************************************/
                char *word = (char *)malloc(strlen(temp->name) * sizeof(char));
                strcpy(word, temp->name);
                int i = 0;
                for (i; word[i]; i++)
                {
                    if (word[i] >= 97 && word[i] <= 122)
                        word[i] -= 32;
                }
                //to convert student name into capital letters
                char *word1 = (char *)malloc(strlen(t2->b_name) * sizeof(char));
                strcpy(word1, t2->b_name);
                int j = 0;
                for (j; word1[j]; j++)
                {
                    if (word1[j] >= 97 && word1[j] <= 122)
                        word1[j] -= 32;
                }
                //to convert branch name into capital letters
                char *word2 = (char *)malloc(strlen(t1->univ_name) * sizeof(char));
                strcpy(word2, t1->univ_name);
                int k = 0;
                for (k; word2[k]; k++)
                {
                    if (word2[k] >= 97 && word2[k] <= 122)
                        word2[k] -= 32;
                }
                //to convert university name into capital letters
                /*********************************************************************************************/
                if (((strcmp(t1->univ_name, "KIIT") == 0) || (strcmp(t1->univ_name, "kiit") == 0)) && ((strcmp(t2->b_name, "CSE") == 0) || (strcmp(t2->b_name, "cse") == 0)))
                {
                    printf("%d%17s%9.3f%7d%10s%5d%15s%22s%12d\n", temp->roll, word, temp->cgpa, t2->b_id, word1, t1->univ_id, word2, t1->univ_loc, t1->year);
                    t = 2;
                }
                t1 = t1->next;
            }
            t2 = t2->next;
        }
        temp = temp->next;
    }
    if (t == 1)
    {
        printf("\nNO DATA IS AVAILABLE FOR KIIT UNIVERSITY FOR CSE BRANCH.");
    }
}
void branch_list()
{
    int x = 0;
    char un[20];
    printf("\nenter the university name: ");
    scanf("%s", un);
    struct university *t1;
    t1 = start1;
    struct branch *t2;
    t2 = start2;
    printf("\nlist of branches avilable in %s university: ", un);
    while (t2 != NULL)
    {
        while ((t1 != NULL) && (t2->univ_id == t1->univ_id))
        {
            if (strcmp(t1->univ_name, un) == 0)
            {
                ++x;
                printf("\n%d. %s", x, t2->b_name);
            }
            t1 = t1->next;
        }
        t2 = t2->next;
    }
    if (x == 0)
    {
        printf("\nNO BRANCH IS AVAILABLE FOR %s UNIVERSITY\n", un);
    }
}
void sorted_year()
{
    struct university *t1, *t2, *t3;
    t2 = start1;
    printf("Un id\tUniversity\t\tLocation\tYear\n");
    printf("------------------------------------------------------------------------------------------------------\n");
    while (t2 != NULL)
    {
        t3 = t2;
        while (t3 != NULL)
        {
            if (t2->year > t3->year)
            {
                int temp1 = t2->year;
                t2->year = t3->year;
                t3->year = temp1;
                int temp2 = t2->univ_id;
                t2->univ_id = t3->univ_id;
                t3->univ_id = temp2;
                char temp3[20];
                strcpy(temp3, t2->univ_name);
                strcpy(t2->univ_name, t3->univ_name);
                strcpy(t3->univ_name, temp3);
                char temp4[20];
                strcpy(temp4, t2->univ_loc);
                strcpy(t2->univ_loc, t3->univ_loc);
                strcpy(t3->univ_loc, temp4);
            }
            t3 = t3->next;
        }
        t2 = t2->next;
    }
    t1 = start1;
    while (t1 != NULL)
    {
        printf("%d%15s%22s%12d\n", t1->univ_id, t1->univ_name, t1->univ_loc, t1->year);
        t1 = t1->next;
    }
    free(t1);
    free(t2);
    free(t3);
}
void subString()
{
    int x = 1, y = 0, z = 0;
    char n[20];
    printf("\nwhat you want to print:\n1.For students' list type <STUDENT>\n2. For universities' list type <UNIVERSITY>\n");
    scanf("%s", n);
    struct student *temp;
    temp = (head)->next;
    struct university *t1;
    t1 = start1;
    if ((strcmp("student", n) == 0) || (strcmp("STUDENT", n) == 0))
    {
        ++x;
        printf("\nstudents' list: \n");
        while (temp != NULL)
        {
            printf("%d.%s", ++y, temp->name);
            printf("\n");
            temp = temp->next;
        }
    }
    if ((strcmp("university", n) == 0) || (strcmp("UNIVERSITY", n) == 0))
    {
        ++x;
        printf("\nuniversities' list: \n");
        while (t1 != NULL)
        {
            printf("%d.%s", ++z, t1->univ_name);
            printf("\n");
            t1 = t1->next;
        }
    }
    if (x == 1)
    {
        printf("\ndata for the entered name substring is NOT found.");
    }
}
void deleteStudent(struct head_node **he, int r, int *ro, char na[20], int *bi, float *cg)
{
    struct student *st, *s, *s1;
    st = (*he)->next;
    s = st;
    if (st->roll == r)
    {
        st = st->next;
        *ro = s->roll;
        strcpy(na, s->name);
        *bi = s->b_id;
        *cg = s->cgpa;
        free(s);
    }
    else
    {
        while (s->roll != r)
        {
            s1 = s;
            s = s->next;
        }
        if (s == NULL)
        {
            printf("\nitem is not found.");
        }
        else
        {
            s1->next = s->next;
            *ro = s->roll;
            strcpy(na, s->name);
            *bi = s->b_id;
            *cg = s->cgpa;
            free(s);
        }
    }
}
void deleteUniv(struct university **st, int id, int *ui, char un[20], char ul[20], int *ye)
{
    struct university *t, *st1;
    st1 = *st;
    if ((*st)->univ_id == id)
    {
        (*st) = (*st)->next;
        *ui = st1->univ_id;
        strcpy(un, st1->univ_name);
        strcpy(ul, st1->univ_loc);
        *ye = st1->year;
        free(st1);
    }
    else
    {
        while (st1->univ_id != id)
        {
            t = st1;
            st1 = st1->next;
        }
        if (st1 == NULL)
        {
            printf("\nitem is not found.");
        }
        else
        {
            t->next = st1->next;
            *ui = st1->univ_id;
            strcpy(un, st1->univ_name);
            strcpy(ul, st1->univ_loc);
            *ye = st1->year;
            free(st1);
        }
    }
}
void deleteBranch(struct branch **st, int id, int *bd, int *ud, char bn[20])
{
    struct branch *t, *st2;
    st2 = *st;
    if ((*st)->b_id == id)
    {
        (*st) = (*st)->next;
        *bd = st2->b_id;
        *ud = st2->univ_id;
        strcpy(bn, st2->b_name);
        free(st2);
    }
    else
    {
        while (st2->b_id != id)
        {
            t = st2;
            st2 = st2->next;
        }
        if (st2 == NULL)
        {
            printf("\nitem is not found.");
        }
        else
        {
            t->next = st2->next;
            *bd = st2->b_id;
            *ud = st2->univ_id;
            strcpy(bn, st2->b_name);
            free(st2);
        }
    }
}
void delete_cgpa(struct head_node **he, struct head_node **he_temp, struct university **st1, struct university **st1_temp, struct branch **st2, struct branch **st2_temp)
{
    struct student *temp;
    temp = (*he)->next;
    struct university *t1;
    t1 = *st1;
    struct branch *t2;
    t2 = *st2;
    struct student *pemp;
    pemp = (*he_temp)->next;
    struct university *p1;
    p1 = *st1_temp;
    struct branch *p2;
    p2 = *st2_temp;
    int ro, bi, ui, ye, bd, ud;
    char na[20], un[20], ul[20], bn[20];
    float cg;
    while (temp != NULL)
    {
        while ((t2 != NULL) && (temp->b_id == t2->b_id))
        {
            while ((t1 != NULL) && (t2->univ_id == t1->univ_id))
            {
                if (temp->cgpa < 6.0)
                {
                    deleteStudent(he, temp->roll, &ro, na, &bi, &cg);
                    deleteUniv(st1, t1->univ_id, &ui, un, ul, &ye);
                    deleteBranch(st2, t2->b_id, &bd, &ud, bn);
                    insert_student(he_temp, ro, na, bi, cg);
                    insertUniv(st1_temp, ui, un, ul, ye);
                    insertBranch(st2_temp, bd, ud, bn);
                }
                t1 = t1->next;
            }
            t2 = t2->next;
        }
        temp = temp->next;
    }
    while (pemp != NULL)
    {
        while ((p2 != NULL) && (pemp->b_id == p2->b_id))
        {
            while ((p1 != NULL) && (p2->univ_id == p1->univ_id))
            {
                if (pemp->cgpa >= 6.0)
                {
                    deleteStudent(he_temp, pemp->roll, &ro, na, &bi, &cg);
                    deleteUniv(st1_temp, p1->univ_id, &ui, un, ul, &ye);
                    deleteBranch(st2_temp, p2->b_id, &bd, &ud, bn);
                    insert_student(he, ro, na, bi, cg);
                    insertUniv(st1, ui, un, ul, ye);
                    insertBranch(st2, bd, ud, bn);
                }
                p1 = p1->next;
            }
            p2 = p2->next;
        }
        pemp = pemp->next;
    }
    display(he, st1, st2);
}
void delete_node()
{
    int no;
    printf("\nenter the student's roll no. whose you want to delete: ");
    scanf("%d", &no);
    struct student *temp;
    temp = (head)->next;
    struct university *t1;
    t1 = start1;
    struct branch *t2;
    t2 = start2;
    int ro, bi, ui, ye, bd, ud;
    char na[20], un[20], ul[20], bn[20];
    float cg;
    while (temp != NULL)
    {
        while ((t2 != NULL) && (temp->b_id == t2->b_id))
        {
            while ((t1 != NULL) && (t2->univ_id == t1->univ_id))
            {
                if (temp->roll == no)
                {
                    deleteStudent(&head, temp->roll, &ro, na, &bi, &cg);
                    deleteUniv(&start1, t1->univ_id, &ui, un, ul, &ye);
                    deleteBranch(&start2, t2->b_id, &bd, &ud, bn);
                }
                t1 = t1->next;
            }
            t2 = t2->next;
        }
        temp = temp->next;
    }
    printf("\nlist after deleteion: ");
    display(&head, &start1, &start2);
}
void add_node(struct head_node **he, struct university **st1, struct branch **st2)
{
    int ro, bi, ui, ye;
    char na[20], un[20], ul[20], bn[20];
    float cg;
    printf("\nenter student's roll no.,name,cgpa respactively: ");
    scanf("%d%s%f", &ro, na, &cg);
    printf("\nenter student's university id,university name,university location,year respactively: ");
    scanf("%d%s%s%d", &ui, un, ul, &ye);
    printf("\nenter student's branch id,branch name respectively: ");
    scanf("%d%s", &bi, bn);
    insert_student(he, ro, na, bi, cg);
    insertUniv(st1, ui, un, ul, ye);
    insertBranch(st2, bi, ui, bn);
    printf("\nlist after adding student's information: ");
    display(he, st1, st2);
    check_unique_id();
}
void update_node()
{
    int no;
    char fn[20];
    struct student *temp;
    temp = (head)->next;
    struct university *t1;
    t1 = start1;
    struct branch *t2;
    t2 = start2;
    int ro, bi, ui, ye, bd, ud;
    char na[20], un[20], ul[20], bn[20];
    float cg;
    printf("\nenter the student's roll no. whose you want to update: ");
    scanf("%d", &no);
    printf("\nwhat you want to update:\n1.For student's cgpa: Type<cgpa>\n2.For university details: Type<university>\n3.For branch details: Type<branch>\n");
    scanf("%s", fn);
    int uui, uye, ubi;
    char uun[20], uul[20], ubn[20];
    float ucg;
    while (temp != NULL)
    {
        while ((t2 != NULL) && (temp->b_id == t2->b_id))
        {
            while ((t1 != NULL) && (t2->univ_id == t1->univ_id))
            {
                if (temp->roll == no)
                {
                    if ((strcmp("cgpa", fn) == 0) || (strcmp("CGPA", fn) == 0))
                    {
                        printf("\nenter the updated cgpa of student: ");
                        scanf("%f", &ucg);
                        deleteStudent(&head, temp->roll, &ro, na, &bi, &cg);
                        deleteUniv(&start1, t1->univ_id, &ui, un, ul, &ye);
                        deleteBranch(&start2, t2->b_id, &bd, &ud, bn);
                        insert_student(&head, ro, na, bi, ucg);
                        insertUniv(&start1, ui, un, ul, ye);
                        insertBranch(&start2, bd, ud, bn);
                    }
                    else if ((strcmp("university", fn) == 0) || (strcmp("UNIVERSITY", fn) == 0))
                    {
                        printf("\nenter the updated university details of student:university id,name,location,year respectively: ");
                        scanf("%d%s%s%d", &uui, uun, uul, &uye);
                        deleteStudent(&head, temp->roll, &ro, na, &bi, &cg);
                        deleteUniv(&start1, t1->univ_id, &ui, un, ul, &ye);
                        deleteBranch(&start2, t2->b_id, &bd, &ud, bn);
                        insert_student(&head, ro, na, bi, cg);
                        insertUniv(&start1, uui, uun, uul, uye);
                        insertBranch(&start2, bd, uui, bn);
                    }
                    else if ((strcmp("branch", fn) == 0) || (strcmp("BRANCH", fn) == 0))
                    {
                        printf("\nenter the updated branch details of student:branch id,name respectively: ");
                        scanf("%d%s", &ubi, ubn);
                        deleteStudent(&head, temp->roll, &ro, na, &bi, &cg);
                        deleteUniv(&start1, t1->univ_id, &ui, un, ul, &ye);
                        deleteBranch(&start2, t2->b_id, &bd, &ud, bn);
                        insert_student(&head, ro, na, ubi, cg);
                        insertUniv(&start1, ui, un, ul, ye);
                        insertBranch(&start2, ubi, ud, ubn);
                    }
                }
                t1 = t1->next;
            }
            t2 = t2->next;
        }
        temp = temp->next;
    }
    printf("\nlist after update: ");
    display(&head, &start1, &start2);
}
int main()
{
    int ch;
    head = (struct head_node *)malloc(sizeof(struct head_node));
    head->data = 0;
    head->next = NULL;
    insert_student(&head, 205, "annie", 1001, 9.7);
    insertUniv(&start1, 561, "KIIT", "Bhubaneshwar", 2020);
    insertBranch(&start2, 1001, 561, "cse");
    //details of student 1
    insert_student(&head, 206, "banner", 1002, 9.3);
    insertUniv(&start1, 562, "KIIT", "Bhubaneshwar", 2019);
    insertBranch(&start2, 1002, 562, "cse");
    //details of student 2
    insert_student(&head, 207, "bond", 2001, 5.6);
    insertUniv(&start1, 763, "SRM", "chennai", 2021);
    insertBranch(&start2, 2001, 763, "eec");
    //details of student 3
    insert_student(&head, 208, "cheems", 1003, 9.8);
    insertUniv(&start1, 764, "SRM", "chennai", 2018);
    insertBranch(&start2, 1003, 764, "cse");
    //details of student 4
    insert_student(&head, 209, "chris", 4001, 8.5);
    insertUniv(&start1, 563, "KIIT", "Bhubaneshwar", 2022);
    insertBranch(&start2, 4001, 563, "civil");
    //details of student 5
    insert_student(&head, 210, "evans", 3001, 7.7);
    insertUniv(&start1, 861, "DTU", "delhi", 2017);
    insertBranch(&start2, 3001, 861, "mech");
    //details of student 6
    check_unique_id();
    printf("\npress <1> to display the entire student list/university list/branch list.");
    printf("\npress <2> to display the list of student reading in KIIT universit.");
    printf("\npress <3> to display the student details who are reading at KIIT university with CSE branch");
    printf("\npress <4> to display the list of branches avilable in any given university.");
    printf("\npress <5> to display the all student name/all university name for a given name substring entered by the user.");
    printf("\npress <6> to delete all students whose CGPA<6.0 and then display and bring them back to original student list if their CGPA>=6.0.");
    printf("\npress <7> to add new data in the students' database.");
    printf("\npress <8> to delete data from students' database.");
    printf("\npress <9> to update data in students' database.");
    printf("\npress <10> to display the university details in ascending order of their year of starting.");
    printf("\npress <11> to EXIT.");
    do
    {
        printf("\nenter your choice(01-11): ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            display(&head, &start1, &start2);
            break;
        case 2:
            printf("\nlist of students who are studied in kiit: \n");
            display_college();
            break;
        case 3:
            printf("\nlist of students who are studied in kiit with CSE branch: \n");
            display_college_branch();
            break;
        case 4:
            printf("\nlist of branches for the given university: \n");
            branch_list();
            break;
        case 5:
            printf("\nto Display the all Student name/ all University name for a given name substring entered by the user.");
            subString();
            break;
        case 6:
            head_temp = (struct head_node *)malloc(sizeof(struct head_node));
            head_temp->data = 0;
            head_temp->next = NULL;
            printf("\nto Delete all students whose CGPA<6.0 and store them in another list. They will come back to original student list if their CGPA>=6.0");
            delete_cgpa(&head, &head_temp, &start1, &start1_temp, &start2, &start2_temp);
            break;
        case 7:
            printf("\nto add new student's data: ");
            add_node(&head, &start1, &start2);
            break;
        case 8:
            printf("\nto delete student's data of respective entered roll no.: ");
            delete_node();
            break;
        case 9:
            printf("\nto update the list: ");
            update_node();
            break;
        case 10:
            printf("\nuniversity details in the ascending order of year of starting: \n");
            sorted_year();
            break;
        case 11:
            exit(0);
            break;
        default:
            printf("\nyou entered the wrong key.");
            break;
        }
    } while (ch != 11);
    return 0;
}