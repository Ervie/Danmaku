#pragma once
#include "ppattern.h"


class PlayerPattern03 : public PPattern
{
private:

	// Przesuni�cia dla miejsc z kt�rych wystrzeliwane b�d� pociski wzgl�dem �rodka gracza
	D3DXVECTOR2 leftShift, rightShift;

public:
	PlayerPattern03(void);
	~PlayerPattern03(void);

	void Initialize(LPDIRECT3DDEVICE9 device, D3DXVECTOR2 const & position) override;

	void Update(float const time) override;
	void Update(float const time, bool pressedKey, D3DXVECTOR2 & position);

	void Add(D3DXVECTOR2 & position);

};
