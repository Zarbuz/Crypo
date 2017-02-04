#include "Encryptions.h"

using namespace CryptoPP;
using namespace std;

//Les fonctions viennent de différents algorithmes des librairie externes !
//cf : http://www.Crypopp.com/

/* La structure des codes n'est pas difficile et très répétitive !
  if(cipher == "ALGO1")
  {
  byte cle[ALGO1::DEFAULT_KEYLENGTH], iv[ALGO1::BLOCKSIZE];
  reinterpret_cast<const char*>(pass.c_str()), true, new HashFilter(*(new SHA256), new ArraySink(cle, ALGO1::DEFAULT_KEYLENGTH)) );
  memset( iv, 0x00, ALGO1::BLOCKSIZE );
        if (encrypt)
        {
            CBC_Mode<ALGO1>::Encryption EnCrypor( cle, sizeof(cle), iv );
            StringSource( text, true, new StreamTransformationFilter( EnCrypor,new HexEncoder(new StringSink( CipherText ) ) ) );
        }
        else
        {
            try
            {
                CBC_Mode<ALGO1>::Decryption DeCrypor( cle, sizeof(cle), iv );
                StringSource( text, true, new HexDecoder(new StreamTransformationFilter( DeCrypor, new StringSink( RecoveredText ) ) ) );
            }
            catch ( Exception& e)
            {
                return e.what();
            }
            catch (...)
            {
                return "Erreur inconnue";
            }
        }

  */
string Encryption::encryption(QString Pass, QString Text, string cipher, bool encrypt)
{
    string text = Text.toStdString();
    string pass = Pass.toStdString();
    string CipherText;
    string RecoveredText;


    if (cipher == "AES") // http://fr.wikipedia.org/wiki/Advanced_Encryption_Standard
    {
        byte cle[ AES::DEFAULT_KEYLENGTH ], iv[ AES::BLOCKSIZE ];
        StringSource( reinterpret_cast<const char*>(pass.c_str()), true, new HashFilter(*(new SHA256), new ArraySink(cle, AES::DEFAULT_KEYLENGTH)) );
        memset( iv, 0x00, AES::BLOCKSIZE );

        if (encrypt)
        {
            CBC_Mode<AES>::Encryption EnCrypor( cle, sizeof(cle), iv );
            StringSource( text, true, new StreamTransformationFilter( EnCrypor,new HexEncoder(new StringSink( CipherText ) ) ) );
        }
        else
        {
            try
            {
                CBC_Mode<AES>::Decryption DeCrypor( cle, sizeof(cle), iv );
                StringSource( text, true, new HexDecoder(new StreamTransformationFilter( DeCrypor, new StringSink( RecoveredText ) ) ) );
            }
            catch ( Exception& e)
            {
                return e.what();
            }
            catch (...)
            {
                return "Erreur inconnue";
            }
        }
    }

    if (cipher == "Blowfish") //http://fr.wikipedia.org/wiki/Blowfish
    {
        byte cle[ Blowfish::DEFAULT_KEYLENGTH ], iv[ Blowfish::BLOCKSIZE ];

        memset( iv, 0x00, Blowfish::BLOCKSIZE );

        StringSource( reinterpret_cast<const char*>(pass.c_str()), true, new HashFilter(*(new SHA256), new ArraySink(cle, Blowfish::DEFAULT_KEYLENGTH)) );



        if (encrypt)
        {
            CBC_Mode<Blowfish>::Encryption EnCrypor( cle, sizeof(cle), iv );
            StringSource( text, true, new StreamTransformationFilter( EnCrypor,new HexEncoder(new StringSink( CipherText ) ) ) );
        }
        else
        {
            try
            {
                CBC_Mode<Blowfish>::Decryption DeCrypor( cle, sizeof(cle), iv );
                StringSource( text, true, new HexDecoder(new StreamTransformationFilter( DeCrypor, new StringSink( RecoveredText ) ) ) );
            }
            catch ( Exception& e)
            {
                RecoveredText = e.what();
            }
            catch (...)
            {
                RecoveredText = "Erreur inconnue";
            }
        }
    }

    else if (cipher == "Camellia") //http://en.wikipedia.org/wiki/Camellia_(cipher)
    {
        byte cle[ Camellia::DEFAULT_KEYLENGTH ], iv[ Camellia::BLOCKSIZE ];
        StringSource( reinterpret_cast<const char*>(pass.c_str()), true, new HashFilter(*(new SHA256), new ArraySink(cle, Camellia::DEFAULT_KEYLENGTH)) );
        memset( iv, 0x00, Camellia::BLOCKSIZE );

        if (encrypt)
        {
            CBC_Mode<Camellia>::Encryption EnCrypor( cle, sizeof(cle), iv );
            StringSource( text, true, new StreamTransformationFilter( EnCrypor,new HexEncoder(new StringSink( CipherText ) ) ) );
        }
        else
        {
            try
            {
                CBC_Mode<Camellia>::Decryption DeCrypor( cle, sizeof(cle), iv );
                StringSource( text, true, new HexDecoder(new StreamTransformationFilter( DeCrypor, new StringSink( RecoveredText ) ) ) );
            }
            catch ( Exception& e)
            {
                return e.what();
            }
            catch (...)
            {
                return "Erreur inconnue";
            }
        }
    }

    else if (cipher == "CAST128") //http://fr.wikipedia.org/wiki/CAST-128
    {
        byte cle[ CAST128::DEFAULT_KEYLENGTH ], iv[ CAST128::BLOCKSIZE ];
        StringSource( reinterpret_cast<const char*>(pass.c_str()), true, new HashFilter(*(new SHA256), new ArraySink(cle, CAST128::DEFAULT_KEYLENGTH)) );
        memset( iv, 0x00, CAST128::BLOCKSIZE );

        if (encrypt)
        {
            CBC_Mode<CAST128>::Encryption EnCrypor( cle, sizeof(cle), iv );
            StringSource( text, true, new StreamTransformationFilter( EnCrypor,new HexEncoder(new StringSink( CipherText ) ) ) );
        }
        else
        {
            try
            {
                CBC_Mode<CAST128>::Decryption DeCrypor( cle, sizeof(cle), iv );
                StringSource( text, true, new HexDecoder(new StreamTransformationFilter( DeCrypor, new StringSink( RecoveredText ) ) ) );
            }
            catch ( Exception& e)
            {
                return e.what();
            }
            catch (...)
            {
                return "Erreur inconnue";
            }
        }
    }

    else if (cipher == "CAST256")//http://fr.wikipedia.org/wiki/CAST-256
    {
        byte cle[ CAST256::DEFAULT_KEYLENGTH ], iv[ CAST256::BLOCKSIZE ];
        StringSource( reinterpret_cast<const char*>(pass.c_str()), true, new HashFilter(*(new SHA256), new ArraySink(cle, CAST256::DEFAULT_KEYLENGTH)) );
        memset( iv, 0x00, CAST256::BLOCKSIZE );

        if (encrypt)
        {
            CBC_Mode<CAST256>::Encryption EnCrypor( cle, sizeof(cle), iv );
            StringSource( text, true, new StreamTransformationFilter( EnCrypor,new HexEncoder(new StringSink( CipherText ) ) ) );
        }
        else
        {
            try
            {
                CBC_Mode<CAST256>::Decryption DeCrypor( cle, sizeof(cle), iv );
                StringSource( text, true, new HexDecoder(new StreamTransformationFilter( DeCrypor, new StringSink( RecoveredText ) ) ) );
            }
            catch ( Exception& e)
            {
                return e.what();
            }
            catch (...)
            {
                return "Erreur inconnue";
            }
        }
    }

    else if (cipher == "DES")//http://fr.wikipedia.org/wiki/Data_Encryption_Standard
    {
        byte cle[ DES::DEFAULT_KEYLENGTH ], iv[ DES::BLOCKSIZE ];
        StringSource( reinterpret_cast<const char*>(pass.c_str()), true, new HashFilter(*(new SHA256), new ArraySink(cle, DES::DEFAULT_KEYLENGTH)) );
        memset( iv, 0x00, DES::BLOCKSIZE );

        if (encrypt)
        {
            CBC_Mode<DES>::Encryption EnCrypor( cle, sizeof(cle), iv );
            StringSource( text, true, new StreamTransformationFilter( EnCrypor,new HexEncoder(new StringSink( CipherText ) ) ) );
        }
        else
        {
            try
            {
                CBC_Mode<DES>::Decryption DeCrypor( cle, sizeof(cle), iv );
                StringSource( text, true, new HexDecoder(new StreamTransformationFilter( DeCrypor, new StringSink( RecoveredText ) ) ) );
            }
            catch ( Exception& e)
            {
                return e.what();
            }
            catch (...)
            {
                return "Erreur inconnue";
            }
        }
    }

    else if (cipher == "DES_EDE2")//http://wikipedia.qwika.com/en2fr/Triple_DES
    {
        byte cle[ DES_EDE2::DEFAULT_KEYLENGTH ], iv[ DES_EDE2::BLOCKSIZE ];
        StringSource( reinterpret_cast<const char*>(pass.c_str()), true, new HashFilter(*(new SHA256), new ArraySink(cle, DES_EDE2::DEFAULT_KEYLENGTH)) );
        memset( iv, 0x00, DES_EDE2::BLOCKSIZE );

        if (encrypt)
        {
            CBC_Mode<DES_EDE2>::Encryption EnCrypor( cle, sizeof(cle), iv );
            StringSource( text, true, new StreamTransformationFilter( EnCrypor,new HexEncoder(new StringSink( CipherText ) ) ) );
        }
        else
        {
            try
            {
                CBC_Mode<DES_EDE2>::Decryption DeCrypor( cle, sizeof(cle), iv );
                StringSource( text, true, new HexDecoder(new StreamTransformationFilter( DeCrypor, new StringSink( RecoveredText ) ) ) );
            }
            catch ( Exception& e)
            {
                return e.what();
            }
            catch (...)
            {
                return "Erreur inconnue";
            }
        }
    }

    else if (cipher == "DES_EDE3") //http://wikipedia.qwika.com/en2fr/Triple_DES
    {
        byte cle[ DES_EDE3::DEFAULT_KEYLENGTH ], iv[ DES_EDE3::BLOCKSIZE ];
        StringSource( reinterpret_cast<const char*>(pass.c_str()), true, new HashFilter(*(new SHA256), new ArraySink(cle, DES_EDE3::DEFAULT_KEYLENGTH)) );
        memset( iv, 0x00, DES_EDE3::BLOCKSIZE );

        if (encrypt)
        {
            CBC_Mode<DES_EDE3>::Encryption EnCrypor( cle, sizeof(cle), iv );
            StringSource( text, true, new StreamTransformationFilter( EnCrypor,new HexEncoder(new StringSink( CipherText ) ) ) );
        }
        else
        {
            try
            {
                CBC_Mode<DES_EDE3>::Decryption DeCrypor( cle, sizeof(cle), iv );
                StringSource( text, true, new HexDecoder(new StreamTransformationFilter( DeCrypor, new StringSink( RecoveredText ) ) ) );
            }
            catch ( Exception& e)
            {
                return e.what();
            }
            catch (...)
            {
                return "Erreur inconnue";
            }
        }
    }

    else if (cipher == "DES_XEX3") ////http://wikipedia.qwika.com/en2fr/Triple_DES
    {
        byte cle[ DES_XEX3::DEFAULT_KEYLENGTH ], iv[ DES_XEX3::BLOCKSIZE ];
        StringSource( reinterpret_cast<const char*>(pass.c_str()), true, new HashFilter(*(new SHA256), new ArraySink(cle, DES_XEX3::DEFAULT_KEYLENGTH)) );
        memset( iv, 0x00, DES_XEX3::BLOCKSIZE );

        if (encrypt)
        {
            CBC_Mode<DES_XEX3>::Encryption EnCrypor( cle, sizeof(cle), iv );
            StringSource( text, true, new StreamTransformationFilter( EnCrypor,new HexEncoder(new StringSink( CipherText ) ) ) );
        }
        else
        {
            try
            {
                CBC_Mode<DES_XEX3>::Decryption DeCrypor( cle, sizeof(cle), iv );
                StringSource( text, true, new HexDecoder(new StreamTransformationFilter( DeCrypor, new StringSink( RecoveredText ) ) ) );
            }
            catch ( Exception& e)
            {
                return e.what();
            }
            catch (...)
            {
                return "Erreur inconnue";
            }
        }
    }

    else if (cipher == "GOST") //http://en.wikipedia.org/wiki/GOST_(block_cipher)
    {
        byte cle[ GOST::DEFAULT_KEYLENGTH ], iv[ GOST::BLOCKSIZE ];
        StringSource( reinterpret_cast<const char*>(pass.c_str()), true, new HashFilter(*(new SHA256), new ArraySink(cle, GOST::DEFAULT_KEYLENGTH)) );
        memset( iv, 0x00, GOST::BLOCKSIZE );

        if (encrypt)
        {
            CBC_Mode<GOST>::Encryption EnCrypor( cle, sizeof(cle), iv );
            StringSource( text, true, new StreamTransformationFilter( EnCrypor,new HexEncoder(new StringSink( CipherText ) ) ) );
        }
        else
        {
            try
            {
                CBC_Mode<GOST>::Decryption DeCrypor( cle, sizeof(cle), iv );
                StringSource( text, true, new HexDecoder(new StreamTransformationFilter( DeCrypor, new StringSink( RecoveredText ) ) ) );
            }
            catch ( Exception& e)
            {
                return e.what();
            }
            catch (...)
            {
                return "Erreur inconnue";
            }
        }
    }

    else if (cipher == "IDEA") //http://en.wikipedia.org/wiki/International_Data_Encryption_Algorithm
    {
        byte cle[ IDEA::DEFAULT_KEYLENGTH ], iv[ IDEA::BLOCKSIZE ];
        StringSource( reinterpret_cast<const char*>(pass.c_str()), true, new HashFilter(*(new SHA256), new ArraySink(cle, IDEA::DEFAULT_KEYLENGTH)) );
        memset( iv, 0x00, IDEA::BLOCKSIZE );

        if (encrypt)
        {
            CBC_Mode<IDEA>::Encryption EnCrypor( cle, sizeof(cle), iv );
            StringSource( text, true, new StreamTransformationFilter( EnCrypor,new HexEncoder(new StringSink( CipherText ) ) ) );
        }
        else
        {
            try
            {
                CBC_Mode<IDEA>::Decryption DeCrypor( cle, sizeof(cle), iv );
                StringSource( text, true, new HexDecoder(new StreamTransformationFilter( DeCrypor, new StringSink( RecoveredText ) ) ) );
            }
            catch ( Exception& e)
            {
                return e.what();
            }
            catch (...)
            {
                return "Erreur inconnue";
            }
        }
    }

    else if (cipher == "MARS") //http://en.wikipedia.org/wiki/MARS_(cryptography)
    {
        byte cle[ MARS::DEFAULT_KEYLENGTH ], iv[ MARS::BLOCKSIZE ];
        StringSource( reinterpret_cast<const char*>(pass.c_str()), true, new HashFilter(*(new SHA256), new ArraySink(cle, MARS::DEFAULT_KEYLENGTH)) );
        memset( iv, 0x00, MARS::BLOCKSIZE );

        if (encrypt)
        {
            CBC_Mode<MARS>::Encryption EnCrypor( cle, sizeof(cle), iv );
            StringSource( text, true, new StreamTransformationFilter( EnCrypor,new HexEncoder(new StringSink( CipherText ) ) ) );
        }
        else
        {
            try
            {
                CBC_Mode<MARS>::Decryption DeCrypor( cle, sizeof(cle), iv );
                StringSource( text, true, new HexDecoder(new StreamTransformationFilter( DeCrypor, new StringSink( RecoveredText ) ) ) );
            }
            catch ( Exception& e)
            {
                return e.what();
            }
            catch (...)
            {
                return "Erreur inconnue";
            }
        }
    }

    else if (cipher == "Panama") //http://en.wikipedia.org/wiki/Panama_(cryptography)
    {
        byte cle[ PanamaCipher<LittleEndian>::DEFAULT_KEYLENGTH ], iv[ PanamaCipher<LittleEndian>::IV_LENGTH ];
        StringSource( reinterpret_cast<const char*>(pass.c_str()), true, new HashFilter(*(new SHA256), new ArraySink(cle, PanamaCipher<LittleEndian>::DEFAULT_KEYLENGTH)) );
        memset( iv, 0x00, PanamaCipher<LittleEndian>::IV_LENGTH );

        if (encrypt)
        {
            PanamaCipher<LittleEndian>::Encryption EnCrypor( cle, sizeof(cle), iv );
            StringSource( text, true, new StreamTransformationFilter( EnCrypor,new HexEncoder(new StringSink( CipherText ) ) ) );
        }
        else
        {
            try
            {
                PanamaCipher<LittleEndian>::Decryption DeCrypor( cle, sizeof(cle), iv );
                StringSource( text, true, new HexDecoder(new StreamTransformationFilter( DeCrypor, new StringSink( RecoveredText ) ) ) );
            }
            catch ( Exception& e)
            {
                return e.what();
            }
            catch (...)
            {
                return "Erreur inconnue";
            }
        }
    }

    else if (cipher == "RC2") //http://fr.wikipedia.org/wiki/RC2
    {
        byte cle[ RC2::DEFAULT_KEYLENGTH ], iv[ RC2::BLOCKSIZE ];
        StringSource( reinterpret_cast<const char*>(pass.c_str()), true, new HashFilter(*(new SHA256), new ArraySink(cle, RC2::DEFAULT_KEYLENGTH)) );
        memset( iv, 0x00, RC2::BLOCKSIZE );

        if (encrypt)
        {
            CBC_Mode<RC2>::Encryption EnCrypor( cle, sizeof(cle), iv );
            StringSource( text, true, new StreamTransformationFilter( EnCrypor,new HexEncoder(new StringSink( CipherText ) ) ) );
        }
        else
        {
            try
            {
                CBC_Mode<RC2>::Decryption DeCrypor( cle, sizeof(cle), iv );
                StringSource( text, true, new HexDecoder(new StreamTransformationFilter( DeCrypor, new StringSink( RecoveredText ) ) ) );
            }
            catch ( Exception& e)
            {
                return e.what();
            }
            catch (...)
            {
                return "Erreur inconnue";
            }
        }
    }

    else if (cipher == "RC5") //http://fr.wikipedia.org/wiki/RC5_(chiffrement)
    {
        byte cle[ RC5::DEFAULT_KEYLENGTH ], iv[ RC5::BLOCKSIZE ];
        StringSource( reinterpret_cast<const char*>(pass.c_str()), true, new HashFilter(*(new SHA256), new ArraySink(cle, RC5::DEFAULT_KEYLENGTH)) );
        memset( iv, 0x00, RC5::BLOCKSIZE );

        if (encrypt)
        {
            CBC_Mode<RC5>::Encryption EnCrypor( cle, sizeof(cle), iv );
            StringSource( text, true, new StreamTransformationFilter( EnCrypor,new HexEncoder(new StringSink( CipherText ) ) ) );
        }
        else
        {
            try
            {
                CBC_Mode<RC5>::Decryption DeCrypor( cle, sizeof(cle), iv );
                StringSource( text, true, new HexDecoder(new StreamTransformationFilter( DeCrypor, new StringSink( RecoveredText ) ) ) );
            }
            catch ( Exception& e)
            {
                return e.what();
            }
            catch (...)
            {
                return "Erreur inconnue";
            }
        }
    }

    else if (cipher == "RC6") //http://fr.wikipedia.org/wiki/RC6
    {
        byte cle[ RC6::DEFAULT_KEYLENGTH ], iv[ RC6::BLOCKSIZE ];
        StringSource( reinterpret_cast<const char*>(pass.c_str()), true, new HashFilter(*(new SHA256), new ArraySink(cle, RC6::DEFAULT_KEYLENGTH)) );
        memset( iv, 0x00, RC6::BLOCKSIZE );

        if (encrypt)
        {
            CBC_Mode<RC6>::Encryption EnCrypor( cle, sizeof(cle), iv );
            StringSource( text, true, new StreamTransformationFilter( EnCrypor,new HexEncoder(new StringSink( CipherText ) ) ) );
        }
        else
        {
            try
            {
                CBC_Mode<RC6>::Decryption DeCrypor( cle, sizeof(cle), iv );
                StringSource( text, true, new HexDecoder(new StreamTransformationFilter( DeCrypor, new StringSink( RecoveredText ) ) ) );
            }
            catch ( Exception& e)
            {
                return e.what();
            }
            catch (...)
            {
                return "Erreur inconnue";
            }
        }
    }

    else if (cipher == "SAFER_K") //https://fr.wikipedia.org/wiki/SAFER_(cryptographie)
    {
        byte cle[ SAFER_K::DEFAULT_KEYLENGTH ], iv[ SAFER_K::BLOCKSIZE ];
        StringSource( reinterpret_cast<const char*>(pass.c_str()), true, new HashFilter(*(new SHA256), new ArraySink(cle, SAFER_K::DEFAULT_KEYLENGTH)) );
        memset( iv, 0x00, SAFER_K::BLOCKSIZE );

        if (encrypt)
        {
            CBC_Mode<SAFER_K>::Encryption EnCrypor( cle, sizeof(cle), iv );
            StringSource( text, true, new StreamTransformationFilter( EnCrypor,new HexEncoder(new StringSink( CipherText ) ) ) );
        }
        else
        {
            try
            {
                CBC_Mode<SAFER_K>::Decryption DeCrypor( cle, sizeof(cle), iv );
                StringSource( text, true, new HexDecoder(new StreamTransformationFilter( DeCrypor, new StringSink( RecoveredText ) ) ) );
            }
            catch ( Exception& e)
            {
                return e.what();
            }
            catch (...)
            {
                return "Erreur inconnue";
            }
        }
    }

    else if (cipher == "SAFER_SK") //http://fr.wikipedia.org/wiki/SAFER_(cryptographie)
    {
        byte cle[ SAFER_SK::DEFAULT_KEYLENGTH ], iv[ SAFER_SK::BLOCKSIZE ];
        StringSource( reinterpret_cast<const char*>(pass.c_str()), true, new HashFilter(*(new SHA256), new ArraySink(cle, SAFER_SK::DEFAULT_KEYLENGTH)) );
        memset( iv, 0x00, SAFER_SK::BLOCKSIZE );

        if (encrypt)
        {
            CBC_Mode<SAFER_SK>::Encryption EnCrypor( cle, sizeof(cle), iv );
            StringSource( text, true, new StreamTransformationFilter( EnCrypor,new HexEncoder(new StringSink( CipherText ) ) ) );
        }
        else
        {
            try
            {
                CBC_Mode<SAFER_SK>::Decryption DeCrypor( cle, sizeof(cle), iv );
                StringSource( text, true, new HexDecoder(new StreamTransformationFilter( DeCrypor, new StringSink( RecoveredText ) ) ) );
            }
            catch ( Exception& e)
            {
                return e.what();
            }
            catch (...)
            {
                return "Erreur inconnue";
            }
        }
    }

    else if (cipher == "Salsa20") //http://en.wikipedia.org/wiki/Salsa20
    {
        byte cle[ Salsa20::DEFAULT_KEYLENGTH ], iv[ Salsa20::IV_LENGTH ];
        StringSource( reinterpret_cast<const char*>(pass.c_str()), true, new HashFilter(*(new SHA256), new ArraySink(cle, Salsa20::DEFAULT_KEYLENGTH)) );
        memset( iv, 0x00, Salsa20::IV_LENGTH );

        if (encrypt)
        {
            Salsa20::Encryption EnCrypor( cle, sizeof(cle), iv );
            StringSource( text, true, new StreamTransformationFilter( EnCrypor,new HexEncoder(new StringSink( CipherText ) ) ) );
        }
        else
        {
            try
            {
                Salsa20::Decryption DeCrypor( cle, sizeof(cle), iv );
                StringSource( text, true, new HexDecoder(new StreamTransformationFilter( DeCrypor, new StringSink( RecoveredText ) ) ) );
            }
            catch ( Exception& e)
            {
                return e.what();
            }
            catch (...)
            {
                return "Erreur inconnue";
            }
        }
    }

    else if (cipher == "SEAL") //http://fr.wikipedia.org/wiki/SEAL_(cryptographie)
    {
        byte cle[ SEAL<BigEndian>::DEFAULT_KEYLENGTH ], iv[ SEAL<BigEndian>::IV_LENGTH ];
        StringSource( reinterpret_cast<const char*>(pass.c_str()), true, new HashFilter(*(new SHA256), new ArraySink(cle, SEAL<BigEndian>::DEFAULT_KEYLENGTH)) );
        memset( iv, 0x00, SEAL<BigEndian>::IV_LENGTH );

        if (encrypt)
        {
            SEAL<BigEndian>::Encryption EnCrypor( cle, sizeof(cle), iv );
            StringSource( text, true, new StreamTransformationFilter( EnCrypor,new HexEncoder(new StringSink( CipherText ) ) ) );
        }
        else
        {
            try
            {
                SEAL<BigEndian>::Decryption DeCrypor( cle, sizeof(cle), iv );
                StringSource( text, true, new HexDecoder(new StreamTransformationFilter( DeCrypor, new StringSink( RecoveredText ) ) ) );
            }
            catch ( Exception& e)
            {
                return e.what();
            }
            catch (...)
            {
                return "Erreur inconnue";
            }
        }
    }

    else if (cipher == "SEED") //http://en.wikipedia.org/wiki/SEED
    {
        byte cle[ SEED::DEFAULT_KEYLENGTH ], iv[ SEED::BLOCKSIZE ];
        StringSource( reinterpret_cast<const char*>(pass.c_str()), true, new HashFilter(*(new SHA256), new ArraySink(cle, SEED::DEFAULT_KEYLENGTH)) );
        memset( iv, 0x00, SEED::BLOCKSIZE );

        if (encrypt)
        {
            CBC_Mode<SEED>::Encryption EnCrypor( cle, sizeof(cle), iv );
            StringSource( text, true, new StreamTransformationFilter( EnCrypor,new HexEncoder(new StringSink( CipherText ) ) ) );
        }
        else
        {
            try
            {
                CBC_Mode<SEED>::Decryption DeCrypor( cle, sizeof(cle), iv );
                StringSource( text, true, new HexDecoder(new StreamTransformationFilter( DeCrypor, new StringSink( RecoveredText ) ) ) );
            }
            catch ( Exception& e)
            {
                return e.what();
            }
            catch (...)
            {
                return "Erreur inconnue";
            }
        }
    }

    else if (cipher == "Serpent") //http://fr.wikipedia.org/wiki/Serpent_(cryptographie)
    {
        byte cle[ Serpent::DEFAULT_KEYLENGTH ], iv[ Serpent::BLOCKSIZE ];
        StringSource( reinterpret_cast<const char*>(pass.c_str()), true, new HashFilter(*(new SHA256), new ArraySink(cle, Serpent::DEFAULT_KEYLENGTH)) );
        memset( iv, 0x00, Serpent::BLOCKSIZE );

        if (encrypt)
        {
            CBC_Mode<Serpent>::Encryption EnCrypor( cle, sizeof(cle), iv );
            StringSource( text, true, new StreamTransformationFilter( EnCrypor,new HexEncoder(new StringSink( CipherText ) ) ) );
        }
        else
        {
            try
            {
                CBC_Mode<Serpent>::Decryption DeCrypor( cle, sizeof(cle), iv );
                StringSource( text, true, new HexDecoder(new StreamTransformationFilter( DeCrypor, new StringSink( RecoveredText ) ) ) );
            }
            catch ( Exception& e)
            {
                return e.what();
            }
            catch (...)
            {
                return "Erreur inconnue";
            }
        }
    }

    else if (cipher == "SHACAL2") // http://fr.wikipedia.org/wiki/SHACAL
    {
        byte cle[ SHACAL2::DEFAULT_KEYLENGTH ], iv[ SHACAL2::BLOCKSIZE ];
        StringSource( reinterpret_cast<const char*>(pass.c_str()), true, new HashFilter(*(new SHA256), new ArraySink(cle, SHACAL2::DEFAULT_KEYLENGTH)) );
        memset( iv, 0x00, SHACAL2::BLOCKSIZE );

        if (encrypt)
        {
            CBC_Mode<SHACAL2>::Encryption EnCrypor( cle, sizeof(cle), iv );
            StringSource( text, true, new StreamTransformationFilter( EnCrypor,new HexEncoder(new StringSink( CipherText ) ) ) );
        }
        else
        {
            try
            {
                CBC_Mode<SHACAL2>::Decryption DeCrypor( cle, sizeof(cle), iv );
                StringSource( text, true, new HexDecoder(new StreamTransformationFilter( DeCrypor, new StringSink( RecoveredText ) ) ) );
            }
            catch ( Exception& e)
            {
                return e.what();
            }
            catch (...)
            {
                return "Erreur inconnue";
            }
        }
    }

    else if (cipher == "SHARK")
    {
        byte cle[ SHARK::DEFAULT_KEYLENGTH ], iv[ SHARK::BLOCKSIZE ];
        StringSource( reinterpret_cast<const char*>(pass.c_str()), true, new HashFilter(*(new SHA256), new ArraySink(cle, SHARK::DEFAULT_KEYLENGTH)) );
        memset( iv, 0x00, SHARK::BLOCKSIZE );

        if (encrypt)
        {
            CBC_Mode<SHARK>::Encryption EnCrypor( cle, sizeof(cle), iv );
            StringSource( text, true, new StreamTransformationFilter( EnCrypor,new HexEncoder(new StringSink( CipherText ) ) ) );
        }
        else
        {
            try
            {
                CBC_Mode<SHARK>::Decryption DeCrypor( cle, sizeof(cle), iv );
                StringSource( text, true, new HexDecoder(new StreamTransformationFilter( DeCrypor, new StringSink( RecoveredText ) ) ) );
            }
            catch ( Exception& e)
            {
                return e.what();
            }
            catch (...)
            {
                return "Erreur inconnue";
            }
        }
    }

    else if (cipher == "SKIPJACK") //http://fr.wikipedia.org/wiki/SHARK
    {
        byte cle[ SKIPJACK::DEFAULT_KEYLENGTH ], iv[ SKIPJACK::BLOCKSIZE ];
        StringSource( reinterpret_cast<const char*>(pass.c_str()), true, new HashFilter(*(new SHA256), new ArraySink(cle, SKIPJACK::DEFAULT_KEYLENGTH)) );
        memset( iv, 0x00, SKIPJACK::BLOCKSIZE );

        if (encrypt)
        {
            CBC_Mode<SKIPJACK>::Encryption EnCrypor( cle, sizeof(cle), iv );
            StringSource( text, true, new StreamTransformationFilter( EnCrypor,new HexEncoder(new StringSink( CipherText ) ) ) );
        }
        else
        {
            try
            {
                CBC_Mode<SKIPJACK>::Decryption DeCrypor( cle, sizeof(cle), iv );
                StringSource( text, true, new HexDecoder(new StreamTransformationFilter( DeCrypor, new StringSink( RecoveredText ) ) ) );
            }
            catch ( Exception& e)
            {
                return e.what();
            }
            catch (...)
            {
                return "Erreur inconnue";
            }
        }
    }

    else if (cipher == "Sosemanuk")
    {
        byte cle[ Sosemanuk::DEFAULT_KEYLENGTH ], iv[ Sosemanuk::IV_LENGTH ];
        StringSource( reinterpret_cast<const char*>(pass.c_str()), true, new HashFilter(*(new SHA256), new ArraySink(cle, Sosemanuk::DEFAULT_KEYLENGTH)) );
        memset( iv, 0x00, Sosemanuk::IV_LENGTH );

        if (encrypt)
        {
            Sosemanuk::Encryption EnCrypor( cle, sizeof(cle), iv );
            StringSource( text, true, new StreamTransformationFilter( EnCrypor,new HexEncoder(new StringSink( CipherText ) ) ) );
        }
        else
        {
            try
            {
                Sosemanuk::Decryption DeCrypor( cle, sizeof(cle), iv );
                StringSource( text, true, new HexDecoder(new StreamTransformationFilter( DeCrypor, new StringSink( RecoveredText ) ) ) );
            }
            catch ( Exception& e)
            {
                return e.what();
            }
            catch (...)
            {
                return "Erreur inconnue";
            }
        }
    }

    else if (cipher == "Square")
    {
        byte cle[ Square::DEFAULT_KEYLENGTH ], iv[ Square::BLOCKSIZE ];
        StringSource( reinterpret_cast<const char*>(pass.c_str()), true, new HashFilter(*(new SHA256), new ArraySink(cle, Square::DEFAULT_KEYLENGTH)) );
        memset( iv, 0x00, Square::BLOCKSIZE );

        if (encrypt)
        {
            CBC_Mode<Square>::Encryption EnCrypor( cle, sizeof(cle), iv );
            StringSource( text, true, new StreamTransformationFilter( EnCrypor,new HexEncoder(new StringSink( CipherText ) ) ) );
        }
        else
        {
            try
            {
                CBC_Mode<Square>::Decryption DeCrypor( cle, sizeof(cle), iv );
                StringSource( text, true, new HexDecoder(new StreamTransformationFilter( DeCrypor, new StringSink( RecoveredText ) ) ) );
            }
            catch ( Exception& e)
            {
                return e.what();
            }
            catch (...)
            {
                return "Erreur inconnue";
            }
        }
    }

    else if (cipher == "TEA")
    {
        byte cle[ TEA::DEFAULT_KEYLENGTH ], iv[ TEA::BLOCKSIZE ];
        StringSource( reinterpret_cast<const char*>(pass.c_str()), true, new HashFilter(*(new SHA256), new ArraySink(cle, TEA::DEFAULT_KEYLENGTH)) );
        memset( iv, 0x00, TEA::BLOCKSIZE );

        if (encrypt)
        {
            CBC_Mode<TEA>::Encryption EnCrypor( cle, sizeof(cle), iv );
            StringSource( text, true, new StreamTransformationFilter( EnCrypor,new HexEncoder(new StringSink( CipherText ) ) ) );
        }
        else
        {
            try
            {
                CBC_Mode<TEA>::Decryption DeCrypor( cle, sizeof(cle), iv );
                StringSource( text, true, new HexDecoder(new StreamTransformationFilter( DeCrypor, new StringSink( RecoveredText ) ) ) );
            }
            catch ( Exception& e)
            {
                return e.what();
            }
            catch (...)
            {
                return "Erreur inconnue";
            }
        }
    }

    else if (cipher == "ThreeWay")
    {
        byte cle[ ThreeWay::DEFAULT_KEYLENGTH ], iv[ ThreeWay::BLOCKSIZE ];
        StringSource( reinterpret_cast<const char*>(pass.c_str()), true, new HashFilter(*(new SHA256), new ArraySink(cle, ThreeWay::DEFAULT_KEYLENGTH)) );
        memset( iv, 0x00, ThreeWay::BLOCKSIZE );

        if (encrypt)
        {
            CBC_Mode<ThreeWay>::Encryption EnCrypor( cle, sizeof(cle), iv );
            StringSource( text, true, new StreamTransformationFilter( EnCrypor,new HexEncoder(new StringSink( CipherText ) ) ) );
        }
        else
        {
            try
            {
                CBC_Mode<ThreeWay>::Decryption DeCrypor( cle, sizeof(cle), iv );
                StringSource( text, true, new HexDecoder(new StreamTransformationFilter( DeCrypor, new StringSink( RecoveredText ) ) ) );
            }
            catch ( Exception& e)
            {
                return e.what();
            }
            catch (...)
            {
                return "Erreur inconnue";
            }
        }
    }

    else if (cipher == "Twofish")
    {
        byte cle[ Twofish::DEFAULT_KEYLENGTH ], iv[ Twofish::BLOCKSIZE ];
        StringSource( reinterpret_cast<const char*>(pass.c_str()), true, new HashFilter(*(new SHA256), new ArraySink(cle, Twofish::DEFAULT_KEYLENGTH)) );
        memset( iv, 0x00, Twofish::BLOCKSIZE );

        if (encrypt)
        {
            CBC_Mode<Twofish>::Encryption EnCrypor( cle, sizeof(cle), iv );
            StringSource( text, true, new StreamTransformationFilter( EnCrypor,new HexEncoder(new StringSink( CipherText ) ) ) );
        }
        else
        {
            try
            {
                CBC_Mode<Twofish>::Decryption DeCrypor( cle, sizeof(cle), iv );
                StringSource( text, true, new HexDecoder(new StreamTransformationFilter( DeCrypor, new StringSink( RecoveredText ) ) ) );
            }
            catch ( Exception& e)
            {
                return e.what();
            }
            catch (...)
            {
                return "Erreur inconnue";
            }
        }
    }

    else if (cipher == "XSalsa20")
    {
        byte cle[ XSalsa20::DEFAULT_KEYLENGTH ], iv[ XSalsa20::IV_LENGTH ];
        StringSource( reinterpret_cast<const char*>(pass.c_str()), true, new HashFilter(*(new SHA256), new ArraySink(cle, XSalsa20::DEFAULT_KEYLENGTH)) );
        memset( iv, 0x00, XSalsa20::IV_LENGTH );

        if (encrypt)
        {
            XSalsa20::Encryption EnCrypor( cle, sizeof(cle), iv );
            StringSource( text, true, new StreamTransformationFilter( EnCrypor,new HexEncoder(new StringSink( CipherText ) ) ) );
        }
        else
        {
            try
            {
                XSalsa20::Decryption DeCrypor( cle, sizeof(cle), iv );
                StringSource( text, true, new HexDecoder(new StreamTransformationFilter( DeCrypor, new StringSink( RecoveredText ) ) ) );
            }
            catch ( Exception& e)
            {
                return e.what();
            }
            catch (...)
            {
                return "Erreur inconnue";
            }
        }
    }

    else if (cipher == "XTEA")
    {
        byte cle[ XTEA::DEFAULT_KEYLENGTH ], iv[ XTEA::BLOCKSIZE ];
        StringSource( reinterpret_cast<const char*>(pass.c_str()), true, new HashFilter(*(new SHA256), new ArraySink(cle, XTEA::DEFAULT_KEYLENGTH)) );
        memset( iv, 0x00, XTEA::BLOCKSIZE );

        if (encrypt)
        {
            CBC_Mode<XTEA>::Encryption EnCrypor( cle, sizeof(cle), iv );
            StringSource( text, true, new StreamTransformationFilter( EnCrypor,new HexEncoder(new StringSink( CipherText ) ) ) );
        }
        else
        {
            try
            {
                CBC_Mode<XTEA>::Decryption DeCrypor( cle, sizeof(cle), iv );
                StringSource( text, true, new HexDecoder(new StreamTransformationFilter( DeCrypor, new StringSink( RecoveredText ) ) ) );
            }
            catch ( Exception& e)
            {
                return e.what();
            }
            catch (...)
            {
                return "Erreur inconnue";
            }
        }
    }

    if (encrypt)
        return CipherText;

    return RecoveredText;
}

