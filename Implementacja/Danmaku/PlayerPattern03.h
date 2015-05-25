#pragma once

#include "PlayerBullet.h"
#include "PPattern.h"

class PlayerPattern03 : public PPattern
{
private:

	// Przesuni�cia dla miejsc z kt�rych wystrzeliwane b�d� pociski wzgl�dem �rodka gracza
	D3DXVECTOR2 leftShift, rightShift;

public:
	PlayerPattern03(void);
	~PlayerPattern03(void);

	void Initialize(D3DXVECTOR2 const & position) override;
	void Update(float const time, D3DXVECTOR2 const & position) override;

	void Add(D3DXVECTOR2 const & position);

	void LoadSprite(PlayerBulletSpriteResource & pbsResource) override;
};

