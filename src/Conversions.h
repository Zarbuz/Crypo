#ifndef HEADER_CONVERSIONS
#define HEADER_CONVERSIONS

#include "C:\Qt\2009.02\qt\include\cryptopp/base32.h"
#include "C:\Qt\2009.02\qt\include\cryptopp/base64.h"
#include "C:\Qt\2009.02\qt\include\cryptopp/hex.h"

#include <QtGui>

using namespace std;

class Conversion
{

public:
    string Base32Encode(QString Text);
    string Base32Decode(QString Text);
    string Base64Encode(QString Text);
    string Base64Decode(QString Text);
    string HexEncode(QString Text);
    string HexDecode(QString Text);
    string Reverse(QString str);
    string Rot13Encode(QString src);
    int UrlDecode(const char *source, char *dest);
    int UrlEncode(const char *source, char *dest, unsigned max);
    string UrlDecodeString(QString encoded);
    string UrlEncodeString(QString decoded);
    string UUEncodeString(QString encoded);
    string UUDecodeString(QString decoded);

};

#endif
