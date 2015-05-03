#pragma once
#include "EPattern.h"
#include "PlayerBullet.h"
#include "PPattern.h"

class PlayerPattern01 : public PPattern
{
private:

public:
	PlayerPattern01(void);
	~PlayerPattern01(void);

	void Initialize(LPDIRECT3DDEVICE9 device, D3DXVECTOR2 const & position) override;
	void Update(float const time) override;
	void Update(float const time, bool pressedKey, D3DXVECTOR2 & position);

	void Add(D3DXVECTOR2 & position);

};
