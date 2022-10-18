#include <bits/stdc++.h>
using namespace std;
class cricketer_198
{
protected:
    string name_198;
    int age_198, jerseyNo_198, odiPlay_198;

public:
    void getData(string n_198, int a_198, int jn_198, int op_198)
    {
        name_198 = n_198;
        age_198 = a_198;
        jerseyNo_198 = jn_198;
        odiPlay_198 = op_198;
    }
};
class batsman_198 : virtual public cricketer_198
{
protected:
    int runsTaken_198, numHalfCen_198, numCen_198, highScore_198, numSix_198, sixLong_198;
    float average_198, strikeRate_198;
    char batHand_198;

public:
    void getBatsMan(int rt_198, int nhc_198, int nc_198, int hs_198, int ns_198, int sl_198, float avg_198, float sr_198, char batH_198)
    {
        runsTaken_198 = rt_198;
        numHalfCen_198 = nhc_198;
        numCen_198 = nc_198;
        highScore_198 = hs_198;
        numSix_198 = ns_198;
        sixLong_198 = sl_198;
        average_198 = avg_198;
        strikeRate_198 = sr_198;
        batHand_198 = batH_198;
    }
};
class bowler_198 : virtual public cricketer_198
{
protected:
    string type_198;
    int wickets_198;
    float runRate_198, speed_198, eco_198;
    char bowlHand_198;

public:
    void getBowler(string t_198, int w_198, float rr_198, float s_198, float e_198, char bowlH_198)
    {
        type_198 = t_198;
        wickets_198 = w_198;
        runRate_198 = rr_198;
        speed_198 = s_198;
        eco_198 = e_198;
        bowlHand_198 = bowlH_198;
    }
};
class allRounder_198 : public batsman_198, public bowler_198
{
    int numMotm_198, numIntMatch_198, numCatches_198, iccRank_198,
        numStylePlaMatch_198;

public:
    void getAll(int nmtm_198, int nim_198, int ncs_198, int icr_198, int nspm_198)
    {
        numMotm_198 = nmtm_198;
        numIntMatch_198 = nim_198;
        numCatches_198 = ncs_198;
        iccRank_198 = icr_198;
        numStylePlaMatch_198 = nspm_198;
    }
    void display_198()
    {
        cout << jerseyNo_198 << ". " << name_198 << " " << age_198 << "\nNumber of odi played : -" << odiPlay_198 << "\n ";
        cout
            << "Runs :- "
            << runsTaken_198
            << "\n";
        cout << "Number of half centuries :- " << numHalfCen_198 << "\n";
        cout << "Number of centuries :- " << numCen_198 << "\n";
        cout << "Highest Score :- " << highScore_198 << "\n";
        cout << "Number of sixes :- " << numSix_198 << "\n";
        cout << "Longest Six :- " << sixLong_198 << "\n";
        cout << "Average :- " << average_198 << "\n";
        cout << "Strike Rate :- " << strikeRate_198 << "\n";
        cout << "Strong hand :- " << batHand_198 << "\n";
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
    string n_198, t_198;
    int a_198, jn_198, op_198, rt_198, nhc_198, nc_198, hs_198, ns_198,
        sl_198, w_198, nmtm_198, nim_198, ncs_198, icr_198, nspm_198;
    float avg_198, sr_198, rr_198, s_198, e_198;
    char batH_198, bowlH_198;

    cin >> n_198 >> a_198 >> jn_198 >> op_198 >> rt_198 >> nhc_198 >> nc_198 >> hs_198 >> ns_198 >> sl_198 >> avg_198 >> sr_198 >> batH_198 >> w_198 >> rr_198 >> s_198 >> e_198 >> bowlH_198 >> nmtm_198 >> nim_198 >> ncs_198 >> icr_198 >> nspm_198 >> t_198;

    allRounder_198 rick_198;
    rick_198.getData(n_198, a_198, jn_198, op_198);
    rick_198.getBatsMan(rt_198, nhc_198, nc_198, hs_198, ns_198, sl_198, avg_198, sr_198, batH_198);
    rick_198.getBowler(t_198, w_198, rr_198, s_198, e_198, bowlH_198);

    rick_198.getAll(nmtm_198, nim_198, ncs_198, icr_198, nspm_198);
    rick_198.display_198();

    return 0;
}