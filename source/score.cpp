#include"score.h"

Score::Score()
{
	score = 0;
}
int Score::Player_Score()
{
	return score;
}
void Score::Add_Points(int d)
{
	score += d;
}
void Score::Reset_Points()
{
	score = 0;
}