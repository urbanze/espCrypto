#ifndef espCrypto_H
#define espCrypto_H
#include <AES.h>



class espCrypto
{
public:
	String decrypt(String text);
	String encrypt(String text);
	void setKey(String key);

private:
	String _key;
};








#endif