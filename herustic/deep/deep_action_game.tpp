#include "deep_action_game.h"

template<class Base>
DeepActionGame<Base>::DeepActionGame(const DeepActionGame& game) : Base(game), sum_evaluate(game.sum_evaluate)
{

}

template<class Base>
DeepActionGame<Base>::DeepActionGame(const IGame& game) : Base(game), sum_evaluate(0)
{

}

template<class Base>
void DeepActionGame<Base>::play(IAction& action)
{
	sum_evaluate += evaluate(action);
	Base::play(action);
}

template<class Base>
size_t DeepActionGame<Base>::evaluate()
{
	return sum_evaluate;
}
