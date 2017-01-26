#pragma once
#include "Graphics.h"
#include "Board.h"
#include <random>
#include "Snake.h"
#include "Goal.h"

class Obstacle
{
public:
	void Draw(Board& brd) const;
	void Respawn(std::mt19937& rng, const Board& brd, const Snake& snake, const Goal& goal);
	const Location& GetLocation() const;

private:
	static constexpr Color c = Colors::Gray;
	Location loc;
};
