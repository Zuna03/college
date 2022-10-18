#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

struct node_198
{
  int row_198, col_198, data_198;
  struct node_198 *next_198;
};

struct node_198 *matrix_to_sparse_198(int **a, int n, int m)
{
  struct node_198 *head_198 = (struct node_198 *)malloc(sizeof(struct node_198));
  head_198->row_198 = n;
  head_198->col_198 = m;
  head_198->data_198 = 0;
  head_198->next_198 = NULL;
  struct node_198 *temp_198 = head_198;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (a[i][j] != 0)
      {
        struct node_198 *new_198 = (struct node_198 *)malloc(sizeof(struct node_198));
        new_198->row_198 = i;
        new_198->col_198 = j;
        new_198->data_198 = a[i][j];
        new_198->next_198 = NULL;
        temp_198->next_198 = new_198;
        temp_198 = temp_198->next_198;
        head_198->data_198++;
      }
    }
  }

  return head_198;
}

void print_sparse_198(struct node_198 *head_198)
{
  struct node_198 *temp_198 = head_198;
  while (temp_198 != NULL)
  {
    printf("%d %d %d\n", temp_198->row_198, temp_198->col_198, temp_198->data_198);
    temp_198 = temp_198->next_198;
  }
}

struct node_198 *add_sparse_198(struct node_198 *sparse1, struct node_198 *sparse2)
{
  struct node_198 *ans_198 = (struct node_198 *)malloc(sizeof(struct node_198));
  ans_198->row_198 = sparse1->row_198;
  ans_198->col_198 = sparse1->col_198;
  ans_198->data_198 = 0;
  ans_198->next_198 = NULL;

  struct node_198 *temp_198 = ans_198;
  struct node_198 *temp1_198 = sparse1->next_198;
  struct node_198 *temp2_198 = sparse2->next_198;

  while (temp1_198 != NULL && temp2_198 != NULL)
  {
    struct node_198 *new_198 = (struct node_198 *)malloc(sizeof(struct node_198));
    if (temp1_198->row_198 < temp2_198->row_198)
    {
      new_198->row_198 = temp1_198->row_198;
      new_198->col_198 = temp1_198->col_198;
      new_198->data_198 = temp1_198->data_198;
      new_198->next_198 = NULL;
      temp_198->next_198 = new_198;
      temp_198 = temp_198->next_198;
      temp1_198 = temp1_198->next_198;
      continue;
    }
    else if (temp2_198->row_198 < temp1_198->row_198)
    {
      new_198->row_198 = temp2_198->row_198;
      new_198->col_198 = temp2_198->col_198;
      new_198->data_198 = temp2_198->data_198;
      new_198->next_198 = NULL;
      temp_198->next_198 = new_198;
      temp_198 = temp_198->next_198;
      temp2_198 = temp2_198->next_198;
      continue;
    }
    else if (temp1_198->row_198 == temp2_198->row_198)
    {
      if (temp1_198->col_198 < temp2_198->col_198)
      {
        new_198->row_198 = temp1_198->row_198;
        new_198->col_198 = temp1_198->col_198;
        new_198->data_198 = temp1_198->data_198;
        new_198->next_198 = NULL;
        temp_198->next_198 = new_198;
        temp_198 = temp_198->next_198;
        temp1_198 = temp1_198->next_198;
        continue;
      }
      else if (temp2_198->col_198 < temp1_198->col_198)
      {
        new_198->row_198 = temp2_198->row_198;
        new_198->col_198 = temp2_198->col_198;
        new_198->data_198 = temp2_198->data_198;
        new_198->next_198 = NULL;
        temp_198->next_198 = new_198;
        temp_198 = temp_198->next_198;
        temp2_198 = temp2_198->next_198;
        continue;
      }
    }
    new_198->row_198 = temp1_198->row_198;
    new_198->col_198 = temp1_198->col_198;
    new_198->data_198 = temp1_198->data_198 + temp2_198->data_198;
    new_198->next_198 = NULL;
    temp_198->next_198 = new_198;
    temp_198 = temp_198->next_198;
    temp1_198 = temp1_198->next_198;
    temp2_198 = temp2_198->next_198;
  }
  while (temp1_198 != NULL)
  {
    struct node_198 *new_198 = (struct node_198 *)malloc(sizeof(struct node_198));
    new_198->row_198 = temp1_198->row_198;
    new_198->col_198 = temp1_198->col_198;
    new_198->data_198 = temp1_198->data_198;
    new_198->next_198 = NULL;
    temp_198->next_198 = new_198;
    temp_198 = temp_198->next_198;
    temp1_198 = temp1_198->next_198;
  }
  while (temp2_198 != NULL)
  {
    struct node_198 *new_198 = (struct node_198 *)malloc(sizeof(struct node_198));
    new_198->row_198 = temp2_198->row_198;
    new_198->col_198 = temp2_198->col_198;
    new_198->data_198 = temp2_198->data_198;
    new_198->next_198 = NULL;
    temp_198->next_198 = new_198;
    temp_198 = temp_198->next_198;
    temp2_198 = temp2_198->next_198;
  }

  return ans_198;
}

int main()
{
  int n, m;
  printf("Enter the number of rows :- ");
  scanf("%d", &n);

  printf("Enter the number of columns :- ");
  scanf("%d", &m);

  int **a = (int **)malloc(sizeof(int *) * n);
  for (int i = 0; i < n; i++)
    a[i] = (int *)malloc(sizeof(int) * m);

  int **b = (int **)malloc(sizeof(int *) * n);
  for (int i = 0; i < n; i++)
    b[i] = (int *)malloc(sizeof(int) * m);

  printf("Enter the elements for first 2d array :-\n");

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
      scanf("%d", &a[i][j]);
  }

  printf("Enter the elements for second 2d array :-\n");

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
      scanf("%d", &b[i][j]);
  }

  struct node_198 *sparse1 = matrix_to_sparse_198(a, n, m);
  struct node_198 *sparse2 = matrix_to_sparse_198(b, n, m);

  printf("First sparse Matrix :-\n");
  print_sparse_198(sparse1);

  printf("Second sparse Matrix :-\n");
  print_sparse_198(sparse2);

  struct node_198 *result = add_sparse_198(sparse1, sparse2);
  printf("The addition result is :-\n");
  print_sparse_198(result);

  return 0;
}