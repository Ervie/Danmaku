#pragma once

#include <D3dx9.h>
#include <D3d9.h>
#include <vector>
#include <string>

#include "IDrawable.h"

/// <summary>
/// Klasa przechowuj�ca informacje o rysunkach (sprajtach)
/// </summary>
class Sprite : public IDrawable
{
	//////// SK�ADOWE ////////////////////////////
	// Elementy graficzne
	static const std::string IMG_PATH;

	LPD3DXSPRITE sprite;			// wska�nik na sprajt
	LPDIRECT3DTEXTURE9 * tex;		// wska�nika na tablic� wska�nik�w na tekstury

	int currentTex;					// obecnie wykorzystywana tekstura
	int texNumber;					// liczba tekstur

	D3DCOLOR color;

	// Dane o rysunku sprajta
	int width;
	int height;

	// Przesuni�cie punktu �rodkowego wzgl�dem lewego g�rnego rogu
	D3DXVECTOR2 center;

	// informacja czy sprajt wykona� si� jak nale�y
	bool initialized;


	///////// METODY /////////////////////////////////
public:
	// utworznie sprajta z zewn�trz
	// pobiera uchwyt do urz�dznia, �cie�k� do pliku, szeroko�� i wysoko��
	// je�li wysoko�� i szeroko�� nie s� podane, pobiera dane z pliku
	Sprite();
	Sprite(LPDIRECT3DDEVICE9 device, std::string const & file,
			UINT const width = D3DX_DEFAULT_NONPOW2, UINT const height = D3DX_DEFAULT_NONPOW2);
	Sprite(LPDIRECT3DDEVICE9 device, std::vector<std::string> const & fileVect,
			UINT const width = D3DX_DEFAULT_NONPOW2, UINT const height = D3DX_DEFAULT_NONPOW2);
	~Sprite();

	bool Initialize(LPDIRECT3DDEVICE9 device, std::string const & file,
		UINT const width = D3DX_DEFAULT_NONPOW2, UINT const height = D3DX_DEFAULT_NONPOW2);
	bool Initialize(LPDIRECT3DDEVICE9 device, std::vector<std::string> const & fileVect,
		UINT const width = D3DX_DEFAULT_NONPOW2, UINT const height = D3DX_DEFAULT_NONPOW2);

public:
	// utworzenie punktu �rodkowego
	void SetCenterPoint();

	////// RYSOWANIE SPRAJTA W OKNIE
	void Draw(D3DXVECTOR2 const & position, float scale = 1.0f, float rotation = 0.0f) override;
	void Draw(D3DXVECTOR2 const & position, D3DXVECTOR2 const & scale, float rotation = 0.0f);

	void SetCurrentTexture( short const number );
	void ResetValues();

	////////// GETTERY ////////////////////
	/// <summary>
	/// Zwraca szeroko�� sprajta.
	/// </summary>
	/// <returns></returns>
	inline const int GetWidth() const
	{
		return this->width;
	};

	/// <summary>
	/// Zwraca wysoko�� sprajta.
	/// </summary>
	/// <returns></returns>
	inline const int GetHeight() const
	{
		return this->height;
	};

	/// <summary>
	/// Czy prawid�owo si� wykona�
	/// </summary>
	/// <returns></returns>
	inline const bool IsInitialized() const
	{
		return this->initialized;
	};

	/// <summary>
	/// Zwraca po�o�enie �rodka obiektu (i tym samym hitboxa).
	/// </summary>
	/// <returns></returns>
	inline const D3DXVECTOR2& GetCenterPoint() const
	{
		return this->center;
	}

	///// FUNKCJE TWORZ�CE �CIE�KI DO SPRAJT�W
	inline static std::string GetFilePath( std::string const & name, int const i, int const j, std::string const & ext )
	{
		return IMG_PATH + name + std::to_string(i) + std::to_string(j) + '.' + ext;
	};

	inline static std::string GetFilePath( std::string const & name, int const number, std::string const & ext )
	{
		return IMG_PATH + name + std::to_string(number) + '.' + ext;
	};

	inline static std::string GetFilePath( std::string const & name, std::string const & ext )
	{
		return IMG_PATH + name + '.' + ext;
	};
	inline static std::string GetFilePath( std::string const & name )
	{
		return IMG_PATH + name + '.' + "png";
	};
};
