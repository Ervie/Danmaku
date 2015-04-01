/* ======================================================== *\
 *  @GraphicsDevice.cpp
 *  @Opis: obsługa i kontrola urządzenia graficznego
 *  @Utworzona: 21.03.2015 21:52
 *  @Autor: Mateusz Forczmański
\* ======================================================== */

#pragma once

#include <d3d9.h>
#include <d3dx9.h>
#include "Bullet.h"

#include "Direct3DInitializationFailedException.h"

class GraphicsDevice
{
public:
	// uchywty do urządzeń DirectXa
	LPDIRECT3DDEVICE9 device;
	LPDIRECT3D9 direct3d;

private:

public:
	GraphicsDevice();

	// utworzenie właściwego obiektu Device
	bool Initialize(HWND & hWnd, bool windowed);

	void ReleaseObjects();

	// funkcje do prezentacji ekranu
	void Clear(D3DCOLOR const & color);
	void Begin();
	void End();
	void Present();

};
