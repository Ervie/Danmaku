#pragma once

#include <d3dx9.h>
#include <sstream>
#include <iomanip>
#include "GraphicsDevice.h"

/// Klasa służąca do generacji i wyświetlania napisów zrozumiałych dla DirectXa

class Font
{
	LPD3DXFONT text;
	RECT rect;
	D3DXCOLOR color;

	unsigned short fieldWidth;
	unsigned short fieldHeight;
	D3DXVECTOR2 fieldPosition;

public:
	//// Konstruktor i destruktor
	Font( D3DXVECTOR2 const & fieldPosition, unsigned short const fieldWidth, unsigned short const fieldHeight );
	~Font();

	//// Inicjalizacja i utowrzenie właściwej instacji czcionki
	bool Initialize( GraphicsDevice * const gDevice, short unsigned const fontHeight, 
			short unsigned const fontWidth, std::string const & font, bool bold, bool italic,
			D3DXCOLOR const & color );

	//// Narysowanie tekstu na ekranie
	void Draw( std::string const & str, short unsigned const padding = 0 );

	//// narysowanie liczby w formie tekstu ze wskazanym wypełnieniem zerami
	void Draw( int const number, short unsigned const padding );

	/// Narysowanie liczby zmiennoprzecinkowej z określoną precyzją
	void Draw( float const number, short unsigned const padding, short unsigned const precision );

};