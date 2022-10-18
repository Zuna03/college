#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
// Struct Declaration.
struct distance_198
{
    float km_198, m_198;
};
// Take input.
void getDistance_198(struct distance_198 *d_198, float KM_198, float M_198)
{
    d_198->km_198 = KM_198;
    d_198->m_198 = M_198;
}
// Add two distances(struct distance elements).
void addDistance_198(struct distance_198 *d_198, struct distance_198 *p_198, struct distance_198 *q_198)
{
    d_198->m_198 = p_198->m_198 + q_198->m_198;
    d_198->km_198 = p_198->km_198 + q_198->km_198 + (d_198->m_198) / 1000;
    d_198->m_198 = (int)d_198->m_198 % 1000;
}
// Gives Output.
void display_198(struct distance_198 *d_198)
{
    printf("%fkm & %fm\n", d_198->km_198, d_198->m_198);
}
// Main Function.
int main()
{
    printf("Enter two distances in km and m \n");

    struct distance_198 *p_198, *q_198, *ans_198;

    float KMp_198, Mp_198, KMq_198, Mq_198;

    scanf("%f%f%f%f", &KMp_198, &Mp_198, &KMq_198, &Mq_198);

    p_198 = (struct distance_198 *)malloc(sizeof(struct distance_198));
    q_198 = (struct distance_198 *)malloc(sizeof(struct distance_198));
    ans_198 = (struct distance_198 *)malloc(sizeof(struct distance_198));

    getDistance_198(p_198, KMp_198, Mp_198);
    getDistance_198(q_198, KMq_198, Mq_198);

    addDistance_198(ans_198, p_198, q_198);
    printf("The sum of both distances is :- \n");
    display_198(ans_198);

    return 0;
}