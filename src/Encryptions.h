#ifndef HEADER_ENCRYPTIONS
#define HEADER_ENCRYPTIONS

#include "C:\Qt\2009.02\qt\include\cryptopp/aes.h"
#include "C:\Qt\2009.02\qt\include\cryptopp/blowfish.h"
#include "C:\Qt\2009.02\qt\include\cryptopp/camellia.h"
#include "C:\Qt\2009.02\qt\include\cryptopp/cast.h"
#include "C:\Qt\2009.02\qt\include\cryptopp/des.h"
#include "C:\Qt\2009.02\qt\include\cryptopp/gost.h"
#include "C:\Qt\2009.02\qt\include\cryptopp/idea.h"
#include "C:\Qt\2009.02\qt\include\cryptopp/mars.h"
#include "C:\Qt\2009.02\qt\include\cryptopp/rc2.h"
#include "C:\Qt\2009.02\qt\include\cryptopp/rc5.h"
#include "C:\Qt\2009.02\qt\include\cryptopp/rc6.h"
#include "C:\Qt\2009.02\qt\include\cryptopp/rijndael.h"
#include "C:\Qt\2009.02\qt\include\cryptopp/safer.h"
#include "C:\Qt\2009.02\qt\include\cryptopp/seed.h"
#include "C:\Qt\2009.02\qt\include\cryptopp/serpent.h"
#include "C:\Qt\2009.02\qt\include\cryptopp/shacal2.h"
#include "C:\Qt\2009.02\qt\include\cryptopp/shark.h"
#include "C:\Qt\2009.02\qt\include\cryptopp/skipjack.h"
#include "C:\Qt\2009.02\qt\include\cryptopp/square.h"
#include "C:\Qt\2009.02\qt\include\cryptopp/3way.h"
#include "C:\Qt\2009.02\qt\include\cryptopp/twofish.h"
#include "C:\Qt\2009.02\qt\include\cryptopp/tea.h"
#include "C:\Qt\2009.02\qt\include\cryptopp/salsa.h"
#include "C:\Qt\2009.02\qt\include\cryptopp/panama.h"
#include "C:\Qt\2009.02\qt\include\cryptopp/seal.h"
#include "C:\Qt\2009.02\qt\include\cryptopp/sosemanuk.h"

#include "C:\Qt\2009.02\qt\include\cryptopp/modes.h"
#include "C:\Qt\2009.02\qt\include\cryptopp/filters.h"
#include "C:\Qt\2009.02\qt\include\cryptopp/hex.h"
#include "C:\Qt\2009.02\qt\include\cryptopp/sha.h"

#include <QtGui>

using namespace std;

class Encryption
{

public:
    string encryption(QString Pass, QString Text, string cipher, bool encrypt);
};

#endif
