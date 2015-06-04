#include "XmlParser.h"

/* ---- Konstruktor
   ------------------------------------------------------------------------------------------- */
XmlParser::XmlParser(std::string const & file) : _filePath(file)
{
};

/* ---- Start
   ------------------------------------------------------------------------------------------- */
void XmlParser::Start()
{
	this->GetContents();
	this->ReadXMLFile();
	this->Create();
};

/* ---- Get Contents
   ------------------------------------------------------------------------------------------- */
void XmlParser::GetContents()
{
	_contents = std::unique_ptr<char>(XML2Char(_filePath));
};

/* ---- XML 2 Char
   ------------------------------------------------------------------------------------------- */
char * XmlParser::XML2Char ( std::string const & stageFile )
{
	std::ifstream file( stageFile );
	if( file.bad() )
	{
		exit( - 1 );
	}
	std::filebuf * pbuf = file.rdbuf();
	long fileLength = static_cast<long>(pbuf->pubseekoff( 0, std::ios::end, std::ios::in ));
	file.seekg( 0 );
	char * out = new char[ fileLength + 1 ];
	file.read( out, fileLength );
	return out;
};

/* ---- Read XML File
   ------------------------------------------------------------------------------------------- */
void XmlParser::ReadXMLFile()
{
	try
	{
		_doc.parse<0>(_contents.get());
	}
	catch( rapidxml::parse_error e )
	{
		e.what();
	}
};

/* ---- Clear Document
   ------------------------------------------------------------------------------------------- */
void XmlParser::ClearDocument()
{
	_doc.clear();
};