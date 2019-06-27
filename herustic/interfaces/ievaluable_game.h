#ifndef IEVALUABLE_GAME_H
#define IEVALUABLE_GAME_H

class IEvaluableGame
{
	public:
		virtual ~IEvaluableGame() = default;

		virtual size_t evaluate() = 0;
};

#endif // IEVALUABLE_GAME_H
