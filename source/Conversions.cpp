#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include "Conversions.h"


using namespace CryptoPP;
using namespace std;

//Les fonctions viennent de différents algorithmes des librairies externes !
//cf : http://www.cryptopp.com/
string Conversion::Base32Encode(QString Text)
{
    string sortie;
    string text = Text.toStdString();
    StringSource(text, true, new Base32Encoder(new StringSink(sortie)));
    return sortie;
}

string Conversion::Base32Decode(QString Text)
{
    string sortie;
    string text = Text.toStdString();
    StringSource(text, true, new Base32Decoder(new StringSink(sortie)));
    return sortie;
}

string Conversion::Base64Encode(QString Text)
{
    string sortie;
    string text = Text.toStdString();
    StringSource(text, true, new Base64Encoder(new StringSink(sortie)));
    return sortie;
}

string Conversion::Base64Decode(QString Text)
{
    string sortie;
    string text = Text.toStdString();
    StringSource(text, true, new Base64Decoder(new StringSink(sortie)));
    return sortie;
}

string Conversion::HexEncode(QString Text)
{
    string sortie;
    string text = Text.toStdString();
    StringSource(text, true, new HexEncoder(new StringSink(sortie)));
    return sortie;
}

string Conversion::HexDecode(QString Text)
{
    string sortie;
    string text = Text.toStdString();
    StringSource(text, true, new HexDecoder(new StringSink(sortie)));
    return sortie;
}

static int HexPairValue(const char * code)
{
    int value = 0;
    const char * pch = code;
    for (;;)
    {
        int digit = *pch++;

        if (digit >= '0' && digit <= '9')
        {
            value += digit - '0';
        }
        else if (digit >= 'A' && digit <= 'F')
        {
            value += digit - 'A' + 10;
        }
        else if (digit >= 'a' && digit <= 'f')
        {
            value += digit - 'a' + 10;
        }
        else
        {
            return -1;
        }
        if (pch == code + 2)
            return value;

        value <<= 4;
    }
}

int Conversion::UrlDecode(const char *source, char *dest)
{
    char * start = dest;

    while (*source)
    {
        switch (*source)
        {
        case '+':
            *(dest++) = ' ';
            break;
        case '%':
            if (source[1] && source[2])
            {
                int value = HexPairValue(source + 1);
                if (value >= 0)
                {
                    *(dest++) = value;
                    source += 2;
                }
                else
                {
                    *dest++ = '?';
                }
            }
            else
            {
                *dest++ = '?';
            }
            break;
        default:
            *dest++ = *source;
        }
        source++;
    }
    *dest = 0;

    return dest - start;
}

int Conversion::UrlEncode(const char *source, char *dest, unsigned max)
{
    static const char *digits = "0123456789ABCDEF";
    unsigned char ch;
    unsigned len = 0;
    char *start = dest;

    while (len < max - 4 && *source)
    {
        ch = (unsigned char)*source;
        if (*source == ' ')
        {
            *dest++ = '+';
        }
        else if (isalnum(ch) || strchr("-_.!~*'()", ch))
        {
            *dest++ = *source;
        }
        else
        {
            *dest++ = '%';
            *dest++ = digits[(ch >> 4) & 0x0F];
            *dest++ = digits[       ch & 0x0F];
        }
        source++;
    }
    *dest = 0;

    return start - dest;
}

string Conversion::UrlDecodeString(QString encoded)
{
    const char * sz_encoded = encoded.toStdString().c_str();
    size_t needed_length = encoded.length();

    for (const char * pch = sz_encoded; *pch; pch++)
    {
        if (*pch == '%')
            needed_length += 2;
    }
    needed_length += 10;
    char stackalloc[64];
    char * buf = needed_length > sizeof(stackalloc)/sizeof(*stackalloc) ? (char *)malloc(needed_length) : stackalloc;

    UrlDecode(encoded.toStdString().c_str(), buf);
    string result(buf);

    if (buf != stackalloc)
    {
        free(buf);
    }

    return result;
}

string Conversion::UrlEncodeString(QString decoded)
{

    size_t needed_length = decoded.length() * 3 + 3;
    char stackalloc[64];
    char * buf = needed_length > sizeof(stackalloc)/sizeof(*stackalloc) ? (char *)malloc(needed_length) : stackalloc;

    UrlEncode(decoded.toStdString().c_str(), buf, needed_length);
    string result(buf);

    if (buf != stackalloc)
    {
        free(buf);
    }

    return result;
}


#define SPtoBACKQ(x) (x == 32) ? 96 : x

typedef union
{
    uint32_t l ;
    char c[4];
}un32;

string Conversion::UUEncodeString(QString decoded)
{
    const string data = decoded.toStdString();
    static const char fillchar = '`';

    static const uint32_t mask1 = 0xFC000000;
    static const uint32_t mask2 = 0x03F00000;
    static const uint32_t mask3 = 0x000FC000;
    static const uint32_t mask4 = 0x00003F00;

    const size_t trail = data.size()%3;
    size_t sz = data.size()/3*4;
    sz += (trail != 0) ? 4 : 0;

    un32 uue;

    string out;
    out.resize(sz+1);

    size_t i = 0, k = 0;
    out[k++] = static_cast < char > (data.size()+32);

    while (i < data.size()-trail)
    {
        uue.c[3] = data[i++];
        uue.c[2] = data[i++];
        uue.c[1] = data[i++];

        out[k++] = static_cast <char> (SPtoBACKQ(( (uue.l & mask1) >> 26) + 32));
        out[k++] = static_cast <char> (SPtoBACKQ(( (uue.l & mask2) >> 20) + 32));
        out[k++] = static_cast <char> (SPtoBACKQ(( (uue.l & mask3) >> 14) + 32));
        out[k++] = static_cast <char> (SPtoBACKQ(( (uue.l & mask4) >> 8) + 32));
    }

    uue.l = 0;

    switch (trail)
    {
    case 1:
        uue.c[3] = data[i++];
        out[k++] = static_cast <char> (SPtoBACKQ(( (uue.l & mask1) >> 26) + 32));
        out[k++] = static_cast <char> (SPtoBACKQ(( (uue.l & mask2) >> 20) + 32));
        out[k++] = fillchar;
        out[k++] = fillchar;
        break;

    case 2:
        uue.c[3] = data[i++];
        uue.c[2] = data[i++];
        out[k++] = static_cast <char> (SPtoBACKQ(( (uue.l & mask1) >> 26) + 32));
        out[k++] = static_cast <char> (SPtoBACKQ(( (uue.l & mask2) >> 20) + 32));
        out[k++] = static_cast <char> (SPtoBACKQ(( (uue.l & mask3) >> 14) + 32));
        out[k++] = fillchar;
        break;
    }

    return out;
}

#undef SPtoBACKQ



#define BACKQtoSP(x) (x == 96) ? 32 : x

string Conversion::UUDecodeString(QString encoded)
{
    const string data = encoded.toStdString();
    static const char fillchar = '`';
    const size_t trail = (data[data.size()-1] == fillchar) ? ((data[data.size()-2] == fillchar) ? 2 : 1 ) : 0;
    const size_t szin = (trail == 0) ? data.size() : data.size()-4;
    const size_t szout = data[0]-32;

    un32 b64;

    string out;
    out.resize(szout);

    size_t i = 1, k = 0;

    for (; i < szin; i+=4)
    {
        b64.l = 0;
        b64.l += (static_cast < uint32_t > (BACKQtoSP(data[i ])) -32) << 26;
        b64.l += (static_cast < uint32_t > (BACKQtoSP(data[i+1])) -32) << 20;
        b64.l += (static_cast < uint32_t > (BACKQtoSP(data[i+2])) -32) << 14;
        b64.l += (static_cast < uint32_t > (BACKQtoSP(data[i+3])) -32) << 8;


        out[k++] = b64.c[3];
        out[k++] = b64.c[2];
        out[k++] = b64.c[1];
    }

    b64.l = 0;

    switch (trail)
    {
    case 1:
        b64.l += (static_cast < uint32_t > (BACKQtoSP(data[i ])) -32) << 26;
        b64.l += (static_cast < uint32_t > (BACKQtoSP(data[i+1])) -32) << 20;
        b64.l += (static_cast < uint32_t > (BACKQtoSP(data[i+2])) -32) << 14;

        out[k++] = b64.c[3];
        out[k++] = b64.c[2];
        break;

    case 2:
        b64.l += (static_cast < uint32_t > (BACKQtoSP(data[i ])) -32) << 26;
        b64.l += (static_cast < uint32_t > (BACKQtoSP(data[i+1])) -32) << 20;

        out[k++] = b64.c[3];
        break;
    }

    return out;
}

#undef BACKQtoSP

#define ROT 13

string Conversion::Rot13Encode(QString src)
{
    string str = src.toStdString();
    string ret = str;

    int i=0;

    while (str[i] != '\0')
    {
        if (str[i] >= 'a' && str[i] <= 'z')
            ret[i] = (str[i] - 'a' + ROT) % 26 + 'a';
        else if (str[i] >= 'A' && str[i] <= 'Z')
            ret[i] = (str[i] - 'A' + ROT) % 26 + 'A';
        i++;
    }
    return ret;
}

string Conversion::Reverse(QString str)
{
    string ret = str.toStdString(), help;

    for(int i=0, j = str.size()-1; i<j/2; i++, j--)
    {
        help[0] = ret[i];
        ret[i] = ret[j];
        ret[j] = help[0];
    }

    return ret;
}

