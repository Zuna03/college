printf("Enter row of  first matrix \n");
    int row1_198;
    scanf("%d", &row1_198);
    printf("Enter column of  matrix \n");
    int column1_198;
    scanf("%d", &column1_198);

    int arr1_198[row1_198][column1_198];

    printf("Enter elements of first matrix \n");
    for (int i = 0; i < row1_198; i++)
    {
        for (int j = 0; j < column1_198; j++)
        {
            scanf("%d", &arr1_198[i][j]);
        }
    }

    printf("Enter row of  second matrix \n");
    int row2_198;
    scanf("%d", &row2_198);
    printf("Enter column of  second matrix \n");
    int column2_198;
    scanf("%d", &column2_198);

    int arr2_198[row2_198][column2_198];

    printf("Enter elements of second matrix \n");
    for (int i = 0; i < row2_198; i++)
    {
        for (int j = 0; j < column2_198; j++)
        {
            scanf("%d", &arr2_198[i][j]);
        }
    }