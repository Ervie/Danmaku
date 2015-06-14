#pragma once
#include "GameInitializationFailedException.h"

/// <summary>
/// Wyjątek związany z nieprawidłowym uruchomieniem gry
/// </summary>
class PlayerInitializationFailedException: public GameInitializationFailedException
{
public:
	// zwrócenie komunikatu
	std::string ToString() const override;
};
