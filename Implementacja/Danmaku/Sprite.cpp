#include "Sprite.h"

Sprite::Sprite()
{
	// When color is set to white, what you see is exactly what the image looks like.
	color = D3DCOLOR_ARGB(255, 255, 255, 255);

	// We are not initialized yet
	initialized = false;
};

bool Sprite::Initialize(LPDIRECT3DDEVICE9 device, std::string file, int width, int height, D3DXVECTOR3 const & position)
{
	//Same functionality as D3DXCreateTextureFromFile EXCEPT width and height are manually entered
	if (!SUCCEEDED(D3DXCreateTextureFromFileEx(device, file.c_str(), 
		width, height, D3DX_DEFAULT, 0, D3DFMT_UNKNOWN, D3DPOOL_MANAGED, D3DX_DEFAULT, 
		D3DX_DEFAULT, 0, NULL, NULL, &tex)))
	{
		std::string s = "There was an issue creating the Texture.  Make sure the requested image is available.  Requested image: " + file;
		MessageBox(NULL, s.c_str(), NULL, NULL); 
		return false;
	}

	//Attempt to create the sprite
	if(!SUCCEEDED(D3DXCreateSprite(device, &sprite)))
	{
		MessageBox(NULL, "There was an issue creating the Sprite.", NULL, NULL);
		return false;
	}

	this->width = width;
	this->height = height;

	this->SetCenterPoint( position );

	this->SetRotation( 0.0f );
	this->SetScale( 1.0f );

	initialized = true;

	return true;
};


void Sprite::SetCenterPoint( D3DXVECTOR3 const & position )
{
	this->SetCenterPoint( position.x + this->GetWidth() / 2, position.y + this->GetHeight() / 2, position.z );
};


void Sprite::SetCenterPoint( float const & x0, float const & y0, float const & z0 )
{
	this->center.x = x0;
	this->center.y = y0;
	this->center.z = z0;
};


void Sprite::Draw(D3DXVECTOR3 const & position)
{
	this->Draw(position, this->tex);
};


// position - g�rny, lewy r�g sprajta
void Sprite::Draw(D3DXVECTOR3 const & position, LPDIRECT3DTEXTURE9 tex)
{
	if (this->sprite && tex)
	{
		this->sprite->Begin(D3DXSPRITE_ALPHABLEND);

		D3DXMATRIX mat;
		D3DXVECTOR2 center2D( center.x, center.y );

		// skalowanie i obr�t
		D3DXMatrixTransformation2D( &mat, &center2D, NULL, new D3DXVECTOR2( scale, scale ), &center2D, rotation, NULL );

		this->sprite->SetTransform( &mat );

		this->sprite->Draw(tex, NULL, NULL, &position, this->color);

		this->sprite->End();
	}

	/** Dzia�aj�cy kod na obr�t 2D dla kwaternionu. Wyszed� w praniu
		D3DXVECTOR3 rotor ( rotation, 0.0f, 0.0f );

		float s2 = std::sin( D3DXToRadian ( rotor.x / 2.0f ) );
		float s1 = std::sin( D3DXToRadian ( rotor.y / 2.0f ) );
		float s3 = std::sin( D3DXToRadian ( rotor.z / 2.0f ) );

		float c2 = std::cos( D3DXToRadian ( rotor.x / 2.0f ) );
		float c1 = std::cos( D3DXToRadian ( rotor.y / 2.0f ) );
		float c3 = std::cos( D3DXToRadian ( rotor.z / 2.0f ) );
				
		float rX = s1 * s2 * c3 + c1 * c2 * s3;
		float rY = s1 * c2 * c3 + c1 * s2 * s3;
		float rZ = c1 * s2 * c3 - s1 * c2 * s3;
		float rW = c1 * c2 * c3 - s1 * s2 * s3;

		D3DXQUATERNION quat ( rX, rY, rZ, rW );
		
		D3DXMATRIX mat;
		D3DXMatrixTransformation(&mat, NULL, NULL, NULL, &center, &quat, NULL);
	*/
};


Sprite::~Sprite()
{
	if (sprite)
	{
		sprite->Release();
		sprite = 0;
	}

	if (tex)
	{
		tex->Release();
		tex = 0;
	}
};


void Sprite::SetRotation(float const & rotation )
{
	this->rotation = rotation;
};


void Sprite::Rotate( float const & angle )
{
	this->rotation += angle;
};


void Sprite::SetScale( float const & scale )
{
	this->scale = scale;
};


void Sprite::Scale( float const & scale )
{
	this->scale *= scale;
};