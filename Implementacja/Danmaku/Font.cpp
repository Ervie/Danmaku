#include "Font.h"


Font::Font( D3DXVECTOR2 const & fieldPosition, unsigned short const & fieldWidth, unsigned short const & fieldHeight )
	: fieldWidth(fieldWidth), fieldHeight(fieldHeight), fieldPosition(fieldPosition)
{
	SetRect(&rect, fieldPosition.x, fieldPosition.y, fieldWidth, fieldHeight);
};


Font::~Font()
{
	if ( text )
	{
		text->Release();
		text = NULL;
	}
};


bool Font::Initialize( GraphicsDevice const * gDevice, short unsigned const & fontHeight, 
		short unsigned const & fontWidth, char const * font, bool bold, bool italic, D3DXCOLOR const & color )
{
	this->color = color;
	return D3DXCreateFont( gDevice->device, fontHeight, fontWidth, bold ? FW_BOLD : FW_NORMAL, 1, italic,
			DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH | FF_DONTCARE,
			font, &text );
};


void Font::Draw( std::string const & str )
{
	text->DrawText( NULL, str.c_str(), -1, &rect, DT_LEFT | DT_NOCLIP, color );
};


void Font::Draw( int const & number, short unsigned const & padding )
{
	std::stringstream ss;
	ss << std::setw(padding) << std::setfill('0') << number;
	text->DrawText( NULL, ss.str().c_str(), -1, &rect, DT_LEFT | DT_NOCLIP, color );
};