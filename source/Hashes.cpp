#include "Hashes.h"

using namespace CryptoPP;
using namespace Weak;
using namespace std;

//Les fonctions viennent de différents algorithmes des librairie externes !
//cf : http://www.cryptopp.com/

/*
  La suite est assez répétitive, grace aux libraires que peut de chose varie
  */
string Hashes::Adler32Fonction(QString qstring)
{
    Adler32 Adler32Hash;
    byte Adler32Digest[ Adler32::DIGESTSIZE ];
    string message = qstring.toStdString();

    Adler32Hash.CalculateDigest( Adler32Digest, (byte*) message.c_str(), message.length() );

    HexEncoder encoder;
    string Adler32sortie;
    encoder.Attach( new StringSink( Adler32sortie ) );
    encoder.Put( Adler32Digest, sizeof(Adler32Digest) );
    encoder.MessageEnd();

    return Adler32sortie;
}

string Hashes::Crc32Fonction(QString qstring)
{
    CRC32 Crc32Hash;
    byte Crc32Digest[ CRC32::DIGESTSIZE ];
    string message = qstring.toStdString();

    Crc32Hash.CalculateDigest( Crc32Digest, (byte*) message.c_str(), message.length() );

    HexEncoder encoder;
    string Crc32sortie;
    encoder.Attach( new StringSink( Crc32sortie ) );
    encoder.Put( Crc32Digest, sizeof(Crc32Digest) );
    encoder.MessageEnd();

    return Crc32sortie;
}

string Hashes::Md2Fonction(QString qstring)
{
    MD2 Md2Hash;
    byte Md2Digest[ MD2::DIGESTSIZE ];
    string message = qstring.toStdString();

    Md2Hash.CalculateDigest( Md2Digest, (byte*) message.c_str(), message.length() );

    HexEncoder encoder;
    string Md2sortie;
    encoder.Attach( new StringSink( Md2sortie ) );
    encoder.Put( Md2Digest, sizeof(Md2Digest) );
    encoder.MessageEnd();

    return Md2sortie;
}

string Hashes::Md4Fonction(QString qstring)
{
    MD4 Md4Hash;
    byte Md4Digest[ MD4::DIGESTSIZE ];
    string message = qstring.toStdString();

    Md4Hash.CalculateDigest( Md4Digest, (byte*) message.c_str(), message.length() );

    HexEncoder encoder;
    string Md4sortie;
    encoder.Attach( new StringSink( Md4sortie ) );
    encoder.Put( Md4Digest, sizeof(Md4Digest) );
    encoder.MessageEnd();

    return Md4sortie;
}

string Hashes::Md5Fonction(QString qstring)
{
    MD5 Md5Hash;
    byte Md5Digest[ MD5::DIGESTSIZE ];
    string message = qstring.toStdString();

    Md5Hash.CalculateDigest( Md5Digest, (byte*) message.c_str(), message.length() );

    HexEncoder encoder;
    string Md5sortie;
    encoder.Attach( new StringSink( Md5sortie ) );
    encoder.Put( Md5Digest, sizeof(Md5Digest) );
    encoder.MessageEnd();

    return Md5sortie;
}


string Hashes::Ripemd128Fonction(QString qstring)
{
    RIPEMD128 Ripemd128Hash;
    byte Ripemd128Digest[ RIPEMD128::DIGESTSIZE ];
    string message = qstring.toStdString();

    Ripemd128Hash.CalculateDigest( Ripemd128Digest, (byte*) message.c_str(), message.length() );

    HexEncoder encoder;
    string Ripemd128sortie;
    encoder.Attach( new StringSink( Ripemd128sortie ) );
    encoder.Put( Ripemd128Digest, sizeof(Ripemd128Digest) );
    encoder.MessageEnd();

    return Ripemd128sortie;
}


string Hashes::Ripemd160Fonction(QString qstring)
{
    RIPEMD160 Ripemd160Hash;
    byte Ripemd160Digest[ RIPEMD160::DIGESTSIZE ];
    string message = qstring.toStdString();

    Ripemd160Hash.CalculateDigest( Ripemd160Digest, (byte*) message.c_str(), message.length() );

    HexEncoder encoder;
    string Ripemd160sortie;
    encoder.Attach( new StringSink( Ripemd160sortie ) );
    encoder.Put( Ripemd160Digest, sizeof(Ripemd160Digest) );
    encoder.MessageEnd();

    return Ripemd160sortie;
}


string Hashes::Ripemd320Fonction(QString qstring)
{
    RIPEMD320 Ripemd320Hash;
    byte Ripemd320Digest[ RIPEMD320::DIGESTSIZE ];
    string message = qstring.toStdString();

    Ripemd320Hash.CalculateDigest( Ripemd320Digest, (byte*) message.c_str(), message.length() );

    HexEncoder encoder;
    string Ripemd320sortie;
    encoder.Attach( new StringSink( Ripemd320sortie ) );
    encoder.Put( Ripemd320Digest, sizeof(Ripemd320Digest) );
    encoder.MessageEnd();

    return Ripemd320sortie;
}


string Hashes::Sha1Fonction(QString qstring)
{
    SHA ShaHash;
    byte ShaDigest[ SHA::DIGESTSIZE ];
    string message = qstring.toStdString();

    ShaHash.CalculateDigest( ShaDigest, (byte*) message.c_str(), message.length() );

    HexEncoder encoder;
    string Shasortie;
    encoder.Attach( new StringSink( Shasortie ) );
    encoder.Put( ShaDigest, sizeof(ShaDigest) );
    encoder.MessageEnd();

    return Shasortie;
}

string Hashes::Sha224Fonction(QString qstring)
{
    SHA224 Sha224Hash;
    byte Sha224Digest[ SHA224::DIGESTSIZE ];
    string message = qstring.toStdString();

    Sha224Hash.CalculateDigest( Sha224Digest, (byte*) message.c_str(), message.length() );

    HexEncoder encoder;
    string Sha224sortie;
    encoder.Attach( new StringSink( Sha224sortie ) );
    encoder.Put( Sha224Digest, sizeof(Sha224Digest) );
    encoder.MessageEnd();

    return Sha224sortie;
}

string Hashes::Sha256Fonction(QString qstring)
{
    SHA256 Sha256Hash;
    byte Sha256Digest[ SHA256::DIGESTSIZE ];
    string message = qstring.toStdString();

    Sha256Hash.CalculateDigest( Sha256Digest, (byte*) message.c_str(), message.length() );

    HexEncoder encoder;
    string Sha256sortie;
    encoder.Attach( new StringSink( Sha256sortie ) );
    encoder.Put( Sha256Digest, sizeof(Sha256Digest) );
    encoder.MessageEnd();

    return Sha256sortie;
}

string Hashes::Sha384Fonction(QString qstring)
{
    SHA384 Sha384Hash;
    byte Sha384Digest[ SHA384::DIGESTSIZE ];
    string message = qstring.toStdString();

    Sha384Hash.CalculateDigest( Sha384Digest, (byte*) message.c_str(), message.length() );

    HexEncoder encoder;
    string Sha384sortie;
    encoder.Attach( new StringSink( Sha384sortie ) );
    encoder.Put( Sha384Digest, sizeof(Sha384Digest) );
    encoder.MessageEnd();

    return Sha384sortie;
}

string Hashes::Sha512Fonction(QString qstring)
{
    SHA512 Sha512Hash;
    byte Sha512Digest[ SHA512::DIGESTSIZE ];
    string message = qstring.toStdString();

    Sha512Hash.CalculateDigest( Sha512Digest, (byte*) message.c_str(), message.length() );

    HexEncoder encoder;
    string Sha512sortie;
    encoder.Attach( new StringSink( Sha512sortie ) );
    encoder.Put( Sha512Digest, sizeof(Sha512Digest) );
    encoder.MessageEnd();

    return Sha512sortie;
}

string Hashes::TigerFonction(QString qstring)
{
    Tiger TigerHash;
    byte TigerDigest[ Tiger::DIGESTSIZE ];
    string message = qstring.toStdString();

    TigerHash.CalculateDigest( TigerDigest, (byte*) message.c_str(), message.length() );

    HexEncoder encoder;
    string Tigersortie;
    encoder.Attach( new StringSink( Tigersortie ) );
    encoder.Put( TigerDigest, sizeof(TigerDigest) );
    encoder.MessageEnd();

    return Tigersortie;
}

string Hashes::WhirlpoolFonction(QString qstring)
{
    Whirlpool WhirlpoolHash;
    byte WhirlpoolDigest[ Whirlpool::DIGESTSIZE ];
    string message = qstring.toStdString();

    WhirlpoolHash.CalculateDigest( WhirlpoolDigest, (byte*) message.c_str(), message.length() );

    HexEncoder encoder;
    string Whirlpoolsortie;
    encoder.Attach( new StringSink( Whirlpoolsortie ) );
    encoder.Put( WhirlpoolDigest, sizeof(WhirlpoolDigest) );
    encoder.MessageEnd();

    return Whirlpoolsortie;
}


