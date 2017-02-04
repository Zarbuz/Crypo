#ifndef HEADER_HASHES
#define HEADER_HASHES

#include <C:\Qt\2009.02\qt\include\cryptopp/filters.h>
#include <C:\Qt\2009.02\qt\include\cryptopp/hex.h>
#include <C:\Qt\2009.02\qt\include\cryptopp/adler32.h>
#include <C:\Qt\2009.02\qt\include\cryptopp/crc.h>
#define CRYPTOPP_ENABLE_NAMESPACE_WEAK 1
#include <C:\Qt\2009.02\qt\include\cryptopp/md5.h>
#include <C:\Qt\2009.02\qt\include\cryptopp/md2.h>
#include <C:\Qt\2009.02\qt\include\cryptopp/md4.h>
#include <C:\Qt\2009.02\qt\include\cryptopp/ripemd.h>
#include <C:\Qt\2009.02\qt\include\cryptopp/sha.h>
#include <C:\Qt\2009.02\qt\include\cryptopp/tiger.h>
#include <C:\Qt\2009.02\qt\include\cryptopp/whrlpool.h>


#include <QtGui>

#include "Conversions.h"

using namespace std;

class Hashes
{

public:
    string Adler32Fonction(QString qstring);
    string Crc32Fonction(QString qstring);
    string Md2Fonction(QString qstring);
    string Md4Fonction(QString qstring);
    string Md5Fonction(QString qstring);
    string Ripemd128Fonction(QString qstring);
    string Ripemd160Fonction(QString qstring);
    string Ripemd320Fonction(QString qstring);
    string Sha1Fonction(QString qstring);
    string Sha224Fonction(QString qstring);
    string Sha256Fonction(QString qstring);
    string Sha384Fonction(QString qstring);
    string Sha512Fonction(QString qstring);
    string TigerFonction(QString qstring);
    string WhirlpoolFonction(QString qstring);
};

#endif
