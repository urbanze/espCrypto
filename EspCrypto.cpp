#include <espCrypto.h>

AES aes;

void espCrypto::setKey(String key)
{
	_key = key;
}


String espCrypto::decrypt(String text)
{
	byte key[32], out[16], inp[16];


	if (text.length() != 32)
	{
		return "TEXT LENGHT ERROR.";
	}

	for (byte i = 0; i < _key.length(); i++)
	{
		key[i] = _key[i];
	}
	for (byte i = 0; i < 32; i += 2)
	{
		if (i >= 0)
		{
			inp[i / 2] = strtol(text.substring(i, i + 2).c_str(), NULL, 16);
		}
		else
		{
			inp[i] = strtol(text.substring(i, i + 2).c_str(), NULL, 16);
		}
	}



	if (aes.set_key(key, _key.length()) != 0)
	{
		return "KEY ERROR, VALID INPUT: 16, 24 OR 32 Bytes.";
	}
	if (aes.decrypt(inp, out) != 0)
	{
		return "DECRYPT ERROR.";
	}


	String a = "";
	for (byte i = 0; i < 16; i++)
	{
		a += char(out[i]);
	}


	aes.clean();

	return a;
}


String espCrypto::encrypt(String text)
{
	byte key[32], out[16], inp[16];

	if (text.length() > 15)
	{
		return "TEXT LENGHT ERROR.";
	}

	for (byte i = 0; i < _key.length(); i++)
	{
		key[i] = _key[i];
	}
	for (byte i = 0; i < 16; i++)
	{
		inp[i] = text[i];
	}


	if (aes.set_key(key, _key.length()) != 0)
	{
		return "KEY ERROR, VALID INPUT: 16, 24 OR 32 Bytes.";
	}
	if (aes.encrypt(inp, out) != 0)
	{
		return "ENCRYPT ERROR.";
	}

	String a = "";
	char buffer[6];

	for (byte i = 0; i < 16; i++)
	{
		itoa(out[i], buffer, 16);

		a += buffer;
		a += " ";
	}

	aes.clean();
	return a;
}
