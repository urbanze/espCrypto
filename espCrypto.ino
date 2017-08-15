/*
 Name:		espCrypto.ino
 Created:	13/08/2017 19:34:34
 Author:	Jos� morais
*/

#include <EspCrypto.h>
espCrypto esp;


void setup()
{
	String enc, dec, hash;

	Serial.begin(115200);//Inicia a comunica��o serial.
	esp.setKey("1234567890123456");//Adicionado a chave para encripta��o, mantenha em segredo!
	

	enc = esp.encrypt("oi");//A fun��o encrypt retorna uma string Encriptada.
	Serial.println("Encrypted: " + enc);//Printa a mensagem encriptada.


	dec = esp.decrypt(enc);//A fun��o decrypt retorna uma string Desencriptada.
	Serial.println("Decrypted: " + dec);//Printa a mensagem desencriptada.
	
	hash = sha1("oi");//A fun��o sha1 retorna uma string Hash.
	Serial.println("Hash: " + hash);//Printa o Hash.
	
}


void loop()
{

}
