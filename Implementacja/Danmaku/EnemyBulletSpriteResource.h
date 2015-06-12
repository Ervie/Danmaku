#pragma once

#include "Sprite.h"
#include "Resource.h"

class EnemyBulletSpriteResource: public Resource<std::string, Sprite>
{
	/// <summary>
	/// Utworzenie materiałów.
	/// </summary>
	/// <param name="gDevice">Urządznie graficzne.</param>
	void Create(GraphicsDevice * const gDevice) override
	{

	}
};
