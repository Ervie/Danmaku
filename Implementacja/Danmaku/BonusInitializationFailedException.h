#pragma once
#include "GameInitializationFailedException.h"

/// <summary>
/// Wyjątek związany z nieprawidłowym utworzenie bonusu
/// </summary>
class BonusInitializationFailedException: public GameInitializationFailedException
{
public:
	// zwrócenie komunikatu
	std::string ToString() const override;
};
