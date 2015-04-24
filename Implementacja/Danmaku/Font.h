#pragma once

#include <d3dx9.h>
#include <sstream>
#include <iomanip>
#include "GraphicsDevice.h"

/// Klasa s�u��ca do generacji i wy�wietlania napis�w zrozumia�ych dla DirectXa

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
	Font( D3DXVECTOR2 const & fieldPosition, unsigned short const & fieldWidth, unsigned short const & fieldHeight );
	~Font();

	//// Inicjalizacja i utowrzenie w�a�ciwej instacji czcionki
	bool Initialize( GraphicsDevice const * gDevice, short unsigned const & fontHeight, 
			short unsigned const & fontWidth, char const * font, bool bold, bool italic,
			D3DXCOLOR const & color );

	//// Narysowanie tekstu na ekranie
	void Draw( std::string const & str );

	//// narysowanie liczby w formie tekstu ze wskazanym wype�nieniem zerami
	void Draw( int const & number, short unsigned const & padding );
};