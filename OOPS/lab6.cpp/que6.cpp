#include <bits/stdc++.h>
using namespace std;
class cricketer_198
{
protected:
    string name_198;
    int age_198;
    int jerseyNo_198;
    int odiPlay_198;

public:
    void getData(string n_198, int a_198, int jn_198, int op_198)
    {
        name_198 = n_198;
        age_198 = a_198;
        jerseyNo_198 = jn_198;
        odiPlay_198 = op_198;
    }
    void display()
    {
        cout << "Name of cricketer :" << name_198 << endl;
        cout << "Age of cricketer  :" << age_198 << endl;
        cout << "Jersey no. of cricketer :" << jerseyNo_198 << endl;
        cout << "Number of ODIs played by cricketer :" << odiPlay_198 << endl;
    }
};
class batsman_198 : public cricketer_198
{
    int runsTaken_198;
    int numHalfCen_198;
    int numCen_198;
    int highScore_198;
    int numSix_198;
    int sixLong_198;
    float average_198;
    float strikeRate_198;
    char batHand_198;

public:
    void getBatsman(int rt_198, int nhc_198, int nc_198, int hs_198, int ns_198, int sl_198, float avg_198, float sr_198, char bh_198)
    {
        runsTaken_198 = rt_198;
        numHalfCen_198 = nhc_198;
        numCen_198 = nc_198;
        highScore_198 = hs_198;
        numSix_198 = ns_198;
        sixLong_198 = sl_198;
        average_198 = avg_198;
        strikeRate_198 = sr_198;
        batHand_198 = bh_198;
    }
    void display_198()
    {
        cricketer_198::display();
        cout << "Runs :- " << runsTaken_198 << "\n";
        cout << "Number of half centuries :- " << numHalfCen_198 << "\n";
        cout << "Number of centuries :- " << numCen_198 << "\n";
        cout << "Highest Score :- " << highScore_198 << "\n";
        cout << "Number of sixes :- " << numSix_198 << "\n";
        cout << "Longest Six :- " << sixLong_198 << "\n";
        cout << "Average :- " << average_198 << "\n";
        cout << "Strike Rate :- " << strikeRate_198 << "\n";
        cout << "Strong hand :- " << batHand_198 << "\n";
    }
};
class bowler_198 : public cricketer_198
{
    string type_198;
    int wickets_198;
    float runRate_198, speed_198, eco_198;
    char bowlHand_198;

public:
    void getbowler_198(string t_198, int w_198, float rr_198, float s_198, float e_198, char bh_198)
    {
        type_198 = t_198;
        wickets_198 = w_198;
        runRate_198 = rr_198;
        speed_198 = s_198;
        eco_198 = e_198;
        bowlHand_198 = bh_198;
    }
    void display_198()
    {
        cricketer_198::display();
        cout << "Type :- " << type_198 << "\n";
        cout << "Number of wickets :- " << wickets_198 << "\n";
        cout << "Average run rate :- " << runRate_198 << "\n";
        cout << "Average speed :- " << speed_198 << "\n";
        cout << "Economy :- " << eco_198 << "\n";
        cout << "Strong hand :- " << bowlHand_198 << "\n";
    }
};
int main()
{
    string n1_198;
    int a1_198, jn1_198, op1_198, rt1_198, nhc1_198, nc1_198, hs1_198,
        ns1_198, sl1_198;
    float avg1_198, sr1_198;
    char bh1_198;

    cin >> n1_198 >> a1_198 >> jn1_198 >> op1_198 >> rt1_198 >> nhc1_198 >> nc1_198 >> hs1_198 >> ns1_198 >> sl1_198 >> avg1_198 >> sr1_198 >> bh1_198;
    batsman_198 virat_198;
    virat_198.getData(n1_198, a1_198, jn1_198, op1_198);
    virat_198.getBatsman(rt1_198, nhc1_198, nc1_198, hs1_198, ns1_198, sl1_198, avg1_198, sr1_198, bh1_198);
    string n2_198, t2_198;
    int a2_198, jn2_198, op2_198, w2_198;
    float rr2_198, s2_198, e2_198;
    char bh2_198;

    cin >> n2_198 >> t2_198 >> a2_198 >> jn2_198 >> op2_198 >> w2_198 >> rr2_198 >> s2_198 >> e2_198 >> bh2_198;
    bowler_198 chahal_198;
    chahal_198.getData(n2_198, a2_198, jn2_198, op2_198);
    chahal_198.getbowler_198(t2_198, w2_198, rr2_198, s2_198, e2_198, bh2_198);
    virat_198.display_198();
    chahal_198.display_198();
    return 0;
}