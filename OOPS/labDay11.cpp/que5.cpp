#include <bits/stdc++.h>
using namespace std;

int main()
{
        ifstream file_198;
        file_198.open("que5.txt");
        char ch;
        file_198.seekg(0, ios::beg);

        int count_ch_198 = 0, count_w_198 = 1, count_l_198 = 0, count_u_198 = 0,
            count_li_198 = 1, count_d_198 = 0, count_s_198 = 0, count_le_198 = 0;
        string line;

        if (!file_198)
        {
                cout << "Error in opening source file_198..!!";
        }

        while (file_198.get(ch))
        {
                if (ch >= '1' && ch <= '9') //digits
                {
                        count_ch_198++;
                        count_d_198++;
                }

                else if (ch >= 'a' && ch <= 'z') //lower case
                {
                        count_ch_198++;
                        count_l_198++;
                        count_le_198++;
                }

                else if (ch >= 'A' && ch <= 'Z') //upper case
                {
                        count_ch_198++;
                        count_u_198++;
                        count_le_198++;
                }

                else if (ch == ' ' || ch == '\t')
                        count_w_198++;

                else if (ch == '\n')
                {
                        count_li_198++;
                        count_w_198++;
                }

                else
                {
                        count_ch_198++;
                        count_s_198++;
                }
        }

        cout << "\n No. of digits in a File : " << count_d_198;
        cout << "\n No. of Characters in a File : " << count_ch_198;
        cout << "\n No. of Upper-case Characters in a File : " << count_u_198;
        cout << "\n No. of Lower-case Characters in a File : " << count_l_198;
        cout << "\n No. of Letters in a File : " << count_le_198;
        cout << "\n No. of Special Characters in a File : " << count_s_198;
        cout << "\n No. of words in a File : " << count_w_198;
        cout << "\n No. of lines in a File : " << count_li_198;

        file_198.close();

        return 0;
}
