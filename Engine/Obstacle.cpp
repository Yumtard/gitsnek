#include "Obstacle.h"

void Obstacle::Draw(Board& brd) const
{	
	brd.DrawCell(loc, c);
}

void Obstacle::Respawn(std::mt19937 & rng, const Board & brd, const Snake & snake, const Goal& goal)
{
	std::uniform_int_distribution<int> xDist(0, brd.GetWidth() - 1);
	std::uniform_int_distribution<int> yDist(0, brd.GetHeight() - 1);

	Location newLoc;
	do
	{
		newLoc.x = xDist(rng);
		newLoc.y = yDist(rng);
	} while (snake.IsInTile(newLoc) || goal.IsInTile(newLoc));

	loc = newLoc;
}

const Location & Obstacle::GetLocation() const
{
	return loc;
}
