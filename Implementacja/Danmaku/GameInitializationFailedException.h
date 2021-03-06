#pragma once
#include "IException.h"

/// <summary>
/// Wyjątek związany z nieprawidłowym uruchomieniem gry
/// </summary>
class GameInitializationFailedException: public IException
{
public:
	// zwrócenie komunikatu
	virtual std::string ToString() const override;

	// pokazanie message boxa
	virtual void ToMessageBox() override;
};
