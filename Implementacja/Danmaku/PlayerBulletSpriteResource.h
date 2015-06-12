#pragma once

#include "Sprite.h"
#include "Resource.h"

class PlayerBulletSpriteResource: public Resource<std::string, Sprite>
{
public:
	/// <summary>
	/// Utworzenie materiałów.
	/// </summary>
	/// <param name="gDevice">Urządznie graficzne.</param>
	void Create(GraphicsDevice * const gDevice) override
	{
		for (Map::const_iterator it = _map.begin(); it != _map.end(); ++it)
		{
			(*it).second->Initialize(gDevice->device, Sprite::GetFilePath((*it).first));
		}
	}
};
